#ifndef G24_LIB_INTERPOL
#define G24_LIB_INTERPOL

/**********************************************
 *                                            *
 *  BIBLIOTECA DE FUNÇÕES MULTI-DIMENSIONAIS  *
 *                                            *
 *     Por: Gonçalo Vaz (87321)               *
 *          Nuno Fernandes (87342)            *
 *     [Antigo Grupo 24 de FC 2017-2018]      *
 * [Antigo Grupo 25 de Programação 2016-2017] *
 *                                            *
 **********************************************/
 
/*!

\file interpol.h

\brief Provides functions that enable grid interpolation in several dimensions
       

\author Nuno Fernandes (main coder, current maintainer)

*/

namespace g24_lib
{
  /*!
    \brief Linear interpolation from a unidimensional array.
    
    \param arr The array of discretized values from which to interpolate.
    
    \param elem The index of the element from which we want to interpolate.
    
    \param position The position at which we want to interpolate
                    expressed as a fraction of the distance
                    between two elements of the array.
                    (`-1 < position < 1`)
    
    \param separation The difference in index between two consecutive elements.
                      (Useful for each unidimensional interpolation in multidimensional grids.)
    
    \remark Given the way linear interpolation works, it is equivalent to have `elem = x` and `position = y`
            (with `y > 0`) or `elem = x + 1` and `position = y - 1`. For consistency reasons,
            we recommend the user always tries to ensure `position > 0`, but the algorithm works either way.
    
    \tparam number A type that can hold non-integer numbers. Typically floating point.
    
    \tparam indexer A type that is appropriate to hold both positive and negative offsets from a position in the array.
    
    \pre \p number must have addition and multiplication with the type held by the array that is being interpolated.
    
    \pre \p indexer must satisfy the constraints placed on the choice of \ref g24_lib::Definitions::default_signed_indexer.
  */
  template <class number, class ArrT, class indexer>
  CUDA_HOS_DEV auto interpolate_from_grid_1D( const ArrT& arr,
                                              const indexer elem,
                                              const number position,
                                              const indexer separation = 1)
  //Linear interpolation
  {
    using namespace std;
    auto ret = arr[elem] * (1 - abs(position)) + arr[elem+separation*sign<number, indexer>(position)]*abs(position);
    return ret;
  }
  
  /*!
    \brief Polynomial interpolation from a unidimensional array (with a number of points).
    
    \param arr The array of discretized values from which to interpolate.
    
    \param elem The index of the point from which we want to interpolate.
    
    \param position The position at which we want to interpolate
                    expressed as a fraction of the distance
                    between two elements of the array.
                    (`-1 < position < 1`)
    
    \param to_left Number of points to the left of the point specified by \p elem to also be considered in the interpolation.
    
    \param to_right Number of points to the right of the point specified by \p elem to also be considered in the interpolation.    
    
    \param separation The difference in index between two consecutive elements.
                      (Useful for each unidimensional interpolation in multidimensional grids.)
        
    \remark The order of the interpolation will be given by `to_left + to_right`.
    
    \remark A linear interpolation would be given by `to_left = 0` and `to_right = 1`
            for `position > 0`, or, equivalently, `to_left = 1` and `to_right = 0`
            for `position < 0`.
    
    \tparam number A type that can hold non-integer numbers. Typically floating point.
    
    \tparam indexer A type that is appropriate to hold both positive and negative offsets from a position in the array.
    
    \pre \p number must have addition and multiplication with the type held by the array that is being interpolated.
    
    \pre \p indexer must satisfy the constraints placed on the choice of \ref g24_lib::Definitions::default_signed_indexer.
    
    \details The interpolation is performed using Lagrange polynomials. Suppose we will use \f$n + 1\f$ points,
             \f$x_0, x_1, \ldots, x_n\f$, to perform the interpolation, and that the values of the function
             at these points are, respectively, \f$y_0, y_1, \ldots, y_n\f$. The polynomial at position \f$x\f$
             can be given by:
             \f[
                  \sum_{j = 0}^n \left (\prod_{k = 0//k \neq j}^{n} \frac{x-x_k}{x_j - x_k} \right ) y_j
             \f]
  */
  template <class number, class ArrT, class indexer>
  CUDA_HOS_DEV auto interpolate_from_grid_1D( const ArrT& arr,
                                              const indexer elem,
                                              const number position,
                                              const indexer to_left,
                                              const indexer to_right,
                                              const indexer separation = 1)
  {
    if (to_left < 0 || to_right < 0 || to_left + to_right == 0)
      //If we won't consider any other elements,
      //there's no interpolation going on.
      //If the number of points is negative...
      //it simply doesn't make any sense.
      {
        return arr[elem];
      }
    else if ( (to_right == 0 && position > 0) ||
              (to_left == 0 && position < 0)     )
      //If we're out of bounds and can't extrapolate...
      {
        return arr[elem];
      }
    else
      {
        auto ret = arr[elem] * 0;
        for (indexer j = -to_left; j <= to_right; ++j)
          {
            number factor = 1;
            for (indexer k = -to_left; k <= to_right; ++k)
              {
                if (j == k)
                  {
                    continue;
                  }
                factor *= position - k;
                factor /= j - k;
              }
            ret += arr[elem + j] * factor;
          }
        return ret;
      }
  }
  
  /*!
      \brief Linear interpolation in a multidimensional array.
          
      \param arr The array of discretized values from which to interpolate.
      
      \param cell The set of indices that specifies the cell from which we want to interpolate.
      
      \param positions The position at which we want to interpolate
                expressed as a vector that contains fraction of the distance
                between two elements of the array in each dimension.
                (`-1 < positions[i] < 1` for `0 <= i < dim`)
      
      \param view The `g24_lib::ndview` that expresses the multidimensional structure of the array.
      
      \remark This multidimensional interpolation works by repeated interpolation in every direction:
               we first interpolate unidimensionally in the highest dimension for the specified position,
               than we interpolate the results of that interpolation at relevant grid points in the second highest
               dimension, and so on.
               
      \remark This allows immidiate generalization to any number of dimensions, with a possible
              (slight) decrease in performance when compared to a matricial treatment of the problem
              in a fixed number of dimensions.
              However, since the number of dimensions is known at compile-time
              and the interpolations are chained together also through compile-time recursion,
              no extra memory needs to be explicitly allocated and the optimizer might be able
              to produce reasonably efficient code.
              
      
      \tparam number A type that can hold non-integer numbers. Typically floating point.
      
      \tparam indexer A type that is appropriate to hold both positive and negative offsets from a position in the array.
      
      \tparam skipped Specifies how many dimensions we are looking into.
                      (Should not be needed for any end user,
                       only for internal iteration of the function.)
                     
      \pre \p number must have addition and multiplication with the type held by the array that is being interpolated.
      
      \pre \p indexer must satisfy the constraints placed on the choice of \ref g24_lib::Definitions::default_signed_indexer.
      
      \sa g24_lib::interpolate_from_grid_1D()
  */
  template <class number, class ArrT, class indexer, indexer dim, indexer skipped = 0>
  CUDA_HOS_DEV auto interpolate_from_grid( const ArrT& arr,
                                           const fspoint<indexer, indexer, dim> cell,
                                           const fspoint<number, indexer, dim> positions,
                                           const ndview<indexer, dim> view)
  {
    if ( (cell[skipped] == view.numbers(skipped) && positions[skipped] > 0) ||
         (cell[skipped] == 0 && positions[skipped] < 0)                       )
      //If we're out of bounds and can't extrapolate...
      {
        return arr[ view[cell] ];
      }
    else
      {
        if constexpr (dim - skipped == 1)
          {
            return interpolate_from_grid_1D(arr, indexer(view[cell]), positions[skipped], view.separation(skipped));
          }
        else
          {
            return interpolate_from_grid_1D( operation_array(arr.size(),[&arr, &cell, &positions, &view](const indexer i)
                                                                        {
                                                                          return interpolate_from_grid<number,ArrT,indexer, dim, skipped+1>
                                                                            (arr, cell.add(skipped, i), positions, view); 
                                                                        } ),
              indexer(0), positions[skipped], indexer(1)           );
          }
      }
  }
  
  /*!
      \brief Polynomial interpolation in a multidimensional array.
          
      \param arr The array of discretized values from which to interpolate.
      
      \param cell The set of indices that specifies the cell from which we want to interpolate.
      
      \param positions The position at which we want to interpolate
                expressed as a vector that contains fraction of the distance
                between two elements of the array in each dimension.
                (`-1 < positions[i] < 1` for `0 <= i < dim`)
      
      \param view The `g24_lib::ndview` that expresses the multidimensional structure of the array.
      
      \param accuracy The accuracy of the polynomial interpolation. Appropriate grid points will be selected
                      taking the limits of the multidimensional array into account, given the information
                      contained in \p view.
            
      \remark This multidimensional interpolation works by repeated interpolation in every direction:
               we first interpolate unidimensionally in the highest dimension for the specified position,
               than we interpolate the results of that interpolation at relevant grid points in the second highest
               dimension, and so on.
               
      \remark This allows immidiate generalization to any number of dimensions, with a possible
              (slight) decrease in performance when compared to a matricial treatment of the problem
              in a fixed number of dimensions.
              However, since the number of dimensions is known at compile-time
              and the interpolations are chained together also through compile-time recursion,
              no extra memory needs to be explicitly allocated and the optimizer might be able
              to produce reasonably efficient code.
              
      
      \tparam number A type that can hold non-integer numbers. Typically floating point.
      
      \tparam indexer A type that is appropriate to hold both positive and negative offsets from a position in the array.
      
      \tparam skipped Specifies how many dimensions we are looking into.
                      (Should not be needed for any end user,
                       only for internal iteration of the function.)
                       
      \pre \p number must have addition and multiplication with the type held by the array that is being interpolated.
      
      \pre \p indexer must satisfy the constraints placed on the choice of \ref g24_lib::Definitions::default_signed_indexer.
      
      \sa g24_lib::interpolate_from_grid_1D()
  */
  template <class number, class ArrT, class indexer, indexer dim, indexer skipped = 0>
  CUDA_HOS_DEV auto interpolate_from_grid( const ArrT& arr,
                                           const fspoint<indexer, indexer, dim> cell,
                                           const fspoint<number, indexer, dim> positions,
                                           const ndview<indexer, dim> view,
                                           const indexer accuracy                      )
  {
    if(accuracy == 0)
      //If accuracy is zero, we don't want to interpolate at all...
      {
        return arr[ view[cell] ];
      }
    else if ( (cell[skipped] == view.numbers(skipped) && positions[skipped] > 0) ||
              (cell[skipped] == 0 && positions[skipped] < 0)                       )
      //If we're out of bounds and can't extrapolate...
      {
        return arr[ view[cell] ];
      }
    else
      {
        using namespace std;
        indexer left = min(accuracy/2 + (positions[skipped] < 0 && accuracy % 2 == 0), cell[skipped]);
        indexer right = min(accuracy/2 + (positions[skipped] > 0 && accuracy % 2 == 0), view.numbers(skipped)-cell[skipped]-1);
        //So that even accuracies use points from both sides of the cell
        //and odd accuracies use an extra point towards the side we're on,
        //and the limits of the array are taken into account.
        if constexpr (dim - skipped == 1)
          {
            return interpolate_from_grid_1D(arr, indexer(view[cell]), positions[skipped], left, right, view.separation(skipped));
          }
        else
          {
            return interpolate_from_grid_1D( operation_array(arr.size(), [&arr, &cell, &positions, &view, &accuracy](const indexer i)
                                                                         {
                                                                           return interpolate_from_grid<number, ArrT, indexer, dim, skipped+1>
                                                                             (arr, cell.add(skipped, i), positions, view, accuracy); 
                                                                         } ),
              indexer(0), positions[skipped], left, right, indexer(1)           );
          }
      }
  }
  
}
#endif

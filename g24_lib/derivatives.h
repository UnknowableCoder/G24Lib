#ifndef G24_LIB_DERIVATIVES
#define G24_LIB_DERIVATIVES

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

\file derivatives.h

\brief Provides the most common finite-difference differential operations,
       using the coefficients from `fin_diff_coeffs.h`.

\author Nuno Fernandes (main coder, current maintainer)

*/

namespace g24_lib
{
  /*!
    \brief A 1D differential operation of order \p ord weighted by \p npoints.
    
    \tparam indexer A type that is appropriate to hold the indexes of the points.
    
    \tparam factorT The factor to be used in the coefficients.
    
    \pre \p indexer must satisfy the constraints placed on the choice of \ref g24_lib::Definitions::default_unsigned_indexer.
    
    \pre \p factor_type must support multiplications and divisions with itself
         (and with the elements of the array whose derivatives will be evaluated).
         It does not need to be a floating point type since the coefficients
         are stored essentially as rational numbers.
         
    \warning Currently, the library only gives correct results for values of \p order up to (and including) 6.
    
    \warning Currently, the library only gives correct results for values of \p npoints up to (and including) `order + 7`.
    
    \remark The accuracy of the derivative will be given by `npoints - order`.
  */
  template<class indexer, class factorT,
           g24_lib::Definitions::default_unsigned_indexer ord,
           g24_lib::Definitions::default_unsigned_indexer npoints>
  class derivator
  {
    
  public:

    using fin_diff_coeff = internals::fin_diff_coeffs<indexer, factorT, ord, npoints>;
  
    CUDA_HOS_DEV inline static constexpr indexer sampled_points()
    {
      return npoints;
    }
    
    CUDA_HOS_DEV inline static constexpr indexer order()
    {
      return ord;
    }

    CUDA_HOS_DEV inline static constexpr indexer accuracy()
    {
      return npoints - ord;
    }

    /*!
      \brief Returns the coefficient for the `i`-th element of the sampled interval (or just the numerator if \p divided is `false`).
      
      \param i The index of the point under consideration.
    
      \param offset The offset from the leftmost point at which the derivative is being evaluated.
    
      \remark For instance, if the derivative would be calculated with 7 points
              and be evaluated at the central point, \p offset would be 3.
      
      \param divided If `true`, returns the coefficient proper; if `false`, 
                     returns only the numerator, with the denominator being
                     obtainable through `coefficient_denominator`.
    */
    CUDA_HOS_DEV inline static constexpr factorT coefficient(const indexer i, const indexer offset = 0, const bool divided = true)
    {
      return ( divided ? fin_diff_coeff::coeffs(i, offset) / fin_diff_coeff::factor() : fin_diff_coeff::coeffs(i, offset) );
    }

    /*!
      \brief Returns the denominator of the coefficients.
    */
    CUDA_HOS_DEV inline static constexpr factorT coefficient_denominator()
    {
      return fin_diff_coeff::factor();
    }
    
    /*!
      \brief Computes the 1D derivative of array \p arr.
      
      \param arr The array to be differentiated.
      
      \param elem The element at which the derivative is being evaluated.
      
      \param offset The offset of \p elem from the left side of set of points that are being sampled.
      
      \remark For instance, if the derivative would be calculated with 7 points
              and be evaluated at the central point, \p offset would be 3.
              
      \param sep The separation (in indices) between each member of the array
                 (to allow for multidimensional evaluations, the possibility of
                  calculating derivatives with a stride must be considered).
    */
    template <class Tarr> CUDA_HOS_DEV inline static auto derivative(const Tarr &arr,
                                                                     const indexer elem,
                                                                     const indexer offset = 0,
                                                                     const indexer sep = 1)
    {
      if constexpr (!fin_diff_coeff::valid())
        {
          exceptions::throw_exception(exceptions::undefined_derivative("Undefined (as of now) derivative [1]."));
          return arr[elem];
        }    
      auto ret = arr[elem - offset*sep]*fin_diff_coeff::coeffs(0);
      for (indexer i = 1; i < npoints; ++i)
        {
          ret += arr[elem - offset*sep  + i*sep]*fin_diff_coeff::coeffs(i);
        }
      return typename g24_lib::value_type<Tarr>(ret/fin_diff_coeff::factor());
    }
    
    /*!
      \brief Computes the 1D derivative of array \p arr taking into account the limits.
      
      \param arr The array to be differentiated.
      
      \param elem The element at which the derivative is being evaluated.
      
      \param sep The separation (in indices) between each member of the array
                 (to allow for multidimensional evaluations, the possibility of
                  calculating derivatives with a stride must be considered).
      
      \param left_constraint The accessible elements of the array to the left of the evaluation point.
      
      \param right_constraint The accessible elements of the array to the right of the evaluation point.
    */
    template <class Tarr> CUDA_HOS_DEV inline static
    g24_lib::value_type<Tarr> derivate(const Tarr &arr,
                                       const indexer elem,
                                       const indexer sep = 1,
                                       const indexer left_constraint = std::numeric_limits<indexer>::max()/2 - 1,
                                       const indexer right_constraint= std::numeric_limits<indexer>::max()/2      )
    {
      if constexpr (npoints <= 1 || !fin_diff_coeff::valid())
        {
          exceptions::throw_exception(exceptions::undefined_derivative("Undefined (as of now) derivative [2]."));
          return arr[elem];
        }
      else
        {
          indexer max = left_constraint + right_constraint + 1;
          if(max < npoints)
            {
              return derivator<indexer, factorT, ord, npoints-1>::derivate(arr, elem, sep, left_constraint, right_constraint);
            }
          else if(max > npoints && npoints % 2 == 0)
            {
              return derivator<indexer, factorT, ord, npoints+1>::derivate(arr, elem, sep, left_constraint, right_constraint);
              //So we typically use centered derivatives whenever possible,
              //for greater numerical performance without much additional cost.
            }
          else if (npoints % 2 != 0)
            {
              //REMEMBER: npoints/2 is rounded down,
              //so npoints = npoints/2 + npoints/2 + 1
              //since we should be dealing with odd cases.
              indexer left_side = std::min(left_constraint, npoints/2) + npoints/2-std::min(right_constraint, npoints/2);
              //Since max < npoints already takes care of the cases
              //where left_constraint < npoints/2 && right_constraint < npoints/2,
              //if left_constraint < npoints/2,
              //right_constraint > npoints/2,
              //which means we get std::min(left_constraint, npoints/2) == left_constraint
              //and std::min(right_constraint, npoints/2) == npoints/2
              //and left_side = left_constraint + npoints/2 - npoints/2 == left_constraint,
              //while right_constraint < npoints/2 implies
              //left_constraint > npoints/2,
              //yielding std::min(left_constraint, npoints/2) == npoints/2
              //and std::min(right_constraitn, npoints/2) == npoints/2
              //and left_side = npoints/2 + npoints/2 - right_constraint == npoints - 1 - right_constraint.
              //This is exactly the behaviour we wanted.
              return derivative(arr, elem, left_side, sep);
            }
          else
          //npoints == max and even npoints,
          //no choice without dropping accuracy.
            {
              return derivative(arr, elem, left_constraint, sep);
            }
        }
    }
  };
  
  namespace internals
  {
    /*!
      \brief Calculates a derivative with a runtime-specified accuracy.
      
      \warning Will do a linear search until a derivative with specified accuracy is found.
               One could update to a binary search, but, given the current value of
               `g24_lib::max_derivative_accuracy`, the additional complexity
               seems hardly necessary, even more so because `accuracy` might be
               commonly known at compile-time!
    */
    template < class Tarr, class indexer, class factorT, g24_lib::Definitions::default_unsigned_indexer order,
               g24_lib::Definitions::default_unsigned_indexer np = order + max_derivative_accuracy > CUDA_HOS_DEV
    inline g24_lib::value_type<Tarr> derivative_with_accuracy (const Tarr &arr,
                                                                const indexer elem,
                                                                const indexer accuracy = 1,
                                                                const indexer sep = 1,
                                                                const indexer left_constraint = std::numeric_limits<indexer>::max()/2 - 1,
                                                                const indexer right_constraint= std::numeric_limits<indexer>::max()/2      )
    {
      if constexpr (np == 0)
        {
          exceptions::throw_exception(exceptions::undefined_derivative("Undefined (as of now) derivative [4.1]."));
          return arr[elem];
        }
      else if constexpr(np > order + max_derivative_accuracy)
        {
          exceptions::throw_exception(exceptions::undefined_derivative("Undefined (as of now) derivative [4.2]."));
          return arr[elem];
        }
      else
        {
          if (np < order + accuracy)
            {
              return derivative_with_accuracy<Tarr, indexer, factorT, order, np + 1>
                        (arr, elem, accuracy, sep, left_constraint, right_constraint);
            }
          else if(np > order + accuracy)
            {
              return derivative_with_accuracy<Tarr, indexer, factorT, order, np - 1>
                        (arr, elem, accuracy, sep, left_constraint, right_constraint);
            }
          else //(np == order + accuracy)
            {
              return derivator<indexer, factorT, order, np>::derivate(arr, elem, sep, left_constraint, right_constraint);
            }
        }
    }
    
    /*!
      \brief Calculates a derivative with runtime-specified order and accuracy.
      
      \warning Will do a linear search until a derivative with specified order is found.
               Then calls `derivative_with_accuracy`.
               One could update to a binary search, but, given the current value of
               `g24_lib::max_derivative_order`, the additional complexity
               seems hardly necessary, even more so because `order` might be
               commonly known at compile-time!
    */
    template < class Tarr, class indexer, class factorT, g24_lib::Definitions::default_unsigned_indexer ord = max_derivative_order > CUDA_HOS_DEV
    inline g24_lib::value_type<Tarr> derivative_with_order (const Tarr &arr,
                                                            const indexer elem,
                                                            const indexer order = 1,
                                                            const indexer accuracy = 1,
                                                            const indexer sep = 1,
                                                            const indexer left_constraint = std::numeric_limits<indexer>::max()/2 - 1,
                                                            const indexer right_constraint= std::numeric_limits<indexer>::max()/2      )
    {
      if constexpr (ord == 0)
        {
          exceptions::throw_exception(exceptions::undefined_derivative("Undefined (as of now) derivative [5.1]."));
          return arr[elem];
        }
      else if constexpr (ord > max_derivative_order)
        {
          exceptions::throw_exception(exceptions::undefined_derivative("Undefined (as of now) derivative [5.2]."));
          return arr[elem];
        }
      else
        {
          if (ord < order)
            {
              return derivative_with_order<Tarr, indexer, factorT, ord + 1>
                        (arr, elem, order, accuracy, sep, left_constraint, right_constraint);
            }
          else if(ord > order)
            {
              return derivative_with_order<Tarr, indexer, factorT, ord - 1>
                        (arr, elem, order, accuracy, sep, left_constraint, right_constraint);
            }
          else //(ord == order)
            {
              return derivative_with_accuracy<Tarr, indexer, factorT, ord>(arr, elem, accuracy, sep, left_constraint, right_constraint);
            }
        }
    }
  }
  
  /*!
    \brief Calculates a derivative along dimension \p dimension
           of an array with multidimensional properties given by \p nd.
    
    \param dimension The dimension along which to take the derivative.
    
    \param arr The array to be differentiated.
    
    \param elem The element of the array where the derivative is meant to be computed.
    
    \param nd The `g24_lib::ndview` that expresses the multidimensional properties of the array.
    
    \param cs The cell size/grid spacing to use.
    
    \param order The order of the derivative.
    
    \param accuracy The accuracy with which to calculate the derivative.
     
    \pre \p indexer must satisfy the constraints placed on the choice of \ref g24_lib::Definitions::default_signed_indexer
          (for compatibility with ndview).
    
    \pre \p factor_type must support multiplications and divisions with itself
         (and with the elements of the array whose derivatives will be evaluated).
         It does not need to be a floating point type since the coefficients
         are stored essentially as rational numbers.
  */
  template <class Tarr, class ndview_like, class cellsizeT, class indexer = g24_lib::Definitions::default_signed_indexer,
            class factorT = g24_lib::Definitions::default_floating_point>
  CUDA_HOS_DEV inline auto derivative(const indexer dimension, const Tarr &arr, const indexer elem,
                                      const ndview_like &nd, const cellsizeT &cs,
                                      const indexer order = 1, const indexer accuracy = 2)
  {
    if(nd.dimensions() <= dimension)
      {
        exceptions::throw_exception(exceptions::undefined_derivative("Trying to take derivative in dimension unsupported by the array."));
        return arr[elem];
      }
    auto p = nd.to_point(elem);
    return internals::derivative_with_order<Tarr, indexer, factorT>
                        (arr, elem, order, accuracy, nd.separation(dimension),
                         p[dimension], nd.numbers(dimension)-p[dimension]-1   )/fastpow(cs[dimension], order);
  }
  
  /*!
    \brief Calculates the laplacian of \p arr at point \p elem.
    
    \remark This is valid both for the (scalar) laplacian of a scalar field
            and for the (vectorial, component-wise) laplacian of a vector field.
            
    \param arr The array to be differentiated.
    
    \param elem The element of the array where the derivative is meant to be computed.
    
    \param nd The `g24_lib::ndview` that expresses the multidimensional properties of the array.
    
    \param cs The cell size/grid spacing to use.
    
    \param accuracy The accuracy with which to calculate the derivative.
     
    \pre \p indexer must satisfy the constraints placed on the choice of \ref g24_lib::Definitions::default_signed_indexer
          (for compatibility with ndview).
    
    \pre \p factor_type must support multiplications and divisions with itself
         (and with the elements of the array whose derivatives will be evaluated).
         It does not need to be a floating point type since the coefficients
         are stored essentially as rational numbers.
         
  */
  template <class Tarr, class ndview_like, class cellsizeT, class indexer = g24_lib::Definitions::default_signed_indexer,
            class factorT = g24_lib::Definitions::default_floating_point>
  CUDA_HOS_DEV inline auto laplacian(const Tarr &arr, const indexer elem, const ndview_like &nd,
                                     const cellsizeT &cs, const indexer accuracy = 1)
  {
    auto ret = derivative<Tarr, ndview_like, cellsizeT, indexer, factorT>(0, arr, elem, nd, cs, 2, accuracy);
    for (indexer i = 1; i < nd.dimensions(); ++i)
      {
        ret += derivative<Tarr, ndview_like, cellsizeT, indexer, factorT>(i, arr, elem, nd, cs, 2, accuracy);
      }
    return ret;
  }
  
  /*!
    \brief Calculates the gradient of \p arr at point \p elem.
    
    \returns A `g24_lib::fspoint` holding the same type as the elements of \p arr.
    
    \remark This is valid both for the (vectorial) gradient of a scalar field
            and for the (matricial, component-wise vectorial) "gradient" of a vector field
            (that is, the Jacobian, or its determinant, depending on how one orders rows and columns).
    
    \param arr The array to be differentiated.
    
    \param elem The element of the array where the derivative is meant to be computed.
    
    \param nd The `g24_lib::ndview` that expresses the multidimensional properties of the array.
    
    \param cs The cell size/grid spacing to use.
    
    \param accuracy The accuracy with which to calculate the derivative.
     
    \pre \p indexer must satisfy the constraints placed on the choice of \ref g24_lib::Definitions::default_signed_indexer
          (for compatibility with ndview).
    
    \pre \p factor_type must support multiplications and divisions with itself
         (and with the elements of the array whose derivatives will be evaluated).
         It does not need to be a floating point type since the coefficients
         are stored essentially as rational numbers.
    
  */
  template <class Tarr, class ndview_like, class cellsizeT, class indexer = g24_lib::Definitions::default_signed_indexer,
            class factorT = g24_lib::Definitions::default_floating_point>
  CUDA_HOS_DEV inline auto gradient(const Tarr &arr, const indexer elem, const ndview_like &nd,
                                    const cellsizeT &cs, const indexer accuracy = 1)
  {
    fspoint<g24_lib::value_type<Tarr>, indexer, nd.dimensions()> ret;
    for (indexer i = 0; i < nd.dimensions(); ++i)
      {
        ret[i] = derivative<Tarr, ndview_like, cellsizeT, indexer, factorT>(i, arr, elem, nd, cs, 1, accuracy);
      }
    return ret;
  }
  
  /*!
    \brief Calculates the curl of \p arr at point \p elem.
            
    \param arr The array to be differentiated.
    
    \param elem The element of the array where the derivative is meant to be computed.
    
    \param nd The `g24_lib::ndview` that expresses the multidimensional properties of the array.
    
    \param cs The cell size/grid spacing to use.
    
    \param accuracy The accuracy with which to calculate the derivative.
     
    \pre It is assumed that \p arr is a tridimensional array holding tridimensional vectors;
         no generalizations of the curl are considered for simplicity's sake.
     
    \pre \p indexer must satisfy the constraints placed on the choice of \ref g24_lib::Definitions::default_signed_indexer
          (for compatibility with ndview).
    
    \pre \p factor_type must support multiplications and divisions with itself
         (and with the elements of the array whose derivatives will be evaluated).
         It does not need to be a floating point type since the coefficients
         are stored essentially as rational numbers.
    
  */
  template <class Tarr_vec, class ndview_like, class cellsizeT, class indexer = g24_lib::Definitions::default_signed_indexer,
            class factorT = g24_lib::Definitions::default_floating_point>
  CUDA_HOS_DEV inline auto curl(const Tarr_vec &arr, const indexer elem, const ndview_like &nd,
                                const cellsizeT &cs, const indexer accuracy = 1)
  //Neste caso, Tarr_vec, ou o retornado por Tarr_vec[],
  //terá de ter um operator[] para 0, 1, ou 2.
  {
    static_assert(nd.dimensions() == 3, "The curl (as defined here) is only valid in three dimensions.");
    using ret_t = g24_lib::value_type<Tarr_vec>;
    
    static_assert(!std::is_void_v<g24_lib::value_type<ret_t>>, "Must take curl of a vector field!");
    
    auto d_x = derivative<Tarr_vec, ndview_like, cellsizeT, indexer, factorT>(0, arr, elem, nd, cs, 1, accuracy);
    auto d_y = derivative<Tarr_vec, ndview_like, cellsizeT, indexer, factorT>(1, arr, elem, nd, cs, 1, accuracy);
    auto d_z = derivative<Tarr_vec, ndview_like, cellsizeT, indexer, factorT>(2, arr, elem, nd, cs, 1, accuracy);
    
    ret_t ret;
    
    ret[0] = d_y[2]-d_z[1];
    ret[1] = d_z[0]-d_x[2];
    ret[2] = d_x[1]-d_y[0];
    
    return ret;
  }
  
  /*!
    \brief Calculates the divergence of \p arr at point \p elem.
        
    \param arr The array to be differentiated.
    
    \param elem The element of the array where the derivative is meant to be computed.
    
    \param nd The `g24_lib::ndview` that expresses the multidimensional properties of the array.
    
    \param cs The cell size/grid spacing to use.
    
    \param accuracy The accuracy with which to calculate the derivative.
     
    \pre \p indexer must satisfy the constraints placed on the choice of \ref g24_lib::Definitions::default_signed_indexer
          (for compatibility with ndview).
    
    \pre \p factor_type must support multiplications and divisions with itself
         (and with the elements of the array whose derivatives will be evaluated).
         It does not need to be a floating point type since the coefficients
         are stored essentially as rational numbers.
         
    \pre \p arr must be an N-dimensional array holding N-dimensional vectors.
    
  */
  template <class Tarr_vec, class ndview_like, class cellsizeT, class indexer = g24_lib::Definitions::default_signed_indexer,
            class factorT = g24_lib::Definitions::default_floating_point>
  CUDA_HOS_DEV inline auto divergence(const Tarr_vec &arr, const indexer elem, const ndview_like &nd,
                                      const cellsizeT &cs, const indexer accuracy = 1)
  {
    using ret_t = g24_lib::value_type<g24_lib::value_type<Tarr_vec>>;
    static_assert(!std::is_void_v<ret_t>, "Must take divergence of a vector field!");
    ret_t ret = derivative<Tarr_vec, ndview_like, cellsizeT, indexer, factorT>(0, arr, elem, nd, cs, 1, accuracy)[0];
    for (indexer i = 1; i < nd.dimensions(); ++i)
      {
        ret += derivative<Tarr_vec, ndview_like, cellsizeT, indexer, factorT>(i, arr, elem, nd, cs, 1, accuracy)[i];
      }
    return ret;
  }

}

#endif

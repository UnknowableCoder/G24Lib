#ifndef G24_LIB_NDVIEW
#define G24_LIB_NDVIEW

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

\file ndview.h

\brief Provides a way to deal with multidimensional arrays.

\author Nuno Fernandes (main coder, current maintainer)

*/

namespace g24_lib
{
  /*!
    \brief Allows indexing of multidimensional arrays.

    \tparam indexer A type that is appropriate to hold the size of the container.
    
    \tparam dim The number of dimensions of the array.
    
    \tparam skipped Specifies how many dimensions we are looking into.
                    (Should not be needed for any end user,
                     only for internal functions.)
    
    \pre \p indexer must satisfy the constraints placed on the choice of \ref g24_lib::Definitions::default_signed_indexer.
    
  */
  template <class indexer = g24_lib::Definitions::default_signed_indexer,
            indexer dim = g24_lib::Definitions::default_fixed_size,
            indexer skipped = 0> class ndview;
  
  
  
  /*!
    \brief Holds several tag-like classes to allow selection of ranges
           instead of single elements using `g24_lib::ndview::operator[]`.
  */
  namespace view
  {
    /*!
      \brief Selects all elements in a given dimension.
    */
    struct all{};
    /*!
      \brief Selects the first and last element in a given dimension.
    */
    struct border{};
    /*!
      \brief Selects all but the first and last element in a given dimension.
    */
    struct interior{};
    /*!
      \brief Selects the first element in a given dimension.
    */
    struct min{};
    /*!
      \brief Selects the last element in a given dimension.
    */
    struct max{};
    /*!
      \brief Selects a range of elements.
      
      \tparam indexer A type that is appropriate to hold the elements of the container.
      
      \pre \p indexer must satisfy the constraints placed on the choice of \ref g24_lib::Definitions::default_unsigned_indexer.
    */
    template <class indexer = g24_lib::Definitions::default_signed_indexer> struct range
    {
      ///\cond HIDDEN_SYMBOLS
      template <class b, b, b> friend class ndview;
      ///\endcond
      
      ///The starting index
      indexer begin;
            
      ///The total number of elements considered
      indexer number;
      
      ///The stride between each element
      indexer step;
      
      /*!
        \param start The desired starting index.
        
        \param stop The desired final index.
        
        \param delta The increment between each index.
                
        \remark `g24_lib::view::range(1,8,2)` will select the elements with indices 1, 3, 5 and 7.
        
        \remark `g24_lib::view::range(11,3,-3)` will select the elements with indices 11, 8 and 5.
        
        \remark `g24:lib::view::range(7,7)` will select the element with index 7.
        
      */
      CUDA_HOS_DEV range(indexer start, indexer stop, indexer delta = 1)
      {
        begin = start;
        
        step = delta + (delta == 0);
        //So it gives 1 if delta is 0.
        
        number = (stop-start)/step;
        
        if (number < 0)
        //This means start > stop and delta > 0 or start < stop and delta < 0,
        //so we are already past the stop...
        {
          number = 0;
        }
        else
        {
          number++;
          //We also consider the starting number.
        }
        
        
        
      }
    };
  }
  
  ///\cond HIDDEN_SYMBOLS
  namespace internals
  {        
    template <class indexer, indexer dim> struct clamped_on_several
    {
      const fspoint<indexer, indexer, dim> p;
      //Not a reference due to possible lifetime issues!
    };
    
    template <class indexer> struct clamped
    {
      const indexer i;
      //Not a reference due to possible lifetime issues!
    };
    
    template <class indexer> struct clamped_range
    {
      const view::range<indexer> r;
      //Not a reference due to possible lifetime issues!
    };
    
    
    template <class ArrT, class indexer, indexer dim, indexer skipped> class ndview_printable;
  }
  ///\endcond
  namespace view
  {
    /*!
      \brief A call to `g24_lib::ndview::operator[]` with a `g24_lib::view::clamped(x)`
             will perform bound checking.
    */
    template <class indexer> CUDA_HOS_DEV internals::clamped<indexer> clamped (const indexer i)
    {
      return internals::clamped<indexer>{i};
    }
    
    /*!
      \brief A call to `g24_lib::ndview::operator[]` with a `g24_lib::view::clamped(x)`
             will perform bound checking.
    */
    template <class indexer, indexer dim>
    CUDA_HOS_DEV internals::clamped_on_several<indexer, dim> clamped(const fspoint<indexer, indexer, dim> &p)
    {
      return internals::clamped_on_several<indexer, dim>{p};
    }
    
    /*!
      \brief A call to `g24_lib::ndview::operator[]` with a `g24_lib::view::clamped(x)`
             will perform bound checking.
    */
    template <class indexer> CUDA_HOS_DEV internals::clamped_range<indexer> clamped (const view::range<indexer> &r)
    {
      return internals::clamped_range<indexer>{r};
    }
  }
  
  template <class indexer, indexer dim, indexer skipped>
  class ndview
  {
    template <class b, b, b> friend class ndview;
      
  private:
    fspoint <indexer, indexer, dim> num, sep;
    //num is the number of elements in each dimension
    //sep is the seperation between elements in the same dimension
    
    //These are stored in reverse order:
    //ndview[1] will use, for instance, sep[dim-1].
    
    indexer off;
    //An additional offset.
    
    static constexpr indexer coord = dim - skipped - 1;
    //The coordinate that will actually be specified in this ndview.
  public:
  
    template<indexer other_skip> CUDA_HOS_DEV inline ndview(const ndview<indexer, dim, other_skip> & nd):
    num(nd.num), sep(nd.sep), off(nd.off) {}
    
    template<indexer other_skip> CUDA_HOS_DEV ndview<indexer, dim, skipped> & operator= (const ndview<indexer, dim, other_skip> &nd)
    {
      if(other_skip != skipped || &nd != this)
        {
          num = nd.num;
          sep = nd.sep;
          off = nd.off;
        }
      return (*this);
    }
  
  
    CUDA_HOS_DEV ndview()
    {
    }
    
  private:
    CUDA_HOS_DEV inline static fspoint<indexer, indexer, dim> get_separation(const fspoint<indexer, indexer, dim> &number)
    //This is reversed, that is, ret[0] is the highest dimension,
    //and it also expects number[0] to be the highest dimension
    {
      fspoint<indexer, indexer, dim> ret;
      ret[0] = 1;
      for(indexer i = 1; i < dim; ++i)
        {
          ret[i] = ret[i-1]*number[i-1];
        }
      return ret;
    }
    
  public:
    CUDA_HOS_DEV ndview(const fspoint<indexer, indexer, dim> &number, const indexer offset = 0):
      num(number.reverse()), sep(get_separation(number.reverse())), off(offset)
    {
    }
    
    CUDA_HOS_DEV ndview(const fspoint<indexer, indexer, dim> &number,
                        const fspoint<indexer, indexer, dim> &separation,
                        const indexer offset = 0, const bool needs_reverse = true):
      num(number.reverse(needs_reverse)), sep(separation.reverse(needs_reverse)) , off(offset)
    {
    }
        
    template <indexer w, indexer x> CUDA_HOS_DEV ndview(const ndview<indexer, w, x> &v):
      num(v.num), sep(v.sep), off(v.off)
    {
    }

    template <indexer w, indexer x> CUDA_HOS_DEV operator ndview<indexer, w, x>() const
    {
      return ndview<indexer, w, x>(*this);
    }
  
    /*!
        \brief The base offset.
    */
    CUDA_HOS_DEV inline indexer offset() const    
    {
      return off;
    }
    
    /*!
      \brief The number of dimensions of this view.
    */
    CUDA_HOS_DEV inline static constexpr indexer dimensions()
    {
      return dim;
    }
    
    private:
    
    CUDA_HOS_DEV inline static
    fspoint<indexer, indexer, dim> to_point_from_separation(const fspoint<indexer, indexer, dim> other_sep,
                                                                    const indexer i)
    //We disregard any offset,
    //that is, the caller must ensure i is offset-free.
    
    //Both other_sep and the return point have the highest dimension at 0.
    {
      indexer m = i;
      fspoint<indexer, indexer, dim> res;
      for (indexer j = 0; j < dim; ++j)
        {
          res[dim-j-1] = m/other_sep[dim-j-1];
          m = m % other_sep[dim-j-1];
        }
      return res;
    }
        
    public:
    
    /*!
      \brief Turns a scalar index (an element) into a set of multidimensional indices (a point).
      
      \param i The index.
      
      \param in_array If `true`, the index refers to the base array,
                      so the offset must be subtracted from it and the proper
                      separations between the elements considered
                      (since the view may have a stride larger than 1).
                      If `false`, the index simply refers to the specified view,
                      so no offset needs to be considered and all the elements
                      become sequential.
      
    */
    CUDA_HOS_DEV inline fspoint<indexer, indexer, dim> to_point(const indexer i, const bool in_array = true) const
    {
      if (in_array)
        {
          return to_point_from_separation(sep, i - off).reverse();
        }
      else
        {
          return to_point_from_separation(get_separation(num), i).reverse();
        }
    }
    
    /*!
      \brief Turns a set of multidimensional entries (a point) into a scalar index (an element).
      
      \param p The point.
      
      \param in_array If `true`, the index refers to the base array,
                      so the offset must be added to it and the proper
                      separations between the elements considered
                      (since the view may have a stride larger than 1).
                      If `false`, the index simply refers to the specified view,
                      so no offset needs to be considered and all the elements
                      become sequential.
    */
    CUDA_HOS_DEV inline indexer to_elem(const fspoint<indexer, indexer, dim> &p, const bool in_array = true) const
    {
      if(in_array)
        {
          return sep.dotp(p.reverse()) + off;
        }
      else
        {
          return get_separation(num).dotp(p.reverse());
        }
    }
        
    /*!
      \brief Checks if a point is outside the multimensional array specified by this `ndview`.
    */
    CUDA_HOS_DEV inline bool is_outside(const fspoint<indexer, indexer, dim> &p) const
    {
      for(indexer j = 0; j < dim; ++j)
        {
          if(p[j] < 0 || p[j] > num[dim-j-1] - 1)
            {
              return true;
            }
        }
      return false;
    }
    
    /*!
      \brief Checks if a point is on the border of the multimensional array specified by this `ndview`.
    */
    CUDA_HOS_DEV inline bool is_border(const fspoint<indexer, indexer, dim> &p) const
    {
      for(indexer j = 0; j < dim; ++j)
        {
          if(p[j] == 0 || p[j] == num[dim-j-1] - 1)
            {
              return true;
            }
        }
      return false;
    }
    
    /*!
      \brief Checks if a point is inside the multimensional array specified by this `ndview`.
    */
    CUDA_HOS_DEV inline bool is_inside(const fspoint<indexer, indexer, dim> &p) const
    {
      for(indexer j = 0; j < dim; ++j)
        {
          if(p[j] <= 0 || p[j] >= num[dim-j-1] - 1)
            {
              return false;
            }
        }
      return true;
    }
    
    /*!
      \brief Checks if a point is contained (either inside or on the border)
             in the multimensional array specified by this `ndview`.
    */
    CUDA_HOS_DEV inline bool is_contained(const fspoint<indexer, indexer, dim> &p) const
    {
      return !is_outside(p);
    }
      
    /*!
      \brief Checks if an element is on the border of the multimensional array specified by this `ndview`.
      
      \param elem The index.
      
      \param in_array If `true`, the index refers to the base array,
                      so the offset must be subtracted from it and the proper
                      separations between the elements considered
                      (since the view may have a stride larger than 1).
                      If `false`, the index simply refers to the specified view,
                      so no offset needs to be considered and all the elements
                      become sequential.
    */
    CUDA_HOS_DEV inline bool is_border(const indexer elem, const bool in_array = true) const
    {
      return is_border(to_point(elem, in_array));
    }
    
    /*!
      \brief Checks if an element is outside the multimensional array specified by this `ndview`.
      
      \param elem The index.
      
      \param in_array If `true`, the index refers to the base array,
                      so the offset must be subtracted from it and the proper
                      separations between the elements considered
                      (since the view may have a stride larger than 1).
                      If `false`, the index simply refers to the specified view,
                      so no offset needs to be considered and all the elements
                      become sequential.
    */
    CUDA_HOS_DEV inline bool is_outside(const indexer elem, const bool in_array = true) const
    {
      return is_outside(to_point(elem, in_array));
    }
    
    /*!
      \brief Checks if an element is inside the multimensional array specified by this `ndview`.
      
      \param elem The index.
      
      \param in_array If `true`, the index refers to the base array,
                      so the offset must be subtracted from it and the proper
                      separations between the elements considered
                      (since the view may have a stride larger than 1).
                      If `false`, the index simply refers to the specified view,
                      so no offset needs to be considered and all the elements
                      become sequential.
    */
    CUDA_HOS_DEV inline bool is_inside(const indexer elem, const bool in_array = true) const
    {
      return is_inside(to_point(elem, in_array));
    }
    
    /*!
      \brief Checks if an element is contained (either inside or on the border)
             in the multimensional array specified by this `ndview`.
      
      \param elem The index.
      
      \param in_array If `true`, the index refers to the base array,
                      so the offset must be subtracted from it and the proper
                      separations between the elements considered
                      (since the view may have a stride larger than 1).
                      If `false`, the index simply refers to the specified view,
                      so no offset needs to be considered and all the elements
                      become sequential.
    */
    CUDA_HOS_DEV inline bool is_contained(const indexer elem, const bool in_array = true) const
    {
      return !is_outside(elem, in_array);
    }
    
    /*!
      \brief Offsets the array view by an amount specified by \p i.
    */
    CUDA_HOS_DEV inline ndview<indexer, dim, skipped> offset_view(const indexer i) const
    {
      return ndview<indexer, dim, skipped>(num, sep, off + i);
    }
    
    inline bool operator== (const ndview &v) const
    {
      return (num == v.num && sep == v.sep && off == v.off);
    }
    
    inline bool operator!= (const ndview &v) const
    {
      return !((*this) == v);
    }
    
    /*!
      \brief This casting enables one to easily write `cont[ndview[a][b][c][d]...]` for a container `cont`.
    */
    CUDA_HOS_DEV inline operator indexer() const
    {
      return offset();
    }
        
    /*!
      \brief Returns the number of elements in the specified multidimensional array.
    */
    CUDA_HOS_DEV inline indexer count_all() const
    {
      return num.multiply_all();
    }
    
    /*!
      \brief Returns the number of elements in the interior of the specified multidimensional array.
    */
    CUDA_HOS_DEV inline indexer count_interior() const
    {
      using namespace std;
      //To ensure it works with CUDA...
      indexer ret = 1;
      for (indexer i = 0; i < dim; ++i)
        {
          ret *= max(indexer(num[i]), indexer(2)) - indexer(2);
        }
      return ret;
    }
    
    /*!
      \brief Returns the number of elements on the border of the specified multidimensional array.
    */
    CUDA_HOS_DEV inline indexer count_border() const
    {
      using namespace std;
      //To ensure it works with CUDA...
      
      indexer ret1 = 1, ret2 = 1;
      for (indexer i = 0; i < dim; ++i)
        {
          ret1 *= max(indexer(num[i]), indexer(2)) - indexer(2);
          //This gives the elements in the interior
          
          ret2 *= num[i];
          //This gives the total number of elements
        }
      return ret2 - ret1;
      //The elements that are not in the interior will,
      //by definition, lie on the border.
    }
    
    /*!
      \brief Returns the size of an (unidimensional) array built from the elements specified by this `ndview`.
      
      \remark Algorithmically identical to `count_all()` in that it merely returns
              the total number of elements that this `ndview` specifies,
              but provided as a separate function for semantic reasons.
    */
    CUDA_HOS_DEV inline indexer array_size() const
    {
      return count_all();
    }
    
    /*!
      \brief Returns the minimum needed size for an array to hold all the elements
             accessible through this `ndview`.
             
      \remark This takes into account the offset and the separation between members,
              so it can be used to check against an accessed array's size to ensure
              nothing is out of bounds.
    */
    CUDA_HOS_DEV inline indexer minimum_required_size() const
    {
      return off + num.dotp(sep);
      //A base offset is of course needed,
      //the other term is basically the element
      //that has the highest coordinate possible in every dimension.
    }
    
    /*!
      \brief Returns a `g24_lib::ndview` that encompasses the closest neighbors of the point (and the point itself),
             bounded by the limits of the array.
      
      \param p The point whose neighbors we want to get.
      
      \param how_much How many neighbors we want.
      
      \remark For a simple case of a bidimensional array:
~~~{}
a b c d e
f g h i j
k l m n o
p q r s t
u v w x y
~~~
      \remark `neighbor_view(g24_lib::fspoint<int, int, 2>{2,2},2)` would give the whole array.
      
      \remark `neighbor_view(g24_lib::fspoint<int, int, 2>{1,1},1)` would give:
~~~{}
a b c
f g h
k l m
~~~
    */
    CUDA_HOS_DEV inline ndview<indexer, dim, skipped>
    neighbor_view(const fspoint<indexer, indexer, dim> &p, const indexer how_much = 1) const
    {
      if constexpr (skipped >= dim)
        {
          return (*this);
        }
      else
        {
          using namespace std;
          return ndview<indexer, dim, skipped>(   
                                                  ((*this)[ view::range( max(indexer(0),p[skipped]-how_much),
                                                                         min(num[coord]-indexer(1),p[skipped]+how_much) ) ]
                                                  ).neighbor_view(p, how_much)
                                              );
        }
    }
    
    /*!
      \brief Returns a `g24_lib::ndview` that encompasses the closest neighbors of an element (and the element itself),
             bounded by the limits of the array.
      
      \param elem The element whose neighbors we want to get.
      
      \param how_much How many neighbors we want.
      
      \param in_array If `true`, the index refers to the base array,
                      so the offset must be subtracted from it and the proper
                      separations between the elements considered
                      (since the view may have a stride larger than 1).
                      If `false`, the index simply refers to the specified view,
                      so no offset needs to be considered and all the elements
                      become sequential.
                      
      \remark For a simple case of a bidimensional array:
~~~{}
a b c d e
f g h i j
k l m n o
p q r s t
u v w x y
~~~
      \remark `neighbor_view(12,2)` would give the whole array.
      
      \remark `neighbor_view(6,1)` would give:
~~~{}
a b c
f g h
k l m
~~~

    */
    CUDA_HOS_DEV inline ndview<indexer, dim, skipped>
    neighbor_view(const indexer elem, const indexer how_much = 1, const bool in_array = true) const
    {
      return neighbor_view(to_point(elem, in_array), how_much);
    }
    
    /*!
      \brief Gives the `g24_lib::fspoint` that holds the strides between each element along every dimension.
    */
    CUDA_HOS_DEV inline fspoint <indexer, indexer, dim> separation() const
    {
      return sep.reverse();
    }
    
    /*!
      \brief Gives the `g24_lib::fspoint` that holds the number of elements along every dimension.
    */
    CUDA_HOS_DEV inline fspoint <indexer, indexer, dim> numbers() const
    {
      return num.reverse();
    }
    
    /*!
      \brief Gives the stride between each element along the `i`-th dimension.
    */
    CUDA_HOS_DEV inline indexer separation(const indexer i) const
    {
      return sep[dim-i-1];
    }
    
    /*!
      \brief Gives the number of elements along the `i`-th dimension.
    */
    CUDA_HOS_DEV inline indexer numbers(const indexer i) const
    {
      return num[dim-i-1];
    }
    
    /*!
      \brief Resets the view to an unskipped one.
      
      \remark Suppose `view` is an `N`-dimensional `g24_lib::ndview`.
              `view[0]` will behave essentially as an `(N-1)`-dimensional `g24_lib::ndview`,
              but there are some cases where it might be useful to consider it
              an `N`-dimensional `g24_lib::ndview` with only one element in the first dimension.
              For these cases, we just call `view[0].reset()`.
    */
    CUDA_HOS_DEV inline ndview<indexer, dim, 0> reset() const
    {
      return ndview<indexer, dim, 0>(*this);
    }
    
    
    /*!
      \brief Skips a dimension without changing anything.
      
      \remark It's functionally equivalent to call either `ndview.skip()` or
              `ndview[g24_lib::view::all()]`. Provided for potential user convenience.
    */
    CUDA_HOS_DEV ndview<indexer, dim, skipped+1> skip() const
    {
      return ndview<indexer, dim, skipped+1>(*this);
    }
    
    
    /*!
      \brief Selects the elements with coordinate \p i in the lowest dimension not yet specified.
    */
    CUDA_HOS_DEV inline ndview<indexer, dim, skipped + 1> operator[] (const indexer i) const
    {
      if constexpr(skipped >= dim)
        {          static_assert(skipped < dim, "Trying to access too many dimensions of ndview!");        }
      else
        {
          ndview <indexer, dim, skipped+1> ret(num.set(coord, 1), sep, off + i * sep[coord], false);
          return ret;
        }
    }
    
    /*!
      \brief Selects the elements with any coordinate in the lowest dimension not yet specified.
    */
    CUDA_HOS_DEV inline ndview <indexer, dim, skipped + 1> operator[] (const view::all dummy) const
    {
      if constexpr(skipped >= dim)
        {          static_assert(skipped < dim, "Trying to access too many dimensions of ndview!");        }
      else
        {
          return ndview <indexer, dim, skipped + 1>(*this);
        }
    }
    
    /*!
      \brief Selects the elements with the first or last possible coordinate in the lowest dimension not yet specified.
    */
    CUDA_HOS_DEV inline ndview <indexer, dim, skipped + 1> operator[] (const view::border dummy) const
    {
      if constexpr(skipped >= dim)
        {          static_assert(skipped < dim, "Trying to access too many dimensions of ndview!");        }
      else
        {
          using namespace std;
          ndview <indexer, dim, skipped+1> ret(num.set(coord, min(indexer(2), num[coord])),
                                               sep.multiply(coord, max(num[coord]-indexer(1),indexer(1)), off, false);
          return ret;
        }
    }
    /*!
      \brief Selects the elements with any coordinate but the first or last in the lowest dimension not yet specified.
    */
    CUDA_HOS_DEV inline ndview <indexer, dim, skipped + 1>  operator[] (const view::interior dummy) const
    {
      if constexpr(skipped >= dim)
        {          static_assert(skipped < dim, "Trying to access too many dimensions of ndview!");        }
      else
        {
          using namespace std;
          ndview <indexer, dim, skipped+1> ret(num.set(coord, max(num[coord]-indexer(2),indexer(0))), sep, off + sep[coord], false);
          return ret;
        }
    }
    
    /*!
      \brief Selects the elements with the first coordinate in the lowest dimension not yet specified.
    */
    CUDA_HOS_DEV inline ndview<indexer, dim, skipped + 1> operator[] (const view::min dummy) const
    {
      if constexpr(skipped >= dim)
        {          static_assert(skipped < dim, "Trying to access too many dimensions of ndview!");        }
      else
        {
          ndview <indexer, dim, skipped+1> ret(num.set(coord,1), sep, off, false);
          return ret;
        }
    }
    
    /*!
      \brief Selects the elements with the last coordinate in the lowest dimension not yet specified.
    */
    CUDA_HOS_DEV inline ndview<indexer, dim, skipped + 1> operator[] (const view::max dummy) const
    {
      if constexpr(skipped >= dim)
        {          static_assert(skipped < dim, "Trying to access too many dimensions of ndview!");        }
      else
        {
          using namespace std;
          ndview <indexer, dim, skipped+1> ret(num.set(coord,1), sep, off + max(num[coord]-indexer(1),indexer(0))*sep[coord]);
          return ret;
        }
    }
    
    /*!
      \brief Selects the elements within the provided range in the lowest dimension not yet specified.
    */
    template <class convertable>
    CUDA_HOS_DEV inline ndview <indexer, dim, skipped + 1>  operator[] (const view::range<convertable> &r) const
    {
      if constexpr(skipped >= dim)
        {          static_assert(skipped < dim, "Trying to access too many dimensions of ndview!");        }
      else
        {
          ndview <indexer, dim, skipped+1> ret(num.set(coord, r.number), sep.multiply(coord, r.step),
                                               off + sep[coord] * r.begin, false);
          return ret;
        }
    }
    /*!
      \brief Selects the elements with coordinates specified by the `m`-dimensional point \p p
             in the `m` lowest dimensions not yet specified.
    */
    template <indexer m>
    CUDA_HOS_DEV inline ndview<indexer, dim, skipped + m> operator[] (const fspoint<indexer, indexer, m> &p) const
    {
      if constexpr(skipped >= dim)
        {          static_assert(skipped < dim, "Trying to access too many dimensions of ndview!");        }
      else
        {
          fspoint<indexer, indexer, dim> tnum;
          indexer toff = off;
          for (indexer j = 0; j < m && j <= coord; ++j)
            {
              tnum[coord-j] = 1;
              toff += p[j] * sep[coord-j];
            }
          ndview <indexer, dim, skipped+m> ret(tnum, sep, toff, false);
          return ret;
        }
    }
    /*!
      \brief Selects the elements with coordinate \p i in the lowest dimension not yet specified,
             clamped by the limits provided for the array.
    */
    template <class convertable, indexer m>
    CUDA_HOS_DEV inline ndview<indexer, dim, skipped + m> operator[] (const internals::clamped<convertable> &i) const
    {
      if constexpr(skipped >= dim)
        {          static_assert(skipped < dim, "Trying to access too many dimensions of ndview!");        }
      else
        {
          using namespace std;
          ndview <indexer, dim, skipped+1> ret(num.set(coord, 1), sep,
                                               off + sep[coord] * min(max(i.i, indexer(0)), num[coord]-indexer(1)), false);
          
          return ret;
        }
    }
    /*!
      \brief Selects the elements with coordinates specified by the `m`-dimensional point \p p
             in the `m` lowest dimensions not yet specified,
             clamped by the limits provided for the array.
    */
    template <indexer m>
    CUDA_HOS_DEV inline ndview<indexer, dim, skipped + m> operator[] (const internals::clamped_on_several<indexer, m> &p) const
    {
      if constexpr(skipped >= dim)
        {          static_assert(skipped < dim, "Trying to access too many dimensions of ndview!");        }
      else
        {
          using namespace std;
          fspoint<indexer, indexer, dim> tnum;
          indexer toff = off;
          for (indexer j = 0; j < m && j <= coord; ++j)
            {
              tnum[coord-j] = 1;
              toff += min(max(p.p[j], indexer(0)), num[coord-j]-indexer(1)) * sep[coord-j];
            }
          ndview <indexer, dim, skipped+m> ret(tnum, sep, toff, false);
          return ret;
        }
    }
    
    /*!
      \brief Selects the elements within the provided range in the lowest dimension not yet specified,
             clamped by the limits provided for the array.
    */
    template <class convertable>
    CUDA_HOS_DEV inline ndview <indexer, dim, skipped + 1>  operator[] (const internals::clamped_range<convertable> &r) const
    {
      if constexpr(skipped >= dim)
        {
          static_assert(skipped < dim, "Trying to access too many dimensions of ndview!");
        }
      else
        {
          using namespace std;
          
          indexer new_start = min(max(r.r.start, indexer(0)), num[coord] - indexer(1));
          
          indexer new_end = min(max(r.r.start + r.r.number * g24_lib::sign(r.r.step), indexer(0)), num[coord] - indexer(1));
          
          indexer new_num = abs(new_end-new_start)/r.r.step;
          
          ndview <indexer, dim, skipped+1> ret(num.set(coord, new_num),
                                               sep.multiply(coord, r.r.step),
                                               off + sep[coord] * new_start, false);
          return ret;
        }
    }
    /*
      private:
      template <class ... Rest> CUDA_HOS_DEV ndview<indexer, dim, skipped + sizeof...(Rest)> operator() (Rest ... others) const {return (*this);}

      public:
      template <class first_type, class ... Args> ndview<indexer, dim, skipped + 1 + sizeof...(Args)> operator() (first_type first, Args ... others) const
      {
      return (*this)[first](others...);
      }
      //Does not perform too good...
    */
    
    private:
            
      struct operate_functor
      {
      //f must take as arguments (container, i, to_point(i), args...)
      //Expectably does something with container[i]...
        template <class Arr, class Func, class ... Args>
        CUDA_HOS_DEV inline void operator () (const g24_lib::empty_array<g24_lib::value_type<Arr>, indexer>& dummy,
                                              const indexer i,
                                              const ndview<indexer, dim, 0> &view,
                                              const fspoint<indexer, indexer, dim> &sep_in_view,
                                              const fspoint<indexer, indexer, dim> &offset_point,
                                              Arr && arr,
                                              Func && f,
                                              Args &&... args) const
        {
          const fspoint<indexer, indexer, dim> p = view.to_point_from_separation(sep_in_view, i).reverse()
                                                    + offset_point;
          //This is the set of coordinates that apply to the specified element.
          
          const indexer real_index = view.to_elem(p, true);
          //And this is the index that really corresponds to them in the array.
          
          f(std::forward<Arr>(arr), real_index, p, std::forward<Args>(args)...);
        }
      };
      friend struct operate_functor;    
      
    public:
  
    /*!
      \brief Performs operation given by \p f on all elements of a multidimensional array \p arr
             described by this \c ndview.
      
      \param arr The array on which to operate
      
      \param f The function to apply on the elements of arr.
      
      \param args Extra arguments to be passed to \p f
      
      \tparam Arr The type of the array on which we will operate.
      
      \tparam Func The type that holds the function to be applied to the elements of the array.
      
      \tparam Args The types for any extra arguments to \p Func.
      
      \pre \p f must take as arguments (a reference to) \p arr, the index at which we're evaluating,
            the multidimensional position at which we're evaluating
            and any extra arguments passed to this function in \p args.
            
      \pre \p parallel must be a valid type of parallelism, that is, it must satisfy `g24_lib::is_parallelism`.
    */
    template <class parallel, class Arr, class Func, class ... Args>
    CUDA_HOS_DEV inline void operate_on_all(Arr&& arr, Func&& f, Args &&... args) const
    {
      static_assert(g24_lib::is_parallelism<parallel>, "Must be using a valid form of parallelism!");
      parallel::loop(g24_lib::empty_array<g24_lib::value_type<Arr>, indexer>{this->count_all()},
                     operate_functor{},
                     ndview<indexer, dim, 0> (*this),
                     get_separation(num),
                     g24_lib::fspoint<indexer, indexer, dim>(indexer(0)),
                     std::forward<Arr>(arr),
                     std::forward<Func>(f),
                     std::forward<Args>(args)...);
    }
    
    /*!
      \brief Performs operation given by \p f on the interior of a multidimensional array \p arr
             described by this \c ndview.
      
      \param arr The array on which to operate
      
      \param f The function to apply on the elements of arr.
      
      \param args Extra arguments to be passed to \p f
      
      \tparam Arr The type of the array on which we will operate.
      
      \tparam Func The type that holds the function to be applied to the elements of the array.
      
      \tparam Args The types for any extra arguments to \p Func.
      
      \pre \p f must take as arguments (a reference to) \p arr, the index at which we're evaluating,
            the multidimensional position at which we're evaluating
            and any extra arguments passed to this function in \p args.
            
      \pre \p parallel must be a valid type of parallelism, that is, it must satisfy `g24_lib::is_parallelism`.
    */
    template <class parallel, class Arr, class Func, class ... Args>
    CUDA_HOS_DEV inline void operate_on_interior(Arr&& arr, Func&& f, Args &&... args) const
    {
      static_assert(g24_lib::is_parallelism<parallel>, "Must be using a valid form of parallelism!");
      
      g24_lib::fspoint<indexer, indexer, dim> interior_number;
      
      using namespace std;
      for (indexer i = 0; i < dim; ++i)
        {
          interior_number[i] = max(num[i], indexer(2)) - 2;
        }
      
      parallel::loop(g24_lib::empty_array<g24_lib::value_type<Arr>, indexer>{this->count_interior()},
                     operate_functor{},
                     ndview<indexer, dim, 0> (*this),
                     get_separation(interior_number),
                     fspoint<indexer, indexer, dim>(indexer(1)),
                     std::forward<Arr>(arr),
                     std::forward<Func>(f),
                     std::forward<Args>(args)...);
    }
      
  private:
      
      
    template <class parallel, class Arr, class Func, class ... Args>
    CUDA_HOS_DEV inline void operate_on_border_inner(const ndview<indexer, dim, 0> &original_view,
                                                     fspoint<indexer, indexer, dim> offset_p,
                                                     Arr&& arr, Func&& f, Args &&... args) const
    {
      if constexpr (skipped == dim)
        {
          return;
        }
      else
        {
          parallel::loop(g24_lib::empty_array<g24_lib::value_type<Arr>, indexer>{this->count_all()/num[dim-skipped-1]},
                         operate_functor{},
                         original_view,
                         get_separation(num.set(dim-skipped-1,1)),
                         offset_p.set(skipped,0),
                         std::forward<Arr>(arr),
                         std::forward<Func>(f),
                         std::forward<Args>(args)...);
          parallel::loop(g24_lib::empty_array<g24_lib::value_type<Arr>, indexer>{this->count_all()/num[dim-skipped-1]},
                         operate_functor{},
                         original_view,
                         get_separation(num.set(dim-skipped-1,1)),
                         offset_p.set(skipped,num[dim-skipped-1]-1),
                         std::forward<Arr>(arr),
                         std::forward<Func>(f),
                         std::forward<Args>(args)...);
          for (indexer i = 1; i < num[dim-skipped-1] - 1; ++i)
            {
              (*this)[i].template operate_on_border_inner<parallel>( original_view,
                                                                     offset_p.set(skipped, i),
                                                                     std::forward<Arr>(arr),
                                                                     std::forward<Func>(f),
                                                                     std::forward<Args>(args)... );
            }
        }
    }
    
  public:
  
    /*!
      \brief Performs operation given by \p f on the border of a multidimensional array \p arr
             described by this \c ndview.
      
      \param arr The array on which to operate
      
      \param f The function to apply on the elements of arr.
      
      \param args Extra arguments to be passed to \p f
      
      \tparam Arr The type of the array on which we will operate.
      
      \tparam Func The type that holds the function to be applied to the elements of the array.
      
      \tparam Args The types for any extra arguments to \p Func.
      
      \pre \p f must take as arguments (a reference to) \p arr, the index at which we're evaluating,
            the multidimensional position at which we're evaluating
            and any extra arguments passed to this function in \p args.
            
      \pre \p parallel must be a valid type of parallelism, that is, it must satisfy `g24_lib::is_parallelism`.
      
      \warning It is assumed that the overhead for calling a parallel loop is negligible.
               For cases where that is not so, performance issues may ensue.
               A possible alternative is using `operate_on_all` with an operation
               that checks first if the element is in the border
               and only performs the operation if so.
    */
    template <class parallel, class Arr, class Func, class ... Args>
    CUDA_HOS_DEV inline void operate_on_border(Arr&& arr, Func&& f, Args &&... args) const
    {
      static_assert(g24_lib::is_parallelism<parallel>, "Must be using a valid form of parallelism!");
      if constexpr (skipped == 0)
        {
          operate_on_border_inner<parallel>(*this,
                                            fspoint<indexer, indexer, dim>(indexer(0)),
                                            std::forward<Arr>(arr),
                                            std::forward<Func>(f),
                                            std::forward<Args>(args)...);
        }
      else
      //So that view[i].operate_on_border_inner sees this as a proper N-dimensional view.
        {
          ndview<indexer, dim, 0> other(*this);
          other.operate_on_border(std::forward<Arr>(arr), std::forward<Func>(f), std::forward<Args>(args)...);
        }
    }
    
    private:
    
      struct set_functor
      {
        template <class Container>
        CUDA_HOS_DEV inline void operator() (Container &c,
                                            const indexer i,
                                            const fspoint<indexer, indexer, dim> &dummy,
                                            const g24_lib::value_type<Container> &val)
        {
          c[i] = val;
        }
      };
      
    public:
    
    /*!
      \brief Sets all elements of \p arr to \p val.
      
      \param arr The array on which to operate
      
      \param val The value to which the array should be set.
            
      \pre \p parallel must be a valid type of parallelism, that is, it must satisfy `g24_lib::is_parallelism`.
    */
    template <class parallel, class Arr>
    CUDA_HOS_DEV inline void set_all(Arr& arr, const g24_lib::value_type<Arr> &val) const
    {
      this->template operate_on_all<parallel>(arr, set_functor{}, val);
    }
    
    /*!
      \brief Sets the interior of \p arr to \p val.
      
      \param arr The array on which to operate
      
      \param val The value to which the array should be set.
            
      \pre \p parallel must be a valid type of parallelism, that is, it must satisfy `g24_lib::is_parallelism`.
    */
    template <class parallel, class Arr>
    CUDA_HOS_DEV inline void set_interior(Arr& arr, const g24_lib::value_type<Arr> &val) const 
    {
      this->template operate_on_interior<parallel>(arr, set_functor{}, val);
    }
    
    
    /*!
      \brief Sets the border of \p arr to \p val.
      
      \param arr The array on which to operate
      
      \param val The value to which the array should be set.
            
      \pre \p parallel must be a valid type of parallelism, that is, it must satisfy `g24_lib::is_parallelism`.
      
      \warning It is assumed that the overhead for calling a parallel loop is negligible.
               For cases where that is not so, performance issues may ensue.
               A possible alternative is using `operate_on_all` with an operation
               that checks first if the element is in the border
               and only performs the operation if so.
    */
    template <class parallel, class Arr>
    CUDA_HOS_DEV inline void set_border(Arr& arr, const g24_lib::value_type<Arr> &val) const
    {
      this->template operate_on_border<parallel>(arr, set_functor{}, val);
    }
    
    /*!
      \brief Provides a quick way to print an array structured through an \c ndview using `operator<<` with some stream.
      
      \param arr The array to be printed.
      
      \param print_coordinates If `true`, prints the coordinates to the sides, as if in a table.
      
      \param width The desired minimum width of each printed element.
    */
    template <class ArrT> internals::ndview_printable<ArrT, indexer, dim, skipped>
    printable(const ArrT &arr, bool print_coordinates = false, std::streamsize width = 6) const
    {
      return internals::ndview_printable<ArrT, indexer, dim, skipped>(*this, arr, print_coordinates, width);
    }
  };
    
  namespace internals
  {
      /*!
        \brief A forwarding structure to allow printing of an array with an ndview.
      */
    template <class ArrT, class indexer, indexer dim, indexer skipped> class ndview_printable
    {
    private:
      template <class a, class b, b, b> friend class ndview_printable;
      const ndview<indexer, dim, skipped> v;
      const ArrT& arr;
      const bool print_coordinates;
      const std::streamsize write_width;
      template<class stream> void ndview_printable_print(stream &s, const g24_lib::fspoint<indexer, indexer, dim> &p) const
      {
        if (v.count_all() > 0)
          {
            std::streamsize desired, w = s.width();
            
            if (write_width == 0)
              {
                desired = std::max(std::max(std::numeric_limits<g24_lib::value_type<ArrT>>::max_digits10,
                                            std::numeric_limits<g24_lib::value_type<ArrT>>::digits10),
                                   std::numeric_limits<g24_lib::value_type<ArrT>>::digits);
              }
            else
              {
                desired = write_width;
              }
            std::ios::fmtflags f = s.setf(std::ios::right, std::ios::adjustfield);
            if constexpr(dim - skipped == 1)
              {
                s << "\n   ";
                for(indexer j = 0; j < v.numbers(0); ++j)
                  {
                    s << std::setw(desired);
                    textual_output(s,arr[v[j]],'_');
                    s << " ";
                  }
                s << "\n";
              }
            else if constexpr(dim - skipped == 2)
              {
                if (dim > 2)
                  {
                    s << g24_lib::fspoint<indexer, indexer, dim -2>(p) <<"\n";
                  }
                for(indexer j = 0; j < v.numbers(dim-2); ++j)
                  {
                    s << "\n";
                    for(indexer k = 0; k < v.numbers(dim-1); ++k)
                      {
                        s << std::setw(desired);
                        textual_output(s,arr[v[j][k]],'_');
                        s << " ";
                      }
                  }
                s << "\n\n";
              }
            else if constexpr(dim > skipped + 2)
              {
                for (indexer j = 0; j < v.numbers(skipped); ++j)
                  {
                    (v[j]).printable(arr, print_coordinates, write_width).ndview_printable_print(s, p.set(skipped, j));
                  }
              }
            else
              {
                exceptions::throw_exception(exceptions::undefined_dimensions("Strange things are happening here..."));
              }
            s.width(w);
            s.setf(f, std::ios::adjustfield);
          }
      }
    public:
      ndview_printable( const ndview<indexer, dim, skipped> &view, const ArrT& array, const bool p_c, const std::streamsize sz):
        v(view), arr(array), print_coordinates(p_c), write_width(sz) {};
      friend inline std::ostream& operator << (std::ostream &s, const ndview_printable &p)
      {
        p.ndview_printable_print(s, g24_lib::fspoint<indexer, indexer, dim>(indexer(0)));
        return s;
      }
    };
  }
}


#endif

#ifndef G24_LIB_COLL
#define G24_LIB_COLL

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

\file coll.h

\brief Defines `g24_lib::coll`, a mostly deprecated class that holds N-dimensional collections of objects.

\author Nuno Fernandes (main coder, current maintainer)

\author Gonçalo Vaz (auxiliary coder and tester)

*/

namespace g24_lib
{
  /*!
    \brief Holds a run-time defined number of objects in a run-time defined number of dimensions.
    
    \tparam Type The type of the elements of the array.
    
    \tparam indexer The type that should be able to hold the size of the array.
        
    \pre \p indexer must satisfy the constraints placed on the choice of \ref g24_lib::Definitions::default_unsigned_indexer.
    
    \details Suppose we want to store something in `n+1` dimensions,
             with `k_0`, `k_1`, ... , `k_n` elements in each dimension.             
             `g24_lib::coll` will allocate an array of `k_0 * k_1 * ... * k_n` elements.
             The elements at each dimension will be stored at decreasing strides,
             much in the same way as native multidimensional static arrays
             (such as `int x[10][11][12]`).
             
    \details The strides between each element in a given dimension will be:
             `k_1 *  k_2 * ... * k_n`, `k_2 * ... * k_n`, ... , `k_n` , `1`
             (that is, in the last dimension the elements are stored contiguosly).
             
             
             
             
    
    \deprecated After seeing much use during the projects that originated the first versions of this library,
                the authors eventually concluded that the run-time defined number of dimensions
                was not a significant advantage, quite the opposite, since it forced the usage
                of the (also deprecated) `g24_lib::point` class and more dynamic allocations
                than desireable. A more reasonable alternative is to use `g24_lib::ndview`
                to specify a run-time number of elements in a compile-time number of dimensions
                and couple this with any array (not necessarily `g24_lib::simple_array`, though
                that would be the most natural choice for this library...) using `g24_lib::ndview::array_size()`
                to get the necessary number of elements and access ordered positions through `g24_lib::ndview`.                
  */
  template <class Type, class indexer = g24_lib::Definitions::default_unsigned_indexer> class coll
  {
  public:
    typedef Type value_type;
    typedef indexer indexer_type;
  private:
    /*!
      \brief The actual array.
    */
    Type *a;
    
    /*!
      \brief The number of dimensions.
    */
    indexer dim;
    
    /*!
      \brief The total size of the array.
    */
    indexer Size;
    
    /*!
      \brief The number of elements per dimension.
    */
    point<indexer, indexer> nums;
    
    /*!
      \brief The stride between the elements in each dimension.
    */
    point<indexer, indexer> sep;
  public:
    
    /*!
      \brief Returns the number of dimensions of the `coll`.
    */
    inline indexer dimension() const
    {
      return dim;
    }
    
    /*!
      \brief Returns the total number of elements of the `coll`.
    */
    inline indexer size() const
    {
      return Size;
    }
    
    /*!
      \brief Returns a `g24_lib::point` that holds the number of elements in each dimension.
    */
    inline point<indexer, indexer> numbers() const
    {
      return nums;
    }
    
    /*!
      \brief Returns the number of elements in the dimension \p i.
    */
    inline indexer numbers(const indexer i) const
    {
      return nums[i];
    }
    
    /*!
      \brief Returns a `g24_lib::point` that holds the stride between each element in each dimension.
    */
    inline point<indexer, indexer> separation() const
    {
      return sep;
    }
    
    /*!
      \brief Returns the stride between each element in the dimension \p i.
    */
    inline indexer separation(const indexer i) const
    {
      return sep[i];
    }
    
    /*!
      \brief Gives direct access to the underlying array.
      
      \warning This gives actual access to the raw array. It shouldn't absolutely be used
               unless the user is really, really sure of what will be done.
      
      \deprecated This is kept for compatibility with older code,
                  where copying to CUDA and so on wasn't as well abstracted
                  as it is now. It really, really shouldn't be needed anymore.
    */
    inline Type *& get_access_to_array()
    {
      return a;
    }
        
    /*!
      \brief Gives direct access to the underlying array.
      
      \warning This gives actual access to the raw array. It shouldn't absolutely be used
               unless the user is really, really sure of what will be done.
      
      \deprecated This is kept for compatibility with older code,
                  where copying to CUDA and so on wasn't as well abstracted
                  as it is now. It really, really shouldn't be needed anymore.
    */
    inline const Type * get_access_to_array() const
    {
      return a;
    }
    
    /*!
      \brief Empty construct.
    */
    coll()
    {
      dim = 0;
      Size = 0;
      a = nullptr;
    }
    
    
    /*!
      \brief Construct with \p d dimensions with \p n elements in each dimension and no initialization.
    */
    coll(const indexer d, const indexer n):
      nums(d, n),
      sep(d)
    {
      indexer i, j;
      Size = fastpow(n,d);
      dim = d;
      j = Size;
      for (i = 0, j = Size; i < dim; ++i)
        {
          j /= n;
          sep[i] = j;
        };
      a = new Type[Size];
    }
    
    /*!
      \brief Construct with \p d dimensions with \p n elements in each dimension,
             with every element being initialized as \p def.
    */
    coll(const indexer d, const indexer n, const Type &def):
      nums(d, n),
      sep(d)
    {
      indexer i, j;
      Size = fastpow(n,d);
      dim = d;
      j = Size;
      for (i = 0, j = Size; i < dim; ++i)
        {
          j /= n;
          sep[i] = j;
        };
      a = new Type[Size];
#ifdef _OPENMP
#pragma omp parallel for
#endif
      for (indexer k = 0; k < Size; ++k)
        {
          a[k] = def;
        }
    }
    
    /*!
      \brief Construct with \p d dimensions
             with the number of elements in each dimension being given by \p ns, with no initialization.
    */
    coll(const indexer d, const point<indexer, indexer> &ns) :
      nums(ns),
      sep(d)
    {
      indexer i, j;
      dim = d;
      Size = 1;
      for (i = 0; i < d; ++i)
        {
          Size *=ns[i];
        };
      for (i = 0, j = Size; i < dim; ++i)
        {
          j /= ns[i];
          sep[i] = j;
        };
      a = new Type[Size];
    }
    
    /*!
      \brief Construct with \p d dimensions
             with the number of elements in each dimension being given by \p ns,
             with every element being initialized as \p def.
    */
    coll(const indexer d, const point<indexer, indexer> &ns, const Type &def) :
      nums(ns),
      sep(d)
    {
      indexer i, j;
      dim = d;
      Size = 1;
      for (i = 0; i < d; ++i)
        {
          Size *=ns[i];
        };
      for (i = 0, j = Size; i < dim; ++i)
        {
          j /= ns[i];
          sep[i] = j;
        };
      a = new Type[Size];
#ifdef _OPENMP
#pragma omp parallel for
#endif
      for (indexer k = 0; k < Size; ++k)
        {
          a[k] = def;
        }
    }
    /*!
      \brief Copy constructor.
    */
    coll(const coll &c):
      nums(c.nums), sep(c.sep)
    {
      Size = c.Size;
      dim = c.dim;
      a = new Type[c.Size];
      memcpy(a, c.a, (c.Size) * sizeof(Type));
    }
    
    /*!
      \brief Move constructor.
    */
    coll(coll &&c):
      nums(c.nums),
      sep(c.sep)
    {
      Size = c.Size;
      dim = c.dim;
      a = c.a;
      c.a = nullptr;
      c.Size = 0;
      c.a.set_all(0);
    }
    
    coll& operator= (const coll& c)
    {
      if(&c == this)
        {
          return (*this);
        }
      nums = c.nums;
      sep = c.sep;
      Size = c.Size;
      dim = c.dim;
      if (a != nullptr)
        {
          delete[] a;
        }
      a = new Type[c.Size];
      memcpy(a, c.a, (c.Size) * sizeof(Type));
      return (*this);
    }
    
    coll& operator= (coll&& c)
    {
      if(&c == this)
        {
          return (*this);
        }
      nums = c.nums;
      sep = c.sep;
      Size = c.Size;
      dim = c.dim;
      if (a != nullptr)
        {
          delete[] a;
        }
      a = c.a;
      c.a = nullptr;
      return (*this);
    }
    
    /*!
      \brief Access operator through an index.
    */
    inline Type& operator[](const indexer i)
    {
      return a[i];
    }
    
    /*!
      \brief Access operator through an index.
    */
    inline const Type& operator[](const indexer i) const
    {
      return a[i];
    }
    
    /*!
      \brief Bounded access operator through an index.
    
      \throw In case the access is out of bounds, uses g24_lib::exceptions::throw_exception
              to possibly throw a g24_lib::exceptions::out_of_bounds_access.
    */
    inline Type& operator()(const indexer i)
    {
      if (i >= Size)
        {
          exceptions::throw_exception(exceptions::out_of_bounds_access("Coll deprecated, but it's accessing outside."));
        }
      return a[i];
    }
    
    /*!
      \brief Bounded access operator through an index.
    
      \throw In case the access is out of bounds, uses g24_lib::exceptions::throw_exception
              to possibly throw a g24_lib::exceptions::out_of_bounds_access.
    */
    inline const Type& operator()(const indexer i) const
    {
      if (i >= Size)
        {
          exceptions::throw_exception(exceptions::out_of_bounds_access("Coll deprecated, but it's accessing outside."));
        }
      return a[i];
    }
    
    /*!
      \brief Converts from an ordered position to an index.
      
      \remark In essence, this is the dot product between the ordered position
              (understood as a vector) and the stride at each dimension (as a vector as well).
              
      \remark To understand the algorithm, take for example a 3d collection of elements with
              `{11, 12, 13}` in each dimension. The strides will be `{156,13,1}`.
              
      \remark Suppose one wants to find the index that corresponds to the position `{4,5,6}`.
              Given the way positions are translated into indexes, one needs to compute:        
              `4 * 156 + 5 * 13 + 1 * 6 = 624 + 65 + 6 = 695`.
              
              
      \sa g24_lib::coll::to_point
      
    */
    inline indexer to_elem(const point<indexer, indexer> &p) const
    {
      indexer i, elem = 0;
      for (i = 0; i < dim; ++i)
        {
          elem += p[i]*sep[i];
        }
      return elem;
    }
    
    /*!
      \brief Access operator with an ordered position. Has worse performance than through an index.
      
      \sa g24_lib::coll::to_elem
    */
    inline Type& operator[] (const point<indexer, indexer> p)
    {
      return (*this)[to_elem(p)];
    }
    
    /*!
      \brief Access operator with an ordered position. Has worse performance than through an index.
      
      \sa g24_lib::coll::to_elem
    */
    inline const Type& operator[] (const point<indexer, indexer> p) const
    {
      return (*this)[to_elem(p)];
    }
    
    /*!
      \brief Bounded access operator with an ordered position. Has worse performance than through an index.
    
      \throw In case the access is out of bounds, uses g24_lib::exceptions::throw_exception
              to possibly throw a g24_lib::exceptions::out_of_bounds_access.
              
      \sa g24_lib::coll::to_elem
    */
    inline Type& operator() (const point<indexer, indexer> p)
    {
      return (*this)(to_elem(p));
    }
    
    /*!
      \brief Bounded access operator with an ordered position. Has worse performance than through an index.
    
      \throw In case the access is out of bounds, uses g24_lib::exceptions::throw_exception
              to possibly throw a g24_lib::exceptions::out_of_bounds_access.
              
      \sa g24_lib::coll::to_elem
    */
    inline const Type& operator() (const point<indexer, indexer> p) const
    {
      return (*this)(to_elem(p));
    }
    
    /*!
      \brief Converts from an index to an ordered position.
      
      \remark To understand the algorithm, take for example a 3d collection of elements with
              `{11, 12, 13}` in each dimension. The strides will be `{156,13,1}`.
              
      \remark Suppose one wants to find the ordered position that corresponds to the index 123.
              Given the way positions are translated into indexes, one needs to compute:        
              #- `123 / 156 = 0` (in integer arithmetic), `123 % 156 = 123`:
                  The first component of the position is 0, we proceed with the number `123`.
              #- `123 / 13 = 9`, `123 % 13 = 6`: The second component of the position is 9,
                  we proceed with the number `6`
              #- `6 / 1 = 6`: The third and last component of the position is `6`.
              
              
      \sa g24_lib::coll::to_elem
      
    */
    inline point<indexer, indexer> to_point(const indexer elem) const
    {
      indexer j, m = elem;
      point<indexer, indexer> res(dim);
      for (j = 0; j < dim; ++j)
        {
          res[j] = m/sep[j];
          m = m % sep[j];
        }
      return res;
    }
        
    /*!
      \brief Returs the elements of the `coll` that are direct neighbors to the specified element.
      
      \param elem The index of the element whose neighbors will be returned.
      
      \param p The ordered position of the element whose neighbors will be returned.
      
      \pre \p elem and \p p must obviously refer to the same element.
      
      \returns An `std::vector` containing the neighbors of the specified element.
               For an element with an ordered position `(a,b,...,d)`,
               the return vector will be ordered as:
               `(a+1,b,...,d)`,`(a-1,b,...,d)`,`(a,b+1,...,d)`,`(a,b-1,...,d)`,...,`(a,b,...,d-1)`,
               with any invalid positions being ommitted
               (if the specified element is in the border of the collection).
               
      \remark Of course, this is extremely inefficient for large types, which is another reason
              for this class to be deprecated...
    */
    std::vector<Type> get_near(const indexer elem, const point<indexer, indexer> &p) const
    {
      indexer i, j = 0;
      std::vector<Type> ret;
      ret.reserve(dim*2);
      for (i = 0; i < dim; ++i)
        {
          if (p[i] > 0)
            {
              ret.push_back(a[elem + sep[i]]);
              ++j;
            }
          if (p[i] > 0 && p[i] < nums[i] - 1)
            {
              ret.push_back(a[elem - sep[i]]);
              ++j;
            }
        }
      ret.shrink_to_fit();
      return ret;
    }
    
    /*!
      \brief Returs the elements of the `coll` that are direct neighbors to the specified element.
            
      \param p The ordered position of the element whose neighbors will be returned.
      
      \returns An `std::vector` containing the neighbors of the specified element.
               For an element with an ordered position `(a,b,...,d)`,
               the return vector will be ordered as:
               `(a+1,b,...,d)`,`(a-1,b,...,d)`,`(a,b+1,...,d)`,`(a,b-1,...,d)`,...,`(a,b,...,d-1)`,
               with any invalid positions being ommitted
               (if the specified element is in the border of the collection).
               
      \remark Of course, this is extremely inefficient for large types, which is another reason
              for this class to be deprecated...
    */
    inline std::vector<Type> get_near(const point<indexer, indexer> &p) const
    {
      return get_near(to_elem(p), p);
    }
    
    /*!
      \brief Returs the elements of the `coll` that are direct neighbors to the specified element.
      
      \param elem The index of the element whose neighbors will be returned.
                  
      \returns An `std::vector` containing the neighbors of the specified element.
               For an element with an ordered position `(a,b,...,d)`,
               the return vector will be ordered as:
               `(a+1,b,...,d)`,`(a-1,b,...,d)`,`(a,b+1,...,d)`,`(a,b-1,...,d)`,...,`(a,b,...,d-1)`,
               with any invalid positions being ommitted
               (if the specified element is in the border of the collection).
               
      \remark Of course, this is extremely inefficient for large types, which is another reason
              for this class to be deprecated...
    */
    inline std::vector<Type> get_near(const indexer elem) const
    //Obtém os pontos mais próximos do elemento.
    {
      return get_near(elem, to_point(elem));
    }
    
    /*!
      \brief Sets all of the elements in the border of the collection to \p v.
      
      \remark When the authors finished writing the algorithm for this function,
              though in retrospective it doesn't seem that impressive,
              they were very glad to have been able to figure out a way
              to select every element of the border in linear time
              and without repetition.
    */
    void set_border(const Type &v)
    {
      indexer i,j, n;
      for (i = 0; i < dim; ++i)
        //i fixes the coordinate where we will consider 0 or max.
        {
          n = 0;
          for(j = 0; j < i; ++j)
            {
              n += sep[j];
            }
          //To start at (1, ... , 1, 0, ...) and avoid repetition.
          while(n < Size - sep[0])
            {
#ifdef _OPENMP
#pragma omp parallel for
#endif
              for (indexer k = 0; k < sep[i]; ++k)
                {
                  a[k+n] = v;
                  a[k+n+(nums[i]-1)*sep[i]] = v;
                }
              if(i > 0)
                {
                  n += sep[i-1];
                }
              else
                {
                  n = Size;
                }
              for(j = i - 1; j < i; --j)
                //This can come outside the conditional
                //since i = 0 invalidates j < i
                //and i = 1 is taken care of through Size - sep[0]
                {
                  if(j > 0 && n % sep[j-1] == 0)
                    {
                      n += sep[j];
                    }
                  else if(j > 0 && (n % sep[j-1])/sep[j] == (nums[j]-1))
                    {
                      n += 2*sep[j];
                    }
                }
            }
        }
    }
    
    /*!
      \brief Returns the number of elements in the border of the collection.
    */
    indexer count_border() const
    //Conta o número de elementos da fronteira.
    {
      indexer i, j, n, count = 0;
      for (i = 0; i < dim; ++i)
        //i fixes the coordinate where we will consider 0 or max.
        {
          n = 0;
          for(j = 0; j < i; ++j)
            {
              n += sep[j];
            }
          //To start at (1, ... , 1, 0, ...) and avoid repetition.
          while(n < Size - sep[0])
            {
              count += 2*sep[i];
              if(i > 0)
                {
                  n += sep[i-1];
                }
              else
                {
                  n = Size;
                }
              for(j = i - 1; j < i; --j)
                //This can come outside the conditional
                //since i = 0 invalidates j < i
                //and i = 1 is taken care of through Size - sep[0]
                {
                  if(j > 0 && n % sep[j-1] == 0)
                    {
                      n += sep[j];
                    }
                  else if(j > 0 && (n % sep[j-1])/sep[j] == (nums[j]-1))
                    {
                      n += 2*sep[j];
                    }
                }
            }
        }
      return count;
    }
    /*
      void operate_on_border(Type (*f) (const Type &, const indexer, const coll<Type, indexer> &, void*), void *par = nullptr)
      {
      #ifdef _OPENMP
      #pragma omp parallel for
      #endif
      for (indexer i = 0; i < Size; ++i)
      {
      a[i] = f(a[i], i, (*this), par);
      }
      }
      
      void operate_on_all(Type (*f) (const Type &, const point<indexer, indexer> &, const coll<Type, indexer> &, void *), void *par = nullptr)
      {
      #ifdef _OPENMP
      #pragma omp parallel for
      for (indexer i = 0; i < Size; ++i)
      {
      point<indexer, indexer> p = to_point (i);
      a[i] = f(a[i], p, (*this), par);
      }
      #else
      point<indexer, indexer> p(dim,0);
      indexer i;
      for (i = 0; i < Size; ++i)
      {
      
      a[i] = f(a[i], p, (*this), par);
      p.inc_with_wrap(nums, dim-1, true, true);
      }
      #endif
      }
      
    */
    
    /*!
      \brief Checks if an element belongs to the border of the collection.
    */
    inline bool is_border(const point <indexer, indexer> &p) const
    {
      indexer i;
      for(i = 0; i < dim; ++i)
        {
          if (p[i] == 0 || p[i] == nums[i] - 1)
            {
              return true;
            }
        }
      return false;
    }
    
    /*!
      \brief Checks if an element belongs to the border of the collection.
    */
    inline bool is_border(const indexer elem) const
    {
      return is_border(to_point(elem));
    }
    
    /*!
      \brief Operates on all elements of the collection.
      
      \param f A function that takes the current element, its index, a reference to the current `coll`
             and an extra `void *` as arguments and returns the new element.
      
      \param par A pointer to any extra arguments.
      
      \remark This heavily foregoes type safety and leans too much towards C and not C++.
              The authors blame that on their lack of experience with the language at the point this was written.
              `g24_lib::ndview` implements this in a more generic and idiomatic way,
              using template parameter packs and other C++ syntax goodies.
    */
    inline void operate_on_all(Type (*f) (const Type &, const indexer, const coll<Type, indexer> &, void*), void *par = nullptr)
    {
#ifdef _OPENMP
#pragma omp parallel for
#endif
      for (indexer i = 0; i < Size; ++i)
        {
          a[i] = f(a[i], i, (*this), par);
        }
    }
    
    /*!
      \brief Operates on all elements of the collection.
      
      \param f A function that takes the current element, its ordered position, a reference to the current `coll`
             and an extra `void *` as arguments and returns the new element.
      
      \param par A pointer to any extra arguments.
      
      \remark This heavily foregoes type safety and leans too much towards C and not C++.
              The authors blame that on their lack of experience with the language at the point this was written.
              `g24_lib::ndview` implements this in a more generic and idiomatic way,
              using template parameter packs and other C++ syntax goodies.
    */
    inline void operate_on_all(Type (*f) (const Type &, const point<indexer, indexer> &, const coll<Type, indexer> &, void *), void *par = nullptr)
    {
#ifdef _OPENMP
#pragma omp parallel for
      for (indexer i = 0; i < Size; ++i)
        {
          point<indexer, indexer> p = to_point (i);
          a[i] = f(a[i], p, (*this), par);
        }
#else
      point<indexer, indexer> p(dim,(indexer) 0);
      indexer i;
      for (i = 0; i < Size; ++i)
        {
          
          a[i] = f(a[i], p, (*this), par);
          p.inc_with_wrap(nums, dim-1, true, true);
        }
#endif
    }
    
    /*!
      \brief Sets all the elements with coordinate \p coord in dimension \p dms to \p v.
    */
    void set_with_specific_coord(const Type &v, const indexer dms, const indexer coord)
    {
      indexer j = 0, n = coord*sep[dms];
      while(n + j + sep[dms] - 1 < Size)
        {
#ifdef _OPENMP
#pragma omp parallel for
#endif
          for (indexer i = 0; i < sep[dms]; ++i)
            {
              a[i + n + j] = v;
            }
          if(dms > 0)
            {
              j += sep[dms - 1];
            }
          else
            {
              return;
            }
        }
    }
    
    ~coll()
    {
      delete[] a;
    }
    
    /*!
      \brief Prints a collection in a roughly understantable format.
      
      \warning For proper serialization, use `textual_output`.
    */
    friend std::ostream& operator<< (std::ostream &s, const coll<Type, indexer> &c)
    //Imprime uma colecção.
    //Não é necessariamente uma forma de armazenar a colecção,
    //antes para um output visualmente compreensível.
    {
      indexer i;
      s << "\n";
      if (c.Size)
        {
          for(i = 0; i < c.size(); ++i)
            {
              if(c.dim > 2 && i % c.separation(c.dim - 3) == 0)
                {
                  s << "\n\n" << (c.to_point(i) >> 2) << "\n\n";
                }
              if(c.dim > 1 && i % c.separation(c.dim-2) == 0)
                {
                  s << "\n";
                }
              s << c.a[i] << " ";
            }
        }
      return s;
    }
    
    /*!
        \brief Prints a `coll` to a stream in a futurely readable way.
        
        \details Prints the number of dimensions,
                 followed by the number of elements in each dimension,
                 followed by the stride in each dimenson,
                 then the total size and finally the elements,
                 all with `operator<<`.
        
        \deprecated Old way of printing the contents of the `coll`,
                    provided for backwards compatibility reasons.
                    Please use `textual_output` for proper serialization.
    */
    template <class stream>
    void raw_print(stream &s)
    {
      s << dim << " ";
      nums.raw_print(s, false);
      s << " ";
      sep.raw_print(s, false);
      s << Size << " ";
      for(indexer i = 0; i < Size; ++i)
        {
          s << a[i] << " ";
        }
    }
    
    /*!
        \brief Reads a `coll` in the format 
        
        \details Reads the number of dimensions,
                 followed by the number of elements in each dimension,
                 followed by the stride in each dimension,
                 then the total size and finally the elements,
                 all with `operator>>`.
        
        \deprecated Old way of reading the contents of the `coll`,
                    provided for backwards compatibility reasons.
                    Please use `textual_input` for proper serialization.
    */
    template <class stream>
    void raw_read(stream &s)
    {
      s >> dim;
      nums.raw_read(s, dim);
      sep.raw_read(s, dim);
      indexer temp;
      s >> temp;
      if (temp != Size)
        {
          delete[] a;
          a = new Type[temp];
          Size = temp;
        }
      for(indexer i = 0; i < Size; ++i)
        {
          s >> a[i];
        }
    }
    
    
    template<class stream, class str = std::basic_string<typename stream::char_type>>
    void textual_output(stream &s, const str& separator = " ") const
    {
      g24_lib::textual_output(s, nums, separator);
      s << separator;
      for (indexer i = 0; i < Size; ++i)
        {
          g24_lib::textual_output(s, a[i], separator);
          s << separator;
        }
    }
      
    template<class stream>
    void textual_input(stream &s)
    {
      point<Type, indexer> new_nums;
      g24_lib::textual_input(s, new_nums);
      if(s.fail())
        {
          exceptions::throw_exception(exceptions::array_length_misread(""));
        }
      coll temp(new_nums.size(), new_nums);
      for (indexer i = 0; i < temp.size(); ++i)
        {
          g24_lib::textual_input(s, temp.a[i]);
        }
      (*this) = temp;
    }
      
    template<class stream>
    void binary_output(stream &s) const
    {
      g24_lib::binary_output(s, nums);
      for (indexer i = 0; i < Size; ++i)
        {
          g24_lib::binary_output(s, a[i]);
        }
    }
      
    template<class stream>
    void binary_input(stream &s)
    {
      point<Type, indexer> new_nums;
      g24_lib::binary_input(s, new_nums);
      if(s.fail())
        {
          exceptions::throw_exception(exceptions::array_length_misread(""));
        }
      coll temp(new_nums.size(), new_nums);
      for (indexer i = 0; i < temp.size(); ++i)
        {
          g24_lib::binary_input(s, temp.arr[i]);
        }
      (*this) = temp;
    }    
    
    /*!
      \brief An old kludge to enable output of `colls` of `g24_lib::fspoints`
             way before `serialization_helpers.h` was written.
      
      \deprecated Currently, it simply calls `g24_lib::coll::binary_output`
                  since this already works with `g24_lib::fspoints`,
                  but the function is kept here for backwards compatibility.
    */
    template <class stream>
    friend void binary_output_special(stream &s, const coll &c)
    {
      c.binary_output(s);
      /*
      s.write( (char*) &c.dim, sizeof(indexer));
      s.write( (char*) c.nums.get_access_to_array(), c.dim*sizeof(indexer));
      s.write( (char*) c.sep.get_access_to_array(), c.dim*sizeof(indexer));
      s.write( (char*) &c.Size, sizeof(indexer));
      for(indexer i = 0; i < c.Size; ++i)
        {
          s.write( (char*) c.a[i].get_access_to_array(), c.a[i].size() * sizeof(c.a[i][0]));
        }
      */
    }
      
    /*!
      \brief An old kludge to enable input of `colls` of `g24_lib::fspoints`
             way before `serialization_helpers.h` was written.
      
      \deprecated Currently, it simply calls `g24_lib::coll::binary_input`
                  since this already works with `g24_lib::fspoints`,
                  but the function is kept here for backwards compatibility.
    */
    template <class stream>
    friend void binary_input_special(stream &s, coll &c)
    {
      c.binary_input(s);
      /*
      s.read( (char*) &c.dim, sizeof(indexer));
      c.nums.assure_size(c.dim);
      s.read( (char*) c.nums.get_access_to_array(), c.dim*sizeof(indexer));
      c.sep.assure_size(c.dim);
      s.read( (char*) c.sep.get_access_to_array(), c.dim*sizeof(indexer));
      indexer temp;
      s.read( (char*) &temp, sizeof(indexer));
      if(temp != c.Size)
        {
          c.Size = temp;
          delete[] c.a;
          c.a = new Type[c.Size];
        }
      for(indexer i = 0; i < c.Size; ++i)
        {
          s.read( (char*) c.a[i].get_access_to_array(), c.a[i].size() * sizeof(c.a[i][0]));
        }
      */
    }
  };
}

#endif

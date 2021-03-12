#ifndef G24_LIB_FSPOINT
#define G24_LIB_FSPOINT

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

\file fspoint.h

\brief Defines `g24_lib::fspoint`, one of the most useful classes for physical simulations: an N-dimensional vector
       with the number of dimensions being fixed at compile time.

\author Nuno Fernandes (main coder, current maintainer)

\author Gonçalo Vaz (auxiliary coder and tester)

*/

namespace g24_lib
{
  ///\cond HIDDEN_SYMBOLS
  template <class Type, class indexer> class point;
  //Forward-declare point.
  ///\endcond
  
  /*!
    \brief An array of \p Size elements of type \p Type. Mainly to be used as an N-dimensional vector
           in mathematical or physical contexts.
           
    \tparam Type The type of the elements of the array.
    
    \tparam indexer The type that should be able to hold the size of the array.
    
    \tparam Size The number of elements of the array.
    
    \pre \p Type should provide appropriate arithmetic operators if `fspoint` is to be used as a mathematical vector.
    
    \pre \p indexer must satisfy the constraints placed on the choice of \ref g24_lib::Definitions::default_unsigned_indexer.
  */
  template <class Type, class indexer = g24_lib::Definitions::default_unsigned_indexer,
            indexer Size = g24_lib::Definitions::default_fixed_size> class fspoint
  {
  public:
    typedef Type value_type;
    typedef indexer indexer_type;
  private:
    Type val[Size];
    //The array
  public:
    
    template <class A, class b, b> friend class fspoint;
    //A slightly convoluted way of getting what we want,
    //that is for the several fspoint<Type, indexer, Size>
    //to be friends for different Size but same Type and indexer.
    //The slight loss of encapsulation is better
    //than the obvious alternative: making the array public...
    
    friend class point<Type, indexer>;
    
    /*!
      \brief Empty construct.
    */
    CUDA_HOS_DEV constexpr fspoint()
    {
    }
    /*
    CUDA_HOS_DEV explicit constexpr fspoint (const std::nullptr_t nullp)
    {
      for(indexer i = 0; i < Size; ++i)
        {
          val[i] = Type(0);
        }
    }
    
    CUDA_HOS_DEV explicit constexpr fspoint (const Type *a)
    //We assume the array is large enough.
    {
      for(indexer i = 0; i < Size; ++i)
        {
          val[i] = a[i];
        }
    }
    */
    /*!
      \brief Copy constructor.
    */
    CUDA_HOS_DEV fspoint(const fspoint<Type, indexer, Size> &p)
    {
      for(indexer i = 0; i < Size; ++i)
        {
          val[i] = p.val[i];
        }
    }
        
    /*!
      \brief Constructor from an `std::array`.
    */
    CUDA_HOS_DEV constexpr fspoint(const std::array<Type, Size> &arr)
    {
      for (indexer j = 0; j < Size; ++j)
        {
          val[j] = arr[j];
        }
    }

    /*  private:
        template<typename std::initializer_list<Type>::iterator it, indexer order, indexer limit> constexpr void list_init()
        {
        if constexpr (order >= limit)
        {
        return;
        }
        else
        {
        val[order] = *it;
        if constexpr(order < limit - 1)
        {
        list_init<++it, order +1, limit>();
        }
        }
        }
        public:*/
    /*!
      \brief Constructor that allows syntax like `p{1,2,3,4,5}`.
    */
    CUDA_HOS_DEV constexpr fspoint(std::initializer_list<Type> list)
    {
      auto it = list.begin();
      for (indexer j = 0; j < Size; ++j, ++it)
        {
          val[j] = *it;
        }
    }

    /*
      template<class... Ts> CUDA_HOS_DEV constexpr fspoint(Ts... t): val{Type(t)...}
      {
      }*/
    
    /*!
      \brief Copy constructor from a different sized point.
             Initializes up to the minimum size, if there are more elements, they are put to zero.
    */
    template <indexer Size2> CUDA_HOS_DEV constexpr fspoint(const fspoint<Type, indexer, Size2> &p)
    {
      if(Size < Size2)
        {
          for(indexer i = 0; i < Size; ++i)
            {
              val[i] = p.val[i];
            }
        }
      else
        {
          indexer i;
          for(i = 0; i < Size2; ++i)
            {
              val[i] = p.val[i];
            }
          for(; i < Size; ++i)
            {
              val[i] = Type(0);
            }
        }
    }
    
    /*!    
      \brief All elements are set equal to \p a.
    */
    CUDA_HOS_DEV constexpr explicit fspoint(const Type &a)
    {
      indexer i;
      for (i = 0; i < Size; ++i)
        {
          val[i] = a;
        }
    }
    
    /*!    
      \todo We could do away with the specific dependence on std::vector
            and generalize this to anything that's a container.
            (`g24_lib::value_type<C>` equal to \p Type).
    */
    explicit fspoint(const std::vector<Type> v)
    {
      for(indexer i = 0; i < Size; ++i)
        {
          val[i] = v[i];
        }
    }
    
    /*!
      \brief Constructor from a `g24_lib::point`.
             Initializes up to the minimum size, if there are more elements, they are put to zero.
    */
    explicit fspoint(const point<Type, indexer> &p) 
    {
      if(p.size() >= Size)
        {
          for(indexer i = 0; i < Size; ++i)
            {
              val[i] = p.val[i];
            }
        }
      else
        {
          for(indexer i = 0; i < p.Size; ++i)
            {
              val[i] = p.val[i];
            }
        }
    }
            
    inline static constexpr indexer size()
    {
      return Size;
    }
    
    /*!
      \remark For an implementation detail in `compile_time_utilities.h`.
    */
    inline static constexpr indexer constexpr_size()
    {
      return Size;
    }
    
    explicit constexpr operator std::array<Type, Size>() const
    {
      return std::array<Type, Size>(val);
    }
    
    /*!
      \remark We always operate on the smallest number of elements, that is,
              `min(Size, Size2)`.
    */
    template<indexer Size2> CUDA_HOS_DEV inline constexpr fspoint<Type, indexer, Size> operator+(const fspoint<Type, indexer, Size2> &p) const
    {
      fspoint temp;
      constexpr indexer max_size = (Size > Size2 ? Size : Size2);
      constexpr indexer min_size = (Size > Size2 ? Size2 : Size);
      for (indexer i = 0; i < min_size; ++i)
        {
          temp.val[i] = val[i] + p.val[i];
        }
      for (indexer i = min_size; i < max_size; ++i)
        {
          if constexpr (max_size == Size)
            {
              temp.val[i] = val[i];
            }
          else
            {
              temp.val[i] = p.val[i];
            }
        }
      return temp;
    }
    
    /*!
      \remark We always operate on the smallest number of elements, that is,
              `min(Size, Size2)`.
    */
    template<indexer Size2> CUDA_HOS_DEV inline constexpr fspoint<Type, indexer, Size>  operator-(const fspoint<Type, indexer, Size2> &p) const
    {
      fspoint temp;
      constexpr indexer max_size = (Size > Size2 ? Size : Size2);
      constexpr indexer min_size = (Size > Size2 ? Size2 : Size);
      for (indexer i = 0; i < min_size; ++i)
        {
          temp.val[i] = val[i] - p.val[i];
        }
      for (indexer i = min_size; i < max_size; ++i)
        {
          if constexpr (max_size == Size)
            {
              temp.val[i] = val[i];
            }
          else
            {
              temp.val[i] = p.val[i];
            }
        }
      return temp;
    }
    
    /*!
      \pre \p a is assumed to be at least as large as \p Size.
      
      \todo Possibly generalize this for any appropriate container
            (`g24_lib::value_type<C>` equal to \p Type)?
    */
    CUDA_HOS_DEV inline fspoint operator+(const Type * const a) const
    {
      fspoint temp;
      indexer i;
      for (i = 0; i < Size; ++i)
        {
          temp.val[i] = val[i] + a[i];
        }
      return temp;
    }
    
    /*!
      \pre \p a is assumed to be at least as large as \p Size.
      
      \todo Possibly generalize this for any appropriate container
            (`g24_lib::value_type<C>` equal to \p Type)?
    */
    CUDA_HOS_DEV inline fspoint operator-(const Type * const a) const
    {
      fspoint temp;
      indexer i;
      for (i = 0; i < Size; ++i)
        {
          temp.val[i] = val[i] - a[i];
        }
      return temp;
    }
    
    CUDA_HOS_DEV inline constexpr fspoint operator-() const
    {
      fspoint temp;
      indexer i;
      for (i = 0; i < Size; ++i)
        {
          temp.val[i] = -val[i];
        }
      return temp;
    }
    
    /*!
      \brief Scalar multiplication.
    */
    CUDA_HOS_DEV inline constexpr fspoint operator*(const Type &a) const
    {
      fspoint temp;
      indexer i;
      for (i = 0; i < Size; ++i)
        {
          temp.val[i] = val[i]*a;
        }
      return temp;
    }
    
    /*!
      \brief Scalar division.
    */
    CUDA_HOS_DEV inline constexpr fspoint operator/(const Type &a) const
    {
      fspoint temp;
      indexer i;
      for (i = 0; i < Size; ++i)
        {
          temp.val[i] = val[i]/a;
        }
      return temp;
    }
    
    CUDA_HOS_DEV inline constexpr const Type& operator[](const indexer i) const
    {
      return val[i];
    }
    
    CUDA_HOS_DEV inline constexpr Type& operator[](const indexer i)
    {
      return val[i];
    }
    
    /*!
      \brief Bounded access operator.
    
      \deprecated Provided for possible compatibility with older code.
      
      \todo Maybe provide an `at()` member function in accordance with STL?
      
      \throw In case the access is out of bounds, uses g24_lib::exceptions::throw_exception
              to possibly throw a g24_lib::exceptions::out_of_bounds_access.
    */
    inline constexpr Type& operator()(const indexer i)
    {
      if (i >= Size)
        {
          exceptions::throw_exception(exceptions::out_of_bounds_access("Trying to access undefined element of fspoint."));
        }
      return val[i];
    }

    /*!
      \brief Bounded access operator.
    
      \deprecated Provided for possible compatibility with older code.
      
      \todo Maybe provide an `at()` member function in accordance with STL?
      
      \throw In case the access is out of bounds, uses g24_lib::exceptions::throw_exception
              to possibly throw a g24_lib::exceptions::out_of_bounds_access.
    */
    inline constexpr const Type& operator()(const indexer i) const
    {
      if (i >= Size)
        {
          exceptions::throw_exception(exceptions::out_of_bounds_access("Trying to access undefined element of fspoint."));
        }
      return val[i];
    }
    
    /*!
      \brief Does element-wise equality.
    */
    CUDA_HOS_DEV inline constexpr bool operator== (const fspoint &p) const
    {
      indexer i;
      for (i = 0; i < Size; ++i)
        {
          if (val[i] != p.val[i])
            {
              return false;
            }
        }
      return true;
    }
    
    /*!
      \brief Does element-wise inequality.
    */
    CUDA_HOS_DEV inline bool constexpr operator!= (const fspoint &p) const
    {
      return !(p == *this);
    }
    
    CUDA_HOS_DEV inline fspoint& operator=(const fspoint &p)
    {
      if(&p == this)
        {
          return (*this);
        }
      for(indexer i = 0; i < Size; ++i)
        {
          val[i] = p.val[i];
        }
      return *this;
    }
    
    /*!
      \remark We always operate on the smallest number of elements, that is,
              `min(Size, Size2)`.
    */
    template <indexer Size2> CUDA_HOS_DEV inline constexpr fspoint& operator+=(const fspoint<Type, indexer, Size2> &p)
    {
      indexer i, j = (Size > Size2 ? Size2 : Size);
      for (i = 0; i < j; ++i)
        {
          val[i] += p.val[i];
        }
      return *this;
    }
    
    
    /*!
      \remark We always operate on the smallest number of elements, that is,
              `min(Size, Size2)`.
    */
    template <indexer Size2> CUDA_HOS_DEV inline constexpr fspoint& operator-=(const fspoint<Type, indexer, Size2> &p)
    {
      indexer i, j = (Size > Size2 ? Size2 : Size);
      for (i = 0; i < j; ++i)
        {
          val[i] -= p.val[i];
        }
      return *this;
    }
    
    /*!
      \pre \p a is assumed to be at least as large as \p Size.
      
      \todo Possibly generalize this for any appropriate container
            (`g24_lib::value_type<C>` equal to \p Type)?
    */
    CUDA_HOS_DEV inline fspoint& operator+=(const Type * const a)
    {
      indexer i;
      for (i = 0; i < Size; ++i)
        {
          val[i] += a[i];
        }
      return *this;
    }
    
    /*!
      \pre \p a is assumed to be at least as large as \p Size.
      
      \todo Possibly generalize this for any appropriate container
            (`g24_lib::value_type<C>` equal to \p Type)?
    */
    CUDA_HOS_DEV inline fspoint& operator-=(const Type * const a)
    {
      indexer i;
      for (i = 0; i < Size; ++i)
        {
          val[i] -= a[i];
        }
      return *this;
    }
    
    /*!
    
      \brief Inserts a new value to the end of the `fspoint`.
      
      \param x The new value to be inserted.
      
      \return An `fspoint` of size `Size + 1` with the new value at the end.
      
      \warning Do note that, since the type changes, we do not return by reference
               and the original `fspoint` remains unchanged!
    
    */
    CUDA_HOS_DEV constexpr fspoint<Type, indexer, Size+1> operator<< (const Type &x)
    {
      Type temp[Size + 1];
      for(indexer i = 0; i < Size; ++i)
        {
          temp[i] = val[i];
        }
      temp[Size] = x;
      return fspoint<Type, indexer, Size+1>(temp);
    }
    
    /*!
    
      \brief Concatenates two `fspoint`s.
      
      \param p The other point to be concatenated.
      
      \return An `fspoint` of size `Size + Size2` with the elements of \p at the end.
    
      \warning Do note that, since the type changes, we do not return by reference
               and the original `fspoint` remains unchanged!
    
    */
    template <indexer Size2> CUDA_HOS_DEV constexpr fspoint<Type, indexer, Size + Size2> operator<< (const fspoint<Type, indexer, Size2> &p)
    {
      Type temp[Size + Size2];
      for(indexer i = 0; i < Size; ++i)
        {
          temp[i] = val[i];
        }
      for(indexer i = 0; i < Size2; ++i)
        {
          temp[i+Size] = p.val[i];
        }
      return fspoint<Type, indexer, Size + Size2>(temp);
    }
    
    /*!
        \brief Prints an fspoint to a stream as a series of objects.
    
        \param print_size If true, we output `Size` as well.
        
        \deprecated Old way of printing the contents of the `fspoint`,
                    provided for backwards compatibility reasons.
                    Please use `textual_output` for proper serialization.
    */
    void raw_print(std::ostream &s, bool print_size = false) const
    {
      indexer i;
      if (print_size)
        {
          s << " " << Size;
        }
      if (Size)
        {
          s << " ";
          for (i = 0; i < Size; ++i)
            {
              s << val[i] << " ";
            }
        }
    }
    
    /*!
      \brief Reads an fspoint from a stream as a series of objects.
      
        
      \deprecated Old way of reading the contents of the `fspoint`,
                  provided for backwards compatibility reasons.
                    Please use `textual_input` for proper serialization.
    */
    void raw_read(std::istream &s)
    {
      indexer i;
      fspoint<Type, indexer, Size> ret;
      for (i = 0; i < Size; ++i)
        {
          s >> ret.val[i];
        }
      (*this) = ret;
    }
    
    CUDA_HOS_DEV constexpr inline Type sum_all() const
    {
      indexer a;
      if(Size)
        {
          Type ret = val[0];
          for (a = 1; a < Size; ++a)
            {
              ret +=val[a];
            }
          return ret;
        }
      return (Type) 0;
    }
    
    CUDA_HOS_DEV constexpr inline Type multiply_all() const
    {
      indexer a;
      if(Size)
        {
          Type ret = val[0];
          for (a = 1; a < Size; ++a)
            {
              ret *=val[a];
            }
          return ret;
        }
      return (Type) 1;
    }
    
    CUDA_HOS_DEV constexpr inline Type max() const
    {
      indexer a;
      if (Size)
        {
          Type ret = val[0];
          for (a = 1; a < Size; ++a)
            {
              if (ret < val[a])
                {
                  ret = val[a];
                }
            }
          return ret;
        }
      return (Type) 0;
    }
    
    /*!
      \remark The index of the maximum element is stored in \p comp.
    */
    CUDA_HOS_DEV constexpr inline Type max(indexer &comp) const
    {
      indexer a;
      comp = std::numeric_limits<indexer>::max();
      if (Size)
        {
          Type ret = val[0];
          comp = 0;
          for (a = 1; a < Size; ++a)
            {
              if (ret < val[a])
                {
                  comp = a;
                  ret = val[a];
                }
            }
          return ret;
        }
      return (Type) 0;
    }
    
    CUDA_HOS_DEV constexpr inline Type min() const
    {
      indexer a;
      if (Size)
        {
          Type ret = val[0];
          for (a = 1; a < Size; ++a)
            {
              if (ret > val[a])
                {
                  ret = val[a];
                }
            }
          return ret;
        }
      return (Type) 0;
    }
    
    /*!
      \remark The index of the minimum element is stored in \p comp.
    */
    CUDA_HOS_DEV constexpr inline Type min(indexer &comp) const
    {
      indexer a;
      comp = std::numeric_limits<indexer>::max();
      if (Size)
        {
          Type ret = val[0];
          comp = 0;
          for (a = 1; a < Size; ++a)
            {
              if (ret > val[a])
                {
                  comp = a;
                  ret = val[a];
                }
            }
          return ret;
        }
      return (Type) 0;
    }
    
    /*!
      \remark This is mathematically equivalent to the inner product of the vector with itself.
    */
    CUDA_HOS_DEV constexpr inline Type square_norm2() const
    {
      indexer i;
      Type ret = (Type) 0;
      for (i = 0; i < Size; ++i)
        {
          ret += val[i]*val[i];
        }
      return ret;
    }
    
    /*!
      \brief Returns a normalized vector.
      
      \param k The vector is normalized so that the k-th component is positive.
             If \p k specified an invalid element of the vector,
             no change is made to the direction (all the components keep the signs they had before).
      
      \param norm The intended final value for the norm of the vector.
      
      \param p The kind of norm we want to calculate. Usual norm has \p `p == 2`,
             but it is mathematically valid as long as `p >= 1`.
             
      \tparam p_type The type that is appropriate to indicate the norm.
    */
    template <class p_type = decltype( abs( std::declval<Type>() ) )>
    CUDA_HOS_DEV inline fspoint<Type, indexer, Size>
    normalize(const indexer k = std::numeric_limits<indexer>::max(), const p_type norm = 1, const p_type p = 2) const
    {
      using namespace std;
      fspoint<Type, indexer, Size> temp(*this);
      p_type f = abs((*this), p)/norm * (k >= Size ?  1 : sign(temp.val[k]));
      indexer i;
      for (i = 0; i < Size; ++i)
        {
          temp.val[i] = temp.val[i]/f;
        }
      return temp;
    }
    
    CUDA_HOS_DEV inline constexpr void set_all(const Type& a)
    {
      indexer i;
      for(i = 0; i < Size; ++i)
        {
          val[i] = a;
        }
    }
    
    /*!
      \brief Performs element-wise multiplication.
      
      \return An fspoint whose elements are the elements of this point multiplied by the equivalent element of \p p.
      
    */
    CUDA_HOS_DEV inline constexpr fspoint element_multiply(const fspoint &p) const
    {
      fspoint ret(*this);
      for (indexer i = 0; i < Size; ++i)
        {
          ret[i] = ret[i] * p[i];
        }
      return ret;
    }
    
    /*!
      \brief Performs element-wise division.
      
      \return An fspoint whose elements are the elements of this point divided by the equivalent element of \p p.
      
    */
    CUDA_HOS_DEV inline constexpr fspoint element_divide(const fspoint &p) const
    {
      fspoint ret(*this);
      for (indexer i = 0; i < Size; ++i)
        {
          ret[i] = ret[i] / p[i];
        }
      return ret;
    }
    
    /*!
      \brief Performs element-wise multiplication.
      
      \pre \p a is assumed to be at least as large as \p Size.
      
      \todo Possibly generalize this for any appropriate container
            (`g24_lib::value_type<C>` equal to \p Type)?
    */
    CUDA_HOS_DEV inline constexpr fspoint element_multiply(const Type *a) const
    {
      fspoint ret(*this);
      indexer i;
      for (i = 0; i < Size; ++i)
        {
          ret[i] = ret[i] * a[i];
        }
      return ret;
    }
    
    /*!
      \brief Performs element-wise division.
      
      \pre \p a is assumed to be at least as large as \p Size.
      
      \todo Possibly generalize this for any appropriate container
            (`g24_lib::value_type<C>` equal to \p Type)?
    */
    CUDA_HOS_DEV inline constexpr fspoint element_divide(const Type *a) const
    {
      fspoint ret(*this);
      indexer i;
      for (i = 0; i < Size; ++i)
        {
          ret[i] = ret[i] / a[i];
        }
      return ret;
    }
    
    /*!
      \brief Element-wise multiplication.
      
      \remark Only defined if `g24_lib::Definitions::elementwise_point_operators` is true.
      
      \remark Although mathematically unsound, this might come in handy to use,
              for instance, arrays of fspoints in linear equation solvers.
    */
    CUDA_HOS_DEV constexpr inline
    typename std::enable_if<g24_lib::Definitions::elementwise_point_operators, fspoint>::type
    operator* (const fspoint& b) const
    {
      return this->element_multiply(b);
    }

    /*!
      \brief Element-wise division.
      
      \remark Only defined if `g24_lib::Definitions::elementwise_point_operators` is true.
      
      \remark Although mathematically unsound, this might come in handy to use,
              for instance, arrays of fspoints in linear equation solvers.
    */
    CUDA_HOS_DEV inline constexpr
    typename std::enable_if<g24_lib::Definitions::elementwise_point_operators, fspoint>::type
    operator/ (const fspoint& b) const
    {
      return this->element_divide(b);
    }

    /*!
      \brief Increments the elements of the fspoint with limits and a carry to the next element.
      
      \deprecated Provided for backwards compatibility with \ref g24_lib::coll.
                  This never made too much sense to begin with,
                  but was useful to express some algorithms regarding
                  finding borders in a more concise way. It probably should have been
                  implemented as a function of coll in any case,
                  but now old code could break...
      
      \param limits The intended upper limits for this operation.
      
      \param where The position from which we should start incrementing.
      
      \param reverse If `false`, we increment from the position specified \p where
                      to the end of the `fspoint`. If `true`, we increment in the reverse direction:
                      we start at \p where and go towards the beginning of the `fspoint`.
                      
      \param brk If, by any reason, one knows all of the elements will be well inside the limits,
                 one can put \p brk to `true` to stop carrying after incrementing at \p where.
      
      \remark In essence, what this does is:
             -# Begin at the position specified by \p where
             -# Increment the value of the position
             -# Go in the direction specified by \p reverse
             -# If the previous position is equal or larger than the limits,
                  put the previous value to zero and increment the current position.
             -# If `brk` is true, stop here, else, continue in the direction specified by \p reverse
                until the end (or the beginning) of the `fspoint` is reached.
                
      \throw In case \p where out of bounds, uses g24_lib::exceptions::throw_exception
              to possibly throw a g24_lib::exceptions::out_of_bounds_access.
    */
    void inline inc_with_wrap(fspoint<Type, indexer, Size> &limits, const indexer where = 0, bool reverse = false, bool brk = false)
    {
      indexer i = std::max(where, Size-1);
      if (where >= Size)
        {
          exceptions::throw_exception(exceptions::out_of_bounds_access("Trying to use non-existent position for inc_with_wrap."));
        }
      val[i] = val[i] + (Type) 1;
      if (reverse)
        {
          for(i = i - 1; i >= 0; --i)
            {
              if (val[i+1] >= limits[i+1])
                {
                  val[i] = val [i] + (Type) 1;
                  val[i+1] = (Type) 0;
                }
              else if(brk)
                {
                  break;
                }
              if (i == 0)
                {
                  break;
                }
            }
        }
      else
        {
          for(i = i + 1; i < Size; ++i)
            {
              if (val[i-1] >= limits[i-1])
                {
                  val[i] = val[i] + 1;
                  val[i-1] = 0;
                }
              else if(brk)
                {
                  break;
                }
            }
        }
    }
    
    /*!
      \brief Prints an `fspoint` in a mathematical notation.
      
      \remark For instance,
~~~~~~{.cpp}      
fspoint<int, int, 5> p{1,2,3,4,5};

std::cout << p << std::endl;
~~~~~~
      \remark would output `(1, 2, 3, 4, 5)`.
             
      \warning For serialization, prefer the use of `textual_output`!
    */
    friend std::ostream& operator<< (std::ostream &s, const fspoint<Type, indexer, Size> &p)
    {
      indexer i, j = Size - 1;
      if (Size)
        {
          s << "(";
          for (i = 0; i < j; ++i)
            {
              s << p.val[i] << ", ";
            }
          s << p.val[Size-1] << ")";
        }
      return s;
    }
    
    /*!
      \brief Returns an `fspoint` with an element deleted from the position specified by \p where.
             The original `fspoint` is unchanged.
             
      \throw In case \p where is out of bounds, uses g24_lib::exceptions::throw_exception
              to possibly throw a g24_lib::exceptions::out_of_bounds_access.
    */
    fspoint<Type, indexer, Size-1> inline delete_from (const indexer where) const
    {
      if (where >= Size)
        {
          exceptions::throw_exception(exceptions::out_of_bounds_access("Trying to delete from undefined position."));
        }
      fspoint<Type, indexer, Size-1> ret;
      for(indexer i = 0; i < Size; ++i)
        {
          ret.val[i-(i > where)] = val[i];
        }
      return ret;
    }
    
    /*!
      \brief Reads an `fspoint` from mathematical notation.
      
      \remark For instance, to get an `fspoint` equivalen to one constructed by `fspoint<int, int, 5> p{1,2,3,4,5}`,
              one should read something of the form `{1,2,3,4,5}`, `(1,2,3,4,5)` or `[1,2,3,4,5]`,
              with any amount of whitespace in between.
              
      \warning For serialization, prefer the use of `textual_input`!
    */
    friend std::istream& operator>> (std::istream &s, fspoint<Type, indexer, Size> &p)
    {
      auto pos = s.tellg();
      fspoint<Type, indexer, Size> ret;
      s >> std::ws;
      if(s.peek() != '(' && s.peek() != '{' && s.peek() != '[')
        {
          s.setstate(std::ios::failbit);
          s.seekg(pos);
          return s;
        }
      for(indexer i = 0; i < Size - 1; ++i)
        {
          if(s.peek() != '+' && s.peek() != '-' && !std::isdigit(s.peek()))
            {
              s.get();
              //Get rid of commas or parentheses or the like.
            }
          s >> std::ws;
          s >> ret.val[i];
          s >> std::ws;
          if(s.peek() != ',' && s.peek() != ';' && s.peek() != ':'
             && s.peek() != '+' && s.peek() != '-' && !std::isdigit(s.peek()))
            {
              s.setstate(std::ios::failbit);
              s.seekg(pos);
              return s;
            }
        }
      if(s.peek() != '+' && s.peek() != '-' && !std::isdigit(s.peek()))
        {
          s.get();
          //Get rid of commas or parentheses or the like.
        }
      s >> std::ws;
      s >> ret.val[Size -1];
      s >> std::ws;
      if(s.peek() != ')' && s.peek() != '}' && s.peek() != ']')
        {
          s.setstate(std::ios::failbit);
          s.seekg(pos);
          return s;
        }
      s.get();
      p = ret;
      return s;
    }
    
    /*!
      \brief Returns the dot (scalar) product of two vectors.
    */
    friend CUDA_HOS_DEV constexpr inline Type dotp(const fspoint<Type, indexer, Size> &u, const fspoint<Type, indexer, Size> &v)
    {
      indexer i;
      Type ret;
      if (Size)
        {
          ret = u[0]*v[0];
          for (i = 1; i < Size; ++i)
            {
              ret += u[i]*v[i];
            }
          return ret;
        }
      return (Type) 0;
    }
    
    /*!
      \brief Returns the cross (vector) product of two vectors.
      
      \todo Eventually, extend this to the other valid cross-product, in 7D.
             
    */
    friend CUDA_HOS_DEV inline constexpr fspoint<Type, indexer, Size> crossp(const fspoint<Type, indexer, Size> &u, const fspoint<Type, indexer, Size> &v)
    {
      static_assert(Size == 3, "Cross products only exist in three or seven dimensions,"
                               "but only the three dimensional case has been implemented.");
      fspoint <Type, indexer, Size> ret;
      ret.val[0] = u.val[1] * v.val[2] - u.val[2] * v.val[1];
      ret.val[1] = u.val[2] * v.val[0] - u.val[0] * v.val[2];
      ret.val[2] = u.val[0] * v.val[1] - u.val[1] * v.val[0];
      return ret;
    }
    
    /*!
      \brief Returns the dot (scalar) product of two vectors.
    */
    CUDA_HOS_DEV inline Type constexpr dotp(const fspoint<Type, indexer, Size> &v) const
    {
      indexer i;
      Type ret;
      if (Size)
        {
          ret = val[0]*v[0];
          for (i = 1; i < Size; ++i)
            {
              ret += val[i]*v[i];
            }
          return ret;
        }
      return (Type) 0;
    }
    
    /*!
      \brief Returns the cross (vector) product of two vectors.
              
      \todo Eventually, extend this to the other valid cross-product, in 7D.
             
    */
    CUDA_HOS_DEV inline constexpr fspoint<Type, indexer, Size> crossp(const fspoint<Type, indexer, Size> &v) const
    {
      static_assert(Size == 3, "Cross products only exist in three or seven dimensions,"
                               "but only the three dimensional case has been implemented.");
      fspoint <Type, indexer, Size> ret;
      ret.val[0] = val[1] * v.val[2] - val[2] * v.val[1];
      ret.val[1] = val[2] * v.val[0] - val[0] * v.val[2];
      ret.val[2] = val[0] * v.val[1] - val[1] * v.val[0];
      return ret;
    }
    
    /*!
      \brief Computes the projection of one vector acoording to another.
      
      \param p The other vector acoording to which the projection will be calculated.
      
      \param normal If one knows beforehand that \p p is normal,
                    one may set this to `true` to avoid normalizing it again.
    */
    CUDA_HOS_DEV inline constexpr fspoint<Type, indexer, Size> project(const fspoint<Type, indexer, Size> &p, const bool normal = false) const
    {
      if (normal)
        {
          return p * (dotp((*this), p));
        }
      return p * (dotp((*this), p)/dotp(p, p));
    }
    
    
    /*!
      \brief Computes the orthogonal part of one vector acoording to another.
      
      \param p The other vector acoording to which the orthogonality will be calculated.
      
      \param normal If one knows beforehand that \p p is normal,
                    one may set this to `true` to avoid normalizing it again.
      
      \sa g24_lib::fspoint::project
    */
    CUDA_HOS_DEV inline constexpr fspoint<Type, indexer, Size> ortog(const fspoint<Type, indexer, Size> &p, const bool normal = false) const
    {
      return ((*this) - project(p, normal));
    }
    
    /*!
      \brief Computes the projection of one vector acoording to another.
      
      \param a The vector that will be projected.
      
      \param b The other vector acoording to which the projection will be calculated.
      
      \param normal If one knows beforehand that \p b is normal,
                    one may set this to `true` to avoid normalizing it again.
    */
    friend CUDA_HOS_DEV inline constexpr fspoint<Type, indexer, Size> project(const fspoint<Type, indexer, Size> &a, const fspoint<Type, indexer, Size> &b, const bool normal = false)
    {
      return a.project(b, normal);
    }
    
    /*!
      \brief Computes the orthogonal part of one vector acoording to another.
      
      \param a The vector whose orthogonal part will be computed.
      
      \param b The other vector acoording to which the orthogonality will be calculated.
      
      \param normal If one knows beforehand that \p b is normal,
                    one may set this to `true` to avoid normalizing it again.
      
      \sa g24_lib::ortog
    */
    friend CUDA_HOS_DEV inline constexpr fspoint<Type, indexer, Size> ortog(const fspoint<Type, indexer, Size> &a, const fspoint<Type, indexer, Size> &b, const bool normal = false)
    {
      return a.ortog(b, normal);
    }

    /*!
      \brief Calculates the angle between two vectors with the usual inner product.
      
      \param p The other vector.
      
      \remark Invokes `std::acos` to get the angle.
    */
    CUDA_HOS_DEV inline Type angle(const fspoint<Type, indexer, Size> &p) const
    {
      Type ret = 0, l1 = 0, l2 = 0;
      indexer i;
      for(i = 0; i < Size; ++i)
        {
          ret += val[i]*p.val[i];
          l1 += val[i]*val[i];
          l2 += p.val[i]*p.val[i];
        }
      return std::acos(ret/sqrt(l1*l2));
    }

    /*!
      \brief Calculates the angle between two vectors with the usual inner product.
      
      \param v One vector.
      
      \param u The other vector.
      
      \remark Invokes `std::acos` to get the angle.
    */
    friend CUDA_HOS_DEV inline Type angle(const fspoint<Type, indexer, Size> &v, const fspoint <Type, indexer, Size> &u)
    {
      return v.angle(u);
    }

    /*!
      \brief Calculates the co-sine of the angle between two vectors with the usual inner product.
      
      \param p The other vector.
    */
    CUDA_HOS_DEV inline Type cosangle(const fspoint<Type, indexer, Size> &p) const
    {
      Type ret = 0, l1 = 0, l2 = 0;
      indexer i;
      for(i = 0; i < Size; ++i)
        {
          ret += val[i]*p.val[i];
          l1 += val[i]*val[i];
          l2 += p.val[i]*p.val[i];
        }
      return (ret/sqrt(l1*l2));
    }

    /*!
      \brief Calculates the co-sine of the angle between two vectors with the usual inner product.
      
      \param v One vector.
      
      \param u The other vector.
    */
    friend CUDA_HOS_DEV inline Type cosangle(const fspoint<Type, indexer, Size> &v, const fspoint <Type, indexer, Size> &u)
    {
      return v.cosangle(u);
    }
    
    /*!
      \brief Multiplies a scalar by a vector, for ease of writing some equations.
    */
    friend CUDA_HOS_DEV inline constexpr fspoint<Type, indexer, Size> operator*(const Type &a, const fspoint<Type, indexer, Size> &p)
    {
      return p*a;
    }
    
    /*!
      \brief Gives direct access to the underlying array.
      
      \warning This gives actual access to the raw array. It shouldn't absolutely be used
               unless the user is really, really sure of what will be done.
      
      \deprecated This is kept for compatibility with older code,
                  where copying to CUDA and so on wasn't as well abstracted
                  as it is now. It really, really shouldn't be needed anymore.
    */
    CUDA_HOS_DEV inline Type (& get_access_to_array() )[Size]
    {
      return val;
    }
    
    /*!
      \brief Gives direct access to the underlying array.
      
      \warning This gives actual access to the raw array. It shouldn't absolutely be used
               unless the user is really, really sure of what will be done.
      
      \deprecated This is kept for compatibility with older code,
                  where copying to CUDA and so on wasn't as well abstracted
                  as it is now. It really, really shouldn't be needed anymore.
    */
    CUDA_HOS_DEV inline const Type (& get_access_to_array() const )[Size]
    {
      return val;
    }
    
    /*!
      \brief Returns an `fspoint` with the same elements, but in reverse order.
      
      \param actually_do If false, simply return a copy of the `fspoint`.
            (Provided for situations in which we may want to reverse or not depending on a condition).
    */
    fspoint<Type, indexer, Size> CUDA_HOS_DEV constexpr inline reverse(const bool actually_do = true) const
    {
      if(!actually_do)
        {
          return (*this);
        }
      fspoint<Type, indexer, Size> ret;
      for (indexer i = 0; i < Size; ++i)
        {
          ret.val[i] = val[Size-i-1];
        }
      return ret;
    }
    
    /*!
      \brief Returns an `fspoint` with the element at \p coord set to \p new_val and all others equal.
    */
    fspoint<Type, indexer, Size> CUDA_HOS_DEV constexpr inline set(const indexer coord, const Type new_val) const
    {
      fspoint<Type, indexer, Size> ret(*this);
      ret[coord] = new_val;
      return ret;
    }
    
    /*!
      \brief Returns an `fspoint` with \p new_val added to the element at \p coord and all others equal.
      
      \remark Just to be clear since English is sometimes tricky, we get `returned_fspoint[coord] = fspoint[coord] + new_val`.
    */
    fspoint<Type, indexer, Size> CUDA_HOS_DEV constexpr inline add(const indexer coord, const Type to_add) const
    {
      fspoint<Type, indexer, Size> ret(*this);
      ret[coord] = ret[coord] + to_add;
      return ret;
    }
    
    /*!
      \brief Returns an `fspoint` with \p new_val subtracted from the element at \p coord and all others equal.
      
      \remark Just to be clear since English is sometimes tricky, we get `returned_fspoint[coord] = fspoint[coord] - new_val`.
    */
    fspoint<Type, indexer, Size> CUDA_HOS_DEV constexpr inline subtract(const indexer coord, const Type to_subtract) const
    {
      fspoint<Type, indexer, Size> ret(*this);
      ret[coord] = ret[coord] - to_subtract;
      return ret;
    }
    
    /*!
      \brief Returns an `fspoint` with the element at \p coord multiplied by \p new_val and all others equal.
      
      \remark Just to be clear since English is sometimes tricky, we get `returned_fspoint[coord] = fspoint[coord] * new_val`.
    */
    fspoint<Type, indexer, Size> CUDA_HOS_DEV constexpr inline multiply(const indexer coord, const Type to_multiply) const
    {
      fspoint<Type, indexer, Size> ret(*this);
      ret[coord] = ret[coord] * to_multiply;
      return ret;
    }
    
    /*!
      \brief Returns an `fspoint` with the element at \p coord divided by \p new_val and all others equal.
      
      \remark Just to be clear since English is sometimes tricky, we get `returned_fspoint[coord] = fspoint[coord] / new_val`.
    */
    fspoint<Type, indexer, Size> CUDA_HOS_DEV constexpr inline divide(const indexer coord, const Type to_divide) const
    {
      fspoint<Type, indexer, Size> ret(*this);
      ret[coord] = ret[coord] / to_divide;
      return ret;
    }
    
    
    /*!
      \brief Returns the coordinate \p i of the `fspoint`.
      
      \remark Provided for compatibility with structured bindings.
    */
    template <g24_lib::Definitions::default_unsigned_indexer i> CUDA_HOS_DEV constexpr Type& get()
    {
      return val[i];
    }

    /*!
      \brief Returns the coordinate \p i of the `fspoint`.
      
      \remark Provided for compatibility with structured bindings.
    */
    template <g24_lib::Definitions::default_unsigned_indexer i> CUDA_HOS_DEV constexpr const Type& get() const
    {
      return val[i];
    }
    
    template<class stream, class str = std::basic_string<typename stream::char_type>>
    CUDA_ONLY_HOS void textual_output(stream &s, const str& separator = " ") const
    {
      for(indexer i = 0; i < Size-1; ++i)
        {
          g24_lib::textual_output(s, val[i], separator);
          s << separator;
        }
      g24_lib::textual_output(s, val[Size-1], separator);
      
    }
    
    template<class stream>
    CUDA_ONLY_HOS void textual_input(stream &s)
    {
      fspoint<Type, indexer, Size> temp;
      for(indexer i = 0; i < Size; ++i)
        {
          g24_lib::textual_input(s, temp.val[i]);
        }
      (*this) = temp;
    }
    
    template<class stream>
    CUDA_ONLY_HOS void binary_output(stream &s) const
    {
      for(indexer i = 0; i < Size; ++i)
        {
          g24_lib::binary_output(s, val[i]);
        }
    }
    
    template<class stream>
    CUDA_ONLY_HOS void binary_input(stream &s)
    {
      fspoint<Type, indexer, Size> temp;
      for(indexer i = 0; i < Size; ++i)
        {
          g24_lib::binary_input(s, temp.val[i]);
        }
      (*this) = temp;
    }
    
    /*!
      \brief Converts between `fspoints` of different types
             as long as those types can be cast to one another.
    */
    template <class Other_type>
    CUDA_HOS_DEV constexpr operator fspoint<Other_type, indexer, Size>() const
    {
      fspoint<Other_type, indexer, Size> ret;
      for (indexer i = 0; i < Size; ++i)
        {
          ret.val[i] = Other_type(val[i]);
        }
      return ret;
    }
  };
  
  /*!
    \brief Creates a new `fspoint` read from a stream.
    
    \warning Serialization should be handled by textual_input and textual_output.
             This might still be useful for prompting the user,
             since it accepts the same formats as `g24_lib::fspoint<Type, indexer, Size>::operator>>`.
  */
  template <class Type, class indexer = g24_lib::Definitions::default_unsigned_indexer, indexer Size = g24_lib::Definitions::default_fixed_size>
  fspoint<Type, indexer, Size> raw_read_fspoint (std::istream &s)
  {
    indexer i;
    fspoint<Type, indexer, Size> ret;
    for (i = 0; i < Size; ++i)
      {
        s >> ret[i];
      }
    return ret;
  }
  
    
}


/*!
\brief Calculates the norm of a vector using `abs` for its elements.

\param p The kind of norm we want to calculate. Usual norm has \p `p == 2`,
       but it is mathematically valid as long as `p >= 1`.
       
\tparam p_type The type that is appropriate to indicate the norm.
*/
template <class Type, class indexer, indexer Size, class p_type = decltype( abs( std::declval<Type>() ) ) >
CUDA_HOS_DEV p_type abs(const g24_lib::fspoint<Type, indexer, Size> &p, const p_type num = 2)
{
  using namespace std;
  //So CUDA doesn't complain...
  indexer i;
  /*
  if (std::isinf(num))
    {
      p_type ret = 0;
      for (i = 0; i < Size; ++i)
        {
          p_type temp = fabs(p[i]);
          ret = temp > ret ? temp : ret;
        }
      return ret;
    }
  else*/
    {
      p_type ret = 0;
      for (i = 0; i < Size; ++i)
        {
          ret += pow(abs(p[i]), num);
        }
      return pow(ret, p_type(1)/num);
    }
}

/*!
\brief Calculates the norm of a vector using `fabs` for its elements.

\param p The kind of norm we want to calculate. Usual norm has \p `p == 2`,
       but it is mathematically valid as long as `p >= 1`.
       
\tparam p_type The type that is appropriate to indicate the norm.
*/
template <class Type, class indexer, indexer Size, class p_type = decltype( fabs( std::declval<Type>() ) ) >
CUDA_HOS_DEV p_type fabs(const g24_lib::fspoint<Type, indexer, Size> &p, const p_type num = 2)
{
  using namespace std;
  //So CUDA doesn't complain...
  indexer i;
  /*
  if (std::isinf(num))
    {
      p_type ret = 0;
      for (i = 0; i < Size; ++i)
        {
          p_type temp = fabs(p[i]);
          ret = temp > ret ? temp : ret;
        }
      return ret;
    }
  else*/
    {
      p_type ret = 0;
      for (i = 0; i < Size; ++i)
        {
          ret += pow(fabs(p[i]), num);
        }
      return pow(ret, p_type(1)/num);
    }
}

/*!
\brief Calculates the norm of a vector using `fabsf` for its elements.

\param p The kind of norm we want to calculate. Usual norm has \p `p == 2`,
       but it is mathematically valid as long as `p >= 1`.
       
\tparam p_type The type that is appropriate to indicate the norm.
*/
template <class Type, class indexer, indexer Size, class p_type = decltype( fabsf( std::declval<Type>() ) ) >
CUDA_HOS_DEV p_type fabsf(const g24_lib::fspoint<Type, indexer, Size> &p, const p_type num = 2)
{
  using namespace std;
  //So CUDA doesn't complain...
  indexer i;/*
  if (std::isinf(num))
    {
      p_type ret = 0;
      for (i = 0; i < Size; ++i)
        {
          ret = max(ret, fabsf(p[i]));
        }
      return ret;
    }
  else*/
    {
      p_type ret = 0;
      for (i = 0; i < Size; ++i)
        {
          ret += powf(fabsf(p[i]), num);
        }
      return powf(ret, p_type(1)/num);
    }
}

/*!
\brief Returns an `fspoint` whose elements are the `floor` of those of the input `fspoint`.
*/
template <class Type, class indexer, indexer Size>
CUDA_HOS_DEV g24_lib::fspoint<Type, indexer, Size> floor(const g24_lib::fspoint<Type, indexer, Size> &p)
{
  using namespace std;
  //So CUDA doesn't complain...
  g24_lib::fspoint<Type, indexer, Size> ret;
  for (indexer i = 0; i < Size; ++i)
    {
      ret[i] = floor(p[i]);
    }
  return ret;
}

/*!
\brief Returns an `fspoint` whose elements are the `floorf` of those of the input `fspoint`.
*/
template <class Type, class indexer, indexer Size>
CUDA_HOS_DEV g24_lib::fspoint<Type, indexer, Size> floorf(const g24_lib::fspoint<Type, indexer, Size> &p)
{
  using namespace std;
  //So CUDA doesn't complain...
  g24_lib::fspoint<Type, indexer, Size> ret;
  for (indexer i = 0; i < Size; ++i)
    {
      ret[i] = floorf(p[i]);
    }
  return ret;
}

/*!
\brief Returns an `fspoint` whose elements are the `ceil` of those of the input `fspoint`.
*/
template <class Type, class indexer, indexer Size>
CUDA_HOS_DEV g24_lib::fspoint<Type, indexer, Size> ceil(const g24_lib::fspoint<Type, indexer, Size> &p)
{
  using namespace std;
  //So CUDA doesn't complain...
  g24_lib::fspoint<Type, indexer, Size> ret;
  for (indexer i = 0; i < Size; ++i)
    {
      ret[i] = ceil(p[i]);
    }
  return ret;
}

/*!
\brief Returns an `fspoint` whose elements are the `ceilf` of those of the input `fspoint`.
*/
template <class Type, class indexer, indexer Size>
CUDA_HOS_DEV g24_lib::fspoint<Type, indexer, Size> ceilf(const g24_lib::fspoint<Type, indexer, Size> &p)
{
  using namespace std;
  //So CUDA doesn't complain...
  g24_lib::fspoint<Type, indexer, Size> ret;
  for (indexer i = 0; i < Size; ++i)
    {
      ret[i] = ceilf(p[i]);
    }
  return ret;
}

/*!
\brief Returns an `fspoint` whose elements are the `trunc` of those of the input `fspoint`.
*/
template <class Type, class indexer, indexer Size>
CUDA_HOS_DEV g24_lib::fspoint<Type, indexer, Size> trunc(const g24_lib::fspoint<Type, indexer, Size> &p)
{
  using namespace std;
  //So CUDA doesn't complain...
  g24_lib::fspoint<Type, indexer, Size> ret;
  for (indexer i = 0; i < Size; ++i)
    {
      ret[i] = trunc(p[i]);
    }
  return ret;
}

/*!
\brief Returns an `fspoint` whose elements are the `truncf` of those of the input `fspoint`.
*/
template <class Type, class indexer, indexer Size>
CUDA_HOS_DEV g24_lib::fspoint<Type, indexer, Size> truncf(const g24_lib::fspoint<Type, indexer, Size> &p)
{
  using namespace std;
  //So CUDA doesn't complain...
  g24_lib::fspoint<Type, indexer, Size> ret;
  for (indexer i = 0; i < Size; ++i)
    {
      ret[i] = truncf(p[i]);
    }
  return ret;
}

/*!
\brief Returns an `fspoint` whose elements are the `round` of those of the input `fspoint`.
*/
template <class Type, class indexer, indexer Size>
CUDA_HOS_DEV g24_lib::fspoint<Type, indexer, Size> round(const g24_lib::fspoint<Type, indexer, Size> &p)
{
  using namespace std;
  //So CUDA doesn't complain...
  g24_lib::fspoint<Type, indexer, Size> ret;
  for (indexer i = 0; i < Size; ++i)
    {
      ret[i] = round(p[i]);
    }
  return ret;
}

/*!
\brief Returns an `fspoint` whose elements are the `roundf` of those of the input `fspoint`.
*/
template <class Type, class indexer, indexer Size>
CUDA_HOS_DEV g24_lib::fspoint<Type, indexer, Size> roundf(const g24_lib::fspoint<Type, indexer, Size> &p)
{
  using namespace std;
  //So CUDA doesn't complain...
  g24_lib::fspoint<Type, indexer, Size> ret;
  for (indexer i = 0; i < Size; ++i)
    {
      ret[i] = roundf(p[i]);
    }
  return ret;
}

///\cond HIDDEN_SYMBOLS
namespace std
{
  template <class T, class ind, ind size> struct tuple_size<g24_lib::fspoint<T, ind, size>> : 
    std::integral_constant<size_t, size> { };
  
  template <size_t I, class T, class ind, ind size> struct tuple_element<I, g24_lib::fspoint<T, ind, size>>
  { 
    using type = T;
  };
}
///\endcond


#endif

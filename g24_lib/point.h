#ifndef G24_LIB_POINT
#define G24_LIB_POINT

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

\file point.h

\brief Defines `g24_lib::point`, a (mostly deprecated) dynamic version of `g24_lib::fspoint`.

\author Nuno Fernandes (main coder, current maintainer)

\author Gonçalo Vaz (auxiliary coder and tester)

*/

namespace g24_lib
{
  
  /*!
    \brief A dynamically sized array of type \p Type. Mainly to be used as an N-dimensional vector
           in mathematical or physical contexts.
           
    \tparam Type The type of the elements of the array.
    
    \tparam indexer The type that should be able to hold the size of the array.
        
    \pre \p Type should provide appropriate arithmetic operators if `point` is to be used as a mathematical vector.
    
    \pre \p indexer must satisfy the constraints placed on the choice of \ref g24_lib::Definitions::default_unsigned_indexer.
    
    \deprecated This class is more or less deprecated since its usefulness is limited.
                In most practical problems, the dimensions are fixed,
                dynamic allocations are slower and \c CUDA interoperatability
                is quite limited. However, compatibility with past projects
                requires it to remain here for the time being, at least.
  */
  template <class Type, class indexer = g24_lib::Definitions::default_unsigned_indexer> class point
  {
    typedef Type value_type;
    typedef indexer indexer_type;
    template <class A, class B, B> friend class fspoint;
    //A slightly convoluted way of getting what we want,
    //that is for the several fspoint<Type, indexer, Size>
    //to be friends for different Size but same Type and indexer.
    
  private:
  
    Type* val;
    //The array itself.
    indexer Size;
    //The length of the array.
    
  public:
    /*!
      \brief Empty constructor.
    */
    point()
    {
      Size = 0;
      val = nullptr;
    }
/*
  private:

    template<class ... Rest> void initialize_several(const indexer i, Rest ... others){};

    template<class T, class ... Rest> void initialize_several(const indexer i, T first, Rest ... others)
    {
      if(i < Size)
        {
          val[i] = first;
          initialize_several(i+1,others...);
        }
    }

  public:

    template<class ... Rest>  point(const indexer n, Type first, Rest ... others)
    {
      Size = n;
      val = nullptr;
      if(n > 0)
        {
          val = new Type[n];
          val[0] = first;
          initialize_several(1,others...);
        }
    }

*/
    /*!
      \brief Constructor from a `g24_lib::fspoint`.
    */
    template <indexer sz> point(const fspoint<Type, indexer, sz> &p)
    {
      Size = sz;
      val = nullptr;
      if (sz)
        {
          val = new Type[sz];
          for(indexer i = 0; i < sz; ++i)
            {
              val[i] = p.val[i];
            }
        }
    }
    
    /*!
      \brief Construct with a specific size.
    */
    point(const indexer n)
    {
      Size = n;
      val = nullptr;
      if (n)
        {
          val = new Type[n];
        }
    }
    
    /*!
      \brief Construct with an array of \p n elements.
    */
    point (const indexer n, const Type *a)
    {
      Size = n;
      val = nullptr;
      if (n)
        {
          val=new Type[n];
          for(indexer i = 0; i < n; ++i)
            {
              val[i] = a[i];
            }
        }
    }
    
    /*!
      \brief Copy constructor.
    */
    point(const point<Type, indexer> &p)
    {
      Size = p.Size;
      val = nullptr;
      if (Size)
        {
          val = new Type[p.Size];
          for(indexer i = 0; i < p.Size; ++i)
            {
              val[i] = p.val[i];
            }
        }
    }
    
    /*!
      \brief Move constructor.
    */
    point(point<Type, indexer> &&p)
    {
      Size = p.Size;
      val = p.val;
      p.val = nullptr;
      p.Size = 0;
    }
    
    /*!
      \brief Construct with \p n elements equal to \p a.
    */
    point(const indexer n, const Type &a)
    {
      indexer i;
      Size = n;
      val = nullptr;
      if (n)
        {
          val=new Type[n];
          for (i = 0; i < n; ++i)
            {
              val[i] = a;
            }
        }
    }
    /*!
      \remark If this weren't deprecated, it could gain from some refactoring
              to be constructed by a generic container...
    */
    explicit point(const std::vector<Type> &v)
    {
      Size = v.size();
      val = nullptr;
      if (Size)
        {
          val=new Type[Size];
          for(indexer i = 0; i < Size; ++i)
            {
              val[i] = v[i];
            }
        }
    }
    
    inline const indexer size() const
    {
      return Size;
    }
    
    /*!
      \remark We always sum up to the minimum size.
    */
    inline point operator+(const point &p) const
    {
      point temp(Size);
      indexer i, j = (temp.Size > p.Size ? p.Size : temp.Size);
      for (i = 0; i < j; ++i)
        {
          temp.val[i] = val[i] + p.val[i];
        }
      return temp;
    }
    
    /*!
      \remark We always subtract up to the minimum size.
    */
    inline point operator-(const point &p) const
    {
      point temp(Size);
      indexer i, j = (temp.Size > p.Size ? p.Size : temp.Size);
      for (i = 0; i < j; ++i)
        {
          temp.val[i] = val[i] - p.val[i];
        }
      return temp;
    }
    
    /*!
      \pre We assume the array is at least as large as the `point`.
    */
    inline point operator+(const Type * const a) const
    {
      point temp(Size);
      indexer i;
      for (i = 0; i < Size; ++i)
        {
          temp.val[i] = val[i] + a[i];
        }
      return temp;
    }
    
    /*!
      \pre We assume the array is at least as large as the `point`.
    */
    inline point operator-(const Type * const a) const
    {
      point temp(Size);
      indexer i;
      for (i = 0; i < Size; ++i)
        {
          temp.val[i] = val[i] - a[i];
        }
      return temp;
    }
    
    inline point operator-() const
    {
      point temp(Size);
      indexer i;
      for (i = 0; i < temp.Size; ++i)
        {
          temp.val[i] = -val[i];
        }
      return temp;
    }
    
    /*!
      \brief Multiplication by scalar.
    */
    inline point operator*(const Type &a) const
    {
      point temp(Size);
      indexer i;
      for (i = 0; i < temp.Size; ++i)
        {
          temp.val[i] = val[i]*a;
        }
      return temp;
    }
    
    /*!
      \brief Division by scalar.
    */
    inline point operator/(const Type &a) const
    {
      point temp(Size);
      indexer i;
      for (i = 0; i < temp.Size; ++i)
        {
          temp.val[i] = val[i]/a;
        }
      return temp;
    }
    
    inline Type& operator[](const indexer i)
    {
      return val[i];
    }
    
    inline const Type& operator[](const indexer i) const
    {
      return val[i];
    }
    
    /*!
      \brief Bounded access operator.
          
      \throw In case the access is out of bounds, uses g24_lib::exceptions::throw_exception
              to possibly throw a g24_lib::exceptions::out_of_bounds_access.
    */
    inline Type& operator()(const indexer i)
    {
      if (i >= Size)
        {
          exceptions::throw_exception(exceptions::out_of_bounds_access("Trying to access invalid position."));
        }
      return val[i];
    }
    
    /*!
      \brief Bounded access operator.
          
      \throw In case the access is out of bounds, uses g24_lib::exceptions::throw_exception
              to possibly throw a g24_lib::exceptions::out_of_bounds_access.
    */
    inline const Type& operator()(const indexer i) const
    {
      if (i >= Size)
        {
          exceptions::throw_exception(exceptions::out_of_bounds_access("Trying to access invalid position."));
        }
      return val[i];
    }
    
    inline bool operator== (const point &p) const
    {
      indexer i;
      if (Size != p.Size)
        {
          return false;
        }
      for (i = 0; i < Size; ++i)
        {
          if (val[i] != p.val[i])
            {
              return false;
            }
        }
      return true;
    }
    
    inline bool operator!= (const point &p) const
    {
      return !(p == *this);
    }
    
    inline point& operator=(const point &p)
    {
      if(&p == this)
        {
          return (*this);
        }
      if(Size != p.Size)
        {
          Size = p.Size;
          if (val)
            {
              delete[] val;
              val = nullptr;
            }
          if(Size)
            {
              val = new Type[Size];
            }
        }
      if(Size)
        {
          for(indexer i = 0; i < Size; ++i)
            {
              val[i] = p.val[i];
            }
        }
      return *this;
    }
    
    inline point& operator=(point &&p)
    {
      if(&p == this)
        {
          return (*this);
        }
      if(val != nullptr)
        {
          delete[] val;
        }
      val = p.val;
      Size = p.Size;
      p.val = nullptr;
      return *this;
    }
    
    inline point& operator+=(const point &p)
    {
      indexer i, j = (Size > p.Size ? p.Size : Size);
      for (i = 0; i < j; ++i)
        {
          val[i] += p.val[i];
        }
      return *this;
    }
    
    inline point& operator-=(const point &p)
    {
      indexer i, j = (Size > p.Size ? p.Size : Size);
      for (i = 0; i < j; ++i)
        {
          val[i] -= p.val[i];
        }
      return *this;
    }
    
    /*!
      \pre We assume the array is at least as large as the `point`.
    */
    inline point& operator+=(const Type * const a)
    {
      indexer i;
      for (i = 0; i < Size; ++i)
        {
          val[i] += a[i];
        }
      return *this;
    }
    
    /*!
      \pre We assume the array is at least as large as the `point`.
    */
    inline point& operator-=(const Type * const a)
    {
      indexer i;
      for (i = 0; i < Size; ++i)
        {
          val[i] -= a[i];
        }
      return *this;
    }
    /*
    inline point& operator*=(const Type &a)
    {
      indexer i;
      for (i = 0; i < Size; ++i)
        {
          val[i] *= a;
        }
      return *this;
    }
    
    inline point& operator/=(const Type &a)
    {
      indexer i;
      for (i = 0; i < Size; ++i)
        {
          val[i] /= a;
        }
      return *this;
    }
    */
    
    
    /*!
    
      \brief Inserts a new value to the end of the `point`.
      
      \param x The new value to be inserted.
      
      \return A `point` of size `Size + 1` with the new value at the end.
      
      \warning By design choice, we do not change the original `point`.
    
    */
    inline point operator<< (const Type &x) const
    {
      point ret(Size+1);
      for(indexer i = 0; i < Size; ++i)
        {
          ret.val[i] = val[i];
        }
      ret.val[Size] = x;
      return ret;
    }
    
    /*!
    
      \brief Concatenates two `point`s.
      
      \param p The other point to be concatenated.
      
      \return A `point` of size `Size + Size2` with the elements of \p at the end.
    
      \warning By design choice, we do not change the original `point`.
    
    */
    inline point operator<< (const point &p) const
    {
      point ret(Size + p.Size);
      for(indexer i = 0; i < Size; ++i)
        {
          ret.val[i] = val[i];
        }
      for(indexer i = 0; i < p.Size; ++i)
        {
          ret.val[i+Size] = p.val[i];
        }
      return ret;
    }
    
    /*!
    
      \brief Removes \p n elements from the `point`.
      
      \param n The number of elements to be removed.
      
      \return A `point` of size `Size - n`.
    
      \warning By design choice, we do not change the original `point`.

      \throw If \p n is larger than the size of the array, uses g24_lib::exceptions::throw_exception
              to possibly throw a g24_lib::exceptions::out_of_bounds_access.
             
    */
    inline point operator>> (const indexer n) const
    {
      if (n >= Size)
        {
          if (n > Size)
            {
              exceptions::throw_exception(exceptions::out_of_bounds_access("Trying to remove more than there is."));
            }
          point ret;
          return ret;
        }
      point ret(Size - n);
      for(indexer i = 0; i < ret.Size; ++i)
        {
          ret.val[i] = val[i];
        }
      return ret;
    }
    
    /*!
      \brief Returns a `point` with an element deleted from the position specified by \p where.
             The original `point` is unchanged.
             
      \throw In case \p where is out of bounds, uses g24_lib::exceptions::throw_exception
              to possibly throw a g24_lib::exceptions::out_of_bounds_access.
    */
    inline point delete_from (const indexer where) const
    {
      if (where >= Size)
        {
          exceptions::throw_exception(exceptions::out_of_bounds_access("Trying to delete non-existent position."));
        }
      point ret(Size - 1);
      for(indexer i = 0; i < Size; ++i)
        {
          ret.val[i-(i>where)] = val[i];
        }
      return ret;
    }
    
    /*!
        \brief Prints a `point` to a stream as a series of objects.
    
        \param print_size If true, we output the size as well.
        
        \deprecated Old way of printing the contents of the `point`,
                    provided for backwards compatibility reasons.
                    Please use `textual_output` for proper serialization.
    */
    void raw_print(std::ostream &s, bool print_size = true) const
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
    
    
    inline Type sum_all() const
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
    
    inline Type multiply_all() const
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
    
    inline Type max() const
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
    inline Type max(indexer &comp) const
    {
      indexer a;
      comp = 0;
      if (Size)
        {
          Type ret = val[0];
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
    
    inline Type min() const
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
    inline Type min(indexer &comp) const
    {
      indexer a;
      comp = 0;
      if (Size)
        {
          Type ret = val[0];
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
    inline Type square_norm2() const
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
             If \p k specifies an invalid element of the vector,
             no change is made to the direction (all the components keep the signs they had before).
      
      \param norm The intended final value for the norm of the vector.
      
      \param p The kind of norm we want to calculate. Usual norm has \p `p == 2`,
             but it is mathematically valid as long as `p >= 1`.
             
    */
    inline point<Type, indexer> normalize(const indexer k = std::numeric_limits<indexer>::max(), const double norm = 1.0, const double p = 2.0) const
    {
      point<Type, indexer> temp(*this);
      double f = fabs(*this, p)/norm;
      if (std::isnan(f))
        {
          return temp;
        }
      indexer i;
      for (i = 0; i < Size; ++i)
        {
          temp.val[i] = temp.val[i]/ (Type) f;
        }
      return temp * (Type) (k >= Size ?  1.0 : (temp.val[k] < 0 ? -1.0 : 1.0));
    }
    
    /*!
      \brief Ensures the size of the vector is \p desired.
      
      \remark If this whole class weren't deprecated, it could and should be 
              renamed `resize` in accordance with what logic dictates...
             
    */
    inline void assure_size(const indexer desired)
    {
      if (Size == desired)
        {
          return;
        }
      else if (Size > desired)
        {
          (*this) >> (Size - desired);
        }
      else
        {
          Type *temp = new Type[desired];
          for(indexer i = 0; i < Size; ++i)
            {
              temp[i] = val[i];
            }
          delete[] val;
          val = temp;
          Size = desired;
        }
    }
    
    ~point()
    {
      delete[] val;
    }
    
    /*!
      \brief Sets all elements of the vector to \p a.
    */
    CUDA_HOS_DEV inline void set_all(const Type& a)
    {
      indexer i;
      for(i = 0; i < Size; ++i)
        {
          val[i] = a;
        }
    }
    
    /*!
      \brief Performs element-wise multiplication.
      
      \return A point whose elements are the elements of this point multiplied by the equivalent element of \p p.
      
    */
    inline point<Type, indexer> element_multiply(const point &p) const
    {
      point ret(*this);
      indexer i, j = (Size > p.Size ? p.Size : Size);
      for (i = 0; i < j; ++i)
        {
          ret[i] = ret[i] * p[i];
        }
      return ret;
    }
    
    
    /*!
      \brief Performs element-wise division.
      
      \return A point whose elements are the elements of this point divided by the equivalent element of \p p.
      
    */
    inline point<Type, indexer> element_divide(const point &p) const
    {
      point ret(*this);
      indexer i, j = (Size > p.Size ? p.Size : Size);
      for (i = 0; i < j; ++i)
        {
          ret[i] = ret[i] / p[i];
        }
      return ret;
    }
    
    /*!
      \brief Performs element-wise multiplication.
      
      \pre \p a is assumed to be at least as large as \p Size.
      
    */
    inline point<Type, indexer> element_multiply(const Type *a) const
    {
      point ret(*this);
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
      
    */
    inline point<Type, indexer> element_divide(const Type *a) const
    {
      point ret(*this);
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
    CUDA_HOS_DEV inline
    typename std::enable_if<g24_lib::Definitions::elementwise_point_operators, point>::type
    operator* (const point& b) const
    {
      return this->element_multiply(b);
    }

    /*!
      \brief Element-wise division.
      
      \remark Only defined if `g24_lib::Definitions::elementwise_point_operators` is true.
      
      \remark Although mathematically unsound, this might come in handy to use,
              for instance, arrays of fspoints in linear equation solvers.
    */
    CUDA_HOS_DEV inline
    typename std::enable_if<g24_lib::Definitions::elementwise_point_operators, point>::type
    operator/ (const point& b) const
    {
      return this->element_divide(b);
    }
    
    /*!
      \brief Increments the elements of the point with limits and a carry to the next element.
            
      \param limits The intended upper limits for this operation.
      
      \param where The position from which we should start incrementing.
      
      \param reverse If `false`, we increment from the position specified \p where
                      to the end of the `point`. If `true`, we increment in the reverse direction:
                      we start at \p where and go towards the beginning of the `point`.
                      
      \param brk If, by any reason, one knows all of the elements will be well inside the limits,
                 one can put \p brk to `true` to stop carrying after incrementing at \p where.
      
      \remark In essence, what this does is:
             -# Begin at the position specified by \p where
             -# Increment the value of the position
             -# Go in the direction specified by \p reverse
             -# If the previous position is equal or larger than the limits,
                  put the previous value to zero and increment the current position.
             -# If `brk` is true, stop here, else, continue in the direction specified by \p reverse
                until the end (or the beginning) of the `point` is reached.
                
      \throw In case \p where out of bounds, uses g24_lib::exceptions::throw_exception
              to possibly throw a g24_lib::exceptions::out_of_bounds_access.
    */
    inline void inc_with_wrap(point<Type, indexer> &limits, const indexer where = 0, bool reverse = false, bool brk = false)
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
      \brief Prints a `point` in a mathematical notation.
      
      \remark For instance,
~~~~~~{.cpp}      
point<int, int> p{1,2,3,4,5};

std::cout << p << std::endl;
~~~~~~
      \remark would output `(1, 2, 3, 4, 5)`.
             
      \warning For serialization, prefer the use of `textual_output`!
    */
    friend std::ostream& operator<< (std::ostream &s, const point<Type, indexer> &p)
    {
      indexer i, j = p.Size - 1;
      if (p.Size)
        {
          s << "(";
          for (i = 0; i < j; ++i)
            {
              s << p.val[i] << ", ";
            }
          s << p.val[p.Size-1] << ")";
        }
      return s;
    }
    
    /*!
      \brief Returns the dot (scalar) product of two vectors.
      
      \throw In case the vectors have different sizes,
              uses g24_lib::exceptions::throw_exception
              to possibly throw a g24_lib::exceptions::length_error.
    */
    inline friend Type dotp(const point<Type, indexer> &u, const point<Type, indexer> &v)
    {
      if(u.Size != v.Size)
        {
          exceptions::throw_exception(exceptions::length_error("Different sizes for dot product..."));
        }
      indexer i;
      Type ret;
      ret = u[0]*v[0];
      for (i = 1; i < u.Size; ++i)
        {
          ret += u[i]*v[i];
        }
      return ret;
    }
    
    /*!
      \brief Returns the cross (vector) product of two vectors.
      
      \throw In case the vectors have any number of dimensions other than 3,
              uses g24_lib::exceptions::throw_exception
              to possibly throw a g24_lib::exceptions::length_error.
                           
    */
    inline friend point<Type, indexer> crossp(const point<Type, indexer> &u, const point<Type, indexer> &v)
    {
      if (u.Size != 3 || v.Size != 3)
        {
          exceptions::throw_exception(std::length_error("Invalid and/or mismatched sizes for cross product."));
        }
      point <Type, indexer> ret(3);
      ret.val[0] = u.val[1] * v.val[2] - u.val[2] * v.val[1];
      ret.val[1] = u.val[2] * v.val[0] - u.val[0] * v.val[2];
      ret.val[2] = u.val[0] * v.val[1] - u.val[1] * v.val[0];
      return ret;
    }

    
    /*!
      \brief Returns the dot (scalar) product of two vectors.
      
      \throw In case the vectors have different sizes,
              uses g24_lib::exceptions::throw_exception
              to possibly throw a g24_lib::exceptions::length_error.
    */
    inline Type dotp(const point<Type, indexer> &v) const
    {
      if(Size != v.Size)
        {
          exceptions::throw_exception(exceptions::length_error("Different sizes for internal product..."));
        }
      indexer i;
      Type ret;
      ret = val[0]*v[0];
      for (i = 1; i < Size; ++i)
        {
          ret += val[i]*v[i];
        }
      return ret;
    }
    
    /*!
      \brief Returns the cross (vector) product of two vectors.
      
      \throw In case the vectors have any number of dimensions other than 3,
              uses g24_lib::exceptions::throw_exception
              to possibly throw a g24_lib::exceptions::length_error.
                           
    */
    inline point<Type, indexer> crossp(const point<Type, indexer> &v) const
    {
      if (Size != 3 || v.Size != 3)
        {
          exceptions::throw_exception(exceptions::length_error("Invalid and/or mismatched sizes for cross product."));
        }
      point <Type, indexer> ret(3);
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
    inline point<Type, indexer> project(const point<Type, indexer> &p, const bool normal = false) const
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
      
      \sa g24_lib::point::project
    */
    inline point<Type, indexer> ortog(const point<Type, indexer> &p, const bool normal = false) const
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
    inline friend point<Type, indexer> project(const point<Type, indexer> &a, const point<Type, indexer> &b, const bool normal = false)
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
    inline friend point<Type, indexer> ortog(const point<Type, indexer> &a, const point<Type, indexer> &b, const bool normal = false)
    {
      return a.ortog(b, normal);
    }

    /*!
      \brief Calculates the angle between two vectors with the usual inner product.
      
      \param p The other vector.
      
      \remark Invokes `std::acos` to get the angle.
    */
    inline Type angle(const point<Type, indexer> &p) const
    {
      if(Size != p.Size)
        {
          exceptions::throw_exception(exceptions::undefined_operation("Different sizes for internal product..."));
        }
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
    inline friend Type angle(const point<Type, indexer> &v, const point <Type, indexer> &u)
    {
      return v.angle(u);
    }

    /*!
      \brief Calculates the co-sine of the angle between two vectors with the usual inner product.
      
      \param p The other vector.
    */
    inline Type cosangle(const point<Type, indexer> &p) const
    {
      if(Size != p.Size)
        {
          exceptions::throw_exception(exceptions::undefined_operation("Different sizes for internal product..."));
        }
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
    inline friend Type cosangle(const point<Type, indexer> &v, const point <Type, indexer> &u)
    {
      return v.cosangle(u);
    }
    
    /*!
      \brief Multiplies a scalar by a vector, for ease of writing some equations.
    */
    inline friend point<Type, indexer> operator*(const Type &a, const point<Type, indexer> &p)
    {
      return p*a;
    }
    
    /*!
      \brief Gives direct access to the underlying array.
      
      \warning This gives actual access to the raw array. It shouldn't absolutely be used
               unless the user is really, really sure of what will be done.
    */
    inline Type *& get_access_to_array()
    {
      return val;
    }
    
    /*!
      \brief Gives direct access to the underlying array.
      
      \warning This gives actual access to the raw array. It shouldn't absolutely be used
               unless the user is really, really sure of what will be done.
    */
    inline const Type * get_access_to_array() const
    {
      return val;
    }
    
    /*!
      \brief Reads a point from a stream as a size followed by a series of objects.
      
      \throw In case the size cannot be read properly, uses g24_lib::exceptions::throw_exception
              to possibly throw a g24_lib::exceptions::array_length_misread.
      
      \deprecated Old way of reading the contents of the `point`,
                  provided for backwards compatibility reasons.
                    Please use `textual_input` for proper serialization.
    */
    void raw_read(std::istream &s)
    {
      indexer a, i;
      s >> a;
      if (s.fail())
        {
          exceptions::throw_exception(exceptions::array_length_misread("Unable to read the length of the point."));
        }
      a = 0;
      point<Type, indexer> ret(a);
      for (i = 0; i < a; ++i)
        {
          s >> ret.val[i];
        }
      (*this) = ret;
    }
    
    /*!
      \brief Reads a point from a stream as a series of objects with a known size.
            
      \deprecated Old way of reading the contents of the `point`,
                  provided for backwards compatibility reasons.
                    Please use `textual_input` for proper serialization.
    */
    void raw_read(std::istream &s, const indexer num)
    {
      indexer i;
      point<Type, indexer> ret(num);
      for (i = 0; i < num; ++i)
        {
          s >> ret.val[i];
        }
      (*this) = ret;
    }
    
    /*!
      \brief Returns a `point` with the same elements, but in reverse order.
      
      \param actually_do If false, simply return a copy of the `fspoint`.
            (Provided for situations in which we may want to reverse or not depending on a condition).
    */
    inline point<Type, indexer> reverse(const bool actually_do = true) const
    {
      if(!actually_do)
        {
          return (*this);
        }
      point<Type, indexer> ret(Size);
      for (indexer i = 0; i < Size; ++i)
        {
          ret.val[i] = val[Size-i-1];
        }
      return ret;
    }
    

    template<class stream, class str = std::basic_string<typename stream::char_type>>
    void textual_output(stream &s, const str& separator = " ") const
    {
      g24_lib::textual_output(s, Size, separator);
      s << separator;
      for (indexer i = 0; i < Size; ++i)
        {
          g24_lib::textual_output(s, val[i], separator);
          s << separator;
        }
    }
      
    template<class stream>
    void textual_input(stream &s)
    {
      indexer new_size;
      g24_lib::textual_input(s, new_size);
      if(s.fail())
        {
          exceptions::throw_exception(exceptions::array_length_misread(""));
        }
      point temp(new_size);
      for (indexer i = 0; i < temp.size(); ++i)
        {
          g24_lib::textual_input(s, temp.val[i]);
        }
      (*this) = temp;
    }
      
    template<class stream>
    void binary_output(stream &s) const
    {
      g24_lib::binary_output(s, Size);
      for (indexer i = 0; i < Size; ++i)
        {
          g24_lib::binary_output(s, val[i]);
        }
    }
      
    template<class stream>
    void binary_input(stream &s)
    {
      indexer new_size;
      g24_lib::binary_input(s, new_size);
      if(s.fail())
        {
          exceptions::throw_exception(exceptions::array_length_misread(""));
        }
      point temp(new_size);
      for (indexer i = 0; i < temp.size(); ++i)
        {
          g24_lib::binary_input(s, temp.val[i]);
        }
      (*this) = temp;
    }    
    
  };
  
  /*!
    \brief Creates a new `point` read from a stream.
    
    \warning Serialization should be handled by textual_input and textual_output.
             This might still be useful for prompting the user,
             since it accepts the same formats as `g24_lib::point<Type, indexer, Size>::operator>>`.

\deprecated `g24_lib::point` is more or less deprecated since its usefulness is limited.
            In most practical problems, the dimensions are fixed,
            dynamic allocations are slower and \c CUDA interoperatability
            is quite limited. However, compatibility with past projects
            requires it to remain here for the time being, at least.
    
    \throw In case the size cannot be read properly, uses g24_lib::exceptions::throw_exception
            to possibly throw a g24_lib::exceptions::array_length_misread.
  */
  template <class Type, class indexer = g24_lib::Definitions::default_unsigned_indexer> point<Type, indexer> raw_read_point (std::istream &s)
  {
    indexer a, i;
    s >> a;
    if (s.fail())
      {
        exceptions::throw_exception(exceptions::array_length_misread("Unable to read the length of the point."));
      }
    a = 0;
    point<Type, indexer> ret(a);
    for (i = 0; i < a; ++i)
      {
        s >> ret[i];
      }
    return ret;
  }
  
  /*!
    \brief Creates a new `point` read from a stream with a known number of elements.
    
    \warning Serialization should be handled by textual_input and textual_output.
             This might still be useful for prompting the user,
             since it accepts the same formats as `g24_lib::point<Type, indexer, Size>::operator>>`.

\deprecated `g24_lib::point` is more or less deprecated since its usefulness is limited.
            In most practical problems, the dimensions are fixed,
            dynamic allocations are slower and \c CUDA interoperatability
            is quite limited. However, compatibility with past projects
            requires it to remain here for the time being, at least.
    
  */
  template <class Type, class indexer = g24_lib::Definitions::default_unsigned_indexer> point<Type, indexer> raw_read_point (std::istream &s, const indexer num)
  {
    indexer i;
    point<Type, indexer> ret(num);
    for (i = 0; i < num; ++i)
      {
        s >> ret[i];
      }
    return ret;
  }
}


/*!
\brief Calculates the norm of a vector using `fabs` for its elements.

\param num The kind of norm we want to calculate. Usual norm has \p `num == 2`,
       but it is mathematically valid as long as `num >= 1`.

\deprecated `g24_lib::point` is more or less deprecated since its usefulness is limited.
            In most practical problems, the dimensions are fixed,
            dynamic allocations are slower and \c CUDA interoperatability
            is quite limited. However, compatibility with past projects
            requires it to remain here for the time being, at least.
       
*/
template <class Type, class indexer = g24_lib::Definitions::default_unsigned_indexer> double fabs(const g24_lib::point <Type, indexer> &p, const double num = 2.0)
{
  indexer i;
  double ret = 0.0;
  if (std::isinf(num))
    {
      for (i = 0; i < p.size(); ++i)
        {
          ret = std::max(ret,fabs(p[i]));
        }
      return ret;
    }
  for (i = 0; i < p.size(); ++i)
    {
      ret += pow(fabs(p[i]), num);
    }
  return pow(ret, 1.0/num);
}

/*!
\brief Calculates the norm of a vector using `fabsf` for its elements.

\param num The kind of norm we want to calculate. Usual norm has \p `num == 2`,
       but it is mathematically valid as long as `num >= 1`.

\deprecated `g24_lib::point` is more or less deprecated since its usefulness is limited.
            In most practical problems, the dimensions are fixed,
            dynamic allocations are slower and \c CUDA interoperatability
            is quite limited. However, compatibility with past projects
            requires it to remain here for the time being, at least.
       
*/
template <class Type, class indexer = g24_lib::Definitions::default_unsigned_indexer> float fabsf(const g24_lib::point <Type, indexer> &p, const float num = 2.0)
{
  indexer i;
  float ret = 0.0;
  if(num < 1.0f)
    {
      exceptions::throw_exception(exceptions::undefined_operation("Invalid norm!"));
    }
  if (std::isinf(num))
    {
      for (i = 0; i < p.size(); ++i)
        {
          ret = std::max(ret,fabs(p[i]));
        }
      return ret;
    }
  for (i = 0; i < p.size(); ++i)
    {
      ret += powf(fabsf(p[i]), num);
    }
  return powf(ret, 1.0f/num);
}


/*!
\brief Returns a `point` whose elements are the `floor` of those of the input `point`.

\deprecated `g24_lib::point` is more or less deprecated since its usefulness is limited.
            In most practical problems, the dimensions are fixed,
            dynamic allocations are slower and \c CUDA interoperatability
            is quite limited. However, compatibility with past projects
            requires it to remain here for the time being, at least.
*/
template <class Type, class indexer>
g24_lib::point<Type, indexer> floor(const g24_lib::point<Type, indexer> &p)
{
  using namespace std;
  //So CUDA doesn't complain...
  g24_lib::point<Type, indexer> ret(p.size());
  for (indexer i = 0; i < p.size(); ++i)
    {
      ret[i] = floor(p[i]);
    }
  return ret;
}

/*!
\brief Returns a `point` whose elements are the `floorf` of those of the input `point`.

\deprecated `g24_lib::point` is more or less deprecated since its usefulness is limited.
            In most practical problems, the dimensions are fixed,
            dynamic allocations are slower and \c CUDA interoperatability
            is quite limited. However, compatibility with past projects
            requires it to remain here for the time being, at least.
*/
template <class Type, class indexer>
g24_lib::point<Type, indexer> floorf(const g24_lib::point<Type, indexer> &p)
{
  using namespace std;
  //So CUDA doesn't complain...
  g24_lib::point<Type, indexer> ret(p.size());
  for (indexer i = 0; i < p.size(); ++i)
    {
      ret[i] = floorf(p[i]);
    }
  return ret;
}

/*!
\brief Returns a `point` whose elements are the `ceil` of those of the input `point`.

\deprecated `g24_lib::point` is more or less deprecated since its usefulness is limited.
            In most practical problems, the dimensions are fixed,
            dynamic allocations are slower and \c CUDA interoperatability
            is quite limited. However, compatibility with past projects
            requires it to remain here for the time being, at least.
*/
template <class Type, class indexer>
g24_lib::point<Type, indexer> ceil(const g24_lib::point<Type, indexer> &p)
{
  using namespace std;
  //So CUDA doesn't complain...
  g24_lib::point<Type, indexer> ret(p.size());
  for (indexer i = 0; i < p.size(); ++i)
    {
      ret[i] = ceil(p[i]);
    }
  return ret;
}

/*!
\brief Returns a `point` whose elements are the `ceilf` of those of the input `point`.

\deprecated `g24_lib::point` is more or less deprecated since its usefulness is limited.
            In most practical problems, the dimensions are fixed,
            dynamic allocations are slower and \c CUDA interoperatability
            is quite limited. However, compatibility with past projects
            requires it to remain here for the time being, at least.
*/
template <class Type, class indexer>
g24_lib::point<Type, indexer> ceilf(const g24_lib::point<Type, indexer> &p)
{
  using namespace std;
  //So CUDA doesn't complain...
  g24_lib::point<Type, indexer> ret(p.size());
  for (indexer i = 0; i < p.size(); ++i)
    {
      ret[i] = ceilf(p[i]);
    }
  return ret;
}

/*!
\brief Returns a `point` whose elements are the `trunc` of those of the input `point`.

\deprecated `g24_lib::point` is more or less deprecated since its usefulness is limited.
            In most practical problems, the dimensions are fixed,
            dynamic allocations are slower and \c CUDA interoperatability
            is quite limited. However, compatibility with past projects
            requires it to remain here for the time being, at least.
*/
template <class Type, class indexer>
g24_lib::point<Type, indexer> trunc(const g24_lib::point<Type, indexer> &p)
{
  using namespace std;
  //So CUDA doesn't complain...
  g24_lib::point<Type, indexer> ret(p.size());
  for (indexer i = 0; i < p.size(); ++i)
    {
      ret[i] = trunc(p[i]);
    }
  return ret;
}

/*!
\brief Returns a `point` whose elements are the `trunc` of those of the input `point`.

\deprecated `g24_lib::point` is more or less deprecated since its usefulness is limited.
            In most practical problems, the dimensions are fixed,
            dynamic allocations are slower and \c CUDA interoperatability
            is quite limited. However, compatibility with past projects
            requires it to remain here for the time being, at least.
*/
template <class Type, class indexer>
g24_lib::point<Type, indexer> truncf(const g24_lib::point<Type, indexer> &p)
{
  using namespace std;
  //So CUDA doesn't complain...
  g24_lib::point<Type, indexer> ret(p.size());
  for (indexer i = 0; i < p.size(); ++i)
    {
      ret[i] = truncf(p[i]);
    }
  return ret;
}

/*!
\brief Returns a `point` whose elements are the `round` of those of the input `point`.

\deprecated `g24_lib::point` is more or less deprecated since its usefulness is limited.
            In most practical problems, the dimensions are fixed,
            dynamic allocations are slower and \c CUDA interoperatability
            is quite limited. However, compatibility with past projects
            requires it to remain here for the time being, at least.
*/
template <class Type, class indexer>
g24_lib::point<Type, indexer> round(const g24_lib::point<Type, indexer> &p)
{
  using namespace std;
  //So CUDA doesn't complain...
  g24_lib::point<Type, indexer> ret(p.size());
  for (indexer i = 0; i < p.size(); ++i)
    {
      ret[i] = round(p[i]);
    }
  return ret;
}

/*!
\brief Returns a `point` whose elements are the `roundf` of those of the input `point`.

\deprecated `g24_lib::point` is more or less deprecated since its usefulness is limited.
            In most practical problems, the dimensions are fixed,
            dynamic allocations are slower and \c CUDA interoperatability
            is quite limited. However, compatibility with past projects
            requires it to remain here for the time being, at least.
*/
template <class Type, class indexer>
g24_lib::point<Type, indexer> roundf(const g24_lib::point<Type, indexer> &p)
{
  using namespace std;
  //So CUDA doesn't complain...
  g24_lib::point<Type, indexer> ret(p.size());
  for (indexer i = 0; i < p.size(); ++i)
    {
      ret[i] = roundf(p[i]);
    }
  return ret;
}

#endif

#ifndef G24_LIB_GENERAL_HELPERS
#define G24_LIB_GENERAL_HELPERS

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

\file general_helpers.h

\brief Functions and definitions that are central to the functioning of the library,
       and some others that may prove quite useful.

\author Nuno Fernandes (main coder, current maintainer)

\author Gonçalo Vaz (past auxiliary coder and tester)

*/

namespace g24_lib
{
  /*!
    \brief An object of type \p T holding the value of pi. Precision assured up to 512 decimal places,
           assuming the type supports it, otherwise rounded to the appropriate precision...
    
    \tparam T The type.
    
    \details The 512 decimal places of pi were taken from https://www.piday.org/million/ .
    
    \pre \p T must be constructible from a long double.
            (Will update for larger precision if future standards include it.)
  */
  template <class T>
  inline static constexpr T pi = T{3.1415926535897932384626433832795028841971693993751058209749445923078164\
06286208998628034825342117067982148086513282306647093844609550582231725359408128481117450284102701938521105\
55964462294895493038196442881097566593344612847564823378678316527120190914564856692346034861045432664821339\
36072602491412737245870066063155881748815209209628292540917153643678925903600113305305488204665213841469519\
415116094330572703657595919530921861173819326117931051185480744623799627495673518857527248912279381830119491298336733624L};
 

  /*!
    \brief Expectably efficient implementation of exponentiation by integers.
    
    \pre \p exp_T must be an integer type with bitwise operations.
    
    \pre \p exp must be non-negative.
  */
  
  template <class base_T, class exp_T = g24_lib::Definitions::default_unsigned_indexer>
  CUDA_HOS_DEV constexpr base_T fastpow(const base_T &base, exp_T exp)
  {
    base_T r{1}, v{base};
    while (exp)
      {
        if (exp & 1)
          {
            r = r*v;
          }
        v = (v*v);
        exp = (exp >> 1);
      }
    return r;
  }
   
  /*!
    \brief Gives the minimum power of 2 larger than or equal to the input.
       
    \pre \p intg must be an integer type with bitwise operations.
    
    \details Heavily inspired by https://graphics.stanford.edu/~seander/bithacks.html#RoundUpPowerOf2 .
    
  */
  template <class intg>
  CUDA_HOS_DEV inline constexpr intg min_power_2 (const intg val)
  //
  //It's the minimum power of 2 that is larger than or equal to val,
  //so, for example, it gives 32 for any number between 17 and 32.
  {
    intg res = val;
    res--;
    for (intg i = 1; i < sizeof(intg) * CHAR_BIT; i *= 2)
      {
        res |= res >> i;
      }
    res++;
    return res;
  }
     
  /*!
    \brief Branchlessly gives the sign of something with comparison operators.
    
    \pre \p Type must have `operator <`.
    
    \pre \p Ret must have the signedness of \p Type (if Type is unsigned, 
         Ret can also be unsigned since the function will only yield non-negative results as well).
    
  */
  template <class Type, class Ret = Type> CUDA_HOS_DEV inline constexpr Ret sign(Type num)
  {
    return (Ret) ((((Type) 0) < num) - (num < ((Type) 0)));
  }
  
  /*!
    \brief Branchlessly clamps something to \f$\left ]-1,1\right]\f$.
    
    \pre \p Type must have `operator *` with `double`.
    
    \deprecated This is included only for compatibility with \ref comp, which is itself deprecated.
                The function does not conform to the same standard of generality and performance 
                as the rest of the library.
    
  */
  template <class Type> CUDA_HOS_DEV inline Type stand(const Type &x)
  {
    return (Type) x + 2.0*std::floor(0.5-0.5*x);
  }
  
  /*!
    \brief A mock array with default-constructed elements of type \p Type.
    
    \pre \p indexer must be a valid choice for \ref g24_lib::Definitions::default_unsigned_indexer.
    
  */
  template <class Type, class indexer = g24_lib::Definitions::default_unsigned_indexer> struct empty_array
  {
  private:
    indexer Size;
  public:
    using value_type = Type;
    using indexer_type = indexer;
    CUDA_HOS_DEV empty_array(const indexer sz = 0): Size(sz)
    {
    }
    CUDA_HOS_DEV indexer size() const
    {
      return Size;
    }
    inline void resize(const indexer new_size)
    {
      Size = new_size;
    }
    CUDA_HOS_DEV inline Type operator[] (const indexer i) const
    {
      return Type{};
    }
  };
  
  
  /*!
    \brief A mock array with a fixed return value.
    
    \pre \p indexer must be a valid choice for \ref g24_lib::Definitions::default_unsigned_indexer.
    
    \remark This comes in rather handy when one wants to operate on arrays with a constant, known value 
            (such as 0) without actually allocating memory for them.
  */
  template <class Type, class indexer = g24_lib::Definitions::default_unsigned_indexer> struct fixed_return_array
  {
  private:
    Type ret; 
    indexer Size;
  public:
    using value_type = Type;
    using indexer_type = indexer;
    CUDA_HOS_DEV fixed_return_array(): ret(0), Size(std::numeric_limits<indexer>::max())
    {
    }
    CUDA_HOS_DEV fixed_return_array(const Type &val): ret(val), Size(std::numeric_limits<indexer>::max())
    {
    }
    CUDA_HOS_DEV fixed_return_array(const indexer sz, const Type &val): ret(val), Size(sz)
    {
    }
    CUDA_HOS_DEV inline void set_value(const Type &val)
    {
      ret = val;
    }
    inline void resize(const indexer new_size)
    {
      Size = new_size;
    }
    CUDA_HOS_DEV inline indexer size() const
    {
      return Size;
    }
    CUDA_HOS_DEV inline Type operator[] (const indexer i) const
    {
      return ret;
    }
  };
  
  /*!
    \brief A mock array with its return value being calculated at each point.
    
    \tparam Op Function, functor, lambda or any other object that will yield the
             desired return value when operated with an indexer: `op(i)`
    
    \pre \p indexer must be a valid choice for \ref g24_lib::Definitions::default_unsigned_indexer.
    
    \remark This comes in rather handy when one wants to operate on arrays
            whose elements can be easily calculated
            without actually allocating memory for them.
            
    \remark For most practical use cases, functors or lambdas will be preferred for \p Op, 
            since some form of state or external parameters might be required
            to properly calculate the elements at each index.
  */
  template <class Op, class indexer = g24_lib::Definitions::default_unsigned_indexer> struct operation_array
  {
  private:
    Op op;
    indexer Size;
  public:
    using value_type = decltype(std::declval<Op>()(std::declval<indexer>()));
    using indexer_type = indexer;
    CUDA_HOS_DEV operation_array(const indexer sz, Op operation): op(operation), Size(sz)
    {
    }
    CUDA_HOS_DEV inline auto operator[] (const indexer i) const
    {
      return op(i);
    }
    inline void resize(const indexer new_size)
    {
      Size = new_size;
    }
    CUDA_HOS_DEV inline indexer size() const
    {
      return Size;
    }
  };
  
  
  /*!
    \brief A class with the amazing ability to convert to any type.
    
    \details Adapted from playfulprogramming.
  */
  struct wildcard
  //This will convert to any type...
  {
    template <class T,
              typename = std::enable_if_t<!std::is_lvalue_reference<T>::value>>
    operator T&&() const;

    template <class T,
              typename = std::enable_if_t<std::is_copy_constructible<T>::value>>
    operator T&() const;
  };
  
///\cond HIDDEN_SYMBOLS
  namespace internals
  {
  
    template <class C, class res, bool needs_checking = std::is_void_v<res>> struct access_checker;
    
    template <class C, class res> struct access_checker<C, res, false>
    {
      template <class T>
      using type = res;
    };
    
    template <class C, class res> struct access_checker<C, res, true>
    {
      template<class indexer, class T >
      static constexpr auto check(T*) -> std::decay_t< 
                                                                 decltype(
                                                                          std::declval<T>()[std::declval<indexer>()]
                                                                         )
                                                              >;

      template<class, class>
      static constexpr void check(...);
      
      template <class T>
      using type = decltype(check<T, C>(nullptr));
    };
    
    template <class C> struct container_checks
    {
      G24_LIB_TYPEDEF_CHECKER(indexer_type, void);
      
      G24_LIB_TYPEDEF_CHECKER(size_type, void);
      
      template<class T>
      static constexpr auto size_checker(T*) -> decltype(std::declval<T>().size());

      template<class>
      static constexpr void size_checker(...);
      
      template <class T>
      using ind_t_1 = indexer_type_t_type<T>;
      template <class T>
      using ind_t_2 = size_type_t_type<T>;
      template <class T>
      using ind_t_3 = decltype(size_checker<T>(nullptr));
      template <class T>
      using ind_t_final = std::conditional_t< 
                                              !std::is_void_v<ind_t_1<T>>,
                                              ind_t_1<T>, 
                                              std::conditional_t< 
                                                                  !std::is_void_v<ind_t_2<T>>,
                                                                  ind_t_2<T>,
                                                                  ind_t_3<T>
                                                                >
                                            >;
                                            
      using indexer = ind_t_final<C>;
      
      
      G24_LIB_TYPEDEF_CHECKER(value_type, void);
      
      using val_t_1 = value_type_t_type<C>;
            
      using value = std::conditional_t< 
                                        !std::is_void_v<val_t_1>,
                                        val_t_1,
                                        std::conditional_t<
                                                            std::is_pointer_v<C>,
                                                            std::remove_pointer_t<C>,
                                                            std::conditional_t<
                                                                                std::is_array_v<C>,
                                                                                std::remove_extent_t<C>,
                                                                                val_t_1
                                                                              >
                                                          >
                                      >;
    };
  }
  
///\endcond

/*!
\brief Yields the indexer type of a container-like class, or void if the class isn't a container.

\details The indexer type is obtained either from a member `typedef` for `indexer_type`,
         a member `typedef` for `size_type` or the return type of a `size()` member function.

\remark When using this, one should try to ensure it is not actually `void`, 
        or else several template instantiation errors might ensue.

*/
  template <class C>
  using indexer_type = typename internals::container_checks<std::decay_t<C>>::indexer;
      
/*!
\brief Yields the value type of a container-like class, or void if the class isn't a container.

\details The value type is obtained either from a member `typedef` for `value_type`
         or the return type of `operator []` (after removing references).

\remark When using this, one should try to ensure it is not actually `void`, 
        or else several template instantiation errors might ensue.

*/
  template <class C>
  using value_type = typename internals::container_checks<std::decay_t<C>>::value;
  
/*!
\brief Checks if \p C is a valid container for the purposes of this library.

\details A valid container will have both non-void `g24_lib::indexer_type` and `g24_lib::value_type`.

\sa `g24_lib::indexer_type`, `g24_lib::value_type`.

*/
  template <class C>
  inline constexpr bool is_container = !(std::is_void_v<indexer_type<C>> || std::is_void_v<value_type<C>>);
  
  /*!
    \brief A container padded with a fixed value after a specified size.
    
    \tparam Cont The container to be padded.
    
    \tparam by_ref Specifies if the original container is stored by value or by reference. 
                 Most sane use cases should work with references (provided they remain valid
                 throughout the \ref value_padded_array's lifetime), but that is not the case 
                 when one is passing parameters into \c CUDA GPU kernels, 
                 since references become invalid.
    
    \tparam Val The type of the padding value.
        
    \pre `Cont::operator []` must yield something that can be casted to or from a \p Val.
    
    \pre \p indexer must be a valid choice for \ref g24_lib::Definitions::default_unsigned_indexer.
    
    \remark This comes in rather handy when one wants to operate on arrays of different sizes
            and assign a neutral value to elements after the end of the smallest. For instance, 
            when summing two arrays of different sizes, any values after the end of the smallest 
            can be put to zero.
            
  */
  template <class Cont, bool by_ref = true, class Val = g24_lib::value_type<Cont>, class indexer = g24_lib::Definitions::default_unsigned_indexer>
  struct value_padded_array
  {
  private:
    const std::conditional_t<by_ref, Cont&, Cont> container; ///< The container to be padded.
    Val value; ///< The value of the padding.
    indexer extra;
    ///< The number of elements to add after the end of the container (that is, the number of added padding elements).
  public:
    using indexer_type = indexer;
    using value_type = Val;
    CUDA_HOS_DEV value_padded_array(const Cont &C, const indexer extra_size = 1, const Val V = Val(0)):
    container(C),
    value(V),
    extra(extra_size)
    {
    }
    CUDA_HOS_DEV inline auto operator[] (const indexer i) const
    {
      if (i >= container.size())
        {
          return value;
        }
      else
        {
          return container[i];
        }
    }
    /*!
    \param desired_size The desired final size of the padded array. In essence,
           the size of the padding will be `max(desired_size - container.size(), 0)`.
    */
    inline void resize(const indexer desired_size)
    {
      if (desired_size > container.size())
        {
          extra = desired_size - container.size()
        }
      else
        {
          extra = 0;
        }
      //We cannot resize this to be smaller than the underlying array...
    }
    CUDA_HOS_DEV inline indexer size() const
    {
      return container.size() + extra;
    }
  };
  
  /*!
  \brief This represents a generic, dummy function, 
         mainly for template parameters that need a function 
         when we don't quite have one.
  */
  struct dummy_function
  {
  /*!
  \brief This `operator()` is a no-op.
  
  \tparam ret The desired return type.
  
  \tparam X A first argument.
  
  \tparam Everything The rest of the arguments.
  
  \return A default object of type \p ret.
  
  */
    template <class ret, class X, class ... Everything>
    ret operator() (const X& x, const Everything& ... dummy) const
    {
      return ret{};
    }
  };
  
  /*!
  \brief This represents a generic, dummy void function, 
         mainly for template parameters that need a function 
         when we don't quite have one.
  */
  struct dummy_void_function
  {
  /*!
  \brief This `operator()` is a no-op.
    
  \tparam X A first argument.
  
  \tparam Everything The rest of the arguments.
  
  */
    template <class X, class ... Everything>
    void operator() (const X& x, const Everything& ... dummy) const
    {
      return;
    }
  };
  
  /*!
    \brief A functor that acts as an identity function.
  */
  struct identity_functor
  {
    /*!
      \brief Returns the first argument and ignores the rest.
    */
    template <class X, class ... Args>
    CUDA_HOS_DEV inline auto operator() (X&& x, Args&& ... args) const
    {
      return x;
    }
  };
  /*!
    \brief A functor that acts as an `operator[]`.
  */
  struct return_ith_functor
  {
    /*!
      \brief Returns `x[i]` and ignores the remaining arguments.
    */
    template <class X, class indexer, class ... Args>
    CUDA_HOS_DEV inline auto operator() (X&& x, indexer &&i, Args&& ... args) const
    {
      return x[i];
    }
  };
  
  /*!
    \brief A functor that sets each element to a provided value.
  */
  struct set_ith_functor
  {
    /*!
      \brief Sets `x[i] = val` and ignores the remaining arguments.
    */
    template <class X, class indexer, class first, class ... Args>
    CUDA_HOS_DEV inline void operator() (X &&x, indexer &&i, first && val, Args && ... args) const
    {
      x[i] = val;
    }
  };
  
}
#endif

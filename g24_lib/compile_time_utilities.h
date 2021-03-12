#ifndef G24_LIB_COMPILE_TIME_REFLECTION
#define G24_LIB_COMPILE_TIME_REFLECTION

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

\file compile_time_utilities.h

\brief Several compile time utilities, the most relevant of which
       is a limited form of compile time reflection for structs.

\author Nuno Fernandes (main coder, current maintainer)

*/

//It must be stated with the utmost clarity
//that current C++ was not developed
//with such functionality in mind,
//in fact, one behaviour that is fundamental
//for this to work is likely a 'bug'
//that will be solved in future revisions;
//however, there is hope that a more native
//implementation of compile time reflection
//will find its way to the standard,
//so most of the code here might become obsolete
//one of these days.

//In any case, for this to work properly,
//all the members of the struct/class
//that we want to keep must be definable
//through a constructor (or brace-initialization,
//that may call a constructor with the appropriate
//number of arguments nonetheless).
//Furthermore, if the imitation structs
//are to be supported, the struct/class
//MUST ONLY HAVE THESE MEMBERS ACCESSIBLE TO STRUCTURED BINDINGS.
//If not, compile errors may abound and... well... it's the programmer's fault.

//All of this was inspired by the Magic Get library,
//along with with some hints and code from:
//
//http://apolukhin.github.io/magic_get/boost_precise_and_flat_reflectio/how_it_works.html
//(By Antony Polukhin)
//
//https://playfulprogramming.blogspot.com/2016/12/serializing-structs-with-c17-structured.html
//(By Bjoern Fahller)
//
//http://alexpolt.github.io/type-loophole.html
//(By Alexandr Poltavsky)
//
//Credit, awe and astonishment go mainly to Antony Polukhin,
//author of the aforementioned Magic Get library,
//and Alexandr Poltavsky, who discovered the loophole
//that allows "leakage" of template metaprogramming state.


namespace g24_lib
{
  
  namespace internals
  {
    ///\cond HIDDEN_SYMBOLS
    template <g24_lib::Definitions::default_unsigned_indexer N = 0>
    static constexpr const wildcard WildCards_{};

    template <class T, g24_lib::Definitions::default_unsigned_indexer... I>
    constexpr auto is_brace_constructible_(std::integer_sequence<g24_lib::Definitions::default_unsigned_indexer, I...>, T*)
      -> decltype(T{WildCards_<I>...}, std::true_type{}) {
      return {};
    }

    template <g24_lib::Definitions::default_unsigned_indexer... I>
    constexpr std::false_type is_brace_constructible_(
                                                      std::integer_sequence<g24_lib::Definitions::default_unsigned_indexer,I...>, ...) {
      return {};
    }
    template <class T, g24_lib::Definitions::default_unsigned_indexer N>
    constexpr auto is_brace_constructible()
      -> decltype(is_brace_constructible_(std::make_integer_sequence<g24_lib::Definitions::default_unsigned_indexer, N>{},
                                          static_cast<T*>(nullptr)))
    {
      return {};
    }

   
    //Adapted from Antony Polukhin
  
    template<class T, g24_lib::Definitions::default_unsigned_indexer begin, g24_lib::Definitions::default_unsigned_indexer end> constexpr g24_lib::Definitions::default_unsigned_indexer get_arity_recurse()
    {
      constexpr g24_lib::Definitions::default_unsigned_indexer now = begin + (end-begin)/2;
      if constexpr((is_brace_constructible<T, now>() && !is_brace_constructible<T, now+1>()) || begin == end)
        {
          return now;
        }
      else if constexpr(is_brace_constructible<T, now+1>())
        {
          return get_arity_recurse<T, now, end>();
        }
      else if constexpr(!is_brace_constructible<T, now>())
        {
          return get_arity_recurse<T, begin, now>();
        }
    }
  
    //The following is adapted from code 
    //written by the user jrok of Stack Exchange
    //(https://stackoverflow.com/a/16824239)

    template<class C> struct has_size
    {
    private:
      template<class T>
      static constexpr auto check(T*) -> typename std::is_scalar<decltype(std::declval<T>().constexpr_size())>;

      template<class>
      static constexpr std::false_type check(...);

      typedef decltype(check<C>(0)) type;

    public:
      static constexpr bool value = type::value;
    };
  
    template<class T> constexpr bool specifies_size()
    {
      return has_size<T>::value;
    }
  
    template<class T> constexpr g24_lib::Definitions::default_unsigned_indexer specified_size()
    {
      return T::size();
    }
 
    template<class T> constexpr g24_lib::Definitions::default_unsigned_indexer maximum_member_number()
    {
      if constexpr (specifies_size<T>())
        {
          return specified_size<T>() + 1;
        }
      else
        {
          return (sizeof(T) * CHAR_BIT);
          //Since a bit field is also a valid entity,
          //there might be as many as CHAR_BIT members
          //for each byte the structure occupies.
          //Since we're aiming for an upper bound anyway,
          //it shouldn't be too bad,
          //even more so since the binary search 
          //grows logarithmically with the number of elements.
        }
    }
 
    
    template<class T> constexpr g24_lib::Definitions::default_unsigned_indexer get_arity()
    {
      if constexpr (specifies_size<T>())
        {
          return specified_size<T>();
        }
      else
        {
          constexpr g24_lib::Definitions::default_unsigned_indexer arity = get_arity_recurse<T, 0, maximum_member_number<T>()>();
          return arity;
        }
    
    }
    
    //Adapted from Alexandr Poltavsky
  
    template<g24_lib::Definitions::default_unsigned_indexer N, class origin_type> struct tag
    {
      friend constexpr auto loophole (tag<N, origin_type>);
    };

    template<g24_lib::Definitions::default_unsigned_indexer N, class origin_type> tag<N, origin_type> global_tags;
    
    template<class T, g24_lib::Definitions::default_unsigned_indexer N, class origin_type>
    struct loophole_t 
    {
      friend constexpr auto loophole (tag<N, origin_type>)
      { 
        return T{};
      }
    };
    
    template <g24_lib::Definitions::default_unsigned_indexer I, class origin_type> struct builder_wildcard
    {
    
      template <class T,
                typename = std::enable_if_t<!std::is_lvalue_reference<T>::value>,
                g24_lib::Definitions::default_unsigned_indexer ignore = sizeof(loophole_t<T, I, origin_type>)>
      operator T&&() const
      {
      }

      template <class T,
                typename = std::enable_if_t<std::is_copy_constructible<T>::value>,
                g24_lib::Definitions::default_unsigned_indexer ignore = sizeof(loophole_t<T, I, origin_type>)>
      operator T&() const
      {
      }
    };
    template <class T, g24_lib::Definitions::default_unsigned_indexer... I>
    constexpr auto build_stuff(std::integer_sequence<g24_lib::Definitions::default_unsigned_indexer,I...>, T*)
      -> decltype(T{builder_wildcard<I+1, T>{}...}, std::true_type{})
    {
      return {};
    }
  
    template <class T, g24_lib::Definitions::default_unsigned_indexer N>
    constexpr auto build_type_info_actual()
      -> decltype(build_stuff(std::make_integer_sequence<g24_lib::Definitions::default_unsigned_indexer,N>{}, static_cast<T*>(nullptr)))
    {
      return {};
    }

    template <class Type, class origin_type, g24_lib::Definitions::default_unsigned_indexer num,
              g24_lib::Definitions::default_unsigned_indexer ignore = sizeof(loophole_t<Type, num, origin_type>)>
    constexpr g24_lib::Definitions::default_unsigned_indexer manual_type_implementer()
    {
      if constexpr (num == 0)
        {
          return 0;
        }
      else
        {
          return manual_type_implementer<Type, origin_type, num-1>();
        }
    }

    template <class T, g24_lib::Definitions::default_unsigned_indexer N = get_arity<T>()> constexpr auto build_type_info()
    {
      if constexpr (specifies_size<T>())
        {
          [[maybe_unused]] constexpr auto ignore = manual_type_implementer<typename T::value_type, T, get_arity<T>()>();
          return std::true_type{};
        }
      else
        {
          return build_type_info_actual<T, N>();
        }
    }

    template <class origin_type, g24_lib::Definitions::default_unsigned_indexer N, class T = decltype(loophole(tag<N, origin_type>{}))> struct type_getter
    {
      typedef T type;
    };
  
    template<class T> constexpr g24_lib::Definitions::default_unsigned_indexer get_true_arity();
  
    template<class T, g24_lib::Definitions::default_unsigned_indexer index> constexpr g24_lib::Definitions::default_unsigned_indexer get_true_arity_recurse()
    {
      if constexpr(index == 0)
        {
          return 0;
        }
      else if constexpr ( std::is_scalar_v<typename type_getter<T, index>::type> )
        {
          return get_arity<typename type_getter<T, index>::type>() + get_true_arity_recurse<T, index-1>();
        }
      else
        {
          return get_true_arity<typename type_getter<T, index>::type>() + get_true_arity_recurse<T, index-1>();
        }
    }
  
    template<class T> constexpr g24_lib::Definitions::default_unsigned_indexer get_true_arity()
    {
      constexpr g24_lib::Definitions::default_unsigned_indexer arity = get_arity<T>();
      if constexpr (std::is_scalar_v<T>)
        {
          [[maybe_unused]] constexpr auto ignore = sizeof(loophole_t<T, 1, T>);
          return arity;
        }
      else if constexpr (specifies_size<T>())
        {
          [[maybe_unused]] constexpr auto ignore = build_type_info<T, arity>();
          return arity * get_true_arity<typename type_getter<T, 1>::type>();
        }
      else
        {
          [[maybe_unused]] constexpr auto ignore = build_type_info<T, arity>();
          return get_true_arity_recurse<T, arity>();
        }
    }
  
    template<g24_lib::Definitions::default_unsigned_indexer N, class origin_type> struct true_tag
    {
      friend constexpr auto true_loophole (true_tag<N, origin_type>);
    };

    template<g24_lib::Definitions::default_unsigned_indexer N, class origin_type> true_tag<N, origin_type> global_true_tags;
    
    template<class T, g24_lib::Definitions::default_unsigned_indexer N, class origin_type>
    struct true_loophole_t 
    {
      friend constexpr auto true_loophole (true_tag<N, origin_type>)
      { 
        return T{};
      }
    };
  
    template<class T, class origin_type = T, g24_lib::Definitions::default_unsigned_indexer offset = 0> constexpr bool de_nest();
  
    template<class T, class origin_type, g24_lib::Definitions::default_unsigned_indexer offset, g24_lib::Definitions::default_unsigned_indexer current, g24_lib::Definitions::default_unsigned_indexer arity> constexpr bool de_nest_iter()
    {
      if constexpr (current <= arity)
        {
          [[maybe_unused]] constexpr auto ignore_it = de_nest<typename type_getter<T, current>::type, origin_type, offset>();
          constexpr auto ignore_it_too = de_nest_iter< T, origin_type,
                                                       offset + get_true_arity<typename type_getter<T, current>::type>(), 
                                                       current+1, arity >();
          return ignore_it_too;
        }
      else
        {
          return true;
        }
    }
  
    template<class T, class origin_type, g24_lib::Definitions::default_unsigned_indexer offset> constexpr bool de_nest()
    {
      if constexpr (std::is_scalar_v<T>)
        {
          [[maybe_unused]] constexpr auto ignore = sizeof(true_loophole_t<T, offset + 1, origin_type>);
          return false;
        }
      else
        {
          constexpr g24_lib::Definitions::default_unsigned_indexer arity = get_arity<T>();
          [[maybe_unused]] constexpr auto ignore_it = build_type_info<T, arity>();
          [[maybe_unused]] constexpr auto ignore_it_too = de_nest_iter<T, origin_type, offset, 1, arity>();
          return true;
        }
    
    
    }
  
    template <class origin_type, g24_lib::Definitions::default_unsigned_indexer N, bool dummy = de_nest<origin_type>(), class T = decltype(true_loophole(true_tag<N, origin_type>{}))> struct true_type_getter
    {
      typedef T type;
    };
  
    ///\endcond
  
    /*!
      \brief Represents an integer type with a specific number of bytes.
      
      \tparam size The number of bytes of the integer type.
      
      \tparam with_sign The signedness of the type.
      
      \warning This is implemented through template specializations
               that will alias types like `int8_t` and the like. 
               Not all combinations of \p size and \p with_sign 
               will be supported and portability will depend on 
               the availability of the aliased types in the platforms in question.
    */
    template <g24_lib::Definitions::default_unsigned_indexer size, bool with_sign = true> struct any_sized_int
    {
      ///\brief The actual integer type. Will be `void` if the combination of `size` and `with_sign` is invalid.
      ///
      using type = void;
    };
  
    ///\cond HIDDEN_SYMBOLS
    template<> struct any_sized_int<1, true>
    {
      using type = int8_t;
    };
  
    template<> struct any_sized_int<2, true>
    {
      using type = int16_t;
    };
  
    template<> struct any_sized_int<4, true>
    {
      using type = int32_t;
    };
  
    template<> struct any_sized_int<8, true>
    {
      using type = int64_t;
    };

    template<> struct any_sized_int<1, false>
    {
      using type = uint8_t;
    };
  
    template<> struct any_sized_int<2, false>
    {
      using type = uint16_t;
    };
  
    template<> struct any_sized_int<4, false>
    {
      using type = uint32_t;
    };
  
    template<> struct any_sized_int<8, false>
    {
      using type = uint64_t;
    };
    ///\endcond
  }
  /*!
    \brief Provides a limited form of compile time reflection.
    
    \tparam T The class one wants to reflect.
    
    
    \warning Current C++ was not designed with this kind of functionality in mind,
             and the implementation actually relies on what can be essentially called a bug,
             or at the very least a loophole, in the current standard
             that allows for a limited form of stateful template metaprogramming.
             It is expected that in a future revision of the standard (post C++20)
             this loophole might be fixed, but there are also some proposals toward
             true support for compile time reflection that will essentially deprecate all of this.
    
   \pre The members of \p T are detected essentially through brace-initialization. 
        For POD objects (that is, C-like structs), this gives exactly every member
        in order of declaration. If T has user defined constructors,
        it is the constructor with the highest number of arguments
        that is used to detect the members, so strange results may
        ensue depending on how these constructors are defined.
            
   \details None of this code would be possible without the efforts of Alexandr Poltavsky,
            who discovered the loophole that allows for stateful template metaprogramming
            (see <a href= "http://alexpolt.github.io/type-loophole.html">here</a>), and especially Antony Polukhin,
            author of the <a href = "http://apolukhin.github.io/magic_get/">Magic Get library</a>,
            which implements in a likely more thourough and robust form what was intended here.
            
   \details Some credit is also due to Björn Fahller, author of the *Playful Programming* blog,
            whose <a href ="https://playfulprogramming.blogspot.com/2016/12/serializing-structs-with-c17-structured.html">
            post</a> on automatically generated serialization for structs using strucutred bindings
            pointed the developer of this functionality towards Antony Polukhin's work.
  */
  template <class T, g24_lib::Definitions::default_unsigned_indexer ignore = internals::get_true_arity<T>()> struct class_info
  {
  public:
  
/*!
    
\brief The number of members of the class.

\remark This differs from `#true_arity` because only the members of the class are considered.
        Suppose we have:
~~~{.cpp}
struct example_inner
{
  int a;
  double b;
  char *c;
};

struct example_outer
{
  float first;
  example_inner second, third;
  char fourth;
};
~~~
\remark The value of `g24_lib::class_info<example_outer>::arity` is 4, 
        whereas `g24_lib::class_info<example_outer>::true_arity` would be 8,
        since in the latter case all classes are (recursively) reflected
        until only types that satisfy `std::is_scalar`
        (bools, integers, floating point types, enums or pointers) are considered.
        
\sa #true_arity
*/
    static constexpr g24_lib::Definitions::default_unsigned_indexer arity = internals::get_arity<T>();
    
    
/*!
    
\brief The number of scalar types contained in all the members of the class.

\remark This differs from `#arity` because the members of the class are recursively reflected
        until only types that satisfy `std::is_scalar`
        (bools, integers, floating point types, enums or pointers) are considered.
        Suppose we have:
~~~{.cpp}
struct example_inner
{
  int a;
  double b;
  char *c;
};

struct example_outer
{
  float first;
  example_inner second, third;
  char fourth;
};
~~~
\remark The value of `g24_lib::class_info<example_outer>::true_arity` is 8, 
        whereas `g24_lib::class_info<example_outer>::arity` would be 4,
        since in the latter case only the members of the class are considered.
        
        
\sa #arity
*/
    static constexpr g24_lib::Definitions::default_unsigned_indexer true_arity = internals::get_true_arity<T>();
    
    
/*!
\brief The types of the members of the class, by order of declaration.

\warning By design, the list of types is 1-indexed. 
         This is arguably inconsistent with the rest of C++,
         and could in fact be easily changed in the code,
         but it seems more natural for the author
         and thus will be kept this way
         unless a more compelling reason presents itself.

\remark Take
~~~{.cpp}
struct example_inner
{
  int a;
  double b;
  char *c;
};

struct example_outer
{
  float first;
  example_inner second, third;
  char fourth;
};
~~~
\remark `g24_lib::class_info<example_outer>::type<1>` is `float`,

\remark `g24_lib::class_info<example_outer>::type<2>` is `example_inner`,

\remark `g24_lib::class_info<example_outer>::type<3>` is `example_inner`,

\remark `g24_lib::class_info<example_outer>::type<4>` is `char`.

\sa #true_type
*/
    template <g24_lib::Definitions::default_unsigned_indexer i> using type = typename internals::type_getter<T, i>::type;
    
/*!
    
\brief A simple check for the presence of non-scalar members.

\remark This is functionally equivalent to `arity == true_arity`,
        but, for implementation reasons, it is defined through another compile type expression
        to ensure an appropriate list of member types is built.

*/
    static constexpr bool has_nested = internals::de_nest<T>();
    
/*!
    
\brief The scalar types of the class and recursively reflected members, by order of declaration.

\warning By design, the list of types is 1-indexed. 
         This is arguably inconsistent with the rest of C++,
         and could in fact be easily changed in the code,
         but it seems more natural for the author
         and thus will be kept this way
         unless a more compelling reason presents itself.

\remark Take
~~~{.cpp}
struct example_inner
{
  int a;
  double b;
  char *c;
};

struct example_outer
{
  float first;
  example_inner second, third;
  char fourth;
};
~~~
\remark `g24_lib::class_info<example_outer>::type<1>` is `float`,

\remark `g24_lib::class_info<example_outer>::type<2>` is `int`,

\remark `g24_lib::class_info<example_outer>::type<3>` is `double`,

\remark `g24_lib::class_info<example_outer>::type<4>` is `char *`,

\remark `g24_lib::class_info<example_outer>::type<5>` is `int`,

\remark `g24_lib::class_info<example_outer>::type<6>` is `double`,

\remark `g24_lib::class_info<example_outer>::type<7>` is `char *`,

\remark `g24_lib::class_info<example_outer>::type<8>` is `char`.

\sa #type
*/
    template <g24_lib::Definitions::default_unsigned_indexer i> using true_type = typename internals::true_type_getter<T, i>::type;
  };


/*!
\brief Represents a signed integer type with a specific number of bytes.

\tparam size The desired number of bytes.

\details See #g24_lib::internals::any_sized_int for details.
*/
  template <g24_lib::Definitions::default_unsigned_indexer size> using signed_integer = typename internals::any_sized_int<size, true>::type;
  
  
/*!
\brief Represents an unsigned integer type with a specific number of bytes.

\tparam size The desired number of bytes.

\details See #g24_lib::internals::any_sized_int for details.
*/
  template <g24_lib::Definitions::default_unsigned_indexer size> using unsigned_integer = typename internals::any_sized_int<size, false>::type;
  //This was created during a type-unsafe attempt of doing
  //the imitation structs with bit-wise manipulations and such,
  //but that attempt (fortunately) was not successful.
  //This is kept here in hopes of possible future utility...


  ///\cond HIDDEN_SYMBOLS
  template<class T> struct nested_imitation_struct;
  template <class T> struct flat_imitation_struct;
  //Forward-declare what will be implemented afterwards...

  namespace internals
  {
    template <class T, g24_lib::Definitions::default_unsigned_indexer N = get_arity<T>(), bool scalar = std::is_scalar_v<T>> struct nested_imitation_impl;

    template <class T, g24_lib::Definitions::default_unsigned_indexer N = get_true_arity<T>()> struct flat_imitation_impl;

    //These two structures hold (hopefully)
    //all the members of an arbitrary struct
    //in a fully accessible and indexable way.
    //The first is "nested" in the sense of
    //having an imitation struct for every
    //type, while the second has all the contained structs
    //flattened and contains all the types outright.

    template <class T, g24_lib::Definitions::default_unsigned_indexer N> struct variadic_structured_binding
    //This is a prototype for (hard-coded) variadic strucuted bindings.
    //Real values are in variadic_structured_bindings.h
    {
      CUDA_HOS_DEV static auto struct_to_nested(const T& s)
      {
        static_assert(get_arity<T>() <= g24_lib::Definitions::max_variadic_structured_binding_size,
                      "Variadic structured bindings only work up to the number specified by "
                      "g24_lib::Definitions::max_variadic_structured_binding_size.");
      }
    };



    template <class T, g24_lib::Definitions::default_unsigned_indexer N> struct nested_imitation_impl<T, N, false>:
      public  nested_imitation_impl<T, N-1>
    {
      static constexpr g24_lib::Definitions::default_unsigned_indexer number = N;
      typedef typename class_info<T>::template type<number> contained_type;
      nested_imitation_struct<contained_type> elem;
      template <g24_lib::Definitions::default_unsigned_indexer i> CUDA_HOS_DEV auto& get_element()
      {
        if constexpr (i == number)
          {
            return elem;
          }
        else
          {
            return static_cast<nested_imitation_impl<T, N-1>*>(this)->template get_element<i>();
          }
      }
      template <g24_lib::Definitions::default_unsigned_indexer i> CUDA_HOS_DEV const auto& get_element() const
      {
        if constexpr (i == number)
          {
            return elem;
          }
        else
          {
            return static_cast<const nested_imitation_impl<T, N-1>*>(this)->template get_element<i>();
          }
      }
    };

    template <class T> struct nested_imitation_impl<T, 1, false>
    {
      static constexpr g24_lib::Definitions::default_unsigned_indexer number = 1;
      typedef typename class_info<T>::template type<number> contained_type;
      nested_imitation_struct<contained_type> elem;
      template <g24_lib::Definitions::default_unsigned_indexer i> CUDA_HOS_DEV auto& get_element()
      {
        return elem;
      }
  
      template <g24_lib::Definitions::default_unsigned_indexer i> CUDA_HOS_DEV const auto& get_element() const
      {
        return elem;
      }
    };

    template <class T> struct nested_imitation_impl<T, 1, true>
    {
      typedef T contained_type;
      T elem;
      template <g24_lib::Definitions::default_unsigned_indexer i> CUDA_HOS_DEV auto& get_element()
      {
        return elem;
      }
      template <g24_lib::Definitions::default_unsigned_indexer i> CUDA_HOS_DEV const auto& get_element() const
      {
        return elem;
      }
    };


    template <class T, g24_lib::Definitions::default_unsigned_indexer N> struct flat_imitation_impl:
      public flat_imitation_impl<T, N-1>
    {
      static constexpr g24_lib::Definitions::default_unsigned_indexer number = N;
      typedef typename class_info<T>::template true_type<number> contained_type;
      contained_type elem;
      template <g24_lib::Definitions::default_unsigned_indexer i> CUDA_HOS_DEV auto& get_element()
      {
        if constexpr (i == number)
          {
            return elem;
          }
        else
          {
            return static_cast<flat_imitation_impl<T, N-1>*>(this)->template get_element<i>();
          }
      }
  
      template <g24_lib::Definitions::default_unsigned_indexer i> CUDA_HOS_DEV const auto& get_element() const
      {
        if constexpr (i == number)
          {
            return elem;
          }
        else
          {
            return static_cast<const flat_imitation_impl<T, N-1>*>(this)->template get_element<i>();
          }
      }
  
    };

    template <class T> struct flat_imitation_impl<T, 1>
    {
      static constexpr g24_lib::Definitions::default_unsigned_indexer number = 1;
      typedef typename class_info<T>::template true_type<number> contained_type;
      contained_type elem;
      template <g24_lib::Definitions::default_unsigned_indexer i> CUDA_HOS_DEV auto& get_element()
      {
        return elem;
      }
      template <g24_lib::Definitions::default_unsigned_indexer i> CUDA_HOS_DEV const auto& get_element() const
      {
        return elem;
      }
    };


    template <class T1, class T2, g24_lib::Definitions::default_unsigned_indexer flat_num = 1, g24_lib::Definitions::default_unsigned_indexer nest_num = 1>
    CUDA_HOS_DEV void flat_to_nested(nested_imitation_struct<T1> &n, const flat_imitation_struct<T2> &f)
    {
      if constexpr (nest_num > n.number || flat_num > f.number)
        //Both conditions will only be fulfilled simultaneously
        //if everything goes right, but better safe than sorry...
        {
          return;
        }
      else if constexpr (n.scalar)
        {
          n.template get_element<1>() = f.template get_element<flat_num>();
        }
      else
        {
          flat_to_nested<typename type_getter<T1, nest_num>::type, T2, flat_num, 1>(n.template get_element<nest_num>(), f);
          flat_to_nested<T1, T2, flat_num+get_true_arity<typename type_getter<T1, nest_num>::type>(), nest_num+1>(n, f);
        }
    }

    template <class T1, class T2, g24_lib::Definitions::default_unsigned_indexer flat_num = 1, g24_lib::Definitions::default_unsigned_indexer nest_num = 1>
    CUDA_HOS_DEV void nested_to_flat(flat_imitation_struct<T1> &f, const nested_imitation_struct<T2> &n)
    {
      if constexpr (flat_num > f.number || nest_num > n.number)
        //Both conditions will only be fulfilled simultaneously
        //if everything goes right, but better safe than sorry...
        {
          return;
        }
      else if constexpr (n.scalar)
        {
          f.template get_element<flat_num>() = n.template get_element<1>();
        }
      else
        {
          nested_to_flat<T1, typename type_getter<T2, nest_num>::type, flat_num, 1>(f, n.template get_element<nest_num>());
          nested_to_flat<T1, T2, flat_num + get_true_arity<typename type_getter<T2, nest_num>::type>(), nest_num+1>(f, n);
        }
    }

  }
  
  
///\endcond

/*!
  \brief Constructs a struct that has the members of a class based on compile time reflection from `g24_lib::class_info`.
  
  \tparam T The class being *imitated*.
  
  \details If \p T satisfies the conditions for being a scalar
          (if it is a bool, integer, floating point type, enum or pointer),
          then it just holds a variable of the appropriate type.
          Else, each member is held as a `nested_imitation_struct` itself, so it can handle 
          structs of structs.
          
  \details The types are in the same order as `g24_lib::class_info<T>::type`.
          
\remark Take
~~~{.cpp}
struct example_inner
{
  int a;
  double b;
  char *c;
};

struct example_outer
{
  float first;
  example_inner second, third;
  char fourth;
};
~~~

\remark We essentially have something equivalent to:
~~~{.cpp}
struct g24_lib::nested_imitation_struct<example_outer>
{
  g24_lib::nested_imitation_struct<float> one;
  g24_lib::nested_imitation_struct<example_inner> two, three;
  g24_lib::nested_imitation_struct<char> four;
};

struct g24_lib::nested_imitation_struct<example_inner>
{
  g24_lib::nested_imitation_struct<int> one;
  g24_lib::nested_imitation_struct<double> two;
  g24_lib::nested_imitation_struct<char *> three;
};

struct g24_lib::nested_imitation_struct<float>
{
  float one;
};

//And similarly for other native (scalar) types.

~~~

\remark Through access to these members is through the `get_element()` or `get()` member functions.

*/
  template<class T> struct nested_imitation_struct:
    protected internals::nested_imitation_impl<T>
  {
    typedef T original_type;
    static constexpr g24_lib::Definitions::default_unsigned_indexer number = internals::get_arity<T>();
    static constexpr bool scalar = std::is_scalar_v<T>;
  private:
    static constexpr g24_lib::Definitions::default_unsigned_indexer true_number = internals::get_true_arity<T>();
  public:
    CUDA_HOS_DEV nested_imitation_struct()
    {
    }
    CUDA_HOS_DEV nested_imitation_struct (const flat_imitation_struct<T>& f)
    {
      internals::flat_to_nested<T, T>(*this, f);
    }
    CUDA_HOS_DEV nested_imitation_struct(const T& other)
    {
      if constexpr(scalar)
        {
          get<0>() = other;
        }
      else
        {
          (*this) = internals::variadic_structured_binding<T, internals::get_arity<T>()>::struct_to_nested(other);
        }
    }
    CUDA_HOS_DEV nested_imitation_struct<T>& operator=(const flat_imitation_struct<T>& f)
    {
      internals::flat_to_nested<T,T>(*this, f);
      return (*this);
    }
    CUDA_HOS_DEV nested_imitation_struct<T>& operator= (const T& other)
    {
      if constexpr (scalar)
        {
          get<0>() = other;
          return (*this);
        }
      else
        {
          return ((*this) = internals::variadic_structured_binding<T, internals::get_arity<T>()>::struct_to_nested(other));
        }
    }
/*!
    \brief Returns the i-th element of the imitation struct using the ordering from `g24_lib::class_info::type`,
           including 1-indexing.
     
    \warning The elements are 1-indexed!
*/
    template <g24_lib::Definitions::default_unsigned_indexer i> CUDA_HOS_DEV auto& get_element()
    {
      static_assert(i > 0, "The elements are 1-indexed!");
      return static_cast<internals::nested_imitation_impl<T>*>(this)->template get_element<i>();
    }
/*!
    \brief Returns the i-th element of the imitation struct using the ordering from `g24_lib::class_info::type`,
           including 1-indexing.
     
    \warning The elements are 1-indexed!
*/
    template <g24_lib::Definitions::default_unsigned_indexer i> CUDA_HOS_DEV const auto& get_element() const
    {
      static_assert(i > 0, "The elements are 1-indexed!");
      return static_cast<const internals::nested_imitation_impl<T>*>(this)->template get_element<i>();
    }
    CUDA_HOS_DEV explicit operator flat_imitation_struct<T>() const
    {
      flat_imitation_struct<T> ret;
      internals::nested_to_flat<T, T>(ret, *this);
      return ret;
    }
  
/*!
    \brief Returns the i-th element of the imitation struct using the ordering from `g24_lib::class_info::type`,
           but with 0-indexing.
           
    \details Provided for compatibility with structured bindings.
     
    \warning The elements are 0-indexed!
*/
    template <g24_lib::Definitions::default_unsigned_indexer I> CUDA_HOS_DEV auto& get()
    {
      return get_element<I+1>();
    }

/*!
    \brief Returns the i-th element of the imitation struct using the ordering from `g24_lib::class_info::type`,
           but with 0-indexing.
           
    \details Provided for compatibility with structured bindings.
     
    \warning The elements are 0-indexed!
*/
    template <g24_lib::Definitions::default_unsigned_indexer I> CUDA_HOS_DEV  const auto& get() const
    {
      return get_element<I+1>();
    }

///\cond HIDDEN_SYMBOLS

  private:

    template <g24_lib::Definitions::default_unsigned_indexer... I> 
    CUDA_HOS_DEV T type_constructor(std::integer_sequence<g24_lib::Definitions::default_unsigned_indexer,I...>) const
    {
      return T{get<I>().to_type()...};
    }
  
  public:

///\endcond

/*!
  \brief Constructs an object of the imitated type using data stored in this imitation struct.
*/
    CUDA_HOS_DEV T to_type() const
    {
      if constexpr (scalar)
        {
          return get<0>();
        }
      else
        {
          return type_constructor(std::make_integer_sequence<g24_lib::Definitions::default_unsigned_indexer,number>{});
        }
    }
  

    CUDA_HOS_DEV operator T() const
    {
      return to_type();
    }
  };

/*!
  \brief Constructs a struct that has every scalar member of all the members of a class 
         (at all levels of inclusion) based on compile time reflection from `g24_lib::class_info`.
  
  \tparam T The class being *imitated*.
  
  \details Every scalar member of any of the members of the class is held by the imitation struct,
           with every member of \p T being (recursively) reflected to extract all the scalar types.
  
  \details The types are in the same order as `g24_lib::class_info<T>::true_type`.
  
          
\remark Take
~~~{.cpp}
struct example_inner
{
  int a;
  double b;
  char *c;
};

struct example_outer
{
  float first;
  example_inner second, third;
  char fourth;
};
~~~

\remark We essentially have something equivalent to:
~~~{.cpp}
struct g24_lib::flat_imitation_struct<example_outer>
{
  float one;
  int two;
  double three;
  char *four;
  int five;
  double six;
  char *seven;
  char eight;
};

struct g24_lib::flat_imitation_struct<example_inner>
{
  int one;
  double two;
  char *three;
};

struct g24_lib::flat_imitation_struct<float>
{
  float one;
};

//And so on.

~~~

\remark Through access to these members is through the `get_element()` or `get()` member functions.

*/
  template <class T> struct flat_imitation_struct:
    protected internals::flat_imitation_impl<T>
  {
    typedef T original_type;
    static constexpr g24_lib::Definitions::default_unsigned_indexer number = internals::get_true_arity<T>();
    CUDA_HOS_DEV flat_imitation_struct()
    {
    }
    CUDA_HOS_DEV flat_imitation_struct(const nested_imitation_struct<T>& n)
    {
      internals::nested_to_flat<T, T>(*this, n);
    }
    CUDA_HOS_DEV flat_imitation_struct (const T& other)
    {
      nested_imitation_struct<T> temp =
        internals::variadic_structured_binding<T, internals::get_arity<T>()>::struct_to_nested(other);
      internals::nested_to_flat(*this, temp);
    }
    CUDA_HOS_DEV flat_imitation_struct<T>& operator=(const nested_imitation_struct<T>& n)
    {
      internals::nested_to_flat<T, T>(*this, n);
      return (*this);
    }
    CUDA_HOS_DEV flat_imitation_struct<T>& operator=(const T& other)
    {
      return ((*this) = internals::variadic_structured_binding<T, internals::get_arity<T>()>::struct_to_nested(other));
    }
  
/*!
    \brief Returns the i-th element of the imitation struct using the ordering from `g24_lib::class_info::true_type`,
           including 1-indexing.
     
    \warning The elements are 1-indexed!
*/
    template <g24_lib::Definitions::default_unsigned_indexer i> CUDA_HOS_DEV auto& get_element()
    {
      return static_cast<internals::flat_imitation_impl<T>*>(this)->template get_element<i>();
    }
  
/*!
    \brief Returns the i-th element of the imitation struct using the ordering from `g24_lib::class_info::true_type`,
           including 1-indexing.
     
    \warning The elements are 1-indexed!
*/
    template <g24_lib::Definitions::default_unsigned_indexer i> CUDA_HOS_DEV const auto& get_element() const
    {
      return static_cast<const internals::flat_imitation_impl<T>*>(this)->template get_element<i>();
    }
  
    CUDA_HOS_DEV explicit operator nested_imitation_struct<T>() const
    {
      nested_imitation_struct<T> ret;
      internals::flat_to_nested<T,T>(ret, *this);
      return ret;
    }
  
/*!
  \brief Constructs an object of the imitated type using data stored in this imitation struct.
*/
    CUDA_HOS_DEV T to_type()
    {
      nested_imitation_struct<T> help;
      internals::flat_to_nested(help, *this);
      return help.to_type();
    }
  
    CUDA_HOS_DEV operator T() const
    {
      return to_type();
    }
  
/*!
    \brief Returns the i-th element of the imitation struct using the ordering from `g24_lib::class_info::true_type`,
           but with 0-indexing.
           
    \details Provided for compatibility with structured bindings.
     
    \warning The elements are 0-indexed!
*/
    template <g24_lib::Definitions::default_unsigned_indexer I> CUDA_HOS_DEV auto& get()
    {
      return get_element<I+1>();
    }

/*!
    \brief Returns the i-th element of the imitation struct using the ordering from `g24_lib::class_info::true_type`,
           but with 0-indexing.
           
    \details Provided for compatibility with structured bindings.
     
    \warning The elements are 0-indexed!
*/
    template <g24_lib::Definitions::default_unsigned_indexer I> CUDA_HOS_DEV const auto& get() const
    {
      return get_element<I+1>();
    }
  };


}
///\cond HIDDEN_SYMBOLS
namespace std
{
  template <class T> struct tuple_size<g24_lib::nested_imitation_struct<T>> : 
    std::integral_constant<size_t, g24_lib::nested_imitation_struct<T>::number> { };
    
  template <size_t I, class T> struct tuple_element<I, g24_lib::nested_imitation_struct<T>>
  { 
    static constexpr size_t arity = g24_lib::internals::get_arity<T>();
    using type = typename std::conditional<std::is_scalar_v<T>, typename g24_lib::class_info<T>::template type<I+1>,
                                           g24_lib::nested_imitation_struct<typename g24_lib::class_info<T>::template type<I+1>>>::type;
  };
}
///\endcond
namespace g24_lib
{
  /*!
    \brief Provides a compile-time type name based on a non-portable trick involving compiler specific macros.
    
    \details This is taken from <a href = "https://stackoverflow.com/a/56766138">an answer</a>
             from user <i>einpoklum</i> of Stack Overflow, which, itself, builds on work by Howard Hinnant.
     
    \warning This uses a non-portable trick involving macros that some compilers define 
             to ease debug output of function signatures. It currently only gives correct results
             with Clang, GCC/G++ and MSVC, with all other compilers yielding "`unsupported compiler for compile time type name`".
    
    \todo Possibly figure out a way to extend this for other compilers? It is very low priority
          since the three major compilers are already supported and this is only used for error messages
          in the serialization functions, but the rest of the library strives for generality and so should this function.
          (Once again, proper reflection might alleviate this, or, at the very least,
           a standard defined way to get compile-time type names as strings...).
             
  */
  template <typename T>
  constexpr std::string_view 
  compile_time_type_name()
  {
    std::string_view name, prefix, suffix;
#ifdef __clang__
    name = __PRETTY_FUNCTION__;
    prefix = "std::string_view compile_time_type_name() [T = ";
    suffix = "]";
#elif defined(__GNUC__)
    name = __PRETTY_FUNCTION__;
    prefix = "constexpr std::string_view compile_time_type_name() [with T = ";
    suffix = "; std::string_view = std::basic_string_view<char>]";
#elif defined(_MSC_VER)
    name = __FUNCSIG__;
    prefix = "class std::basic_string_view<char,struct std::char_traits<char> > __cdecl type_name<";
    suffix = ">(void)";
#else
    name = "unsupported compiler for compile time type name";
    prefix = "";
    suffix = "";
#endif
    name.remove_prefix(prefix.size());
    name.remove_suffix(suffix.size());
    return name;
  }

}

#endif

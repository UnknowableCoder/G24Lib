#ifndef G24_LIB_DEFERRED_OPS
#define G24_LIB_DEFERRED_OPS

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

\file deferred_ops.h

\brief Defines several utilities to allow compile-time deferral of the evaluation of some
       operations (in essence, a limited form of lazy evaluation enforced by types).

\author Nuno Fernandes (main coder, current maintainer)

*/ 

namespace g24_lib
{
  ///\cond HIDDEN_SYMBOLS
  namespace internals
  {
    struct deferred_base
    {
    };
  }
  ///\endcond
  
  /*!
    \brief Checks if \p C expresses a type on which the operations are deferred.
    
    \sa `g24_lib::defer`
  */
  template <class C>
  inline constexpr bool is_deferred = std::is_base_of_v<internals::deferred_base,std::decay_t<C>>;
  
  
  ///\cond HIDDEN_SYMBOLS
  namespace internals
  {
    template <class C, bool by_value = false> struct deferred_return;
    template <class A, class B> struct deferred_add;
    template <class A, class B> struct deferred_subtract;
    template <class A, class B> struct deferred_multiply;
    template <class A, class B> struct deferred_divide;
    template <class A, class B> struct deferred_mod;
    template <class A, class B> struct deferred_bit_xor;
    template <class A, class B> struct deferred_bit_and;
    template <class A, class B> struct deferred_bit_or;
    template <class A, class B> struct deferred_lesser;
    template <class A, class B> struct deferred_lesser_equal;
    template <class A, class B> struct deferred_greater;
    template <class A, class B> struct deferred_greater_equal;
    template <class A, class B> struct deferred_left_shift;
    template <class A, class B> struct deferred_right_shift;
    template <class A, class B> struct deferred_equal;
    template <class A, class B> struct deferred_not_equal;
    template <class A> struct deferred_pre_increment;
    template <class A> struct deferred_pre_decrement;
    template <class A> struct deferred_post_increment;
    template <class A> struct deferred_post_decrement;
    template <class A> struct deferred_negative;
    template <class A> struct deferred_positive;
    template <class A> struct deferred_bit_not;
    template <class A> struct deferred_not;
    template <class A, class B> struct deferred_array_access;
    
  }
  ///\endcond 
  /*!
    \brief Defers the evaluation of most overloadable operators on \p x.
    
    \tparam C The type of the object upon which the operators will be deferred.
    
    \tparam by_value If `true`, the object is stored by value rather than by reference.
                     Useful mostly for \c CUDA interoperatability, or other situations
                     where references may be invalidated.
                     
    \param x The object to be deferred
    
    \warning The deferred operators correspond to binary `x + y`, `x - y`, `x * y`,
             `x / y`, `x % y`, `x ^ y`, `x & y`, `x | y`, `x < y`, `x <= y`, `x > y`,
             `x >= y`, `x << y`, `x >> y`, `x == y`, `x != y`, unary `+x`, `-x`,
             `~x`, `!x` and both pre and post increment and decrement 
             (`++x`, `x++`, `--x` and `x--`), as well as array access (`x[y]`).
             
    \remark Due to the type-based nature of this deferred evaluation,
            the use of the `auto` keyword is strongly reccommended.
            Similarly, to ensure function parameters that may be deferred objects
            do work properly, they should be templated.
    
    \remark The author acknowledges this could be partly alleviated if one were to employ
            virtual functions and simply refer to a base object,
    
    \warning Since the `<<` operator is also deferred, if one wishes to output a deferred object
             to a stream, one should either explicitly cast it to an appropriate type or call its
             `execute()` method. (Which, despite its name, will not entail any harm to any living being.)
  */
  template <class C, bool by_value = false> CUDA_HOS_DEV inline constexpr auto defer(const C& x)
  {
    if constexpr (is_deferred<C>)
      {
        if constexpr (by_value)
          {
            return x.to_by_value();
          }
        else
          {
            return x.to_by_reference();
          }
      }
    else if constexpr (std::is_rvalue_reference_v<C>)
      {
        return internals::deferred_return<std::decay_t<C>, true>{x};
      }
    else
      {
        return internals::deferred_return<std::decay_t<C>, by_value>{x};
      }
  }
    
  ///\endcond 
  /*!
    \brief Defers the evaluation of most overloadable operators on \p x.
    
    \tparam C The type of the object upon which the operators will be deferred.
    
    \tparam by_value If `true`, the object is stored by value rather than by reference.
                     Useful mostly for \c CUDA interoperatability, or other situations
                     where references may be invalidated.
                     
    \param x The object to be deferred
    
    \warning The deferred operators correspond to binary `x + y`, `x - y`, `x * y`,
             `x / y`, `x % y`, `x ^ y`, `x & y`, `x | y`, `x < y`, `x <= y`, `x > y`,
             `x >= y`, `x << y`, `x >> y`, `x == y`, `x != y`, unary `+x`, `-x`,
             `~x`, `!x` and both pre and post increment and decrement 
             (`++x`, `x++`, `--x` and `x--`), as well as array access (`x[y]`).
             
    \remark Due to the type-based nature of this deferred evaluation,
            the use of the `auto` keyword is strongly reccommended.
            Similarly, to ensure function parameters that may be deferred objects
            do work properly, they should be templated.
    
    \remark The author acknowledges this could be partly alleviated if one were to employ
            virtual functions and simply refer to a base object,
    
    \warning Since the `<<` operator is also deferred, if one wishes to output a deferred object
             to a stream, one should either explicitly cast it to an appropriate type or call its
             `execute()` method. (Which, despite its name, will not entail any harm to any living being.)
  */
  template <class C, bool by_value = false> CUDA_HOS_DEV inline constexpr auto defer(C&& x)
  {
    if constexpr (is_deferred<C>)
      {
        if constexpr (by_value)
          {
            return x.to_by_value();
          }
        else
          {
            return x.to_by_reference();
          }
      }
    else
      {
        return internals::deferred_return<std::decay_t<C>, true>{x};
        //In this case, the object is doomed to die, so we store it inside...
      }
  }
  ///\cond HIDDEN_SYMBOLS
  namespace internals
  {
#define G24_LIB_DEFERRED_OPS_BINARY_OPER(OP, NAME)                     \
template <class T1, class T2, typename std::enable_if_t<is_deferred<T1> || is_deferred<T2>>* = nullptr> \
CUDA_HOS_DEV inline constexpr auto operator OP (T1&& x, T2&& y)        \
{                                                                      \
  if constexpr (is_deferred<T1> && is_deferred <T2>)                   \
    {                                                                  \
      constexpr bool return_by_value = std::decay_t<T1>::by_value || std::decay_t<T1>::by_value; \
      const auto defer_first = defer<T1, return_by_value>(x);          \
      const auto defer_second = defer<T2, return_by_value>(y);         \
      return NAME <std::decay_t<decltype(defer_first)>,                \
                   std::decay_t<decltype(defer_second)>>               \
                  { defer_first, defer_second };                       \
    }                                                                  \
  else if constexpr (is_deferred<T1>)                                  \
    {                                                                  \
      constexpr bool return_by_value = std::decay_t<T1>::by_value;     \
      const auto defer_first = defer<T1, return_by_value>(x);          \
      const auto defer_second = defer<T2, return_by_value>(y);         \
      return NAME <std::decay_t<decltype(defer_first)>,                \
                   std::decay_t<decltype(defer_second)>>               \
                  { defer_first, defer_second };                       \
    }                                                                  \
  else /*if constexpr (is_deferred<T2>)*/                              \
    {                                                                  \
      constexpr bool return_by_value = std::decay_t<T2>::by_value;     \
      const auto defer_first = defer<T1, return_by_value>(x);          \
      const auto defer_second = defer<T2, return_by_value>(y);         \
      return NAME <std::decay_t<decltype(defer_first)>,                \
                   std::decay_t<decltype(defer_second)>>               \
                  { defer_first, defer_second };                       \
    }                                                                  \
}                                                                      \


      G24_LIB_DEFERRED_OPS_BINARY_OPER(+, deferred_add);
      G24_LIB_DEFERRED_OPS_BINARY_OPER(-, deferred_subtract);
      G24_LIB_DEFERRED_OPS_BINARY_OPER(*, deferred_multiply);
      G24_LIB_DEFERRED_OPS_BINARY_OPER(/, deferred_divide);
      G24_LIB_DEFERRED_OPS_BINARY_OPER(%, deferred_mod);
      G24_LIB_DEFERRED_OPS_BINARY_OPER(^, deferred_bit_xor);
      G24_LIB_DEFERRED_OPS_BINARY_OPER(&, deferred_bit_and);
      G24_LIB_DEFERRED_OPS_BINARY_OPER(|, deferred_bit_or);
      G24_LIB_DEFERRED_OPS_BINARY_OPER(<, deferred_lesser);
      G24_LIB_DEFERRED_OPS_BINARY_OPER(<=, deferred_lesser_equal);
      G24_LIB_DEFERRED_OPS_BINARY_OPER(>, deferred_greater);
      G24_LIB_DEFERRED_OPS_BINARY_OPER(>=, deferred_greater_equal);
      G24_LIB_DEFERRED_OPS_BINARY_OPER(<<, deferred_left_shift);
      G24_LIB_DEFERRED_OPS_BINARY_OPER(>>, deferred_right_shift);
      G24_LIB_DEFERRED_OPS_BINARY_OPER(==, deferred_equal);
      G24_LIB_DEFERRED_OPS_BINARY_OPER(!=, deferred_not_equal);      

#define G24_LIB_DEFERRED_OPS_PRE_UNARY_OPER(OP, NAME)                  \
template <class T1, typename std::enable_if_t<is_deferred<T1>>* = nullptr> \
CUDA_HOS_DEV inline constexpr auto operator OP (const T1& x)           \
{                                                                      \
  return NAME <T1>(x);                                                 \
}                                                                      \
      
      G24_LIB_DEFERRED_OPS_PRE_UNARY_OPER(++, deferred_pre_increment);
      G24_LIB_DEFERRED_OPS_PRE_UNARY_OPER(--, deferred_pre_decrement);
      G24_LIB_DEFERRED_OPS_PRE_UNARY_OPER(-, deferred_negative);
      G24_LIB_DEFERRED_OPS_PRE_UNARY_OPER(+, deferred_positive);
      G24_LIB_DEFERRED_OPS_PRE_UNARY_OPER(~, deferred_bit_not);
      G24_LIB_DEFERRED_OPS_PRE_UNARY_OPER(!, deferred_not);
      
#define G24_LIB_DEFERRED_OPS_POST_UNARY_OPER(OP, NAME)                 \
template <class T1, typename std::enable_if_t<is_deferred<T1>>* = nullptr> \
CUDA_HOS_DEV inline constexpr auto operator OP (const T1& x, int)      \
{                                                                      \
  return NAME <T1>(x);                                                 \
}                                                                      \


      G24_LIB_DEFERRED_OPS_POST_UNARY_OPER(++, deferred_post_increment);
      G24_LIB_DEFERRED_OPS_POST_UNARY_OPER(--, deferred_post_decrement);      
  
//The variable arguments are the class name, so it can contain commas!
#define G24_LIB_DEFERRED_OPS_IN_CLASS_OPERATORS(...)                  \
template <class T1, class T = typename __VA_ARGS__::result_t,         \
          typename std::enable_if_t<!is_container<T> && std::is_convertible_v<result_t, T>>* = nullptr >  \
CUDA_HOS_DEV inline constexpr operator T1 () const                    \
{                                                                     \
  return execute();                                                   \
}                                                                     \
template <class T2>                                                   \
CUDA_HOS_DEV inline constexpr auto operator[] (T2&& x) const          \
{                                                                     \
  if constexpr (is_deferred<T2>)                                      \
    {                                                                 \
      constexpr bool return_by_value = by_value || std::decay_t<T2>::by_value; \
      const auto defer_first = defer<__VA_ARGS__, return_by_value>(*this); \
      const auto defer_second = defer<T2, return_by_value>(x);        \
      return deferred_array_access <std::decay_t<decltype(defer_first)>, \
                                    std::decay_t<decltype(defer_second)>> \
                                    { defer_first, defer_second };    \
    }                                                                 \
  else                                                                \
    {                                                                 \
      const auto defer_second = defer<T2, by_value>(x);               \
      return deferred_array_access< __VA_ARGS__,                      \
                                    std::decay_t<decltype(defer_second)>> \
                                    { (*this), defer_second };        \
    }                                                                 \
}

    template <class C, bool by_val> struct deferred_return_helper;
    
    template <class C> struct deferred_return_helper<C, false>
    {
      const C& a;
      CUDA_HOS_DEV constexpr deferred_return_helper(const C& c): a(c)
      {
      }
    };
    
    template <class C> struct deferred_return_helper<C, true>
    {
      const C a;
      CUDA_HOS_DEV constexpr deferred_return_helper(const C& c): a(c)
      {
      }
    };
    
    template <class C, bool by_val> struct deferred_return : private deferred_base, public deferred_return_helper<C, by_val>
    {
      CUDA_HOS_DEV constexpr deferred_return(const C& c): deferred_return_helper<C, by_val>(c)
      {
      }
      
      static constexpr bool by_value = by_val;
      
      using result_t = C;
      
      using value_type = g24_lib::value_type<result_t>;
      //Will be void if C is not a container.
      
      using indexer_type = g24_lib::indexer_type<result_t>;
      //Will be void if C is not a container.
      
      template <class T = result_t, typename std::enable_if_t<g24_lib::is_container<T>>* = nullptr>
      CUDA_HOS_DEV constexpr auto size() const
      {
        return this->a.size();
      }
      
      template <class Other>
      CUDA_HOS_DEV constexpr auto array_access (const Other& oth) const
      {
        if constexpr (g24_lib::is_container<result_t> ||
                      !std::is_void_v<typename g24_lib::internals::
                                        access_checker<result_t, void, true>::template type<Other>>)
        //We also check to see if applying operator[oth] yields anything.
          {
            return this -> a[oth];
          }
        else
          {
            return this -> a;
          }
      }
      
      CUDA_HOS_DEV constexpr result_t execute() const
      {
        return this->a;
      }
      
      template <class stream>
      void print(stream &s) const
      {
        if constexpr (g24_lib::is_container<C>)
          {
            s << "{ CONTAINER @ " << &this->a << " }" ; 
          }
        else
          {
            s << "{ " << this->a << " }" ; 
          }
      }
      
      CUDA_HOS_DEV constexpr auto to_by_value() const
      {
        if constexpr (by_value)
          {
            return (*this);
          }
        else
          {
            return deferred_return<C, true>(this->a);
          }
      }
      
      CUDA_HOS_DEV constexpr auto to_by_reference() const
      {
        if constexpr (!by_value)
          {
            return (*this);
          }
        else
          {
            return deferred_return<C, false>(this->a);
          }
      }
      
      CUDA_ONLY_HOS constexpr auto to_CUDA() const
      {
        return deferred_return<C, true>{g24_lib::to_CUDA(this->a)};
      }
      
      G24_LIB_DEFERRED_OPS_IN_CLASS_OPERATORS(deferred_return<C, by_val>);
      
    };
    
    
    template <class A, class B,
              bool helper1 = g24_lib::is_container<A>,
              bool helper2 = g24_lib::is_container<B> > struct result_type_getter;
                  
//The variable arguments are the class name, so it can contain commas!
#define G24_LIB_DEFERRED_OPS_BINARY_CLASS(OP, ...)      \
    template <class A, class B,                         \
              bool container = g24_lib::is_container<A> || \
                               g24_lib::is_container<B>    > \
    struct __VA_ARGS__ ## _result_getter;                \
    template <class A, class B> struct __VA_ARGS__ ## _result_getter <A, B, true> \
    {                                                    \
      using type = std::conditional_t< g24_lib::is_container<A>, \
                                       typename A::result_t, \
                                       typename B::result_t \
                                     >;                  \
    };                                                   \
    template <class A, class B> struct __VA_ARGS__ ## _result_getter <A, B, false> \
    {                                                    \
      using type = decltype(std::declval<A>().execute() OP std::declval<B>().execute()); \
    };                                                   \
    template <class A, class B> struct __VA_ARGS__  : private deferred_base \
    {                                                    \
      const A a;                                         \
      const B b;                                         \
      CUDA_HOS_DEV constexpr __VA_ARGS__ (const A& c1, const B& c2): a(c1), b(c2) \
      {                                                  \
      }                                                  \
      CUDA_HOS_DEV constexpr auto execute() const        \
      {                                                  \
        return a.execute() OP b.execute();               \
      }                                                  \
      static constexpr bool by_value = A::by_value || B::by_value; \
      using result_t = typename __VA_ARGS__ ## _result_getter<A, B>::type;  \
      using value_type = g24_lib::value_type<result_t>;  \
      using indexer_type = g24_lib::indexer_type<result_t>; \
      template <class T = result_t, typename std::enable_if_t<g24_lib::is_container<T>>* = nullptr>\
      CUDA_HOS_DEV constexpr auto size() const           \
      {                                                  \
        if constexpr(!g24_lib::is_container<B>)          \
          {                                              \
            return a.size();                             \
          }                                              \
        else if constexpr(!g24_lib::is_container<A>)     \
          {                                              \
            return b.size();                             \
          }                                              \
        else                                             \
          {                                              \
            if (b.size() >= a.size())                    \
              {                                          \
                return a.size();                         \
              }                                          \
            else                                         \
              {                                          \
                return b.size();                         \
              }                                          \
          }                                              \
      }                                                  \
      template <class Other>                             \
      CUDA_HOS_DEV constexpr auto array_access (const Other& oth) const \
      {                                                  \
        return (a.array_access(oth) OP b.array_access(oth)); \
      }                                                  \
      template <class stream>                            \
      void print(stream &s) const                        \
      {                                                  \
        s << "{ ";                                       \
        a.print(s);                                      \
        s << " " << #OP << " ";                          \
        b.print(s);                                      \
        s << " }" ;                                      \
      }                                                  \
      CUDA_HOS_DEV constexpr auto to_by_value() const    \
      {                                                  \
        if constexpr (by_value)                          \
          {                                              \
            return (*this);                              \
          }                                              \
        else                                             \
          {                                              \
            return a.to_by_value() OP b.to_by_value();   \
          }                                              \
      }                                                  \
      CUDA_HOS_DEV constexpr auto to_by_reference() const \
      {                                                  \
        if constexpr (!by_value)                         \
          {                                              \
            return (*this);                              \
          }                                              \
        else                                             \
          {                                              \
            return a.to_by_reference() OP b.to_by_reference(); \
          }                                              \
      }                                                  \
      CUDA_ONLY_HOS constexpr auto to_CUDA() const       \
      {                                                  \
        return a.to_CUDA() OP b.to_CUDA();               \
      }                                                  \
      G24_LIB_DEFERRED_OPS_IN_CLASS_OPERATORS(__VA_ARGS__ <A , B>);\
    }
    
    G24_LIB_DEFERRED_OPS_BINARY_CLASS(+, deferred_add);
    G24_LIB_DEFERRED_OPS_BINARY_CLASS(-, deferred_subtract);
    G24_LIB_DEFERRED_OPS_BINARY_CLASS(*, deferred_multiply);
    G24_LIB_DEFERRED_OPS_BINARY_CLASS(/, deferred_divide);
    G24_LIB_DEFERRED_OPS_BINARY_CLASS(%, deferred_mod);
    G24_LIB_DEFERRED_OPS_BINARY_CLASS(^, deferred_bit_xor);
    G24_LIB_DEFERRED_OPS_BINARY_CLASS(&, deferred_bit_and);
    G24_LIB_DEFERRED_OPS_BINARY_CLASS(|, deferred_bit_or);
    G24_LIB_DEFERRED_OPS_BINARY_CLASS(<, deferred_lesser);
    G24_LIB_DEFERRED_OPS_BINARY_CLASS(<=, deferred_lesser_equal);
    G24_LIB_DEFERRED_OPS_BINARY_CLASS(>, deferred_greater);
    G24_LIB_DEFERRED_OPS_BINARY_CLASS(>=, deferred_greater_equal);
    G24_LIB_DEFERRED_OPS_BINARY_CLASS(<<, deferred_left_shift);
    G24_LIB_DEFERRED_OPS_BINARY_CLASS(>>, deferred_right_shift);
    G24_LIB_DEFERRED_OPS_BINARY_CLASS(==, deferred_equal);
    G24_LIB_DEFERRED_OPS_BINARY_CLASS(!=, deferred_not_equal);
    
//The variable arguments are the class name, so it can contain commas!
#define G24_LIB_DEFERRED_OPS_PRE_UNARY_CLASS(OP, ...)    \
    template <class A, bool container = g24_lib::is_container<A> > \
    struct __VA_ARGS__ ## _result_getter;                \
    template <class A> struct __VA_ARGS__ ## _result_getter <A, true> \
    {                                                    \
      using type = typename A::result_t;                 \
    };                                                   \
    template <class A> struct __VA_ARGS__ ## _result_getter <A, false> \
    {                                                    \
      using type = decltype(OP std::declval<A>().execute); \
    };                                                   \
    template <class A> struct __VA_ARGS__ : private deferred_base \
    {                                                    \
      const A a;                                         \
      CUDA_HOS_DEV constexpr __VA_ARGS__ (const A &c1): a(c1) \
      {                                                  \
      }                                                  \
      CUDA_HOS_DEV constexpr auto execute() const        \
      {                                                  \
        return (OP a.execute());                         \
      }                                                  \
      static constexpr bool by_value = A::by_value;      \
      using result_t = typename __VA_ARGS__ ## _result_getter<A>::type;  \
      using value_type = g24_lib::value_type<result_t>;  \
      using indexer_type = g24_lib::indexer_type<result_t>; \
      template <class T = result_t, typename std::enable_if_t<g24_lib::is_container<T>>* = nullptr>\
      CUDA_HOS_DEV constexpr auto size() const           \
      {                                                  \
        return a.size();                                 \
      }                                                  \
      template <class Other>                             \
      CUDA_HOS_DEV constexpr auto array_access (const Other& oth) const \
      {                                                  \
        return (OP a.array_access(oth));                 \
      }                                                  \
      template <class stream>                            \
      void print(stream &s) const                        \
      {                                                  \
        s << "{ " << #OP << " ";                         \
        a.print(s);                                      \
        s << " }" ;                                      \
      }                                                  \
      CUDA_HOS_DEV constexpr auto to_by_value() const    \
      {                                                  \
        if constexpr (by_value)                          \
          {                                              \
            return (*this);                              \
          }                                              \
        else                                             \
          {                                              \
            return (OP a.to_by_value());                 \
          }                                              \
      }                                                  \
      CUDA_HOS_DEV constexpr auto to_by_reference() const \
      {                                                  \
        if constexpr (!by_value)                         \
          {                                              \
            return (*this);                              \
          }                                              \
        else                                             \
          {                                              \
            return (OP a.to_by_reference());             \
          }                                              \
      }                                                  \
      CUDA_ONLY_HOS constexpr auto to_CUDA() const       \
      {                                                  \
        return (OP a.to_CUDA());                         \
      }                                                  \
      G24_LIB_DEFERRED_OPS_IN_CLASS_OPERATORS(__VA_ARGS__ <A>);   \
    }
    
#define G24_LIB_DEFERRED_OPS_POST_UNARY_CLASS(OP, ...)   \
    template <class A, bool container = g24_lib::is_container<A> > \
    struct __VA_ARGS__ ## _result_getter;                \
    template <class A> struct __VA_ARGS__ ## _result_getter <A, true> \
    {                                                    \
      using type = typename A::result_t;                 \
    };                                                   \
    template <class A> struct __VA_ARGS__ ## _result_getter <A, false> \
    {                                                    \
      using type = decltype(OP std::declval<A>().execute); \
    };                                                   \
    template <class A> struct __VA_ARGS__ : private deferred_base \
    {                                                    \
      const A a;                                         \
      CUDA_HOS_DEV constexpr __VA_ARGS__ (const A &c1): a(c1) \
      {                                                  \
      }                                                  \
      CUDA_HOS_DEV constexpr auto execute() const        \
      {                                                  \
        return (a.execute() OP);                         \
      }                                                  \
      static constexpr bool by_value = A::by_value;      \
      using result_t = typename __VA_ARGS__ ## _result_getter<A>::type; \
      using value_type = g24_lib::value_type<result_t>;  \
      using indexer_type = g24_lib::indexer_type<result_t>; \
      template <class T = result_t, typename std::enable_if_t<g24_lib::is_container<T>>* = nullptr>\
      CUDA_HOS_DEV constexpr auto size() const           \
      {                                                  \
        return a.size();                                 \
      }                                                  \
      template <class Other>                             \
      CUDA_HOS_DEV constexpr auto array_access (const Other& oth) const \
      {                                                  \
        return (a.array_access(oth) OP);                 \
      }                                                  \
      template <class stream>                            \
      void print(stream &s) const                        \
      {                                                  \
        s << "{ ";                                       \
        a.print(s);                                      \
        s << " " << #OP << " }" ;                        \
      }                                                  \
      CUDA_HOS_DEV constexpr auto to_by_value() const    \
      {                                                  \
        if constexpr (by_value)                          \
          {                                              \
            return (*this);                              \
          }                                              \
        else                                             \
          {                                              \
            return (a.to_by_value() OP);                 \
          }                                              \
      }                                                  \
      CUDA_HOS_DEV constexpr auto to_by_reference() const \
      {                                                  \
        if constexpr (!by_value)                         \
          {                                              \
            return (*this);                              \
          }                                              \
        else                                             \
          {                                              \
            return (a.to_by_reference() OP);             \
          }                                              \
      }                                                  \
      CUDA_ONLY_HOS constexpr auto to_CUDA() const       \
      {                                                  \
        return (a.to_CUDA() OP);                         \
      }                                                  \
      G24_LIB_DEFERRED_OPS_IN_CLASS_OPERATORS(__VA_ARGS__ <A>);   \
    }
    
    G24_LIB_DEFERRED_OPS_PRE_UNARY_CLASS(++, deferred_pre_increment);
    G24_LIB_DEFERRED_OPS_PRE_UNARY_CLASS(--, deferred_pre_decrement);
    G24_LIB_DEFERRED_OPS_PRE_UNARY_CLASS(-, deferred_negative);
    G24_LIB_DEFERRED_OPS_PRE_UNARY_CLASS(+, deferred_positive);
    G24_LIB_DEFERRED_OPS_PRE_UNARY_CLASS(~, deferred_bit_not);
    G24_LIB_DEFERRED_OPS_PRE_UNARY_CLASS(!, deferred_not);
    G24_LIB_DEFERRED_OPS_POST_UNARY_CLASS(++, deferred_post_increment);
    G24_LIB_DEFERRED_OPS_POST_UNARY_CLASS(--, deferred_post_decrement);
    
    template <class A, class B> struct deferred_array_access : public deferred_base
    {
      const A a;
      const B b;
      CUDA_HOS_DEV constexpr deferred_array_access (const A& c1, const B&c2): a(c1), b(c2)
      {
      }
      CUDA_HOS_DEV constexpr auto execute() const
      {
        return a.array_access(b.execute());
      }
      static constexpr bool by_value = A::by_value || B::by_value;
      
      using result_t = decltype(std::declval<A>().array_access(std::declval<B>().execute()));
      
      using value_type = g24_lib::value_type<result_t>;
      
      using indexer_type = g24_lib::indexer_type<result_t>;
      
      template <class T = result_t, typename std::enable_if_t<g24_lib::is_container<T>>* = nullptr>
      CUDA_HOS_DEV constexpr auto size() const
      {
        return this->execute().size();
      }
      template <class Other>
      CUDA_HOS_DEV constexpr auto array_access (const Other& oth) const
      {
        return a;
      }
      template <class stream>
      void print(stream &s) const
      {
        a.print(s);
        s << " [ ";
        b.print(s);
        s << " ] " ;
      }
      CUDA_HOS_DEV constexpr auto to_by_value() const
      {
        if constexpr (by_value)
          {
            return (*this);
          }
        else
          {
            return a.to_by_value() [b.to_by_value()];
          }
      }
      CUDA_HOS_DEV constexpr auto to_by_reference() const
      {
        if constexpr (!by_value)
          {
            return (*this);
          }
        else
          {
            return a.to_by_reference() [b.to_by_reference()];
          }
      }
      CUDA_ONLY_HOS constexpr auto to_CUDA() const
      {
        return a.to_CUDA() [b.to_CUDA()];
      }
      
      G24_LIB_DEFERRED_OPS_IN_CLASS_OPERATORS(deferred_array_access<A,B>);
            
    };
  #undef G24_LIB_DEFERRED_OPS_POST_UNARY_CLASS
  #undef G24_LIB_DEFERRED_OPS_PRE_UNARY_CLASS
  #undef G24_LIB_DEFERRED_OPS_BINARY_CLASS
  #undef G24_LIB_DEFERRED_OPS_IN_CLASS_OPERATORS
  #undef G24_LIB_DEFERRED_OPS_POST_UNARY_OPER
  #undef G24_LIB_DEFERRED_OPS_PRE_UNARY_OPER
  #undef G24_LIB_DEFERRED_OPS_BINARY_OPER
  }
  ///\endcond 
}
#endif
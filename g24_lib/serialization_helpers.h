#ifndef G24_LIB_SERIALIZATION_HELPERS
#define G24_LIB_SERIALIZATION_HELPERS

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

\file serialization_helpers.h

\brief A set of utilities that facillitate input and output, both in textual
       and binary form, of any class that can undergo compile time reflection.

\author Nuno Fernandes (main coder, current maintainer)

*/

namespace g24_lib
{
///\cond HIDDEN_SYMBOLS
  namespace internals
  {

    template<class C> struct has_functions
    {
    //The following is adapted from code 
    //written by the user jrok of Stack Exchange
    //(https://stackoverflow.com/a/16824239)
    private:
      template<class T>
      static constexpr auto check1(T*) -> typename std::is_void<decltype(std::declval<T>().binary_output(std::cout))>;
      template<class T>
      static constexpr auto check2(T*) -> typename std::is_void<decltype(std::declval<T>().binary_input(std::cin))>;
      template<class T>
      static constexpr auto check3(T*) -> typename std::is_void<decltype(std::declval<T>().textual_output(std::cout))>;
      template<class T>
      static constexpr auto check4(T*) -> typename std::is_void<decltype(std::declval<T>().textual_input(std::cin))>;
      template<class T, class S>
      static constexpr auto check5(T*) -> typename std::is_same<decltype(std::declval<S>() << std::declval<T>()), S>;
      template<class T, class S>
      static constexpr auto check6(T*) -> typename std::is_same<decltype(std::declval<S>() >> std::declval<T>()), S>;

      template<class>
      static constexpr std::false_type check1(...);
      template<class>
      static constexpr std::false_type check2(...);
      template<class>
      static constexpr std::false_type check3(...);
      template<class>
      static constexpr std::false_type check4(...);
      template<class, class>
      static constexpr std::false_type check5(...);
      template<class, class>
      static constexpr std::false_type check6(...);

      typedef decltype(check1<C>(0)) type1;
      typedef decltype(check2<C>(0)) type2;
      typedef decltype(check3<C>(0)) type3;
      typedef decltype(check4<C>(0)) type4;
      template <class S> using type5 = decltype(check5<C, S>(0));
      template <class S> using type6 = decltype(check6<C, S>(0));

    public:
      static constexpr bool value1 = type1::value;
      static constexpr bool value2 = type2::value;
      static constexpr bool value3 = type3::value;
      static constexpr bool value4 = type4::value;
      template <class S> static constexpr bool value5 = type5<S>::value;
      template <class S> static constexpr bool value6 = type6<S>::value;
    };
  
    template<class T> constexpr bool specifies_binary_output()
    {
      return has_functions<T>::value1;
    }
  
    template<class T> constexpr bool specifies_binary_input()
    {
      return has_functions<T>::value2;
    }
  
    template<class T> constexpr bool specifies_textual_output()
    {
      return has_functions<T>::value3;
    }
  
    template<class T> constexpr bool specifies_textual_input()
    {
      return has_functions<T>::value4;
    }
  
    template<class T, class S> constexpr bool specifies_output_operator()
    {
      return has_functions<T>::template value5<S>;
    }
  
    template<class T, class S> constexpr bool specifies_input_operator()
    {
      return has_functions<T>::template value6<S>;
    }
    
    template<class T, class stream, class str, g24_lib::Definitions::default_unsigned_indexer num = 0>
    void text_out_iter(stream &s, const flat_imitation_struct<T> &imit, const str& separator)
    {
      if constexpr (num < imit.number - 1)
        //imit.number is the number of members
        //of the flattened representation of type T.
        {
          s << imit.template get<num>() << separator;
          text_out_iter<T, stream, str, num+1>(s, imit, separator);
        }
      else if constexpr (num == imit.number-1)
        //To prevent printing another separator.
        {
          s << imit.template get<num>();
        }
    }
  
    template<class T, class stream, g24_lib::Definitions::default_unsigned_indexer num = 0>
    void text_in_iter(stream &s, flat_imitation_struct<T> &imit)
    {
      if constexpr (num < imit.number)
        {
          s >> imit.template get<num>();
          text_in_iter<T, stream, num+1>(s, imit);
        }
    }
  
    template<class T, class stream, g24_lib::Definitions::default_unsigned_indexer num = 0>
    void bin_out_iter(stream &s, const flat_imitation_struct<T> &imit)
    {
      if constexpr (num < imit.number)
        {
          s.write((char*) &imit.template get<num>(),sizeof(imit.template get<num>()));
          bin_out_iter<T, stream, num+1>(s, imit);
        }
    }
  
    template<class T, class stream, g24_lib::Definitions::default_unsigned_indexer num = 0>
    void bin_in_iter(stream &s, flat_imitation_struct<T> &imit)
    {
      if constexpr (num < imit.number)
        {
          s.read((char*) &imit.template get<num>(),sizeof(imit.template get<num>()));
          bin_in_iter<T, stream, num+1>(s, imit);
        }
    }
  }
///\endcond

/*!
\brief Outputs an object in text mode.

\tparam T the type of the object being output.

\tparam stream Something akin to an `ostream`, to which text can be output.

\param separator A set of characters (of appropriate type) that may be outputted to separate
                 the several members of a reflected struct.

\throw In case an output error is encountered, uses g24_lib::exceptions::throw_exception
       to possibly throw a g24_lib::exceptions::output_error.

\remark The behaviour of this function for user defined classes may be more simply "overloaded"
        by providing a `textual_output` member function that takes \p s and \p separator as arguments,
        which will be used whenever available.
        
\remark For classes that implement an `operator <<` that applies to an object of type \p stream,
        that operator is used.
        
\remark For classes that do not have either a `textual_output` member function or
        an `operator <<` that applies to an object of type \p stream,
        a `g24_lib::flat_imitation_struct` is constructed and
        every member is output to the stream.
        
\pre \p stream must have a valid `operator <<` with any type that
     satisfies `std::is_scalar` (bools, integers, floating point types, enums or pointers).

*/
  template <class T, class stream, class str = std::basic_string<typename stream::char_type>>
  void textual_output(stream &s, const T& out, const str& separator = " ")
  //stream is something like an ostream,
  //but I wanted to keep it generic.
  //If everything goes well, it's all deduced.
  {
    if constexpr(internals::specifies_textual_output<T>())
      {
        out.textual_output(s, separator);
      }
    else if constexpr (internals::specifies_output_operator<T, stream>())
      {
        s << out;
      }
    else if constexpr (std::is_scalar_v<T>)
      {
        s << out;
      }
    else
      {
        flat_imitation_struct<T> imit = out;
        internals::text_out_iter(s, imit, separator);
      }
    if(s.fail())
      {
        exceptions::throw_exception(exceptions::output_error(std::string("Cannot output object of type ") + std::string(compile_time_type_name<T>())));
      }
  }

/*!
\brief Inputs an object in text mode.

\tparam T the type of the object being input.

\tparam stream Something akin to an `istream`, from which text can be input.

\throw In case an input error is encountered, uses g24_lib::exceptions::throw_exception
       to possibly throw a g24_lib::exceptions::input_error. The input object \p in may be in an invalid state.

\remark The behaviour of this function for user defined classes may be more simply "overloaded"
        by providing a `textual_input` member function that takes \p s as argument,
        which will be used whenever available.
        
\remark For classes that implement an `operator >>` that applies to an object of type \p stream,
        that operator is used.
        
\remark For classes that do not have either a `textual_input` member function or
        an `operator >>` that applies to an object of type \p stream,
        a `g24_lib::flat_imitation_struct` is constructed,
        every member is input from the stream
        and the new value of \p in will come from a new \p T constructed from the imitation struct.
        
\pre \p stream must have a valid `operator >>` with any type that
     satisfies `std::is_scalar` (bools, integers, floating point types, enums or pointers).

*/
  template <class T, class stream>
  void textual_input(stream &s, T& in)
  {
    if constexpr(internals::specifies_textual_input<T>())
      {
        in.textual_input(s);
      }
    else if constexpr (internals::specifies_input_operator<T, stream>())
      {
        s >> in;
      }
    else if constexpr (std::is_scalar_v<T>)
      {
        s >> in;
      }
    else
      {
        flat_imitation_struct<T> imit;
        internals::text_in_iter(s, imit);
        in = imit.to_type();
      }
    if(s.fail())
      {
        exceptions::throw_exception(exceptions::input_error(std::string("Cannot input object of type ") + std::string(compile_time_type_name<T>())));
      }
  }
///\cond HIDDEN_SYMBOLS
  template <class T, class stream, class str = std::basic_string<typename stream::char_type>>
  void textual_output(stream &s, const flat_imitation_struct<T>& out, const str& separator = " ")
  {
    internals::text_out_iter(s, out, separator);
    if(s.fail())
      {
        exceptions::throw_exception(exceptions::output_error(std::string("Cannot output imitation of type ") + std::string(compile_time_type_name<T>())));
      }
  }

  template <class T, class stream>
  void textual_input(stream &s, flat_imitation_struct<T>& in)
  {
    internals::text_in_iter(s, in);
    if(s.fail())
      {
        exceptions::throw_exception(exceptions::input_error(std::string("Cannot input imitation of type ") + std::string(compile_time_type_name<T>())));
      }
  }

  template <class T, class stream, class str = std::basic_string<typename stream::char_type>>
  void textual_output(stream &s, const nested_imitation_struct<T>& out, const str& separator = " ")
  {
    flat_imitation_struct<T> imit = out;
    internals::text_out_iter(s, imit, separator);
    if(s.fail())
      {
        exceptions::throw_exception(exceptions::output_error(std::string("Cannot output nested imitation of type ") + std::string(compile_time_type_name<T>())));
      }
  }

  template <class T, class stream>
  void textual_input(stream &s, nested_imitation_struct<T>& in)
  {
    flat_imitation_struct<T> imit;
    internals::text_in_iter(s, imit);
    in = imit;
    if(s.fail())
      {
        exceptions::throw_exception(exceptions::input_error(std::string("Cannot input nested imitation of type ") + std::string(compile_time_type_name<T>())));
      }
  }

///\endcond

/*!
\brief Outputs an object in binary mode.

\tparam T the type of the object being output.

\tparam stream Something akin to an `ostream`, to which bytes can be output.

\throw In case an output error is encountered, uses g24_lib::exceptions::throw_exception
       to possibly throw a g24_lib::exceptions::output_error.

\remark The behaviour of this function for user defined classes may be more simply "overloaded"
        by providing a `binary_output` member function that takes \p s as argument,
        which will be used whenever available.
        
\remark For classes that satisfy `std::is_trivially_copyable`
        (which are defined by the standard as able to be serialized in a binary format),
        the byte sequence that corresponds to the object \p out is written to the stream.
        
\remark For classes that do not have a `binary_output` member function or
        are not trivially copyable, a `g24_lib::flat_imitation_struct` is constructed and
        every member is written to the stream as a sequence of bytes.
        
\pre \p stream must have a valid member function with signature
        `void write(const char *origin, const size_t n)` that writes `n` bytes starting from
        the memory location pointed by `origin`.

\warning As with all binary serialization procedures, the output will be dependent
         on the endianness of the system in use, the sizes of the different native types
         and the padding added to trivially copyable classes.
         For the same program running on the same system, 
         there will be no problems, but portability may be a significant concern.  

*/
  template <class T, class stream>
  void binary_output(stream &s, const T& out)
  {
    if constexpr(internals::specifies_binary_output<T>())
      {
        out.binary_output(s);
      }
    else if constexpr (std::is_trivially_copyable_v<T>)
      {
        s.write((char*) &out, sizeof(T));
      }
    else
      {
        flat_imitation_struct<T> imit = out;
        internals::bin_out_iter(s, imit);
      }
    if(s.fail())
      {
        exceptions::throw_exception(exceptions::output_error(std::string("Cannot binarily output object of type ") + std::string(compile_time_type_name<T>())));
      }
  }

/*!

\brief Inputs an object in binary mode.

\tparam T the type of the object being input.

\tparam stream Something akin to an `istream`, to which bytes can be input.

\throw In case an input error is encountered, uses g24_lib::exceptions::throw_exception
       to possibly throw a g24_lib::exceptions::input_error. The input object \p in may be in an invalid state.

\remark The behaviour of this function for user defined classes may be more simply "overloaded"
        by providing a `binary_input` member function that takes \p s as argument,
        which will be used whenever available.
        
\remark For classes that satisfy `std::is_trivially_copyable`
        (which are defined by the standard as able to be serialized in a binary format),
        the byte sequence that corresponds to the object \p in is read from the stream.
        
\remark For classes that do not have a `binary_input` member function or
        are not trivially copyable, a `g24_lib::flat_imitation_struct` is constructed,
        every member is read from the stream as a sequence of bytes
        and the new value of \p in will come from a new \p T constructed from the imitation struct.
        
\pre \p stream must have a valid member function with signature
        `void read(char *dest, const size_t n)` that reads `n` bytes starting from
        the memory location pointed by `origin`.

\warning As with all binary serialization procedures, the expected input will be dependent
         on the endianness of the system in use, the sizes of the different native types
         and the padding added to trivially copyable classes.
         For the same program running on the same system, 
         there will be no problems, but portability may be a significant concern.  

*/
  template <class T, class stream>
  void binary_input(stream &s, T& in)
  {
    if constexpr(internals::specifies_binary_input<T>())
      {
        in.binary_input(s);
      }
    else if constexpr (std::is_trivially_copyable_v<T>)
      {
        s.read((char*) &in, sizeof(T));
      }
    else
      {
        flat_imitation_struct<T> imit;
        internals::bin_in_iter(s, imit);
        in = imit.to_type();
      }
    if(s.fail())
      {
        exceptions::throw_exception(exceptions::input_error(std::string("Cannot binarily input object of type ") + std::string(compile_time_type_name<T>())));
      }
  }
///\cond HIDDEN_SYMBOLS
  template <class T, class stream>
  void binary_output(stream &s, const flat_imitation_struct<T>& out)
  {
    internals::bin_out_iter(s, put);
    if(s.fail())
      {
        exceptions::throw_exception(exceptions::output_error(std::string("Cannot binarily output imitation of type ") + std::string(compile_time_type_name<T>())));
      }
  }

  template <class T, class stream>
  void binary_input(stream &s, flat_imitation_struct<T>& in)
  {
    internals::bin_in_iter(s, in);
    if(s.fail())
      {
        exceptions::throw_exception(exceptions::input_error(std::string("Cannot binarily input imitation of type ") + std::string(compile_time_type_name<T>())));
      }
  }

  template <class T, class stream>
  void binary_output(stream &s, const nested_imitation_struct<T>& out)
  {
    flat_imitation_struct<T> imit = out;
    internals::bin_out_iter(s, imit);
    if(s.fail())
      {
        exceptions::throw_exception(exceptions::input_error(std::string("Cannot binarily output nested imitation of type ") + std::string(compile_time_type_name<T>())));
      }
  }

  template <class T, class stream>
  void binary_input(stream &s, nested_imitation_struct<T>& in)
  {
    flat_imitation_struct<T> imit;
    internals::bin_in_iter(s, imit);
    in = imit;
    if(s.fail())
      {
        exceptions::throw_exception(exceptions::input_error(std::string("Cannot binarily input nested imitaiton of type ") + std::string(compile_time_type_name<T>())));
      }
  }
    
///\endcond
}

/*!
\fn template <class stream, class T> stream& operator<< (stream &s, const T& out)

\brief Provides a generic output operator based on `g24_lib::textual_output`.

\details It is only available if `G24_LIB_DEFAULT_I_O_OPERATORS` is `true`.

*/
template <class T, int dummy = sizeof(T)>
typename std::enable_if<g24_lib::Definitions::default_I_O_operators && (dummy > 0), std::ostream>::type&
operator<< (std::ostream &s, const T& out)
{
  g24_lib::textual_output(s, out);
  return s;
}

/*!
\fn template <class stream, class T> stream& operator>> (stream &s, T& in)

\brief Provides a generic input operator based on `g24_lib::textual_output`.

\details It is only available if `G24_LIB_DEFAULT_I_O_OPERATORS` is `true`.

*/
template <class T, int dummy = sizeof(T)>
typename std::enable_if<g24_lib::Definitions::default_I_O_operators && (dummy > 0), std::ostream>::type&
operator>> (std::ostream &s, T& in)
{
  g24_lib::textual_input(s, in);
  return s;
}

#endif

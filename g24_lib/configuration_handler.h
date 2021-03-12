#ifndef G24_LIB_CONFIGURATION_HANDLER
#define G24_LIB_CONFIGURATION_HANDLER

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

\file configuration_handler.h

\brief Implements functionalities that enable the users of the library to customize
       some of its behaviour and/or default parameters.

\author Nuno Fernandes (main coder, current maintainer)

*/




namespace g24_lib
{
  /*!
    \brief Allows customization of the library's behaviour by declaring member typedefs/type aliases.
    
    \detail Supported aliases:
              - \c default_I_O_operators, should be `std::true_type` or `std::false_type`
              - \c elementwise_point_operators, should be `std::true_type` or `std::false_type`
              - \c throw_exceptions, should be `std::true_type` or `std::false_type`
              - \c print_exceptions, should be `std::true_type` or `std::false_type`
              - \c print_memory_debug_info, should be `std::true_type` or `std::false_type`
              - \c check_for_CUDA_kernel_errors, should be `std::true_type` or `std::false_type`
              - \c default_unsigned_indexer, should be a type
              - \c default_signed_indexer, should be a type
              - \c default_fixed_size, should be an `std::integral_constant`
                of a type convertible to `default_unsigned_indexer` and appropriate value
              - \c default_floating_point, should be a type.
              
    \remark The user can specify only some of the aliases, with the default
            values being taken if the alias is absent.
            The full default configuration would be equivalent to using:
~~~~~~{cpp}
class g24_lib::Configuration
{
  public:
    using default_I_O_operators = std::false_type;
    using elementwise_point_operators = std::false_type;
    using throw_exceptions = std::true_type;
    using print_exceptions = std::true_type;
    using print_memory_debug_info = std::false_type;
    using check_for_CUDA_kernel_errors = std::false_type;
    using default_unsigned_indexer = size_t;
    using default_signed_indexer = ptrdiff_t;
    using default_fixed_size = std::integral_constant<size_t, 3>;
    using default_floating_point = double;
};
~~~~~~
    \remark Obviously, this will be equivalent to `class Configuration {};`,
            since the default values are taken when the members are not aliased.
    
    
    \sa g24_lib::Definitions
  */
  class Configuration;
  
  /*!
    \brief Holds the definitions of the library, which can be changed by
           declaring the relevant members in a class `g24_lib::Configuration`.
    
    \sa g24_lib::Configuration
  */
  struct Definitions
  {
  
    private:
    
    G24_LIB_TYPEDEF_CHECKER(default_I_O_operators , std::false_type);
    G24_LIB_TYPEDEF_CHECKER(elementwise_point_operators , std::false_type);
    G24_LIB_TYPEDEF_CHECKER(throw_exceptions , std::true_type);
    G24_LIB_TYPEDEF_CHECKER(print_exceptions , std::true_type);
    G24_LIB_TYPEDEF_CHECKER(print_memory_debug_info , std::false_type);
    G24_LIB_TYPEDEF_CHECKER(check_for_CUDA_kernel_errors , std::false_type);
    G24_LIB_TYPEDEF_CHECKER(default_unsigned_indexer , size_t);
    G24_LIB_TYPEDEF_CHECKER(default_signed_indexer , ptrdiff_t);
    G24_LIB_TYPEDEF_CHECKER(default_fixed_size , std::integral_constant<size_t G24_LIB_COMMA_HACK 3>);
    //The G24_LIB_COMMA_HACK is so the comma in the macro is properly expanded.
    G24_LIB_TYPEDEF_CHECKER(default_floating_point , double);
    
    //These macros simply construct appropriate functions to check for
    //the existence of the typedef (and the corresponding type itself)
    
    public:
    /*!
      \brief Controls if `<<` and `>>` operators will be generated automatically 
             using #binary_input and #binary_output. Default is \b `false`.

      \remark The default value is false since, in general, the limited compile time 
              reflection one can achieve with the current C++ standard might not work 
              with user-defined classes, in which case the unknowing user might incurr 
              in compilation errors.
              
      \sa See \ref class_info for details on the limitations 
              of compile time reflection.
    */
    static constexpr bool default_I_O_operators = default_I_O_operators_t_type<Configuration>::value;
    
    
    /*!

      \brief Controls if `*` and `/` operators will be defined between two \ref point 
             or \ref fspoint as elementwise multiplications or divisions. Default is \b `false`.

      \remark The default value is false because it is mathematically unsound 
              to define such elementwise operations with the same notation 
              and there might be some programming errors that will be masked 
              (multiplying two vectors when one wanted to multiply a vector by a scalar). 
              However, for using, for instance, arrays of \ref fspoint in a linear equation solver, 
              this might come in very handy, hence the option being given to the user.

    */
    static constexpr bool elementwise_point_operators = elementwise_point_operators_t_type<Configuration>::value;
    
    /*!

      \brief Controls if exceptions are thrown. Default is \b `true`.


      \remark There are, and, for the forseeable future, always will be tradeoffs 
              involved in the use of exceptions, depending on the specifics 
              of the platform and hardware under use. For what one could assume 
              will be the most common usage of this library, 
              exceptions should not pose a significant issue since 
              only the exceptional path results in performance degradation 
              (slight increases in code size notwithstanding), 
              but this might not always be the case.

      \sa See #throw_exception for the changes in program behaviour depending on the value of `throw_exceptions`.

    */
    static constexpr bool throw_exceptions = throw_exceptions_t_type<Configuration>::value;
    
    /*!

      \brief Controls if a message describing the exception is printed to `stderr`. Default is \b `true`.

      \remark This is merely a case of programmer preference and/or convenience. 
              Obviously, if exceptions are actually being thrown, 
              one can always use their `what()` method to access the message 
              and log or output it in the desired way.

      \sa See #throw_exception for the changes in program behaviour depending on the value of `G24_LIB_PRINT_EXCEPTIONS`.

    */
    static constexpr bool print_exceptions = print_exceptions_t_type<Configuration>::value;
    
    
    /*!

      \brief Controls debug output related to memory allocations. Default is \b `false`.

      \remark This might be useful to quickly diagnose any extraneous allocations or memory leaks 
              without recourse to an external utility (such as a debugger or a memory sanitizer). 
              Obviously, for normal program usage, the output will not be desirable, 
              hence the default value.

      \sa See \ref simple_array and \ref managed_object for more details on the output.

    */
    static constexpr bool print_memory_debug_info = print_memory_debug_info_t_type<Configuration>::value;
    
    /*!

    \brief Controls synchronization after most \c CUDA kernel invocations, 
           to detect any errors as soon as possible. Default is \b `false`.

    \remark This only has any effect if \c CUDA is available and being used. 
            Since the synchronization requires the program
            to wait until all threads are finished, 
            the default is false to maximize performance. 
            However, without that explicit synchronization, 
            kernel errors might be detected only at a later point, 
            which can hinder debugging.
    */
    static constexpr bool check_for_CUDA_kernel_errors = check_for_CUDA_kernel_errors_t_type<Configuration>::value;
    
    /*!

      \brief Specifies the type to be used as the default unsigned indexer 
             (for container sizes, absolute positions and the like). Default is \b `size_t`.

      \pre The type must have addition, subtraction, multiplication, division, modulus and comparison operators 
           and support <b>at least</b> non-negative values.

      \remark Signed integer types are also a valid choice, since they support non-negative values. 
              
      \warning Equality must make sense in all situations, so floating point types should not be used.

    */
    using default_unsigned_indexer = default_unsigned_indexer_t_type<Configuration>;
    
    
    /*!

      \brief Specifies the type to be used as the default signed indexer 
             (mainly for relative positions or position differences). 
             Default is \b `ptrdiff_t`.

      \pre The type must have addition, subtraction, multiplication, division, modulus and comparison operators 
           and support both positive and negative values (as well as zero).

      \remark Unsigned integer types <b>are not</b> a valid choice, since they do not support negative values.
              
      \warning Equality must make sense in all situations, so floating point types should not be used.

    */
    using default_signed_indexer = default_unsigned_indexer_t_type<Configuration>;
    
    /*!

    \brief Specifies the default size for fixed size objects such as \ref g24_lib::fspoint or \ref g24_lib::ndview. Default is \b 3.

    \pre This macro must be evaluated to a valid initializer of an \ref g24_lib::unsigned_indexer.

    \remark Given the constraints placed on \ref g24_lib::Definitions::default_unsigned_indexer, the default value 
            should be sufficiently sane since one could assume it is constructible from an integer. 
            If the user has made a more exotic choice, it is up to the user's responsibility 
            to ensure a proper default value has been set...

    */
    static constexpr default_unsigned_indexer default_fixed_size = default_fixed_size_t_type<Configuration>::value;
    
      /*!

        \brief Specifies the type to be used as the default numeric type for finite difference
               coefficients (and elsewhere, if/when necessary). Default is \b `double`.

        \pre The type must support multiplication and division by the relevant types in the finite differences or equation solvers.

        \remark Default chosen merely by convenience; in practice, if we are taking finite differences
                of an array of type `T`, the numeric factor type `factorT` 
                must only ensure that the return type of `operator * (T, factorT)` 
                has addition between itself and, when divided by another `factorT`, 
                yields (something that can be converted to) a `T`. \n Using 
                `double` seems the most sensible choice given the expected scope of this library,
                though one must take care if GPU interoperatability is desired that `float`
                tends to be more performant there.

      */
    using default_floating_point = default_floating_point_t_type<Configuration>;
    
#ifdef G24_LIB_VARIADIC_STRUCTURED_BINDINGS_SIZE

#if MACKRO_EVAL(MACKRO_IS_GREATER(G24_LIB_VARIADIC_STRUCTURED_BINDINGS_SIZE, (0,0,0,0,0,0,0,1)))
    static constexpr default_unsigned_indexer 
          max_variadic_structured_binding_size = MACKRO_NUM_TO_VALUE(G24_LIB_VARIADIC_STRUCTURED_BINDINGS_SIZE);
#else
    static constexpr default_unsigned_indexer
          max_variadic_structured_binding_size = 128;
#endif

#else
    static constexpr default_unsigned_indexer
          max_variadic_structured_binding_size = 128;
#endif

      /*!
        \var max_variadic_structured_binding_size
        
        \brief Specified the maximum number of member variables
               supported by the library's "variadic" strucutred bindings. Default is `128`.

        \warning Since the only way that the C++ standards (up to C++20 at the time of writing)
                 allow this to be implemented means hard-coding all the possibilities up to a given size,
                 there are essentially two approaches: the reasonable one, in which a file is generated
                 defining the variadic structured bindings, and the outright crazy one, which relies on
                 preprocessing-time cycles to output the same definitions
                 without the need for a pre-build step. The library contains a generated file for variadic
                 structured bindings for structs up to 128 members; if the user desires more,
                 the macro `G24_LIB_VARIADIC_STRUCTURED_BINDINGS_SIZE` may be defined,
                 in which case (provided the preprocessing-time tricks library `Mad<ro Trid<s` by the author
                 is available) the preprocessing-time cycle is invoked (at a potentially
                 significant cost in terms of memory and preprocessing time)
                 to define variadic structured bindings up to the specified number of members.
                 
        \remark For most use cases, the default value is more than fine,
                since a struct with more than 128 members should be a very rare
                occurence. Nevertheless, in the spirit of absolute generality
                that pervades this whole library, the option of specifing a larger size
                and generating it through preprocessing-time cycles is given.
                However, the author cannot express emphatically enough that
                <b>the preprocessing time cycles can increase the memory requirements
                for preprocessing to several gigabytes and the preprocessing time
                for up to several minutes</b>, even for an arguably reasonable demand
                of variadic structured bindings for up to 256 members, which means
                that the usefulness of this definition is quite limited: in any case,
                it would be enormously faster to just generate a file
                with variadic structured bindings up to the desired size.
                Still, given enough time and memory, it is theoretically possible
                to achieve any arbitrary size, which was the author's goal.

        \sa `G24_LIB_VARIADIC_STRUCTURED_BINDINGS_SIZE`
      */

  };
}

#endif

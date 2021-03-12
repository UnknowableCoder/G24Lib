#ifndef G24_LIB_PRELIMINARY_MACROS
#define G24_LIB_PRELIMINARY_MACROS

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
\file preliminary_macros.h

\brief Implements some useful macros for the code itself.

\author Nuno Fernandes (main coder, current maintainer)

\author Gonçalo Vaz (past auxiliary coder and tester)
*/


#if __CUDA_ARCH__
#define CUDA_AVAILABLE 1
#elif __CUDA__
#define CUDA_AVAILABLE 1
#else
#define CUDA_AVAILABLE 0
#endif

//For maximum interoperatability between CUDA and normal code.
#ifndef CUDA_HOS_DEV
#if CUDA_AVAILABLE
#define CUDA_HOS_DEV __host__ __device__
#else
#define CUDA_HOS_DEV
#endif
#endif

#ifndef CUDA_ONLY_HOS
#if CUDA_AVAILABLE
#define CUDA_ONLY_HOS __host__
#else
#define CUDA_ONLY_HOS
#endif
#endif

#ifndef CUDA_ONLY_DEV
#if CUDA_AVAILABLE
#define CUDA_ONLY_DEV __device__
#else
#define CUDA_ONLY_DEV
#endif
#endif



/*! \def CUDA_AVAILABLE

    \brief Evaluates to \b 1 if \c CUDA is available, \b 0 otherwise.
*/

/*! \def CUDA_HOS_DEV

    \brief If \c CUDA is available, evaluates to the attributes `__host__ __device__`. Otherwise, to nothing.
    
    \remark This is useful to ensure code will compile even without \c CUDA.
*/

/*! \def CUDA_ONLY_HOS

    \brief If \c CUDA is available, evaluates to the attribute `__host__`. Otherwise, to nothing.
    
    \remark This is useful to ensure code will compile even without \c CUDA.
*/

/*! \def CUDA_ONLY_DEV

    \brief If \c CUDA is available, evaluates to the attribute `__device__`. Otherwise, to nothing.
    
    \remark This is useful to ensure code will compile even without \c CUDA.
*/

/*! \def G24_LIB_VARIADIC_STRUCTURED_BINDINGS_SIZE

    \brief Defines a maximum size for variadic structured bindings. If not defined, the default value is 128.
    
    \pre Due to the constraints of the implementation, this must be given in a reversed binary
         representation of the number: `(0,1)` would give variadic structured bindings up to 2,
         `(0,1,0,0,1)` up to 18, and so on.
    
    \pre Defining this value requires availability of the `Mad<ro Trid<s` library
         to enable preprocessing-time cycles.
    
    \warning Preprocessing-time cycles may entail significant memory requirements
             and a larger preprocessing time.
    
    \sa `g24_lib::Definitions::max_variadic_structured_binding_size`
*/


#ifndef G24_LIB_CLEAN_UP_MACROS
/*!

\brief Controls if all the macros defined in the library will be `#undef` ined 
       after use. Default is \b `false`.

\remark The default value is false since some of these macros might be useful
        and all of them are prefixed by `G24_LIB_`.

\remark But we still give this option in case there is a strange conflict happening
        or the user somehow is an anti-macro fundamentalist.

*/
#define G24_LIB_CLEAN_UP_MACROS 0
#endif

/*!
  \brief Provides a way to check for the existence of a \b static member function.
  
  \param FUNCNAME The static member function to check for.
    
  \warning Declares `FUNCNAME_sf_checker` and `FUNCNAME_sf_exists` at the current scope.
           
  \remark Just use `FUNCNAME_sf_exists<T>` to check if type `T` has the relevant static member function.
*/
#define G24_LIB_STATIC_FUNC_CHECKER(FUNCNAME)                                \
template<class T> inline static constexpr                                    \
auto FUNCNAME ## _sf_checker(T*) -> decltype(&T:: FUNCNAME);                 \
template<class T> inline static constexpr                                    \
void FUNCNAME ## _sf_checker(...);                                           \
template <class T> inline static constexpr                                   \
bool FUNCNAME ## _sf_exists = std::is_pointer_v<decltype( FUNCNAME ## _sf_checker<T>(nullptr) )>;


/*!
  \brief Provides a way to check for the existence of a \b non-static member function.
  
  \param FUNCNAME The member function to check for.
    
  \warning Declares `FUNCNAME_f_checker` and `FUNCNAME_f_exists` at the current scope.
           
  \remark Just use `FUNCNAME_f_exists<T>` to check if type `T` has the relevant member function.
*/
#define G24_LIB_FUNC_CHECKER(FUNCNAME)                                      \
template<class T> inline static constexpr                                   \
auto FUNCNAME ## _f_checker(T*) -> decltype(&T:: FUNCNAME);                 \
template<class T> inline static constexpr                                   \
void FUNCNAME ## _f_checker(...);                                           \
template <class T> inline static constexpr                                  \
bool FUNCNAME ## _f_exists = std::is_member_pointer_v<decltype( FUNCNAME ## _f_checker<T>(nullptr) )>;

/*!
  \brief Provides a way to check for the existence of a member typedef or type alias
         (and to get the corresponding type).
         
  \param MEMBERNAME The member typedef/type alias to check for.
  
  \param INVALID_TYPE A type to be attributed to `MEMBERNAME_t_checker`
                      whenever the member typedef/type alias is not defined.
                      
  \warning Declares `MEMBERNAME_t_checker`, `MEMBERNAME_t_type` and `MEMBERNAME_t_exists` at the current scope.
  
  \remark Just use `MEMBERNAME_t_exists<T>` to check if type `T` has the relevant typedef/type alias
          and `MEMBERNAME_t_type<T>` to get the type, if existent, or `INVALID_TYPE`, if not.
*/
#define G24_LIB_TYPEDEF_CHECKER(MEMBERNAME, INVALID_TYPE)                    \
template<class T> inline static constexpr                                    \
auto MEMBERNAME ## _t_checker(T*) -> decltype(typename T:: MEMBERNAME{});    \
template<class T> inline static constexpr                                    \
INVALID_TYPE MEMBERNAME ## _t_checker(...);                                  \
template <class T>                                                           \
using MEMBERNAME ## _t_type = decltype( MEMBERNAME ## _t_checker<T>(nullptr) );  \
template <class T> inline static constexpr                                   \
bool MEMBERNAME ## _t_exists = !std::is_same_v<MEMBERNAME ## _t_type<T>, INVALID_TYPE>; \



/*!
  \brief Provides a way to check for the existence of a \b static member variable
         (and to get the corresponding type and value).
         
  \param MEMBERNAME The static member variable to check for.
    
  \param INVALID_INIT The expression to be used to initialize the invalid value,
                      with parenthesis, brackets, whatever is necessary to perform the initialization.
                      (In essence, it returns `INVALID_INIT`).
  
  \warning Declares `MEMBERNAME_sm_checker`, `MEMBERNAME_sm_type`, `MEMBERNAME_sm_value`
           and `MEMBERNAME_sm_exists` at the current scope.
  
  \remark Just use `MEMBERNAME_sm_exists<T>` to check if type `T` has the relevant static variable,
          `MEMBERNAME_sm_type<T>` to get the type, if existent, or `INVALID_TYPE`, if not,
          and `MEMBERNAME_sm_value<T>` to get the value.
*/
#define G24_LIB_STATIC_MEMBER_CHECKER(MEMBERNAME, INVALID_INIT)              \
template<class T> inline static constexpr                                    \
auto MEMBERNAME ## _sm_checker(T*) -> decltype(T:: MEMBERNAME) { return T:: MEMBERNAME; } \
template<class T> inline static constexpr                                    \
void MEMBERNAME ## _sm_checker(...);                                         \
template <class T> inline static constexpr                                   \
bool MEMBERNAME ## _sm_exists = !std::is_void_v<decltype(MEMBERNAME ## _sm_checker<T>(nullptr))>; \
template <class T>                                                           \
using MEMBERNAME ## _sm_type = std::conditional_t<!MEMBERNAME ## _sm_exists<T>, \
                                                  decltype(INVALID_INIT),    \
                                                  decltype(MEMBERNAME ## _sm_checker<T>(nullptr))>; \
template <class T> inline static constexpr                                   \
MEMBERNAME ## _sm_type<T> MEMBERNAME ## _sm_results () { if constexpr (MEMBERNAME ## _sm_exists<T>) \
                                                    { return (INVALID_INIT); } \
                                                      else { return MEMBERNAME ## _sm_checker<T>(nullptr) ; } } \
template <class T> inline static constexpr                                   \
MEMBERNAME ## _sm_type<T> MEMBERNAME ## _sm_value = MEMBERNAME ## _sm_results<T>(); \


/*!
  \brief Provides a way to check for the existence of a \b non-static member variable
         (and to get the corresponding type).
         
  \param MEMBERNAME The member variable to check for.
  
  \remark Just use `MEMBERNAME_m_exists<T>` to check if type `T` has the relevant member variable,
          `MEMBERNAME_m_type<T>` to get the type, if existent, or `void`, if not.
*/
#define G24_LIB_MEMBER_CHECKER(MEMBERNAME, INVALID_TYPE, INVALID_INIT)       \
template<class T> inline static constexpr                                    \
auto MEMBERNAME ## _m_checker(T*) -> decltype(T:: MEMBERNAME);               \
template<class T> inline static constexpr                                    \
void MEMBERNAME ## _m_checker(...);                                          \
template <class T>                                                           \
using MEMBERNAME ## _m_type = decltype( MEMBERNAME ## _m_checker<T>(nullptr) ); \
template <class T> inline static constexpr                                   \
bool MEMBERNAME ## _m_exists = !std::is_void_v<MEMBERNAME ## _m_type<T>>;    \


#define G24_LIB_COMMA_HACK ,
//This is to allow for commas in macro parameters without parentheses.

#endif

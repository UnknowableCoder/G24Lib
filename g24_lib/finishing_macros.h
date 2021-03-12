#ifndef G24_LIB_FINISHING_MACROS
#define G24_LIB_FINISHING_MACROS

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


#if G24_LIB_CLEAN_UP_MACROS

#undef CUDA_AVAILABLE
#undef CUDA_HOS_DEV
#undef CUDA_ONLY_HOS
#undef CUDA_ONLY_DEV


#undef G24_LIB_STATIC_FUNC_CHECKER
#undef G24_LIB_FUNC_CHECKER
#undef G24_LIB_TYPEDEF_CHECKER
#undef G24_LIB_STATIC_MEMBER_CHECKER
#undef G24_LIB_MEMBER_CHECKER
#undef G24_LIB_COMMA_HACK

#undef G24_LIB_CUDA_ERRCHECK


#undef G24_LIB_CLEAN_UP_MACROS


#endif

#endif
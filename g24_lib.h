#ifndef G24_LIB
#define G24_LIB

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
\file g24_lib.h

\brief General inclusions and definitions for G24Lib

\author Nuno Fernandes (main coder, current maintainer)

\author Gonçalo Vaz (past auxiliary coder and tester)
*/

///\cond HIDDEN_SYMBOLS

#include <iostream>
#include <fstream>
//For input/output.

#include <vector> //vector
#include <cstdlib> //size_t
#include <cstring> //memcpy
#include <cmath> //Math
#include <limits> //Max, min, NaN...
#include <algorithm> //min, max, clamp
#include <cctype> //std::is_digit.
#include <string> //strings
#include <iomanip> //Some pretty output with ndview
#include <type_traits> //std::decay
#include <utility> //For several tricks in compile_time_reflection
#include <variant> //Idem.
#include <array> //For possible initialization of points and fspoints
#include <string_view> //For compile-time type name generation

///\endcond


/*!

\brief The namespace where all the library resides.

*/
namespace g24_lib
{
  /*!
    \brief A namespace where several implementation details are stored.
           When possibly relevant, they are documented here,
           but, being implementation details, they should not be used
           by the end users!
  */
  namespace internals
  {
  }
}

#include "g24_lib/preliminary_macros.h"
//This must come first because it provides some useful macros
//to tie everything else together.

#include "g24_lib/configuration_handler.h"

#include "g24_lib/general_helpers.h"

#include "g24_lib/CUDA_utilities.h"

#include "g24_lib/exceptions.h"
//This is to ensure it works with CUDA...


#include "g24_lib/compile_time_utilities.h"
#include "g24_lib/variadic_structured_bindings.h"
#include "g24_lib/serialization_helpers.h"

#include "g24_lib/memory_manager.h"

#include "g24_lib/fspoint.h"
#include "g24_lib/point.h"
#include "g24_lib/coll.h"
#include "g24_lib/comp.h"

#include "g24_lib/simple_array.h"
#include "g24_lib/managed_object.h"
#include "g24_lib/carried_bool_vector.h"
#include "g24_lib/split_array.h"

                                          
#include "g24_lib/parallelism.h"

#include "g24_lib/ndview.h"

#include "g24_lib/fin_diff_coeffs.h"
#include "g24_lib/derivatives.h"

#include "g24_lib/interpol.h"

#include "g24_lib/deferred_ops.h"

#include "g24_lib/temporal_evolver.h"

#include "g24_lib/lineq_solver.h"

#include "g24_lib/finishing_macros.h"
//Some de-definitions to clean up the macros defined in the library
//in case the user requests it through G24_LIB_CLEAN_UP_MACROS.

#endif

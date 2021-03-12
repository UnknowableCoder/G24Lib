#ifndef G24_LIB_CUDA_HELPERS
#define G24_LIB_CUDA_HELPERS

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

#if CUDA_AVAILABLE
#include <stdio.h>
#include <cuda.h>
#include <cuda_runtime.h>
#endif

/*!

\file CUDA_utilities.h

\brief Provides two or three useful definitions to ensure good CUDA interoperatability
       and possibly increase the expressiveness of CUDA-related code.
       

\author Nuno Fernandes (main coder, current maintainer)

*/

namespace g24_lib
{


#if CUDA_AVAILABLE

  /*!
    \brief Provides a way to report errors in \c CUDA kernels.
    
    \remark Standard CUDA definition that can be found almost everywhere...
  */
  inline void gpuAssert(cudaError_t code, const char *file, int line, bool abort=true)
  {
    if (code != cudaSuccess)
      {
        fprintf(stderr,"GPUassert: %s %s %d\n", cudaGetErrorString(code), file, line);
        if (abort) exit(code);
      }
  }

/*!
  \brief Wraps up a `g24_lib::gpuAssert` using `__FILE__` and `__LINE__`
         to improve error reporting (and debugging) capabilities.
*/
#define G24_LIB_CUDA_ERRCHECK(ans) { gpuAssert((ans), __FILE__, __LINE__); }

#else


#define G24_LIB_CUDA_ERRCHECK(ans) { }

#endif

///\cond HIDDEN_SYMBOLS
  namespace internals
  {
    template<class C> struct has_to_CUDA
    {
    private:
      template<class T>
      static constexpr auto check1(T* t) -> typename std::is_void<decltype(t->to_CUDA())>;

      template<class>
      static constexpr std::true_type check1(...);
      /*
      template<class T>
      static constexpr auto check2(T* t) -> typename std::is_void<decltype(to_CUDA(*t))>;*/

      template<class>
      static constexpr std::true_type check2(...);

      typedef decltype(check1<C>(0)) type1;
      typedef decltype(check2<C>(0)) type2;

    public:
      static constexpr bool value1 = !(type1::value);
      static constexpr bool value2 = !(type2::value);
    };
    
  }
///\endcond

/*!
  \brief Provides a form of \p obj that is suitable to be operated on in a \c CUDA kernel.
  
  \remark This will work with any class that has defined a `to_CUDA()` method.
*/
  template <class T>
  auto to_CUDA(const T& obj)
  {
    if constexpr(internals::has_to_CUDA<std::decay_t<T>>::value1)
      {
        return obj.to_CUDA();
      }
    else if constexpr(internals::has_to_CUDA<std::decay_t<T>>::value2)
      {
        return to_CUDA(obj);
      }
    else
      {
        return obj;
      }
  }
  
/*!
  \brief Provides a form of \p obj that is suitable to be operated on in a \c CUDA kernel.
  
  \remark This will work with any class that has defined a `to_CUDA()` method.
*/
  template <class T>
  auto to_CUDA(T& obj) 
  {
    if constexpr(internals::has_to_CUDA<std::decay_t<T>>::value1)
      {
        return obj.to_CUDA();
      }
    else if constexpr(internals::has_to_CUDA<std::decay_t<T>>::value2)
      {
        return to_CUDA(obj);
      }
    else
      {
        return obj;
      }
  }
  
  /*!
      \brief Specifies the type of the CUDA-compatible version of \p T.
  */
  template <class T>
  using to_CUDA_t = decltype(to_CUDA(std::declval<T>()));

}

#endif

#ifndef G24_LIB_EXCEPTIONS
#define G24_LIB_EXCEPTIONS

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

\file exceptions.h

\brief A custom implementation of exceptions to allow for interoperatability with \c CUDA.

\author Nuno Fernandes (main coder, current maintainer)

\author Gonçalo Vaz (past auxiliary coder and tester)

*/

namespace g24_lib
{
  /*!
    \brief Holds our custom exception objects to allow for interoperatability with \c CUDA.
  */
  namespace exceptions
  {
    /*!
    \brief A simple implementation of a strncpy-like function,
           with automatic null-termination at the end
           even if the original string is truncated.
           
    \remark This is implemented here to minimize dependencies and ensure CUDA interoperatability.
    */
    CUDA_HOS_DEV inline void simple_copy(char * dest, const char* origin, const g24_lib::Definitions::default_unsigned_indexer num)
    {
      g24_lib::Definitions::default_unsigned_indexer i;
      for(i = 0; i < num; ++i)
        {
          dest[i] = origin[i];
          if (dest[i] == '\0')
            {
              break;
            }
        }
      if (i == num)
        {
          dest[num-1] = '\0';
        }
    }
    
    /*!
      \brief The class that serves as a base to all other exceptions.
    */
    struct base_exception
    {
      static constexpr g24_lib::Definitions::default_unsigned_indexer message_size = 64;
    protected:
      char desc[message_size];
    public:
      CUDA_HOS_DEV base_exception (const char* text)
      {
        simple_copy(desc, text, message_size);
      }
      CUDA_HOS_DEV base_exception (const std::string &text)
      {
        simple_copy(desc, text.c_str(), message_size);
      }
      CUDA_HOS_DEV base_exception () noexcept 
      {
        desc[0] = '\0';
      }
      CUDA_HOS_DEV base_exception (const base_exception& other) noexcept
      {
        simple_copy(desc, other.desc, message_size);
      }
      CUDA_HOS_DEV base_exception& operator= (const base_exception& other) noexcept
        {
         if(&other != this)
           {
             simple_copy(desc, other.desc, message_size);
           }
         return (*this);
        }
        CUDA_HOS_DEV virtual ~base_exception()
      {
      };
      CUDA_HOS_DEV virtual const char* what() const noexcept
      {
        return desc;
      }
    };
    
    /*!
      \brief Exception thrown when an input operation cannot determine the array size.
    */
    struct array_length_misread: public base_exception
    {
      CUDA_HOS_DEV array_length_misread (const char* text)
      {
        simple_copy(desc, text, message_size);
      }
      CUDA_HOS_DEV array_length_misread (const std::string &text)
      {
        simple_copy(desc, text.c_str(), message_size);
      }
    };
    
    /*!
      \brief Exception thrown when a bounds checking operation tries to access unallocated memory.
    */
    struct out_of_bounds_access: public base_exception
    {    
      CUDA_HOS_DEV out_of_bounds_access (const char* text)
      {
        simple_copy(desc, text, message_size);
      }
      CUDA_HOS_DEV out_of_bounds_access (const std::string &text)
      {
        simple_copy(desc, text.c_str(), message_size);
      }
    };
    
    /*!
      \brief Exception thrown when trying to take a derivative that's not (yet) supported by the library.
    */
    struct undefined_derivative: public base_exception
    {    
      CUDA_HOS_DEV undefined_derivative (const char* text)
      {
        simple_copy(desc, text, message_size);
      }
      CUDA_HOS_DEV undefined_derivative (const std::string &text)
      {
        simple_copy(desc, text.c_str(), message_size);
      }
    };
    
    /*!
      \brief Exception thrown when some error or incompatilibity is detected in the dimensions of some object.
    */
    struct undefined_dimensions: public base_exception
    {    
      CUDA_HOS_DEV undefined_dimensions (const char* text)
      {
        simple_copy(desc, text, message_size);
      }
      CUDA_HOS_DEV undefined_dimensions (const std::string &text)
      {
        simple_copy(desc, text.c_str(), message_size);
      }
    };
    
    /*!
      \brief Exception thrown when trying to calculate a mathematically invalid expression, 
             such as a cross product in two dimensions.
    */
    struct undefined_operation: public base_exception
    {    
      CUDA_HOS_DEV undefined_operation (const char* text)
      {
        simple_copy(desc, text, message_size);
      }
      CUDA_HOS_DEV undefined_operation (const std::string &text)
      {
        simple_copy(desc, text.c_str(), message_size);
      }
    };
    
    /*!
      \brief Exception thrown when an error is encountered during input.
    */
    struct input_error: public base_exception
    {    
      CUDA_HOS_DEV input_error (const char* text)
      {
        simple_copy(desc, text, message_size);
      }
      CUDA_HOS_DEV input_error (const std::string &text)
      {
        simple_copy(desc, text.c_str(), message_size);
      }
    };
    
    /*!
      \brief Exception thrown when an error is encountered during output.
    */
    struct output_error: public base_exception
    {    
      CUDA_HOS_DEV output_error (const char* text)
      {
        simple_copy(desc, text, message_size);
      }
      CUDA_HOS_DEV output_error (const std::string &text)
      {
        simple_copy(desc, text.c_str(), message_size);
      }
    };
      
    /*!
      \brief Exception thrown when an error is encountered during memory management (allocation or deallocation).
    */
    struct memory_manager_error: public base_exception
    {    
      CUDA_HOS_DEV memory_manager_error (const char* text)
      {
        simple_copy(desc, text, message_size);
      }
      CUDA_HOS_DEV memory_manager_error (const std::string &text)
      {
        simple_copy(desc, text.c_str(), message_size);
      }
    };

    /*!
      \brief Exception thrown when an error is encountered during input.
      \param e The exception to be thrown.
      \details If `g24_lib::Definitions::throw_exceptions` is `true`
               and the code isn't being ran on a \c CUDA kernel, throws the exception. 
      
      \details If `g24_lib::Definitions::print_exceptions` is `true`
               or `g24_lib::Definitions::throw_exceptions` is `false`,
               and the code isn't being ran on a \c CUDA kernel,
               prints the error message associated with the expression and exits the program with `EXIT_FAILURE`.
       
      \details If the code is being ran on a \c CUDA kernel,
               regardless of the values of `g24_lib::Definitions::throw_exceptions` and 
               `g24_lib::Definitions::print_exceptions`, prints the error message associated with the expression 
               and calls `__trap()`, which interrupts any running threads, stopping the kernel.
       
    */
    template <class Exception>
    CUDA_ONLY_HOS inline void throw_exception(const Exception & e)
    {
      if constexpr (g24_lib::Definitions::print_exceptions || !g24_lib::Definitions::throw_exceptions)
        {
          std::cerr << e.what();
        }
      if constexpr (g24_lib::Definitions::throw_exceptions)
        {
          throw e;
        }
      else
        {
          exit(EXIT_FAILURE);
        }
    }

#if CUDA_AVAILABLE
    template <class Exception>
    CUDA_ONLY_DEV inline void throw_exception(const Exception & e)
    {
      printf("%s", e.what());
      __trap();
    }
#endif
  }
}


#endif

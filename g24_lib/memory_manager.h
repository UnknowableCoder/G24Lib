#ifndef G24_LIB_MEMORY_MANAGER
#define G24_LIB_MEMORY_MANAGER

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

\file memory_manager.h

\brief Provides a generic way to handle memory allocations and de-allocations
       in different memory contexts.
       

\author Nuno Fernandes (main coder, current maintainer)

*/

namespace g24_lib
{
  /*!
      \brief The different memory contexts supported by the library are here.
      
      \remark Since this was written with just CPU and CUDA code in mind,
              it is assumed that it can be determined at compile time
              where the memory will be allocated.
              More complex memory architectures might eventually need a more flexible approach,
              but, for the time being, no revision is planned.
  */
  namespace MemoryContext
  {
  
    /*!
      \brief Provides a base class for all memory contexts.
      
      \remark The memory contexts all serve as a compile-time tag,
              being just empty structs. However, this base class allows one
              to quickly check if an arbitrary class represents a memory context
              (if one assumes all memory contexts derive from it, we just
              use `std::is_base_of`).
    */
    struct memory_context_base{};
  
    /*!
        \brief Usual, CPU-addressable memory. Anything allocated by `new` or `new[]` fits here.
    */
    struct CPU : public memory_context_base {};
    /*!
        \brief Memory that is accessible only to CUDA kernels. In essence, anything from `cudaMalloc`.
        
        \remark Though there is also `cudaMallocManaged` to manage transfers between CPU and a CUDA-compatible GPU,
                it will entail memory allocations on both memory contexts in a way the programmer
                is not really able to control, and there must be synchronizations and so on,
                so, overall, it might not be the most desirable way of implementing the transfers,
                especially in the use cases that led to the development of this part of the library.
    */
    struct CUDA_GPU : public memory_context_base {};
  }
  
  /*!
    \brief Checks if \p context is a valid memory context.
    
    \remark Valid memory contexts are classes that derive from `g24_lib::MemoryContext::memory_context_base`.
  */
  template<class context>
  inline constexpr bool is_memory_context = std::is_base_of_v<MemoryContext::memory_context_base, context>;
  
  namespace internals
  {
    /*!
      \brief Returns the memory context in which the code is being ran.
      
      \remark Since this was written with just CPU and CUDA code in mind,
              it is assumed that it can be determined at compile time.
              More complex memory architectures might eventually need a more flexible approach.
    */
    CUDA_HOS_DEV inline constexpr auto get_current_memory_context()
    {
#if __CUDA_ARCH__
      //__CUDA_ARCH__ is false if undefined
      //(which happens either because
      //we're not using CUDA
      //or we're on host code in Clang)
      //or 0 (which happens for host code in NBCC).
      return MemoryContext::CUDA_GPU{};
#else
      return MemoryContext::CPU{};
#endif
    }
  }
  
  namespace MemoryContext
  {
    /*!
      \brief The current memory context.
      
      \sa g24_lib::internals::get_current_memory_context
    */
    using current = decltype(internals::get_current_memory_context());
  }
  
  /*!
      \brief Provides a base class for all memory managers.
      
      \tparam Type The type of the object being managed.
      
      \tparam indexer A type that is appropriate to hold sizes of objects.
      
      \pre \p indexer must satisfy the constraints placed on the choice of \ref g24_lib::Definitions::default_unsigned_indexer.
    
      \remark All of the member functions (and the member typedef) should be overriden
              in any derived class.
              
      \warning By design, memory managers should only have global state, if any state at all,
               since all the functions are static (and called as such in the code: no separate
               instances of a manager are kept for each container, contrary to what the standard
               mandates should happen with the STL containers). In all the use cases considered,
               this was not problematic at all, but one can never accurately predict all future needs...
  */
  template <class Type, class indexer>
  struct memory_manager_base
  {
    using managed_type = Type;
    
    using indexer_type = indexer;
    
    /*!
        \brief The memory context in which this manager allocates and deallocates the requested memory.
    */
    using memory_location = void;
    
    /*!
        \brief A quick way to check if the managed memory can be safely operated on in the current context.
    */
    CUDA_HOS_DEV static inline constexpr bool can_operate()
    {
      return false;
    }
    
    /*!
        \brief An identifier for this memory manager, mainly for debug outputs
               enabled by `g24_lib::Definitions::print_memory_debug_info`.
    */
    static constexpr std::string_view manager_name()
    {
      static_assert(!std::is_same_v<void,memory_manager_base>, "Should not be using memory_manager_base!");
      return std::string_view("MEMORY MANAGER BASE - SHOULD NOT BE USED!");
    }
    
    /*!
      \brief Allocates \p num objects of type \p Type.
      
      \return A raw pointer to the allocated array.
    */
    static inline Type * allocate(const indexer num)
    {
      static_assert(std::is_same_v<void,memory_manager_base>, "Should not be using memory_manager_base!");
      return nullptr;
    }
    
    /*!
      \brief Deallocates \p num objects of type \p Type residing in an array pointed by \p arr
             and sets \p arr to `nullptr`.
      
      \pre \p arr must be a pointer previously allocated by this manager.
    */
    static inline void deallocate(Type *& arr, const indexer num)
    {
      static_assert(std::is_same_v<void,memory_manager_base>, "Should not be using memory_manager_base!");
    }
    
    /*!
      \brief Copies \p num objects from array pointed by \p source to array in \p dest.
            
      \pre \p source must be a pointer previously allocated by \p other_manager.
      
      \pre \p dest must be a pointer previously allocated by this manager.
    */
    template<class other_manager> static inline void copy(Type *dest, const Type* source, const indexer num)
    {
      static_assert(std::is_same_v<void,memory_manager_base>, "Should not be using memory_manager_base!");
    }
    
    /*!
      \brief Copies \p num objects from array pointed by \p source to array in \p dest that resides in normal memory.
      
      \pre \p source must be a pointer previously allocated by this manager.
      
      \pre \p dest must be a pointer that resides in normal memory
           (either allocated with `new` or through `g24_lib::default_memory_manager`).
    */
    static inline void copy_to_normal_memory(Type *dest, const Type* source, const indexer num)
    {
      static_assert(std::is_same_v<void,memory_manager_base>, "Should not be using memory_manager_base!");
    }
    
    /*!
      \brief Copies \p num objects from array that resides in normal memory pointed by \p source to array in \p dest.
      
      \pre \p source must be a pointer that resides in normal memory
           (either allocated with `new` or through `g24_lib::default_memory_manager`).
           
      \pre \p dest must be a pointer previously allocated by this manager.
    */
    static inline void copy_from_normal_memory(Type *dest, const Type* source, const indexer num)
    {
      static_assert(std::is_same_v<void,memory_manager_base>, "Should not be using memory_manager_base!");
    }
    
    /*!
      \brief Moves \p num objects from array pointed by \p source to array in \p dest.
             Deallocates \p source and puts it to `nullptr`.
      
      \pre \p source must be a pointer previously allocated by \p other_manager.
      
      \pre \p dest must be a pointer previously allocated by this manager.
      
    */
    template<class other_manager> static inline void move(Type *& dest, Type*& source, const indexer old_num, const indexer new_num)
    {
      static_assert(std::is_same_v<void,memory_manager_base>, "Should not be using memory_manager_base!");
    }
  };
  
  ///\cond HIDDEN_SYMBOLS
  
  namespace internals
  {
    template<class C> struct memory_manager_checker
    //Checks for typedefs that must appear in memory managers.
    {
      template<class T>
      static constexpr auto type_checker(T*) -> decltype(typename T::managed_type{});

      template<class>
      static constexpr void type_checker(...);
            
      template<class T>
      static constexpr auto indexer_checker(T*) -> decltype(typename T::indexer_type{});

      template<class>
      static constexpr void indexer_checker(...);
      
      using type = decltype(type_checker<C>(0));
      using indexer = decltype(indexer_checker<C>(0));
      
      constexpr static bool is_manager = true/*std::is_base_of_v<memory_manager_base<type, indexer>, C>*/;
    };
  }
  
  ///\endcond
  
  /*!
    \brief Checks if \p manager is a valid memory manager.
    
    \remark Valid memory managers are classes that derive from `g24_lib::memory_manager_base`.
  */
  template<class manager>
  static inline constexpr bool is_memory_manager = internals::memory_manager_checker<manager>::is_manager;
  
  
  /*!
    \brief Manages memory on the CPU. Basically a slightly different take on `std::allocator`...
    
    \tparam Type The type of the object being managed.
    
    \tparam indexer A type that is appropriate to hold sizes of objects.
    
    \pre \p indexer must satisfy the constraints placed on the choice of \ref g24_lib::Definitions::default_unsigned_indexer.
  */
  template <class Type, class indexer = g24_lib::Definitions::default_unsigned_indexer> struct default_memory_manager :
    public memory_manager_base<Type, indexer>
  {  
    
    static constexpr std::string_view manager_name()
    {
      return std::string_view("Default CPU Memory Manager");
    }
    
    using memory_location = MemoryContext::CPU;
        
    CUDA_HOS_DEV static inline constexpr bool can_operate()
    {
      return std::is_same_v<MemoryContext::current, memory_location>;
    }
    
    using managed_type = Type;
    
    using indexer_type = indexer;
        
    static inline Type * allocate(const indexer num)
    {
      if (num == 0)
        {
          return nullptr;
        }
      Type *ret = new Type[num];
      if constexpr(g24_lib::Definitions::print_memory_debug_info)
        {
          std::cout << manager_name() << ": Allocated " << ret << " (" << num << ")" << std::endl;
        }
      return ret;
    }
    
    static inline void deallocate(Type *& arr, const indexer num)
    {
      if constexpr(g24_lib::Definitions::print_memory_debug_info)
        {
          std::cout << manager_name() << ": Deallocated " << arr << " (" << num << ")"<< std::endl;
        }
      delete[] arr;
      arr = nullptr;
    }
    
    template<class other_manager> static inline void copy(Type *dest, const Type* source, const indexer num)
    {
      static_assert(is_memory_manager<other_manager>, "'other_manager' must be a memory manager!");
      if constexpr(g24_lib::Definitions::print_memory_debug_info)
        {
          std::cout << manager_name() << " <- " << other_manager::manager_name()
                    << ": Copied " << source << " (" << num << ") to " << dest << std::endl;
        }
      if constexpr(std::is_same_v<memory_location, typename other_manager::memory_location>)
        {
          std::memcpy(dest, source, sizeof(Type)*num);
        }
#if CUDA_AVAILABLE
      else if constexpr(std::is_same_v<MemoryContext::CUDA_GPU, typename other_manager::memory_location>)
        {
          G24_LIB_CUDA_ERRCHECK(cudaMemcpy(dest, source, sizeof(Type)*num, cudaMemcpyDeviceToHost));
          //The other manager is the source!
        }
#endif
      else
        {
          Type *temp = new Type[num];
          other_manager::copy_to_normal_memory(temp, source, num);
          copy_from_normal_memory(dest, temp, num);
          delete[] temp;
        }
    }
    
    static inline void copy_to_normal_memory(Type *dest, const Type* source, const indexer num)
    {
      std::memcpy(dest, source, sizeof(Type)*num);
    }
    
    static inline void copy_from_normal_memory(Type *dest, const Type* source, const indexer num)
    {
      std::memcpy(dest, source, sizeof(Type)*num);
    }
    
    template<class other_manager> static inline void move(Type *& dest, Type*& source, const indexer old_num, const indexer new_num)
    {
      static_assert(is_memory_manager<other_manager>, "'other_manager' must be a memory manager!");
      if constexpr(g24_lib::Definitions::print_memory_debug_info)
        {
          std::cout << manager_name() << " <<- " << other_manager::manager_name() << ": Moved "
                    << source << " (" << new_num << ") to " << dest << " (" << old_num << ")" << std::endl;
        }
      if constexpr(std::is_same_v<memory_location, typename other_manager::memory_location>)
        {
          deallocate(dest, old_num);
          dest = source;
          source = nullptr;
        }
      else
        {
          if(old_num == new_num)
            {
              deallocate(dest, old_num);
              dest = allocate(new_num); 
            }
          copy<other_manager>(dest, source, new_num);
          other_manager::deallocate(source, new_num);
        }
    }
  };
  
  /*!
    \brief Manages memory on a CUDA-enabled GPU.
    
    \tparam Type The type of the object being managed.
    
    \tparam indexer A type that is appropriate to hold sizes of objects.
    
    \pre \p indexer must satisfy the constraints placed on the choice of \ref g24_lib::Definitions::default_unsigned_indexer.
  */
  template <class Type, class indexer = g24_lib::Definitions::default_unsigned_indexer> struct CUDA_memory_manager :
    public memory_manager_base<Type, indexer>
  {    
    static constexpr std::string_view manager_name()
    {
      return std::string_view("CUDA GPU Memory Manager");
    }
    
    using memory_location = MemoryContext::CUDA_GPU;
    
    CUDA_HOS_DEV static inline constexpr bool can_operate()
    {
      return std::is_same_v<MemoryContext::current, memory_location>;
    }
    
    using managed_type = Type;
    
    using indexer_type = indexer;
    
    CUDA_HOS_DEV static inline Type * allocate(const indexer num)
    {
      if (num == 0)
        {
          return nullptr;
        }
      Type *ret;
      static_assert(CUDA_AVAILABLE, "Trying to use CUDA memory manager without CUDA...");
      if constexpr (std::is_same_v<MemoryContext::current, MemoryContext::CUDA_GPU>)
        {
          ret = new Type[num];
        }
      else
        {
#if CUDA_AVAILABLE
          G24_LIB_CUDA_ERRCHECK(cudaMalloc(&ret, sizeof(Type)*num));
#endif
        }
      if constexpr(g24_lib::Definitions::print_memory_debug_info)
        {
          std::cout << manager_name() << ": Allocated " << ret << " (" << num << ")" << std::endl;
        }
      return ret;
    }
        
    CUDA_HOS_DEV static inline void deallocate(Type*& arr, const indexer num)
    {
      if constexpr(g24_lib::Definitions::print_memory_debug_info)
        {
          std::cout << manager_name() << ": Deallocated " << arr << " (" << num << ")"<< std::endl;
        }
      static_assert(CUDA_AVAILABLE, "Trying to use CUDA memory manager without CUDA...");
      if constexpr (std::is_same_v<MemoryContext::current, MemoryContext::CUDA_GPU>)
        {
          delete[] arr;
        }
      else
        {
#if CUDA_AVAILABLE
          G24_LIB_CUDA_ERRCHECK(cudaFree(arr));
#endif
        }
      arr = nullptr;
    }
        
    template<class other_manager> CUDA_HOS_DEV static inline void copy(Type *dest, const Type* source, const indexer num)
    {
      static_assert(is_memory_manager<other_manager>, "'other_manager' must be a memory manager!");
      if constexpr(g24_lib::Definitions::print_memory_debug_info)
        {
          std::cout << manager_name() << " <- " << other_manager::manager_name()
                    << ": Copied " << source << " (" << num << ") to " << dest << std::endl;
        }
      if constexpr(std::is_same_v<memory_location, typename other_manager::memory_location>)
        {
          static_assert(CUDA_AVAILABLE, "Trying to use CUDA memory manager without CUDA...");
          if constexpr (std::is_same_v<MemoryContext::current, MemoryContext::CUDA_GPU>)
            {
              memcpy(dest, source, sizeof(Type)*num);
            }
          else
            {
#if CUDA_AVAILABLE
              G24_LIB_CUDA_ERRCHECK(cudaMemcpy(dest, source, sizeof(Type)*num, cudaMemcpyDeviceToDevice));
#endif
            }
        }
      else if constexpr(std::is_same_v<MemoryContext::CPU, typename other_manager::memory_location>)
        {
#if CUDA_AVAILABLE
          G24_LIB_CUDA_ERRCHECK(cudaMemcpy(dest, source, sizeof(Type)*num, cudaMemcpyHostToDevice));
          //The other manager is the source!
#endif
        }
      else
        {
          Type *temp = new Type[num];
          other_manager::copy_to_normal_memory(temp, source, num);
          copy_from_normal_memory(dest, temp, num);
          delete[] temp;
        }
    }
    
    static inline void copy_to_normal_memory(Type *dest, const Type* source, const indexer num)
    {
      static_assert(CUDA_AVAILABLE, "Trying to use CUDA memory manager without CUDA...");
#if CUDA_AVAILABLE
      G24_LIB_CUDA_ERRCHECK(cudaMemcpy(dest, source, sizeof(Type)*num, cudaMemcpyDeviceToHost));
#endif
    }
    
    static inline void copy_from_normal_memory(Type *dest, const Type* source, const indexer num)
    {
      static_assert(CUDA_AVAILABLE, "Trying to use CUDA memory manager without CUDA...");
#if CUDA_AVAILABLE
      G24_LIB_CUDA_ERRCHECK(cudaMemcpy(dest, source, sizeof(Type)*num, cudaMemcpyHostToDevice));
#endif
    }
    
    template<class other_manager> static inline void move(Type *& dest, Type*& source, const indexer old_num, const indexer new_num)
    {
      static_assert(is_memory_manager<other_manager>, "'other_manager' must be a memory manager!");
      if constexpr(g24_lib::Definitions::print_memory_debug_info)
        {
          std::cout << manager_name() << " <<- " << other_manager::manager_name() << ": Moved " 
                    << source << " (" << new_num << ") to " << dest << " (" << old_num << ")" << std::endl;
        }
      if constexpr(std::is_same_v<memory_location, typename other_manager::memory_location>)
        {
          deallocate(dest, old_num);
          dest = source;
          source = nullptr;
        }
      else
        {
          if(old_num == new_num)
            {
              deallocate(dest, old_num);
              dest = allocate(new_num); 
            }
          copy<other_manager>(dest, source, new_num);
          other_manager::deallocate(source, new_num);
        }
    }
  };

  
  namespace internals
  {
  
    /*!
      \brief Returns the an appropriate memory manager from a memory context.
      
      \tparam context The memory context for which one wishes to know the memory manager.
      
      \tparam Type The type of the object one wishes to manage.
      
      \tparam indexer The type that should be able to hold the number of allocated objects and such.
      
      \pre \p context must be a valid memory context.
      
      \pre \p indexer must satisfy the constraints placed on the choice of \ref g24_lib::Definitions::default_unsigned_indexer.
    */
    template <class context, class Type, class indexer> CUDA_HOS_DEV static inline constexpr auto get_memory_manager_from_context()
    {
      static_assert(is_memory_context<context>, "'context' must be a valid memory context!");
      if constexpr (std::is_same_v<context, ::g24_lib::MemoryContext::CPU>)
        {
          return default_memory_manager<Type, indexer>{};
        }
      else if constexpr(std::is_same_v<context, ::g24_lib::MemoryContext::CUDA_GPU>)
        {
          return CUDA_memory_manager<Type, indexer>{};
        }
      else if constexpr(std::is_same_v<context, ::g24_lib::MemoryContext::memory_context_base>)
        {
          return memory_manager_base<Type, indexer>{};
        }
    }
    
  }
  
  namespace MemoryContext
  {
    /*!
      \brief The memory manager that is appropriate for the a given memory context.
      
      \tparam context The memory context for which one wishes to know the memory manager.
      
      \tparam Type The type of the object one wishes to manage.
      
      \tparam indexer The type that should be able to hold the number of allocated objects and such.
      
      \pre \p context must be a valid memory context.
      
      \pre \p indexer must satisfy the constraints placed on the choice of \ref g24_lib::Definitions::default_unsigned_indexer.
      
      \sa g24_lib::internals::get_memory_manager_from_context
      
    */
    template <class context, class Type, class indexer> using manager_from_context = decltype(internals::get_memory_manager_from_context<context, Type, indexer>());
    
    /*!
      \brief The memory manager that is appropriate for the current memory context.
            
      \tparam Type The type of the object one wishes to manage.
      
      \tparam indexer The type that should be able to hold the number of allocated objects and such.
            
      \pre \p indexer must satisfy the constraints placed on the choice of \ref g24_lib::Definitions::default_unsigned_indexer.
      
      \sa g24_lib::MemoryContext::current
      
      \sa g24_lib::internals::get_memory_manager_from_context
      
    */
    template<class Type, class indexer> using current_manager = manager_from_context<current, Type, indexer>;
    
    
    /*!
      \brief The memory context in which a given manager allocates and deallocates memory.
            
      \tparam manager The memory manager for which one wishes to know the context.
            
      \pre \p manager must be a valid memory manager.
      
      \remark This is an alias for whatever is defined as `manager::memory_location`,
              just for completeness and possible convenience.
      
      \sa g24_lib::memory_manager_base::memory_location
      
    */
    template <class manager> using context_from_manager = typename manager::memory_location;
  }
  
}


#endif

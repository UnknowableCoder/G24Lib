#ifndef G24_LIB_MANAGED_OBJECT
#define G24_LIB_MANAGED_OBJECT
 
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

\file managed_object.h

\brief Defines `g24_lib::managed_object`, which makes it easy to copy between several memory contexts.
       

\author Nuno Fernandes (main coder, current maintainer)

*/

namespace g24_lib
{

  /*!
    \brief A container that holds an object in a given memory context.
    
    \tparam Type The type of the object being managed.
    
    \tparam indexer A type that is appropriate to hold sizes of objects.
    
    \tparam memory_manager The memory manager corresponding to the memory context where the object will be held.
    
    \tparam default_is_copy Determines the behaviour of copy constructors and assignment operators:
                            if `false`, instead of allocating a copy of the object,
                            only the pointer is copied (and the memory will not be deleted upon destruction).
                            In essence, if `true`, this acts as something akin to an `std::unique_ptr`,
                            while, if `false`, it is more like an `std::weak_ptr`. (This is currently only used
                            to pass object into \c CUDA kernels. For the end user, `default_is_copy` should be true.)
    
    \remark Even if \p default_is_copy is `false`, this will still act as an `std::unique_ptr`
            if it isn't copy-constructed and/or assigned from another `g24_lib::managed_object`
            with the same \p memory_manager.
            
    \remark Just to be extra clear, for memory validity to be ensured,
            if the memory contexts do not match, the `g24_lib::managed_object`
            will still act as an `std::unique_ptr`,
            allocating the appropriate amount of memory
            and being able to delete it upon destruction.
    
    \warning When acting as a raw pointer, the memory may become invalid
             if the object from which that pointer was copied is destructed
             or resized.
    
    \pre \p indexer must satisfy the constraints placed on the choice of \ref g24_lib::Definitions::default_unsigned_indexer.
    
    \pre \p memory_manager must be a valid memory manager, that is,
            `g24_lib::is_memory_manager<memory_manager>` should be `true`.
    
    \warning Due to the possible need to copy objects between different memory contexts,
             namely when interfacing with CUDA-enabled GPUs,
             copy constructors or assignment operators of `Type` will not be invoked
             during these transfers: `Type` will only be shallow-copied
             (that is, operations akin to `std::memcpy` that copy bytes).
             For most numerical applications, this shouln't pose too much of a problem,
             but it is a limitation one must take into account carefully.
             
    \todo Try to accomodate copy constructors/assignment operators into this.
  */
  template < class Type, class indexer = g24_lib::Definitions::default_unsigned_indexer,
             class memory_manager = default_memory_manager<Type, indexer>,
             bool default_is_copy = true>
  class managed_object
  {
    static_assert(g24_lib::is_memory_manager<memory_manager>,"memory_manager should be a valid memory manager");
    template <class a, class b, class c, bool d> friend class managed_object;
  
    typedef Type value_type;
    typedef memory_manager memory_manager_type;
  private:
    Type *p;
    bool may_dealloc;
  public:
          
    /*!
      \brief Returns `true` if the object can be deallocated 
             (which should be the usual case)
             and `false` if not (when `default_is_copy` is false
             and the pointer has been copied from another object).
    */
    CUDA_HOS_DEV inline bool deallocatable() const
    {
      return may_dealloc;
    }
      
    /*!
      \brief Clears the memory allocated for the object. If `deallocatable()` is false,
             just sets the internal pointer to `nullptr`.
    */
    CUDA_ONLY_HOS inline void clear()
    {
      if(may_dealloc)
        {
          memory_manager::deallocate(p, 1);
        }
    }
    
    /*!
      \brief Returns `true` if this holds an actual object
             and `false` if not.
             
      \remark In essence, it checks if the internal pointer is `nullptr` or not.
    */
    CUDA_HOS_DEV inline bool valid() const
    {
      return (p != nullptr);
      //Just wanted to make it explicit,
      //obviously this is just bool(p)...
    }
    
    /*!
      \brief Default constructor: no allocation.
    */
    CUDA_ONLY_HOS managed_object()
    {
      if constexpr(g24_lib::Definitions::print_memory_debug_info)
        {
          std::cout << "Empty construct " << this << std::endl;
        }
      p = nullptr;
      may_dealloc = true;
    }
      
      
    /*!
      \brief Constructs an object equal to \p val.
    */
    CUDA_ONLY_HOS managed_object (const Type &val)
    {
      if constexpr(g24_lib::Definitions::print_memory_debug_info)
        {
          std::cout << "Value construct " << this << " (" << 1 << ")" << std::endl;
        }
      p = memory_manager::allocate(1);
      if(memory_manager::can_operate())
        {
          p = val;
        }
      else
        {
          memory_manager::template copy<memory_manager>(p, &val, 1);
        }
      may_dealloc = true;
    }
      
    /*!
      \brief Copy-constructs. If, by any reason, the user wants to force the pointer to be copied
             instead of performing allocations, \p `copy` can be put to false.
    */
    CUDA_HOS_DEV managed_object (const managed_object &m, const bool copy = default_is_copy)
    {
      if constexpr(g24_lib::Definitions::print_memory_debug_info)
        {
      std::cout << "Copy construct " << this << " from " << &m  << std::endl;
        }
      if(copy)
        {
          p = memory_manager::allocate(m.valid());
          memory_manager::template copy<memory_manager>(p, m.p, m.valid());
          may_dealloc = true;
        }
      else
        {
          p = m.p;
          may_dealloc = false;
        }
    }
      
    /*!
      \brief Move-constructs.
    */
    CUDA_HOS_DEV managed_object (managed_object &&m)
    {
      if constexpr(g24_lib::Definitions::print_memory_debug_info)
        {
      std::cout << "Move construct " << this << " from " << &m  << std::endl;
        }
      p = m.p;
      may_dealloc = m.may_dealloc;
      s.p = nullptr;
    }
    
    /*!
      \brief Assignment operator from an object of the managed type.
             The behaviour will depend on the template parameter
             \p default_is_copy, with there being allocations if `true`
             and a simple pointer copy if it is `false`.
    */
    CUDA_HOS_DEV managed_object& operator= (const Type &val)
    {
      if constexpr(g24_lib::Definitions::print_memory_debug_info)
        {
      std::cout << "Copy to " << this << " from value " << val << std::endl;
        }
      if(!valid() || !may_dealloc)
        {
          p = memory_manager::allocate(1);
        }
      if(memory_manager::can_operate())
        {
          *p = val;
        }
      else
        {
          memory_manager::template copy<memory_manager>(p, &val, 1);
        }
      may_dealloc = true;
      return (*this);
    }
      
    /*!
      \brief Assignment operator. The behaviour will depend on the template parameter
             \p default_is_copy, with there being allocations if `true`
             and a simple pointer copy if it is `false`.
    */
    CUDA_HOS_DEV managed_object& operator= (const managed_object &m)
    {
      if constexpr(g24_lib::Definitions::print_memory_debug_info)
        {
      std::cout << "Copy to " << this << " from " << &m << std::endl;
        }
      if(this == &m)
        {
          return (*this);
        }
      if(default_is_copy)
        {
          if(valid() != m.valid() || !may_dealloc)
            {
              p = memory_manager::allocate(m.valid());
            }
          memory_manager::template copy<memory_manager>(p, m.p, m.valid());
          may_dealloc = true;
        }
      else
        {
          p = m.p;
          may_dealloc = false;
        }
      return (*this);
    }
      
    /*!
      \brief Move-assignment operator.
    */
    CUDA_HOS_DEV managed_object& operator= (managed_object &&m)
    {
      if constexpr(g24_lib::Definitions::print_memory_debug_info)
        {
      std::cout << "Move to " << this << " from " << &m << std::endl;
        }
      if(this == &m)
        {
          return (*this);
        }
      if (may_dealloc)
        {
          memory_manager::deallocate(p, valid());
        }
      p = m.p;
      may_dealloc = m.may_dealloc;
      m.p = nullptr;
      return (*this);
    }
      
    /*!
      \brief Copy-constructs from another memory context.
             If, by any reason, the user wants to force the pointer to be copied
             instead of performing allocations, \p `copy` can be put to false,
             which happens if and only if the memory locations are the same.
    */
    template <class other_manager, bool other_bool>
    CUDA_ONLY_HOS managed_object (const managed_object<Type, indexer, other_manager, other_bool> &m, const bool copy = default_is_copy)
    {
      if constexpr(g24_lib::Definitions::print_memory_debug_info)
        {
      std::cout << "Convert-construct " << this << " from " << &m  << std::endl;
        }
      if (copy || !std::is_same<typename memory_manager::memory_location, typename other_manager::memory_location>::value)
        {
          memory_manager::allocate(m.valid());
          memory_manager::template copy<other_manager>(p, m.p, m.valid());
          may_dealloc = true;
        }
      else
        {
          p = m.p;
          may_dealloc = false;
        }
    }
      
    /*!
      \brief Move-constructs from another memory context.
    */
    template <class other_manager, bool other_bool>
    CUDA_ONLY_HOS managed_object (managed_object<Type, indexer, other_manager, other_bool> &&m)
    {
      if constexpr(g24_lib::Definitions::print_memory_debug_info)
        {
      std::cout << "Convert-move- construct " << this << " from " << &m  << std::endl;
        }
      p = nullptr;
      if(m.may_dealloc)
        {
          memory_manager::template move<other_manager>(p, m.p, 0, m.valid());
          may_dealloc = true;
        }
      else if(std::is_same<typename memory_manager::memory_location, typename other_manager::memory_location>::value && !m.may_dealloc)
        {
          p = m.p;
          may_dealloc = false;
          m.p = nullptr;
        }
      else if(!m.may_dealloc && !std::is_same<typename memory_manager::memory_location, typename other_manager::memory_location>::value)
        {
          p = memory_manager::allocate(m.valid());
          memory_manager::template copy<other_manager>(p, m.p, m.valid());
          may_dealloc = true;
          m.p = nullptr;
        }
      else
        {
          //std::cerr << "LOGIC ERROR at line " << __LINE__ << "!" << std::endl;
        }
    }
            
    /*!
      \brief Assignment operator from another memory context.
            The behaviour will depend on the template parameter
             \p default_is_copy, with there being allocations if `true`
             and a simple pointer copy if it is `false` and the memory locations are the same.
    */ 
    template<class other_manager, bool other_bool>
    CUDA_ONLY_HOS managed_object& operator= (const managed_object <Type, indexer, other_manager, other_bool>&m)
    {
      if constexpr(g24_lib::Definitions::print_memory_debug_info)
        {
      std::cout << "Copy-convert " << this << " from " << &m << std::endl;
        }
      if constexpr(std::is_same_v<other_manager, memory_manager> && default_is_copy == other_bool)
        {
          if(&m == this)
            {
              return (*this);
            }
        }
      if(!may_dealloc)
        {
          p = nullptr;
        }
      if(default_is_copy || !std::is_same<typename memory_manager::memory_location, typename other_manager::memory_location>::value)
        {
          if(valid() != m.valid() || !may_dealloc)
            {
              memory_manager::deallocate(p, valid());
              //At this point, these checks are equivalent
              //and p is nullptr, so the deallocation is a no-op.
              p = memory_manager::allocate(m.valid());
            }
          memory_manager::template copy<other_manager>(p, m.p, m.valid());
          may_dealloc = true;
        }
      else //default_is_copy = false && memory managers iguais
        {
          memory_manager::deallocate(p, p.valid());
          may_dealloc = false;
          p = m.p;
        }
      return (*this);
    }
      
    /*!
      \brief Move-assignment operator from another memory context.
    */ 
    template<class other_manager, bool other_bool>
    CUDA_ONLY_HOS managed_object& operator= (managed_object <Type, indexer, other_manager, other_bool>&&m)
    { 
      if constexpr(g24_lib::Definitions::print_memory_debug_info)
        {
      std::cout << "Move-convert " << this << " from " << &m << std::endl;
        }
      if constexpr(std::is_same_v<other_manager, memory_manager> && default_is_copy == other_bool)
        {
          if(&m == this)
            {
              return (*this);
            }
        }
      if(!may_dealloc)
        {
          p = nullptr;
        }
        
      if(m.may_dealloc)
        {
          memory_manager::template move<other_manager>(p, m.p, valid(), m.valid());
          may_dealloc = true;
        }
      else if(std::is_same<typename memory_manager::memory_location, typename other_manager::memory_location>::value && !m.may_dealloc)
        {
          p = m.p;
          may_dealloc = false;
          m.p = nullptr;
        }
      else //if(!m.may_dealloc && !std::is_same<typename memory_manager::memory_location, typename other_manager::memory_location>::value)
        {
          p = memory_manager::allocate(m.valid());
          memory_manager::template copy<other_manager>(p, m.p, m.valid());
          may_dealloc = true;
          m.p = nullptr;
        }
      return (*this);
    }
    
    /*!
      \brief Constructs from something that is like an array.
      
      \pre The address of the first element of the array, `&a[0]`, is taken to point to a valid \p Type.
    */
    template<class ArrLike, class disabler = std::enable_if_t< ! std::is_integral_v<ArrLike> >>
    CUDA_ONLY_HOS explicit managed_object(ArrLike &a, const bool copy = default_is_copy)
    {
      if constexpr(g24_lib::Definitions::print_memory_debug_info)
        {
      std::cout << "Array-like construct " << this << " from " << &a  << std::endl;
        }
      if (copy)
        {
          p = memory_manager::allocate(1);
          memory_manager::template copy<memory_manager>(p, &a[0], 1);
          may_dealloc = true;
        }
      else
        {
          p = const_cast<Type*>(&a[0]);
          //I know this is slighly problematic,
          //but it's the best solution I can find now.
          may_dealloc = false;
        }
    }
    
    
    CUDA_HOS_DEV ~managed_object()
    {
      if constexpr(g24_lib::Definitions::print_memory_debug_info)
        {
      std::cout << "Deconstruct " << this << std::endl;
        }
      if (may_dealloc)
        {
          memory_manager::deallocate(p, valid()); 
        }
      p = nullptr;
    }
    
    
    /*!
      \brief Gives direct access to the internal pointer.
      
      \warning This gives actual access to the raw pointer. It shouldn't absolutely be used
               unless the user is really, really sure of what will be done.
    */
    CUDA_HOS_DEV Type*& get_access_to_pointer()
    {
      return p;
    }
      
    /*!
      \brief Gives direct access to the internal pointer.
      
      \warning This gives actual access to the raw pointer. It shouldn't absolutely be used
               unless the user is really, really sure of what will be done.
    */
    CUDA_HOS_DEV const Type* get_access_to_pointer() const
    {
      return p;
    }
          
    /*!
      \brief Returns a pointer to the object.
      
      \warning This gives actual access to the raw pointer. <b>Do not delete this pointer</b>.
    */
    CUDA_HOS_DEV operator Type*() const
    {
      return p;
    }
     
    /*!
      \brief Returns an object of type \p Type.
      
      \remark If the object is stored in memory that is not addressable in the current context,
              it is copied to the addressable memory and this copy is returned.
    */
    CUDA_HOS_DEV operator Type() const
    {
      if (memory_manager::can_operate())
        {
          return *p;
        }
      else
        {
          managed_object<Type, indexer, MemoryContext::current_manager<Type, indexer>> temp(*this);
          return Type(temp);
        }
    }
      
    /*!
      \remark If the object is held in non-addressable memory, a local copy is created specifically for the output.
    */
    template<class stream, class str = std::basic_string<typename stream::char_type>>
    CUDA_ONLY_HOS void textual_output(stream &s, const str& separator = " ") const
    {
      if (memory_manager::can_operate())
        {
          g24_lib::textual_output(s, *p, separator);
        }
      else
        {
          managed_object<Type, indexer, MemoryContext::current_manager<Type, indexer>> temp(*this);
          temp.textual_output(s, separator);
        }
    }
      
    /*!
      \remark If the object is held in non-addressable memory, a local copy is created specifically for the input,
              with the object being copied back to non-adressable memory.
    */
    template<class stream>
    CUDA_ONLY_HOS void textual_input(stream &s)
    {
      if (memory_manager::can_operate())
        {
          g24_lib::textual_input(s, *p, separator);
        }
      else
        {
          managed_object<Type, indexer, MemoryContext::current_manager<Type, indexer>> temp;
          temp.textual_input(s);
          (*this) = temp;
        }
    }
      
    /*!
      \remark If the object is held in non-addressable memory, a local copy is created specifically for the output.
    */
    template<class stream>
    CUDA_ONLY_HOS void binary_output(stream &s) const
    {
      if (memory_manager::can_operate())
        {
          g24_lib::binary_output(s, *p);
        }
      else
        {
          managed_object<Type, indexer, MemoryContext::current_manager<Type, indexer>> temp(*this);
          temp.binary_output(s);
        }
    }
      
    /*!
      \remark If the object is held in non-addressable memory, a local copy is created specifically for the input,
              with the object being copied back to non-adressable memory.
    */
    template<class stream>
    CUDA_ONLY_HOS void binary_input(stream &s)
    {
      if (memory_manager::can_operate())
        {
          g24_lib::binary_input(s, *p, separator);
        }
      else
        {
          managed_object<Type, indexer, MemoryContext::current_manager<Type, indexer>> temp;
          temp.binary_input(s);
          (*this) = temp;
        }
    }
#if CUDA_AVAILABLE
    /*!
      \brief Converts the `g24_lib::managed_object` to a form that can easily be passed to \c CUDA kernels.
      
      \remark This may either copy the pointer, if the memory already resides in the GPU,
              or allocate new memory in the GPU, in case the memory resides elsewhere.
              In this case, any changes made to the object in the GPU will be lost after destruction
              since the object will not be copied back!
    */
    CUDA_ONLY_HOS managed_object<Type, indexer, CUDA_memory_manager<Type, indexer>, false> to_CUDA() const
    {
      return managed_object<Type, indexer, CUDA_memory_manager<Type, indexer>, false>(*this);
    }
#endif
  };
  
  /*!
    \brief A `g24_lib::managed_object` that holds the object in the memory appropriate for the current context.
    
    \tparam Type The type of the object.
    
    \tparam num A type that is appropriate to hold sizes of objects.
    
    \pre \p num must satisfy the constraints placed on the choice of \ref g24_lib::Definitions::default_unsigned_indexer.
  */
  template <class Type, class num = g24_lib::Definitions::default_unsigned_indexer> using managed =
    managed_object <Type, num, MemoryContext::current_manager<Type, num>, true>;  
    
  /*!
    \brief A `g24_lib::managed_object` that holds the object in the usual, CPU-addressable memory.
    
    \tparam Type The type of the object.
    
    \tparam num A type that is appropriate to hold sizes of objects.
    
    \pre \p num must satisfy the constraints placed on the choice of \ref g24_lib::Definitions::default_unsigned_indexer.
  */
  template <class Type, class num = g24_lib::Definitions::default_unsigned_indexer> using cpu_object =
    managed_object <Type, num, default_memory_manager<Type, num>, true>;
    
  /*!
    \brief A `g24_lib::managed_object` that holds the object in the memory of a \c CUDA-enabled GPU.
    
    \tparam Type The type of the object.
    
    \tparam num A type that is appropriate to hold sizes of objects.
    
    \pre \p num must satisfy the constraints placed on the choice of \ref g24_lib::Definitions::default_unsigned_indexer.
  */
  template <class Type, class num = g24_lib::Definitions::default_unsigned_indexer> using cuda_object =
    managed_object <Type, num, CUDA_memory_manager<Type, num>, true>;
    
  /*!
    \brief The appropriate way to pass a `g24_lib::managed_object` into a \c CUDA kernel.
           Will copy the pointer if the memory already resides in the GPU,
           so the original array will be addressed and will experience any changes dictated by the kernel.
    
    \tparam Type The type of the object.
    
    \tparam num A type that is appropriate to hold sizes of objects.
    
    \pre \p num must satisfy the constraints placed on the choice of \ref g24_lib::Definitions::default_unsigned_indexer.
    
    \remark Since there is `g24_lib::to_CUDA` (and all the abstractions in `g24_lib::parallelism`),
            it should no longer be necessary to explicitly convert to this class to pass things into a kernel.
  */
  template <class Type, class num = g24_lib::Definitions::default_unsigned_indexer> using cuda_kernel_object =
    managed_object <Type, num, CUDA_memory_manager<Type, num>, false>;


  /*!
    \brief A `g24_lib::managed_object` that holds the object in a way that is appropriate for a specific type of parallelism.
    
    \tparam Type The type of the object.
    
    \tparam num A type that is appropriate to hold sizes of objects.
    
    \tparam parallel A type of parallelism.
    
    \pre \p num must satisfy the constraints placed on the choice of \ref g24_lib::Definitions::default_unsigned_indexer.
    
    \pre \p parallel must be a valid type of parallelism, that is, it must satisfy `g24_lib::is_parallelism`.
    
  */
  template <class parallel, class Type, class num = g24_lib::Definitions::default_unsigned_indexer>
  using managed_parallel = managed_object <Type, num, typename parallel::template memory_manager<Type, num>, true>;
  //And this generalizes for any parallelism being considered.
  //(It's useful for temporaries and the like.)
}

#endif

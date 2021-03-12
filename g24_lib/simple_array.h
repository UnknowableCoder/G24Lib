#ifndef G24_LIB_SIMPLE_ARRAY
#define G24_LIB_SIMPLE_ARRAY

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

\file simple_array.h

\brief Defines `g24_lib::simple_array`, a container that is suited to
       numerical computations and designed for easy transfer between different `g24_lib::memory_context`.
       

\author Nuno Fernandes (main coder, current maintainer)

*/

namespace g24_lib
{

  /*!
    \brief A container that holds an array of objects in a given memory context.
    
    \tparam Type The type of the objects in the array.
    
    \tparam indexer A type that is appropriate to hold the size of the array.
    
    \tparam memory_manager The memory manager corresponding to the memory context where the array will be held.
    
    \tparam default_is_copy Determines the behaviour of copy constructors and assignment operators:
                            if `false`, instead of copying the elements into a new array,
                            only the pointer is copied (and the memory will not be deleted upon destruction).
                            In essence, if `true`, the array acts as something akin to an `std::unique_ptr`,
                            while, if `false`, it is more like an `std::weak_ptr`. (This is currently only used
                            to pass arrays into \c CUDA kernels. For the end user,
                            `default_is_copy` should be true.)
    
    \remark Even if \p default_is_copy is `false`, this will still act as an `std::unique_ptr`
            if it isn't copy-constructed and/or assigned from another `g24_lib::simple_array`
            with the same \p memory_manager.
            
    \remark Just to be extra clear, for memory validity to be ensured,
            if the memory contexts do not match, the `g24_lib::simple_array`
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
  class simple_array
  {
    static_assert(g24_lib::is_memory_manager<memory_manager>,"memory_manager should be a valid memory manager");
    
    template <class a, class b, class c, bool d> friend class simple_array;
  
    using value_type = Type;
    using indexer_type = indexer;
    using memory_manager_type = memory_manager;
    
  private:
    Type *arr;
    indexer Size;
    bool may_dealloc;
  public:
    
    CUDA_HOS_DEV inline indexer size() const
    {
      return Size;
    }
    /*!
      \brief Returns `true` if the array can be deallocated 
             (which should be the usual case)
             and `false` if not (when `default_is_copy` is false
             and the pointer has been copied from another object).
    */
    CUDA_HOS_DEV inline bool deallocatable() const
    {
      return may_dealloc;
    }
      
    CUDA_HOS_DEV inline Type& operator[] (const indexer i)
    {
      return arr[i];
    }
      
    CUDA_HOS_DEV inline const Type& operator[] (const indexer i) const
    {
      return arr[i];
    }
      
    /*!
      \brief Clears the array. If `deallocatable()` is false,
             just sets the size to 0 and the internal pointer to `nullptr`.
    */
    CUDA_ONLY_HOS inline void clear()
    {
      if(may_dealloc)
        {
          memory_manager::deallocate(arr, Size);
        }
      Size = 0;
      arr = nullptr;
      may_dealloc = true;
    }
      
    /*!
      \brief Sets all the elements of the array to \p x without using parallelism or such.
      
      \remark If the array is not valid in the current memory context
              (for instance, it was allocated on the GPU and we are running the code in the CPU),
              this creates a `g24_lib::simple_array` in the current memory context,
              sets all of it to \p x and then copies it to the memory context in which the array is held.
    */
    void set_all_simple(const Type& x)
    {
      if (memory_manager::can_operate())
        {
          for (indexer i = 0; i < Size; ++i)
            {
              arr[i] = x;
            }
        }
      else
        {
          simple_array<Type, indexer, MemoryContext::current_manager<Type, indexer>> temp(Size);
          temp.set_all_simple(x);
          (*this) = temp;
        }
    }
      
    /*!
      \brief Resizes the array, unless the sizes match.
      
      \remark If `deallocatable()` is false, a new array is allocated
              even if the sizes match, since we can assume the need to resize the array
              means the user is not using this simply as a `std::weak_ptr`;
              furthermore, since we do not keep track of the original object
              from which we copied the pointer, it is impossible to resize it otherwise.
    */
    CUDA_ONLY_HOS inline void resize(const indexer new_size)
    {
      if(new_size != Size || !may_dealloc)
        {
          Type *temp = arr;
          arr = memory_manager::allocate(new_size);
          memory_manager::template copy<memory_manager>(arr, temp, std::min(Size, new_size));
          if (may_dealloc)
            {
              memory_manager::deallocate(temp, Size);
            }
          Size = new_size;
          may_dealloc = true;
        }
    }
    
    /*!
      \brief Default constructor: an empty array.
    */
    CUDA_ONLY_HOS simple_array()
    {
      if constexpr(g24_lib::Definitions::print_memory_debug_info)
        {
      std::cout << "Empty construct " << this << std::endl;
        }
      arr = nullptr;
      Size = 0;
      may_dealloc = true;
    }
      
    /*!
      \brief Constructs an uninitialized array of \p size elements.
    */
    CUDA_ONLY_HOS simple_array (const indexer size)
    {
      if constexpr(g24_lib::Definitions::print_memory_debug_info)
        {
      std::cout << "Size construct " << this << " (" << size << ")" << std::endl;
        }
      arr = memory_manager::allocate(size);
      Size = size;
      may_dealloc = true;
    }
      
    /*!
      \brief Constructs an array of \p size elements that are initialized to \p val.
    */
    CUDA_ONLY_HOS simple_array (const indexer size, const Type &val)
    {
      if constexpr(g24_lib::Definitions::print_memory_debug_info)
        {
      std::cout << "Size construct " << this << " (" << size << ")" << std::endl;
        }
      if(memory_manager::can_operate())
        {
          arr = memory_manager::allocate(size);
          Size = size;
          for(indexer i = 0; i < Size; ++i)
            {
              arr[i] = val;
            }
          may_dealloc = true;
        }
      else
        {
          simple_array<Type, indexer, MemoryContext::current_manager<Type, indexer>> temp(Size, val);
          (*this) = temp;
        }
    }
      
    /*!
      \brief Copy-constructs. If, by any reason, the user wants to force the pointer to be copied
             instead of performing allocations, \p `copy` can be put to false.
    */
    CUDA_HOS_DEV simple_array (const simple_array &s, const bool copy = default_is_copy)
    {
      if constexpr(g24_lib::Definitions::print_memory_debug_info)
        {
      std::cout << "Copy construct " << this << " from " << &s  << std::endl;
        }
      if(copy)
        {
          arr = memory_manager::allocate(s.Size);
          Size = s.Size;
          memory_manager::template copy<memory_manager>(arr, s.arr, Size);
          may_dealloc = true;
        }
      else
        {
          arr = s.arr;
          Size = s.Size;
          may_dealloc = false;
        }
    }
      
    /*!
      \brief Move-constructs.
    */
    CUDA_HOS_DEV simple_array (simple_array &&s)
    {
      if constexpr(g24_lib::Definitions::print_memory_debug_info)
        {
      std::cout << "Move construct " << this << " from " << &s  << std::endl;
        }
      arr = s.arr;
      Size = s.Size;
      may_dealloc = s.may_dealloc;
      s.arr = nullptr;
      s.Size = 0;
    }
      
    /*!
      \brief Assignment operator. The behaviour will depend on the template parameter
             \p default_is_copy, with there being allocations if `true`
             and a simple pointer copy if it is `false`.
    */
    CUDA_HOS_DEV simple_array& operator= (const simple_array &s)
    {
      if constexpr(g24_lib::Definitions::print_memory_debug_info)
        {
      std::cout << "Copy to " << this << " from " << &s << std::endl;
        }
      if(this == &s)
        {
          return (*this);
        }
      if(may_dealloc && Size != s.Size)
        {
          memory_manager::deallocate(arr, Size);
          arr = nullptr;
          Size = 0;
        }
      if(default_is_copy)
        {
          if(Size != s.Size || !may_dealloc)
            {
              arr = memory_manager::allocate(s.Size);
              Size = s.Size;
            }
          memory_manager::template copy<memory_manager>(arr, s.arr, Size);
          may_dealloc = true;
        }
      else
        {
          arr = s.arr;
          Size = s.Size;
          may_dealloc = false;
        }
      return (*this);
    }
      
    /*!
      \brief Move-assignment operator.
    */
    CUDA_HOS_DEV simple_array& operator= (simple_array &&s)
    {
      if constexpr(g24_lib::Definitions::print_memory_debug_info)
        {
      std::cout << "Move to " << this << " from " << &s << std::endl;
        }
      if(this == &s)
        {
          return (*this);
        }
      if (may_dealloc)
        {
          memory_manager::deallocate(arr, Size);
        }
      arr = s.arr;
      Size = s.Size;
      may_dealloc = s.may_dealloc;
      s.arr = nullptr;
      s.Size = 0;
      return (*this);
    }
      
    /*!
      \brief Copy-constructs from another memory context.
             If, by any reason, the user wants to force the pointer to be copied
             instead of performing allocations, \p `copy` can be put to false.
    */
    template <class other_manager, bool other_bool>
    CUDA_ONLY_HOS simple_array (const simple_array<Type, indexer, other_manager, other_bool> &s, const bool copy = default_is_copy)
    {
      if constexpr(g24_lib::Definitions::print_memory_debug_info)
        {
      std::cout << "Convert-construct " << this << " from " << &s  << std::endl;
        }
      if (copy || !std::is_same<typename memory_manager::memory_location, typename other_manager::memory_location>::value)
        {
          arr = memory_manager::allocate(s.Size);
          Size = s.Size;
          memory_manager::template copy<other_manager>(arr, s.arr, Size);
          may_dealloc = true;
        }
      else
        {
          arr = s.arr;
          Size = s.Size;
          may_dealloc = false;
        }
    }
      
    /*!
      \brief Move-constructs from another memory context.
    */
    template <class other_manager, bool other_bool>
    CUDA_ONLY_HOS simple_array (simple_array<Type, indexer, other_manager, other_bool> &&s)
    {
      if constexpr(g24_lib::Definitions::print_memory_debug_info)
        {
      std::cout << "Convert-move- construct " << this << " from " << &s  << std::endl;
        }
      Size = s.Size;
      arr = nullptr;
      if(s.may_dealloc)
        {
          memory_manager::template move<other_manager>(arr, s.arr, 0, Size);
          s.arr = nullptr;
          s.Size = 0;
          may_dealloc = true;
        }
      else if(std::is_same<typename memory_manager::memory_location, typename other_manager::memory_location>::value && !s.may_dealloc)
        {
          arr = s.arr;
          may_dealloc = false;
          s.arr = nullptr;
          s.Size = 0;
        }
      else if(!s.may_dealloc && !std::is_same<typename memory_manager::memory_location, typename other_manager::memory_location>::value)
        {
          arr = memory_manager::allocate(s.Size);
          memory_manager::template copy<other_manager>(arr, s.arr, Size);
          may_dealloc = true;
          s.arr = nullptr;
          s.Size = 0;
        }
      else
        {
          //std::cerr << "LOGIC ERROR at line " << __LINE__ << "!" << std::endl;
        }
    }
     
    /*!
      \brief Copy-constructs from a generic container with a known \p size.
             If, by any reason, the user wants to force the pointer to be copied
             instead of performing allocations, \p `copy` can be put to false.
             
      \warning This assumes the other container has contiuous storage and the address
               of the 0-th component is the beginning of the array.
    */     
    template<class ArrLike, class disabler = std::enable_if_t<!std::is_same_v<ArrLike, Type> &&
                                                              std::is_same_v<g24_lib::value_type<ArrLike>, Type> > >
    CUDA_ONLY_HOS explicit simple_array(const indexer size, const ArrLike &a, const bool copy = default_is_copy)
    {
      if constexpr(g24_lib::Definitions::print_memory_debug_info)
        {
      std::cout << "Array+size construct " << this << " from " << &a  << std::endl;
        }
      if (copy)
        {
          arr = memory_manager::allocate(size);
          Size = size;
          memory_manager::template copy<memory_manager>(arr, &a[0], size);
          may_dealloc = true;
        }
      else
        {
          Size = size;
          arr = const_cast<Type*>(&a[0]);
          may_dealloc = false;
        }
    }
    
    /*!
      \brief Copy-constructs from a generic container with a `size()` member function.
             If, by any reason, the user wants to force the pointer to be copied
             instead of performing allocations, \p `copy` can be put to false.
             
      \warning This assumes the other container has contiuous storage and the address
               of the 0-th component is the beginning of the array.
    */
    template<class ArrLike, class disabler = std::enable_if_t<!std::is_integral_v<ArrLike> &&
                                                              std::is_same_v<g24_lib::value_type<ArrLike>, Type> > >
    CUDA_ONLY_HOS explicit simple_array(const ArrLike &a, const bool copy = default_is_copy)
    {
      if constexpr(g24_lib::Definitions::print_memory_debug_info)
        {
      std::cout << "Sized_array construct " << this << " from " << &a  << std::endl;
        }
      if (copy)
        {
          arr = memory_manager::allocate(a.size());
          Size = a.size();
          memory_manager::template copy<memory_manager>(arr, &a[0], a.size());
          may_dealloc = true;
        }
      else
        {
          Size = a.size();
          arr = &a[0];
          may_dealloc = false;
        }
    }
    
      
           
    /*!
      \brief Assignment operator from another memory context.
            The behaviour will depend on the template parameter
             \p default_is_copy, with there being allocations if `true`
             and a simple pointer copy if it is `false` and the memory locations are the same.
    */ 
    template<class other_manager, bool other_bool>
    CUDA_ONLY_HOS simple_array& operator= (const simple_array <Type, indexer, other_manager, other_bool>&s)
    {
      if constexpr(g24_lib::Definitions::print_memory_debug_info)
        {
      std::cout << "Copy-convert " << this << " from " << &s << std::endl;
        }
      if constexpr(std::is_same_v<other_manager, memory_manager> && default_is_copy == other_bool)
        {
          if(&s == this)
            {
              return (*this);
            }
        }
      if(!may_dealloc)
        {
          arr = nullptr;
          Size = 0;
        }
      if(default_is_copy || !std::is_same<typename memory_manager::memory_location, typename other_manager::memory_location>::value)
        {
          if(Size != s.Size || !may_dealloc)
            {
              memory_manager::deallocate(arr, Size);
              //In case of !may_dealloc,
              //arr has been set to nullptr
              //and deallocate is a no-op.
              Size = s.Size;
              arr = memory_manager::allocate(Size);
            }
          memory_manager::template copy<other_manager>(arr, s.arr, Size);
          may_dealloc = true;
        }
      else //default_is_copy = false && memory managers the same
        {
          memory_manager::deallocate(arr, Size);
          may_dealloc = false;
          arr = s.arr;
          Size = s.Size;
        }
      return (*this);
    }
      
    /*!
      \brief Move-assignment operator from another memory context.
    */ 
    template<class other_manager, bool other_bool>
    CUDA_ONLY_HOS simple_array& operator= (simple_array <Type, indexer, other_manager, other_bool>&&s)
    { 
      if constexpr(g24_lib::Definitions::print_memory_debug_info)
        {
      std::cout << "Move-convert " << this << " from " << &s << std::endl;
        }
      if constexpr(std::is_same_v<other_manager, memory_manager> && default_is_copy == other_bool)
        {
          if(&s == this)
            {
              return (*this);
            }
        }
      if(!may_dealloc)
        {
          arr = nullptr;
          Size = 0;
        }        
      if(s.may_dealloc)
        {
          memory_manager::template move<other_manager>(arr, s.arr, Size, s.Size);
          Size = s.Size;
          s.Size = 0;
          may_dealloc = true;
        }
      else if(std::is_same<typename memory_manager::memory_location, typename other_manager::memory_location>::value && !s.may_dealloc)
        {
          arr = s.arr;
          Size = s.Size;
          may_dealloc = false;
          s.arr = nullptr;
          s.Size = 0;
        }
      else //if(!s.may_dealloc && !std::is_same<typename memory_manager::memory_location, typename other_manager::memory_location>::value)
        {
          arr = memory_manager::allocate(s.Size);
          memory_manager::template copy<other_manager>(arr, s.arr, s.Size);
          may_dealloc = true;
          Size = s.Size;
          s.arr = nullptr;
          s.Size = 0;
        }
      return (*this);
    }
            
    CUDA_HOS_DEV ~simple_array()
    {
      if constexpr(g24_lib::Definitions::print_memory_debug_info)
        {
      std::cout << "Deconstruct " << this << std::endl;
        }
      if (may_dealloc)
        {
          memory_manager::deallocate(arr, Size); 
        }
      arr = nullptr;
    }
            
    /*!
      \brief Gives direct access to the underlying array.
      
      \warning This gives actual access to the raw array. It shouldn't absolutely be used
               unless the user is really, really sure of what will be done.
    */
    CUDA_HOS_DEV Type*& get_access_to_array()
    {
      return arr;
    }
      
    /*!
      \brief Gives direct access to the underlying array.
      
      \warning This gives actual access to the raw array. It shouldn't absolutely be used
               unless the user is really, really sure of what will be done.
    */
    CUDA_HOS_DEV const Type* get_access_to_array() const
    {
      return arr;
    }
      
    /*!
      \brief Returns a pointer to the array.
      
      \warning This gives actual access to the raw array. <b>Do not delete this pointer</b>.
    */
    CUDA_HOS_DEV operator Type*() const
    {
      return get_access_to_array();
    }
      
    /*!
      \brief Returns a pointer to the beginning of the array.

      \warning This is meant to be used, if need be, as an iterator. <b>Do not delete this pointer</b>.
    */
    Type * begin()
    {
      return arr;
    }
    
    /*!
      \brief Returns a pointer to the beginning of the array.

      \warning This is meant to be used, if need be, as an iterator. <b>Do not delete this pointer</b>.
    */
    const Type* begin() const
    {
      return arr;
    }
    
    /*!
      \brief Returns a pointer to the end of the array.

      \warning This is meant to be used, if need be, as an iterator. <b>Do not delete this pointer</b>.
    */
    Type* end()
    {
      return (arr + Size);
    }
    
    /*!
      \brief Returns a pointer to the end of the array.

      \warning This is meant to be used, if need be, as an iterator. <b>Do not delete this pointer</b>.
    */
    const Type* end() const
    {
      return (arr + Size);
    }
    
    /*!
      \remark If the array is held in non-addressable memory, a local copy is created specifically for the output.
    */
    template<class stream, class str = std::basic_string<typename stream::char_type>>
    CUDA_ONLY_HOS void textual_output(stream &s, const str& separator = " ") const
    {
      if (memory_manager::can_operate())
        {
          g24_lib::textual_output(s, Size, separator);
          s << separator;
          for (indexer i = 0; i < Size; ++i)
            {
              g24_lib::textual_output(s, arr[i], separator);
              s << separator;
            }
        }
      else
        {
          simple_array<Type, indexer, MemoryContext::current_manager<Type, indexer>> temp(*this);
          temp.textual_output(s, separator);
        }
    }
      
    /*!
      \remark If the array is held in non-addressable memory, a local copy is created specifically for the input,
              with the objects being copied back to non-adressable memory.
    */
    template<class stream>
    CUDA_ONLY_HOS void textual_input(stream &s)
    {
      if (memory_manager::can_operate())
        {
          indexer new_size;
          g24_lib::textual_input(s, new_size);
          if(s.fail())
            {
              exceptions::throw_exception(exceptions::array_length_misread(""));
            }
          simple_array temp(new_size);
          for (indexer i = 0; i < temp.size(); ++i)
            {
              g24_lib::textual_input(s, temp.arr[i]);
            }
          (*this) = temp;
        }
      else
        {
          simple_array<Type, indexer, MemoryContext::current_manager<Type, indexer>> temp;
          temp.textual_input(s);
          (*this) = temp;
        }
    }
      
    /*!
      \remark If the array is held in non-addressable memory, a local copy is created specifically for the output.
    */
    template<class stream>
    CUDA_ONLY_HOS void binary_output(stream &s) const
    {
      if (memory_manager::can_operate())
        {
          g24_lib::binary_output(s, Size);
          for (indexer i = 0; i < Size; ++i)
            {
              g24_lib::binary_output(s, arr[i]);
            }
        }
      else
        {
          simple_array<Type, indexer, MemoryContext::current_manager<Type, indexer>> temp(*this);
          temp.binary_output(s);
        }
    }
      
    /*!
      \remark If the array is held in non-addressable memory, a local copy is created specifically for the input,
              with the objects being copied back to non-adressable memory.
    */
    template<class stream>
    CUDA_ONLY_HOS void binary_input(stream &s)
    {
      if (memory_manager::can_operate())
        {
          indexer new_size;
          g24_lib::binary_input(s, new_size);
          if(s.fail())
            {
              exceptions::throw_exception(exceptions::array_length_misread(""));
            }
          simple_array temp(new_size);
          for (indexer i = 0; i < temp.size(); ++i)
            {
              g24_lib::binary_input(s, temp.arr[i]);
            }
          (*this) = temp;
        }
      else
        {
          simple_array<Type, indexer, MemoryContext::current_manager<Type, indexer>> temp;
          temp.binary_input(s);
          (*this) = temp;
        }
    }
#if CUDA_AVAILABLE
    /*!
      \brief Converts the `g24_lib::simple_array` to a form that can easily be passed to \c CUDA kernels.
      
      \remark This may either copy the pointer, if the memory already resides in the GPU,
              or allocate new memory in the GPU, in case the memory resides elsewhere.
              In this case, any changes made to the array in the GPU will be lost after destruction
              since the array will not be copied back!
    */
    CUDA_ONLY_HOS simple_array<Type, indexer, CUDA_memory_manager<Type, indexer>, false> to_CUDA() const
    {
      return simple_array<Type, indexer, CUDA_memory_manager<Type, indexer>, false>(*this);
    }
#endif

    /*!
      \brief Performs operation given by \p f on every element of the array.
            
      \param f The function to apply on the elements of the array.
      
      \param args Extra arguments to be passed to \p f
            
      \tparam Func The type that holds the function to be applied to the elements of the array.
      
      \tparam Args The types for any extra arguments to \p Func.
      
      \pre \p f must take as arguments a reference to an array
            (appropriate to be operated with the specified form of parallelism)
            and the index at which we're evaluating, and any extra arguments passed to this function in \p args.
            
      \pre \p parallel must be a valid type of parallelism, that is, it must satisfy `g24_lib::is_parallelism`.
      
      \remark For a `simple_array`, it's just a wrapper around `parallelism::loop()`.
      
      \warning If the array is not held in a `memory_context` appropriate for being operated on
               with the specified parallelism, it is converted to an appropriate array.
               
    */
    template <class parallel, class Func, class ... Args>
    void operate_on_all(Func &&f, Args &&... args)
    {
      static_assert(g24_lib::is_parallelism<parallel>, "Must be using a valid form of parallelism!");
      if constexpr (std::is_same_v<typename memory_manager::memory_location, typename parallel::memory_location>)
        {
          parallel::loop((*this), std::forward<Func>(f), std::forward<Args>(args)...);
        }
      else
        {
          simple_array<Type, indexer, typename parallel::template memory_manager<Type, indexer>> temp(*this);
          temp.template operate_on_all<parallel>(std::forward<Func>(f), std::forward<Args>(args)...);
          (*this) = temp;
        }
    }
    
    /*!
      \brief Sets all elements of the array to \p val.
            
      \param val The value to which the array should be set.
            
      \pre \p parallel must be a valid type of parallelism, that is, it must satisfy `g24_lib::is_parallelism`.
    */
    template <class parallel>
    void set_all(const Type &val)
    {
      this->template operate_on_all<parallel>(set_ith_functor{}, val);
      //set_ith_functor from general_helpers sets arr[i] = val.
    }

  };

  /*!
    \brief A `g24_lib::simple_array` that holds the array in the memory appropriate for the current context.
    
    \tparam Type The type of the objects in the array.
    
    \tparam num A type that is appropriate to hold sizes of objects.
    
    \pre \p num must satisfy the constraints placed on the choice of \ref g24_lib::Definitions::default_unsigned_indexer.
  */
  template <class Type, class num = g24_lib::Definitions::default_unsigned_indexer> using array =
    simple_array <Type, num, MemoryContext::current_manager<Type, num>, true>;  
  
  
  /*!
    \brief A `g24_lib::simple_array` that holds the array in the usual, CPU-addressable memory.
    
    \tparam Type The type of the objects in the array.
    
    \tparam num A type that is appropriate to hold sizes of objects.
    
    \pre \p num must satisfy the constraints placed on the choice of \ref g24_lib::Definitions::default_unsigned_indexer.
  */
  template <class Type, class num = g24_lib::Definitions::default_unsigned_indexer> using cpu_array =
    simple_array <Type, num, default_memory_manager<Type, num>, true>;
    
  /*!
    \brief A `g24_lib::simple_array` that holds the array in the memory of a \c CUDA-enabled GPU.
    
    \tparam Type The type of the objects in the array.
    
    \tparam num A type that is appropriate to hold sizes of objects.
    
    \pre \p num must satisfy the constraints placed on the choice of \ref g24_lib::Definitions::default_unsigned_indexer.
  */
  template <class Type, class num = g24_lib::Definitions::default_unsigned_indexer> using cuda_array =
    simple_array <Type, num, CUDA_memory_manager<Type, num>, true>;
    
    
  /*!
    \brief The appropriate way to pass a `g24_lib::simple_array` into a \c CUDA kernel.
           Will copy the pointer if the memory already resides in the GPU,
           so the original array will be addressed and will experience any changes dictated by the kernel.
    
    \tparam Type The type of the objects in the array.
    
    \tparam num A type that is appropriate to hold sizes of objects.
    
    \pre \p num must satisfy the constraints placed on the choice of \ref g24_lib::Definitions::default_unsigned_indexer.
    
    \remark Since there is `g24_lib::to_CUDA` (and all the abstractions in `g24_lib::parallelism`),
            it should no longer be necessary to explicitly convert to this class to pass things into a kernel.
  */
  template <class Type, class num = g24_lib::Definitions::default_unsigned_indexer> using cuda_kernel_array =
    simple_array <Type, num, CUDA_memory_manager<Type, num>, false>;

  
  /*!
    \brief A `g24_lib::simple_array` that holds the array in a way that is appropriate for a specific type of parallelism.
    
    \tparam Type The type of the objects in the array.
    
    \tparam num A type that is appropriate to hold sizes of objects.
    
    \tparam parallel A type of parallelism.
    
    \pre \p num must satisfy the constraints placed on the choice of \ref g24_lib::Definitions::default_unsigned_indexer.
    
    \pre \p parallel must be a valid type of parallelism, that is, it must satisfy `g24_lib::is_parallelism`.
    
  */
  template <class parallel, class Type, class num = g24_lib::Definitions::default_unsigned_indexer>
  using array_parallel = simple_array <Type, num, typename parallel::template memory_manager<Type, num>, true>;
}

#endif

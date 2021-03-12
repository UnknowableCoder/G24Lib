#ifndef G24_LIB_SPLIT_ARRAY
#define G24_LIB_SPLIT_ARRAY

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

\file split_array.h

\brief Defines `g24_lib::split_member_array`, that stores each member of a struct as a separate array.

\author Nuno Fernandes (main coder, current maintainer)

*/ 
namespace g24_lib
{

  namespace internals
  {
  
    ///\cond HIDDEN_SYMBOLS
    
    template <class Type, g24_lib::Definitions::default_unsigned_indexer num> struct split_array_helper;
    
    template <class Type> struct split_array_helper<Type, 0>
    {
      static constexpr g24_lib::Definitions::default_unsigned_indexer number = 0;
      //Empty because the type list is 1-indexed.
    };
    
    template <class Type, g24_lib::Definitions::default_unsigned_indexer num>
    struct split_array_helper : public split_array_helper<Type, num-1>
    {
      static constexpr g24_lib::Definitions::default_unsigned_indexer number = num;
      
      using type = typename g24_lib::class_info<Type>::template true_type<num>;
      
      type *arr;
    };
    
    ///\endcond
  }

  /*!
    \brief A container that stores the different members of a struct that can undergo compile time reflection
           through `g24_lib::class_info` as separate arrays. In short, translates an *array of structs*
           into a *struct of arrays* in a more or less automatic way.
    
    \tparam Type The type of the structs that will be stored.
    
    \tparam indexer A type that is appropriate to hold the size of the arrays.
    
    \tparam memory_manager_type The memory manager corresponding to the memory context where the arrays will be held.
    
    \tparam default_is_copy See `g24_lib::simple_array`.
    
    \pre \p Type must support the limited form of compile time reflection provided by `g24_lib::class_info`.
    
    \pre \p indexer must satisfy the constraints placed on the choice of `g24_lib::Definitions::default_unsigned_indexer`.
    
    \pre \p memory_manager_type must be a valid template for memory managers, that is,
            `g24_lib::is_memory_manager<memory_manager_type<T, indexer>>` should be `true` for any `T`.
                          
  */
  template < class Type, class indexer = g24_lib::Definitions::default_unsigned_indexer,
             template <class, class> class memory_manager_type = default_memory_manager,
             bool default_is_copy = true>
  struct split_member_array : private internals::split_array_helper<Type, g24_lib::class_info<Type>::true_arity>
  
  {
    static_assert(g24_lib::is_memory_manager<memory_manager_type<Type,indexer>>,"memory_manager_type should be a valid memory manager");
    
    template <class a, class b, template <class, class> class c, bool d> friend struct split_member_array;
  
  private:
    using info = g24_lib::class_info<Type>;
  
    template <g24_lib::Definitions::default_unsigned_indexer num>
    using hold_t = typename info::template true_type<num>;
    
    template <g24_lib::Definitions::default_unsigned_indexer num>
    using holder = internals::split_array_helper<Type, num>;
    
    static constexpr g24_lib::Definitions::default_unsigned_indexer number = info::true_arity;
    
    indexer Size;
    bool may_dealloc;
    
  public:
    
    typedef Type value_type;
    
    typedef flat_imitation_struct<Type> true_type;
    
    typedef indexer indexer_type;
    
    template <g24_lib::Definitions::default_unsigned_indexer num>
    using memory_manager = memory_manager_type<hold_t<num>, indexer>;
    
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
      
    private:
    
    template <g24_lib::Definitions::default_unsigned_indexer num, class F, class ... Args>
    CUDA_HOS_DEV inline void operate_on_all_members_parts (F && f, Args && ...args)
    //Just so we simplify the logic.
    //F must take as arguments a pointer to an holder
    //(which will be casted from "this").
    {
      f(static_cast<holder<num>*>(this), std::forward<Args>(args)...);
      if constexpr (num < number)
        {
          operate_on_all_members_parts<num+1, F, Args...>(std::forward<F>(f), std::forward<Args>(args)...);
        }
    }
    
    template <g24_lib::Definitions::default_unsigned_indexer num, class F, class ... Args>
    CUDA_HOS_DEV inline void operate_on_all_members_parts (F && f, Args && ...args) const
    //Just so we simplify the logic.
    //F must take as arguments a pointer to an holder
    //(which will be casted from "this").
    {
      f(static_cast<const holder<num>*>(this), std::forward<Args>(args)...);
      if constexpr (num < number)
        {
          operate_on_all_members_parts<num+1, F, Args...>(std::forward<F>(f), std::forward<Args>(args)...);
        }
    }
        
    template <class F, class ... Args>
    CUDA_HOS_DEV inline void operate_on_all_members(F && f, Args && ...args)
    {
      operate_on_all_members_parts<1>(std::forward<F>(f), std::forward<Args>(args)...);
    }
    
    template <class F, class ... Args>
    CUDA_HOS_DEV inline void operate_on_all_members(F && f, Args && ...args) const
    {
      operate_on_all_members_parts<1>(std::forward<F>(f), std::forward<Args>(args)...);
    }
            
    public:
    
    /*!
      \brief Clears the array. If `deallocatable()` is false,
             just sets the size to 0 and the internal pointers to `nullptr`.
    */
    CUDA_ONLY_HOS inline void clear()
    {
      operate_on_all_members([this](auto *p)
                        {
                          constexpr g24_lib::Definitions::default_unsigned_indexer num = std::remove_reference_t<decltype(*p)>::number;
                          if(may_dealloc)
                            {
                              memory_manager<num>::deallocate(p->arr, this->Size);
                            }
                          p->arr = nullptr;
                        }
                    );
      Size = 0;
      may_dealloc = true;
    }
    
    /*!
      \brief Sets all the elements of the array to \p x.
      
      \remark If the array is not valid in the current memory context
              (for instance, it was allocated on the GPU and we are running the code in the CPU),
              this creates a `g24_lib::split_member_array` in the current memory context,
              sets all of it to \p x and then copies it to the memory context in which the array is held.
    */
    CUDA_ONLY_HOS void set_all_simple(const g24_lib::flat_imitation_struct<Type>& x)
    {
      if (memory_manager_type<Type, indexer>::can_operate())
        {
          operate_on_all_members([this, &x](auto *p)
                            {
                              constexpr g24_lib::Definitions::default_unsigned_indexer num = std::remove_reference_t<decltype(*p)>::number;
                              for (indexer i = 0; i < this->Size; ++i)
                                {
                                  p->arr[i] = x.template get_element<num>();
                                }
                            }
                        );
        }
      else
        {
          split_member_array<Type, indexer, MemoryContext::current_manager> temp(Size);
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
          operate_on_all_members([this, new_size](auto *p)
                            {
                              constexpr g24_lib::Definitions::default_unsigned_indexer num = std::remove_reference_t<decltype(*p)>::number;
                              hold_t<num> *temp = p->arr;
                              p->arr = memory_manager<num>::allocate(new_size);
                              memory_manager<num>::template copy<memory_manager<num>>(p->arr, temp, std::min(this->Size, new_size));
                              if (may_dealloc)
                                {
                                  memory_manager<num>::deallocate(temp, this->Size);
                                }
                            }
                        );
          Size = new_size;
          may_dealloc = true;
        }
    }
    
    /*!
      \brief Default constructor: an empty array.
    */
    CUDA_ONLY_HOS split_member_array()
    {
      if constexpr(g24_lib::Definitions::print_memory_debug_info)
        {
      std::cout << "Empty construct " << this << std::endl;
        }
      operate_on_all_members([](auto *p)
                        {
                          p->arr = nullptr;
                        }
                    );
      Size = 0;
      may_dealloc = true;
    }
      
    /*!
      \brief Constructs an uninitialized split array of \p size elements.
    */
    CUDA_ONLY_HOS split_member_array (const indexer size)
    {
      if constexpr(g24_lib::Definitions::print_memory_debug_info)
        {
      std::cout << "Size construct " << this << " (" << size << ")" << std::endl;
        }
      operate_on_all_members([size](auto *p)
                        {
                          constexpr g24_lib::Definitions::default_unsigned_indexer num = std::remove_reference_t<decltype(*p)>::number;
                          p->arr = memory_manager<num>::allocate(size);
                        }
                    );
      Size = size;
      may_dealloc = true;
    }
      
    /*!
      \brief Constructs a split array of \p size elements that are initialized to \p val.
    */
    CUDA_ONLY_HOS split_member_array (const indexer size, const g24_lib::flat_imitation_struct<Type> &val)
    {
      if constexpr(g24_lib::Definitions::print_memory_debug_info)
        {
      std::cout << "Size construct " << this << " (" << size << ")" << std::endl;
        }
      if(memory_manager_type<Type, indexer>::can_operate())
        {
          operate_on_all_members([size, &val](auto *p)
                            {
                              constexpr g24_lib::Definitions::default_unsigned_indexer num = std::remove_reference_t<decltype(*p)>::number;
                              p->arr = memory_manager<num>::allocate(size);
                              for(indexer i = 0; i < size; ++i)
                                {
                                  p->arr[i] = val.template get_element<num>();
                                }
                            }
                        );
          Size = size;
          may_dealloc = true;
        }
      else
        {
          split_member_array<Type, indexer, MemoryContext::current_manager> temp(Size, val);
          (*this) = temp;
        }
    }
      
    /*!
      \brief Copy-constructs. If, by any reason, the user wants to force the pointer to be copied
             instead of performing allocations, \p `copy` can be put to false.
    */
    CUDA_HOS_DEV split_member_array (const split_member_array &s, const bool copy = default_is_copy)
    {
      if constexpr(g24_lib::Definitions::print_memory_debug_info)
        {
      std::cout << "Copy construct " << this << " from " << &s  << std::endl;
        }
      if(copy)
        {
          operate_on_all_members([&s](auto *p)
                            {
                              constexpr g24_lib::Definitions::default_unsigned_indexer num = std::remove_reference_t<decltype(*p)>::number;
                              p->arr = memory_manager<num>::allocate(s.Size);
                              memory_manager<num>::template copy<memory_manager<num>>(p->arr, s.holder<num>::arr, s.Size);
                            }
                        );
          Size = s.Size;
          may_dealloc = true;
        }
      else
        {
          operate_on_all_members([&s](auto *p)
                            {
                              constexpr g24_lib::Definitions::default_unsigned_indexer num = std::remove_reference_t<decltype(*p)>::number;
                              p->arr = s.holder<num>::arr;
                            }
                        );
          Size = s.Size;
          may_dealloc = false;
        }
    }
      
    /*!
      \brief Move-constructs.
    */
    CUDA_HOS_DEV split_member_array (split_member_array &&s)
    {
      if constexpr(g24_lib::Definitions::print_memory_debug_info)
        {
      std::cout << "Move construct " << this << " from " << &s  << std::endl;
        }
      operate_on_all_members([&s](auto *p)
                        {
                          constexpr g24_lib::Definitions::default_unsigned_indexer num = std::remove_reference_t<decltype(*p)>::number;
                          p->arr = s.holder<num>::arr;
                          s.holder<num>::arr = nullptr;
                        }
                    );
      Size = s.Size;
      may_dealloc = s.may_dealloc;
      s.Size = 0;
    }
      
    /*!
      \brief Assignment operator. The behaviour will depend on the template parameter
             \p default_is_copy, with there being allocations if `true`
             and a simple pointer copy if it is `false`.
    */
    CUDA_HOS_DEV split_member_array& operator= (const split_member_array &s)
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
          operate_on_all_members([this](auto *p)
                            {
                              constexpr g24_lib::Definitions::default_unsigned_indexer num = std::remove_reference_t<decltype(*p)>::number;
                              memory_manager<num>::deallocate(p->arr, this->Size);
                              p->arr = nullptr;
                            }
                        );
          Size = 0;
        }
      if(default_is_copy)
        {
          if(Size != s.Size || !may_dealloc)
            {
              Size = s.Size;
              operate_on_all_members([this](auto *p)
                                {
                                  constexpr g24_lib::Definitions::default_unsigned_indexer num = std::remove_reference_t<decltype(*p)>::number;
                                  p->arr = memory_manager<num>::allocate(this->Size);
                                }
                            );
            }
          operate_on_all_members([&s](auto *p)
                            {
                              constexpr g24_lib::Definitions::default_unsigned_indexer num = std::remove_reference_t<decltype(*p)>::number;
                              memory_manager<num>::template copy<memory_manager<num>>(p->arr, s.holder<num>::arr, s.Size);
                            }
                        );
          may_dealloc = true;
        }
      else
        {
        operate_on_all_members([&s](auto *p)
                          {
                            constexpr g24_lib::Definitions::default_unsigned_indexer num = std::remove_reference_t<decltype(*p)>::number;
                            p->arr = s.holder<num>::arr;
                          }
                      );
          Size = s.Size;
          may_dealloc = false;
        }
      return (*this);
    }
      
    /*!
      \brief Move-assignment operator.
    */
    CUDA_HOS_DEV split_member_array& operator= (split_member_array &&s)
    {
      if constexpr(g24_lib::Definitions::print_memory_debug_info)
        {
      std::cout << "Move to " << this << " from " << &s << std::endl;
        }
      if(this == &s)
        {
          return (*this);
        }
      operate_on_all_members([this, &s](auto *p)
                        {
                          constexpr g24_lib::Definitions::default_unsigned_indexer num = std::remove_reference_t<decltype(*p)>::number;
                          if (this->may_dealloc)
                            {
                              memory_manager<num>::deallocate(p->arr, this->Size);
                            }
                          p->arr = s.holder<num>::arr;
                          s.holder<num>::arr = nullptr;
                        }
                    );
      Size = s.Size;
      may_dealloc = s.may_dealloc;
      s.Size = 0;
      return (*this);
    }
      
    /*!
      \brief Copy-constructs from another memory context.
             If, by any reason, the user wants to force the pointer to be copied
             instead of performing allocations, \p `copy` can be put to false.
    */
    template < template<class, class> class other_manager, bool other_bool>
    CUDA_ONLY_HOS split_member_array (const split_member_array<Type, indexer, other_manager, other_bool> &s, const bool copy = default_is_copy)
    {
      if constexpr(g24_lib::Definitions::print_memory_debug_info)
        {
      std::cout << "Convert-construct " << this << " from " << &s  << std::endl;
        }
      if (copy || !std::is_same<typename memory_manager_type<Type, indexer>::memory_location,
                                typename other_manager<Type, indexer>::memory_location >::value)
        {
          operate_on_all_members([&s](auto *p)
                            {
                              constexpr g24_lib::Definitions::default_unsigned_indexer num = std::remove_reference_t<decltype(*p)>::number;
                              p->arr = memory_manager<num>::allocate(s.Size);
                              memory_manager<num>::template copy<other_manager<hold_t<num>, indexer>>(arr, s.holder<num>::arr, s.Size);
                            }
                        );
          Size = s.Size;
          may_dealloc = true;
        }
      else
        {
          operate_on_all_members([&s](auto *p)
                            {
                              constexpr g24_lib::Definitions::default_unsigned_indexer num = std::remove_reference_t<decltype(*p)>::number;
                              p->arr = s.holder<num>::arr;
                            }
                        );
          Size = s.Size;
          may_dealloc = false;
        }
    }
      
    /*!
      \brief Move-constructs from another memory context.
    */
    template <template <class, class> class other_manager, bool other_bool>
    CUDA_ONLY_HOS split_member_array (split_member_array<Type, indexer, other_manager, other_bool> &&s)
    {
      if constexpr(g24_lib::Definitions::print_memory_debug_info)
        {
      std::cout << "Convert-move- construct " << this << " from " << &s  << std::endl;
        }
      Size = s.Size;
      if(s.may_dealloc)
        {
          operate_on_all_members([&s](auto *p)
                            {
                              constexpr g24_lib::Definitions::default_unsigned_indexer num = std::remove_reference_t<decltype(*p)>::number;
                              p->arr = nullptr;
                              memory_manager<num>::template move<other_manager<hold_t<num>, indexer>>(arr, s.holder<num>::arr, 0, s.Size);
                              s.holder<num>::arr = nullptr;
                            }
                        );
          s.Size = 0;
          may_dealloc = true;
        }
      else if(std::is_same<typename memory_manager_type<Type, indexer>::memory_location,
                                typename other_manager<Type, indexer>::memory_location >::value && !s.may_dealloc)
        {
          operate_on_all_members([&s](auto *p)
                            {
                              constexpr g24_lib::Definitions::default_unsigned_indexer num = std::remove_reference_t<decltype(*p)>::number;
                              p->arr = s.holder<num>::arr;
                              s.holder<num>::arr = nullptr;
                            }
                        );
          may_dealloc = false;
          s.Size = 0;
        }
      else if(!s.may_dealloc && !std::is_same<typename memory_manager_type<Type, indexer>::memory_location,
                                typename other_manager<Type, indexer>::memory_location >::value)
        {
          operate_on_all_members([&s](auto *p)
                            {
                              constexpr g24_lib::Definitions::default_unsigned_indexer num = std::remove_reference_t<decltype(*p)>::number;
                              p->arr = memory_manager<num>::allocate(s.Size);
                              memory_manager<num>::template copy<other_manager<hold_t<num>, indexer>>(p->arr, s.holder<num>::arr, s.Size);
                              s.holder<num>::arr = nullptr;
                            }
                        );
          may_dealloc = true;
          s.Size = 0;
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
    template<template <class, class> class other_manager, bool other_bool>
    CUDA_ONLY_HOS split_member_array& operator= (const split_member_array <Type, indexer, other_manager, other_bool>&s)
    {
      if constexpr(g24_lib::Definitions::print_memory_debug_info)
        {
      std::cout << "Copy-convert " << this << " from " << &s << std::endl;
        }
      if constexpr(std::is_same_v<other_manager<Type, indexer>, memory_manager_type<Type, indexer>> && default_is_copy == other_bool)
        {
          if(&s == this)
            {
              return (*this);
            }
        }
      if(!may_dealloc)
        {
          operate_on_all_members([](auto *p)
                            {
                              p->arr = nullptr;
                            }
                        );
          Size = 0;
        }
      if(default_is_copy || !std::is_same<typename memory_manager_type<Type, indexer>::memory_location,
                                typename other_manager<Type, indexer>::memory_location >::value)
        {
          if(Size != s.Size || !may_dealloc)
            {
              operate_on_all_members([this, &s](auto *p)
                                {
                                  constexpr g24_lib::Definitions::default_unsigned_indexer num = std::remove_reference_t<decltype(*p)>::number;
                                  memory_manager<num>::deallocate(p->arr, this->Size);
                                  p->arr = memory_manager<num>::allocate(s.Size);
                                }
                            );
              Size = s.Size;
            }
          operate_on_all_members([&s](auto *p)
                            {
                              constexpr g24_lib::Definitions::default_unsigned_indexer num = std::remove_reference_t<decltype(*p)>::number;
                              memory_manager<num>::template copy<other_manager<hold_t<num>, indexer>>(p->arr, s.holder<num>::arr, s.Size);
                            }
                        );
          may_dealloc = true;
        }
      else //default_is_copy = false && memory managers the same
        {
          operate_on_all_members([&s](auto *p)
                            {
                              constexpr g24_lib::Definitions::default_unsigned_indexer num = std::remove_reference_t<decltype(*p)>::number;
                              memory_manager<num>::deallocate(p->arr, Size);
                              p->arr = s.holder<num>::arr;
                            }
                        );
          may_dealloc = false;
          Size = s.Size;
        }
      return (*this);
    }
      
    /*!
      \brief Move-assignment operator from another memory context.
    */ 
    template<template <class, class> class other_manager, bool other_bool>
    CUDA_ONLY_HOS split_member_array& operator= (split_member_array <Type, indexer, other_manager, other_bool>&&s)
    { 
      if constexpr(g24_lib::Definitions::print_memory_debug_info)
        {
      std::cout << "Move-convert " << this << " from " << &s << std::endl;
        }
      if constexpr(std::is_same_v<other_manager<Type, indexer>, memory_manager_type<Type, indexer>> && default_is_copy == other_bool)
        {
          if(&s == this)
            {
              return (*this);
            }
        }
      if(!may_dealloc)
        {
          operate_on_all_members([](auto *p)
                            {
                              p->arr = nullptr;
                            }
                        );
          Size = 0;
        }        
      if(s.may_dealloc)
        {
          operate_on_all_members([&s](auto *p)
                            {
                              constexpr g24_lib::Definitions::default_unsigned_indexer num = std::remove_reference_t<decltype(*p)>::number;
                              memory_manager<num>::template move<other_manager<hold_t<num>, indexer>>(p->arr, s.holder<num>::arr, s.Size);
                              s.holder<num>::arr = nullptr;
                            }
                        );
          Size = s.Size;
          s.Size = 0;
          may_dealloc = true;
        }
      else if(std::is_same<typename memory_manager_type<Type, indexer>::memory_location,
                           typename other_manager<Type, indexer>::memory_location >::value && !s.may_dealloc)
        {
          operate_on_all_members([&s](auto *p)
                            {
                              constexpr g24_lib::Definitions::default_unsigned_indexer num = std::remove_reference_t<decltype(*p)>::number;
                              p->arr = s.holder<num>::arr;
                              s.holder<num>::arr = nullptr;
                            }
                        );
          Size = s.Size;
          may_dealloc = false;
          s.Size = 0;
        }
      else
        {
          operate_on_all_members([&s](auto *p)
                            {
                              constexpr g24_lib::Definitions::default_unsigned_indexer num = std::remove_reference_t<decltype(*p)>::number;
                              p->arr = memory_manager<num>::allocate(s.Size);
                              memory_manager<num>::template copy<other_manager<hold_t<num>, indexer>>(p->arr, s.holder<num>::arr, s.Size);
                              s.holder<num>::arr = nullptr;
                            }
                        );
          may_dealloc = true;
          Size = s.Size;
          s.Size = 0;
        }
      return (*this);
    }
            
    CUDA_HOS_DEV ~split_member_array()
    {
      if constexpr(g24_lib::Definitions::print_memory_debug_info)
        {
          std::cout << "Deconstruct " << this << std::endl;
        }
      operate_on_all_members([this](auto *p)
                        {
                          constexpr g24_lib::Definitions::default_unsigned_indexer num = std::remove_reference_t<decltype(*p)>::number;
                          if (this->may_dealloc)
                            {
                              memory_manager<num>::deallocate(p->arr, this->Size);
                            }
                          p->arr = nullptr;
                        }
                    );
    }
            
    /*!
      \brief Gives direct access to the underlying array.
      
      \warning This gives actual access to the raw array. It shouldn't absolutely be used
               unless the user is really, really sure of what will be done.
    */
    template <class num>
    CUDA_HOS_DEV Type*& get_access_to_array()
    {
      return holder<num>::arr;
    }
      
    /*!
      \brief Gives direct access to the underlying array.
      
      \warning This gives actual access to the raw array. It shouldn't absolutely be used
               unless the user is really, really sure of what will be done.
    */
    template <class num>
    CUDA_HOS_DEV const Type* get_access_to_array() const
    {
      return holder<num>::arr;
    }
    
    /*!
      \remark If the array is held in non-addressable memory, a local copy is created specifically for the output.
    */
    template<class stream, class str = std::basic_string<typename stream::char_type>>
    CUDA_ONLY_HOS void textual_output(stream &s, const str& separator = " ") const
    {
      if (memory_manager_type<Type, indexer>::can_operate())
        {
          g24_lib::textual_output(s, Size, separator);
          s << separator;
          operate_on_all_members([this, &s, &separator](auto *p)
                            {
                              for (indexer i = 0; i < this->Size; ++i)
                                {
                                  g24_lib::textual_output(s, p->arr[i], separator);
                                  s << separator;
                                }
                              s << separator;
                            }
                        );
        }
      else
        {
          split_member_array<Type, indexer, MemoryContext::current_manager> temp(*this);
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
      if (memory_manager_type<Type, indexer>::can_operate())
        {
          indexer new_size;
          g24_lib::textual_input(s, new_size);
          if(s.fail())
            {
              exceptions::throw_exception(exceptions::array_length_misread(""));
            }
          split_member_array temp(new_size);
          temp.operate_on_all_members([&s, new_size](auto *p)
                                {
                                  for (indexer i = 0; i < new_size; ++i)
                                    {
                                      g24_lib::textual_input(s, p->arr[i]);
                                    }
                                }
                            );
          (*this) = temp;
        }
      else
        {
          split_member_array<Type, indexer, MemoryContext::current_manager> temp;
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
      if (memory_manager_type<Type, indexer>::can_operate())
        {
          g24_lib::binary_output(s, Size);
          temp.operate_on_all_members([&s, this](auto *p)
                                {
                                  for (indexer i = 0; i < this->Size; ++i)
                                    {
                                      g24_lib::binary_output(s, p->arr[i]);
                                    }
                                }
                            );
        }
      else
        {
          split_member_array<Type, indexer, MemoryContext::current_manager> temp(*this);
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
      if (memory_manager_type<Type, indexer>::can_operate())
        {
          indexer new_size;
          g24_lib::binary_input(s, new_size);
          if(s.fail())
            {
              exceptions::throw_exception(exceptions::array_length_misread(""));
            }
          split_member_array temp(new_size);
          temp.operate_on_all_members([&s, new_size](auto *p)
                                {
                                  for (indexer i = 0; i < new_size; ++i)
                                    {
                                      g24_lib::binary_input(s, p->arr[i]);
                                    }
                                }
                            );
          (*this) = temp;
        }
      else
        {
          split_member_array<Type, indexer, MemoryContext::current_manager> temp;
          temp.binary_input(s);
          (*this) = temp;
        }
    }
#if CUDA_AVAILABLE
    /*!
      \brief Converts the `g24_lib::split_member_array` to a form that can easily be passed to \c CUDA kernels.
      
      \remark This may either copy the pointer, if the memory already resides in the GPU,
              or allocate new memory in the GPU, in case the memory resides elsewhere.
              In this case, any changes made to the array in the GPU will be lost after destruction
              since the array will not be copied back!
    */
    CUDA_ONLY_HOS split_member_array<Type, indexer, CUDA_memory_manager, false> to_CUDA() const
    {
      return split_member_array<Type, indexer, CUDA_memory_manager, false>(*this);
    }
#endif

    private:
    
    template <g24_lib::Definitions::default_unsigned_indexer num>
    CUDA_HOS_DEV inline const hold_t<num>& get_element (const indexer i) const
    {
      return this->holder<num>::arr[i];
    }
    
    template <g24_lib::Definitions::default_unsigned_indexer num>
    CUDA_HOS_DEV inline hold_t<num>& get_element (const indexer i)
    {
      return this->holder<num>::arr[i];
    }
    
    CUDA_HOS_DEV inline flat_imitation_struct<Type> construct_imitation (const indexer i) const
    {
      flat_imitation_struct<Type> ret;
      
      operate_on_all_members([&ret, i](auto *p)
                      {
                        constexpr g24_lib::Definitions::default_unsigned_indexer num = std::remove_reference_t<decltype(*p)>::number;
                        ret.template get_element<num>() = p->arr[i];
                      }
                    );
      return ret;
    }
    
    
    public:
    
    /*!
      \brief An interface for the object held in the `g24_lib::split_member_array`
             so they can be changed through an `operator=`.
    */
    struct split_member_accessor
    {
    private:
      /*!
        \brief A pointer to the array being accessed.
        
        \remark This makes split_member_accessor possibly invalidated
                if the array goes out of scope and/or is passed to CUDA,
                but that would only occur if this was being misused.
      */
      split_member_array *arr;
      /*!
        \brief The index of the element being accessed.
      */
      indexer idx;
    public:
      
      /*!
        \brief Construct a split_member_accessor. The end-user probably
               shouldn't need to do this, but...
               
      */
      CUDA_HOS_DEV split_member_accessor(split_member_array *a, const indexer i): arr(a), idx(i) {}
      
      CUDA_HOS_DEV split_member_accessor& operator= (const g24_lib::flat_imitation_struct<Type> &imit)
      {        
        arr->operate_on_all_members([&imit, this](auto *p)
                              {
                                constexpr g24_lib::Definitions::default_unsigned_indexer num = std::remove_reference_t<decltype(*p)>::number;
                                p->arr[this->idx] = imit.template get_element<num>();
                              }
                            );
        
        return (*this);
      }
      
      /*!
        \brief Returns the i-th element of the struct using the ordering from `g24_lib::class_info::true_type`,
               including 1-indexing.
         
        \warning The elements are 1-indexed!
      */
      template <g24_lib::Definitions::default_unsigned_indexer I> CUDA_HOS_DEV const auto& get_element() const
      {
        return arr->holder<I>::arr[idx];
      }
      
      /*!
        \brief Returns the i-th element of the struct using the ordering from `g24_lib::class_info::true_type`,
               including 1-indexing.
         
        \warning The elements are 1-indexed!
      */
      template <g24_lib::Definitions::default_unsigned_indexer I> CUDA_HOS_DEV auto& get_element()
      {
        return arr->holder<I>::arr[idx];
      }
      
      /*!
        \brief Returns the i-th element of the struct using the ordering from `g24_lib::class_info::true_type`,
               but with 0-indexing.
               
        \details Provided for compatibility with structured bindings.
         
        \warning The elements are 0-indexed!
      */
      template <g24_lib::Definitions::default_unsigned_indexer I> CUDA_HOS_DEV const auto& get() const
      {
        return get_element<I+1>();
      }
      
      /*!
        \brief Returns the i-th element of the struct using the ordering from `g24_lib::class_info::true_type`,
               but with 0-indexing.
               
        \details Provided for compatibility with structured bindings.
         
        \warning The elements are 0-indexed!
      */
      template <g24_lib::Definitions::default_unsigned_indexer I> CUDA_HOS_DEV auto& get()
      {
        return get_element<I+1>();
      }
      
      CUDA_ONLY_HOS operator flat_imitation_struct<Type>() const
      {
        return arr->construct_imitation(idx);
      }
      
      CUDA_HOS_DEV operator Type() const
      {
        return arr->construct_imitation(idx).to_type();
      }
      
    };
    
    friend struct split_member_accessor;
    
    CUDA_HOS_DEV inline split_member_accessor operator[] (const indexer i)
    {
      return split_member_accessor(this, i);
    }
    
    /*!
      \brief An interface for the object held in the `g24_lib::split_member_array`
             so they can be changed through an `operator=`.
    */
    struct const_split_member_accessor
    {
    private:
      /*!
        \brief A pointer to the array being accessed.
        
        \remark This makes split_member_accessor possibly invalidated
                if the array goes out of scope and/or is passed to CUDA,
                but that would only occur if this was being misused.
      */
      const split_member_array *arr;
      /*!
        \brief The index of the element being accessed.
      */
      const indexer idx;
    public:
      
      /*!
        \brief Construct a split_member_accessor. The end-user probably
               shouldn't need to do this, but...
               
      */
      CUDA_HOS_DEV const_split_member_accessor(const split_member_array *a, const indexer i): arr(a), idx(i) {}
      
/*!
    \brief Returns the i-th element of the struct using the ordering from `g24_lib::class_info::true_type`,
           including 1-indexing.
     
    \warning The elements are 1-indexed!
*/
      template <g24_lib::Definitions::default_unsigned_indexer I> CUDA_HOS_DEV const auto& get_element() const
      {
        return arr->holder<I>::arr[idx];
      }
      
/*!
    \brief Returns the i-th element of the struct using the ordering from `g24_lib::class_info::true_type`,
           but with 0-indexing.
           
    \details Provided for compatibility with structured bindings.
     
    \warning The elements are 0-indexed!
*/
      template <g24_lib::Definitions::default_unsigned_indexer I> CUDA_HOS_DEV const auto& get() const
      {
        return get_element<I+1>();
      }
      
      CUDA_ONLY_HOS operator flat_imitation_struct<Type>() const
      {
        return arr->construct_imitation(idx);
      }
      
      CUDA_HOS_DEV operator Type() const
      {
        return arr->construct_imitation(idx).to_type();
      }
      
    };
    
    friend struct const_split_member_accessor;

      
    CUDA_HOS_DEV inline const_split_member_accessor operator[] (const indexer i) const
    {
      return const_split_member_accessor(this, i);
    }
    
    template <class container, class enabler = std::enable_if_t< std::is_same_v< Type, g24_lib::value_type<container> > > >
    CUDA_HOS_DEV inline explicit operator container() const
    {
      if (memory_manager_type<Type, indexer>::can_operate())
        {
          container ret(Size);
          for (indexer  i = 0; i < Size; ++i)
            {
              ret[i] = this->construct_imitation(i).to_type();
            }
          return ret;
        }
      else
        {
          split_member_array<Type, indexer, MemoryContext::current_manager> temp(*this);
          return container(temp);
        }
    }
    
    
    /*!
      \brief Copy-constructs from a generic container with a known \p size.
      
      \pre `a[i]` must give the `i`-th element.
    */     
    template<class ArrLike, class enable = std::enable_if_t< !std::is_same_v<ArrLike, Type> &&
                                                             std::is_same_v< Type, g24_lib::value_type<ArrLike> > > >
    CUDA_ONLY_HOS explicit split_member_array(const indexer size, const ArrLike &a)
    { 
      if (memory_manager_type<Type, indexer>::can_operate())
        {
          operate_on_all_members([size](auto *p)
                          {
                            constexpr g24_lib::Definitions::default_unsigned_indexer num = std::remove_reference_t<decltype(*p)>::number;
                            p->arr = memory_manager<num>::allocate(size);
                          }
                        );
          for (indexer i = 0; i < size; ++i)
            {
              flat_imitation_struct<Type> imit(a[i]);
              operate_on_all_members([i, &imit](auto *p)
                              {
                                constexpr g24_lib::Definitions::default_unsigned_indexer num = std::remove_reference_t<decltype(*p)>::number;
                                p->arr[i] = imit.template get_element<num>();
                              }
                            );
            }
          Size = size;
          may_dealloc = true;
        }
      else
        {
          split_member_array<Type, indexer, MemoryContext::current_manager> temp(size, a);
          (*this) = temp;
        }
    }
    
    /*!
      \brief Copy-constructs from a generic container with a `size()` member function.
             
      \pre `a[i]` must give the `i`-th element.
    */
    template<class ArrLike, class disabler = std::enable_if_t< !std::is_integral_v<ArrLike> &&
                                                               std::is_same_v< Type, g24_lib::value_type<ArrLike> > > >
    CUDA_ONLY_HOS explicit split_member_array(const ArrLike &a)
    {
      if (memory_manager_type<Type, indexer>::can_operate())
        {
          Size = a.size();
          operate_on_all_members([this](auto *p)
                          {
                            constexpr g24_lib::Definitions::default_unsigned_indexer num = std::remove_reference_t<decltype(*p)>::number;
                            p->arr = memory_manager<num>::allocate(this->Size);
                          }
                        );
          for (indexer i = 0; i < a.size(); ++i)
            {
              flat_imitation_struct<Type> imit(a[i]);
              operate_on_all_members([i, &imit](auto *p)
                              {
                                constexpr g24_lib::Definitions::default_unsigned_indexer num = std::remove_reference_t<decltype(*p)>::number;
                                p->arr[i] = imit.template get_element<num>();
                              }
                            );
              may_dealloc = true;
            }
        }
      else
        {
          split_member_array<Type, indexer, MemoryContext::current_manager> temp(a);
          (*this) = temp;
        }
    }
    

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
          split_array<Type, indexer, typename parallel::template memory_manager<Type, indexer>> temp(*this);
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
    \brief A `g24_lib::split_member_array` that holds the array in the memory appropriate for the current context.
    
    \tparam Type The type of the objects in the array.
    
    \tparam num A type that is appropriate to hold sizes of objects.
    
    \pre \p num must satisfy the constraints placed on the choice of \ref g24_lib::Definitions::default_unsigned_indexer.
  */
  template <class Type, class num = g24_lib::Definitions::default_unsigned_indexer> using split_array =
    split_member_array <Type, num, MemoryContext::current_manager, true>;  
  
  
  /*!
    \brief A `g24_lib::split_member_array` that holds the array in the usual, CPU-addressable memory.
    
    \tparam Type The type of the objects in the array.
    
    \tparam num A type that is appropriate to hold sizes of objects.
    
    \pre \p num must satisfy the constraints placed on the choice of \ref g24_lib::Definitions::default_unsigned_indexer.
  */
  template <class Type, class num = g24_lib::Definitions::default_unsigned_indexer> using cpu_split_array =
    split_member_array <Type, num, default_memory_manager, true>;
    
  /*!
    \brief A `g24_lib::split_member_array` that holds the array in the memory of a \c CUDA-enabled GPU.
    
    \tparam Type The type of the objects in the array.
    
    \tparam num A type that is appropriate to hold sizes of objects.
    
    \pre \p num must satisfy the constraints placed on the choice of \ref g24_lib::Definitions::default_unsigned_indexer.
  */
  template <class Type, class num = g24_lib::Definitions::default_unsigned_indexer> using cuda_split_array =
    split_member_array <Type, num, CUDA_memory_manager, true>;
    
    
  /*!
    \brief The appropriate way to pass a `g24_lib::split_member_array` into a \c CUDA kernel.
           Will copy the pointer if the memory already resides in the GPU,
           so the original array will be addressed and will experience any changes dictated by the kernel.
    
    \tparam Type The type of the objects in the array.
    
    \tparam num A type that is appropriate to hold sizes of objects.
    
    \pre \p num must satisfy the constraints placed on the choice of \ref g24_lib::Definitions::default_unsigned_indexer.
    
    \remark Since there is `g24_lib::to_CUDA` (and all the abstractions in `g24_lib::Parallelism`),
            it should no longer be necessary to explicitly convert to this class to pass things into a kernel.
  */
  template <class Type, class num = g24_lib::Definitions::default_unsigned_indexer> using cuda_kernel_split_array =
    split_member_array <Type, num, CUDA_memory_manager, false>;

  
  /*!
    \brief A `g24_lib::split_member_array` that holds the array in a way that is appropriate for a specific type of parallelism.
    
    \tparam Type The type of the objects in the array.
    
    \tparam num A type that is appropriate to hold sizes of objects.
    
    \tparam parallel A type of parallelism.
    
    \pre \p num must satisfy the constraints placed on the choice of \ref g24_lib::Definitions::default_unsigned_indexer.
    
    \pre \p parallel must be a valid type of parallelism, that is, it must satisfy `g24_lib::is_parallelism`.
    
  */
  template <class parallel, class Type, class num = g24_lib::Definitions::default_unsigned_indexer >
  using split_array_parallel = split_member_array <Type, num, parallel::template memory_manager, true>;

}



#endif
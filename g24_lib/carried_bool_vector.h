#ifndef G24_LIB_CARRIED_BOOL_VECTOR
#define G24_LIB_CARRIED_BOOL_VECTOR

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

\file carried_bool_vector.h

\brief Defines `g24_lib::carried_bool_vector`, a compact form to store arrays of booleans
       by packing them into bits.
       

\author Nuno Fernandes (main coder, current maintainer)

\author Gonçalo Vaz (past auxiliary coder and tester)

*/


namespace g24_lib
{
  
  /*!
    \brief A container that holds an array of booleans in a given memory context
           in a space efficient way, by packing them as the binary representation of another object. 
    
    \tparam Block The type of the objects whose binary representation will hold the booleans (the blocks).
    
    \tparam indexer A type that is appropriate to hold the size of the array.
    
    \tparam memory_manager The memory manager corresponding to the memory context where the array will be held.
    
    \tparam default_is_copy See `g24_lib::simple_array`.
    
    \pre \p Block must support bitwise operations and should not have padding
            (that is, all bytes must be part of the object's data). In essence,
            one should use something that behaves like an integer type.
    
    \pre \p indexer must satisfy the constraints placed on the choice
                    of \ref g24_lib::Definitions::default_unsigned_indexer.
    
    \pre \p memory_manager must be a valid memory manager, that is,
            `g24_lib::is_memory_manager<memory_manager>` should be `true`.
            
    \remark Though most mainstream implementations of `std::vector<bool>`
            are a template specialization that packs the booleans in a way
            quite similar to what's achieved here, it is not mandated by
            the standard to work that way. There are some trade-offs
            since accessing a bool requires bitwise operations 
              
    \todo Implement generalized construction from any form of container
          that returns booleans with `operator[]`.
  */
  template <class Block, class indexer = g24_lib::Definitions::default_unsigned_indexer,
            class memory_manager = default_memory_manager<Block, indexer>,
            bool default_is_copy = true>
  class carried_bool_vector
  {
  public:
    template <class a, class b, class c, bool d> friend class carried_bool_vector;
  
    typedef Block block_type;
    typedef indexer indexer_type;
    typedef bool value_type;
  private:
    /*!
      \brief Total number of booleans held, not the size of the array of blocks!
    */
    indexer Size;
    simple_array <Block, indexer, memory_manager, default_is_copy> arr;
    
  public:
        
    /*!
      \brief An interface for the booleans held in the `g24_lib::carried_bool_vector`
             so they can be changed through an `operator=`.
    */
    struct bool_accessor
    {
    private:
      /*!
        \brief The pointer to the `Block` that holds the boolean.
      */
      Block* val;
      /*!
        \brief The offset from the beginning of the `Block`.
        
        \remark The way this is constructed requires 
      */
      indexer num;
    public:
      /*!
        \brief The number of booleans (bits) held in each block.
      */
      static constexpr indexer chunk = sizeof(Block)*CHAR_BIT;
      
      /*!
        \brief Construct a bool_accessor. The end-user probably
               shouldn't need to do this, but...
               
        \pre \p i should be smaller than `chunk`.
             In other words, `i % chunk == i` must be true.
      */
      CUDA_HOS_DEV bool_accessor(Block *v, indexer i): val(v), num(i) {}
      
      /*!
        \brief Allows one to change the value of a single boolean.
        
        \warning This is not safe for multithreaded operations
                 unless different blocks are being accessed.
         
        \remark The access will surely be thread safe if the difference
                of the indices of the accessed booleans is greater than
                `chunk`, though particular cases can be constructed
                where a smaller difference still allows for thread safety.
                (Edge case: accessing the last boolean in a block and the first
                 boolean in the next will be perfectly thread-safe.)
      */
      CUDA_HOS_DEV bool_accessor& operator= (const bool b)
      {
        *val = (*val | Block(Block(b) << num)) & ~Block(Block(!b) << num);
        return (*this);
      }
      
      CUDA_HOS_DEV operator bool() const
      {
        return (*val & (Block) 1 << num);
      }
    };
    
    /*!
      \brief The number of booleans (bits) held in each block.
    */
    static constexpr indexer chunk = sizeof(Block)*CHAR_BIT;
    
    /*!
      \brief The total number of booleans held in the carried_bool_vector.
      
      \remark Actual total capacity might be slightly larger
              if the requested size is not a multiple of \ref chunk :
              the highest bits of the last block will be ignored.
              
      \sa g24_lib::carried_bool_vector::blocks()
    */
    CUDA_HOS_DEV inline indexer size() const
    {
      return Size;
    }
    
    /*!
      \brief The number of blocks needed to hold all the
      
      \brief Total capacity will be given by multiplying the return value by \ref chunk.
      
      \sa g24_lib::carried_bool_vector::size()
    */
    CUDA_HOS_DEV inline indexer blocks() const
    //The total number of blocks
    {
      return arr.size();
    }
    
    /*!
      \brief See `g24_lib::simple_array::deallocatable()`.
    */
    CUDA_HOS_DEV inline bool deallocatable() const
    {
      return arr.deallocatable();
    }
  
    /*!
      \brief Sets all booleans to \p to_what.
    */
    CUDA_HOS_DEV inline void set_all_simple(const bool to_what)
    {
      arr.set_all_simple(to_what * (~(Block(0))));
      //So, if to_what is true, all 1,
      //else, all 0.
    }
  
    /*!
      \brief Sets all booleans to \p to_what.
      
      \deprecated Provided only for compatibility with older code.
                  Equivalent to `g24_lib::carried_bool_vector::set_all_simple()`
                  except for the default value.
    */
    CUDA_HOS_DEV inline void reset(const bool to_what = false)
    {
      set_all_simple(to_what);
    }
    
    /*!
      \brief Clears the memory needed for holding the array.
    */
    CUDA_ONLY_HOS inline void clear()
    {
      arr.clear();
      //This works whether arr is deallocatable or not,
      //since, in the latter case, we can just set the pointer to null.
      Size = 0;
    }
    
    /*!
      \brief Gives direct access to the underlying array.
      
      \warning This gives actual access to the raw array. It shouldn't absolutely be used
               unless the user is really, really sure of what will be done.
    */
    CUDA_HOS_DEV inline Block*& get_access_to_array()
    {
      return arr.get_access_to_array();
    }
    
    /*!
      \brief Gives direct access to the underlying array.
      
      \warning This gives actual access to the raw array. It shouldn't absolutely be used
               unless the user is really, really sure of what will be done.
    */
    CUDA_HOS_DEV inline const Block* get_access_to_array() const
    {
      return arr.get_access_to_array();
    }
    
  private:
    CUDA_ONLY_HOS indexer calculate_array_size(const indexer number_of_bools) const
    {
      return (number_of_bools/chunk + (number_of_bools % chunk != 0));
    }
  public:
    
    CUDA_ONLY_HOS void resize(const indexer new_size)
    {
      indexer new_numb = calculate_array_size(new_size);
      arr.resize(new_numb);
      Size = new_size;
    }
    
  private:
    
    /*!
      \brief Updates the array of blocks from a thing of size \p size
             which allows access to its elements through `operator[]`.
    */
    template<class container> CUDA_ONLY_HOS void update_from_container(array<Block, indexer> & arr,
                                                                       const container &c,
                                                                       const indexer size)
    {
      Size = size;
      arr.resize(calculate_array_size(size));
      arr.set_all_simple(0);
      for (indexer i = 0; i < size; ++i)
        {
          arr[i/chunk] |= ((Block) c[i]) << (i % chunk);
        }
      /*
        indexer i, j;
        for(i = 0; i < arr.size(); ++i)
        {
        arr[i] = 0;
        if(i == arr.size() - 1)
        {
        for(j = 0; chunk*i+j < Size; ++j)
        {
        arr[i] |= ((Block) c[chunk*i + j]) << j;
        }
        }
        else
        {
        for(j = 0; j < chunk; ++j)
        {
        arr[i] |= ((Block) c[chunk*i + j]) << j;
        }
        }
        }
      */
    }
    
    /*!
      \brief Updates the array of blocks from a thing that has a `size()` member function
             and allows access to its elements through `operator[]`.
    */
    template<class container> CUDA_ONLY_HOS void update_from_container(array<Block, indexer> & arr,
                                                                       const container &c)
    {
      update_from_container(arr, c, c.size());
    }
    
  public:
  
    /*!
      \brief Default-construct as empty.
    */
    CUDA_ONLY_HOS carried_bool_vector(): Size(0)
    {
    }
    
    /*!
      \brief Construct an array of \p sz booleans.
    */
    CUDA_ONLY_HOS carried_bool_vector(const indexer sz): Size(sz), arr(calculate_array_size(sz))
    {
    }
        
    /*!
      \brief Construct from a `g24_lib::simple_array` of booleans.
    */
    template<class other_manager, bool copy>
    CUDA_ONLY_HOS carried_bool_vector(const simple_array<bool, indexer, other_manager, copy> &v):
      Size(v.size())
    {
      array<Block, indexer> temparr;
      array<bool, indexer> tempcont(v);
      update_from_container(temparr, tempcont);
      arr = temparr;
      //This is to ensure we can update things from other memory managers
    }
    
    /*!
      \brief Copy-constructs from a generic container with a known \p size.
      
      \pre `a[i]` must give the `i`-th boolean.
    */     
    template<class ArrLike, class disabler = std::enable_if_t<!std::is_same_v<ArrLike, bool>>>
    CUDA_ONLY_HOS explicit carried_bool_vector(const indexer size, const ArrLike &a)
    { 
      array<Block, indexer> temparr;
      update_from_container(temparr, a, size);
      arr = temparr;
      //This is to ensure we can update things from other memory managers
    }
    
    /*!
      \brief Copy-constructs from a generic container with a `size()` member function.
             
      \pre `a[i]` must give the `i`-th boolean.
    */
    template<class ArrLike, class disabler = std::enable_if_t<!std::is_integral_v<ArrLike>>>
    CUDA_ONLY_HOS explicit carried_bool_vector(const ArrLike &a)
    {
      array<Block, indexer> temparr;
      update_from_container(temparr, a);
      arr = temparr;
    }
     
     
    /*!
      \brief Copy-construct. For the effects of \p default_is_copy, see copy-constructor of \ref g24_lib::simple_array.
    */
    CUDA_ONLY_HOS carried_bool_vector(const carried_bool_vector &v, const bool copy = default_is_copy):
      Size(v.Size), arr(v.arr, copy)
    {
    }
    
    /*!
      \brief Move-construct.
    */
    CUDA_ONLY_HOS carried_bool_vector(carried_bool_vector &&v):
      Size(v.Size), arr(v.arr)
    {
    }
    
    /*!
      \brief Copy-construct from a different memory context.
             For the effects of \p default_is_copy, see copy-constructor of \ref g24_lib::simple_array.
    */
    template<class other_manager, bool other_bool>
    CUDA_ONLY_HOS carried_bool_vector( const carried_bool_vector<Block, indexer, other_manager, other_bool> &v,
                                       const bool copy = default_is_copy ):
      Size(v.Size), arr(v.arr, copy)
    {
    }
    
    /*!
      \brief Move-construct from a different memory context.
    */
    template<class other_manager, bool other_bool>
    CUDA_ONLY_HOS carried_bool_vector(carried_bool_vector<Block, indexer, other_manager, other_bool> &&v):
      Size(v.Size), arr(v.arr)
    {
    }
        
    /*!
      \brief Assignment operator from a `g24_lib::simple_array` of booleans.
    */
    template <class other_manager, bool other_bool>
    CUDA_ONLY_HOS carried_bool_vector& operator= (const simple_array<bool, indexer, other_manager, other_bool> &c)
    {
      array<Block, indexer> temparr;
      array<bool, indexer> tempcont(c);
      update_from_container(temparr, tempcont);
      arr = temparr;
      return (*this);
    }
        
    
    /*!
      \brief Assignment operator.
    */
    CUDA_ONLY_HOS carried_bool_vector& operator= (const carried_bool_vector &v)
    {
      if(&v == this)
        {
          return (*this);
        }
      Size = v.Size;
      arr = v.arr;
      return (*this);
    }
    
    /*!
      \brief Move-assignment operator.
    */
    CUDA_ONLY_HOS carried_bool_vector& operator= (carried_bool_vector &&v)
    {
      if(&v == this)
        {
          return (*this);
        }
      Size = v.Size;
      arr = v.arr;
      return (*this);
    }
    
    
    /*!
      \brief Assignment operator from a different memory context.
    */
    template<class other_manager, bool other_bool>
    CUDA_ONLY_HOS carried_bool_vector& operator= (const carried_bool_vector<Block, indexer, other_manager, other_bool> &v)
    {
      if constexpr(std::is_same_v<other_manager, memory_manager> && other_bool == default_is_copy)
        {
          if(&v == this)
            {
              return (*this);
            }
        }
      Size = v.Size;
      arr = v.arr;
      return (*this);
    }
    
    /*!
      \brief Move-assignment operator from a different memory context.
    */
    template<class other_manager, bool other_bool>
    CUDA_ONLY_HOS carried_bool_vector& operator= (carried_bool_vector<Block, indexer, other_manager, other_bool> &&v)
    {
      if constexpr(std::is_same_v<other_manager, memory_manager> && other_bool == default_is_copy)
        {
          if(&v == this)
            {
              return (*this);
            }
        }
      Size = v.Size;
      arr = v.arr;
      return (*this);
    }
    
    /*!
      \remark Since we are dealing with a `const` version of the `carried_bool_vector`,
              we can forego the additional complexity of returning a \ref bool_accessor
              because the boolean in the array will not need to be changed.
    */
    CUDA_HOS_DEV inline bool operator[] (const indexer i) const
    {
      return ( (bool) ( arr[i/chunk] & ( ( (Block) 1 ) << i%chunk ) ) );
    }
    
    CUDA_HOS_DEV inline bool_accessor operator[] (const indexer i)
    {
      return bool_accessor(&arr[i/chunk], i%chunk);
    }
    
    /*!
      \brief Returns the block that holds the boolean with index \p i.
    */
    CUDA_HOS_DEV inline Block& block (const indexer i)
    {
      return (arr[i/chunk]);
    }
    
    /*!
      \brief Returns the block that holds the boolean with index \p i.
    */
    CUDA_HOS_DEV inline const Block& block (const indexer i) const
    {
      return (arr[i/chunk]);
    }
    
    
    /*!
      \brief Sets the boolean with index \p i to the value of \p b.
        
      \warning This is not safe for multithreaded operations
               unless different blocks are being accessed.
       
      \remark The access will surely be thread safe if the difference
              of the indices of the accessed booleans is greater than
              `chunk`, though particular cases can be constructed
              where a smaller difference still allows for thread safety.
              (Edge case: accessing the last boolean in a block and the first
               boolean in the next will be perfectly thread-safe.)
    */
    CUDA_HOS_DEV inline void write (const indexer i, const bool b)
    {
      arr[i/chunk] = (arr[i/chunk] | Block(Block(b) << i%chunk)) & ~Block(Block(!b) << i%chunk);
      //Boolean logic checks out...
    }
    
    CUDA_HOS_DEV ~carried_bool_vector()
    {
      //Default destructors will do fine.
    }    
    
    /*!
      \remark If \p as_bools is `true`, each boolean value is printed separately,
              while, if false, it prints each block.
    */
    template<class stream, class str = std::basic_string<typename stream::char_type>>
    CUDA_ONLY_HOS void textual_output(stream &s, const str& separator = " ", const bool as_bools = true) const
    {
    
      if (memory_manager::can_operate())
        {
          g24_lib::textual_output(s, Size);
          s << separator;
          if(as_bools)
            {
              for(indexer i = 0; i < Size; ++i)
              {
                g24_lib::textual_output(s, bool( ( arr[i/chunk] >> (i%chunk) ) & 1));
                s << separator;
              }
              /*
              for(indexer i = 0; i < arr.size(); ++i)
                {
                  if(i == arr.size() - 1)
                    {
                      for(indexer j = 0; i*chunk + j < Size; ++j)
                        {
                          g24_lib::textual_output(s, bool( (arr[i] >> j) & 1 ));
                          if(i*chunk + j < Size -1)
                            {
                              s << separator;
                            }
                        }
                    }
                  else
                    {
                      for(indexer j = 0; j < chunk-1; ++j)
                        {
                          g24_lib::textual_output(s, bool( (arr[i] >> j) & 1 ));
                          s << separator;
                        }
                    }
                }
              */
            }
          else
            {
              for(indexer i = 0; i < arr.size(); ++i)
                {
                  g24_lib::textual_output(s, arr[i]);
                  s << separator;
                }
            }
        }
      else
        {
          carried_bool_vector <Block, indexer, MemoryContext::current_manager<Block, indexer>, false> temp(*this);
          temp.textual_output(s, separator, as_bools);
        }
    }
    
    
    /*!
      \remark If \p as_bools is `true`, each boolean value is read separately,
              while, if false, it reads each block.
    */
    template<class stream>
    void textual_input(stream &s, const bool as_bools = true)
    {
      indexer tempind;
      bool tempboo;
      
      g24_lib::textual_input(s, tempind);
      if(s.fail())
        {
          exceptions::throw_exception(exceptions::array_length_misread(""));
        }
      
      resize(tempind);
      
      if (memory_manager::can_operate())
        {
          if(as_bools)
            {
              for(indexer i = 0; i < arr.size(); ++i)
                {
                  Block buffer = 0;
                  if(i == arr.size() - 1)
                    {
                      for(indexer j = 0; i*chunk + j < Size; ++j)
                        {
                          g24_lib::textual_input(s, tempboo);
                          buffer |= tempboo << j;
                        }
                    }
                  else
                    {
                      for(indexer j = 0; j < chunk; ++j)
                        {
                          g24_lib::textual_input(s, tempboo);
                          buffer |= tempboo << j;
                        }
                    }
                  arr[i] = buffer;
                }
            }
          else
            {
              for(indexer i = 0; i < arr.size(); ++i)
                {
                  g24_lib::textual_input(s, arr[i]);
                }
            }
        }
      else
        {
          carried_bool_vector <Block, indexer, MemoryContext::current_manager<Block, indexer>, false> temp(*this);
          temp.textual_input(s, as_bools);
          (*this) = temp;
        }
    }
      
    template<class stream>
    CUDA_ONLY_HOS void binary_output(stream &s) const
    {
      g24_lib::binary_output(s, Size);
      arr.binary_output(s);
      //simple_array::binary_output already handles non-cpu cases.
    }
      
    template<class stream>
    CUDA_ONLY_HOS void binary_input(stream &s)
    {
      g24_lib::binary_input(s, Size);
      arr.binary_input(s);
      //simple_array::binary_input already handles non-cpu cases.
    }
    
    
#if CUDA_AVAILABLE
    /*!
      \brief Converts the `g24_lib::carried_bool_vector` to a form that can easily be passed to \c CUDA kernels.
      
      \sa g24_lib::simple_array::to_CUDA()
    */
    CUDA_ONLY_HOS carried_bool_vector<Block, indexer, CUDA_memory_manager<Block, indexer>, false> to_CUDA() const
    {
      return carried_bool_vector<Block, indexer, CUDA_memory_manager<Block, indexer>, false>(*this);
    }
#endif

    
    private:
      
      struct operate_on_all_functor
      {
        template <class CBV, class F, class ... Args>
        CUDA_HOS_DEV inline void operator() (const g24_lib::empty_array<Block, indexer>& dummy,
                                             const indexer i,
                                             CBV && vec,
                                             F && f,
                                             Args &&... args) const
        {
          if (i == dummy.size() - 1)
            {
              for (indexer j = 0; j < dummy.size() % vec::chunk; ++j)
                {
                  f(vec, i * vec::chunk + j, std::forward<Args>(args)...);
                }
            }
          else
            {
              for (indexer j = 0; j < vec::chunk ; ++j)
                {
                  f(vec, i * vec::chunk + j, std::forward<Args>(args)...);
                }
            }
        }
      };
      
    public:
    
    /*!
      \brief Performs operation given by \p f on every element of the vector.
            
      \param f The function to apply on the elements of the vector.
      
      \param args Extra arguments to be passed to \p f
            
      \tparam Func The type that holds the function to be applied to the elements of the vector.
      
      \tparam Args The types for any extra arguments to \p Func.
      
      \pre \p f must take as arguments a reference to \p the vector and the index at which we're evaluating
            and any extra arguments passed to this function in \p args.
            
      \pre \p parallel must be a valid type of parallelism, that is, it must satisfy `g24_lib::is_parallelism`.
      
      \remark This is constructed in such a way that all the vector accesses are thread-safe
              (as long as only the element of the provided index is written to).
              Effectively, the operations are parallelized over the array of \p Blocks,
              so there will be roughly `v.size/v::chunk` operations in parallel,
              each comprised of `chunk` function evaluations.
              For sufficiently complicated functions, it could prove more useful to
              operate on a `g24_lib::simple_array` of booleans and then convert it to a `g24_lib::carried_bool_vector`,
              as long as there is sufficient memory for it, of course.
    */
    template <class parallel, class Func, class ... Args>
    void operate_on_all(Func &&f, Args &&... args)
    {
      static_assert(g24_lib::is_parallelism<parallel>, "Must be using a valid form of parallelism!");
      if constexpr (std::is_same_v<typename memory_manager::memory_location, typename parallel::memory_location>)
        {
          
          parallel::loop(g24_lib::empty_array<Block, indexer>{arr.size()}, operate_on_all_functor,
                         (*this), std::forward<Func>(f), std::forward<Args>(args)...);
        }
      else
        {
          carried_bool_vector<Block, indexer, typename parallel::template memory_manager<Block, indexer>> temp(*this);
          temp.template operate_on_all<parallel>(std::forward<Func>(f), std::forward<Args>(args)...);
          (*this) = temp;
        }
    }
    
    /*!
      \brief Sets all elements of the bool to \p val.
            
      \param val The value to which the booleans should be set.
            
      \pre \p parallel must be a valid type of parallelism, that is, it must satisfy `g24_lib::is_parallelism`.
    */
    template <class parallel>
    void set_all(const bool val)
    {
      arr.template set_all<parallel>(val * (~(Block(0))));
      //val * (~(Block(0))) is all 1 is val is true or all 0 if val is false.
    }
  };
  
  //template <typename Block, typename indexer> indexer carried_bool_vector<Block, indexer>::chunk = 8*sizeof(Block);
  
  
  /*!
    \brief A `g24_lib::carried_bool_vector` that holds the booleans in the memory appropriate for the current context.
    
    \tparam Type The type of the objects in whose bitwise representation the booleans will be packed (the *blocks*).
    
    \tparam num A type that is appropriate to hold sizes of objects.
    
    \pre \p num must satisfy the constraints placed on the choice
            of \ref g24_lib::Definitions::default_unsigned_indexer.
  */
  template <class Type, class indexer = g24_lib::Definitions::default_unsigned_indexer> using bool_vector =
    carried_bool_vector <Type, indexer, MemoryContext::current_manager<Type, indexer>, true>;
  
  /*!
    \brief A `g24_lib::carried_bool_vector` that holds the booleans in the usual, CPU-addressable memory.
    
    \tparam Type The type of the objects in whose bitwise representation the booleans will be packed (the *blocks*).
    
    \tparam num A type that is appropriate to hold sizes of objects.
    
    \pre \p num must satisfy the constraints placed on the choice
          of \ref g24_lib::Definitions::default_unsigned_indexer.
  */
  template <class Type, class indexer = g24_lib::Definitions::default_unsigned_indexer> using cpu_bool_vector =
    carried_bool_vector <Type, indexer, default_memory_manager<Type, indexer>, true>;
    
  /*!
    \brief A `g24_lib::carried_bool_vector` that holds the booleans in the memory of a \c CUDA-enabled GPU.
    
    \tparam Type The type of the objects in whose bitwise representation the booleans will be packed (the *blocks*).
    
    \tparam num A type that is appropriate to hold sizes of objects.
    
    \pre \p num must satisfy the constraints placed on the choice 
          of \ref g24_lib::Definitions::default_unsigned_indexer.
  */
  template <class Type, class indexer = g24_lib::Definitions::default_unsigned_indexer> using cuda_bool_vector =
    carried_bool_vector <Type, indexer, CUDA_memory_manager<Type, indexer>, true>;
    
  /*!
    \brief The appropriate way to pass a `g24_lib::carried_bool_vector` into a \c CUDA kernel.
           Will copy a pointer if the memory already resides in the GPU,
           so the original array will be addressed and will experience any changes dictated by the kernel.
    
    \tparam Type The type of the objects in whose bitwise representation the booleans will be packed (the *blocks*).
    
    \tparam num A type that is appropriate to hold sizes of objects.
    
    \pre \p num must satisfy the constraints placed on the choice of \ref g24_lib::Definitions::default_unsigned_indexer.
  */
  template <class Type, class indexer = g24_lib::Definitions::default_unsigned_indexer> using cuda_kernel_bool_vector =
    carried_bool_vector <Type, indexer, CUDA_memory_manager<Type, indexer>, false>;
    
  /*!    
    \brief A `g24_lib::carried_bool_vector` that holds the booleans
           in a way that is appropriate for a specific type of parallelism.
    
    \tparam Type The type of the objects in whose bitwise representation the booleans will be packed (the *blocks*).
    
    \tparam num A type that is appropriate to hold sizes of objects.
    
    \pre \p num must satisfy the constraints placed on the choice of \ref g24_lib::Definitions::default_unsigned_indexer.
    
    \pre \p parallel must be a valid type of parallelism, that is, it must satisfy `g24_lib::is_parallelism`.
    
  */
  template <class parallel, class Type, class num = g24_lib::Definitions::default_unsigned_indexer>
  using bool_vector_parallel = carried_bool_vector<Type, num, typename parallel::template memory_manager<Type, num>, true>;
  //And this generalizes for any parallelism being considered.
  //(It's useful for temporaries and the like.)
}



#endif

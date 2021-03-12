#ifndef G24_LIB_PARALLELISM
#define G24_LIB_PARALLELISM

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

\file parallelism.h

\brief Provides a generic way to handle operations and reductions
       using different forms of parallelism (including \c CUDA and \c OpenMP).
       

\author Nuno Fernandes (main coder, current maintainer)

*/


namespace g24_lib
{
  namespace internals
  {
    /*!
      \brief An empty struct to serve as a kernel size indicator
             for forms of parallelism that do not need kernel sizes.
    */
    struct empty_kernel_size{};
    
  }
  
  /*!
    \brief The different forms of parallelism supported by the library are here.
  */
  namespace Parallelism
  {
    /*!
      \brief Provides a base class for all parallelism specifications.
      
      \remark All of the member functions (and member typedefs) should be overriden in any derived class.
    */
    struct parallelism_base
    {
      /*!
        \brief The memory context in which the data should be held.
      */
      using memory_location = MemoryContext::memory_context_base;
      
      /*!
        \brief An appropriate memory manager for the data.
      */
      template <class T, class indexer>
      using memory_manager = memory_manager_base<T, indexer>;
            
      
      /*!
        \brief Some form of scaling factor for some of the parallel operations.
        
        \remark Currently used solely for reductions with \c CUDA.
      */
      static constexpr g24_lib::Definitions::default_unsigned_indexer block_size = 1;
      
      /*!
        \brief Indicates whether we need to calculate kernel sizes before running the functions.
               Currently, when false, kernel sizes are empty and their calculation is a no-op.
               
        \remark In the current state of the library, kernel sizes are only relevant for \c CUDA.
      */
      static constexpr bool uses_kernel_sizes = false;
            
      /*!
        \brief Indicates whether we can pass stuff around by reference
               or, if false, if we should store them by value
              (mainly for deferred_ops and the like).
              This is mainly for CUDA interoperatability,
              since passing things into CUDA kernels invalidates any references
              coming from CPU code.
      */
      static constexpr bool can_pass_by_reference = true;
      
      /*!
        The class that is suitable to hold possible estimates for the ideal size of the kernels.
        
        \remark In the current state of the library, kernel sizes are only relevant for \c CUDA.
      */
      using kernel_size_type = internals::empty_kernel_size;
      
      /*!
        \brief Holds the different atomic operations in this type of parallelism.
        
        \warning This atomicity does not necessarily imply thread-safety,
                 only that an operation that is a member of parallism::atomics
                 will be executed atomically inside any loop with this form of parallelism.
      */
      struct atomics
      {
        /*!
          \brief Stores in \p res the result of adding \p val to \p res, all in a single (atomic) operation.
          
          \remark To be extra clear, this does `res = res + val`.
        */
        template <class T1, class T2> CUDA_HOS_DEV static inline
        void add(T1& res, const T2& val)
        {
          static_assert(!std::is_same_v<void, parallelism_base>, "Should not be using parallelism_base!");
        }
        /*!
          \brief Stores in \p res the result of subtracting \p val from \p res, all in a single (atomic) operation.
          
          \remark To be extra clear, this does `res = res - val`.
        */
        template <class T1, class T2> CUDA_HOS_DEV static inline
        void subtract(T1& res, const T2& val)
        {
          static_assert(!std::is_same_v<void, parallelism_base>, "Should not be using parallelism_base!");
        }
        /*!
          \brief Stores in \p res the result of multiplying \p res by \p val, all in a single (atomic) operation.
          
          \remark To be extra clear, this does `res = res * val`.
        */
        template <class T1, class T2> CUDA_HOS_DEV static inline
        void multiply(T1& res, const T2& val)
        {
          static_assert(!std::is_same_v<void, parallelism_base>, "Should not be using parallelism_base!");
        }
        /*!
          \brief Stores in \p res the result of dividing \p res by \p val, all in a single (atomic) operation.
          
          \remark To be extra clear, this does `res = res / val`.
        */
        template <class T1, class T2> CUDA_HOS_DEV static inline
        void divide(T1& res, const T2& val)
        {
          static_assert(!std::is_same_v<void, parallelism_base>, "Should not be using parallelism_base!");
        }
        /*!
          \brief Stores in \p res the result of taking the bitwise and between \p res and \p val,
                  all in a single (atomic) operation.
          
          \remark To be extra clear, this does `res = res & val`.
        */
        template <class T1, class T2> CUDA_HOS_DEV static inline
        void bitwise_and(T1& res, const T2& val)
        {
          static_assert(!std::is_same_v<void, parallelism_base>, "Should not be using parallelism_base!");
        }
        /*!
          \brief Stores in \p res the result of taking the bitwise or between \p res and \p val,
                  all in a single (atomic) operation.
          
          \remark To be extra clear, this does `res = res | val`.
        */
        template <class T1, class T2> CUDA_HOS_DEV static inline
        void bitwise_or(T1& res, const T2& val)
        {
          static_assert(!std::is_same_v<void, parallelism_base>, "Should not be using parallelism_base!");
        }
        /*!
          \brief Stores in \p res the result of taking the bitwise XOR between \p res and \p val,
                  all in a single (atomic) operation.
          
          \remark To be extra clear, this does `res = res ^ val`.
        */
        template <class T1, class T2> CUDA_HOS_DEV static inline
        void bitwise_xor(T1& res, const T2& val)
        {
          static_assert(!std::is_same_v<void, parallelism_base>, "Should not be using parallelism_base!");
        }
      };
      
      /*!
        \brief Loops through every element of the container \p c, applying operation \p op.
               If this form of parallelism needs kernel sizes, it uses that specified by \p size.
        
        \param size The kernel size that will be used to perform the loop
                    (if this kind of parallelism does not depend on kernel sizes,
                      this argument is ignored).
        
        \param c The container through which we will loop.
        
        \param op The operation that will be applied to the elements of the container.
        
        \param args Extra arguments to be passed to \p op.
        
        \tparam Cont The type of the container through which we will loop.
        
        \tparam Op The type that holds the operation to be applied to the elements of the container.
        
        \tparam Args The types for any extra arguments to \p Op.
        
        \pre \p op must take as arguments (a reference to) \p c, the index at which we're evaluating
              and any extra arguments passed to this function in \p args.
        
      */
      template <class Cont, class Op, class ... Args> CUDA_HOS_DEV static inline
      void loop(const kernel_size_type &size, Cont &&c, Op &&op, Args&& ... args)
      //op must take as arguments (container, i, args...)
      //Expectably does something with container[i]...
      {
          static_assert(!std::is_same_v<void, parallelism_base>, "Should not be using parallelism_base!");
      }
      
      /*!
        \brief Loops through every element of the container \p c, applying operation \p op.
               In case this form of parallelism needs kernel sizes, it estimates the appropriate size
               through `estimate_loop_kernel_size()`.
        
        \param c The container through which we will loop.
        
        \param op The operation that will be applied to the elements of the container.
        
        \param args Extra arguments to be passed to \p op.
        
        \tparam Cont The type of the container through which we will loop.
        
        \tparam Op The type that holds the operation to be applied to the elements of the container.
        
        \tparam Args The types for any extra arguments to \p Op.
        
        \pre \p op must take as arguments (a reference to) \p c, the index at which we're evaluating
              and any extra arguments passed to this function in \p args.
      */
      template <class Cont, class Op, class ... Args> CUDA_HOS_DEV static inline
      std::enable_if_t<!std::is_same_v<std::decay_t<Cont>,kernel_size_type>> loop(Cont &&c, Op &&op, Args&& ... args)
      //op must take as arguments (container, i, args...)
      //Expectably does something with container[i]...
      {
          static_assert(!std::is_same_v<void, parallelism_base>, "Should not be using parallelism_base!");
      }
      
      /*!
        \brief Provides an appropriate estimation for the kernel size to be used in a loop.
        
        \param size The size of the container through which we will loop.
        
        \tparam Cont The type of the container through which we will loop.
        
        \tparam Op The type that holds the operation to be applied to the elements of the container.
        
        \tparam Args The types for any extra arguments to \p Op.
        
        \pre An object of type \p Op must take as arguments (a reference to) \p c, the index at which we're evaluating
              and any extra arguments passed to this function in \p args.
              
        \remark This function is provided mainly for the cases where the user does not have,
                or does not want to pass, valid instances of the arguments to \p Op.
                Since, in principle, the only run-time component that will influence
                the kernel size will be the size of the container, this is the only argument
                that is actually needed.
                
      */
      template <class Cont, class Op, class ... Args> CUDA_HOS_DEV static inline
      kernel_size_type estimate_loop_kernel_size(const g24_lib::indexer_type<Cont> size)
      {
        static_assert(!std::is_same_v<void, parallelism_base>, "Should not be using parallelism_base!");
        return kernel_size_type{};
      }
      
      /*!
        \brief Provides an appropriate estimation for the kernel size to be used in a loop.
        
        \param c The container through which we will loop.
        
        \param op The operation that will be applied to the elements of the container.
        
        \param args Extra arguments to be passed to \p op.
        
        \tparam Cont The type of the container through which we will loop.
        
        \tparam Op The type that holds the operation to be applied to the elements of the container.
        
        \tparam Args The types for any extra arguments to \p Op.
        
        \pre An object of type \p Op must take as arguments (a reference to) \p c, the index at which we're evaluating
              and any extra arguments passed to this function in \p args.
              
        \remark Since, in principle, the only run-time component that will influence
                the kernel size will be the size of the container, this is the only argument
                that is actually used. The others serve mainly to enable
                argument type deduction when the user already has every argument
                instantiated and simply does not want to write the types explicitly again.
                Any sane optimizing compiler should optimize them out...
      */
      template <class Cont, class Op, class ... Args> CUDA_HOS_DEV static inline
      kernel_size_type estimate_loop_kernel_size(const Cont &c, const Op &op, const Args& ... args)
      {
        static_assert(!std::is_same_v<void, parallelism_base>, "Should not be using parallelism_base!");
        return kernel_size_type{};
      }
      
      /*!
        The class that is suitable to hold temporary values during reductions.
        
        \tparam T The type of the values being reduced.
        
        \tparam indexer A type that is appropriate to hold the size of the container.
        
        \pre \p indexer must satisfy the constraints placed on the choice of \ref g24_lib::Definitions::default_unsigned_indexer.
      */
      template <class T, class indexer = g24_lib::Definitions::default_unsigned_indexer>
      struct reduce_temporaries
      {
        friend struct parallelism_base;
          /*!
            \brief Resizes, if needed, the internal storage for the temporary variables.
                  
                  \param array_size The size of the array that will be reduced.
                  
                  \param block_size The block size that will be used in the reduction.
                         (May only be relevant for some forms of parallelism, namely \c CUDA.
                          For others, it is just ignored.)
          */
          inline void resize(const indexer array_size, const indexer block_size = 1)
          {
            static_assert(!std::is_same_v<void, parallelism_base::reduce_temporaries>,
                          "Should not be using parallelism_base::reduce_temporaries!");
          }
          /*!
            \brief Clears, if possible, any memory allocated for the temporaries.
          */
          CUDA_HOS_DEV inline void clear()
          {
            static_assert(!std::is_same_v<void, parallelism_base::reduce_temporaries>,
                          "Should not be using parallelism_base::reduce_temporaries!");
          }
          /*!
            \brief Constructor. Allocates, if needed, the internal storage for the temporary variables.
                  
                  \param array_size The size of the array that will be reduced.
                  
                  \param block_size The block size that will be used in the reduction.
                         (May only be relevant for some forms of parallelism, namely \c CUDA.
                          For others, it is just ignored.)
          */
          CUDA_HOS_DEV reduce_temporaries (const indexer array_size = 0, const indexer block_size = 1)
          {
            static_assert(!std::is_same_v<void, parallelism_base::reduce_temporaries>,
                          "Should not be using parallelism_base::reduce_temporaries!");
          }
          /*!
            \brief Returns the result of the reduction according to what's stored in the internal storage.
            
            \remark Depending on the specifics of the reduction, this may be
                    slightly more complex than just returning a variable.
          */
          CUDA_HOS_DEV inline T get_value() const
          {
            static_assert(!std::is_same_v<void, parallelism_base::reduce_temporaries>,
                          "Should not be using parallelism_base::reduce_temporaries!");
            return T{};
          }
      };


      /*!
        \brief Performs a reduction on the results of \p op applied to every element of \p c.
        
        \param temp The `reduce_temporaries` that will be used to calculate the result,
                    which can then be obtained by its `get_value()` method.
        
        \param c The container through which we will loop.
        
        \param op The operation that will be applied to the elements of the container.
        
        \param args Extra arguments to be passed to \p op.
        
        \tparam Cont The type of the container through which we will loop.
        
        \tparam Op The type that holds the operation to be applied to the elements of the container.
        
        \tparam OpRes The type of the result of the reduction.
        
        \tparam Args The types for any extra arguments to \p Op.
        
        \pre An object of type \p Op must take as arguments (a reference to) \p c, the index at which we're evaluating
              and any extra arguments passed to this function in \p args, and have return type that has an `operator+`
              with \p OpRes.
      */
      template <class Cont, class Op, class OpRes, class ... Args> CUDA_HOS_DEV static inline
      void reduce(reduce_temporaries<OpRes, g24_lib::indexer_type<Cont>> &temp, Cont && c, Op&& op, Args &&... args)
      //op must take as arguments (container, i, args...)
      //and return something of type OpRes (or addable to it)
      {
        static_assert(!std::is_same_v<void, parallelism_base>, "Should not be using parallelism_base!");
      }
      
      /*!
        \brief Performs a reduction on the results of \p op applied to every element of \p c.
        
        \remark This instantiates a local `reduce_temporaries`. If there will be several reductions
                applied to the same array, it is more efficient for the end user to instantiate a
                `reduce_temporaries` and use the appropriate version of the `reduce` function.
                
        \param c The container through which we will loop.
        
        \param op The operation that will be applied to the elements of the container.
        
        \param args Extra arguments to be passed to \p op.
        
        \returns The result of the reduction.
        
        \tparam Cont The type of the container through which we will loop.
        
        \tparam Op The type that holds the operation to be applied to the elements of the container.
        
        \tparam Args The types for any extra arguments to \p Op.
        
        \pre An object of type \p Op must take as arguments (a reference to) \p c, the index at which we're evaluating
              and any extra arguments passed to this function in \p args.
      */
      template <class Cont, class Op, class ... Args> CUDA_HOS_DEV static inline
      auto reduce(Cont && c, Op&& op, Args &&... args)
      {
        static_assert(!std::is_same_v<void, parallelism_base>, "Should not be using parallelism_base!");
        return g24_lib::value_type<Cont>{};
      }
      
      /*!
        \brief Performs a reduction on the elements of \p c.
        
        \param temp The `reduce_temporaries` that will be used to calculate the result,
                    which can then be obtained by its `get_value()` method.
        
        \param c The container through which we will loop.
        
        \tparam Cont The type of the container through which we will loop.
        
        \tparam OpRes The type of the result of the reduction.
        
        \pre The container must hold elements that have an `operator+` with \p OpRes.
      */
      template <class Cont, class OpRes> CUDA_HOS_DEV static inline
      void reduce(reduce_temporaries<OpRes, g24_lib::indexer_type<Cont>> &temp, Cont && c)
      //The temporaries should be managed outside.
      //If not, we just use the functions without the reduce_temporaries...
      {
        static_assert(!std::is_same_v<void, parallelism_base>, "Should not be using parallelism_base!");
      }
      
      /*!
        \brief Performs a reduction on the elements of \p c.
        
        \remark This instantiates a local `reduce_temporaries`. If there will be several reductions
                applied to the same array, it is more efficient for the end user to instantiate a
                `reduce_temporaries` and use the appropriate version of the `reduce` function.
                
        \param c The container through which we will loop.
        
        \returns The result of the reduction.
        
        \tparam Cont The type of the container through which we will loop.
        
      */
      template <class Cont> CUDA_HOS_DEV static inline
      g24_lib::value_type<Cont> reduce(Cont && c)
      {
        static_assert(!std::is_same_v<void, parallelism_base>, "Should not be using parallelism_base!");
        return g24_lib::value_type<Cont>{};
      }


    };
  
    /*!
      \brief No parallelism at all: simple, serial C++ code.
      
      \remark Since there is no parallelism, the functions in `g24_lib::Parallelism::None::atomic` are simple operations.
              <b>They are not thread safe</b>, that is, using `g24_lib::Parallelism::None`
              on the same variables in two different threads will lead to memory races!
    */
    struct None : public parallelism_base
    {
      using memory_location = MemoryContext::CPU;
      template <class T, class indexer>
      using memory_manager = default_memory_manager<T, indexer>;
      
      static constexpr g24_lib::Definitions::default_unsigned_indexer block_size = 1;
      
      static constexpr bool uses_kernel_sizes = false;
      //If we need to calculate kernel_sizes before running the functions.
      //Currently, when false, kernel_sizes are empty and their calculation a no-op.
            
      static constexpr bool can_pass_by_reference = true;
      //If we can pass stuff around by reference or we should store them by value
      //(mainly for deferred_ops and the like)
      
      using kernel_size_type = internals::empty_kernel_size;
      //We could do a more sophisticated approach
      //to leverage empty base optimization,
      //but the extra 4~8 bytes at most we'd get from this
      //(and that is assuming the as-if rule doesn't optimize them anyway)
      //is really, really not worth the hassle.
      
      struct atomics
      //In this case, it's trivial...
      //We only operate one-at-a-time in the array.
      //This does not mean this atomicity == thread-safety,
      //just that, if we want to ensure that an operation
      //happens atomically during the loops,
      //we should use parallelism::atomics::operation...
      {
        template <class T1, class T2> CUDA_HOS_DEV static inline
        void add(T1& res, const T2& val)
        {
          res = res + val;
        }
        template <class T1, class T2> CUDA_HOS_DEV static inline
        void subtract(T1& res, const T2& val)
        {
          res = res - val;
        }
        template <class T1, class T2> CUDA_HOS_DEV static inline
        void multiply(T1& res, const T2& val)
        {
          res = res * val;
        }
        template <class T1, class T2> CUDA_HOS_DEV static inline
        void divide(T1& res, const T2& val)
        {
          res = res / val;
        }
        template <class T1, class T2> CUDA_HOS_DEV static inline
        void bitwise_and(T1& res, const T2& val)
        {
          res = res & val;
        }
        template <class T1, class T2> CUDA_HOS_DEV static inline
        void bitwise_or(T1& res, const T2& val)
        {
          res = res | val;
        }
        template <class T1, class T2> CUDA_HOS_DEV static inline
        void bitwise_xor(T1& res, const T2& val)
        {
          res = res ^ val;
        }
      };
      
      template <class Cont, class Op, class ... Args> CUDA_HOS_DEV static inline
      void loop(const kernel_size_type &ignore, Cont &&c, Op &&op, Args&& ... args)
      //op must take as arguments (container, i, args...)
      //Expectably does something with container[i]...
      {
        loop(std::forward<Cont>(c), std::forward<Op>(op), std::forward<Args>(args)...);
      }
      
      template <class Cont, class Op, class ... Args> CUDA_HOS_DEV static inline
      std::enable_if_t<!std::is_same_v<std::decay_t<Cont>,kernel_size_type>> loop(Cont &&c, Op &&op, Args&& ... args)
      //op must take as arguments (container, i, args...)
      //Expectably does something with container[i]...
      {
        using indexer = typename g24_lib::indexer_type<Cont>;
        for (indexer i = 0; i < c.size(); ++i)
        {
          op(std::forward<Cont>(c), i, std::forward<Args>(args)...);
        }
      }
      
      template <class Cont, class Op, class ... Args> CUDA_HOS_DEV static inline
      kernel_size_type estimate_loop_kernel_size(const g24_lib::indexer_type<Cont> size)
      {
        return kernel_size_type{};
      }
      
      template <class Cont, class Op, class ... Args> CUDA_HOS_DEV static inline
      kernel_size_type estimate_loop_kernel_size(const Cont &c, const Op &op, const Args& ... args)
      {
        return estimate_loop_kernel_size<Cont, Op, Args...>(c.size());
      }
      
      template <class T, class indexer = g24_lib::Definitions::default_unsigned_indexer>
      struct reduce_temporaries
      {
        friend struct None;
        private:
          T temp;
        public:
          inline void resize(const indexer array_size, const indexer block_size = 1)
          {
            temp = T{0};
            return;
          }
          CUDA_HOS_DEV inline void clear()
          {
            return;
            //No de-allocations to perform
            //since it's all stack allocated.
          }
          CUDA_HOS_DEV reduce_temporaries (const indexer array_size = 0, const indexer block_size = 1)
          {
            resize(array_size, block_size);
          }
          CUDA_HOS_DEV inline T get_value() const
          {
            return temp;
          }
      };
      
      template <class Cont, class Op, class OpRes, class ... Args> CUDA_HOS_DEV static inline
      void reduce(reduce_temporaries<OpRes, g24_lib::indexer_type<Cont>> &temp, Cont && c, Op&& op, Args &&... args)
      //op must take as arguments (container, i, args...)
      //and return something of type OpRes (or addable to it)
      {
        using indexer = typename g24_lib::indexer_type<Cont>;
        temp.temp = OpRes{0};
        for (indexer i = 0; i < c.size(); ++i)
          {
            temp.temp += op(std::forward<Cont>(c), i, std::forward<Args>(args)...);
          }
      }
      
      template <class Cont, class Op, class ... Args> CUDA_HOS_DEV static inline
      auto reduce(Cont && c, Op&& op, Args &&... args)
      {
        reduce_temporaries< decltype(op(std::forward<Cont>(c), 0, std::forward<Args>(args)...)),
                            g24_lib::indexer_type<Cont>> temp(c.size());
        reduce(temp, std::forward<Cont>(c), std::forward<Op>(op), std::forward<Args>(args)...);
        return temp.get_value();
      }
      
      template <class Cont, class OpRes> CUDA_HOS_DEV static inline
      void reduce(reduce_temporaries<OpRes, g24_lib::indexer_type<Cont>> &temp, Cont && c)
      //The temporaries should be managed outside.
      //If not, we just use the functions without the reduce_temporaries...
      //OpRes must (hopefully) be something to which we can add g24_lib::value_type<Cont>...
      {
        reduce(temp, std::forward<Cont>(c), return_ith_functor{});
      }
      
      template <class Cont> CUDA_HOS_DEV static inline
      g24_lib::value_type<Cont> reduce(Cont && c)
      {
        reduce_temporaries<g24_lib::value_type<Cont>, g24_lib::indexer_type<Cont>> temp(c.size());
        reduce(temp, std::forward<Cont>(c));
        return temp.get_value();
      }
      
    };
    
    /*!
        \brief Parallelised operations using \c OpenMP.
        
        \warning `g24_lib::Parallelism::OpenMP::atomic` uses `#pragma omp atomic`,
                so it might possibly fail for non-scalar type, though the possible loss in performance
                by using `#pragma omp critical` instead far outweighs the gains in generality...
    */
    struct OpenMP : public parallelism_base
    {
      using memory_location = MemoryContext::CPU;
      template <class T, class indexer>
      using memory_manager = default_memory_manager<T, indexer>;
      
      static constexpr g24_lib::Definitions::default_unsigned_indexer block_size = 1;
            
      static constexpr bool uses_kernel_sizes = false;
      //If we need to calculate kernel_sizes before running the functions.
      //Currently, when false, kernel_sizes are empty and their calculation a no-op.
      
      static constexpr bool can_pass_by_reference = true;
      //If we can pass stuff around by reference or we should store them by value
      //(mainly for deferred_ops and the like)
      
      using kernel_size_type = internals::empty_kernel_size;
      //We could do a more sophisticated approach
      //to leverage empty base optimization,
      //but the extra 4~8 bytes at most we'd get from this
      //(and that is assuming the as-if rule doesn't optimize them anyway)
      //is really, really not worth the hassle.
      
      
      struct atomics
      //In this case, we use pragma omp atomic.
      //For non-scalar T, this might fail,
      //but should emit compile-time warnings?
      {
        template <class T1, class T2> CUDA_HOS_DEV static inline
        void add(T1& res, const T2& val)
        {
#ifdef _OPENMP
#pragma omp atomic
#endif
          res = res + val;
        }
        template <class T1, class T2> CUDA_HOS_DEV static inline
        void subtract(T1& res, const T2& val)
        {
#ifdef _OPENMP
#pragma omp atomic
#endif
          res = res - val;
        }
        template <class T1, class T2> CUDA_HOS_DEV static inline
        void multiply(T1& res, const T2& val)
        {
#ifdef _OPENMP
#pragma omp atomic
#endif
          res = res * val;
        }
        template <class T1, class T2> CUDA_HOS_DEV static inline
        void divide(T1& res, const T2& val)
        {
#ifdef _OPENMP
#pragma omp atomic
#endif
          res = res / val;
        }
        template <class T1, class T2> CUDA_HOS_DEV static inline
        void bitwise_and(T1& res, const T2& val)
        {
#ifdef _OPENMP
#pragma omp atomic
#endif
          res = res & val;
        }
        template <class T1, class T2> CUDA_HOS_DEV static inline
        void bitwise_or(T1& res, const T2& val)
        {
#ifdef _OPENMP
#pragma omp atomic
#endif
          res = res | val;
        }
        template <class T1, class T2> CUDA_HOS_DEV static inline
        void bitwise_xor(T1& res, const T2& val)
        {
#ifdef _OPENMP
#pragma omp atomic
#endif
          res = res ^ val;
        }
      };
      
      template <class Cont, class Op, class ... Args> CUDA_HOS_DEV static inline
      void loop(const kernel_size_type &ignore, Cont &&c, Op &&op, Args&& ... args)
      //op must take as arguments (container, i, args...)
      //Expectably does something with container[i]...
      {
        loop<Cont, Op, Args...>(std::forward<Cont>(c), std::forward<Op>(op), std::forward<Args>(args)...);
      }
      
      template <class Cont, class Op, class ... Args> CUDA_HOS_DEV static inline
      std::enable_if_t<!std::is_same_v<std::decay_t<Cont>,kernel_size_type>> loop(Cont &&c, Op &&op, Args&& ... args)
      //op must take as arguments (container, i, args...)
      //Expectably does something with container[i]...
      //We also assume it is safe thread-safe enough to work...
      {
        using indexer = typename g24_lib::indexer_type<Cont>;
#ifdef _OPENMP
#pragma omp parallel for
#endif
        for (indexer i = 0; i < c.size(); ++i)
        {
          op(std::forward<Cont>(c), i, std::forward<Args>(args)...);
        }
      }
      
      
      template <class Cont, class Op, class ... Args> CUDA_HOS_DEV static inline
      kernel_size_type estimate_loop_kernel_size(const g24_lib::indexer_type<Cont> size)
      {
        return kernel_size_type{};
      }
      
      template <class Cont, class Op, class ... Args> CUDA_HOS_DEV static inline
      kernel_size_type estimate_loop_kernel_size(const Cont &c, const Op &op, const Args& ... args)
      {
        return estimate_loop_kernel_size<Cont, Op, Args...>(c.size());
      }
      
      template <class T, class indexer>
      struct reduce_temporaries
      {
        friend struct OpenMP;
        private:
          T temp;
        public:
          inline void resize(const indexer array_size, const indexer block_size = 1)
          {
            temp = T{0};
            return;
          }
          CUDA_HOS_DEV inline void clear()
          {
            return;
            //No de-allocations to perform
            //since it's all stack allocated.
          }
          CUDA_HOS_DEV reduce_temporaries (const indexer array_size = 0, const indexer block_size = 1)
          {
            resize(array_size, block_size);
          }
          CUDA_HOS_DEV inline T get_value() const
          {
            return temp;
          }
      };
      
      template <class Cont, class Op, class OpRes, class ... Args> CUDA_HOS_DEV static inline
      void reduce(reduce_temporaries<OpRes, g24_lib::indexer_type<Cont>> &temp, Cont && c, Op&& op, Args &&... args)
      //op must take as arguments (container, i, args...)
      //and return something of type OpRes (or addable to it)
      {
        using indexer = typename g24_lib::indexer_type<Cont>;
        OpRes ret{0};
#ifdef _OPENMP
#pragma omp parallel for reduction(+: ret)
#endif
        for (indexer i = 0; i < c.size(); ++i)
          {
            ret += op(std::forward<Cont>(c), i, std::forward<Args>(args)...);
          }
        temp.temp = ret;
        //This extra variable should not constitute a significant memory increase,
        //both because it will only be an element of Cont
        //and it might very well be optimized out...
      }
      
      template <class Cont, class Op, class ... Args> CUDA_HOS_DEV static inline
      auto reduce(Cont && c, Op&& op, Args &&... args)
      {
        reduce_temporaries< decltype(op(std::forward<Cont>(c), 0, std::forward<Args>(args)...)),
                            g24_lib::indexer_type<Cont>> temp(c.size());
        reduce(temp, std::forward<Cont>(c), std::forward<Op>(op), std::forward<Args>(args)...);
        return temp.get_value();
      }
      
      template <class Cont, class OpRes> CUDA_HOS_DEV static inline
      void reduce(reduce_temporaries<OpRes, g24_lib::indexer_type<Cont>> &temp, Cont && c)
      //The temporaries should be managed outside.
      //If not, we just use the functions without the reduce_temporaries...
      {
        reduce(temp, std::forward<Cont>(c), return_ith_functor{});
      }
      
      template <class Cont> CUDA_HOS_DEV static inline
      g24_lib::value_type<Cont> reduce(Cont && c)
      {
        reduce_temporaries<g24_lib::value_type<Cont>, g24_lib::indexer_type<Cont>> temp(c.size());
        reduce(temp, std::forward<Cont>(c));
        return temp.get_value();
      }
    }; 
    
    
    template<class estimator, g24_lib::Definitions::default_unsigned_indexer BlockSize> struct CUDA;
  }
  
//-------------------------------------------
//Warning! CUDA madness might follow!
//Lasciate ogne speranza, voi chi scorrete!
//--------------------------------------------

  /*!
    \brief Holds definitions that generalize estimation of \c CUDA kernel sizes.
  */
  namespace CUDA_kernel_size
  {
    /*!
      \brief Holds the kernel size. If \c CUDA isn't available, it's an empty struct.
    */
    struct kernel_size_type
    {
#if CUDA_AVAILABLE
      dim3 grid, block;
      friend std::ostream& operator<< (std::ostream &s, const kernel_size_type &k)
      {
        s << "( " << k.grid.x << " , " << k.grid.y << " , " << k.grid.z
          << " ) x ( " << k.block.x << " , " << k.block.y << " , " << k.block.z << " )";
        return s;
      }
#endif
    };
    
    /*!
      \brief Different strategies for estimating the kernel size.
    */
    namespace estimator
    {
    
      /*!
        \brief Provides a base class for all \c CUDA kernel size estimators.
        
        \remark All of the member functions should be overriden in any derived class.
      */
      struct cuda_kernel_estimator_base
      {
        /*!
          \brief Estimates the kernel size with shared memory.
          
          \param size The size of the container on which we want to operate.
          
          \param f The function (\c CUDA kernel) that we want to call with the kernel size.
          
          \param shared_size Something that specifies the required size of the shared memory
                             that should be allocated and used in the function.
                    
          \pre \p shared_size must be either an integer, which will specify
               a static amount of memory independently of the kernel block size,
               or something that is a valid argument for `cudaOccupancyMaxPotentialBlockSizeVariableSMem`:
               a unary function / functor that takes block size,
               and returns the size, in bytes,
              of dynamic shared memory needed for a block (as stated in CUDA documentation).
               
        */
        template <class indexer, class Func, class ShSize>
        inline static kernel_size_type estimate(const indexer size, Func f, ShSize shared_size)
        {
          return kernel_size_type{};
        }
        
        /*!
          \brief Estimates the kernel size without shared memory.
          
          \param size The size of the container on which we want to operate.
          
          \param f The function (\c CUDA kernel) that we want to call with the kernel size.
               
        */
        template <class indexer, class Func>
        inline static kernel_size_type estimate(const indexer size, Func f)
        {
          return estimate(size, f, 0);
        }
      };
      /*!
        \brief Estimates the kernel size just based on the size of the container,
                rounding up to the next integer power of two for efficiency.
        
        \remark The results will be independent of the function that will be called
                and the amount of shared memory to be allocated. For most use cases,
                this might lead to suboptimal use of the registers available on the GPU,
                which can degrade performance, but there might be some cases where
                this simple estimate is enough.
      */
      struct basic
      {
        template <class indexer, class Func, class ShSize>
        inline static kernel_size_type estimate(const indexer size, Func ignore1, ShSize ignore2)
        {
#if CUDA_AVAILABLE
          return kernel_size_type{min_power_2( size/512 + (size % 512 != 0) ), 512};
#else
          return kernel_size_type{};
#endif
        }
        
        template <class indexer, class Func>
        inline static kernel_size_type estimate(const indexer size, Func ignore1)
        {
          return estimate(size, ignore1, 0);
        }
      };
      
      /*!
        \brief Estimates the kernel size using `cudaOccupancyMaxPotentialBlockSize()`
               or `cudaOccupancyMaxPotentialBlockSizeVariableSMem()`.
      */
      struct automatic
      {        
        template <class indexer, class Func, class ShSize>
        inline static kernel_size_type estimate(const indexer size, Func f, ShSize shared_size)
        //shared_size is either an integer
        //specifying the (static) shared memory size
        //or something that might be a valid argument
        //to cudaOccupancyMaxPotentialBlockSizeVariableSMem:
        //
        //(from CUDA docs)
        //
        // A unary function / functor that takes block size,
        // and returns the size, in bytes,
        // of dynamic shared memory needed for a block 
        {
#if CUDA_AVAILABLE
          int grid, block;
          if constexpr (std::is_integral_v<ShSize>)
          //If it is integral, then the amount of static memory
          //is independent of block size.
            {
              G24_LIB_CUDA_ERRCHECK(cudaOccupancyMaxPotentialBlockSize(&grid, &block, f, shared_size));
            }
          else
            {
              G24_LIB_CUDA_ERRCHECK(cudaOccupancyMaxPotentialBlockSizeVariableSMem(&grid, &block, f, shared_size));
            }
          grid = size/block + (size % block != 0);
          return kernel_size_type{grid, block};
#else
          return kernel_size_type{};
#endif
        }
        
        template <class indexer, class Func>
        inline static kernel_size_type estimate(const indexer size, Func f)
        {
          return estimate(size, f, 0);
        }
      };
    }
    
    
    /*!
      \brief Checks if \p estim is a valid estimator for \c CUDA kernel sizes.
      
      \remark Valid estimators are classes that derive from `g24_lib::CUDA_kernel_size::estimator::cuda_kernel_estimator_base`.
    */
    template<class estim>
    static inline constexpr bool is_estimator = std::is_base_of_v<estimator::cuda_kernel_estimator_base, estim>;
  }
  
#if CUDA_AVAILABLE
  namespace internals  
  {
  
///\cond HIDDEN_SYMBOLS

    template <class resT, class indexer, indexer Block>
    __device__ inline void CUDA_reduce_helper_helper(resT *shared, const indexer id)
    {
      if constexpr (Block > 1)
      {
        shared[id] += shared[id + Block/2];
        __syncwarp();
        CUDA_reduce_helper_helper<resT, indexer, Block/2>(shared, id);
      }
      else
      {
        return;
      }
    }
  
    template <class resT, class indexer, indexer Block>
    __device__ inline void CUDA_reduce_helper(resT *shared, const indexer id)
    {
      if constexpr (Block <= 64)
        {
          if(id < 32)
          {
            CUDA_reduce_helper_helper<resT, indexer, Block>(shared, id);
          }
        }
      else
        {
          if (id < Block/2)
            {
              shared[id] += shared[id+Block/2];
            }
          __syncthreads();
          if constexpr (Block == 128)
            {
              if(id < 32)
                {
                  CUDA_reduce_helper_helper<resT, indexer, Block/2>(shared, id);
                }
            }
          else
            {
              CUDA_reduce_helper<resT, indexer, Block/2>(shared, id);
            }
        }
    }
    
    template <class indexer, indexer Block, class ArrIn, class ArrOut, class Func, class ... Args>
    __global__ void CUDA_general_reduce_kernel(const ArrIn in, ArrOut out, const indexer num, Func f, const Args ... args)
    //Based on https://developer.download.nvidia.com/assets/cuda/files/reduction.pdf
    //Block will be a power of 2.
    {
      using resT = g24_lib::value_type<ArrOut>;
      __shared__ resT shared[Block];
      
      shared[threadIdx.x] = resT(0);
      
      indexer delta_i = Block * gridDim.x;
      
      for (indexer i = blockIdx.x * Block + threadIdx.x; i < num; i += delta_i)
        {
          shared[threadIdx.x] += f(in, i, args...);
        }
      __syncthreads();
      
      CUDA_reduce_helper<resT, indexer, Block>(shared, threadIdx.x);
      if (threadIdx.x == 0)
      {
        out[blockIdx.x] = shared[0];
      }
    }

///\endcond


    /*!
      \brief Performs a reduction on the results of an operation over every element of an array.
      
      \param in The input array.
      
      \param out The temporary and output array (the result of the reduction will be its first element).
      
      \param f The function to be evaluated over every element of the array.
      
      \param args The extra arguments for the function.
      
      \tparam indexer A type that is appropriate to hold the size of the arrays on which we will operate.
      
      \tparam Block The block size to be used for the reduction.
      
      \tparam ArrIn The type of the input array.
      
      \tparam ArrOut The type of the output array.
      
      \tparam Func The type of the operation to be applied on every element of the array.
      
      \tparam Args The types of the extra arguments passed to the function.
      
      \pre \p indexer must satisfy the constraints placed on the choice of \ref g24_lib::Definitions::default_unsigned_indexer.
        
      \pre The output array (\p out) must have a size equal to or larger than `in.size()/Block`.
        
      \pre \p f must take as arguments (a reference to) the input array (\p in), the index at which we're evaluating
              and any extra arguments passed to this function in \p args.
    */

    template <class indexer, indexer Block, class ArrIn, class ArrOut, class Func, class ... Args>
    void CUDA_general_reduce(ArrIn &&in, ArrOut &&out, Func &&f, Args&& ... args)
    //The result is in out[0].
    {
      static_assert(min_power_2(Block) == Block, "CUDA reduction error: Block must be a power of 2!");
      indexer i = min_power_2(in.size());
      if constexpr (Block > 1)
        {
          if (i < Block)
            {
              CUDA_general_reduce<indexer, Block/2>
                          (std::forward<ArrIn>(in), std::forward<ArrOut>(out), std::forward<Func>(f), std::forward<Args>(args)...);
            }
          else
            {
              CUDA_general_reduce_kernel<indexer, Block> <<< i/Block, Block >>> ( to_CUDA<ArrIn>(in),
                                                                                    to_CUDA<ArrOut>(out),
                                                                                    i, f, to_CUDA<Args>(args)...);
              if constexpr (g24_lib::Definitions::check_for_CUDA_kernel_errors)
                {
                  cudaDeviceSynchronize();
                  G24_LIB_CUDA_ERRCHECK(cudaPeekAtLastError());
                }
              
              for(i = min_power_2(in.size())/Block; i > Block; i /= Block)
                {
                  CUDA_general_reduce_kernel<indexer, Block> <<< i/Block, Block >>> ( to_CUDA<ArrOut>(out),
                                                                                      to_CUDA<ArrOut>(out),
                                                                                      i, return_ith_functor{} );
                  if constexpr (g24_lib::Definitions::check_for_CUDA_kernel_errors)
                    {
                      cudaDeviceSynchronize();
                      G24_LIB_CUDA_ERRCHECK(cudaPeekAtLastError());
                    }
                }
              CUDA_general_reduce_kernel<indexer, Block> <<< 1, Block >>> ( to_CUDA<ArrOut>(out),
                                                                            to_CUDA<ArrOut>(out),
                                                                            i, return_ith_functor{});
              if constexpr (g24_lib::Definitions::check_for_CUDA_kernel_errors)
                {
                  cudaDeviceSynchronize();
                  G24_LIB_CUDA_ERRCHECK(cudaPeekAtLastError());
                }
            }
        }
      else
        {
          CUDA_general_reduce_kernel<indexer, 1> <<< i , 1 >>>( to_CUDA<ArrIn>(in),
                                                                to_CUDA<ArrOut>(out),
                                                                i, f, to_CUDA<Args>(args)...);
          if constexpr (g24_lib::Definitions::check_for_CUDA_kernel_errors)
          {
            cudaDeviceSynchronize();
            G24_LIB_CUDA_ERRCHECK(cudaPeekAtLastError());
          }
        }
    }
    

    /*!
      The class that is suitable to hold temporary values during \c CUDA reductions.
      
      \tparam T The type of the values being reduced.
      
      \tparam indexer A type that is appropriate to hold the size of the container.
      
      \pre \p indexer must satisfy the constraints placed on the choice of \ref g24_lib::Definitions::default_unsigned_indexer.
    */
    template <class T, class indexer = g24_lib::Definitions::default_unsigned_indexer>
    struct CUDA_general_reduce_temps
    {
      template <class a, g24_lib::Definitions::default_unsigned_indexer b> friend struct Parallelism::CUDA;
      private:
        cuda_array<T, indexer> temp;
      public:
        /*!
          \brief Resizes the internal storage for the temporary variables.
                
                \param array_size The size of the array that will be reduced.
                
                \param block_size The block size that will be used in the reduction.
        */
        inline void resize(const indexer array_size, const indexer block_size = 1)
        {
          temp.resize(min_power_2(array_size) / block_size);
        }
        /*!
          \brief Clears the memory allocated for the temporaries.
        */
        CUDA_HOS_DEV inline void clear()
        {
          temp.clear();
        }
        /*!
          \brief Constructor. Allocates the internal storage for the temporary variables.
                
                \param array_size The size of the array that will be reduced.
                
                \param block_size The block size that will be used in the reduction.
        */
        CUDA_HOS_DEV CUDA_general_reduce_temps (const indexer array_size = 0, const indexer block_size = 1)
        {
          resize(array_size, block_size);
        }
        /*!
          \brief Returns the result of the reduction according to what's stored in the internal storage.
          
          \remark This basically copies back to host memory the first element of the array.
        */
        CUDA_HOS_DEV inline T get_value() const
        {
          T ret;
          memory_location::current_manager<T, indexer>::
                                  template copy<CUDA_memory_manager<T, indexer>>(&ret, temp.begin(), 1);
          return ret;
        }
    };
    
///\cond HIDDEN_SYMBOLS

    template <class Cont_cuda, class Op_cuda, class ... Args_cuda>
    __global__ void CUDA_general_loop_kernel(Cont_cuda c, Op_cuda op, Args_cuda ... args)
    //Note the pass-by-copy because references from the host are invalid in CUDA.
    {
      using indexer = g24_lib::indexer_type<Cont_cuda>;
      indexer h = threadIdx.x + blockIdx.x * blockDim.x;
      if (h < c.size())
        {
          op(c, h, args...);
        }
      //No need to std::forward here,
      //in fact, quite the opposite.
    }
    
    
    template <class T>
    __device__ double atomicSubtract(T* address, const T& val)
    //Adapted from the atomicAdd example...
    {
      using int_type = any_sized_int<sizeof(T), false>;
      int_type* address_as_int = reinterpret_cast<int_type*>(address);
      int_type old = *address_as_int, assumed;

      do {
          assumed = old;
          old = atomicCAS(address_as_int, assumed,
                          reinterpret_cast<int_type>(val - reinterpret_cast<T>(assumed)));
      } while (assumed != old);

      return reinterpret_cast<T>(old);
    }
    
    template <class T>
    __device__ double atomicMultiply(T* address, const T& val)
    //Adapted from the atomicAdd example...
    {
      using int_type = any_sized_int<sizeof(T), false>;
      int_type* address_as_int = reinterpret_cast<int_type*>(address);
      int_type old = *address_as_int, assumed;

      do {
          assumed = old;
          old = atomicCAS(address_as_int, assumed,
                          reinterpret_cast<int_type>(val * reinterpret_cast<T>(assumed)));
      } while (assumed != old);

      return reinterpret_cast<T>(old);
    }
    
    template <class T>
    __device__ double atomicDivide(T* address, const T& val)
    //Adapted from the atomicAdd example...
    {
      using int_type = any_sized_int<sizeof(T), false>;
      int_type* address_as_int = reinterpret_cast<int_type*>(address);
      int_type old = *address_as_int, assumed;

      do {
          assumed = old;
          old = atomicCAS(address_as_int, assumed,
                          reinterpret_cast<int_type>(val / reinterpret_cast<T>(assumed)));
      } while (assumed != old);

      return reinterpret_cast<T>(old);
    }

///\endcond
  }
#else
  namespace internals
  {
///\cond HIDDEN_SYMBOLS
    template <class T, class indexer = g24_lib::Definitions::default_unsigned_indexer>
    struct CUDA_general_reduce_temps
    {
      inline void resize(const indexer array_size, const indexer block_size)
      {
        static_assert(CUDA_AVAILABLE, "Trying to use CUDA-based parallelism without CUDA...");
      }
      CUDA_HOS_DEV inline void clear()
      {
        static_assert(CUDA_AVAILABLE, "Trying to use CUDA-based parallelism without CUDA...");
      }
      CUDA_HOS_DEV CUDA_general_reduce_temps (const indexer array_size)
      {
        static_assert(CUDA_AVAILABLE, "Trying to use CUDA-based parallelism without CUDA...");
      }
      CUDA_HOS_DEV inline T get_value() const
      {
        static_assert(CUDA_AVAILABLE, "Trying to use CUDA-based parallelism without CUDA...");
        return T{};
      }
    };
///\endcond
  }
#endif

  namespace Parallelism
  {
    /*!
        \brief Parallelised operations using \c CUDA.
        
        \warning `g24_lib::parallelism::CUDA::atomic` uses the \c CUDA API to provide
                most operations, so it might fail for user-defined types. For most use cases,
                we should be dealing with numerical code that deals with native types,
                so this shouldn't be too problematic.
    */
    template<class estimator = CUDA_kernel_size::estimator::automatic, g24_lib::Definitions::default_unsigned_indexer BlockSize = 128>
    struct CUDA : parallelism_base
    { 
    private:
      using estimator_t = estimator;
    public:
      using memory_location = MemoryContext::CUDA_GPU;
      template <class T, class indexer>
      using memory_manager = CUDA_memory_manager<T, indexer>;
      
      static constexpr g24_lib::Definitions::default_unsigned_indexer block_size = BlockSize;
      
      static constexpr bool uses_kernel_sizes = true;
      //If we need to calculate kernel_sizes before running the functions.
      //Currently, when false, kernel_sizes are empty and their calculation a no-op.
      
      static constexpr bool can_pass_by_reference = false;
      //If we can pass stuff around by reference or we should store them by value
      //(mainly for deferred_ops and the like)
      
      using kernel_size_type = CUDA_kernel_size::kernel_size_type;
      
      
      struct atomics
      //In this case, though the CUDA API
      //only provides atomic operations for some
      //types, we still write as templates for shortness...
      //If we try to be funny with anything,
      //it should give out due errors...
      {
        template <class T1, class T2> CUDA_ONLY_DEV static inline
        void add(T1& res, const T2& val)
        {
          atomicAdd(&res, val);
        }
        template <class T1, class T2> CUDA_ONLY_DEV static inline
        void subtract(T1& res, const T2& val)
        {
          if constexpr (std::is_same_v<T1, int32_t> || std::is_same_v<T1, uint32_t>)
            {
              atomicSub(&res, val);
            }
          else
            {
              internals::atomicSubtract(&res, val);
            }
        }
        template <class T1, class T2> CUDA_ONLY_DEV static inline
        void multiply(T1& res, const T2& val)
        {
          internals::atomicMultiply(&res, val);
        }
        template <class T1, class T2> CUDA_ONLY_DEV static inline
        void divide(T1& res, const T2& val)
        {
          internals::atomicDivide(&res, val);
        }
        template <class T1, class T2> CUDA_ONLY_DEV static inline
        void bitwise_and(T1& res, const T2& val)
        {
          atomicAnd(&res, val);
        }
        template <class T1, class T2> CUDA_ONLY_DEV static inline
        void bitwise_or(T1& res, const T2& val)
        {
          atomicOr(&res, val);
        }
        template <class T1, class T2> CUDA_ONLY_DEV static inline
        void bitwise_xor(T1& res, const T2& val)
        {
          atomicXor(&res, val);
        }
      };
      
      template <class Cont, class Op, class ... Args> CUDA_HOS_DEV static inline
      void loop(const kernel_size_type &size, Cont &&c, Op &&op, Args&& ... args)
      //op must take as arguments (container, i, args...)
      //Expectably does something with container[i]...
      //We also assume it is safe thread-safe enough to work...
      {
        static_assert(CUDA_AVAILABLE, "Trying to use CUDA-based parallelism without CUDA...");
        internals::CUDA_general_loop_kernel<<<size.grid, size.block>>>(to_CUDA(c),
                                                                       to_CUDA(op),
                                                                       to_CUDA(args)...);
#if G24_LIB_CUDA_CHECK_FOR_ERRORS
        cudaDeviceSynchronize();
        G24_LIB_CUDA_ERRCHECK(cudaPeekAtLastError());
#endif
      }
     
      template <class Cont, class Op, class ... Args> CUDA_HOS_DEV static inline
      kernel_size_type estimate_loop_kernel_size(const g24_lib::indexer_type<Cont> size)
      {
        static_assert(CUDA_AVAILABLE, "Trying to use CUDA-based parallelism without CUDA...");
        return estimator_t::estimate(size, internals::CUDA_general_loop_kernel<to_CUDA_t<Cont>,
                                                                               to_CUDA_t<Op>,
                                                                               to_CUDA_t<Args>...> , 0);
      }
      
      
      template <class Cont, class Op, class ... Args> CUDA_HOS_DEV static inline
      kernel_size_type estimate_loop_kernel_size(const Cont &c, const Op &op, const Args& ... args)
      {
        static_assert(CUDA_AVAILABLE, "Trying to use CUDA-based parallelism without CUDA...");
        return estimate_loop_kernel_size<Cont, Op, Args...>(c.size());
      }
      
      template <class Cont, class Op, class ... Args> CUDA_HOS_DEV static inline
      std::enable_if_t<!std::is_same_v<std::decay_t<Cont>,kernel_size_type>> loop(Cont &&c, Op &&op, Args&& ... args)
      //op must take as arguments (container, i, args...)
      //Expectably does something with container[i]...
      //We also assume it is safe thread-safe enough to work...
      {
        static_assert(CUDA_AVAILABLE, "Trying to use CUDA-based parallelism without CUDA...");
        kernel_size_type krn_sz = estimate_loop_kernel_size(std::forward<Cont>(c),
                                                        std::forward<Op>(op),
                                                        std::forward<Args>(args)...);
        
        loop<Cont, Op, Args...>(krn_sz, std::forward<Cont>(c), std::forward<Op>(op), std::forward<Args>(args)...);
      }
      
      template <class T, class indexer = g24_lib::Definitions::default_unsigned_indexer>
      using reduce_temporaries = internals::CUDA_general_reduce_temps<T, indexer>;
      
      template <class Cont, class Op, class OpRes, class ... Args> CUDA_HOS_DEV static inline
      void reduce(reduce_temporaries<OpRes, g24_lib::indexer_type<Cont>> &temp, Cont && c, Op&& op, Args &&... args)
      //op must take as arguments (container, i, args...)
      //and return something of type OpRes (or addable to it)
      {
        static_assert(CUDA_AVAILABLE, "Trying to use CUDA-based parallelism without CUDA...");
        using indexer = typename g24_lib::indexer_type<Cont>;
        internals::CUDA_general_reduce<indexer, block_size>
                (std::forward<Cont>(c), temp.temp, std::forward<Op>(op), std::forward<Args>(args)...);
      }
      
      template <class Cont, class Op, class ... Args> CUDA_HOS_DEV static inline
      auto reduce(Cont && c, Op&& op, Args &&... args)
      {
        reduce_temporaries<decltype(op(std::forward<Cont>(c), 0, std::forward<Args>(args)...))> temp(c.size(), block_size);
        reduce(temp, std::forward<Cont>(c), std::forward<Op>(op), std::forward<Args>(args)...);
        return temp.get_value();
      }
      
      template <class Cont, class OpRes> CUDA_HOS_DEV static inline
      void reduce(reduce_temporaries<OpRes, g24_lib::indexer_type<Cont>> &temp, Cont && c)
      //The temporaries should be managed outside.
      //If not, we just use the functions without the reduce_temporaries...
      {
        reduce(temp, std::forward<Cont>(c), return_ith_functor{});
      }
      
      template <class Cont> CUDA_HOS_DEV static inline
      g24_lib::value_type<Cont> reduce(Cont && c)
      {
        reduce_temporaries<g24_lib::value_type<Cont>, g24_lib::indexer_type<Cont>> temp(c.size(), block_size);
        reduce(temp, std::forward<Cont>(c));
        return temp.get_value();
      }
    }; 
  }
  
  
  /*!
    \brief Checks if \p parallel is a valid form of parallelism.
    
    \remark Valid forms of parallelism are classes that derive from `g24_lib::parallelism::parallelism_base`.
  */
  template<class parallel>
  static inline constexpr bool is_parallelism = std::is_base_of_v<Parallelism::parallelism_base, parallel>;
  
  
  
}
 

#endif
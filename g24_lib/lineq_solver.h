#ifndef G24_LIB_LINEQ_EVOLVER
#define G24_LIB_LINEQ_EVOLVER

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

\file lineq_solver.h

\brief Linear equation solvers, without explicit matrix creation.
       Especially useful for systems where each

\author Nuno Fernandes (main coder, current maintainer)

*/


namespace g24_lib
{ 

  /*!
    \brief Holds linear equation solvers that forego the creation of (sparse) matrices
           when the components of `A x` and `b` can be more easily expressed with functions.
  */
  namespace NonMatrixLinearSolvers
  {
    /*!
      \brief Holds linear equation solver methods that work on the Krylov subspace
             of the equivalent matricial formulation.
      
      \details The Krylov subspace is the space generated by repeated multiplication
              of a vector by a matrix.
    */
    namespace KrylovMethods
    {
      /*!
        \brief The Conjugate Gradient Method is reasonably easy to implement,
               but more efficient than the usual Gauss-Seidel or Jacobi iterative methods.
               However, it requires symmetrical systems/matrices.
               
        \tparam parallelism_type A valid type of parallelism, that is, one that satisfies `g24_lib::is_parallelism`,
                                 with which to perform the computations.
      */
      template <class parallelism_type = Parallelism::None>
      class ConjugateGradient
      {
        public:
          using parallel_type = parallelism_type;
          
          template <class Vec>
          using factor_type = g24_lib::value_type<Vec>;
          ///< \brief The type of the elements of the vector
          
          /// \brief The type of the absolue value of the elements of the vector
          ///        (for vectors of non-scalar objects)
          template <class Vec>
          using scalar_type = decltype(::abs(std::declval<factor_type<Vec>>()));
          
          template <class Vec>
          using indexer_type = g24_lib::indexer_type<Vec>;
          ///< \brief The type that holds the length of the vectors
          
          /*!
            \brief Temporary storage for the methods to be applied to a vector of type \p Obj.
          */
          template <class Obj>
          class storage
          {
              friend class ConjugateGradient;
              Obj res;
              //The residual
              Obj vec;
              //The direction
              factor_type<Obj> old_res, next_res, vec_val, alpha, beta;
              scalar_type<Obj> average;
            
              typename parallel_type::template reduce_temporaries<factor_type<Obj>, indexer_type<Obj>> factor_reduce;
              typename parallel_type::template reduce_temporaries<scalar_type<Obj>, indexer_type<Obj>> scalar_reduce;
            
              typename parallel_type::kernel_size_type kernel_sizes[3];
            
            public:         
              /*!
                \brief Clears the storage.
              */
              inline void clear()
              {
                res.clear();
                vec.clear();
                factor_reduce.clear();
                scalar_reduce.clear();
              }
            /*!
              \brief Constructs the storage for a vector of size \p vector_size.
            */
            CUDA_HOS_DEV storage (const indexer_type<Obj> vector_size = 0):
            res(vector_size), vec(vector_size), factor_reduce(vector_size), scalar_reduce(vector_size)
            {
            }
          };
          
  //On everything that follows, Mat gives the result of A x
  //in an equation of the form A x = b,
  //and takes as arguments (x_array, coordinate, b_array, extra...)
        private:  
        
          struct reduce_squared_functor
          {
          //Requires no extra arguments.
          
            template<class X, class indexer>
            CUDA_HOS_DEV inline auto operator() (const X& x, const indexer i) const
            {
              return fastpow(x[i], 2);
            }
          };
          
          struct reduce_squared_norm_functor
          {
          //Requires no extra arguments.
          
            template<class X, class indexer>
            CUDA_HOS_DEV inline auto operator() (const X& x, const indexer i) const
            {
              using namespace std; //For CUDA.
              return fastpow(::abs(x[i]), 2);
            }
          };
          
          struct reduce_vec_times_mat_functor
          {
          //Requires std::forward(mat), other_side, unchange and std::forward(args) as extra arguments
          
            template<class X, class indexer, class Mat, class OtherSideT, class UnchangeT, class ... Args>
            CUDA_HOS_DEV inline auto operator() ( const X& x,
                                                   const indexer i,
                                                   Mat&& mat,
                                                   const OtherSideT& other_side,
                                                   const UnchangeT& unchange,
                                                   Args&& ... args            ) const
            {
              if(!unchange[i])
                {
                  return x[i] * mat(x, i, other_side, std::forward<Args>(args)...);
                }
              else
                {
                  return g24_lib::value_type<X>(0);
                }
            }
          };
          
          struct pre_iteration_functor
          {
          //Requires std::forward(vec), std::forward(mat), wanted, other_side, unchange and std::forward(args) as extra arguments.
          
            template<class Mat, class Vec1, class Vec2, class BoolArr, class ... Args>
            CUDA_HOS_DEV inline void operator() (  Vec1& res,
                                                   const indexer_type<Vec1> i,
                                                   Vec1& vec,
                                                   Mat&& mat,
                                                   const Vec1& wanted,
                                                   const Vec2& other_side,
                                                   const BoolArr& unchange,
                                                   Args&& ... args            ) const
            {
              if(unchange[i])
                {
                  res[i] = factor_type<Vec1>(0);
                  vec[i] = factor_type<Vec1>(0);
                }
              else
                {
                  auto temp = other_side[i] - mat(wanted, i, other_side, std::forward<Args>(args)...);
                  res[i] = temp;
                  vec[i] = temp;
                }
            }
          };
          

        public:
          /*!
            \brief Must be called before the iterations, to ensure
                   the temporaries hold appropriate values.
            
            \param store A pre-allocated `storage` to hold the temporary values.
            
            \param mat The function that calculates the entries of `A * x` in `A * x == b`.
            
            \param wanted The initial estimate of `x` in `A * x == b`.
            
            \param other_side The value of `b` in `A * x == b`.
            
            \param unchange An array such that `unchange[i]` being true means that `x[i]`
                            must have the value specified in `wanted`. Especially useful
                            for boundary conditions.
            
            \param args Any extra arguments needed for \p mat.
            
            \pre \p mat must take as arguments the current value of `x`,
                 the coordinate to be evaluated, the value of `b` and
                 any extra arguments specified in \p args and return `A*x [coordinate]`.
          */
          template<class Mat, class Vec1, class Vec2, class BoolArr, class ... Args>
          CUDA_HOS_DEV static void pre_iteration(storage<Vec1> &store,
                                                 //The array that stores the temporaries needed for the method.
                                                 Mat &&mat,
                                                 //The function that calculates entry i of A x
                                                 Vec1 &wanted,
                                                 //The initial estimate of x in A x = b
                                                 const Vec2& other_side,
                                                 //b in A x = b
                                                 const BoolArr& unchange,
                                                 //unchange[i] is true if the value of x[i] should be fixed.
                                                 Args&& ... args
                                                 //Extra arguments for the calculation of A x 
                                                                                                    )
          {
            
            store.old_res = factor_type<Vec1>(1);
            store.next_res = factor_type<Vec1>(1);
            store.vec_val = factor_type<Vec1>(1);
            parallel_type::loop(store.kernel_sizes[0], store.res, pre_iteration_functor{},
                                store.vec, std::forward<Mat>(mat), wanted, other_side, unchange, std::forward<Args>(args)...);
                                                      
            parallel_type::reduce(store.factor_reduce, std::forward<Vec1>(store.res), reduce_squared_functor{});
            
            store.old_res = store.factor_reduce.get_value();
            
            parallel_type::reduce(store.factor_reduce, store.vec, reduce_vec_times_mat_functor{}, std::forward<Mat>(mat),
                                                      other_side, unchange, std::forward<Args>(args)... );
                                                      
            store.vec_val = store.factor_reduce.get_value();
            
          }
          
        private:

          struct next_values_functor
          {
          //Requires alpha, std::forward(res), vec, mat, other_side, unchange and args as extra arguments.
          
            template<class Mat, class Vec1, class Vec2, class BoolArr, class ... Args>
            CUDA_HOS_DEV inline void operator() (  Vec1& wanted,
                                                   const indexer_type<Vec1> i,
                                                   const factor_type<Vec1> alpha,
                                                   Vec1& res,
                                                   const Vec1& vec,
                                                   Mat&& mat,
                                                   const Vec2& other_side,
                                                   const BoolArr& unchange,
                                                   Args&& ... args            ) const
            {
              if(unchange[i])
                {
                  //Do nothing.
                }
              else
                {
                  wanted[i] = wanted[i] + alpha * vec[i];
                  res[i] = res[i] - alpha * mat(vec, i, other_side, std::forward<Args>(args)...);
                }
            }
          };
          
        
          template<class Mat, class Vec1, class Vec2, class BoolArr, class ... Args>
          CUDA_HOS_DEV static auto calculate_next_values(storage<Vec1> &store,
                                                         //The array that stores the temporaries needed for the method.
                                                         Mat &&mat,
                                                         //The function that calculates entry i of A x
                                                         Vec1 &wanted,
                                                         //The initial estimate of x in A x = b
                                                         const Vec2& other_side,
                                                         //b in A x = b
                                                         const BoolArr& unchange,
                                                         //unchange[i] is true if the value of x[i] should be fixed.
                                                         Args&& ... args
                                                         //Extra arguments for the calculation of A x
                                                                                                          )
          {
          
            parallel_type::loop(store.kernel_sizes[1], wanted, next_values_functor{}, store.alpha,
                                store.res, store.vec, std::forward<Mat>(mat), other_side, unchange, std::forward<Args>(args)...);
                                                  
            parallel_type::reduce(store.factor_reduce, std::forward<Vec1>(store.res), reduce_squared_functor{});
            
            store.next_res = store.factor_reduce.get_value();
            
            parallel_type::reduce(store.scalar_reduce, wanted, reduce_squared_norm_functor{});
            
            store.average = store.scalar_reduce.get_value()/wanted.size();
            
          }
          
          struct next_vectors_functor
          {
          //Requires beta, res and unchange as extra arguments.
          
            template<class Vec1, class Vec2, class BoolArr, class ... Args>
            //Technically, we should expect Vec1 == Vec2...
            CUDA_HOS_DEV inline void operator() (  Vec1&& vec,
                                                   const indexer_type<Vec1> i,
                                                   const factor_type<Vec1> beta,
                                                   const Vec2& res,
                                                   const BoolArr& unchange ) const
            {
              if(unchange[i])
                {
                  //Do nothing.
                }
              else
                {
                  vec[i] = res[i] + beta * vec[i];
                }
            }
          };
          

          template<class Mat, class Vec1, class Vec2, class BoolArr, class ... Args>
          CUDA_HOS_DEV static auto calculate_next_vector(storage<Vec1> &store,
                                                         //The array that stores the temporaries needed for the method.
                                                         Mat &&mat,
                                                         //The function that calculates entry i of A x
                                                         const Vec2& other_side,
                                                         //b in A x = b
                                                         const BoolArr& unchange,
                                                         //unchange[i] is true if the value of x[i] should be fixed.
                                                         Args&& ... args
                                                         //Extra arguments for the calculation of A x
                                                                                                        )
          {
            
            parallel_type::loop(store.kernel_sizes[2], store.vec, next_vectors_functor{}, store.beta, store.res, unchange);

            parallel_type::reduce(store.factor_reduce, store.vec, reduce_vec_times_mat_functor{}, std::forward<Mat>(mat),
                                  other_side, unchange, std::forward<Args>(args)... );
                                                      
            store.vec_val = store.factor_reduce.get_value();
          }
          
        public:
          /*!
            \brief Resizes the `storage` in \p store for vectors of size \p size.
            
            \param size The size of the vectors that are involved in the equation.
            
            \param store A pre-allocated `storage` to hold the temporary values.
            
            \tparam Mat The type of the object that returns `A * x` in `A * x == b`.
            
            \tparam Vec1 The type of `x` in `A * x == b`.
            
            \tparam Vec2 The type of `b` in `A * x == b`.
            
            \tparam BoolArr A type of an array whose i-th component evaluating to `true`
                            means the i-th component of `x` must remain constant throughout the iterations.
                            (Used for the `unchange` parameter in the iterations.)
                            
            \tparam Args The types of the extra arguments that must be provided to \p Mat.
            
            
            \pre An object of type \p Mat must take as arguments the current value of `x`,
                 the coordinate to be evaluated, the value of `b` and
                 any extra arguments specified in \p args and return `A*x [coordinate]`.
          */
          template <class Mat, class Vec1, class Vec2, class BoolArr, class ... Args>
          CUDA_HOS_DEV static void resize_temporaries(const indexer_type<Vec1> size, storage<Vec1> &store)
          {
            store.res.resize(size);
            store.vec.resize(size);
            
            store.factor_reduce.resize(size);
            store.scalar_reduce.resize(size);
            
            store.kernel_sizes[0] = parallel_type::template estimate_loop_kernel_size<Vec1,
                                                                                      pre_iteration_functor,
                                                                                      Vec1,
                                                                                      Mat,
                                                                                      Vec1,
                                                                                      Vec2,
                                                                                      BoolArr,
                                                                                      Args...>(size);
            
            
            store.kernel_sizes[1] = parallel_type::template estimate_loop_kernel_size<Vec1,
                                                                                      next_values_functor,
                                                                                      factor_type<Vec1>,
                                                                                      Vec1,
                                                                                      Vec1,
                                                                                      Mat,
                                                                                      Vec2,
                                                                                      BoolArr,
                                                                                      Args...>(size);


            store.kernel_sizes[2] = parallel_type::template estimate_loop_kernel_size<Vec1,
                                                                                      next_vectors_functor,
                                                                                      factor_type<Vec1>,
                                                                                      Vec1,
                                                                                      BoolArr>(size);
        
            
          }
          
          
          /*!
            \brief Resizes the `storage` in \p store for vectors of size \p size.
            
            \remark Serves only to allow template parameter deduction from arguments.
                    The values of any of the arguments besides \p size and \p store are not used,
                    so the other arguments will be optimized out.
            
            \param size The size of the vectors that are involved in the equation.
            
            \param store A pre-allocated `storage` to hold the temporary values.
            
            \param mat The function that calculates the entries of `A * x` in `A * x == b`.
            
            \param vector The initial estimate of `x` in `A * x == b`.
            
            \param other_side The value of `b` in `A * x == b`.
            
            \param unchange An array such that `unchange[i]` being true means that `x[i]`
                            must have the value specified in `wanted`. Especially useful
                            for boundary conditions.
            
            \param args Any extra arguments needed for \p mat.
            
            \pre \p mat must take as arguments the current value of `x`,
                 the coordinate to be evaluated, the value of `b` and
                 any extra arguments specified in \p args and return `A*x [coordinate]`.
          */
          template <class Mat, class Vec1, class Vec2, class BoolArr, class ... Args>
          //This allows template parameter deduction
          //from arguments, in case it is easier to call it this way.
          //The extra arguments will typically be optimized out?
          CUDA_HOS_DEV static void resize_temporaries(const indexer_type<Vec1> size,
                                                      storage<Vec1> &store,
                                                      const Mat &mat,
                                                      const Vec1 & vector,
                                                      const Vec2 & other_side,
                                                      const BoolArr& unchange,
                                                      const Args&... args )
          {
            resize_temporaries<Mat, Vec1, Vec2, BoolArr, Args...>(size, store);
          }
          
          /*!
            \brief Holds the results of an iteration with a vector of type \p Obj.
          */
          template <class Obj>
          struct results
          {
            factor_type<Obj> error;
            scalar_type<Obj> average;
          };
        
          /*!
            \brief Perfroms the iteration itself.
            
            \param store A pre-allocated `storage` to hold the temporary values.
            
            \param mat The function that calculates the entries of `A * x` in `A * x == b`.
            
            \param vector The initial estimate of `x` in `A * x == b`.
            
            \param other_side The value of `b` in `A * x == b`.
            
            \param unchange An array such that `unchange[i]` being true means that `x[i]`
                            must have the value specified in `wanted`. Especially useful
                            for boundary conditions.
            
            \param args Any extra arguments needed for \p mat.
            
            \pre \p mat must take as arguments the current value of `x`,
                 the coordinate to be evaluated, the value of `b` and
                 any extra arguments specified in \p args and return `A*x [coordinate]`.
          */
          template <class Mat, class Vec_type, class Other_type, class BoolArr, class ... Args>
          CUDA_HOS_DEV inline static auto iterate(storage<Vec_type> &store,
                                                  Mat &&mat,
                                                  Vec_type & vector,
                                                  const Other_type & other_side,
                                                  const BoolArr& unchange,
                                                  Args&&... args )
          //store is the storage object.
          //unchange[i], when true, signals that the i-th component of the vector
          //should not be changed, typically because it is a constraint of the problem.
          //Of course, mat could accomodate this,
          //but the intermediate values used in the algorithm
          //might take undesired values if it is so
          //(in the pre-iteration, res[i] = 0 
          //would need the vector to be equal to other_side,
          //but, for every other iteration,
          //for it not to change vec_val and such,
          //it should be zero...)
          //
          //We will try to solve M * vector = other_side,
          //where mat is such that mat(i, vector, other_side, params...)
          //gives the i-th component of M * vector;
          //params are additional parameters the user may want to pass to mat
          //(so as to be able to use functors instead of lambdas).
          //vector and other_side are passed as such to mat,
          //in principle it should not need to be templated
          //(unless the user deems it so, of course...).
          //More exotic lineq_solvers may include deferred_ops,
          //so, in any case, it might be more desirable to assume
          //mat gets i, then two objects that, when operated with [],
          //give components of two possible vectors x and b in A x = b,
          //and then, of course, the user-provided arguments.
          
          {
            using namespace std; //For CUDA.
                                //(and charges toward Barad-Dûr) 
           
            
            if (::abs(store.vec_val) > 0)
              {
                store.alpha = store.old_res  / store.vec_val;
              }
            else
              {
                store.alpha = store.old_res;
              }
            
            /*
            if(isnan(abs(store.alpha)) || isinf(abs(store.alpha)))
            {
              store.alpha = factor_type<Vec_type>(1);
            }*/
            calculate_next_values(store, std::forward<Mat>(mat), vector,
                                         other_side, unchange, std::forward<Args>(args)...);
            
            if (::abs(store.old_res) > 0)
              {
                store.beta = store.next_res  / store.old_res;
              }
            else
              {
                store.alpha = store.next_res;
              }
              
            /*
            if(isnan(abs(store.beta)) || isinf(abs(store.beta)))
            {
              store.beta = factor_type<Vec_type>(1);
            }*/
                      
            calculate_next_vector(store, std::forward<Mat>(mat), other_side, unchange, std::forward<Args>(args)...);
            
            store.old_res = store.next_res;
            
            results<Vec_type> ret;
            
            ret.error = store.next_res/vector.size();
            ret.average = store.average;
            
            return ret;
          }
      };
    }
  }
}

 
#endif

#ifndef G24_LIB_TEMPORAL_EVOLVER
#define G24_LIB_TEMPORAL_EVOLVER

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

namespace g24_lib
{
  /*!
    \brief Holds a fraction with numerator and denominator of type \p factorT.
  */
  template <class factorT>
  struct fraction
  {    
    const factorT numerator, denominator;
    
    template <class T>
    CUDA_HOS_DEV inline fraction<factorT> set_numerator(const T& num) const
    {
      return fraction<factorT>{num, denominator};
    }
    
    template <class T>
    CUDA_HOS_DEV inline fraction<factorT> set_denominator(const T& den) const
    {
      return fraction<factorT>{numerator, den};
    }
    
    template <class num>
    CUDA_HOS_DEV inline constexpr fraction(): numerator(factorT(0)), denominator(factorT(1))
    {
    }
    
    template <class num>
    CUDA_HOS_DEV inline constexpr fraction(const num &f): numerator(f), denominator(factorT(1))
    {
    }
    
    template <class num, class denom>
    CUDA_HOS_DEV inline constexpr fraction(const num &n, const denom& d): numerator(n), denominator(d)
    {
    }
    
    template <class num, class denom>
    CUDA_HOS_DEV inline constexpr fraction(const fraction<factorT> &other):
    numerator(other.numerator), denominator(other.denominator)
    {
    }
    
    template <class num, class denom>
    CUDA_HOS_DEV inline constexpr fraction(const std::pair<num, denom> &other):
    numerator(other.first), denominator(other.second)
    {
    }
    
    CUDA_HOS_DEV inline fraction<factorT> inverse() const
    {
      return fraction<factorT>{denominator, numerator};
    }
    
    template <class T>
    CUDA_HOS_DEV inline auto operator* (const T& x) const
    {
      return numerator * x / denominator; 
    }
    
    template <class T, class disabler = std::enable_if_t<!is_deferred<T>> >
    //For compatibility with the deferred stuff.
    friend CUDA_HOS_DEV inline auto operator* (const T&x, const fraction<factorT>& y)
    {
      return y.numerator * x / y.denominator;
    }
    
    friend CUDA_HOS_DEV inline std::ostream& operator<< (std::ostream& s, const fraction<factorT>& y)
    {
      s << "( " << y.numerator << " )/( " << y.denominator << " )";
      return s;
    }
    
  };
  
  /*!
    \brief A `constexpr` way of holding a compile time fraction.
    
    \remark C++20 and above might make this obsolete if the requirements on non-type template parameters
            can be made less strict.
  */
  template<class factorT, factorT num, factorT den>
  struct constexpr_fraction
  {
    CUDA_HOS_DEV static inline constexpr fraction<factorT> value()
    {
      return fraction<factorT>{num, den};
    }
    
    CUDA_HOS_DEV inline constexpr operator fraction<factorT>() const
    {
      return fraction<factorT>{num, den};
    }
  };
  
  namespace internals
  {
    /*!
      \brief An entry of a Butcher tableau.
      
      \tparam factorT The type that will hold the parameters (numerator and denominator).
      
      \tparam eval_gen A type whose `value()` static method yields a `g24_lib::fraction<factorT>`
                       which corresponds to the evaluation time.
      
      \tparam frac_gens A set of types whose `value()` static method yields a `g24_lib::fraction<factorT>`
                        which correspond to the coefficients of the previous evaluations of the derivative function.
      
      \remark A Butcher tableau entry of the form `a | b c d ... ` would be represented by
              `butcher_entry_class<T, x<a>, x<b>, x<c>, x<d> ...>`, where `x<y>` is a class
              whose `x::value()` is constexpr and returns `y`. In practice, `x` should correspond
              to a `g24_lib::constexpr_fraction<factorT, num, dem>` for `y = num/dem`.
    */
    template <class factorT, class eval_gen, class... frac_gens>
    struct butcher_entry_class
    {
      constexpr static g24_lib::Definitions::default_unsigned_indexer number = sizeof...(frac_gens);
      constexpr static fraction<factorT> evaluation_time{eval_gen::value()};
      constexpr static fraction<factorT> factors[number]{frac_gens::value()...};
      template<class stream, class str = std::basic_string<typename stream::char_type>>
      static void print(stream &s, const str& minor_separator = " ",
                                   const str& vertical_separator = " | ")
      {
        s << evaluation_time << minor_separator << vertical_separator << minor_separator;
        for (g24_lib::Definitions::default_unsigned_indexer i = 0; i < number-1; ++i)
        {
          s << factors[i] << minor_separator;
        }
        s << factors[number-1];
      }
    };
    
    /*!
      \brief A final entry of a Butcher tableau.
      
      \tparam factorT The type that will hold the parameters (numerator and denominator).
      
      \tparam frac_gens A set of types whose `value()` static method yields a `g24_lib::fraction<factorT>`
                        which correspond to the coefficients of the previous evaluations of the derivative function.
      
      \remark A Butcher tableau that ends with something of the from of the form `  | a b c d ... `
              would be represented by `butcher_final_class<T, x<a>, x<b>, x<c>, x<d> ...>`,
              where `x<y>` is a class whose `x::value()` is constexpr and returns `y`.
              In practice, `x` should correspond to a
              `g24_lib::constexpr_fraction<factorT, num, dem>` for `y = num/dem`.
    */
    template <class factorT, class ... frac_gens>
    struct butcher_final_class
    {
      constexpr static g24_lib::Definitions::default_unsigned_indexer number = sizeof...(frac_gens);
      constexpr static fraction<factorT> factors[number]{frac_gens::value()...};
      
      template<class stream, class str = std::basic_string<typename stream::char_type>>
      static void print(stream &s, const str& minor_separator = " ",
                                   const str& vertical_separator = " | ")
      {
        s << minor_separator << vertical_separator << minor_separator;
        for (g24_lib::Definitions::default_unsigned_indexer i = 0; i < number-1; ++i)
        {
          s << factors[i] << minor_separator;
        }
        s << factors[number-1];
      }
    };
    
    ///\cond HIDDEN_SYMBOLS
    template<g24_lib::Definitions::default_unsigned_indexer N, class butcher_entry_l, class ... butcher_entry_likes>
    struct butcher_table_holder
    {
      using entry = butcher_entry_l;
      using next = butcher_table_holder<N+1,butcher_entry_likes...>;
      template <g24_lib::Definitions::default_unsigned_indexer i>
      CUDA_HOS_DEV static constexpr auto get_entry()
      {
        if constexpr (i == N)
          {
            return entry{};
          }
        else
          {
            return next::template get_entry<i>();
          }
      }
      
      template<class stream, class str = std::basic_string<typename stream::char_type>>
      static void print_entries(stream &s, const str& major_separator = "\n",
                                            const str& minor_separator = " ",
                                            const str& vertical_separator = " | ")
      {
        entry::print(s, minor_separator, vertical_separator);
        s << major_separator;
        next::print_entries(s, major_separator, minor_separator, vertical_separator);
      }
    };
    
    template<g24_lib::Definitions::default_unsigned_indexer N, class butcher_entry_l>
    struct butcher_table_holder<N, butcher_entry_l>
    {
      using entry = butcher_entry_l;
      template <g24_lib::Definitions::default_unsigned_indexer i>
      CUDA_HOS_DEV static constexpr auto get_entry()
      {
        if constexpr (i == N)
          {
            return entry{}; 
          }
        else
          {
            return;
          }
      }
      
      template<class stream, class str = std::basic_string<typename stream::char_type>>
      static void print_entries(stream &s, const str& major_separator = "\n",
                                            const str& minor_separator = " ",
                                            const str& vertical_separator = " | ")
      {
        entry::print(s, minor_separator, vertical_separator);
      }
    };
    ///\endcond
    
    /*!
      \brief Holds a Butcher tableau describing a Runge-Kutta Method.
      
      \tparam butcher_final_like A `g24_lib::internals::butcher_final_class` that
                                 properly describes the final iteration in the Butcher tableau.
      
      \tparam butcher_entry_likes A series of `g24_lib::internals::butcher_entry_class` that
                                  properly describe the intermediate steps in the Butcher tableau.
                                  The `t = t` evaluation is always performed, so the first entry
                                  corresponds to the first step after that.
    */
    template <class butcher_final_like, class ... butcher_entry_likes>
    struct butcher_table
    {
      ///\brief Signals whether this is an adaptive Runge-Kutta method 
      ///       (thus having an <b>extended</b> Butcher tableau) or not.
      static constexpr bool is_extended = false;
      
      ///\brief The total number of times the function must be evaluated in the method.
      static constexpr g24_lib::Definitions::default_unsigned_indexer iterations_needed = sizeof...(butcher_entry_likes) + 1;

      ///\brief The class that internally holds the data, not too relevant for the end-user.
      using holder = butcher_table_holder<1, butcher_entry_likes...> ;
      
      ///\brief The number of intermediate values that should be stored for this method.
      static constexpr g24_lib::Definitions::default_unsigned_indexer temporaries_needed = sizeof...(butcher_entry_likes)+1;
      
      //We assume no Butcher Table with zero coefficients on a certain evaluation will be used...
      //That is, we don't explicitly check that every calculated value is used at least once.
      //Obviously, if it isn't, it's pointless to store and/or calculate it,
      //but the user should be conscious enough not to do that. I hope.
      
      template <g24_lib::Definitions::default_unsigned_indexer i>
      CUDA_HOS_DEV static constexpr auto get_entry()
      {
        return holder::template get_entry<i>();
      }
      
      CUDA_HOS_DEV static constexpr auto get_result()
      {
        return butcher_final_like{};
      }
      
      template<class stream, class str = std::basic_string<typename stream::char_type>>
      static void print_entries(stream &s, const str& major_separator = "\n",
                                            const str& minor_separator = " ",
                                            const str& vertical_separator = " | ")
      {
        s << 0 << vertical_separator << major_separator;
        holder::print_entries(s, major_separator, minor_separator);
      }
      
      template<class stream, class str = std::basic_string<typename stream::char_type>>
      static void print_table(stream &s, const str& major_separator = "\n",
                                         const str& minor_separator = " ",
                                         const str& vertical_separator = " | ",
                                         const str& bottom_separator = "-------------------------")
      {
        print_entries(s, major_separator, minor_separator, vertical_separator);
        s << major_separator << bottom_separator << major_separator;
        butcher_final_like::print(s, minor_separator, vertical_separator);
      }

      ///\brief The class that defines the `i`-th entry of the Butcher tableau.
      template <g24_lib::Definitions::default_unsigned_indexer i> using entry = decltype(get_entry<i>());
      
      ///\brief The class that defines the final entry of the Butcher tableau.
      using result = decltype(get_result());
      
      ///\remark Defined for easier interoperatability with `g24_lib::internals::butcher_table_extended`.
      using first_result = result;
      ///\remark Defined for easier interoperatability with `g24_lib::internals::butcher_table_extended`.
      using second_result = void;
    };
    
    /*!
      \brief Holds an extended Butcher tableau describing an adaptive Runge-Kutta method.
      
      \tparam butcher_final_like1 A `g24_lib::internals::butcher_final_class` that
                                 properly describes the first final iteration in the Butcher tableau.
      
      \tparam butcher_final_like2 A `g24_lib::internals::butcher_final_class` that
                                 properly describes the second final iteration in the Butcher tableau.
                                 
      \tparam butcher_entry_likes A series of `g24_lib::internals::butcher_entry_class` that
                                  properly describe the intermediate steps in the Butcher tableau.
                                  The `t = t` evaluation is always performed, so the first entry
                                  corresponds to the first step after that.
    */
    template <class butcher_final_like1, class butcher_final_like2, class ... butcher_entry_likes>
    struct butcher_table_extended
    {
      ///\brief Signals whether this is an adaptive Runge-Kutta method 
      ///       (thus having an <b>extended</b> Butcher tableau) or not.
      static constexpr bool is_extended = true;
      
      ///\brief The total number of times the function must be evaluated in the method.
      static constexpr g24_lib::Definitions::default_unsigned_indexer iterations_needed = sizeof...(butcher_entry_likes) + 1;
      
      ///\brief The class that internally holds the data, not too relevant for the end-user.
      using holder = butcher_table_holder<1, butcher_entry_likes...>;
      
      ///\brief The number of intermediate values that should be stored for this method.
      static constexpr g24_lib::Definitions::default_unsigned_indexer temporaries_needed = sizeof...(butcher_entry_likes)+1;
      
      //We assume no Butcher Table with zero coefficients on a certain evaluation will be used...
      //That is, we don't explicitly check that every calculated value is used at least once.
      //Obviously, if it isn't, it's pointless to store and/or calculate it,
      //but the user should be conscious enough not to do that. I hope.
      
      template <g24_lib::Definitions::default_unsigned_indexer i>
      CUDA_HOS_DEV static constexpr auto get_entry()
      {
        return holder::template get_entry<i>();
      }
      CUDA_HOS_DEV static constexpr auto get_first_result()
      {
        return butcher_final_like1{};
      }
      CUDA_HOS_DEV static constexpr auto get_second_result()
      {
        return butcher_final_like2{};
      }
      
      template<class stream, class str = std::basic_string<typename stream::char_type>>
      static void print_entries(stream &s, const str& major_separator = "\n",
                                            const str& minor_separator = " ",
                                            const str& vertical_separator = " | ")
      {
        s << 0 << minor_separator << vertical_separator << minor_separator << major_separator;
        holder::print_entries(s, major_separator, minor_separator);
      }
      
      template<class stream, class str = std::basic_string<typename stream::char_type>>
      static void print_table(stream &s, const str& major_separator = "\n",
                                         const str& minor_separator = " ",
                                         const str& vertical_separator = " | ",
                                         const str& bottom_separator = "-------------------------")
      {
        print_entries(s, major_separator, minor_separator, vertical_separator);
        s << major_separator << bottom_separator << major_separator;
        butcher_final_like1::print(s, minor_separator, vertical_separator);
        s << major_separator;
        butcher_final_like2::print(s, minor_separator, vertical_separator);
      }
      
      ///\brief The class that defines the `i`-th entry of the extended Butcher tableau.
      template <g24_lib::Definitions::default_unsigned_indexer i> using entry = decltype(get_entry<i>());
      
      ///\brief The class that defines the first final entry of the Butcher tableau.
      using first_result = decltype(get_first_result());
      
      ///\brief The class that defines the second final entry of the Butcher tableau.
      using second_result = decltype(get_second_result());
      
      ///\brief Defined for easier interoperatability with `g24_lib::internals::butcher_table`.
      using result = second_result;
    };
    
    //Next up, a specialization for the Euler case
    //(no intermediate steps),
    //to make sure everything really works.
    
    ///\brief This is a specialization for the Euler method.
    template <class butcher_final_like>
    struct butcher_table<butcher_final_like>
    {
      static constexpr bool is_extended = false;
      
      static constexpr g24_lib::Definitions::default_unsigned_indexer iterations_needed = 1;
      
      using holder = void;
      
      static constexpr g24_lib::Definitions::default_unsigned_indexer temporaries_needed = 1;
            
      template <g24_lib::Definitions::default_unsigned_indexer i>
      CUDA_HOS_DEV static constexpr void get_entry()
      {
        return;
      }
      
      CUDA_HOS_DEV static constexpr auto get_result()
      {
        return butcher_final_like{};
      }
      
      template<class stream, class str = std::basic_string<typename stream::char_type>>
      static void print_entries(stream &s, const str& major_separator = "\n",
                                            const str& minor_separator = " ",
                                            const str& vertical_separator = " | ")
      {
        s << 0 << minor_separator << vertical_separator << minor_separator << major_separator;
      }
      
      template<class stream, class str = std::basic_string<typename stream::char_type>>
      static void print_table(stream &s, const str& major_separator = "\n",
                                         const str& minor_separator = " ",
                                         const str& vertical_separator = " | ",
                                         const str& bottom_separator = "-------------------------")
      {
        print_entries(s, major_separator, minor_separator, vertical_separator);
        s << major_separator << bottom_separator << major_separator;
        butcher_final_like::print(s, minor_separator, vertical_separator);
      }
      
      template <g24_lib::Definitions::default_unsigned_indexer i> using entry = decltype(get_entry<i>());
      
      using result = decltype(get_result());
      using first_result = result;
      using second_result = void;
    };
  }
  
  /*!
    \brief Returns an entry of a Butcher tableau.
           
    \param eval_t A `g24_lib::constexpr_fraction` that holds the evaluation time of this entry.
    
    \param fracs A series of `g24_lib::constexpr_fraction` that hold the coefficients of previous evaluations.
    
    \remark For a Butcher entry like `a/b | c/d e/f g/h ...`, one could do something like:
~~~~{cpp}
using factorT = ...;
template <factorT num, factorT denom> using frac = g24_lib::constexpr_fraction<factorT, num, denom>;
butcher_entry(frac<a, b>, frac<c, d>, frac<e, f>, frac<g, h>, ...);
~~~~
  */
  template<class factorT, factorT num, factorT denom, class ... frac_gens>
  CUDA_HOS_DEV constexpr auto butcher_entry(const constexpr_fraction<factorT, num, denom> eval_t, const frac_gens ... fracs)
  {
    return internals::butcher_entry_class<factorT, constexpr_fraction<factorT, num, denom>, frac_gens...>{};
  }
  
  /*!
    \brief Returns a final entry of a Butcher tableau.
           
    \param frac1 A `g24_lib::constexpr_fraction` that holds the coefficient of the evaluation at `t`.
    
    \param fracs A series of `g24_lib::constexpr_fraction` that hold the coefficients of previous evaluations.
    
    \remark For a Butcher final entry like `  | a/b c/d e/f g/h ...`, one could do something like:
~~~~{cpp}
using factorT = ...;
template <factorT num, factorT denom> using frac = g24_lib::constexpr_fraction<factorT, num, denom>;
butcher_final_entry(frac<a, b>, frac<c, d>, frac<e, f>, frac<g, h>, ...);
~~~~
  */
  template<class factorT, factorT num, factorT denom, class ... frac_gens>
  CUDA_HOS_DEV constexpr auto butcher_final(const constexpr_fraction<factorT, num, denom> frac1, const frac_gens ... fracs)
  //To enable type deduction, we explicitly mention the first type.
  //Of course, we assume the writer will be kind enough
  //to provide the entries with an appropriate type...
  {
    return internals::butcher_final_class<factorT, constexpr_fraction<factorT, num, denom>, frac_gens...>{};
  }
  
  /*!
    \brief Creates a Butcher tableau from the provided Butcher entries.
    
    \tparam butcher_final_like The final entry in the Butcher tableau.
    
    \tparam butcher_entry_likes The remaining entries in the Butcher tableau.
                                The `t = t` evaluation is always performed, so the first entry
                                corresponds to the first step after that.
  */
  template<class butcher_final_like, class ... butcher_entry_likes>
  CUDA_HOS_DEV constexpr auto make_butcher_table(const butcher_final_like, const butcher_entry_likes ... entries)
  {
    return internals::butcher_table<butcher_final_like, butcher_entry_likes...>{};
  }
  
  /*!
    \brief Creates an extended Butcher tableau from the provided Butcher entries.
    
    \tparam butcher_final_like1 The first final entry in the extended Butcher tableau.
    
    \tparam butcher_final_like2 The second final entry in the extended Butcher tableau.
    
    \tparam butcher_entry_likes The remaining entries in the Butcher tableau.
                                The `t = t` evaluation is always performed, so the first entry
                                corresponds to the first step after that.
  */
  template<class butcher_final_like1, class butcher_final_like2, class ... butcher_entry_likes>
  CUDA_HOS_DEV constexpr auto make_extended_butcher_table( const butcher_final_like1 b1, const butcher_final_like2 b2,
                                                           const butcher_entry_likes ... entries)
  {
    return internals::butcher_table_extended<butcher_final_like1, butcher_final_like2, butcher_entry_likes...>{};
  }
  
  /*!
    \brief A specialization for the Euler case.
  */
  template<class butcher_final_like>
  CUDA_HOS_DEV constexpr auto make_butcher_table(const butcher_final_like)
  {
    return internals::butcher_table<butcher_final_like>{};
  }
  
  namespace internals
  {
    ///\cond HIDDEN_SYMBOLS
    template <class butcher_tableau, bool defer_by_val, class Func_T,
              class Up_T, class object, class time_type,
              class tol_type, class ... Args >
    class temporal_evolver_helper;
    ///\endcond
    //And, now, the evolver itself.
    /*!
      \brief Holds temporary storage for the temporal evolver.
    */
    template <class object, class butcher_tableau> struct temporal_evolver_storage
    {
      template <class, bool, class, class, class, class, class, class ...>
      friend class temporal_evolver_helper;
      
      //private:
        object temp[butcher_tableau::temporaries_needed];
      public:
        using stored_type = object;
        static constexpr g24_lib::Definitions::default_unsigned_indexer number = butcher_tableau::temporaries_needed;
        static constexpr g24_lib::Definitions::default_unsigned_indexer size()
        {
          return number;
        }
        inline void clear()
        {
          for(g24_lib::Definitions::default_unsigned_indexer i = 0; i < number; ++i)
            {
              temp[i].clear();
            }
        }
    };
    ///\cond HIDDEN_SYMBOLS
    template <class butcher_tableau, bool defer_by_val, class Func_T,
              class Up_T, class object, class time_type,
              class tol_type, class ... Args >
    class temporal_evolver_helper
    {
      public:
      
        using storage = temporal_evolver_storage<std::decay_t<object>, butcher_tableau>;
        
        
        template<class entry, g24_lib::Definitions::default_unsigned_indexer order = 0>
        CUDA_HOS_DEV static auto value_iteration(const object &obj, const storage &store, const time_type& dt)
        {
          if constexpr (std::is_void_v<entry>)
            {
              return;
            }
          else if constexpr (order == 0)
            {
              return defer<std::decay_t<object>, defer_by_val>(obj) + (value_iteration<entry, 1>(obj, store, dt)) * dt;
            }
          else if constexpr(order == entry::number)
            {
              return defer<std::decay_t<object>, defer_by_val>(store.temp[order-1])*entry::factors[order-1]; 
            }
          else
            {
              return defer<std::decay_t<object>, defer_by_val>(store.temp[order-1]) * entry::factors[order-1] +
                     value_iteration<entry, order + 1>(obj, store, dt);
            }
        }
        
        template<class entry> using value_iteration_t = decltype( value_iteration<entry>( std::declval<object>(),
                                                                                          std::declval<storage>(),
                                                                                          std::declval<time_type>() ) );
        
        template<class result, g24_lib::Definitions::default_unsigned_indexer order = 0>
        CUDA_HOS_DEV static auto final_iteration(const object &obj, const storage &store, const time_type& dt)
        {
          if constexpr (std::is_void_v<result>)
            {
              return;
            }
          else if constexpr (order == 0)
            {
              return defer<std::decay_t<object>, defer_by_val>(obj) + (final_iteration<result, 1>(obj, store, dt)) * dt;
            }
          else if constexpr(order == result::number)
            {
              return defer<std::decay_t<object>, defer_by_val>(store.temp[order-1])*result::factors[order-1]; 
            }
          else
            {
              return defer<std::decay_t<object>, defer_by_val>(store.temp[order-1]) * result::factors[order-1] +
                     final_iteration<result, order + 1>(obj, store, dt);
            }
        }
        
        template<class result> using final_iteration_t = decltype( final_iteration<result>( std::declval<object>(),
                                                                                            std::declval<storage>(),
                                                                                            std::declval<time_type>() ) );
                                                                                          
        template <g24_lib::Definitions::default_unsigned_indexer order = 0>
        CUDA_HOS_DEV static auto evolve( Func_T &&f, Up_T &&update, object && obj, const time_type &current,
                                         const time_type &dt, const tol_type &tol,
                                         storage &store, Args&&... params)
        {          
          if constexpr(butcher_tableau::iterations_needed == 1)
          {
            f(store.temp[0], std::forward<object>(obj), current, dt, std::forward<Args>(params)...);
            auto&& final_1 = final_iteration<typename butcher_tableau::result>(obj, store, dt);
            //No forwarding here because we deal with const references.
            return update(std::forward<object>(obj), std::forward<decltype(final_1)>(final_1),
                          dt, tol, std::forward<Args>(params)...);
          }
          else if constexpr(order == 0)
            {
              f(store.temp[0], std::forward<object>(obj), current, dt, std::forward<Args>(params)...);
              return evolve<1>(std::forward<Func_T>(f), std::forward<Up_T>(update),
                              std::forward<object>(obj), current, dt, tol, store, std::forward<Args>(params)...);
            }
          else if constexpr(order == butcher_tableau::iterations_needed - 1)
            {
              using entry = typename butcher_tableau::template entry<order>;
              
              auto&& value = value_iteration<entry>(obj, store, dt);
              
              f(store.temp[order], std::forward<decltype(value)>(value), current + entry::evaluation_time*dt,
                  dt, std::forward<Args>(params)...);
              
              
              if constexpr (butcher_tableau::is_extended)
                {
                                  
                  auto&& final_1 = final_iteration<typename butcher_tableau::first_result>(obj, store, dt);
                  
                  auto&& final_2 = final_iteration<typename butcher_tableau::second_result>(obj, store, dt);
                                    
                  return update(std::forward<object>(obj), std::forward<decltype(final_2)>(final_2),
                                std::forward<decltype(final_1)>(final_1), dt, tol, std::forward<Args>(params)...);
                }
              else
                {
                  auto&& final_1 = final_iteration<typename butcher_tableau::result>(obj, store, dt);
                  
                  return update(std::forward<object>(obj), std::forward<decltype(final_1)>(final_1),
                                nullptr, dt, tol, std::forward<Args>(params)...);
                }
            }
          else
            {
              using entry = typename butcher_tableau::template entry<order>;
              
              auto value = value_iteration<entry>(obj, store, dt);
              
              f(store.temp[order], value, current + entry::evaluation_time*dt, dt, params...);
              
              return evolve<order + 1>(std::forward<Func_T>(f), std::forward<Up_T>(update),
                              std::forward<object>(obj), current, dt, tol, store, std::forward<Args>(params)...);
            }
        }
      template <g24_lib::Definitions::default_unsigned_indexer step>
      using iteration_t =
      std::conditional_t <  (step < butcher_tableau::iterations_needed && step > 0) ,
      
                            value_iteration_t<typename butcher_tableau::template entry<step> >,
                            
                            std::conditional_t <  butcher_tableau::is_extended,
                            
                                                  std::conditional_t < (step < butcher_tableau::iterations_needed + 2),
                                                  
                                                                       std::conditional_t< step ==  butcher_tableau::iterations_needed,
                                                                                           final_iteration_t<typename butcher_tableau::second_result>,
                                                                                           final_iteration_t<typename butcher_tableau::first_result>
                                                                                         >,
                                                                       void >,
                                                                       
                                                  std::conditional_t < step == butcher_tableau::iterations_needed,
                                                                       final_iteration_t<typename butcher_tableau::result>,
                                                                       void >
                                                                       
                                               >
                        
                        >;
    };      
    ///\endcond
  }
  
  /*!
    \brief Evolves a function in time according to the Runge-Kutta method specified by \p butcher_tableau.
    
    \tparam butcher_tableau The Butcher Tableau of the specified Runge-Kutta method.
    
    \tparam defer_by_value If `true`, pass things by value rather than reference.
                           (May be useful for interoperatability between different memory contexts,
                            but not relevant for most end-users)
  */
  template <class butcher_tableau, bool defer_by_value = false>
  class temporal_evolver
  {
    public:
      template <class object> using storage = internals::temporal_evolver_storage<std::decay_t<object>, butcher_tableau>;
      ///< \brief The object that holds the temporary values for the iterations.
      using tableau = butcher_tableau;
      ///< \brief The Butcher tableau.
      
      /*!
        \brief The type that holds the current value of the function
               at the (0-indexed) i-th step in the Runge-Kutta method.
        
        \tparam step The step being considered.
        
        \tparam obj The type that holds the values of the function.
        
        
        \remark The 0-th step corresponds to the first evaluation after `t = t`.
        
        \remark If the method is not adaptive (the Butcher tableau is not extended),
                for the step corresponding to `butcher_tableau::iterations_needed`,
                this is the type that holds the value of the function at `t = t + dt`
                after combining the several evaluations required by the method.
        
        \remark If the method is adaptive, `butcher_tableau::iterations_needed`
                and `butcher_tableau::iterations_needed + 1` hold the two different
                estimates according to the two final entries in the Butcher tableau
                of the value of the function at `t = t + dt`.
                
        \tparam time_type The type that holds the current time and the timestep.
        
        \tparam Func_T The type that specifies the (programming) function
                       that calculates the derivative of the (mathematical) function.
        
        \tparam Up_T The type that specifies the (programming) function
                     that updates the current value of the (mathematical) function.
        
        \tparam Args Extra arguments passed to both \p Func_T and \p Up_T.
        
        \sa `g24_lib::temporal_evolver::evolve`.
      */
      template <g24_lib::Definitions::default_unsigned_indexer step, class obj,
                class time_type = g24_lib::Definitions::default_floating_point,
                class Func_T = dummy_void_function,
                class Up_T = dummy_void_function,
                class ... Args>
      using step_result_t = typename internals::temporal_evolver_helper<butcher_tableau, defer_by_value,
                                                                        Func_T, Up_T, obj, time_type,
                                                                        time_type, Args...>::template
                                                                              iteration_t<step>;
      //The type that will be used to update the object or array at the step (0-indexed) in question.
      
      
      
      /*!
        \brief Calculates a timestep according to the Runge-Kutta method specified by `butcher_tableau`.
        
        \param store Appropriate storage to hold the temporary values for the method.
                     Being externally managed, it is assumed it has sufficient capacity
                     (e. g. in case we are dealing with arrays).
        
        \param f Calculates the derivative of the function being advanced.
        
        \pre \p f must take as arguments:
                   * A <b>non-const</b> reference to the \p object where the derivative is to be stored
                   * (A const reference to) the current value of the function,
                     which, given that `g24_lib::defer` is used, should be templated
                     (thus, we cannot use a plain old function, but must use
                      a functor with a templated `operator()` or a generic lambda)
                   * (A const reference to) the current time
                   * (A const reference to) the current timestep
                   * The extra arguments specified in \p params
                     (with any desired combination of constness and references,
                      since the internal functions use perfect forwarding).
        
        \param update Updates the current object with the value after the timestep.
        
        \pre \p update must take as arguments:
                  * A <b>non-const</b> reference to the current value of the function
                  * (A const reference to) one estimate of the next value of the function,
                    which, again, should be templated
                  * (A const reference to) the other estimate of the next value of the function,
                    which also should be templated; in case the method is not adaptive,
                    this will be `nullptr`, so the user can check for this case with `std::is_null_pointer_v`.
                  * (A const reference to) the current timestep
                  * (A const reference to) the user-provided tolerance
                   * The extra arguments specified in \p params
                     (with any desired combination of constness and references,
                      since the internal functions use perfect forwarding).
        
        \param obj The current value of the function.
        
        \param current The current time.
        
        \param dt The timestep to advance the function.
        
        \param tol The tolerance to be used in \p update
                   (mainly for adaptive methods, where it
                    is used to regulate the estimation of the next timestep).
                    
        \param params Extra parameters to be passed to \p f and \p update.
        
        \returns The result of \p update, which can be useful for outputting
                 diagnostic info (such as the estimated error of the method).
      */
      template <class Func_T, class Up_T, class object, class time_type, class tol_type, class ... Args>
      CUDA_HOS_DEV inline static auto evolve(storage<object> &store,
                                             Func_T &&f, Up_T &&update, object && obj, const time_type &current,
                                             const time_type &dt, const tol_type &tol,
                                             Args&&... params )
      {
        using helper = internals::temporal_evolver_helper< butcher_tableau, defer_by_value,
                                                          Func_T, Up_T, object, time_type, tol_type, Args... >;
        return helper::evolve(std::forward<Func_T>(f), std::forward<Up_T>(update),
                              std::forward<object>(obj), current, dt, tol, store, std::forward<Args>(params)...);
      }
      
      /*!
        \brief Resizes \p store to be able to deal with objects of size \p size.
        
        \remark This does nothing if the objects held in \p store are not containers.
        
        \pre The object being held in \p store must either be a container
             as defined by `g24_lib::is_container` and have a `resize()` method
             or not satisfy the conditions for being a container.
      */
      template <class indexer, class storage>
      inline static void resize_temporaries(const indexer size, storage &store)
      {
        if constexpr (g24_lib::is_container<typename storage::object_type>)
          {
            for (indexer i = 0; i < store.size(); ++i)
              {
                store[i].resize(size);
              }
          }
      }
      
      /*!
        \brief Calculates a timestep according to the Runge-Kutta method specified by `butcher_tableau`,
               internally handling the storage for the temporary values.
        
        \remark This is not recommended for sufficiently complex objects (e. g. arrays)
                that will be evolved several times, since the temporary is allocated and
                deallocated at each step, with the obvious decrease in performance.
                
        \param f Calculates the derivative of the function being advanced.
        
        \pre \p f must take as arguments:
                   * A <b>non-const</b> reference to the \p object where the derivative is to be stored
                   * (A const reference to) the current value of the function,
                     which, given that `g24_lib::defer` is used, should be templated
                     (thus, we cannot use a plain old function, but must use
                      a functor with a templated `operator()` or a generic lambda)
                   * (A const reference to) the current time
                   * (A const reference to) the current timestep
                   * The extra arguments specified in \p params
                     (with any desired combination of constness and references,
                      since the internal functions use perfect forwarding).
        
        \param update Updates the current object with the value after the timestep.
        
        \pre \p update must take as arguments:
                  * A <b>non-const</b> reference to the current value of the function
                  * (A const reference to) one estimate of the next value of the function,
                    which, again, should be templated
                  * (A const reference to) the other estimate of the next value of the function,
                    which also should be templated; in case the method is not adaptive,
                    this will be `nullptr`, so the user can check for this case with `std::is_null_pointer_v`.
                  * (A const reference to) the current timestep
                  * (A const reference to) the user-provided tolerance
                   * The extra arguments specified in \p params
                     (with any desired combination of constness and references,
                      since the internal functions use perfect forwarding).
        
        \param obj The current value of the function.
        
        \param current The current time.
        
        \param dt The timestep to advance the function.
        
        \param tol The tolerance to be used in \p update
                   (mainly for adaptive methods, where it
                    is used to regulate the estimation of the next timestep).
                    
        \param params Extra parameters to be passed to \p f and \p update.
        
        \returns The result of \p update, which can be useful for outputting
                 diagnostic info (such as the estimated error of the method).
      */
      template <class Func_T, class Up_T, class object, class time_type, class tol_type, class ... Args>
      CUDA_HOS_DEV inline static auto evolve(Func_T &&f, Up_T &&update, object &&obj, const time_type &current,
                                             const time_type &dt, const tol_type &tol, Args&&... params )
      {
        storage<object> store;
        if constexpr (g24_lib::is_container<object>)
          {
            resize_temporaries(obj.size(), store);
            //If the object is not a container, there's no need to resize it.
            //In fact, resize_temporaries doesn't do anything if it isn't a container.
          }
        return evolve(store, std::forward<Func_T>(f), std::forward<Up_T>(update),
                             std::forward<object>(obj), current, dt, tol, std::forward<Args>(params)...);
      }
  };
  
  /*!
    \brief The results of a `g24_lib::simple_evolve`.
    
    \tparam diffT The type that holds the difference between successive iterations.
    
    \tparam errorT The type that holds the estimated error for each iteration.
    
    \tparam timeT The type that holds the current and predicted timesteps.
  */
  template<class diffT, class errorT, class timeT>
  struct simple_evolve_result
  {
    timeT dt_used;
    ///< \brief The timestep used in the iterations.
    timeT next_dt;
    ///< \brief The next timestep, as predicted by the method.
    ///         (If the method isn't adaptive, it's the same as before.)
    errorT error;
    ///< \brief The error estimated from the method.
    ///         (For non-adaptive methods, it is given
    ///          the maximum value that \p errorT can hold.)
    diffT difference;
    ///< \brief The variation between sucessive iterations.
  };
  
  namespace internals
  {
  
    /*!
      \brief Updates a simple (non-array) object to a new value, after being evolved.
      
      \param obj The object to be updated.
      
      \param recent1 One estimate of the next value.
      
      \param recent2 Another estimate of the next value
                     (or `nullptr` if the chosen method was non-adaptive).
      
      \param dt The current timestep.
      
      \param tolerance The user-specified tolerance.
      
      \remark In this case, for adaptive methods, we have:
              `next_dt = dt * (tolerance/(2*error)) ^(1/4)`,
              where `error` is the difference between the two
              estimates for the next value of the function.
      
      \param params Extra parameters that the user may specify
                    for the evaluation of the derivative,
                    that, as per `g24_lib::temporal_evolver::evolve()`,
                    are passed here, even though they are ignored.
    */
    template <class object, class time_type, class tol_type, class NewT1, class NewT2, class ... Args>
    CUDA_HOS_DEV inline auto trivial_updater( object &obj, const NewT1 &recent1,
                                              const NewT2 &recent2, const time_type &dt, const tol_type &tolerance,
                                              Args&& ... params )
    {
      using namespace std;
      //For abs() and CUDA interoperatability.
      using err_diff_T = decltype(abs(std::declval<object>()));
      if constexpr (std::is_null_pointer_v<NewT2>)
      //Non-adaptive method
        {
          simple_evolve_result<err_diff_T, err_diff_T,time_type> ret;
          ret.dt_used = dt;
          ret.next_dt = dt;
          ret.error = std::numeric_limits<err_diff_T>::max();
          ret.difference = abs(-obj + recent1);
          obj = object(recent1);
          return ret;
        }
      else
      //Adaptive method
        {
          simple_evolve_result<err_diff_T, err_diff_T,time_type> ret;
          ret.dt_used = dt;
          ret.error = abs(abs(recent1)-abs(recent2));
          ret.next_dt = time_type(dt * pow(tolerance/(2*(ret.error)),0.25));
          if (ret.next_dt < 0.01 * dt)
            {
              ret.next_dt = 0.01 * dt;
            }
          else if (ret.next_dt > 100 * dt)
            {
              ret.next_dt = 100 * dt;
            }
          ret.difference = abs(-obj + recent1);
          obj = object(recent1);
          return ret;
        }
    }
    
    /*!
      \brief The functor for `g24_lib::internals::trivial_updater`.
      
      \remark We could do this with generic lambdas as well:
~~~~{cpp}
auto trivial_functor_lambda = [](auto &obj, const auto &recent1,
                                 const auto &recent2, const auto &dt,
                                 const auto& tolerance, const auto &... params )
                                 { return trivial_updater(obj, recent1, recent2, dt, tolerance, params...); };
~~~~
    \remark However, the fact that generic lambdas use auto for template parameters
            impairs clarity too much for the author's taste.
    */
    struct trivial_updater_functor
    {
      template<class object, class time_type, class tol_type, class NewT1, class NewT2, class ... Args>
      CUDA_HOS_DEV inline auto operator() ( object &obj, const NewT1 &recent1,
                                            const NewT2 &recent2, const time_type &dt, const tol_type &tolerance,
                                            Args&&... params) const
      {
        return trivial_updater(obj, recent1, recent2, dt, tolerance, std::forward<Args>(params)...);
      }
    };
    
  }
  
  /*!
    \brief Provides a simpler wrapper for `g24_lib::temporal_evolver`
           for objects that are known to be simple to update
           (i. e., not arrays, so something like a scalar or a vector function).
    
    \tparam method The Runge-Kutta method (extended or not) with which to perform the evolution.
    
    \param f Calculates the derivative of the function being advanced.
    
    \pre \p f must take as arguments:
               * A <b>non-const</b> reference to the \p object where the derivative is to be stored
               * (A const reference to) the current value of the function,
                 which, given that `g24_lib::defer` is used, should be templated
                 (thus, we cannot use a plain old function, but must use
                  a functor with a templated `operator()` or a generic lambda)
               * (A const reference to) the current time
               * (A const reference to) the current timestep
               * The extra arguments specified in \p params
                 (with any desired combination of constness and references,
                  since the internal functions use perfect forwarding).
    
    \param obj The current value of the function.
    
    \param current The current time.
    
    \param dt The timestep to advance the function.
    
    \param tol The tolerance to be used in \p update
               (mainly for adaptive methods, where it
                is used to regulate the estimation of the next timestep).
                
    \param params Extra parameters to be passed to \p f and \p update.
    
    \returns A `g24_lib::simple_evolve_result` of appropriate types.
    
    \sa `g24_lib::temporal_evolver::evolve`
  */
  template<class method, class Func_T, class object, class time_type, class tol_type, class ... Args>
  CUDA_HOS_DEV inline auto simple_evolve( Func_T &&f, object && obj, const time_type &current,
                                          const time_type &dt, const tol_type &tol, Args&&... params)
  //Provides a simpler wrapper for a temporal_evolver,
  //in a case where the update is trivial.
  {
    return temporal_evolver<method>::evolve(std::forward<Func_T>(f),
                                            internals::trivial_updater_functor{},
                                            std::forward<object>(obj),
                                            current, dt, tol,
                                            std::forward<Args>(params)...);
  }
  
  
  /*!
    \brief Holds Runge-Kutta Methods for use with `g24_lib::temporal_evolver`.
  */
  namespace RungeKuttaMethods
  {
    ///\brief A simple shorthand notation to ease the writing of the tables.
    template <class Factor, Factor num, Factor denom> using frac = constexpr_fraction<Factor, num, denom>;
    
    /*!
      \brief Explicit, non-adaptive Runge-Kutta methods.
    */
    namespace Explicit
    {
      ///\brief The classic, 4th order Runge-Kutta.
      template<class F = g24_lib::Definitions::default_signed_indexer> using RK4_classic =
        decltype(
          make_butcher_table
            (
              butcher_final(frac<F,1,6>(),frac<F,1,3>(),frac<F,1,3>(),frac<F,1,6>()),
              butcher_entry(frac<F,1,2>(),frac<F,1,2>()),
              butcher_entry(frac<F,1,2>(),frac<F,0,1>(),frac<F,1,2>()),
              butcher_entry(frac<F,1,1>(),frac<F,0,1>(),frac<F,0,1>(),frac<F,1,1>())
            ) 
       );
      
      ///\brief The classic, 4th order Runge-Kutta.
      template<class F = g24_lib::Definitions::default_signed_indexer> using RK4 = RK4_classic<F>;
      
      ///\brief A 4th order method known as the <i>3/8-rule</i>.
      template<class F = g24_lib::Definitions::default_signed_indexer> using RK4_3_8_rule =
        decltype(
          make_butcher_table
            (
              butcher_final(frac<F,1,8>(),frac<F,3,8>(),frac<F,3,8>(),frac<F,1,8>()),
              butcher_entry(frac<F,1,3>(),frac<F,1,3>()),
              butcher_entry(frac<F,2,3>(),frac<F,-1,3>(),frac<F,1,1>()),
              butcher_entry(frac<F,1,1>(),frac<F,1,1>(),frac<F,-1,1>(),frac<F,1,1>())
            )
       );
      
      ///\brief The 1st order (forward) Euler's method.
      template<class F = g24_lib::Definitions::default_signed_indexer> using Euler = 
        decltype(
            make_butcher_table
              (
                butcher_final(frac<F,1,1>())
              )
        );
      
      ///\brief The 2nd order midpoint method.
      template<class F = g24_lib::Definitions::default_signed_indexer> using Midpoint =
        decltype(
          make_butcher_table
            (
              butcher_final(frac<F,0,1>(),frac<F,1,2>()),
              butcher_entry(frac<F,1,2>(),frac<F,1,2>())
            )
         );
         
      ///\brief The 2nd order Heun's method.
      template<class F = g24_lib::Definitions::default_signed_indexer> using Heun =
        decltype(
          make_butcher_table
            (
              butcher_final(frac<F,1,2>(),frac<F,1,2>()),
              butcher_entry(frac<F,1,1>(),frac<F,1,1>())
            )
         );
                
      ///\brief The 2nd order Ralston's method. 
      template<class F = g24_lib::Definitions::default_signed_indexer> using Ralston =
        decltype(
          make_butcher_table
            (
              butcher_final(frac<F,1,4>(),frac<F,3,4>()),
              butcher_entry(frac<F,2,3>(),frac<F,2,3>())
            )
          );
    }
    
    /*!
      \brief Adaptive Runge-Kutta methods.
    */
    namespace Adaptive
    {
      ///\brief The Runge-Kutta-Fehlberg method, 4th order with 5th order error estimation.
      template<class F = g24_lib::Definitions::default_signed_indexer> using RKF45 = 
        decltype(
          make_extended_butcher_table
            (
              butcher_final(frac<F,16,135>(),frac<F,0,1>(),frac<F,6656,12825>(),frac<F,28561,56430>(),frac<F,-9,50>(),frac<F,2,55>()),
              butcher_final(frac<F,25,216>(),frac<F,0,1>(),frac<F,1408,2565>(),frac<F,2197,4104>(),frac<F,-1,5>()),
              butcher_entry(frac<F,1,4>(),frac<F,1,4>()),
              butcher_entry(frac<F,3,8>(),frac<F,3,32>(),frac<F,9,32>()),
              butcher_entry(frac<F,12,13>(),frac<F,1932,2197>(),frac<F,-7200,2197>(),frac<F,7296,2197>()),
              butcher_entry(frac<F,1,1>(),frac<F,439,216>(),frac<F,-8,1>(),frac<F,3680,513>(),frac<F,-845,4104>()),
              butcher_entry(frac<F,1,2>(),frac<F,-8,27>(),frac<F,2,1>(),frac<F,-3544,2565>(),frac<F,1859,4104>(),frac<F,-11,40>())
            )
      );
      
      ///\brief The Runge-Kutta-Fehlberg method, 4th order with 5th order error estimation.
      template<class F = g24_lib::Definitions::default_signed_indexer> using Runge_Kutta_Fehlberg = RKF45<F>;
      
      ///\brief The Euler-Heun method, 1storder with 2nd order error estimation.
      template<class F = g24_lib::Definitions::default_signed_indexer> using RK12 =
        decltype(
          make_extended_butcher_table
            (
              butcher_final(frac<F,1,2>(),frac<F,1,2>()),
              butcher_final(frac<F,1,1>(),frac<F,0,1>()),
              butcher_entry(frac<F,1,1>(),frac<F,1,1>())
            )
        );
        
      ///\brief The Euler-Heun method, 1st order with 2nd order error estimation.
      template<class F = g24_lib::Definitions::default_signed_indexer> using Heun_Euler = RK12<F>;
      
      ///\brief The Cash-Karp method, 4th order with 5th order error estimation.
      template<class F = g24_lib::Definitions::default_signed_indexer> using CK45 = 
        decltype(
          make_extended_butcher_table
            (
              butcher_final(frac<F,37,378>(),frac<F,0,1>(),frac<F,250,621>(),frac<F,125,594>(),frac<F,0,1>(),frac<F,512,1771>()),
              butcher_final(frac<F,2825,27648>(),frac<F,0,1>(),frac<F,18575,48384>(),frac<F,13525,55296>(),frac<F,277,14336>(),frac<F,1,4>()),
              butcher_entry(frac<F,1,5>(),frac<F,1,5>()),
              butcher_entry(frac<F,3,10>(),frac<F,3,40>(),frac<F,9,40>()),
              butcher_entry(frac<F,3,5>(),frac<F,3,10>(),frac<F,-9,10>(),frac<F,6,5>()),
              butcher_entry(frac<F,1,1>(),frac<F,-11,54>(),frac<F,5,2>(),frac<F,-70,27>(),frac<F,35,27>()),
              butcher_entry(frac<F,7,8>(),frac<F,1631,55296>(),frac<F,175,512>(),frac<F,575,13824>(),frac<F,44275,110592>(),frac<F,253,4096>())
            )
        );
        
      ///\brief The Cash-Karp method, 4th order with 5th order error estimation.
      template<class F = g24_lib::Definitions::default_signed_indexer> using Cash_Karp = CK45<F>;
    }
  
  }
  
}

 
#endif

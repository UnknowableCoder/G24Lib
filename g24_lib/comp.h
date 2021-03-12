#ifndef G24_LIB_COMP
#define G24_LIB_COMP

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

\file comp.h

\brief Defines `g24_lib::comp`, a class for handling complex numbers.

\author Nuno Fernandes (main coder, current maintainer)

\author Gonçalo Vaz (auxiliary coder and tester)

*/
namespace g24_lib
{
  /*!
    \brief A complex number.
    
    \tparam Type The underlying type.
    
    \pre \p Type should have usual arithmetic operators.
    
    \details This class holds the complex numbers in two simultaneous representations:
    
    \details Cartesian form: `a + b*i`
    
    \details Polar form: `r * exp(i*theta)` (`theta` in fractions of pi, that is, in the range `]-1, 1]`)
      
    \details Though this doubles memory requirements, it allows for easier computations,
             using the cartesian form for additions and subtractions
             and the polar form for multiplications and divisions.
      
    \remark Since the standard library already implements `std::complex`,
             this might be more than a bit superfluous unless \c CUDA
             interoperatability is significant...
  */
  template <class Type> class comp
  {
  private:
    Type rho, theta;
    //Polar form; theta in ]-1, 1], since we are using fractions of pi.
    Type re, im;
    //Cartesian form
    
    /*!
      \brief Updates the polar form representation.
    */
    CUDA_HOS_DEV inline void update_polar()
    {
      rho = (Type) sqrt(re*re + im*im);
      theta = (Type) atan2(im, re)/(g24_lib::pi<FLType>);
    }
    
    /*!
      \brief Updates the cartesian form representation.
    */
    CUDA_HOS_DEV inline void update_cart()
    {
      re = rho*cos(theta*g24_lib::pi<Type>);
      im = rho*sin(theta*g24_lib::pi<Type>);
    }
  public:
    CUDA_HOS_DEV comp()
    {
      re = (Type) 0;
      im = (Type) 0;
      rho = (Type) 0;
      theta = (Type) 0;
    }
    /*!
      \brief Constructor from a real number.
    */
    CUDA_HOS_DEV comp(const Type &x)
    {
      re = x;
      im = (Type) 0;
      rho = (Type) fabs(x);
      theta = (Type) 0.5 - 0.5*sign(x);
    }
    /*!
      \brief Constructor from two numbers, which are taken to be in cartesian form unless \p pol is true,
              case in which they will be interpreted to be in polar form.
    */
    CUDA_HOS_DEV comp (const Type &x, const Type &y, const bool pol = false)
    {
      if(!pol)
        {
          re = x;
          im = y;
          update_polar();
        }
      else
        {
          rho = x;
          theta = stand(y);
          update_cart();
        }
    }
    /*!
      \brief Constructor from two numbers in a appropriately sized `g24_lib::fspoint`,
              which are taken to be in cartesian form unless \p pol is true,
              case in which they will be interpreted to be in polar form.
    */
    template<class indexer, indexer size> CUDA_HOS_DEV comp (const fspoint<Type, indexer, size> &p, const bool pol = false)
    {
      static_assert(size > 1, "The vector must have at least two elements to construct the complex number!");
      if(!pol)
        {
          re = p[0];
          im = p[1];
          update_polar();
        }
      else
        {
          rho = (Type) fabs(p[0]);
          theta = stand(p[1]);
          update_cart();
        }
    }
    
    /*!
      \brief Fastest constructor, for when the full expression for the number is known.
      
      \param x The real part
      
      \param y The imaginary part
      
      \param r The absolute value
      
      \param t The argument (in fractions of pi).
      
      \remark Since this is meant to be used whenever all the values are known,
              no checks are made for the validity of the input.
    */
    CUDA_HOS_DEV comp (const Type x, const Type y, const Type r, const Type t)
    {
      re = x;
      im = y;
      rho = r;
      theta = t;
    }
    
    CUDA_HOS_DEV comp (const comp &z)
    {
      re = z.re;
      im = z.im;
      rho = z.rho;
      theta = z.theta;
    }
    
    CUDA_HOS_DEV inline comp operator+ (const comp &z) const
    {
      return comp<Type>(re+z.re, im+z.im);
    }
    
    CUDA_HOS_DEV inline comp operator+ (const Type &x) const
    {
      return comp<Type>(re+x, im);
    }
    
    friend CUDA_HOS_DEV inline comp<Type> operator+ (const Type &x, const comp<Type> &z)
    {
      return comp<Type>(z.re+x, z.im);
    }
    
    CUDA_HOS_DEV inline comp operator- (const comp &z) const
    {
      return comp<Type>(re-z.re, im-z.im);
    }
    
    CUDA_HOS_DEV inline comp operator- (const Type &x) const
    {
      return comp<Type>(re-x, im);
    }
    
    friend CUDA_HOS_DEV inline comp<Type> operator- (const Type &x, const comp<Type> &z)
    {
      return comp<Type>(x-z.re, -z.im);
    }
    
    CUDA_HOS_DEV inline comp operator- () const
    {
      return comp<Type>(-re, -im, rho, stand(theta + 1.0));
    }
    
    CUDA_HOS_DEV inline comp operator* (const comp &z) const
    {
      return comp<Type>(re*z.re-im*z.im, re*z.im+im*z.re, rho*z.rho, stand(theta+z.theta));
    }
    
    CUDA_HOS_DEV inline comp operator* (const Type &s) const
    {
      return comp<Type>(s*re, s*im, (Type) fabs(s)*rho, stand((s < 0) + theta));
    }
    
    friend CUDA_HOS_DEV inline comp<Type> operator* (const Type &s, const comp<Type> &z)
    {
      return comp<Type>(s*z.re, s*z.im, (Type) fabs(s)*z.rho, stand((s < 0) + z.theta));
    }
    
    CUDA_HOS_DEV inline comp operator/ (const comp &z) const
    {
      return comp<Type>((re*z.re+im*z.im)/(z.rho*z.rho), (im*z.re-re*z.im)/(z.rho*z.rho), rho/z.rho, stand(theta-z.theta));
    }
    
    CUDA_HOS_DEV inline comp<Type> operator/ (const Type &s) const
    {
      return comp<Type>(re/s , im/s , (Type) rho/fabs(s), stand(theta - (s < 0)));
    }
    
    friend CUDA_HOS_DEV inline comp<Type> operator/ (const Type &s, const comp<Type> &z)
    {
      return comp<Type>((s*z.re)/(z.rho*z.rho), (-s*z.im)/(z.rho*z.rho), (Type) fabs(s)/z.rho, stand((s < 0) - z.theta));
    }
    
    CUDA_HOS_DEV inline comp & operator= (const comp &z)
    {
      re = z.re;
      im = z.im;
      rho = z.rho;
      theta = z.theta;
      return (*this);
    }
    
    CUDA_HOS_DEV inline comp & operator+= (const comp &z)
    {
      re +=z.re;
      im += z.im;
      update_polar();
      return (*this);
    }
    
    CUDA_HOS_DEV inline comp & operator-= (const comp &z)
    {
      re -= z.re;
      im -= z.im;
      update_polar();
      return (*this);
    }
    
    CUDA_HOS_DEV inline comp & operator*= (const comp &z)
    {
      comp<Type> temp;
      temp.re = re*z.re-im*z.im;
      temp.im = re*z.im+im*z.re;
      temp.rho = rho*z.rho;
      temp.theta = stand(theta+z.theta);
      (*this) = temp;
      return (*this);
    }
    
    CUDA_HOS_DEV inline comp & operator/= (const comp &z)
    {
      comp<Type> temp;
      temp.re = (re*z.re+im*z.im)/(z.rho*z.rho);
      temp.im = (im*z.re-re*z.im)/(z.rho*z.rho);
      temp.rho = rho/z.rho;
      temp.theta = stand(theta-z.theta);
      (*this) = temp;
      return (*this);
    }
    
    /*!
      \remark The comparison is done through the cartesian representation
              since the argument is ambiguous whenever the norm is zero...
    */
    CUDA_HOS_DEV inline bool operator == (const comp &z) const
    {
      return (re == z.re && im == z.im);
    }
    
    /*!
      \brief Checks if the complex is equal to \p z within a tolerance provided by \p epsilon.
    
      \remark The comparison is done through the cartesian representation
              since the argument is ambiguous whenever the norm is zero...
    */
    CUDA_HOS_DEV inline bool checkequal(const comp &z, double epsilon = std::numeric_limits<double>::epsilon()) const
    {
      return (fabs(re - z.re) < epsilon && fabs(im - z.im) < epsilon);
    }
    
    /*!
      \remark The comparison is done through the cartesian representation
              since the argument is ambiguous whenever the norm is zero...
    */
    CUDA_HOS_DEV inline bool operator != (const comp &z) const
    {
      return (re != z.re || im != z.im);
    }
    
    /*!
      \brief Checks if the complex is different from \p z within a tolerance provided by \p epsilon.
    
      \remark The comparison is done through the cartesian representation
              since the argument is ambiguous whenever the norm is zero...
    */
    CUDA_HOS_DEV inline bool checkdiff(const comp &z, double epsilon = std::numeric_limits<double>::epsilon()) const
    {
      return (fabs(re - z.re) >= epsilon || fabs(im - z.im) >= epsilon);
    }
    
    /*!
      \brief Returns the real part of the complex number.
    */
    CUDA_HOS_DEV inline Type real() const
    {
      return re;
    }
    
    /*!
      \brief Returns the imaginary part of the complex number.
    */
    CUDA_HOS_DEV inline Type imag() const
    //Parte imaginária
    {
      return im;
    }
    
    /*!
      \brief Returns the absolute value of the complex number.
    */
    CUDA_HOS_DEV inline Type abs() const
    {
      return rho;
    }
    
    /*!
      \brief Returns the argument of the complex number, as a fraction of pi if \p redce is true, else as number in `]-pi, pi]`.
    */
    CUDA_HOS_DEV inline Type arg(const bool reduce = false) const
    {
      if(reduce)
        {
          return theta;
        }
      else
        {
          return theta*g24_lib::pi<Type>;
        }
    }
    
    /*!
      \brief Returns the conjugate of the complex number.
    */
    CUDA_HOS_DEV inline comp conjug() const
    {
      return comp<Type>(re, -im, rho, -theta);
    }
    
    /*!
      \brief Returns the complex logarithm of the complex number.
    */
    friend CUDA_HOS_DEV inline comp<Type> log(const comp<Type> &z)
    //Logaritmo complexo
    {
      return comp <Type> (log(z.rho), z.theta, false);
    }
    
    /*!
      \brief Returns the complex exponential of the complex number.
    */
    friend CUDA_HOS_DEV inline comp<Type> exp(const comp<Type> &z)
    {
      return comp <Type> (exp(z.re)*cos(z.im), exp(z.re)*sin(z.im), exp(z.re), stand(z.im));
    }
    
    /*!
      \brief The imaginary unit.      
    */
    static comp<Type> I_;
    
    /*!
      \brief Returns the complex sine of the complex number.
    */
    friend CUDA_HOS_DEV inline comp<Type> sin(const comp<Type> &z)
    {
      return (exp(I_*z) - exp(-I_*z))/(((Type) 2)*I_);
    }
    
    /*!
      \brief Returns the complex cosine of the complex number.
    */
    friend CUDA_HOS_DEV inline comp<Type> cos(const comp<Type> &z)
    {
      return (exp(I_*z) + exp(-I_*z))/((Type) 2);
    }
    
    /*!
      \brief Returns the complex tangent of the complex number.
    */
    friend CUDA_HOS_DEV inline comp<Type> tan(const comp<Type> &z)
    {
      return (exp(I_*z) - exp(-I_*z))/(I_*(exp(I_*z) + exp(-I_*z)));
    }
    
    friend CUDA_HOS_DEV inline Type fabs(const comp<Type> &z)
    {
      return z.rho;
    }
    
    friend CUDA_HOS_DEV inline Type abs(const comp<Type> &z)
    {
      return z.rho;
    }
    
    /*!
      \brief Reads a complex number in its cartesian form.
    */
    template <class stream>
    friend stream& operator>> (stream &s, comp<Type> &z)
    {
      s >> z.re;
      s >> z.im;
      z.update_polar();
      return s;
    }
    
    /*!
      \brief Writes a complex number in its cartesian form.
    */
    friend std::ostream& operator<< (std::ostream &s, const comp<Type> &z)
    {
      s << z.re << " " << z.im;
      return s;
    }
    
    /*!
      \brief Prints a complex number.
      
      \details If \p pol is false, it prints in the cartesian form.
               If \p pol is true, it prints in the polar form, as a fraction of pi if \p reduc is true,
               else as number in `]-pi, pi]`.
    */
    template <class stream>
    friend void print_comp(stream &s, const comp<Type> &z, const bool pol = false, const bool reduc = false)
    {
      if (!pol)
        {
          s << z.re;
          if (sign(z.im) < 0)
            {
              s << " - " << fabs(z.im) << " i";
            }
          else if (sign(z.im) > 0)
            {
              s << " + " << fabs(z.im) << " i";
            }
        }
      else
        {
          s << z.rho << " cis ";
          if (reduc)
            {
              s << z.theta;
            }
          else
            {
              s << z.theta*g24_lib::pi<Type>;
            }
        }
    }
  private:
  
    /*!
      \brief Parses a complex from a stream. If \p reduc is true,
             if the complex appears to be in the polar form,
             the argument is read as a fraction of pi.
             
      \details The possible inputs are:
        `a + i b`, `a - i b`, `a + b i`, `a - bi`,
        `b i + a`, `b i`, a, `rho cis theta`, `rho pol theta`,
        ignoring whitespace and capitalization
        in what regards to the plus or minus signs and the imaginary unit.
    */
    template <class stream>
    void parse_comp(stream &s, const bool reduc = false)
    {
      double temp1;
      //Double so it understands non-integer numbers...
      char u;
      s >> temp1;
      u = s.peek();
      if(u == '\n' || u == '\0' || s.eof())
        {
          re = (Type) temp1;
          im = (Type) 0;
          rho = (Type) ::fabs(temp1);
          theta = (Type) 0.5 - 0.5*sign(temp1);
          return;
        }
      s >> std::ws;
      u = s.peek();
      if(u == '+')
        {
          s >> u >> std::ws;
          re = (Type) temp1;
          u = s.peek();
          if(u == 'i' || u == 'I')
            {
              s >> u >> temp1;
              im = (Type) temp1;
              update_polar();
            }
          else if (std::isdigit(u))
            {
              s >> temp1;
              u = s.peek();
              im = (Type) temp1;
              update_polar();
              if(u != 'i' && u != 'I')
                {
                  s.setstate(std::ios::failbit);
                }
            }
        }
      else if(u == '-')
        {
          re = temp1;
          s >> u >> std::ws;
          u = s.peek();
          if(u == 'i' || u == 'I')
            {
              s >> u >> temp1;
              im = - (Type) temp1;
              update_polar();
              return;
            }
          else if (std::isdigit(u))
            {
              s >> temp1;
              u = s.peek();
              im = (Type) -temp1;
              update_polar();
              if(u != 'i' || u != 'I')
                {
                  s.setstate(std::ios::failbit);
                }
            }
        }
      else if(u == 'c' || u == 'C')
        //Using a string would perhaps be more compact,
        //but this allows for whitespace to be ignored.
        {
          s >> u >> u;
          if(u == 'i' || u == 'I')
            {
              s >> u;
              if(u == 's' || u == 'S')
                {
                  rho = (Type) ::fabs(temp1);
                  if(temp1 < 0)
                    {
                      theta = (Type) 1;
                    }
                  else
                    {
                      theta = (Type) 0;
                    }
                  s >> temp1;
                  if(!reduc)
                    {
                      temp1 = (Type) temp1/g24_lib::pi<Type>;
                    }
                  theta = stand(theta + temp1);
                  update_cart();
                }
            }
        }
      else if(u == 'p' || u == 'P')
        {
          s >> u >> u;
          if(u == 'o' || u == 'O')
            {
              s >> u;
              if(u == 'l' || u == 'L')
                {
                  rho = (Type) ::fabs(temp1);
                  if(temp1 < 0)
                    {
                      theta = (Type) 1;
                    }
                  else
                    {
                      theta = (Type) 0;
                    }
                  s >> temp1;
                  if(!reduc)
                    {
                      temp1 = (Type) temp1/g24_lib::pi<Type>;
                    }
                  theta = stand(rho + temp1);
                  update_cart();
                }
            }
        }
      else if(u == 'i' || u == 'I')
        {
          im = (Type) temp1;
          s >> u;
          u = s.peek();
          if(u == '\n' || u == '\0' || s.eof())
            {
              re = (Type) 0;
              rho = (Type) fabs(im);
              theta = 0.5*sign(im);
              return;
            }
          s >> std::ws;
          u = s.peek();
          if(u == '-')
            {
              s >> u >> temp1;
              re = (Type) -temp1;
            }
          else if(u == '+')
            {
              s >> u >> temp1;
              re = (Type) temp1;
            }
          update_polar();
        }
      else
        {
          s.setstate(std::ios::failbit);
        }
    }
    
  public:
    
    CUDA_HOS_DEV ~comp()
    {
      return;
    }
    
    template <class Tp> friend comp read_comp(std::istream &s, const bool reduc);
    template <class Tp> friend comp read_comp(std::istream &s, comp<Type> &c, const bool reduc);
    template <class Tp> friend comp ask_comp(const bool reduc);
    template <class Tp> friend comp fast_read_comp(std::istream &s, const bool pol, const bool reduc);
    template <class Tp> friend comp fast_read_comp(std::istream &s, comp<Type> &c, const bool pol, const bool reduc);
  };
  
  // template <class Type> comp<Type> comp<Type>::I_((Type) 0, (Type) 1, (Type) 1, (Type) 0.5);
  
  
  /*!
    \brief Returns a g24_lib::comp read from a stream. If \p reduc is true,
           if the complex appears to be in the polar form,
           the argument is read as a fraction of pi.
           
    \details The possible inputs are:
      `a + i b`, `a - i b`, `a + b i`, `a - bi`,
      `b i + a`, `b i`, a, `rho cis theta`, `rho pol theta`,
      ignoring whitespace and capitalization
      in what regards to the plus or minus signs and the imaginary unit.
      
    \remark Since the standard library already implements `std::complex`,
             `g24_lib::comp` might be more than a bit superfluous unless \c CUDA
             interoperatability is significant...
  */
  template <class Type> comp<Type> read_comp(std::istream &s, const bool reduc)
  {
    comp<Type> temp;
    temp.parse_comp(s, reduc);
    return temp;
  }
  
    /*!
      \brief Updates a g24_lib::comp from values read from a stream. If \p reduc is true,
             if the complex appears to be in the polar form,
             the argument is read as a fraction of pi.
             
      \details The possible inputs are:
        `a + i b`, `a - i b`, `a + b i`, `a - bi`,
        `b i + a`, `b i`, a, `rho cis theta`, `rho pol theta`,
        ignoring whitespace and capitalization
        in what regards to the plus or minus signs and the imaginary unit.
        
    \remark Since the standard library already implements `std::complex`,
             `g24_lib::comp` might be more than a bit superfluous unless \c CUDA
             interoperatability is significant...
    */
  template <class Type> comp<Type> read_comp(std::istream &s, comp<Type> &c, const bool reduc)
  {
    c.parse_comp(s, reduc);
    return c;
  }
  
    /*!
      \brief Asks the user for a g24_lib::comp number and returns it. If \p reduc is true,
             if the complex appears to be in the polar form,
             the argument is read as a fraction of pi.
             
      \details The possible inputs are:
        `a + i b`, `a - i b`, `a + b i`, `a - bi`,
        `b i + a`, `b i`, a, `rho cis theta`, `rho pol theta`,
        ignoring whitespace and capitalization
        in what regards to the plus or minus signs and the imaginary unit.
        
    \remark Since the standard library already implements `std::complex`,
             `g24_lib::comp` might be more than a bit superfluous unless \c CUDA
             interoperatability is significant...
    */
  template <class Type> comp<Type> ask_comp(const bool reduc)
  {
    comp<Type> temp;
    std::cout << "Please, enter a complex number. " << std::flush;
    read_comp(std::cin, temp, reduc);
    return temp;
  }
  
    /*!
      \brief Returns a g24_lib::comp read from a stream. If \p pol is false, in cartesian form; if \p pol is true,
             in polar form, with the argument being as a fraction of pi if \p reduc is true
             or as a number in `]-pi, pi]` if \p recuc is false.
             
    \remark Since the standard library already implements `std::complex`,
             `g24_lib::comp` might be more than a bit superfluous unless \c CUDA
             interoperatability is significant...
    */
  template <class Type> comp<Type> fast_read_comp(std::istream &s, const bool pol, const bool reduc)
  {
    Type temp1, temp2;
    s >> temp1 >> temp2;
    if (reduc)
      {
        return (comp<Type>) (temp1, g24_lib::pi<Type>*temp2, pol);
      }
    return (comp<Type>) (temp1, temp2, pol);
  }
  
  /*!
    \brief Updates a g24_lib::comp from a stream. If \p pol is false, in cartesian form; if \p pol is true,
           in polar form, with the argument being as a fraction of pi if \p reduc is true
           or as a number in `]-pi, pi]` if \p recuc is false.
           
    \remark Since the standard library already implements `std::complex`,
             `g24_lib::comp` might be more than a bit superfluous unless \c CUDA
             interoperatability is significant...
  */
  template <class Type> comp<Type> fast_read_comp(std::istream &s, comp<Type> &c, const bool pol, const bool reduc)
  {
    if (pol)
      {
        s >> c.rho >> c.theta;
        c.theta = stand((reduc ? c.theta : c.theta/g24_lib::pi<Type>));
        c.update_cart();
      }
    else
      {
        s >> c.re >> c.im;
        c.update_polar();
      }
    return c;
  }
  
}

#endif
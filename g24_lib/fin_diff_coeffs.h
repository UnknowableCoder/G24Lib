#ifndef G24_LIB_FIN_DIFF_COEFFS
#define G24_LIB_FIN_DIFF_COEFFS

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

\file fin_diff_coeffs.h

\brief Defines the finite difference coefficients for several combinations
       of derivative order, number of points and position of the point in which
       the derivative is to be evaluated.
         
\remark Most of the file is automatically generated using a Mathematica script.

\warning Currently, the library only supports derivatives of order up to (and including) 6
         and a number of points up to (and including) `order + 7`.

\author Nuno Fernandes (main coder, current maintainer)

*/

namespace g24_lib
{

namespace internals
{

/*!
  \brief Defines the finite difference coefficients for a given derivative.
  
  \tparam indexer A type that is appropriate to hold the offsets.
  
  \tparam factor_type A type that is appropriate to hold the coefficients.
  
  \tparam order The order of the derivative.
  
  \tparam npoints The number of points that will be used to calculate the derivative
  
  \pre \p indexer must satisfy the constraints placed on the choice of \ref g24_lib::Definitions::default_unsigned_indexer.
  
  \pre \p factor_type must support multiplications and divisions with itself
       (and with the elements of the array whose derivatives will be evaluated).
       It does not need to be a floating point type since the coefficients
       are stored essentially as rational numbers.
       
  \warning Currently, the library only gives correct results for values of \p order up to (and including) 6.
  
  \warning, the library only gives correct results for values of \p npoints up to (and including) `order + 7`.
  
  \remark The accuracy of the derivative will be given by `npoints - order`.
*/
template<class indexer, class factor_type,
g24_lib::Definitions::default_unsigned_indexer order,
g24_lib::Definitions::default_unsigned_indexer npoints>
struct fin_diff_coeffs
{
  /*!
    \brief Returns `true` if the library provides values for this combination of \p order and \p npoints.
  */
  CUDA_HOS_DEV static constexpr bool valid()
  {
    return false;
  }
  /*!
    \brief Returns the numerator of the coefficient to use for the `i`-th point starting from the left.
  
    \param i The index of the point under consideration.
  
    \param offset The offset from the leftmost point at which the derivative is being evaluated.
  
    \remark For instance, if the derivative would be calculated with 7 points
            and be evaluated at the central point, \p offset would be 3.
  
  */
  CUDA_HOS_DEV static constexpr factor_type coeffs(const indexer i, const indexer offset)
  {
    return factor_type(0);
  }
  /*!
    \brief Returns the denominator of the coefficients (it is independent of the point under consideration).
  */
  CUDA_HOS_DEV static constexpr factor_type factor()
  {
    return factor_type(1);
  }
};

/*!
  \brief The maximum accuracy of the derivatives provided by the library.
*/
static constexpr g24_lib::Definitions::default_unsigned_indexer max_derivative_accuracy = 8;


/*!
  \brief The maximum order of the derivatives provided by the library.
*/
static constexpr g24_lib::Definitions::default_unsigned_indexer max_derivative_order = 6;

///\cond HIDDEN_SYMBOLS
template<class indexer, class factor_type> struct
fin_diff_coeffs <indexer, factor_type, 0, 0>
{
  CUDA_HOS_DEV static constexpr bool valid()
  {
    return false;
  }
  CUDA_HOS_DEV static constexpr factor_type coeffs(const indexer i)
  {
    return factor_type(0);
  }
  CUDA_HOS_DEV static constexpr factor_type factor()
  {
    return factor_type(1);
  }
};

//Automatically generated from here on.
template<class indexer, class factor_type> struct
fin_diff_coeffs <indexer, factor_type, 1, 2>
{
  CUDA_HOS_DEV static constexpr bool valid()
  {
    return true;
  }
  CUDA_HOS_DEV static constexpr factor_type coeffs(const indexer i, const indexer offset = 0)
  {
    switch(offset)
    {
     default:
       return factor_type(0);
     case 0:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-1);
       case 1:
        return factor_type(1);
      }
     };
     case 1:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-1);
       case 1:
        return factor_type(1);
      }
     };
    }
  }
  CUDA_HOS_DEV static constexpr factor_type factor()
  {
    return factor_type(1);
  }
};

template<class indexer, class factor_type> struct
fin_diff_coeffs <indexer, factor_type, 1, 3>
{
  CUDA_HOS_DEV static constexpr bool valid()
  {
    return true;
  }
  CUDA_HOS_DEV static constexpr factor_type coeffs(const indexer i, const indexer offset = 0)
  {
    switch(offset)
    {
     default:
       return factor_type(0);
     case 0:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-3);
       case 1:
        return factor_type(4);
       case 2:
        return factor_type(-1);
      }
     };
     case 1:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-1);
       case 1:
        return factor_type(0);
       case 2:
        return factor_type(1);
      }
     };
     case 2:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(1);
       case 1:
        return factor_type(-4);
       case 2:
        return factor_type(3);
      }
     };
    }
  }
  CUDA_HOS_DEV static constexpr factor_type factor()
  {
    return factor_type(2);
  }
};

template<class indexer, class factor_type> struct
fin_diff_coeffs <indexer, factor_type, 1, 4>
{
  CUDA_HOS_DEV static constexpr bool valid()
  {
    return true;
  }
  CUDA_HOS_DEV static constexpr factor_type coeffs(const indexer i, const indexer offset = 0)
  {
    switch(offset)
    {
     default:
       return factor_type(0);
     case 0:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-11);
       case 1:
        return factor_type(18);
       case 2:
        return factor_type(-9);
       case 3:
        return factor_type(2);
      }
     };
     case 1:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-2);
       case 1:
        return factor_type(-3);
       case 2:
        return factor_type(6);
       case 3:
        return factor_type(-1);
      }
     };
     case 2:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(1);
       case 1:
        return factor_type(-6);
       case 2:
        return factor_type(3);
       case 3:
        return factor_type(2);
      }
     };
     case 3:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-2);
       case 1:
        return factor_type(9);
       case 2:
        return factor_type(-18);
       case 3:
        return factor_type(11);
      }
     };
    }
  }
  CUDA_HOS_DEV static constexpr factor_type factor()
  {
    return factor_type(6);
  }
};

template<class indexer, class factor_type> struct
fin_diff_coeffs <indexer, factor_type, 1, 5>
{
  CUDA_HOS_DEV static constexpr bool valid()
  {
    return true;
  }
  CUDA_HOS_DEV static constexpr factor_type coeffs(const indexer i, const indexer offset = 0)
  {
    switch(offset)
    {
     default:
       return factor_type(0);
     case 0:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-25);
       case 1:
        return factor_type(48);
       case 2:
        return factor_type(-36);
       case 3:
        return factor_type(16);
       case 4:
        return factor_type(-3);
      }
     };
     case 1:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-3);
       case 1:
        return factor_type(-10);
       case 2:
        return factor_type(18);
       case 3:
        return factor_type(-6);
       case 4:
        return factor_type(1);
      }
     };
     case 2:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(1);
       case 1:
        return factor_type(-8);
       case 2:
        return factor_type(0);
       case 3:
        return factor_type(8);
       case 4:
        return factor_type(-1);
      }
     };
     case 3:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-1);
       case 1:
        return factor_type(6);
       case 2:
        return factor_type(-18);
       case 3:
        return factor_type(10);
       case 4:
        return factor_type(3);
      }
     };
     case 4:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(3);
       case 1:
        return factor_type(-16);
       case 2:
        return factor_type(36);
       case 3:
        return factor_type(-48);
       case 4:
        return factor_type(25);
      }
     };
    }
  }
  CUDA_HOS_DEV static constexpr factor_type factor()
  {
    return factor_type(12);
  }
};

template<class indexer, class factor_type> struct
fin_diff_coeffs <indexer, factor_type, 1, 6>
{
  CUDA_HOS_DEV static constexpr bool valid()
  {
    return true;
  }
  CUDA_HOS_DEV static constexpr factor_type coeffs(const indexer i, const indexer offset = 0)
  {
    switch(offset)
    {
     default:
       return factor_type(0);
     case 0:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-137);
       case 1:
        return factor_type(300);
       case 2:
        return factor_type(-300);
       case 3:
        return factor_type(200);
       case 4:
        return factor_type(-75);
       case 5:
        return factor_type(12);
      }
     };
     case 1:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-12);
       case 1:
        return factor_type(-65);
       case 2:
        return factor_type(120);
       case 3:
        return factor_type(-60);
       case 4:
        return factor_type(20);
       case 5:
        return factor_type(-3);
      }
     };
     case 2:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(3);
       case 1:
        return factor_type(-30);
       case 2:
        return factor_type(-20);
       case 3:
        return factor_type(60);
       case 4:
        return factor_type(-15);
       case 5:
        return factor_type(2);
      }
     };
     case 3:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-2);
       case 1:
        return factor_type(15);
       case 2:
        return factor_type(-60);
       case 3:
        return factor_type(20);
       case 4:
        return factor_type(30);
       case 5:
        return factor_type(-3);
      }
     };
     case 4:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(3);
       case 1:
        return factor_type(-20);
       case 2:
        return factor_type(60);
       case 3:
        return factor_type(-120);
       case 4:
        return factor_type(65);
       case 5:
        return factor_type(12);
      }
     };
     case 5:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-12);
       case 1:
        return factor_type(75);
       case 2:
        return factor_type(-200);
       case 3:
        return factor_type(300);
       case 4:
        return factor_type(-300);
       case 5:
        return factor_type(137);
      }
     };
    }
  }
  CUDA_HOS_DEV static constexpr factor_type factor()
  {
    return factor_type(60);
  }
};

template<class indexer, class factor_type> struct
fin_diff_coeffs <indexer, factor_type, 1, 7>
{
  CUDA_HOS_DEV static constexpr bool valid()
  {
    return true;
  }
  CUDA_HOS_DEV static constexpr factor_type coeffs(const indexer i, const indexer offset = 0)
  {
    switch(offset)
    {
     default:
       return factor_type(0);
     case 0:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-147);
       case 1:
        return factor_type(360);
       case 2:
        return factor_type(-450);
       case 3:
        return factor_type(400);
       case 4:
        return factor_type(-225);
       case 5:
        return factor_type(72);
       case 6:
        return factor_type(-10);
      }
     };
     case 1:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-10);
       case 1:
        return factor_type(-77);
       case 2:
        return factor_type(150);
       case 3:
        return factor_type(-100);
       case 4:
        return factor_type(50);
       case 5:
        return factor_type(-15);
       case 6:
        return factor_type(2);
      }
     };
     case 2:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(2);
       case 1:
        return factor_type(-24);
       case 2:
        return factor_type(-35);
       case 3:
        return factor_type(80);
       case 4:
        return factor_type(-30);
       case 5:
        return factor_type(8);
       case 6:
        return factor_type(-1);
      }
     };
     case 3:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-1);
       case 1:
        return factor_type(9);
       case 2:
        return factor_type(-45);
       case 3:
        return factor_type(0);
       case 4:
        return factor_type(45);
       case 5:
        return factor_type(-9);
       case 6:
        return factor_type(1);
      }
     };
     case 4:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(1);
       case 1:
        return factor_type(-8);
       case 2:
        return factor_type(30);
       case 3:
        return factor_type(-80);
       case 4:
        return factor_type(35);
       case 5:
        return factor_type(24);
       case 6:
        return factor_type(-2);
      }
     };
     case 5:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-2);
       case 1:
        return factor_type(15);
       case 2:
        return factor_type(-50);
       case 3:
        return factor_type(100);
       case 4:
        return factor_type(-150);
       case 5:
        return factor_type(77);
       case 6:
        return factor_type(10);
      }
     };
     case 6:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(10);
       case 1:
        return factor_type(-72);
       case 2:
        return factor_type(225);
       case 3:
        return factor_type(-400);
       case 4:
        return factor_type(450);
       case 5:
        return factor_type(-360);
       case 6:
        return factor_type(147);
      }
     };
    }
  }
  CUDA_HOS_DEV static constexpr factor_type factor()
  {
    return factor_type(60);
  }
};

template<class indexer, class factor_type> struct
fin_diff_coeffs <indexer, factor_type, 1, 8>
{
  CUDA_HOS_DEV static constexpr bool valid()
  {
    return true;
  }
  CUDA_HOS_DEV static constexpr factor_type coeffs(const indexer i, const indexer offset = 0)
  {
    switch(offset)
    {
     default:
       return factor_type(0);
     case 0:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-1089);
       case 1:
        return factor_type(2940);
       case 2:
        return factor_type(-4410);
       case 3:
        return factor_type(4900);
       case 4:
        return factor_type(-3675);
       case 5:
        return factor_type(1764);
       case 6:
        return factor_type(-490);
       case 7:
        return factor_type(60);
      }
     };
     case 1:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-60);
       case 1:
        return factor_type(-609);
       case 2:
        return factor_type(1260);
       case 3:
        return factor_type(-1050);
       case 4:
        return factor_type(700);
       case 5:
        return factor_type(-315);
       case 6:
        return factor_type(84);
       case 7:
        return factor_type(-10);
      }
     };
     case 2:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(10);
       case 1:
        return factor_type(-140);
       case 2:
        return factor_type(-329);
       case 3:
        return factor_type(700);
       case 4:
        return factor_type(-350);
       case 5:
        return factor_type(140);
       case 6:
        return factor_type(-35);
       case 7:
        return factor_type(4);
      }
     };
     case 3:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-4);
       case 1:
        return factor_type(42);
       case 2:
        return factor_type(-252);
       case 3:
        return factor_type(-105);
       case 4:
        return factor_type(420);
       case 5:
        return factor_type(-126);
       case 6:
        return factor_type(28);
       case 7:
        return factor_type(-3);
      }
     };
     case 4:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(3);
       case 1:
        return factor_type(-28);
       case 2:
        return factor_type(126);
       case 3:
        return factor_type(-420);
       case 4:
        return factor_type(105);
       case 5:
        return factor_type(252);
       case 6:
        return factor_type(-42);
       case 7:
        return factor_type(4);
      }
     };
     case 5:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-4);
       case 1:
        return factor_type(35);
       case 2:
        return factor_type(-140);
       case 3:
        return factor_type(350);
       case 4:
        return factor_type(-700);
       case 5:
        return factor_type(329);
       case 6:
        return factor_type(140);
       case 7:
        return factor_type(-10);
      }
     };
     case 6:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(10);
       case 1:
        return factor_type(-84);
       case 2:
        return factor_type(315);
       case 3:
        return factor_type(-700);
       case 4:
        return factor_type(1050);
       case 5:
        return factor_type(-1260);
       case 6:
        return factor_type(609);
       case 7:
        return factor_type(60);
      }
     };
     case 7:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-60);
       case 1:
        return factor_type(490);
       case 2:
        return factor_type(-1764);
       case 3:
        return factor_type(3675);
       case 4:
        return factor_type(-4900);
       case 5:
        return factor_type(4410);
       case 6:
        return factor_type(-2940);
       case 7:
        return factor_type(1089);
      }
     };
    }
  }
  CUDA_HOS_DEV static constexpr factor_type factor()
  {
    return factor_type(420);
  }
};

template<class indexer, class factor_type> struct
fin_diff_coeffs <indexer, factor_type, 1, 9>
{
  CUDA_HOS_DEV static constexpr bool valid()
  {
    return true;
  }
  CUDA_HOS_DEV static constexpr factor_type coeffs(const indexer i, const indexer offset = 0)
  {
    switch(offset)
    {
     default:
       return factor_type(0);
     case 0:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-2283);
       case 1:
        return factor_type(6720);
       case 2:
        return factor_type(-11760);
       case 3:
        return factor_type(15680);
       case 4:
        return factor_type(-14700);
       case 5:
        return factor_type(9408);
       case 6:
        return factor_type(-3920);
       case 7:
        return factor_type(960);
       case 8:
        return factor_type(-105);
      }
     };
     case 1:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-105);
       case 1:
        return factor_type(-1338);
       case 2:
        return factor_type(2940);
       case 3:
        return factor_type(-2940);
       case 4:
        return factor_type(2450);
       case 5:
        return factor_type(-1470);
       case 6:
        return factor_type(588);
       case 7:
        return factor_type(-140);
       case 8:
        return factor_type(15);
      }
     };
     case 2:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(15);
       case 1:
        return factor_type(-240);
       case 2:
        return factor_type(-798);
       case 3:
        return factor_type(1680);
       case 4:
        return factor_type(-1050);
       case 5:
        return factor_type(560);
       case 6:
        return factor_type(-210);
       case 7:
        return factor_type(48);
       case 8:
        return factor_type(-5);
      }
     };
     case 3:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-5);
       case 1:
        return factor_type(60);
       case 2:
        return factor_type(-420);
       case 3:
        return factor_type(-378);
       case 4:
        return factor_type(1050);
       case 5:
        return factor_type(-420);
       case 6:
        return factor_type(140);
       case 7:
        return factor_type(-30);
       case 8:
        return factor_type(3);
      }
     };
     case 4:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(3);
       case 1:
        return factor_type(-32);
       case 2:
        return factor_type(168);
       case 3:
        return factor_type(-672);
       case 4:
        return factor_type(0);
       case 5:
        return factor_type(672);
       case 6:
        return factor_type(-168);
       case 7:
        return factor_type(32);
       case 8:
        return factor_type(-3);
      }
     };
     case 5:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-3);
       case 1:
        return factor_type(30);
       case 2:
        return factor_type(-140);
       case 3:
        return factor_type(420);
       case 4:
        return factor_type(-1050);
       case 5:
        return factor_type(378);
       case 6:
        return factor_type(420);
       case 7:
        return factor_type(-60);
       case 8:
        return factor_type(5);
      }
     };
     case 6:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(5);
       case 1:
        return factor_type(-48);
       case 2:
        return factor_type(210);
       case 3:
        return factor_type(-560);
       case 4:
        return factor_type(1050);
       case 5:
        return factor_type(-1680);
       case 6:
        return factor_type(798);
       case 7:
        return factor_type(240);
       case 8:
        return factor_type(-15);
      }
     };
     case 7:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-15);
       case 1:
        return factor_type(140);
       case 2:
        return factor_type(-588);
       case 3:
        return factor_type(1470);
       case 4:
        return factor_type(-2450);
       case 5:
        return factor_type(2940);
       case 6:
        return factor_type(-2940);
       case 7:
        return factor_type(1338);
       case 8:
        return factor_type(105);
      }
     };
     case 8:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(105);
       case 1:
        return factor_type(-960);
       case 2:
        return factor_type(3920);
       case 3:
        return factor_type(-9408);
       case 4:
        return factor_type(14700);
       case 5:
        return factor_type(-15680);
       case 6:
        return factor_type(11760);
       case 7:
        return factor_type(-6720);
       case 8:
        return factor_type(2283);
      }
     };
    }
  }
  CUDA_HOS_DEV static constexpr factor_type factor()
  {
    return factor_type(840);
  }
};

template<class indexer, class factor_type> struct
fin_diff_coeffs <indexer, factor_type, 2, 3>
{
  CUDA_HOS_DEV static constexpr bool valid()
  {
    return true;
  }
  CUDA_HOS_DEV static constexpr factor_type coeffs(const indexer i, const indexer offset = 0)
  {
    switch(offset)
    {
     default:
       return factor_type(0);
     case 0:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(1);
       case 1:
        return factor_type(-2);
       case 2:
        return factor_type(1);
      }
     };
     case 1:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(1);
       case 1:
        return factor_type(-2);
       case 2:
        return factor_type(1);
      }
     };
     case 2:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(1);
       case 1:
        return factor_type(-2);
       case 2:
        return factor_type(1);
      }
     };
    }
  }
  CUDA_HOS_DEV static constexpr factor_type factor()
  {
    return factor_type(1);
  }
};

template<class indexer, class factor_type> struct
fin_diff_coeffs <indexer, factor_type, 2, 4>
{
  CUDA_HOS_DEV static constexpr bool valid()
  {
    return true;
  }
  CUDA_HOS_DEV static constexpr factor_type coeffs(const indexer i, const indexer offset = 0)
  {
    switch(offset)
    {
     default:
       return factor_type(0);
     case 0:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(2);
       case 1:
        return factor_type(-5);
       case 2:
        return factor_type(4);
       case 3:
        return factor_type(-1);
      }
     };
     case 1:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(1);
       case 1:
        return factor_type(-2);
       case 2:
        return factor_type(1);
      }
     };
     case 2:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(0);
       case 1:
        return factor_type(1);
       case 2:
        return factor_type(-2);
       case 3:
        return factor_type(1);
      }
     };
     case 3:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-1);
       case 1:
        return factor_type(4);
       case 2:
        return factor_type(-5);
       case 3:
        return factor_type(2);
      }
     };
    }
  }
  CUDA_HOS_DEV static constexpr factor_type factor()
  {
    return factor_type(1);
  }
};

template<class indexer, class factor_type> struct
fin_diff_coeffs <indexer, factor_type, 2, 5>
{
  CUDA_HOS_DEV static constexpr bool valid()
  {
    return true;
  }
  CUDA_HOS_DEV static constexpr factor_type coeffs(const indexer i, const indexer offset = 0)
  {
    switch(offset)
    {
     default:
       return factor_type(0);
     case 0:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(35);
       case 1:
        return factor_type(-104);
       case 2:
        return factor_type(114);
       case 3:
        return factor_type(-56);
       case 4:
        return factor_type(11);
      }
     };
     case 1:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(11);
       case 1:
        return factor_type(-20);
       case 2:
        return factor_type(6);
       case 3:
        return factor_type(4);
       case 4:
        return factor_type(-1);
      }
     };
     case 2:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-1);
       case 1:
        return factor_type(16);
       case 2:
        return factor_type(-30);
       case 3:
        return factor_type(16);
       case 4:
        return factor_type(-1);
      }
     };
     case 3:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-1);
       case 1:
        return factor_type(4);
       case 2:
        return factor_type(6);
       case 3:
        return factor_type(-20);
       case 4:
        return factor_type(11);
      }
     };
     case 4:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(11);
       case 1:
        return factor_type(-56);
       case 2:
        return factor_type(114);
       case 3:
        return factor_type(-104);
       case 4:
        return factor_type(35);
      }
     };
    }
  }
  CUDA_HOS_DEV static constexpr factor_type factor()
  {
    return factor_type(12);
  }
};

template<class indexer, class factor_type> struct
fin_diff_coeffs <indexer, factor_type, 2, 6>
{
  CUDA_HOS_DEV static constexpr bool valid()
  {
    return true;
  }
  CUDA_HOS_DEV static constexpr factor_type coeffs(const indexer i, const indexer offset = 0)
  {
    switch(offset)
    {
     default:
       return factor_type(0);
     case 0:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(45);
       case 1:
        return factor_type(-154);
       case 2:
        return factor_type(214);
       case 3:
        return factor_type(-156);
       case 4:
        return factor_type(61);
       case 5:
        return factor_type(-10);
      }
     };
     case 1:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(10);
       case 1:
        return factor_type(-15);
       case 2:
        return factor_type(-4);
       case 3:
        return factor_type(14);
       case 4:
        return factor_type(-6);
       case 5:
        return factor_type(1);
      }
     };
     case 2:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-1);
       case 1:
        return factor_type(16);
       case 2:
        return factor_type(-30);
       case 3:
        return factor_type(16);
       case 4:
        return factor_type(-1);
      }
     };
     case 3:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(0);
       case 1:
        return factor_type(-1);
       case 2:
        return factor_type(16);
       case 3:
        return factor_type(-30);
       case 4:
        return factor_type(16);
       case 5:
        return factor_type(-1);
      }
     };
     case 4:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(1);
       case 1:
        return factor_type(-6);
       case 2:
        return factor_type(14);
       case 3:
        return factor_type(-4);
       case 4:
        return factor_type(-15);
       case 5:
        return factor_type(10);
      }
     };
     case 5:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-10);
       case 1:
        return factor_type(61);
       case 2:
        return factor_type(-156);
       case 3:
        return factor_type(214);
       case 4:
        return factor_type(-154);
       case 5:
        return factor_type(45);
      }
     };
    }
  }
  CUDA_HOS_DEV static constexpr factor_type factor()
  {
    return factor_type(12);
  }
};

template<class indexer, class factor_type> struct
fin_diff_coeffs <indexer, factor_type, 2, 7>
{
  CUDA_HOS_DEV static constexpr bool valid()
  {
    return true;
  }
  CUDA_HOS_DEV static constexpr factor_type coeffs(const indexer i, const indexer offset = 0)
  {
    switch(offset)
    {
     default:
       return factor_type(0);
     case 0:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(812);
       case 1:
        return factor_type(-3132);
       case 2:
        return factor_type(5265);
       case 3:
        return factor_type(-5080);
       case 4:
        return factor_type(2970);
       case 5:
        return factor_type(-972);
       case 6:
        return factor_type(137);
      }
     };
     case 1:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(137);
       case 1:
        return factor_type(-147);
       case 2:
        return factor_type(-255);
       case 3:
        return factor_type(470);
       case 4:
        return factor_type(-285);
       case 5:
        return factor_type(93);
       case 6:
        return factor_type(-13);
      }
     };
     case 2:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-13);
       case 1:
        return factor_type(228);
       case 2:
        return factor_type(-420);
       case 3:
        return factor_type(200);
       case 4:
        return factor_type(15);
       case 5:
        return factor_type(-12);
       case 6:
        return factor_type(2);
      }
     };
     case 3:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(2);
       case 1:
        return factor_type(-27);
       case 2:
        return factor_type(270);
       case 3:
        return factor_type(-490);
       case 4:
        return factor_type(270);
       case 5:
        return factor_type(-27);
       case 6:
        return factor_type(2);
      }
     };
     case 4:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(2);
       case 1:
        return factor_type(-12);
       case 2:
        return factor_type(15);
       case 3:
        return factor_type(200);
       case 4:
        return factor_type(-420);
       case 5:
        return factor_type(228);
       case 6:
        return factor_type(-13);
      }
     };
     case 5:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-13);
       case 1:
        return factor_type(93);
       case 2:
        return factor_type(-285);
       case 3:
        return factor_type(470);
       case 4:
        return factor_type(-255);
       case 5:
        return factor_type(-147);
       case 6:
        return factor_type(137);
      }
     };
     case 6:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(137);
       case 1:
        return factor_type(-972);
       case 2:
        return factor_type(2970);
       case 3:
        return factor_type(-5080);
       case 4:
        return factor_type(5265);
       case 5:
        return factor_type(-3132);
       case 6:
        return factor_type(812);
      }
     };
    }
  }
  CUDA_HOS_DEV static constexpr factor_type factor()
  {
    return factor_type(180);
  }
};

template<class indexer, class factor_type> struct
fin_diff_coeffs <indexer, factor_type, 2, 8>
{
  CUDA_HOS_DEV static constexpr bool valid()
  {
    return true;
  }
  CUDA_HOS_DEV static constexpr factor_type coeffs(const indexer i, const indexer offset = 0)
  {
    switch(offset)
    {
     default:
       return factor_type(0);
     case 0:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(938);
       case 1:
        return factor_type(-4014);
       case 2:
        return factor_type(7911);
       case 3:
        return factor_type(-9490);
       case 4:
        return factor_type(7380);
       case 5:
        return factor_type(-3618);
       case 6:
        return factor_type(1019);
       case 7:
        return factor_type(-126);
      }
     };
     case 1:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(126);
       case 1:
        return factor_type(-70);
       case 2:
        return factor_type(-486);
       case 3:
        return factor_type(855);
       case 4:
        return factor_type(-670);
       case 5:
        return factor_type(324);
       case 6:
        return factor_type(-90);
       case 7:
        return factor_type(11);
      }
     };
     case 2:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-11);
       case 1:
        return factor_type(214);
       case 2:
        return factor_type(-378);
       case 3:
        return factor_type(130);
       case 4:
        return factor_type(85);
       case 5:
        return factor_type(-54);
       case 6:
        return factor_type(16);
       case 7:
        return factor_type(-2);
      }
     };
     case 3:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(2);
       case 1:
        return factor_type(-27);
       case 2:
        return factor_type(270);
       case 3:
        return factor_type(-490);
       case 4:
        return factor_type(270);
       case 5:
        return factor_type(-27);
       case 6:
        return factor_type(2);
      }
     };
     case 4:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(0);
       case 1:
        return factor_type(2);
       case 2:
        return factor_type(-27);
       case 3:
        return factor_type(270);
       case 4:
        return factor_type(-490);
       case 5:
        return factor_type(270);
       case 6:
        return factor_type(-27);
       case 7:
        return factor_type(2);
      }
     };
     case 5:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-2);
       case 1:
        return factor_type(16);
       case 2:
        return factor_type(-54);
       case 3:
        return factor_type(85);
       case 4:
        return factor_type(130);
       case 5:
        return factor_type(-378);
       case 6:
        return factor_type(214);
       case 7:
        return factor_type(-11);
      }
     };
     case 6:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(11);
       case 1:
        return factor_type(-90);
       case 2:
        return factor_type(324);
       case 3:
        return factor_type(-670);
       case 4:
        return factor_type(855);
       case 5:
        return factor_type(-486);
       case 6:
        return factor_type(-70);
       case 7:
        return factor_type(126);
      }
     };
     case 7:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-126);
       case 1:
        return factor_type(1019);
       case 2:
        return factor_type(-3618);
       case 3:
        return factor_type(7380);
       case 4:
        return factor_type(-9490);
       case 5:
        return factor_type(7911);
       case 6:
        return factor_type(-4014);
       case 7:
        return factor_type(938);
      }
     };
    }
  }
  CUDA_HOS_DEV static constexpr factor_type factor()
  {
    return factor_type(180);
  }
};

template<class indexer, class factor_type> struct
fin_diff_coeffs <indexer, factor_type, 2, 9>
{
  CUDA_HOS_DEV static constexpr bool valid()
  {
    return true;
  }
  CUDA_HOS_DEV static constexpr factor_type coeffs(const indexer i, const indexer offset = 0)
  {
    switch(offset)
    {
     default:
       return factor_type(0);
     case 0:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(29531);
       case 1:
        return factor_type(-138528);
       case 2:
        return factor_type(312984);
       case 3:
        return factor_type(-448672);
       case 4:
        return factor_type(435330);
       case 5:
        return factor_type(-284256);
       case 6:
        return factor_type(120008);
       case 7:
        return factor_type(-29664);
       case 8:
        return factor_type(3267);
      }
     };
     case 1:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(3267);
       case 1:
        return factor_type(128);
       case 2:
        return factor_type(-20916);
       case 3:
        return factor_type(38556);
       case 4:
        return factor_type(-37030);
       case 5:
        return factor_type(23688);
       case 6:
        return factor_type(-9828);
       case 7:
        return factor_type(2396);
       case 8:
        return factor_type(-261);
      }
     };
     case 2:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-261);
       case 1:
        return factor_type(5616);
       case 2:
        return factor_type(-9268);
       case 3:
        return factor_type(1008);
       case 4:
        return factor_type(5670);
       case 5:
        return factor_type(-4144);
       case 6:
        return factor_type(1764);
       case 7:
        return factor_type(-432);
       case 8:
        return factor_type(47);
      }
     };
     case 3:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(47);
       case 1:
        return factor_type(-684);
       case 2:
        return factor_type(7308);
       case 3:
        return factor_type(-13216);
       case 4:
        return factor_type(6930);
       case 5:
        return factor_type(-252);
       case 6:
        return factor_type(-196);
       case 7:
        return factor_type(72);
       case 8:
        return factor_type(-9);
      }
     };
     case 4:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-9);
       case 1:
        return factor_type(128);
       case 2:
        return factor_type(-1008);
       case 3:
        return factor_type(8064);
       case 4:
        return factor_type(-14350);
       case 5:
        return factor_type(8064);
       case 6:
        return factor_type(-1008);
       case 7:
        return factor_type(128);
       case 8:
        return factor_type(-9);
      }
     };
     case 5:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-9);
       case 1:
        return factor_type(72);
       case 2:
        return factor_type(-196);
       case 3:
        return factor_type(-252);
       case 4:
        return factor_type(6930);
       case 5:
        return factor_type(-13216);
       case 6:
        return factor_type(7308);
       case 7:
        return factor_type(-684);
       case 8:
        return factor_type(47);
      }
     };
     case 6:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(47);
       case 1:
        return factor_type(-432);
       case 2:
        return factor_type(1764);
       case 3:
        return factor_type(-4144);
       case 4:
        return factor_type(5670);
       case 5:
        return factor_type(1008);
       case 6:
        return factor_type(-9268);
       case 7:
        return factor_type(5616);
       case 8:
        return factor_type(-261);
      }
     };
     case 7:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-261);
       case 1:
        return factor_type(2396);
       case 2:
        return factor_type(-9828);
       case 3:
        return factor_type(23688);
       case 4:
        return factor_type(-37030);
       case 5:
        return factor_type(38556);
       case 6:
        return factor_type(-20916);
       case 7:
        return factor_type(128);
       case 8:
        return factor_type(3267);
      }
     };
     case 8:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(3267);
       case 1:
        return factor_type(-29664);
       case 2:
        return factor_type(120008);
       case 3:
        return factor_type(-284256);
       case 4:
        return factor_type(435330);
       case 5:
        return factor_type(-448672);
       case 6:
        return factor_type(312984);
       case 7:
        return factor_type(-138528);
       case 8:
        return factor_type(29531);
      }
     };
    }
  }
  CUDA_HOS_DEV static constexpr factor_type factor()
  {
    return factor_type(5040);
  }
};

template<class indexer, class factor_type> struct
fin_diff_coeffs <indexer, factor_type, 2, 10>
{
  CUDA_HOS_DEV static constexpr bool valid()
  {
    return true;
  }
  CUDA_HOS_DEV static constexpr factor_type coeffs(const indexer i, const indexer offset = 0)
  {
    switch(offset)
    {
     default:
       return factor_type(0);
     case 0:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(32575);
       case 1:
        return factor_type(-165924);
       case 2:
        return factor_type(422568);
       case 3:
        return factor_type(-704368);
       case 4:
        return factor_type(818874);
       case 5:
        return factor_type(-667800);
       case 6:
        return factor_type(375704);
       case 7:
        return factor_type(-139248);
       case 8:
        return factor_type(30663);
       case 9:
        return factor_type(-3044);
      }
     };
     case 1:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(3044);
       case 1:
        return factor_type(2135);
       case 2:
        return factor_type(-28944);
       case 3:
        return factor_type(57288);
       case 4:
        return factor_type(-65128);
       case 5:
        return factor_type(51786);
       case 6:
        return factor_type(-28560);
       case 7:
        return factor_type(10424);
       case 8:
        return factor_type(-2268);
       case 9:
        return factor_type(223);
      }
     };
     case 2:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-223);
       case 1:
        return factor_type(5274);
       case 2:
        return factor_type(-7900);
       case 3:
        return factor_type(-2184);
       case 4:
        return factor_type(10458);
       case 5:
        return factor_type(-8932);
       case 6:
        return factor_type(4956);
       case 7:
        return factor_type(-1800);
       case 8:
        return factor_type(389);
       case 9:
        return factor_type(-38);
      }
     };
     case 3:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(38);
       case 1:
        return factor_type(-603);
       case 2:
        return factor_type(6984);
       case 3:
        return factor_type(-12460);
       case 4:
        return factor_type(5796);
       case 5:
        return factor_type(882);
       case 6:
        return factor_type(-952);
       case 7:
        return factor_type(396);
       case 8:
        return factor_type(-90);
       case 9:
        return factor_type(9);
      }
     };
     case 4:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-9);
       case 1:
        return factor_type(128);
       case 2:
        return factor_type(-1008);
       case 3:
        return factor_type(8064);
       case 4:
        return factor_type(-14350);
       case 5:
        return factor_type(8064);
       case 6:
        return factor_type(-1008);
       case 7:
        return factor_type(128);
       case 8:
        return factor_type(-9);
      }
     };
     case 5:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(0);
       case 1:
        return factor_type(-9);
       case 2:
        return factor_type(128);
       case 3:
        return factor_type(-1008);
       case 4:
        return factor_type(8064);
       case 5:
        return factor_type(-14350);
       case 6:
        return factor_type(8064);
       case 7:
        return factor_type(-1008);
       case 8:
        return factor_type(128);
       case 9:
        return factor_type(-9);
      }
     };
     case 6:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(9);
       case 1:
        return factor_type(-90);
       case 2:
        return factor_type(396);
       case 3:
        return factor_type(-952);
       case 4:
        return factor_type(882);
       case 5:
        return factor_type(5796);
       case 6:
        return factor_type(-12460);
       case 7:
        return factor_type(6984);
       case 8:
        return factor_type(-603);
       case 9:
        return factor_type(38);
      }
     };
     case 7:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-38);
       case 1:
        return factor_type(389);
       case 2:
        return factor_type(-1800);
       case 3:
        return factor_type(4956);
       case 4:
        return factor_type(-8932);
       case 5:
        return factor_type(10458);
       case 6:
        return factor_type(-2184);
       case 7:
        return factor_type(-7900);
       case 8:
        return factor_type(5274);
       case 9:
        return factor_type(-223);
      }
     };
     case 8:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(223);
       case 1:
        return factor_type(-2268);
       case 2:
        return factor_type(10424);
       case 3:
        return factor_type(-28560);
       case 4:
        return factor_type(51786);
       case 5:
        return factor_type(-65128);
       case 6:
        return factor_type(57288);
       case 7:
        return factor_type(-28944);
       case 8:
        return factor_type(2135);
       case 9:
        return factor_type(3044);
      }
     };
     case 9:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-3044);
       case 1:
        return factor_type(30663);
       case 2:
        return factor_type(-139248);
       case 3:
        return factor_type(375704);
       case 4:
        return factor_type(-667800);
       case 5:
        return factor_type(818874);
       case 6:
        return factor_type(-704368);
       case 7:
        return factor_type(422568);
       case 8:
        return factor_type(-165924);
       case 9:
        return factor_type(32575);
      }
     };
    }
  }
  CUDA_HOS_DEV static constexpr factor_type factor()
  {
    return factor_type(5040);
  }
};

template<class indexer, class factor_type> struct
fin_diff_coeffs <indexer, factor_type, 3, 4>
{
  CUDA_HOS_DEV static constexpr bool valid()
  {
    return true;
  }
  CUDA_HOS_DEV static constexpr factor_type coeffs(const indexer i, const indexer offset = 0)
  {
    switch(offset)
    {
     default:
       return factor_type(0);
     case 0:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-1);
       case 1:
        return factor_type(3);
       case 2:
        return factor_type(-3);
       case 3:
        return factor_type(1);
      }
     };
     case 1:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-1);
       case 1:
        return factor_type(3);
       case 2:
        return factor_type(-3);
       case 3:
        return factor_type(1);
      }
     };
     case 2:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-1);
       case 1:
        return factor_type(3);
       case 2:
        return factor_type(-3);
       case 3:
        return factor_type(1);
      }
     };
     case 3:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-1);
       case 1:
        return factor_type(3);
       case 2:
        return factor_type(-3);
       case 3:
        return factor_type(1);
      }
     };
    }
  }
  CUDA_HOS_DEV static constexpr factor_type factor()
  {
    return factor_type(1);
  }
};

template<class indexer, class factor_type> struct
fin_diff_coeffs <indexer, factor_type, 3, 5>
{
  CUDA_HOS_DEV static constexpr bool valid()
  {
    return true;
  }
  CUDA_HOS_DEV static constexpr factor_type coeffs(const indexer i, const indexer offset = 0)
  {
    switch(offset)
    {
     default:
       return factor_type(0);
     case 0:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-5);
       case 1:
        return factor_type(18);
       case 2:
        return factor_type(-24);
       case 3:
        return factor_type(14);
       case 4:
        return factor_type(-3);
      }
     };
     case 1:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-3);
       case 1:
        return factor_type(10);
       case 2:
        return factor_type(-12);
       case 3:
        return factor_type(6);
       case 4:
        return factor_type(-1);
      }
     };
     case 2:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-1);
       case 1:
        return factor_type(2);
       case 2:
        return factor_type(0);
       case 3:
        return factor_type(-2);
       case 4:
        return factor_type(1);
      }
     };
     case 3:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(1);
       case 1:
        return factor_type(-6);
       case 2:
        return factor_type(12);
       case 3:
        return factor_type(-10);
       case 4:
        return factor_type(3);
      }
     };
     case 4:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(3);
       case 1:
        return factor_type(-14);
       case 2:
        return factor_type(24);
       case 3:
        return factor_type(-18);
       case 4:
        return factor_type(5);
      }
     };
    }
  }
  CUDA_HOS_DEV static constexpr factor_type factor()
  {
    return factor_type(2);
  }
};

template<class indexer, class factor_type> struct
fin_diff_coeffs <indexer, factor_type, 3, 6>
{
  CUDA_HOS_DEV static constexpr bool valid()
  {
    return true;
  }
  CUDA_HOS_DEV static constexpr factor_type coeffs(const indexer i, const indexer offset = 0)
  {
    switch(offset)
    {
     default:
       return factor_type(0);
     case 0:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-17);
       case 1:
        return factor_type(71);
       case 2:
        return factor_type(-118);
       case 3:
        return factor_type(98);
       case 4:
        return factor_type(-41);
       case 5:
        return factor_type(7);
      }
     };
     case 1:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-7);
       case 1:
        return factor_type(25);
       case 2:
        return factor_type(-34);
       case 3:
        return factor_type(22);
       case 4:
        return factor_type(-7);
       case 5:
        return factor_type(1);
      }
     };
     case 2:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-1);
       case 1:
        return factor_type(-1);
       case 2:
        return factor_type(10);
       case 3:
        return factor_type(-14);
       case 4:
        return factor_type(7);
       case 5:
        return factor_type(-1);
      }
     };
     case 3:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(1);
       case 1:
        return factor_type(-7);
       case 2:
        return factor_type(14);
       case 3:
        return factor_type(-10);
       case 4:
        return factor_type(1);
       case 5:
        return factor_type(1);
      }
     };
     case 4:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-1);
       case 1:
        return factor_type(7);
       case 2:
        return factor_type(-22);
       case 3:
        return factor_type(34);
       case 4:
        return factor_type(-25);
       case 5:
        return factor_type(7);
      }
     };
     case 5:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-7);
       case 1:
        return factor_type(41);
       case 2:
        return factor_type(-98);
       case 3:
        return factor_type(118);
       case 4:
        return factor_type(-71);
       case 5:
        return factor_type(17);
      }
     };
    }
  }
  CUDA_HOS_DEV static constexpr factor_type factor()
  {
    return factor_type(4);
  }
};

template<class indexer, class factor_type> struct
fin_diff_coeffs <indexer, factor_type, 3, 7>
{
  CUDA_HOS_DEV static constexpr bool valid()
  {
    return true;
  }
  CUDA_HOS_DEV static constexpr factor_type coeffs(const indexer i, const indexer offset = 0)
  {
    switch(offset)
    {
     default:
       return factor_type(0);
     case 0:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-49);
       case 1:
        return factor_type(232);
       case 2:
        return factor_type(-461);
       case 3:
        return factor_type(496);
       case 4:
        return factor_type(-307);
       case 5:
        return factor_type(104);
       case 6:
        return factor_type(-15);
      }
     };
     case 1:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-15);
       case 1:
        return factor_type(56);
       case 2:
        return factor_type(-83);
       case 3:
        return factor_type(64);
       case 4:
        return factor_type(-29);
       case 5:
        return factor_type(8);
       case 6:
        return factor_type(-1);
      }
     };
     case 2:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-1);
       case 1:
        return factor_type(-8);
       case 2:
        return factor_type(35);
       case 3:
        return factor_type(-48);
       case 4:
        return factor_type(29);
       case 5:
        return factor_type(-8);
       case 6:
        return factor_type(1);
      }
     };
     case 3:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(1);
       case 1:
        return factor_type(-8);
       case 2:
        return factor_type(13);
       case 3:
        return factor_type(0);
       case 4:
        return factor_type(-13);
       case 5:
        return factor_type(8);
       case 6:
        return factor_type(-1);
      }
     };
     case 4:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-1);
       case 1:
        return factor_type(8);
       case 2:
        return factor_type(-29);
       case 3:
        return factor_type(48);
       case 4:
        return factor_type(-35);
       case 5:
        return factor_type(8);
       case 6:
        return factor_type(1);
      }
     };
     case 5:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(1);
       case 1:
        return factor_type(-8);
       case 2:
        return factor_type(29);
       case 3:
        return factor_type(-64);
       case 4:
        return factor_type(83);
       case 5:
        return factor_type(-56);
       case 6:
        return factor_type(15);
      }
     };
     case 6:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(15);
       case 1:
        return factor_type(-104);
       case 2:
        return factor_type(307);
       case 3:
        return factor_type(-496);
       case 4:
        return factor_type(461);
       case 5:
        return factor_type(-232);
       case 6:
        return factor_type(49);
      }
     };
    }
  }
  CUDA_HOS_DEV static constexpr factor_type factor()
  {
    return factor_type(8);
  }
};

template<class indexer, class factor_type> struct
fin_diff_coeffs <indexer, factor_type, 3, 8>
{
  CUDA_HOS_DEV static constexpr bool valid()
  {
    return true;
  }
  CUDA_HOS_DEV static constexpr factor_type coeffs(const indexer i, const indexer offset = 0)
  {
    switch(offset)
    {
     default:
       return factor_type(0);
     case 0:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-967);
       case 1:
        return factor_type(5104);
       case 2:
        return factor_type(-11787);
       case 3:
        return factor_type(15560);
       case 4:
        return factor_type(-12725);
       case 5:
        return factor_type(6432);
       case 6:
        return factor_type(-1849);
       case 7:
        return factor_type(232);
      }
     };
     case 1:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-232);
       case 1:
        return factor_type(889);
       case 2:
        return factor_type(-1392);
       case 3:
        return factor_type(1205);
       case 4:
        return factor_type(-680);
       case 5:
        return factor_type(267);
       case 6:
        return factor_type(-64);
       case 7:
        return factor_type(7);
      }
     };
     case 2:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-7);
       case 1:
        return factor_type(-176);
       case 2:
        return factor_type(693);
       case 3:
        return factor_type(-1000);
       case 4:
        return factor_type(715);
       case 5:
        return factor_type(-288);
       case 6:
        return factor_type(71);
       case 7:
        return factor_type(-8);
      }
     };
     case 3:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(8);
       case 1:
        return factor_type(-71);
       case 2:
        return factor_type(48);
       case 3:
        return factor_type(245);
       case 4:
        return factor_type(-440);
       case 5:
        return factor_type(267);
       case 6:
        return factor_type(-64);
       case 7:
        return factor_type(7);
      }
     };
     case 4:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-7);
       case 1:
        return factor_type(64);
       case 2:
        return factor_type(-267);
       case 3:
        return factor_type(440);
       case 4:
        return factor_type(-245);
       case 5:
        return factor_type(-48);
       case 6:
        return factor_type(71);
       case 7:
        return factor_type(-8);
      }
     };
     case 5:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(8);
       case 1:
        return factor_type(-71);
       case 2:
        return factor_type(288);
       case 3:
        return factor_type(-715);
       case 4:
        return factor_type(1000);
       case 5:
        return factor_type(-693);
       case 6:
        return factor_type(176);
       case 7:
        return factor_type(7);
      }
     };
     case 6:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-7);
       case 1:
        return factor_type(64);
       case 2:
        return factor_type(-267);
       case 3:
        return factor_type(680);
       case 4:
        return factor_type(-1205);
       case 5:
        return factor_type(1392);
       case 6:
        return factor_type(-889);
       case 7:
        return factor_type(232);
      }
     };
     case 7:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-232);
       case 1:
        return factor_type(1849);
       case 2:
        return factor_type(-6432);
       case 3:
        return factor_type(12725);
       case 4:
        return factor_type(-15560);
       case 5:
        return factor_type(11787);
       case 6:
        return factor_type(-5104);
       case 7:
        return factor_type(967);
      }
     };
    }
  }
  CUDA_HOS_DEV static constexpr factor_type factor()
  {
    return factor_type(120);
  }
};

template<class indexer, class factor_type> struct
fin_diff_coeffs <indexer, factor_type, 3, 9>
{
  CUDA_HOS_DEV static constexpr bool valid()
  {
    return true;
  }
  CUDA_HOS_DEV static constexpr factor_type coeffs(const indexer i, const indexer offset = 0)
  {
    switch(offset)
    {
     default:
       return factor_type(0);
     case 0:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-2403);
       case 1:
        return factor_type(13960);
       case 2:
        return factor_type(-36706);
       case 3:
        return factor_type(57384);
       case 4:
        return factor_type(-58280);
       case 5:
        return factor_type(39128);
       case 6:
        return factor_type(-16830);
       case 7:
        return factor_type(4216);
       case 8:
        return factor_type(-469);
      }
     };
     case 1:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-469);
       case 1:
        return factor_type(1818);
       case 2:
        return factor_type(-2924);
       case 3:
        return factor_type(2690);
       case 4:
        return factor_type(-1710);
       case 5:
        return factor_type(814);
       case 6:
        return factor_type(-268);
       case 7:
        return factor_type(54);
       case 8:
        return factor_type(-5);
      }
     };
     case 2:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-5);
       case 1:
        return factor_type(-424);
       case 2:
        return factor_type(1638);
       case 3:
        return factor_type(-2504);
       case 4:
        return factor_type(2060);
       case 5:
        return factor_type(-1080);
       case 6:
        return factor_type(394);
       case 7:
        return factor_type(-88);
       case 8:
        return factor_type(9);
      }
     };
     case 3:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(9);
       case 1:
        return factor_type(-86);
       case 2:
        return factor_type(-100);
       case 3:
        return factor_type(882);
       case 4:
        return factor_type(-1370);
       case 5:
        return factor_type(926);
       case 6:
        return factor_type(-324);
       case 7:
        return factor_type(70);
       case 8:
        return factor_type(-7);
      }
     };
     case 4:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-7);
       case 1:
        return factor_type(72);
       case 2:
        return factor_type(-338);
       case 3:
        return factor_type(488);
       case 4:
        return factor_type(0);
       case 5:
        return factor_type(-488);
       case 6:
        return factor_type(338);
       case 7:
        return factor_type(-72);
       case 8:
        return factor_type(7);
      }
     };
     case 5:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(7);
       case 1:
        return factor_type(-70);
       case 2:
        return factor_type(324);
       case 3:
        return factor_type(-926);
       case 4:
        return factor_type(1370);
       case 5:
        return factor_type(-882);
       case 6:
        return factor_type(100);
       case 7:
        return factor_type(86);
       case 8:
        return factor_type(-9);
      }
     };
     case 6:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-9);
       case 1:
        return factor_type(88);
       case 2:
        return factor_type(-394);
       case 3:
        return factor_type(1080);
       case 4:
        return factor_type(-2060);
       case 5:
        return factor_type(2504);
       case 6:
        return factor_type(-1638);
       case 7:
        return factor_type(424);
       case 8:
        return factor_type(5);
      }
     };
     case 7:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(5);
       case 1:
        return factor_type(-54);
       case 2:
        return factor_type(268);
       case 3:
        return factor_type(-814);
       case 4:
        return factor_type(1710);
       case 5:
        return factor_type(-2690);
       case 6:
        return factor_type(2924);
       case 7:
        return factor_type(-1818);
       case 8:
        return factor_type(469);
      }
     };
     case 8:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(469);
       case 1:
        return factor_type(-4216);
       case 2:
        return factor_type(16830);
       case 3:
        return factor_type(-39128);
       case 4:
        return factor_type(58280);
       case 5:
        return factor_type(-57384);
       case 6:
        return factor_type(36706);
       case 7:
        return factor_type(-13960);
       case 8:
        return factor_type(2403);
      }
     };
    }
  }
  CUDA_HOS_DEV static constexpr factor_type factor()
  {
    return factor_type(240);
  }
};

template<class indexer, class factor_type> struct
fin_diff_coeffs <indexer, factor_type, 3, 10>
{
  CUDA_HOS_DEV static constexpr bool valid()
  {
    return true;
  }
  CUDA_HOS_DEV static constexpr factor_type coeffs(const indexer i, const indexer offset = 0)
  {
    switch(offset)
    {
     default:
       return factor_type(0);
     case 0:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-180920);
       case 1:
        return factor_type(1145259);
       case 2:
        return factor_type(-3375594);
       case 3:
        return factor_type(6095796);
       case 4:
        return factor_type(-7392546);
       case 5:
        return factor_type(6185970);
       case 6:
        return factor_type(-3540894);
       case 7:
        return factor_type(1328724);
       case 8:
        return factor_type(-295326);
       case 9:
        return factor_type(29531);
      }
     };
     case 1:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-29531);
       case 1:
        return factor_type(114390);
       case 2:
        return factor_type(-183636);
       case 3:
        return factor_type(168126);
       case 4:
        return factor_type(-105714);
       case 5:
        return factor_type(49266);
       case 6:
        return factor_type(-15540);
       case 7:
        return factor_type(2826);
       case 8:
        return factor_type(-171);
       case 9:
        return factor_type(-16);
      }
     };
     case 2:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(16);
       case 1:
        return factor_type(-29691);
       case 2:
        return factor_type(115110);
       case 3:
        return factor_type(-185556);
       case 4:
        return factor_type(171486);
       case 5:
        return factor_type(-109746);
       case 6:
        return factor_type(52626);
       case 7:
        return factor_type(-17460);
       case 8:
        return factor_type(3546);
       case 9:
        return factor_type(-331);
      }
     };
     case 3:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(331);
       case 1:
        return factor_type(-3294);
       case 2:
        return factor_type(-14796);
       case 3:
        return factor_type(75390);
       case 4:
        return factor_type(-116046);
       case 5:
        return factor_type(88074);
       case 6:
        return factor_type(-40236);
       case 7:
        return factor_type(12906);
       case 8:
        return factor_type(-2565);
       case 9:
        return factor_type(236);
      }
     };
     case 4:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-236);
       case 1:
        return factor_type(2691);
       case 2:
        return factor_type(-13914);
       case 3:
        return factor_type(13524);
       case 4:
        return factor_type(25830);
       case 5:
        return factor_type(-56574);
       case 6:
        return factor_type(38514);
       case 7:
        return factor_type(-11916);
       case 8:
        return factor_type(2286);
       case 9:
        return factor_type(-205);
      }
     };
     case 5:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(205);
       case 1:
        return factor_type(-2286);
       case 2:
        return factor_type(11916);
       case 3:
        return factor_type(-38514);
       case 4:
        return factor_type(56574);
       case 5:
        return factor_type(-25830);
       case 6:
        return factor_type(-13524);
       case 7:
        return factor_type(13914);
       case 8:
        return factor_type(-2691);
       case 9:
        return factor_type(236);
      }
     };
     case 6:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-236);
       case 1:
        return factor_type(2565);
       case 2:
        return factor_type(-12906);
       case 3:
        return factor_type(40236);
       case 4:
        return factor_type(-88074);
       case 5:
        return factor_type(116046);
       case 6:
        return factor_type(-75390);
       case 7:
        return factor_type(14796);
       case 8:
        return factor_type(3294);
       case 9:
        return factor_type(-331);
      }
     };
     case 7:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(331);
       case 1:
        return factor_type(-3546);
       case 2:
        return factor_type(17460);
       case 3:
        return factor_type(-52626);
       case 4:
        return factor_type(109746);
       case 5:
        return factor_type(-171486);
       case 6:
        return factor_type(185556);
       case 7:
        return factor_type(-115110);
       case 8:
        return factor_type(29691);
       case 9:
        return factor_type(-16);
      }
     };
     case 8:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(16);
       case 1:
        return factor_type(171);
       case 2:
        return factor_type(-2826);
       case 3:
        return factor_type(15540);
       case 4:
        return factor_type(-49266);
       case 5:
        return factor_type(105714);
       case 6:
        return factor_type(-168126);
       case 7:
        return factor_type(183636);
       case 8:
        return factor_type(-114390);
       case 9:
        return factor_type(29531);
      }
     };
     case 9:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-29531);
       case 1:
        return factor_type(295326);
       case 2:
        return factor_type(-1328724);
       case 3:
        return factor_type(3540894);
       case 4:
        return factor_type(-6185970);
       case 5:
        return factor_type(7392546);
       case 6:
        return factor_type(-6095796);
       case 7:
        return factor_type(3375594);
       case 8:
        return factor_type(-1145259);
       case 9:
        return factor_type(180920);
      }
     };
    }
  }
  CUDA_HOS_DEV static constexpr factor_type factor()
  {
    return factor_type(15120);
  }
};

template<class indexer, class factor_type> struct
fin_diff_coeffs <indexer, factor_type, 3, 11>
{
  CUDA_HOS_DEV static constexpr bool valid()
  {
    return true;
  }
  CUDA_HOS_DEV static constexpr factor_type coeffs(const indexer i, const indexer offset = 0)
  {
    switch(offset)
    {
     default:
       return factor_type(0);
     case 0:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-420475);
       case 1:
        return factor_type(2876868);
       case 2:
        return factor_type(-9389763);
       case 3:
        return factor_type(19227792);
       case 4:
        return factor_type(-27098442);
       case 5:
        return factor_type(27147960);
       case 6:
        return factor_type(-19395138);
       case 7:
        return factor_type(9693648);
       case 8:
        return factor_type(-3229227);
       case 9:
        return factor_type(645412);
       case 10:
        return factor_type(-58635);
      }
     };
     case 1:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-58635);
       case 1:
        return factor_type(224510);
       case 2:
        return factor_type(-348057);
       case 3:
        return factor_type(285012);
       case 4:
        return factor_type(-121758);
       case 5:
        return factor_type(-9072);
       case 6:
        return factor_type(58590);
       case 7:
        return factor_type(-45588);
       case 8:
        return factor_type(18873);
       case 9:
        return factor_type(-4302);
       case 10:
        return factor_type(427);
      }
     };
     case 2:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(427);
       case 1:
        return factor_type(-63332);
       case 2:
        return factor_type(247995);
       case 3:
        return factor_type(-418512);
       case 4:
        return factor_type(425922);
       case 5:
        return factor_type(-319032);
       case 6:
        return factor_type(188202);
       case 7:
        return factor_type(-82320);
       case 8:
        return factor_type(24867);
       case 9:
        return factor_type(-4612);
       case 10:
        return factor_type(395);
      }
     };
     case 3:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(395);
       case 1:
        return factor_type(-3918);
       case 2:
        return factor_type(-41607);
       case 3:
        return factor_type(182820);
       case 4:
        return factor_type(-288162);
       case 5:
        return factor_type(243432);
       case 6:
        return factor_type(-136542);
       case 7:
        return factor_type(57852);
       case 8:
        return factor_type(-17145);
       case 9:
        return factor_type(3142);
       case 10:
        return factor_type(-267);
      }
     };
     case 4:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-267);
       case 1:
        return factor_type(3332);
       case 2:
        return factor_type(-18603);
       case 3:
        return factor_type(2448);
       case 4:
        return factor_type(94710);
       case 5:
        return factor_type(-164808);
       case 6:
        return factor_type(120078);
       case 7:
        return factor_type(-48432);
       case 8:
        return factor_type(13797);
       case 9:
        return factor_type(-2460);
       case 10:
        return factor_type(205);
      }
     };
     case 5:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(205);
       case 1:
        return factor_type(-2522);
       case 2:
        return factor_type(14607);
       case 3:
        return factor_type(-52428);
       case 4:
        return factor_type(70098);
       case 5:
        return factor_type(0);
       case 6:
        return factor_type(-70098);
       case 7:
        return factor_type(52428);
       case 8:
        return factor_type(-14607);
       case 9:
        return factor_type(2522);
       case 10:
        return factor_type(-205);
      }
     };
     case 6:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-205);
       case 1:
        return factor_type(2460);
       case 2:
        return factor_type(-13797);
       case 3:
        return factor_type(48432);
       case 4:
        return factor_type(-120078);
       case 5:
        return factor_type(164808);
       case 6:
        return factor_type(-94710);
       case 7:
        return factor_type(-2448);
       case 8:
        return factor_type(18603);
       case 9:
        return factor_type(-3332);
       case 10:
        return factor_type(267);
      }
     };
     case 7:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(267);
       case 1:
        return factor_type(-3142);
       case 2:
        return factor_type(17145);
       case 3:
        return factor_type(-57852);
       case 4:
        return factor_type(136542);
       case 5:
        return factor_type(-243432);
       case 6:
        return factor_type(288162);
       case 7:
        return factor_type(-182820);
       case 8:
        return factor_type(41607);
       case 9:
        return factor_type(3918);
       case 10:
        return factor_type(-395);
      }
     };
     case 8:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-395);
       case 1:
        return factor_type(4612);
       case 2:
        return factor_type(-24867);
       case 3:
        return factor_type(82320);
       case 4:
        return factor_type(-188202);
       case 5:
        return factor_type(319032);
       case 6:
        return factor_type(-425922);
       case 7:
        return factor_type(418512);
       case 8:
        return factor_type(-247995);
       case 9:
        return factor_type(63332);
       case 10:
        return factor_type(-427);
      }
     };
     case 9:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-427);
       case 1:
        return factor_type(4302);
       case 2:
        return factor_type(-18873);
       case 3:
        return factor_type(45588);
       case 4:
        return factor_type(-58590);
       case 5:
        return factor_type(9072);
       case 6:
        return factor_type(121758);
       case 7:
        return factor_type(-285012);
       case 8:
        return factor_type(348057);
       case 9:
        return factor_type(-224510);
       case 10:
        return factor_type(58635);
      }
     };
     case 10:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(58635);
       case 1:
        return factor_type(-645412);
       case 2:
        return factor_type(3229227);
       case 3:
        return factor_type(-9693648);
       case 4:
        return factor_type(19395138);
       case 5:
        return factor_type(-27147960);
       case 6:
        return factor_type(27098442);
       case 7:
        return factor_type(-19227792);
       case 8:
        return factor_type(9389763);
       case 9:
        return factor_type(-2876868);
       case 10:
        return factor_type(420475);
      }
     };
    }
  }
  CUDA_HOS_DEV static constexpr factor_type factor()
  {
    return factor_type(30240);
  }
};

template<class indexer, class factor_type> struct
fin_diff_coeffs <indexer, factor_type, 4, 5>
{
  CUDA_HOS_DEV static constexpr bool valid()
  {
    return true;
  }
  CUDA_HOS_DEV static constexpr factor_type coeffs(const indexer i, const indexer offset = 0)
  {
    switch(offset)
    {
     default:
       return factor_type(0);
     case 0:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(1);
       case 1:
        return factor_type(-4);
       case 2:
        return factor_type(6);
       case 3:
        return factor_type(-4);
       case 4:
        return factor_type(1);
      }
     };
     case 1:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(1);
       case 1:
        return factor_type(-4);
       case 2:
        return factor_type(6);
       case 3:
        return factor_type(-4);
       case 4:
        return factor_type(1);
      }
     };
     case 2:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(1);
       case 1:
        return factor_type(-4);
       case 2:
        return factor_type(6);
       case 3:
        return factor_type(-4);
       case 4:
        return factor_type(1);
      }
     };
     case 3:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(1);
       case 1:
        return factor_type(-4);
       case 2:
        return factor_type(6);
       case 3:
        return factor_type(-4);
       case 4:
        return factor_type(1);
      }
     };
     case 4:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(1);
       case 1:
        return factor_type(-4);
       case 2:
        return factor_type(6);
       case 3:
        return factor_type(-4);
       case 4:
        return factor_type(1);
      }
     };
    }
  }
  CUDA_HOS_DEV static constexpr factor_type factor()
  {
    return factor_type(1);
  }
};

template<class indexer, class factor_type> struct
fin_diff_coeffs <indexer, factor_type, 4, 6>
{
  CUDA_HOS_DEV static constexpr bool valid()
  {
    return true;
  }
  CUDA_HOS_DEV static constexpr factor_type coeffs(const indexer i, const indexer offset = 0)
  {
    switch(offset)
    {
     default:
       return factor_type(0);
     case 0:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(3);
       case 1:
        return factor_type(-14);
       case 2:
        return factor_type(26);
       case 3:
        return factor_type(-24);
       case 4:
        return factor_type(11);
       case 5:
        return factor_type(-2);
      }
     };
     case 1:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(2);
       case 1:
        return factor_type(-9);
       case 2:
        return factor_type(16);
       case 3:
        return factor_type(-14);
       case 4:
        return factor_type(6);
       case 5:
        return factor_type(-1);
      }
     };
     case 2:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(1);
       case 1:
        return factor_type(-4);
       case 2:
        return factor_type(6);
       case 3:
        return factor_type(-4);
       case 4:
        return factor_type(1);
      }
     };
     case 3:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(0);
       case 1:
        return factor_type(1);
       case 2:
        return factor_type(-4);
       case 3:
        return factor_type(6);
       case 4:
        return factor_type(-4);
       case 5:
        return factor_type(1);
      }
     };
     case 4:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-1);
       case 1:
        return factor_type(6);
       case 2:
        return factor_type(-14);
       case 3:
        return factor_type(16);
       case 4:
        return factor_type(-9);
       case 5:
        return factor_type(2);
      }
     };
     case 5:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-2);
       case 1:
        return factor_type(11);
       case 2:
        return factor_type(-24);
       case 3:
        return factor_type(26);
       case 4:
        return factor_type(-14);
       case 5:
        return factor_type(3);
      }
     };
    }
  }
  CUDA_HOS_DEV static constexpr factor_type factor()
  {
    return factor_type(1);
  }
};

template<class indexer, class factor_type> struct
fin_diff_coeffs <indexer, factor_type, 4, 7>
{
  CUDA_HOS_DEV static constexpr bool valid()
  {
    return true;
  }
  CUDA_HOS_DEV static constexpr factor_type coeffs(const indexer i, const indexer offset = 0)
  {
    switch(offset)
    {
     default:
       return factor_type(0);
     case 0:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(35);
       case 1:
        return factor_type(-186);
       case 2:
        return factor_type(411);
       case 3:
        return factor_type(-484);
       case 4:
        return factor_type(321);
       case 5:
        return factor_type(-114);
       case 6:
        return factor_type(17);
      }
     };
     case 1:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(17);
       case 1:
        return factor_type(-84);
       case 2:
        return factor_type(171);
       case 3:
        return factor_type(-184);
       case 4:
        return factor_type(111);
       case 5:
        return factor_type(-36);
       case 6:
        return factor_type(5);
      }
     };
     case 2:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(5);
       case 1:
        return factor_type(-18);
       case 2:
        return factor_type(21);
       case 3:
        return factor_type(-4);
       case 4:
        return factor_type(-9);
       case 5:
        return factor_type(6);
       case 6:
        return factor_type(-1);
      }
     };
     case 3:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-1);
       case 1:
        return factor_type(12);
       case 2:
        return factor_type(-39);
       case 3:
        return factor_type(56);
       case 4:
        return factor_type(-39);
       case 5:
        return factor_type(12);
       case 6:
        return factor_type(-1);
      }
     };
     case 4:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-1);
       case 1:
        return factor_type(6);
       case 2:
        return factor_type(-9);
       case 3:
        return factor_type(-4);
       case 4:
        return factor_type(21);
       case 5:
        return factor_type(-18);
       case 6:
        return factor_type(5);
      }
     };
     case 5:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(5);
       case 1:
        return factor_type(-36);
       case 2:
        return factor_type(111);
       case 3:
        return factor_type(-184);
       case 4:
        return factor_type(171);
       case 5:
        return factor_type(-84);
       case 6:
        return factor_type(17);
      }
     };
     case 6:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(17);
       case 1:
        return factor_type(-114);
       case 2:
        return factor_type(321);
       case 3:
        return factor_type(-484);
       case 4:
        return factor_type(411);
       case 5:
        return factor_type(-186);
       case 6:
        return factor_type(35);
      }
     };
    }
  }
  CUDA_HOS_DEV static constexpr factor_type factor()
  {
    return factor_type(6);
  }
};

template<class indexer, class factor_type> struct
fin_diff_coeffs <indexer, factor_type, 4, 8>
{
  CUDA_HOS_DEV static constexpr bool valid()
  {
    return true;
  }
  CUDA_HOS_DEV static constexpr factor_type coeffs(const indexer i, const indexer offset = 0)
  {
    switch(offset)
    {
     default:
       return factor_type(0);
     case 0:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(56);
       case 1:
        return factor_type(-333);
       case 2:
        return factor_type(852);
       case 3:
        return factor_type(-1219);
       case 4:
        return factor_type(1056);
       case 5:
        return factor_type(-555);
       case 6:
        return factor_type(164);
       case 7:
        return factor_type(-21);
      }
     };
     case 1:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(21);
       case 1:
        return factor_type(-112);
       case 2:
        return factor_type(255);
       case 3:
        return factor_type(-324);
       case 4:
        return factor_type(251);
       case 5:
        return factor_type(-120);
       case 6:
        return factor_type(33);
       case 7:
        return factor_type(-4);
      }
     };
     case 2:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(4);
       case 1:
        return factor_type(-11);
       case 2:
        return factor_type(0);
       case 3:
        return factor_type(31);
       case 4:
        return factor_type(-44);
       case 5:
        return factor_type(27);
       case 6:
        return factor_type(-8);
       case 7:
        return factor_type(1);
      }
     };
     case 3:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-1);
       case 1:
        return factor_type(12);
       case 2:
        return factor_type(-39);
       case 3:
        return factor_type(56);
       case 4:
        return factor_type(-39);
       case 5:
        return factor_type(12);
       case 6:
        return factor_type(-1);
      }
     };
     case 4:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(0);
       case 1:
        return factor_type(-1);
       case 2:
        return factor_type(12);
       case 3:
        return factor_type(-39);
       case 4:
        return factor_type(56);
       case 5:
        return factor_type(-39);
       case 6:
        return factor_type(12);
       case 7:
        return factor_type(-1);
      }
     };
     case 5:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(1);
       case 1:
        return factor_type(-8);
       case 2:
        return factor_type(27);
       case 3:
        return factor_type(-44);
       case 4:
        return factor_type(31);
       case 5:
        return factor_type(0);
       case 6:
        return factor_type(-11);
       case 7:
        return factor_type(4);
      }
     };
     case 6:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-4);
       case 1:
        return factor_type(33);
       case 2:
        return factor_type(-120);
       case 3:
        return factor_type(251);
       case 4:
        return factor_type(-324);
       case 5:
        return factor_type(255);
       case 6:
        return factor_type(-112);
       case 7:
        return factor_type(21);
      }
     };
     case 7:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-21);
       case 1:
        return factor_type(164);
       case 2:
        return factor_type(-555);
       case 3:
        return factor_type(1056);
       case 4:
        return factor_type(-1219);
       case 5:
        return factor_type(852);
       case 6:
        return factor_type(-333);
       case 7:
        return factor_type(56);
      }
     };
    }
  }
  CUDA_HOS_DEV static constexpr factor_type factor()
  {
    return factor_type(6);
  }
};

template<class indexer, class factor_type> struct
fin_diff_coeffs <indexer, factor_type, 4, 9>
{
  CUDA_HOS_DEV static constexpr bool valid()
  {
    return true;
  }
  CUDA_HOS_DEV static constexpr factor_type coeffs(const indexer i, const indexer offset = 0)
  {
    switch(offset)
    {
     default:
       return factor_type(0);
     case 0:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(3207);
       case 1:
        return factor_type(-21056);
       case 2:
        return factor_type(61156);
       case 3:
        return factor_type(-102912);
       case 4:
        return factor_type(109930);
       case 5:
        return factor_type(-76352);
       case 6:
        return factor_type(33636);
       case 7:
        return factor_type(-8576);
       case 8:
        return factor_type(967);
      }
     };
     case 1:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(967);
       case 1:
        return factor_type(-5496);
       case 2:
        return factor_type(13756);
       case 3:
        return factor_type(-20072);
       case 4:
        return factor_type(18930);
       case 5:
        return factor_type(-11912);
       case 6:
        return factor_type(4876);
       case 7:
        return factor_type(-1176);
       case 8:
        return factor_type(127);
      }
     };
     case 2:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(127);
       case 1:
        return factor_type(-176);
       case 2:
        return factor_type(-924);
       case 3:
        return factor_type(3088);
       case 4:
        return factor_type(-4070);
       case 5:
        return factor_type(2928);
       case 6:
        return factor_type(-1244);
       case 7:
        return factor_type(304);
       case 8:
        return factor_type(-33);
      }
     };
     case 3:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-33);
       case 1:
        return factor_type(424);
       case 2:
        return factor_type(-1364);
       case 3:
        return factor_type(1848);
       case 4:
        return factor_type(-1070);
       case 5:
        return factor_type(88);
       case 6:
        return factor_type(156);
       case 7:
        return factor_type(-56);
       case 8:
        return factor_type(7);
      }
     };
     case 4:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(7);
       case 1:
        return factor_type(-96);
       case 2:
        return factor_type(676);
       case 3:
        return factor_type(-1952);
       case 4:
        return factor_type(2730);
       case 5:
        return factor_type(-1952);
       case 6:
        return factor_type(676);
       case 7:
        return factor_type(-96);
       case 8:
        return factor_type(7);
      }
     };
     case 5:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(7);
       case 1:
        return factor_type(-56);
       case 2:
        return factor_type(156);
       case 3:
        return factor_type(88);
       case 4:
        return factor_type(-1070);
       case 5:
        return factor_type(1848);
       case 6:
        return factor_type(-1364);
       case 7:
        return factor_type(424);
       case 8:
        return factor_type(-33);
      }
     };
     case 6:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-33);
       case 1:
        return factor_type(304);
       case 2:
        return factor_type(-1244);
       case 3:
        return factor_type(2928);
       case 4:
        return factor_type(-4070);
       case 5:
        return factor_type(3088);
       case 6:
        return factor_type(-924);
       case 7:
        return factor_type(-176);
       case 8:
        return factor_type(127);
      }
     };
     case 7:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(127);
       case 1:
        return factor_type(-1176);
       case 2:
        return factor_type(4876);
       case 3:
        return factor_type(-11912);
       case 4:
        return factor_type(18930);
       case 5:
        return factor_type(-20072);
       case 6:
        return factor_type(13756);
       case 7:
        return factor_type(-5496);
       case 8:
        return factor_type(967);
      }
     };
     case 8:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(967);
       case 1:
        return factor_type(-8576);
       case 2:
        return factor_type(33636);
       case 3:
        return factor_type(-76352);
       case 4:
        return factor_type(109930);
       case 5:
        return factor_type(-102912);
       case 6:
        return factor_type(61156);
       case 7:
        return factor_type(-21056);
       case 8:
        return factor_type(3207);
      }
     };
    }
  }
  CUDA_HOS_DEV static constexpr factor_type factor()
  {
    return factor_type(240);
  }
};

template<class indexer, class factor_type> struct
fin_diff_coeffs <indexer, factor_type, 4, 10>
{
  CUDA_HOS_DEV static constexpr bool valid()
  {
    return true;
  }
  CUDA_HOS_DEV static constexpr factor_type coeffs(const indexer i, const indexer offset = 0)
  {
    switch(offset)
    {
     default:
       return factor_type(0);
     case 0:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(4275);
       case 1:
        return factor_type(-30668);
       case 2:
        return factor_type(99604);
       case 3:
        return factor_type(-192624);
       case 4:
        return factor_type(244498);
       case 5:
        return factor_type(-210920);
       case 6:
        return factor_type(123348);
       case 7:
        return factor_type(-47024);
       case 8:
        return factor_type(10579);
       case 9:
        return factor_type(-1068);
      }
     };
     case 1:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(1068);
       case 1:
        return factor_type(-6405);
       case 2:
        return factor_type(17392);
       case 3:
        return factor_type(-28556);
       case 4:
        return factor_type(31656);
       case 5:
        return factor_type(-24638);
       case 6:
        return factor_type(13360);
       case 7:
        return factor_type(-4812);
       case 8:
        return factor_type(1036);
       case 9:
        return factor_type(-101);
      }
     };
     case 2:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(101);
       case 1:
        return factor_type(58);
       case 2:
        return factor_type(-1860);
       case 3:
        return factor_type(5272);
       case 4:
        return factor_type(-7346);
       case 5:
        return factor_type(6204);
       case 6:
        return factor_type(-3428);
       case 7:
        return factor_type(1240);
       case 8:
        return factor_type(-267);
       case 9:
        return factor_type(26);
      }
     };
     case 3:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-26);
       case 1:
        return factor_type(361);
       case 2:
        return factor_type(-1112);
       case 3:
        return factor_type(1260);
       case 4:
        return factor_type(-188);
       case 5:
        return factor_type(-794);
       case 6:
        return factor_type(744);
       case 7:
        return factor_type(-308);
       case 8:
        return factor_type(70);
       case 9:
        return factor_type(-7);
      }
     };
     case 4:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(7);
       case 1:
        return factor_type(-96);
       case 2:
        return factor_type(676);
       case 3:
        return factor_type(-1952);
       case 4:
        return factor_type(2730);
       case 5:
        return factor_type(-1952);
       case 6:
        return factor_type(676);
       case 7:
        return factor_type(-96);
       case 8:
        return factor_type(7);
      }
     };
     case 5:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(0);
       case 1:
        return factor_type(7);
       case 2:
        return factor_type(-96);
       case 3:
        return factor_type(676);
       case 4:
        return factor_type(-1952);
       case 5:
        return factor_type(2730);
       case 6:
        return factor_type(-1952);
       case 7:
        return factor_type(676);
       case 8:
        return factor_type(-96);
       case 9:
        return factor_type(7);
      }
     };
     case 6:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-7);
       case 1:
        return factor_type(70);
       case 2:
        return factor_type(-308);
       case 3:
        return factor_type(744);
       case 4:
        return factor_type(-794);
       case 5:
        return factor_type(-188);
       case 6:
        return factor_type(1260);
       case 7:
        return factor_type(-1112);
       case 8:
        return factor_type(361);
       case 9:
        return factor_type(-26);
      }
     };
     case 7:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(26);
       case 1:
        return factor_type(-267);
       case 2:
        return factor_type(1240);
       case 3:
        return factor_type(-3428);
       case 4:
        return factor_type(6204);
       case 5:
        return factor_type(-7346);
       case 6:
        return factor_type(5272);
       case 7:
        return factor_type(-1860);
       case 8:
        return factor_type(58);
       case 9:
        return factor_type(101);
      }
     };
     case 8:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-101);
       case 1:
        return factor_type(1036);
       case 2:
        return factor_type(-4812);
       case 3:
        return factor_type(13360);
       case 4:
        return factor_type(-24638);
       case 5:
        return factor_type(31656);
       case 6:
        return factor_type(-28556);
       case 7:
        return factor_type(17392);
       case 8:
        return factor_type(-6405);
       case 9:
        return factor_type(1068);
      }
     };
     case 9:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-1068);
       case 1:
        return factor_type(10579);
       case 2:
        return factor_type(-47024);
       case 3:
        return factor_type(123348);
       case 4:
        return factor_type(-210920);
       case 5:
        return factor_type(244498);
       case 6:
        return factor_type(-192624);
       case 7:
        return factor_type(99604);
       case 8:
        return factor_type(-30668);
       case 9:
        return factor_type(4275);
      }
     };
    }
  }
  CUDA_HOS_DEV static constexpr factor_type factor()
  {
    return factor_type(240);
  }
};

template<class indexer, class factor_type> struct
fin_diff_coeffs <indexer, factor_type, 4, 11>
{
  CUDA_HOS_DEV static constexpr bool valid()
  {
    return true;
  }
  CUDA_HOS_DEV static constexpr factor_type coeffs(const indexer i, const indexer offset = 0)
  {
    switch(offset)
    {
     default:
       return factor_type(0);
     case 0:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(341693);
       case 1:
        return factor_type(-2655764);
       case 2:
        return factor_type(9531612);
       case 3:
        return factor_type(-20819472);
       case 4:
        return factor_type(30600654);
       case 5:
        return factor_type(-31524696);
       case 6:
        return factor_type(22968204);
       case 7:
        return factor_type(-11646672);
       case 8:
        return factor_type(3923037);
       case 9:
        return factor_type(-790964);
       case 10:
        return factor_type(72368);
      }
     };
     case 1:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(72368);
       case 1:
        return factor_type(-454355);
       case 2:
        return factor_type(1324476);
       case 3:
        return factor_type(-2409108);
       case 4:
        return factor_type(3061968);
       case 5:
        return factor_type(-2833362);
       case 6:
        return factor_type(1909320);
       case 7:
        return factor_type(-913236);
       case 8:
        return factor_type(294048);
       case 9:
        return factor_type(-57203);
       case 10:
        return factor_type(5084);
      }
     };
     case 2:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(5084);
       case 1:
        return factor_type(16444);
       case 2:
        return factor_type(-174735);
       case 3:
        return factor_type(485616);
       case 4:
        return factor_type(-731388);
       case 5:
        return factor_type(713160);
       case 6:
        return factor_type(-484554);
       case 7:
        return factor_type(231600);
       case 8:
        return factor_type(-74376);
       case 9:
        return factor_type(14428);
       case 10:
        return factor_type(-1279);
      }
     };
     case 3:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-1279);
       case 1:
        return factor_type(19153);
       case 2:
        return factor_type(-53901);
       case 3:
        return factor_type(36300);
       case 4:
        return factor_type(63546);
       case 5:
        return factor_type(-140490);
       case 6:
        return factor_type(122262);
       case 7:
        return factor_type(-62484);
       case 8:
        return factor_type(20565);
       case 9:
        return factor_type(-4031);
       case 10:
        return factor_type(359);
      }
     };
     case 4:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(359);
       case 1:
        return factor_type(-5228);
       case 2:
        return factor_type(38898);
       case 3:
        return factor_type(-113136);
       case 4:
        return factor_type(154770);
       case 5:
        return factor_type(-102312);
       case 6:
        return factor_type(25368);
       case 7:
        return factor_type(3792);
       case 8:
        return factor_type(-3249);
       case 9:
        return factor_type(820);
       case 10:
        return factor_type(-82);
      }
     };
     case 5:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-82);
       case 1:
        return factor_type(1261);
       case 2:
        return factor_type(-9738);
       case 3:
        return factor_type(52428);
       case 4:
        return factor_type(-140196);
       case 5:
        return factor_type(192654);
       case 6:
        return factor_type(-140196);
       case 7:
        return factor_type(52428);
       case 8:
        return factor_type(-9738);
       case 9:
        return factor_type(1261);
       case 10:
        return factor_type(-82);
      }
     };
     case 6:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-82);
       case 1:
        return factor_type(820);
       case 2:
        return factor_type(-3249);
       case 3:
        return factor_type(3792);
       case 4:
        return factor_type(25368);
       case 5:
        return factor_type(-102312);
       case 6:
        return factor_type(154770);
       case 7:
        return factor_type(-113136);
       case 8:
        return factor_type(38898);
       case 9:
        return factor_type(-5228);
       case 10:
        return factor_type(359);
      }
     };
     case 7:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(359);
       case 1:
        return factor_type(-4031);
       case 2:
        return factor_type(20565);
       case 3:
        return factor_type(-62484);
       case 4:
        return factor_type(122262);
       case 5:
        return factor_type(-140490);
       case 6:
        return factor_type(63546);
       case 7:
        return factor_type(36300);
       case 8:
        return factor_type(-53901);
       case 9:
        return factor_type(19153);
       case 10:
        return factor_type(-1279);
      }
     };
     case 8:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-1279);
       case 1:
        return factor_type(14428);
       case 2:
        return factor_type(-74376);
       case 3:
        return factor_type(231600);
       case 4:
        return factor_type(-484554);
       case 5:
        return factor_type(713160);
       case 6:
        return factor_type(-731388);
       case 7:
        return factor_type(485616);
       case 8:
        return factor_type(-174735);
       case 9:
        return factor_type(16444);
       case 10:
        return factor_type(5084);
      }
     };
     case 9:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(5084);
       case 1:
        return factor_type(-57203);
       case 2:
        return factor_type(294048);
       case 3:
        return factor_type(-913236);
       case 4:
        return factor_type(1909320);
       case 5:
        return factor_type(-2833362);
       case 6:
        return factor_type(3061968);
       case 7:
        return factor_type(-2409108);
       case 8:
        return factor_type(1324476);
       case 9:
        return factor_type(-454355);
       case 10:
        return factor_type(72368);
      }
     };
     case 10:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(72368);
       case 1:
        return factor_type(-790964);
       case 2:
        return factor_type(3923037);
       case 3:
        return factor_type(-11646672);
       case 4:
        return factor_type(22968204);
       case 5:
        return factor_type(-31524696);
       case 6:
        return factor_type(30600654);
       case 7:
        return factor_type(-20819472);
       case 8:
        return factor_type(9531612);
       case 9:
        return factor_type(-2655764);
       case 10:
        return factor_type(341693);
      }
     };
    }
  }
  CUDA_HOS_DEV static constexpr factor_type factor()
  {
    return factor_type(15120);
  }
};

template<class indexer, class factor_type> struct
fin_diff_coeffs <indexer, factor_type, 4, 12>
{
  CUDA_HOS_DEV static constexpr bool valid()
  {
    return true;
  }
  CUDA_HOS_DEV static constexpr factor_type coeffs(const indexer i, const indexer offset = 0)
  {
    switch(offset)
    {
     default:
       return factor_type(0);
     case 0:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(418143);
       case 1:
        return factor_type(-3496714);
       case 2:
        return factor_type(13736362);
       case 3:
        return factor_type(-33433722);
       case 4:
        return factor_type(55829154);
       case 5:
        return factor_type(-66844596);
       case 6:
        return factor_type(58288104);
       case 7:
        return factor_type(-36875172);
       case 8:
        return factor_type(16537287);
       case 9:
        return factor_type(-4995714);
       case 10:
        return factor_type(913318);
       case 11:
        return factor_type(-76450);
      }
     };
     case 1:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(76450);
       case 1:
        return factor_type(-499257);
       case 2:
        return factor_type(1548986);
       case 3:
        return factor_type(-3082638);
       case 4:
        return factor_type(4409028);
       case 5:
        return factor_type(-4719246);
       case 6:
        return factor_type(3795204);
       case 7:
        return factor_type(-2260296);
       case 8:
        return factor_type(967578);
       case 9:
        return factor_type(-281713);
       case 10:
        return factor_type(49986);
       case 11:
        return factor_type(-4082);
      }
     };
     case 2:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(4082);
       case 1:
        return factor_type(27466);
       case 2:
        return factor_type(-229845);
       case 3:
        return factor_type(650946);
       case 4:
        return factor_type(-1062048);
       case 5:
        return factor_type(1176084);
       case 6:
        return factor_type(-947478);
       case 7:
        return factor_type(562260);
       case 8:
        return factor_type(-239706);
       case 9:
        return factor_type(69538);
       case 10:
        return factor_type(-12301);
       case 11:
        return factor_type(1002);
      }
     };
     case 3:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-1002);
       case 1:
        return factor_type(16106);
       case 2:
        return factor_type(-38666);
       case 3:
        return factor_type(-9405);
       case 4:
        return factor_type(154956);
       case 5:
        return factor_type(-268464);
       case 6:
        return factor_type(250236);
       case 7:
        return factor_type(-153894);
       case 8:
        return factor_type(66270);
       case 9:
        return factor_type(-19266);
       case 10:
        return factor_type(3406);
       case 11:
        return factor_type(-277);
      }
     };
     case 4:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(277);
       case 1:
        return factor_type(-4326);
       case 2:
        return factor_type(34388);
       case 3:
        return factor_type(-99606);
       case 4:
        return factor_type(127710);
       case 5:
        return factor_type(-64428);
       case 6:
        return factor_type(-12516);
       case 7:
        return factor_type(30852);
       case 8:
        return factor_type(-16779);
       case 9:
        return factor_type(5330);
       case 10:
        return factor_type(-984);
       case 11:
        return factor_type(82);
      }
     };
     case 5:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-82);
       case 1:
        return factor_type(1261);
       case 2:
        return factor_type(-9738);
       case 3:
        return factor_type(52428);
       case 4:
        return factor_type(-140196);
       case 5:
        return factor_type(192654);
       case 6:
        return factor_type(-140196);
       case 7:
        return factor_type(52428);
       case 8:
        return factor_type(-9738);
       case 9:
        return factor_type(1261);
       case 10:
        return factor_type(-82);
      }
     };
     case 6:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(0);
       case 1:
        return factor_type(-82);
       case 2:
        return factor_type(1261);
       case 3:
        return factor_type(-9738);
       case 4:
        return factor_type(52428);
       case 5:
        return factor_type(-140196);
       case 6:
        return factor_type(192654);
       case 7:
        return factor_type(-140196);
       case 8:
        return factor_type(52428);
       case 9:
        return factor_type(-9738);
       case 10:
        return factor_type(1261);
       case 11:
        return factor_type(-82);
      }
     };
     case 7:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(82);
       case 1:
        return factor_type(-984);
       case 2:
        return factor_type(5330);
       case 3:
        return factor_type(-16779);
       case 4:
        return factor_type(30852);
       case 5:
        return factor_type(-12516);
       case 6:
        return factor_type(-64428);
       case 7:
        return factor_type(127710);
       case 8:
        return factor_type(-99606);
       case 9:
        return factor_type(34388);
       case 10:
        return factor_type(-4326);
       case 11:
        return factor_type(277);
      }
     };
     case 8:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-277);
       case 1:
        return factor_type(3406);
       case 2:
        return factor_type(-19266);
       case 3:
        return factor_type(66270);
       case 4:
        return factor_type(-153894);
       case 5:
        return factor_type(250236);
       case 6:
        return factor_type(-268464);
       case 7:
        return factor_type(154956);
       case 8:
        return factor_type(-9405);
       case 9:
        return factor_type(-38666);
       case 10:
        return factor_type(16106);
       case 11:
        return factor_type(-1002);
      }
     };
     case 9:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(1002);
       case 1:
        return factor_type(-12301);
       case 2:
        return factor_type(69538);
       case 3:
        return factor_type(-239706);
       case 4:
        return factor_type(562260);
       case 5:
        return factor_type(-947478);
       case 6:
        return factor_type(1176084);
       case 7:
        return factor_type(-1062048);
       case 8:
        return factor_type(650946);
       case 9:
        return factor_type(-229845);
       case 10:
        return factor_type(27466);
       case 11:
        return factor_type(4082);
      }
     };
     case 10:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-4082);
       case 1:
        return factor_type(49986);
       case 2:
        return factor_type(-281713);
       case 3:
        return factor_type(967578);
       case 4:
        return factor_type(-2260296);
       case 5:
        return factor_type(3795204);
       case 6:
        return factor_type(-4719246);
       case 7:
        return factor_type(4409028);
       case 8:
        return factor_type(-3082638);
       case 9:
        return factor_type(1548986);
       case 10:
        return factor_type(-499257);
       case 11:
        return factor_type(76450);
      }
     };
     case 11:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-76450);
       case 1:
        return factor_type(913318);
       case 2:
        return factor_type(-4995714);
       case 3:
        return factor_type(16537287);
       case 4:
        return factor_type(-36875172);
       case 5:
        return factor_type(58288104);
       case 6:
        return factor_type(-66844596);
       case 7:
        return factor_type(55829154);
       case 8:
        return factor_type(-33433722);
       case 9:
        return factor_type(13736362);
       case 10:
        return factor_type(-3496714);
       case 11:
        return factor_type(418143);
      }
     };
    }
  }
  CUDA_HOS_DEV static constexpr factor_type factor()
  {
    return factor_type(15120);
  }
};

template<class indexer, class factor_type> struct
fin_diff_coeffs <indexer, factor_type, 5, 6>
{
  CUDA_HOS_DEV static constexpr bool valid()
  {
    return true;
  }
  CUDA_HOS_DEV static constexpr factor_type coeffs(const indexer i, const indexer offset = 0)
  {
    switch(offset)
    {
     default:
       return factor_type(0);
     case 0:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-1);
       case 1:
        return factor_type(5);
       case 2:
        return factor_type(-10);
       case 3:
        return factor_type(10);
       case 4:
        return factor_type(-5);
       case 5:
        return factor_type(1);
      }
     };
     case 1:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-1);
       case 1:
        return factor_type(5);
       case 2:
        return factor_type(-10);
       case 3:
        return factor_type(10);
       case 4:
        return factor_type(-5);
       case 5:
        return factor_type(1);
      }
     };
     case 2:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-1);
       case 1:
        return factor_type(5);
       case 2:
        return factor_type(-10);
       case 3:
        return factor_type(10);
       case 4:
        return factor_type(-5);
       case 5:
        return factor_type(1);
      }
     };
     case 3:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-1);
       case 1:
        return factor_type(5);
       case 2:
        return factor_type(-10);
       case 3:
        return factor_type(10);
       case 4:
        return factor_type(-5);
       case 5:
        return factor_type(1);
      }
     };
     case 4:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-1);
       case 1:
        return factor_type(5);
       case 2:
        return factor_type(-10);
       case 3:
        return factor_type(10);
       case 4:
        return factor_type(-5);
       case 5:
        return factor_type(1);
      }
     };
     case 5:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-1);
       case 1:
        return factor_type(5);
       case 2:
        return factor_type(-10);
       case 3:
        return factor_type(10);
       case 4:
        return factor_type(-5);
       case 5:
        return factor_type(1);
      }
     };
    }
  }
  CUDA_HOS_DEV static constexpr factor_type factor()
  {
    return factor_type(1);
  }
};

template<class indexer, class factor_type> struct
fin_diff_coeffs <indexer, factor_type, 5, 7>
{
  CUDA_HOS_DEV static constexpr bool valid()
  {
    return true;
  }
  CUDA_HOS_DEV static constexpr factor_type coeffs(const indexer i, const indexer offset = 0)
  {
    switch(offset)
    {
     default:
       return factor_type(0);
     case 0:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-7);
       case 1:
        return factor_type(40);
       case 2:
        return factor_type(-95);
       case 3:
        return factor_type(120);
       case 4:
        return factor_type(-85);
       case 5:
        return factor_type(32);
       case 6:
        return factor_type(-5);
      }
     };
     case 1:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-5);
       case 1:
        return factor_type(28);
       case 2:
        return factor_type(-65);
       case 3:
        return factor_type(80);
       case 4:
        return factor_type(-55);
       case 5:
        return factor_type(20);
       case 6:
        return factor_type(-3);
      }
     };
     case 2:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-3);
       case 1:
        return factor_type(16);
       case 2:
        return factor_type(-35);
       case 3:
        return factor_type(40);
       case 4:
        return factor_type(-25);
       case 5:
        return factor_type(8);
       case 6:
        return factor_type(-1);
      }
     };
     case 3:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-1);
       case 1:
        return factor_type(4);
       case 2:
        return factor_type(-5);
       case 3:
        return factor_type(0);
       case 4:
        return factor_type(5);
       case 5:
        return factor_type(-4);
       case 6:
        return factor_type(1);
      }
     };
     case 4:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(1);
       case 1:
        return factor_type(-8);
       case 2:
        return factor_type(25);
       case 3:
        return factor_type(-40);
       case 4:
        return factor_type(35);
       case 5:
        return factor_type(-16);
       case 6:
        return factor_type(3);
      }
     };
     case 5:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(3);
       case 1:
        return factor_type(-20);
       case 2:
        return factor_type(55);
       case 3:
        return factor_type(-80);
       case 4:
        return factor_type(65);
       case 5:
        return factor_type(-28);
       case 6:
        return factor_type(5);
      }
     };
     case 6:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(5);
       case 1:
        return factor_type(-32);
       case 2:
        return factor_type(85);
       case 3:
        return factor_type(-120);
       case 4:
        return factor_type(95);
       case 5:
        return factor_type(-40);
       case 6:
        return factor_type(7);
      }
     };
    }
  }
  CUDA_HOS_DEV static constexpr factor_type factor()
  {
    return factor_type(2);
  }
};

template<class indexer, class factor_type> struct
fin_diff_coeffs <indexer, factor_type, 5, 8>
{
  CUDA_HOS_DEV static constexpr bool valid()
  {
    return true;
  }
  CUDA_HOS_DEV static constexpr factor_type coeffs(const indexer i, const indexer offset = 0)
  {
    switch(offset)
    {
     default:
       return factor_type(0);
     case 0:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-46);
       case 1:
        return factor_type(295);
       case 2:
        return factor_type(-810);
       case 3:
        return factor_type(1235);
       case 4:
        return factor_type(-1130);
       case 5:
        return factor_type(621);
       case 6:
        return factor_type(-190);
       case 7:
        return factor_type(25);
      }
     };
     case 1:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-25);
       case 1:
        return factor_type(154);
       case 2:
        return factor_type(-405);
       case 3:
        return factor_type(590);
       case 4:
        return factor_type(-515);
       case 5:
        return factor_type(270);
       case 6:
        return factor_type(-79);
       case 7:
        return factor_type(10);
      }
     };
     case 2:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-10);
       case 1:
        return factor_type(55);
       case 2:
        return factor_type(-126);
       case 3:
        return factor_type(155);
       case 4:
        return factor_type(-110);
       case 5:
        return factor_type(45);
       case 6:
        return factor_type(-10);
       case 7:
        return factor_type(1);
      }
     };
     case 3:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-1);
       case 1:
        return factor_type(-2);
       case 2:
        return factor_type(27);
       case 3:
        return factor_type(-70);
       case 4:
        return factor_type(85);
       case 5:
        return factor_type(-54);
       case 6:
        return factor_type(17);
       case 7:
        return factor_type(-2);
      }
     };
     case 4:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(2);
       case 1:
        return factor_type(-17);
       case 2:
        return factor_type(54);
       case 3:
        return factor_type(-85);
       case 4:
        return factor_type(70);
       case 5:
        return factor_type(-27);
       case 6:
        return factor_type(2);
       case 7:
        return factor_type(1);
      }
     };
     case 5:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-1);
       case 1:
        return factor_type(10);
       case 2:
        return factor_type(-45);
       case 3:
        return factor_type(110);
       case 4:
        return factor_type(-155);
       case 5:
        return factor_type(126);
       case 6:
        return factor_type(-55);
       case 7:
        return factor_type(10);
      }
     };
     case 6:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-10);
       case 1:
        return factor_type(79);
       case 2:
        return factor_type(-270);
       case 3:
        return factor_type(515);
       case 4:
        return factor_type(-590);
       case 5:
        return factor_type(405);
       case 6:
        return factor_type(-154);
       case 7:
        return factor_type(25);
      }
     };
     case 7:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-25);
       case 1:
        return factor_type(190);
       case 2:
        return factor_type(-621);
       case 3:
        return factor_type(1130);
       case 4:
        return factor_type(-1235);
       case 5:
        return factor_type(810);
       case 6:
        return factor_type(-295);
       case 7:
        return factor_type(46);
      }
     };
    }
  }
  CUDA_HOS_DEV static constexpr factor_type factor()
  {
    return factor_type(6);
  }
};

template<class indexer, class factor_type> struct
fin_diff_coeffs <indexer, factor_type, 5, 9>
{
  CUDA_HOS_DEV static constexpr bool valid()
  {
    return true;
  }
  CUDA_HOS_DEV static constexpr factor_type coeffs(const indexer i, const indexer offset = 0)
  {
    switch(offset)
    {
     default:
       return factor_type(0);
     case 0:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-81);
       case 1:
        return factor_type(575);
       case 2:
        return factor_type(-1790);
       case 3:
        return factor_type(3195);
       case 4:
        return factor_type(-3580);
       case 5:
        return factor_type(2581);
       case 6:
        return factor_type(-1170);
       case 7:
        return factor_type(305);
       case 8:
        return factor_type(-35);
      }
     };
     case 1:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-35);
       case 1:
        return factor_type(234);
       case 2:
        return factor_type(-685);
       case 3:
        return factor_type(1150);
       case 4:
        return factor_type(-1215);
       case 5:
        return factor_type(830);
       case 6:
        return factor_type(-359);
       case 7:
        return factor_type(90);
       case 8:
        return factor_type(-10);
      }
     };
     case 2:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-10);
       case 1:
        return factor_type(55);
       case 2:
        return factor_type(-126);
       case 3:
        return factor_type(155);
       case 4:
        return factor_type(-110);
       case 5:
        return factor_type(45);
       case 6:
        return factor_type(-10);
       case 7:
        return factor_type(1);
      }
     };
     case 3:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(0);
       case 1:
        return factor_type(-10);
       case 2:
        return factor_type(55);
       case 3:
        return factor_type(-126);
       case 4:
        return factor_type(155);
       case 5:
        return factor_type(-110);
       case 6:
        return factor_type(45);
       case 7:
        return factor_type(-10);
       case 8:
        return factor_type(1);
      }
     };
     case 4:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(1);
       case 1:
        return factor_type(-9);
       case 2:
        return factor_type(26);
       case 3:
        return factor_type(-29);
       case 4:
        return factor_type(0);
       case 5:
        return factor_type(29);
       case 6:
        return factor_type(-26);
       case 7:
        return factor_type(9);
       case 8:
        return factor_type(-1);
      }
     };
     case 5:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-1);
       case 1:
        return factor_type(10);
       case 2:
        return factor_type(-45);
       case 3:
        return factor_type(110);
       case 4:
        return factor_type(-155);
       case 5:
        return factor_type(126);
       case 6:
        return factor_type(-55);
       case 7:
        return factor_type(10);
      }
     };
     case 6:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(0);
       case 1:
        return factor_type(-1);
       case 2:
        return factor_type(10);
       case 3:
        return factor_type(-45);
       case 4:
        return factor_type(110);
       case 5:
        return factor_type(-155);
       case 6:
        return factor_type(126);
       case 7:
        return factor_type(-55);
       case 8:
        return factor_type(10);
      }
     };
     case 7:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(10);
       case 1:
        return factor_type(-90);
       case 2:
        return factor_type(359);
       case 3:
        return factor_type(-830);
       case 4:
        return factor_type(1215);
       case 5:
        return factor_type(-1150);
       case 6:
        return factor_type(685);
       case 7:
        return factor_type(-234);
       case 8:
        return factor_type(35);
      }
     };
     case 8:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(35);
       case 1:
        return factor_type(-305);
       case 2:
        return factor_type(1170);
       case 3:
        return factor_type(-2581);
       case 4:
        return factor_type(3580);
       case 5:
        return factor_type(-3195);
       case 6:
        return factor_type(1790);
       case 7:
        return factor_type(-575);
       case 8:
        return factor_type(81);
      }
     };
    }
  }
  CUDA_HOS_DEV static constexpr factor_type factor()
  {
    return factor_type(6);
  }
};

template<class indexer, class factor_type> struct
fin_diff_coeffs <indexer, factor_type, 5, 10>
{
  CUDA_HOS_DEV static constexpr bool valid()
  {
    return true;
  }
  CUDA_HOS_DEV static constexpr factor_type coeffs(const indexer i, const indexer offset = 0)
  {
    switch(offset)
    {
     default:
       return factor_type(0);
     case 0:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-3013);
       case 1:
        return factor_type(23421);
       case 2:
        return factor_type(-81444);
       case 3:
        return factor_type(166476);
       case 4:
        return factor_type(-220614);
       case 5:
        return factor_type(196638);
       case 6:
        return factor_type(-117876);
       case 7:
        return factor_type(45804);
       case 8:
        return factor_type(-10461);
       case 9:
        return factor_type(1069);
      }
     };
     case 1:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-1069);
       case 1:
        return factor_type(7677);
       case 2:
        return factor_type(-24684);
       case 3:
        return factor_type(46836);
       case 4:
        return factor_type(-58014);
       case 5:
        return factor_type(48774);
       case 6:
        return factor_type(-27852);
       case 7:
        return factor_type(10404);
       case 8:
        return factor_type(-2301);
       case 9:
        return factor_type(229);
      }
     };
     case 2:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-229);
       case 1:
        return factor_type(1221);
       case 2:
        return factor_type(-2628);
       case 3:
        return factor_type(2796);
       case 4:
        return factor_type(-1254);
       case 5:
        return factor_type(-306);
       case 6:
        return factor_type(684);
       case 7:
        return factor_type(-372);
       case 8:
        return factor_type(99);
       case 9:
        return factor_type(-11);
      }
     };
     case 3:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(11);
       case 1:
        return factor_type(-339);
       case 2:
        return factor_type(1716);
       case 3:
        return factor_type(-3948);
       case 4:
        return factor_type(5106);
       case 5:
        return factor_type(-4026);
       case 6:
        return factor_type(2004);
       case 7:
        return factor_type(-636);
       case 8:
        return factor_type(123);
       case 9:
        return factor_type(-11);
      }
     };
     case 4:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(11);
       case 1:
        return factor_type(-99);
       case 2:
        return factor_type(156);
       case 3:
        return factor_type(396);
       case 4:
        return factor_type(-1638);
       case 5:
        return factor_type(2334);
       case 6:
        return factor_type(-1716);
       case 7:
        return factor_type(684);
       case 8:
        return factor_type(-141);
       case 9:
        return factor_type(13);
      }
     };
     case 5:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-13);
       case 1:
        return factor_type(141);
       case 2:
        return factor_type(-684);
       case 3:
        return factor_type(1716);
       case 4:
        return factor_type(-2334);
       case 5:
        return factor_type(1638);
       case 6:
        return factor_type(-396);
       case 7:
        return factor_type(-156);
       case 8:
        return factor_type(99);
       case 9:
        return factor_type(-11);
      }
     };
     case 6:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(11);
       case 1:
        return factor_type(-123);
       case 2:
        return factor_type(636);
       case 3:
        return factor_type(-2004);
       case 4:
        return factor_type(4026);
       case 5:
        return factor_type(-5106);
       case 6:
        return factor_type(3948);
       case 7:
        return factor_type(-1716);
       case 8:
        return factor_type(339);
       case 9:
        return factor_type(-11);
      }
     };
     case 7:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(11);
       case 1:
        return factor_type(-99);
       case 2:
        return factor_type(372);
       case 3:
        return factor_type(-684);
       case 4:
        return factor_type(306);
       case 5:
        return factor_type(1254);
       case 6:
        return factor_type(-2796);
       case 7:
        return factor_type(2628);
       case 8:
        return factor_type(-1221);
       case 9:
        return factor_type(229);
      }
     };
     case 8:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-229);
       case 1:
        return factor_type(2301);
       case 2:
        return factor_type(-10404);
       case 3:
        return factor_type(27852);
       case 4:
        return factor_type(-48774);
       case 5:
        return factor_type(58014);
       case 6:
        return factor_type(-46836);
       case 7:
        return factor_type(24684);
       case 8:
        return factor_type(-7677);
       case 9:
        return factor_type(1069);
      }
     };
     case 9:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-1069);
       case 1:
        return factor_type(10461);
       case 2:
        return factor_type(-45804);
       case 3:
        return factor_type(117876);
       case 4:
        return factor_type(-196638);
       case 5:
        return factor_type(220614);
       case 6:
        return factor_type(-166476);
       case 7:
        return factor_type(81444);
       case 8:
        return factor_type(-23421);
       case 9:
        return factor_type(3013);
      }
     };
    }
  }
  CUDA_HOS_DEV static constexpr factor_type factor()
  {
    return factor_type(144);
  }
};

template<class indexer, class factor_type> struct
fin_diff_coeffs <indexer, factor_type, 5, 11>
{
  CUDA_HOS_DEV static constexpr bool valid()
  {
    return true;
  }
  CUDA_HOS_DEV static constexpr factor_type coeffs(const indexer i, const indexer offset = 0)
  {
    switch(offset)
    {
     default:
       return factor_type(0);
     case 0:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-8591);
       case 1:
        return factor_type(72492);
       case 2:
        return factor_type(-278313);
       case 3:
        return factor_type(640752);
       case 4:
        return factor_type(-979878);
       case 5:
        return factor_type(1039656);
       case 6:
        return factor_type(-774402);
       case 7:
        return factor_type(399408);
       case 8:
        return factor_type(-136347);
       case 9:
        return factor_type(27788);
       case 10:
        return factor_type(-2565);
      }
     };
     case 1:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-2565);
       case 1:
        return factor_type(19624);
       case 2:
        return factor_type(-68583);
       case 3:
        return factor_type(144912);
       case 4:
        return factor_type(-205698);
       case 5:
        return factor_type(205152);
       case 6:
        return factor_type(-145374);
       case 7:
        return factor_type(72048);
       case 8:
        return factor_type(-23817);
       case 9:
        return factor_type(4728);
       case 10:
        return factor_type(-427);
      }
     };
     case 2:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-427);
       case 1:
        return factor_type(2132);
       case 2:
        return factor_type(-3861);
       case 3:
        return factor_type(1872);
       case 4:
        return factor_type(4002);
       case 5:
        return factor_type(-8424);
       case 6:
        return factor_type(7878);
       case 7:
        return factor_type(-4464);
       case 8:
        return factor_type(1593);
       case 9:
        return factor_type(-332);
       case 10:
        return factor_type(31);
      }
     };
     case 3:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(31);
       case 1:
        return factor_type(-768);
       case 2:
        return factor_type(3837);
       case 3:
        return factor_type(-8976);
       case 4:
        return factor_type(12102);
       case 5:
        return factor_type(-10320);
       case 6:
        return factor_type(5898);
       case 7:
        return factor_type(-2352);
       case 8:
        return factor_type(651);
       case 9:
        return factor_type(-112);
       case 10:
        return factor_type(9);
      }
     };
     case 4:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(9);
       case 1:
        return factor_type(-68);
       case 2:
        return factor_type(-273);
       case 3:
        return factor_type(2352);
       case 4:
        return factor_type(-6006);
       case 5:
        return factor_type(7944);
       case 6:
        return factor_type(-6162);
       case 7:
        return factor_type(2928);
       case 8:
        return factor_type(-867);
       case 9:
        return factor_type(156);
       case 10:
        return factor_type(-13);
      }
     };
     case 5:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-13);
       case 1:
        return factor_type(152);
       case 2:
        return factor_type(-783);
       case 3:
        return factor_type(1872);
       case 4:
        return factor_type(-1938);
       case 5:
        return factor_type(0);
       case 6:
        return factor_type(1938);
       case 7:
        return factor_type(-1872);
       case 8:
        return factor_type(783);
       case 9:
        return factor_type(-152);
       case 10:
        return factor_type(13);
      }
     };
     case 6:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(13);
       case 1:
        return factor_type(-156);
       case 2:
        return factor_type(867);
       case 3:
        return factor_type(-2928);
       case 4:
        return factor_type(6162);
       case 5:
        return factor_type(-7944);
       case 6:
        return factor_type(6006);
       case 7:
        return factor_type(-2352);
       case 8:
        return factor_type(273);
       case 9:
        return factor_type(68);
       case 10:
        return factor_type(-9);
      }
     };
     case 7:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-9);
       case 1:
        return factor_type(112);
       case 2:
        return factor_type(-651);
       case 3:
        return factor_type(2352);
       case 4:
        return factor_type(-5898);
       case 5:
        return factor_type(10320);
       case 6:
        return factor_type(-12102);
       case 7:
        return factor_type(8976);
       case 8:
        return factor_type(-3837);
       case 9:
        return factor_type(768);
       case 10:
        return factor_type(-31);
      }
     };
     case 8:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-31);
       case 1:
        return factor_type(332);
       case 2:
        return factor_type(-1593);
       case 3:
        return factor_type(4464);
       case 4:
        return factor_type(-7878);
       case 5:
        return factor_type(8424);
       case 6:
        return factor_type(-4002);
       case 7:
        return factor_type(-1872);
       case 8:
        return factor_type(3861);
       case 9:
        return factor_type(-2132);
       case 10:
        return factor_type(427);
      }
     };
     case 9:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(427);
       case 1:
        return factor_type(-4728);
       case 2:
        return factor_type(23817);
       case 3:
        return factor_type(-72048);
       case 4:
        return factor_type(145374);
       case 5:
        return factor_type(-205152);
       case 6:
        return factor_type(205698);
       case 7:
        return factor_type(-144912);
       case 8:
        return factor_type(68583);
       case 9:
        return factor_type(-19624);
       case 10:
        return factor_type(2565);
      }
     };
     case 10:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(2565);
       case 1:
        return factor_type(-27788);
       case 2:
        return factor_type(136347);
       case 3:
        return factor_type(-399408);
       case 4:
        return factor_type(774402);
       case 5:
        return factor_type(-1039656);
       case 6:
        return factor_type(979878);
       case 7:
        return factor_type(-640752);
       case 8:
        return factor_type(278313);
       case 9:
        return factor_type(-72492);
       case 10:
        return factor_type(8591);
      }
     };
    }
  }
  CUDA_HOS_DEV static constexpr factor_type factor()
  {
    return factor_type(288);
  }
};

template<class indexer, class factor_type> struct
fin_diff_coeffs <indexer, factor_type, 5, 12>
{
  CUDA_HOS_DEV static constexpr bool valid()
  {
    return true;
  }
  CUDA_HOS_DEV static constexpr factor_type coeffs(const indexer i, const indexer offset = 0)
  {
    switch(offset)
    {
     default:
       return factor_type(0);
     case 0:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-242537);
       case 1:
        return factor_type(2205718);
       case 2:
        return factor_type(-9261503);
       case 3:
        return factor_type(23706582);
       case 4:
        return factor_type(-41079018);
       case 5:
        return factor_type(50534988);
       case 6:
        return factor_type(-44964654);
       case 7:
        return factor_type(28889148);
       case 8:
        return factor_type(-13114077);
       case 9:
        return factor_type(4000478);
       case 10:
        return factor_type(-737251);
       case 11:
        return factor_type(62126);
      }
     };
     case 1:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-62126);
       case 1:
        return factor_type(502975);
       case 2:
        return factor_type(-1894598);
       case 3:
        return factor_type(4406217);
       case 4:
        return factor_type(-7045788);
       case 5:
        return factor_type(8124774);
       case 6:
        return factor_type(-6869436);
       case 7:
        return factor_type(4239138);
       case 8:
        return factor_type(-1863222);
       case 9:
        return factor_type(553643);
       case 10:
        return factor_type(-99838);
       case 11:
        return factor_type(8261);
      }
     };
     case 2:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-8261);
       case 1:
        return factor_type(37006);
       case 2:
        return factor_type(-42251);
       case 3:
        return factor_type(-77178);
       case 4:
        return factor_type(317022);
       case 5:
        return factor_type(-503076);
       case 6:
        return factor_type(491610);
       case 7:
        return factor_type(-326724);
       case 8:
        return factor_type(149943);
       case 9:
        return factor_type(-45802);
       case 10:
        return factor_type(8417);
       case 11:
        return factor_type(-706);
      }
     };
     case 3:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(706);
       case 1:
        return factor_type(-16733);
       case 2:
        return factor_type(83602);
       case 3:
        return factor_type(-197571);
       case 4:
        return factor_type(272292);
       case 5:
        return factor_type(-242130);
       case 6:
        return factor_type(149268);
       case 7:
        return factor_type(-67542);
       case 8:
        return factor_type(22746);
       case 9:
        return factor_type(-5377);
       case 10:
        return factor_type(794);
       case 11:
        return factor_type(-55);
      }
     };
     case 4:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(55);
       case 1:
        return factor_type(46);
       case 2:
        return factor_type(-13103);
       case 3:
        return factor_type(71502);
       case 4:
        return factor_type(-170346);
       case 5:
        return factor_type(228732);
       case 6:
        return factor_type(-191310);
       case 7:
        return factor_type(105708);
       case 8:
        return factor_type(-40317);
       case 9:
        return factor_type(10646);
       case 10:
        return factor_type(-1747);
       case 11:
        return factor_type(134);
      }
     };
     case 5:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-134);
       case 1:
        return factor_type(1663);
       case 2:
        return factor_type(-8798);
       case 3:
        return factor_type(16377);
       case 4:
        return factor_type(5172);
       case 5:
        return factor_type(-64218);
       case 6:
        return factor_type(104916);
       case 7:
        return factor_type(-85182);
       case 8:
        return factor_type(39378);
       case 9:
        return factor_type(-10837);
       case 10:
        return factor_type(1802);
       case 11:
        return factor_type(-139);
      }
     };
     case 6:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(139);
       case 1:
        return factor_type(-1802);
       case 2:
        return factor_type(10837);
       case 3:
        return factor_type(-39378);
       case 4:
        return factor_type(85182);
       case 5:
        return factor_type(-104916);
       case 6:
        return factor_type(64218);
       case 7:
        return factor_type(-5172);
       case 8:
        return factor_type(-16377);
       case 9:
        return factor_type(8798);
       case 10:
        return factor_type(-1663);
       case 11:
        return factor_type(134);
      }
     };
     case 7:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-134);
       case 1:
        return factor_type(1747);
       case 2:
        return factor_type(-10646);
       case 3:
        return factor_type(40317);
       case 4:
        return factor_type(-105708);
       case 5:
        return factor_type(191310);
       case 6:
        return factor_type(-228732);
       case 7:
        return factor_type(170346);
       case 8:
        return factor_type(-71502);
       case 9:
        return factor_type(13103);
       case 10:
        return factor_type(-46);
       case 11:
        return factor_type(-55);
      }
     };
     case 8:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(55);
       case 1:
        return factor_type(-794);
       case 2:
        return factor_type(5377);
       case 3:
        return factor_type(-22746);
       case 4:
        return factor_type(67542);
       case 5:
        return factor_type(-149268);
       case 6:
        return factor_type(242130);
       case 7:
        return factor_type(-272292);
       case 8:
        return factor_type(197571);
       case 9:
        return factor_type(-83602);
       case 10:
        return factor_type(16733);
       case 11:
        return factor_type(-706);
      }
     };
     case 9:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(706);
       case 1:
        return factor_type(-8417);
       case 2:
        return factor_type(45802);
       case 3:
        return factor_type(-149943);
       case 4:
        return factor_type(326724);
       case 5:
        return factor_type(-491610);
       case 6:
        return factor_type(503076);
       case 7:
        return factor_type(-317022);
       case 8:
        return factor_type(77178);
       case 9:
        return factor_type(42251);
       case 10:
        return factor_type(-37006);
       case 11:
        return factor_type(8261);
      }
     };
     case 10:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-8261);
       case 1:
        return factor_type(99838);
       case 2:
        return factor_type(-553643);
       case 3:
        return factor_type(1863222);
       case 4:
        return factor_type(-4239138);
       case 5:
        return factor_type(6869436);
       case 6:
        return factor_type(-8124774);
       case 7:
        return factor_type(7045788);
       case 8:
        return factor_type(-4406217);
       case 9:
        return factor_type(1894598);
       case 10:
        return factor_type(-502975);
       case 11:
        return factor_type(62126);
      }
     };
     case 11:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-62126);
       case 1:
        return factor_type(737251);
       case 2:
        return factor_type(-4000478);
       case 3:
        return factor_type(13114077);
       case 4:
        return factor_type(-28889148);
       case 5:
        return factor_type(44964654);
       case 6:
        return factor_type(-50534988);
       case 7:
        return factor_type(41079018);
       case 8:
        return factor_type(-23706582);
       case 9:
        return factor_type(9261503);
       case 10:
        return factor_type(-2205718);
       case 11:
        return factor_type(242537);
      }
     };
    }
  }
  CUDA_HOS_DEV static constexpr factor_type factor()
  {
    return factor_type(6048);
  }
};

template<class indexer, class factor_type> struct
fin_diff_coeffs <indexer, factor_type, 5, 13>
{
  CUDA_HOS_DEV static constexpr bool valid()
  {
    return true;
  }
  CUDA_HOS_DEV static constexpr factor_type coeffs(const indexer i, const indexer offset = 0)
  {
    switch(offset)
    {
     default:
       return factor_type(0);
     case 0:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-624455);
       case 1:
        return factor_type(6084008);
       case 2:
        return factor_type(-27722152);
       case 3:
        return factor_type(78076984);
       case 4:
        return factor_type(-151151631);
       case 5:
        return factor_type(211459728);
       case 6:
        return factor_type(-218717352);
       case 7:
        return factor_type(168168048);
       case 8:
        return factor_type(-95221749);
       case 9:
        return factor_type(38664776);
       case 10:
        return factor_type(-10673648);
       case 11:
        return factor_type(1796824);
       case 12:
        return factor_type(-139381);
      }
     };
     case 1:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-139381);
       case 1:
        return factor_type(1187498);
       case 2:
        return factor_type(-4787710);
       case 3:
        return factor_type(12140814);
       case 4:
        return factor_type(-21580431);
       case 5:
        return factor_type(28231716);
       case 6:
        return factor_type(-27718068);
       case 7:
        return factor_type(20460444);
       case 8:
        return factor_type(-11215299);
       case 9:
        return factor_type(4435666);
       case 10:
        return factor_type(-1198190);
       case 11:
        return factor_type(198070);
       case 12:
        return factor_type(-15129);
      }
     };
     case 2:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-15129);
       case 1:
        return factor_type(57296);
       case 2:
        return factor_type(7436);
       case 3:
        return factor_type(-460816);
       case 4:
        return factor_type(1323579);
       case 5:
        return factor_type(-2109408);
       case 6:
        return factor_type(2270352);
       case 7:
        return factor_type(-1756704);
       case 8:
        return factor_type(989421);
       case 9:
        return factor_type(-398064);
       case 10:
        return factor_type(108772);
       case 11:
        return factor_type(-18128);
       case 12:
        return factor_type(1393);
      }
     };
     case 3:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(1393);
       case 1:
        return factor_type(-33238);
       case 2:
        return factor_type(165950);
       case 3:
        return factor_type(-390962);
       case 4:
        return factor_type(535179);
       case 5:
        return factor_type(-469212);
       case 6:
        return factor_type(280980);
       case 7:
        return factor_type(-120036);
       case 8:
        return factor_type(36087);
       case 9:
        return factor_type(-6574);
       case 10:
        return factor_type(334);
       case 11:
        return factor_type(118);
       case 12:
        return factor_type(-19);
      }
     };
     case 4:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-19);
       case 1:
        return factor_type(1640);
       case 2:
        return factor_type(-34720);
       case 3:
        return factor_type(171384);
       case 4:
        return factor_type(-404547);
       case 5:
        return factor_type(559632);
       case 6:
        return factor_type(-501816);
       case 7:
        return factor_type(313584);
       case 8:
        return factor_type(-144489);
       case 9:
        return factor_type(49672);
       case 10:
        return factor_type(-12008);
       case 11:
        return factor_type(1816);
       case 12:
        return factor_type(-129);
      }
     };
     case 5:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-129);
       case 1:
        return factor_type(1658);
       case 2:
        return factor_type(-8422);
       case 3:
        return factor_type(2174);
       case 4:
        return factor_type(79149);
       case 5:
        return factor_type(-238524);
       case 6:
        return factor_type(338268);
       case 7:
        return factor_type(-280452);
       case 8:
        return factor_type(147561);
       case 9:
        return factor_type(-52254);
       case 10:
        return factor_type(12778);
       case 11:
        return factor_type(-1946);
       case 12:
        return factor_type(139);
      }
     };
     case 6:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(139);
       case 1:
        return factor_type(-1936);
       case 2:
        return factor_type(12500);
       case 3:
        return factor_type(-48176);
       case 4:
        return factor_type(101559);
       case 5:
        return factor_type(-99744);
       case 6:
        return factor_type(0);
       case 7:
        return factor_type(99744);
       case 8:
        return factor_type(-101559);
       case 9:
        return factor_type(48176);
       case 10:
        return factor_type(-12500);
       case 11:
        return factor_type(1936);
       case 12:
        return factor_type(-139);
      }
     };
     case 7:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-139);
       case 1:
        return factor_type(1946);
       case 2:
        return factor_type(-12778);
       case 3:
        return factor_type(52254);
       case 4:
        return factor_type(-147561);
       case 5:
        return factor_type(280452);
       case 6:
        return factor_type(-338268);
       case 7:
        return factor_type(238524);
       case 8:
        return factor_type(-79149);
       case 9:
        return factor_type(-2174);
       case 10:
        return factor_type(8422);
       case 11:
        return factor_type(-1658);
       case 12:
        return factor_type(129);
      }
     };
     case 8:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(129);
       case 1:
        return factor_type(-1816);
       case 2:
        return factor_type(12008);
       case 3:
        return factor_type(-49672);
       case 4:
        return factor_type(144489);
       case 5:
        return factor_type(-313584);
       case 6:
        return factor_type(501816);
       case 7:
        return factor_type(-559632);
       case 8:
        return factor_type(404547);
       case 9:
        return factor_type(-171384);
       case 10:
        return factor_type(34720);
       case 11:
        return factor_type(-1640);
       case 12:
        return factor_type(19);
      }
     };
     case 9:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(19);
       case 1:
        return factor_type(-118);
       case 2:
        return factor_type(-334);
       case 3:
        return factor_type(6574);
       case 4:
        return factor_type(-36087);
       case 5:
        return factor_type(120036);
       case 6:
        return factor_type(-280980);
       case 7:
        return factor_type(469212);
       case 8:
        return factor_type(-535179);
       case 9:
        return factor_type(390962);
       case 10:
        return factor_type(-165950);
       case 11:
        return factor_type(33238);
       case 12:
        return factor_type(-1393);
      }
     };
     case 10:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-1393);
       case 1:
        return factor_type(18128);
       case 2:
        return factor_type(-108772);
       case 3:
        return factor_type(398064);
       case 4:
        return factor_type(-989421);
       case 5:
        return factor_type(1756704);
       case 6:
        return factor_type(-2270352);
       case 7:
        return factor_type(2109408);
       case 8:
        return factor_type(-1323579);
       case 9:
        return factor_type(460816);
       case 10:
        return factor_type(-7436);
       case 11:
        return factor_type(-57296);
       case 12:
        return factor_type(15129);
      }
     };
     case 11:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(15129);
       case 1:
        return factor_type(-198070);
       case 2:
        return factor_type(1198190);
       case 3:
        return factor_type(-4435666);
       case 4:
        return factor_type(11215299);
       case 5:
        return factor_type(-20460444);
       case 6:
        return factor_type(27718068);
       case 7:
        return factor_type(-28231716);
       case 8:
        return factor_type(21580431);
       case 9:
        return factor_type(-12140814);
       case 10:
        return factor_type(4787710);
       case 11:
        return factor_type(-1187498);
       case 12:
        return factor_type(139381);
      }
     };
     case 12:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(139381);
       case 1:
        return factor_type(-1796824);
       case 2:
        return factor_type(10673648);
       case 3:
        return factor_type(-38664776);
       case 4:
        return factor_type(95221749);
       case 5:
        return factor_type(-168168048);
       case 6:
        return factor_type(218717352);
       case 7:
        return factor_type(-211459728);
       case 8:
        return factor_type(151151631);
       case 9:
        return factor_type(-78076984);
       case 10:
        return factor_type(27722152);
       case 11:
        return factor_type(-6084008);
       case 12:
        return factor_type(624455);
      }
     };
    }
  }
  CUDA_HOS_DEV static constexpr factor_type factor()
  {
    return factor_type(12096);
  }
};

template<class indexer, class factor_type> struct
fin_diff_coeffs <indexer, factor_type, 6, 7>
{
  CUDA_HOS_DEV static constexpr bool valid()
  {
    return true;
  }
  CUDA_HOS_DEV static constexpr factor_type coeffs(const indexer i, const indexer offset = 0)
  {
    switch(offset)
    {
     default:
       return factor_type(0);
     case 0:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(1);
       case 1:
        return factor_type(-6);
       case 2:
        return factor_type(15);
       case 3:
        return factor_type(-20);
       case 4:
        return factor_type(15);
       case 5:
        return factor_type(-6);
       case 6:
        return factor_type(1);
      }
     };
     case 1:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(1);
       case 1:
        return factor_type(-6);
       case 2:
        return factor_type(15);
       case 3:
        return factor_type(-20);
       case 4:
        return factor_type(15);
       case 5:
        return factor_type(-6);
       case 6:
        return factor_type(1);
      }
     };
     case 2:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(1);
       case 1:
        return factor_type(-6);
       case 2:
        return factor_type(15);
       case 3:
        return factor_type(-20);
       case 4:
        return factor_type(15);
       case 5:
        return factor_type(-6);
       case 6:
        return factor_type(1);
      }
     };
     case 3:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(1);
       case 1:
        return factor_type(-6);
       case 2:
        return factor_type(15);
       case 3:
        return factor_type(-20);
       case 4:
        return factor_type(15);
       case 5:
        return factor_type(-6);
       case 6:
        return factor_type(1);
      }
     };
     case 4:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(1);
       case 1:
        return factor_type(-6);
       case 2:
        return factor_type(15);
       case 3:
        return factor_type(-20);
       case 4:
        return factor_type(15);
       case 5:
        return factor_type(-6);
       case 6:
        return factor_type(1);
      }
     };
     case 5:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(1);
       case 1:
        return factor_type(-6);
       case 2:
        return factor_type(15);
       case 3:
        return factor_type(-20);
       case 4:
        return factor_type(15);
       case 5:
        return factor_type(-6);
       case 6:
        return factor_type(1);
      }
     };
     case 6:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(1);
       case 1:
        return factor_type(-6);
       case 2:
        return factor_type(15);
       case 3:
        return factor_type(-20);
       case 4:
        return factor_type(15);
       case 5:
        return factor_type(-6);
       case 6:
        return factor_type(1);
      }
     };
    }
  }
  CUDA_HOS_DEV static constexpr factor_type factor()
  {
    return factor_type(1);
  }
};

template<class indexer, class factor_type> struct
fin_diff_coeffs <indexer, factor_type, 6, 8>
{
  CUDA_HOS_DEV static constexpr bool valid()
  {
    return true;
  }
  CUDA_HOS_DEV static constexpr factor_type coeffs(const indexer i, const indexer offset = 0)
  {
    switch(offset)
    {
     default:
       return factor_type(0);
     case 0:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(4);
       case 1:
        return factor_type(-27);
       case 2:
        return factor_type(78);
       case 3:
        return factor_type(-125);
       case 4:
        return factor_type(120);
       case 5:
        return factor_type(-69);
       case 6:
        return factor_type(22);
       case 7:
        return factor_type(-3);
      }
     };
     case 1:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(3);
       case 1:
        return factor_type(-20);
       case 2:
        return factor_type(57);
       case 3:
        return factor_type(-90);
       case 4:
        return factor_type(85);
       case 5:
        return factor_type(-48);
       case 6:
        return factor_type(15);
       case 7:
        return factor_type(-2);
      }
     };
     case 2:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(2);
       case 1:
        return factor_type(-13);
       case 2:
        return factor_type(36);
       case 3:
        return factor_type(-55);
       case 4:
        return factor_type(50);
       case 5:
        return factor_type(-27);
       case 6:
        return factor_type(8);
       case 7:
        return factor_type(-1);
      }
     };
     case 3:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(1);
       case 1:
        return factor_type(-6);
       case 2:
        return factor_type(15);
       case 3:
        return factor_type(-20);
       case 4:
        return factor_type(15);
       case 5:
        return factor_type(-6);
       case 6:
        return factor_type(1);
      }
     };
     case 4:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(0);
       case 1:
        return factor_type(1);
       case 2:
        return factor_type(-6);
       case 3:
        return factor_type(15);
       case 4:
        return factor_type(-20);
       case 5:
        return factor_type(15);
       case 6:
        return factor_type(-6);
       case 7:
        return factor_type(1);
      }
     };
     case 5:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-1);
       case 1:
        return factor_type(8);
       case 2:
        return factor_type(-27);
       case 3:
        return factor_type(50);
       case 4:
        return factor_type(-55);
       case 5:
        return factor_type(36);
       case 6:
        return factor_type(-13);
       case 7:
        return factor_type(2);
      }
     };
     case 6:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-2);
       case 1:
        return factor_type(15);
       case 2:
        return factor_type(-48);
       case 3:
        return factor_type(85);
       case 4:
        return factor_type(-90);
       case 5:
        return factor_type(57);
       case 6:
        return factor_type(-20);
       case 7:
        return factor_type(3);
      }
     };
     case 7:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-3);
       case 1:
        return factor_type(22);
       case 2:
        return factor_type(-69);
       case 3:
        return factor_type(120);
       case 4:
        return factor_type(-125);
       case 5:
        return factor_type(78);
       case 6:
        return factor_type(-27);
       case 7:
        return factor_type(4);
      }
     };
    }
  }
  CUDA_HOS_DEV static constexpr factor_type factor()
  {
    return factor_type(1);
  }
};

template<class indexer, class factor_type> struct
fin_diff_coeffs <indexer, factor_type, 6, 9>
{
  CUDA_HOS_DEV static constexpr bool valid()
  {
    return true;
  }
  CUDA_HOS_DEV static constexpr factor_type coeffs(const indexer i, const indexer offset = 0)
  {
    switch(offset)
    {
     default:
       return factor_type(0);
     case 0:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(39);
       case 1:
        return factor_type(-292);
       case 2:
        return factor_type(956);
       case 3:
        return factor_type(-1788);
       case 4:
        return factor_type(2090);
       case 5:
        return factor_type(-1564);
       case 6:
        return factor_type(732);
       case 7:
        return factor_type(-196);
       case 8:
        return factor_type(23);
      }
     };
     case 1:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(23);
       case 1:
        return factor_type(-168);
       case 2:
        return factor_type(536);
       case 3:
        return factor_type(-976);
       case 4:
        return factor_type(1110);
       case 5:
        return factor_type(-808);
       case 6:
        return factor_type(368);
       case 7:
        return factor_type(-96);
       case 8:
        return factor_type(11);
      }
     };
     case 2:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(11);
       case 1:
        return factor_type(-76);
       case 2:
        return factor_type(228);
       case 3:
        return factor_type(-388);
       case 4:
        return factor_type(410);
       case 5:
        return factor_type(-276);
       case 6:
        return factor_type(116);
       case 7:
        return factor_type(-28);
       case 8:
        return factor_type(3);
      }
     };
     case 3:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(3);
       case 1:
        return factor_type(-16);
       case 2:
        return factor_type(32);
       case 3:
        return factor_type(-24);
       case 4:
        return factor_type(-10);
       case 5:
        return factor_type(32);
       case 6:
        return factor_type(-24);
       case 7:
        return factor_type(8);
       case 8:
        return factor_type(-1);
      }
     };
     case 4:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-1);
       case 1:
        return factor_type(12);
       case 2:
        return factor_type(-52);
       case 3:
        return factor_type(116);
       case 4:
        return factor_type(-150);
       case 5:
        return factor_type(116);
       case 6:
        return factor_type(-52);
       case 7:
        return factor_type(12);
       case 8:
        return factor_type(-1);
      }
     };
     case 5:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-1);
       case 1:
        return factor_type(8);
       case 2:
        return factor_type(-24);
       case 3:
        return factor_type(32);
       case 4:
        return factor_type(-10);
       case 5:
        return factor_type(-24);
       case 6:
        return factor_type(32);
       case 7:
        return factor_type(-16);
       case 8:
        return factor_type(3);
      }
     };
     case 6:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(3);
       case 1:
        return factor_type(-28);
       case 2:
        return factor_type(116);
       case 3:
        return factor_type(-276);
       case 4:
        return factor_type(410);
       case 5:
        return factor_type(-388);
       case 6:
        return factor_type(228);
       case 7:
        return factor_type(-76);
       case 8:
        return factor_type(11);
      }
     };
     case 7:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(11);
       case 1:
        return factor_type(-96);
       case 2:
        return factor_type(368);
       case 3:
        return factor_type(-808);
       case 4:
        return factor_type(1110);
       case 5:
        return factor_type(-976);
       case 6:
        return factor_type(536);
       case 7:
        return factor_type(-168);
       case 8:
        return factor_type(23);
      }
     };
     case 8:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(23);
       case 1:
        return factor_type(-196);
       case 2:
        return factor_type(732);
       case 3:
        return factor_type(-1564);
       case 4:
        return factor_type(2090);
       case 5:
        return factor_type(-1788);
       case 6:
        return factor_type(956);
       case 7:
        return factor_type(-292);
       case 8:
        return factor_type(39);
      }
     };
    }
  }
  CUDA_HOS_DEV static constexpr factor_type factor()
  {
    return factor_type(4);
  }
};

template<class indexer, class factor_type> struct
fin_diff_coeffs <indexer, factor_type, 6, 10>
{
  CUDA_HOS_DEV static constexpr bool valid()
  {
    return true;
  }
  CUDA_HOS_DEV static constexpr factor_type coeffs(const indexer i, const indexer offset = 0)
  {
    switch(offset)
    {
     default:
       return factor_type(0);
     case 0:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(75);
       case 1:
        return factor_type(-616);
       case 2:
        return factor_type(2252);
       case 3:
        return factor_type(-4812);
       case 4:
        return factor_type(6626);
       case 5:
        return factor_type(-6100);
       case 6:
        return factor_type(3756);
       case 7:
        return factor_type(-1492);
       case 8:
        return factor_type(347);
       case 9:
        return factor_type(-36);
      }
     };
     case 1:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(36);
       case 1:
        return factor_type(-285);
       case 2:
        return factor_type(1004);
       case 3:
        return factor_type(-2068);
       case 4:
        return factor_type(2748);
       case 5:
        return factor_type(-2446);
       case 6:
        return factor_type(1460);
       case 7:
        return factor_type(-564);
       case 8:
        return factor_type(128);
       case 9:
        return factor_type(-13);
      }
     };
     case 2:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(13);
       case 1:
        return factor_type(-94);
       case 2:
        return factor_type(300);
       case 3:
        return factor_type(-556);
       case 4:
        return factor_type(662);
       case 5:
        return factor_type(-528);
       case 6:
        return factor_type(284);
       case 7:
        return factor_type(-100);
       case 8:
        return factor_type(21);
       case 9:
        return factor_type(-2);
      }
     };
     case 3:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(2);
       case 1:
        return factor_type(-7);
       case 2:
        return factor_type(-4);
       case 3:
        return factor_type(60);
       case 4:
        return factor_type(-136);
       case 5:
        return factor_type(158);
       case 6:
        return factor_type(-108);
       case 7:
        return factor_type(44);
       case 8:
        return factor_type(-10);
       case 9:
        return factor_type(1);
      }
     };
     case 4:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-1);
       case 1:
        return factor_type(12);
       case 2:
        return factor_type(-52);
       case 3:
        return factor_type(116);
       case 4:
        return factor_type(-150);
       case 5:
        return factor_type(116);
       case 6:
        return factor_type(-52);
       case 7:
        return factor_type(12);
       case 8:
        return factor_type(-1);
      }
     };
     case 5:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(0);
       case 1:
        return factor_type(-1);
       case 2:
        return factor_type(12);
       case 3:
        return factor_type(-52);
       case 4:
        return factor_type(116);
       case 5:
        return factor_type(-150);
       case 6:
        return factor_type(116);
       case 7:
        return factor_type(-52);
       case 8:
        return factor_type(12);
       case 9:
        return factor_type(-1);
      }
     };
     case 6:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(1);
       case 1:
        return factor_type(-10);
       case 2:
        return factor_type(44);
       case 3:
        return factor_type(-108);
       case 4:
        return factor_type(158);
       case 5:
        return factor_type(-136);
       case 6:
        return factor_type(60);
       case 7:
        return factor_type(-4);
       case 8:
        return factor_type(-7);
       case 9:
        return factor_type(2);
      }
     };
     case 7:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-2);
       case 1:
        return factor_type(21);
       case 2:
        return factor_type(-100);
       case 3:
        return factor_type(284);
       case 4:
        return factor_type(-528);
       case 5:
        return factor_type(662);
       case 6:
        return factor_type(-556);
       case 7:
        return factor_type(300);
       case 8:
        return factor_type(-94);
       case 9:
        return factor_type(13);
      }
     };
     case 8:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-13);
       case 1:
        return factor_type(128);
       case 2:
        return factor_type(-564);
       case 3:
        return factor_type(1460);
       case 4:
        return factor_type(-2446);
       case 5:
        return factor_type(2748);
       case 6:
        return factor_type(-2068);
       case 7:
        return factor_type(1004);
       case 8:
        return factor_type(-285);
       case 9:
        return factor_type(36);
      }
     };
     case 9:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-36);
       case 1:
        return factor_type(347);
       case 2:
        return factor_type(-1492);
       case 3:
        return factor_type(3756);
       case 4:
        return factor_type(-6100);
       case 5:
        return factor_type(6626);
       case 6:
        return factor_type(-4812);
       case 7:
        return factor_type(2252);
       case 8:
        return factor_type(-616);
       case 9:
        return factor_type(75);
      }
     };
    }
  }
  CUDA_HOS_DEV static constexpr factor_type factor()
  {
    return factor_type(4);
  }
};

template<class indexer, class factor_type> struct
fin_diff_coeffs <indexer, factor_type, 6, 11>
{
  CUDA_HOS_DEV static constexpr bool valid()
  {
    return true;
  }
  CUDA_HOS_DEV static constexpr factor_type coeffs(const indexer i, const indexer offset = 0)
  {
    switch(offset)
    {
     default:
       return factor_type(0);
     case 0:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(7513);
       case 1:
        return factor_type(-67090);
       case 2:
        return factor_type(270705);
       case 3:
        return factor_type(-650280);
       case 4:
        return factor_type(1030290);
       case 5:
        return factor_type(-1125276);
       case 6:
        return factor_type(858090);
       case 7:
        return factor_type(-451080);
       case 8:
        return factor_type(156405);
       case 9:
        return factor_type(-32290);
       case 10:
        return factor_type(3013);
      }
     };
     case 1:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(3013);
       case 1:
        return factor_type(-25630);
       case 2:
        return factor_type(98625);
       case 3:
        return factor_type(-226440);
       case 4:
        return factor_type(344010);
       case 5:
        return factor_type(-361716);
       case 6:
        return factor_type(266730);
       case 7:
        return factor_type(-136200);
       case 8:
        return factor_type(46065);
       case 9:
        return factor_type(-9310);
       case 10:
        return factor_type(853);
      }
     };
     case 2:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(853);
       case 1:
        return factor_type(-6370);
       case 2:
        return factor_type(21285);
       case 3:
        return factor_type(-42120);
       case 4:
        return factor_type(55050);
       case 5:
        return factor_type(-50076);
       case 6:
        return factor_type(32370);
       case 7:
        return factor_type(-14760);
       case 8:
        return factor_type(4545);
       case 9:
        return factor_type(-850);
       case 10:
        return factor_type(73);
      }
     };
     case 3:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(73);
       case 1:
        return factor_type(50);
       case 2:
        return factor_type(-2355);
       case 3:
        return factor_type(9240);
       case 4:
        return factor_type(-18030);
       case 5:
        return factor_type(21324);
       case 6:
        return factor_type(-16350);
       case 7:
        return factor_type(8280);
       case 8:
        return factor_type(-2715);
       case 9:
        return factor_type(530);
       case 10:
        return factor_type(-47);
      }
     };
     case 4:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-47);
       case 1:
        return factor_type(590);
       case 2:
        return factor_type(-2535);
       case 3:
        return factor_type(5400);
       case 4:
        return factor_type(-6270);
       case 5:
        return factor_type(3684);
       case 6:
        return factor_type(-390);
       case 7:
        return factor_type(-840);
       case 8:
        return factor_type(525);
       case 9:
        return factor_type(-130);
       case 10:
        return factor_type(13);
      }
     };
     case 5:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(13);
       case 1:
        return factor_type(-190);
       case 2:
        return factor_type(1305);
       case 3:
        return factor_type(-4680);
       case 4:
        return factor_type(9690);
       case 5:
        return factor_type(-12276);
       case 6:
        return factor_type(9690);
       case 7:
        return factor_type(-4680);
       case 8:
        return factor_type(1305);
       case 9:
        return factor_type(-190);
       case 10:
        return factor_type(13);
      }
     };
     case 6:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(13);
       case 1:
        return factor_type(-130);
       case 2:
        return factor_type(525);
       case 3:
        return factor_type(-840);
       case 4:
        return factor_type(-390);
       case 5:
        return factor_type(3684);
       case 6:
        return factor_type(-6270);
       case 7:
        return factor_type(5400);
       case 8:
        return factor_type(-2535);
       case 9:
        return factor_type(590);
       case 10:
        return factor_type(-47);
      }
     };
     case 7:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-47);
       case 1:
        return factor_type(530);
       case 2:
        return factor_type(-2715);
       case 3:
        return factor_type(8280);
       case 4:
        return factor_type(-16350);
       case 5:
        return factor_type(21324);
       case 6:
        return factor_type(-18030);
       case 7:
        return factor_type(9240);
       case 8:
        return factor_type(-2355);
       case 9:
        return factor_type(50);
       case 10:
        return factor_type(73);
      }
     };
     case 8:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(73);
       case 1:
        return factor_type(-850);
       case 2:
        return factor_type(4545);
       case 3:
        return factor_type(-14760);
       case 4:
        return factor_type(32370);
       case 5:
        return factor_type(-50076);
       case 6:
        return factor_type(55050);
       case 7:
        return factor_type(-42120);
       case 8:
        return factor_type(21285);
       case 9:
        return factor_type(-6370);
       case 10:
        return factor_type(853);
      }
     };
     case 9:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(853);
       case 1:
        return factor_type(-9310);
       case 2:
        return factor_type(46065);
       case 3:
        return factor_type(-136200);
       case 4:
        return factor_type(266730);
       case 5:
        return factor_type(-361716);
       case 6:
        return factor_type(344010);
       case 7:
        return factor_type(-226440);
       case 8:
        return factor_type(98625);
       case 9:
        return factor_type(-25630);
       case 10:
        return factor_type(3013);
      }
     };
     case 10:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(3013);
       case 1:
        return factor_type(-32290);
       case 2:
        return factor_type(156405);
       case 3:
        return factor_type(-451080);
       case 4:
        return factor_type(858090);
       case 5:
        return factor_type(-1125276);
       case 6:
        return factor_type(1030290);
       case 7:
        return factor_type(-650280);
       case 8:
        return factor_type(270705);
       case 9:
        return factor_type(-67090);
       case 10:
        return factor_type(7513);
      }
     };
    }
  }
  CUDA_HOS_DEV static constexpr factor_type factor()
  {
    return factor_type(240);
  }
};

template<class indexer, class factor_type> struct
fin_diff_coeffs <indexer, factor_type, 6, 12>
{
  CUDA_HOS_DEV static constexpr bool valid()
  {
    return true;
  }
  CUDA_HOS_DEV static constexpr factor_type coeffs(const indexer i, const indexer offset = 0)
  {
    switch(offset)
    {
     default:
       return factor_type(0);
     case 0:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(11418);
       case 1:
        return factor_type(-110045);
       case 2:
        return factor_type(485480);
       case 3:
        return factor_type(-1294605);
       case 4:
        return factor_type(2318940);
       case 5:
        return factor_type(-2929386);
       case 6:
        return factor_type(2662200);
       case 7:
        return factor_type(-1739730);
       case 8:
        return factor_type(800730);
       case 9:
        return factor_type(-247065);
       case 10:
        return factor_type(45968);
       case 11:
        return factor_type(-3905);
      }
     };
     case 1:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(3905);
       case 1:
        return factor_type(-35442);
       case 2:
        return factor_type(147685);
       case 3:
        return factor_type(-373620);
       case 4:
        return factor_type(638370);
       case 5:
        return factor_type(-773820);
       case 6:
        return factor_type(678834);
       case 7:
        return factor_type(-430560);
       case 8:
        return factor_type(193245);
       case 9:
        return factor_type(-58370);
       case 10:
        return factor_type(10665);
       case 11:
        return factor_type(-892);
      }
     };
     case 2:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(892);
       case 1:
        return factor_type(-6799);
       case 2:
        return factor_type(23430);
       case 3:
        return factor_type(-48555);
       case 4:
        return factor_type(67920);
       case 5:
        return factor_type(-68094);
       case 6:
        return factor_type(50388);
       case 7:
        return factor_type(-27630);
       case 8:
        return factor_type(10980);
       case 9:
        return factor_type(-2995);
       case 10:
        return factor_type(502);
       case 11:
        return factor_type(-39);
      }
     };
     case 3:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(39);
       case 1:
        return factor_type(424);
       case 2:
        return factor_type(-4225);
       case 3:
        return factor_type(14850);
       case 4:
        return factor_type(-29250);
       case 5:
        return factor_type(37032);
       case 6:
        return factor_type(-32058);
       case 7:
        return factor_type(19500);
       case 8:
        return factor_type(-8325);
       case 9:
        return factor_type(2400);
       case 10:
        return factor_type(-421);
       case 11:
        return factor_type(34);
      }
     };
     case 4:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-34);
       case 1:
        return factor_type(447);
       case 2:
        return factor_type(-1820);
       case 3:
        return factor_type(3255);
       case 4:
        return factor_type(-1980);
       case 5:
        return factor_type(-2322);
       case 6:
        return factor_type(5616);
       case 7:
        return factor_type(-5130);
       case 8:
        return factor_type(2670);
       case 9:
        return factor_type(-845);
       case 10:
        return factor_type(156);
       case 11:
        return factor_type(-13);
      }
     };
     case 5:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(13);
       case 1:
        return factor_type(-190);
       case 2:
        return factor_type(1305);
       case 3:
        return factor_type(-4680);
       case 4:
        return factor_type(9690);
       case 5:
        return factor_type(-12276);
       case 6:
        return factor_type(9690);
       case 7:
        return factor_type(-4680);
       case 8:
        return factor_type(1305);
       case 9:
        return factor_type(-190);
       case 10:
        return factor_type(13);
      }
     };
     case 6:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(0);
       case 1:
        return factor_type(13);
       case 2:
        return factor_type(-190);
       case 3:
        return factor_type(1305);
       case 4:
        return factor_type(-4680);
       case 5:
        return factor_type(9690);
       case 6:
        return factor_type(-12276);
       case 7:
        return factor_type(9690);
       case 8:
        return factor_type(-4680);
       case 9:
        return factor_type(1305);
       case 10:
        return factor_type(-190);
       case 11:
        return factor_type(13);
      }
     };
     case 7:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-13);
       case 1:
        return factor_type(156);
       case 2:
        return factor_type(-845);
       case 3:
        return factor_type(2670);
       case 4:
        return factor_type(-5130);
       case 5:
        return factor_type(5616);
       case 6:
        return factor_type(-2322);
       case 7:
        return factor_type(-1980);
       case 8:
        return factor_type(3255);
       case 9:
        return factor_type(-1820);
       case 10:
        return factor_type(447);
       case 11:
        return factor_type(-34);
      }
     };
     case 8:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(34);
       case 1:
        return factor_type(-421);
       case 2:
        return factor_type(2400);
       case 3:
        return factor_type(-8325);
       case 4:
        return factor_type(19500);
       case 5:
        return factor_type(-32058);
       case 6:
        return factor_type(37032);
       case 7:
        return factor_type(-29250);
       case 8:
        return factor_type(14850);
       case 9:
        return factor_type(-4225);
       case 10:
        return factor_type(424);
       case 11:
        return factor_type(39);
      }
     };
     case 9:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-39);
       case 1:
        return factor_type(502);
       case 2:
        return factor_type(-2995);
       case 3:
        return factor_type(10980);
       case 4:
        return factor_type(-27630);
       case 5:
        return factor_type(50388);
       case 6:
        return factor_type(-68094);
       case 7:
        return factor_type(67920);
       case 8:
        return factor_type(-48555);
       case 9:
        return factor_type(23430);
       case 10:
        return factor_type(-6799);
       case 11:
        return factor_type(892);
      }
     };
     case 10:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-892);
       case 1:
        return factor_type(10665);
       case 2:
        return factor_type(-58370);
       case 3:
        return factor_type(193245);
       case 4:
        return factor_type(-430560);
       case 5:
        return factor_type(678834);
       case 6:
        return factor_type(-773820);
       case 7:
        return factor_type(638370);
       case 8:
        return factor_type(-373620);
       case 9:
        return factor_type(147685);
       case 10:
        return factor_type(-35442);
       case 11:
        return factor_type(3905);
      }
     };
     case 11:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-3905);
       case 1:
        return factor_type(45968);
       case 2:
        return factor_type(-247065);
       case 3:
        return factor_type(800730);
       case 4:
        return factor_type(-1739730);
       case 5:
        return factor_type(2662200);
       case 6:
        return factor_type(-2929386);
       case 7:
        return factor_type(2318940);
       case 8:
        return factor_type(-1294605);
       case 9:
        return factor_type(485480);
       case 10:
        return factor_type(-110045);
       case 11:
        return factor_type(11418);
      }
     };
    }
  }
  CUDA_HOS_DEV static constexpr factor_type factor()
  {
    return factor_type(240);
  }
};

template<class indexer, class factor_type> struct
fin_diff_coeffs <indexer, factor_type, 6, 13>
{
  CUDA_HOS_DEV static constexpr bool valid()
  {
    return true;
  }
  CUDA_HOS_DEV static constexpr factor_type coeffs(const indexer i, const indexer offset = 0)
  {
    switch(offset)
    {
     default:
       return factor_type(0);
     case 0:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(4090021);
       case 1:
        return factor_type(-42283560);
       case 2:
        return factor_type(202378170);
       case 3:
        return factor_type(-593031160);
       case 4:
        return factor_type(1184651955);
       case 5:
        return factor_type(-1698651792);
       case 6:
        return factor_type(1791395340);
       case 7:
        return factor_type(-1398858480);
       case 8:
        return factor_type(802063035);
       case 9:
        return factor_type(-329051080);
       case 10:
        return factor_type(91621146);
       case 11:
        return factor_type(-15536280);
       case 12:
        return factor_type(1212685);
      }
     };
     case 1:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(1212685);
       case 1:
        return factor_type(-11674884);
       case 2:
        return factor_type(52305870);
       case 3:
        return factor_type(-144449740);
       case 4:
        return factor_type(274038615);
       case 5:
        return factor_type(-376073640);
       case 6:
        return factor_type(382315668);
       case 7:
        return factor_type(-289572120);
       case 8:
        return factor_type(161867115);
       case 9:
        return factor_type(-65006740);
       case 10:
        return factor_type(17776830);
       case 11:
        return factor_type(-2968284);
       case 12:
        return factor_type(228625);
      }
     };
     case 2:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(228625);
       case 1:
        return factor_type(-1759440);
       case 2:
        return factor_type(6157866);
       case 3:
        return factor_type(-13080880);
       case 4:
        return factor_type(19017135);
       case 5:
        return factor_type(-20201760);
       case 6:
        return factor_type(16246860);
       case 7:
        return factor_type(-10004832);
       case 8:
        return factor_type(4668255);
       case 9:
        return factor_type(-1599760);
       case 10:
        return factor_type(380010);
       case 11:
        return factor_type(-55920);
       case 12:
        return factor_type(3841);
      }
     };
     case 3:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(3841);
       case 1:
        return factor_type(178692);
       case 2:
        return factor_type(-1459842);
       case 3:
        return factor_type(5059340);
       case 4:
        return factor_type(-10334565);
       case 5:
        return factor_type(14073768);
       case 6:
        return factor_type(-13610604);
       case 7:
        return factor_type(9655704);
       case 8:
        return factor_type(-5061465);
       case 9:
        return factor_type(1921940);
       case 10:
        return factor_type(-501234);
       case 11:
        return factor_type(80412);
       case 12:
        return factor_type(-5987);
      }
     };
     case 4:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-5987);
       case 1:
        return factor_type(81672);
       case 2:
        return factor_type(-288294);
       case 3:
        return factor_type(252440);
       case 4:
        return factor_type(778635);
       case 5:
        return factor_type(-2629296);
       case 6:
        return factor_type(3800076);
       case 7:
        return factor_type(-3336912);
       case 8:
        return factor_type(1950435);
       case 9:
        return factor_type(-780760);
       case 10:
        return factor_type(209658);
       case 11:
        return factor_type(-34248);
       case 12:
        return factor_type(2581);
      }
     };
     case 5:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(2581);
       case 1:
        return factor_type(-39540);
       case 2:
        return factor_type(282990);
       case 3:
        return factor_type(-1026460);
       case 4:
        return factor_type(2097855);
       case 5:
        return factor_type(-2543112);
       case 6:
        return factor_type(1799700);
       case 7:
        return factor_type(-628920);
       case 8:
        return factor_type(-15165);
       case 9:
        return factor_type(105020);
       case 10:
        return factor_type(-42594);
       case 11:
        return factor_type(8340);
       case 12:
        return factor_type(-695);
      }
     };
     case 6:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-695);
       case 1:
        return factor_type(11616);
       case 2:
        return factor_type(-93750);
       case 3:
        return factor_type(481760);
       case 4:
        return factor_type(-1523385);
       case 5:
        return factor_type(2992320);
       case 6:
        return factor_type(-3735732);
       case 7:
        return factor_type(2992320);
       case 8:
        return factor_type(-1523385);
       case 9:
        return factor_type(481760);
       case 10:
        return factor_type(-93750);
       case 11:
        return factor_type(11616);
       case 12:
        return factor_type(-695);
      }
     };
     case 7:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-695);
       case 1:
        return factor_type(8340);
       case 2:
        return factor_type(-42594);
       case 3:
        return factor_type(105020);
       case 4:
        return factor_type(-15165);
       case 5:
        return factor_type(-628920);
       case 6:
        return factor_type(1799700);
       case 7:
        return factor_type(-2543112);
       case 8:
        return factor_type(2097855);
       case 9:
        return factor_type(-1026460);
       case 10:
        return factor_type(282990);
       case 11:
        return factor_type(-39540);
       case 12:
        return factor_type(2581);
      }
     };
     case 8:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(2581);
       case 1:
        return factor_type(-34248);
       case 2:
        return factor_type(209658);
       case 3:
        return factor_type(-780760);
       case 4:
        return factor_type(1950435);
       case 5:
        return factor_type(-3336912);
       case 6:
        return factor_type(3800076);
       case 7:
        return factor_type(-2629296);
       case 8:
        return factor_type(778635);
       case 9:
        return factor_type(252440);
       case 10:
        return factor_type(-288294);
       case 11:
        return factor_type(81672);
       case 12:
        return factor_type(-5987);
      }
     };
     case 9:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-5987);
       case 1:
        return factor_type(80412);
       case 2:
        return factor_type(-501234);
       case 3:
        return factor_type(1921940);
       case 4:
        return factor_type(-5061465);
       case 5:
        return factor_type(9655704);
       case 6:
        return factor_type(-13610604);
       case 7:
        return factor_type(14073768);
       case 8:
        return factor_type(-10334565);
       case 9:
        return factor_type(5059340);
       case 10:
        return factor_type(-1459842);
       case 11:
        return factor_type(178692);
       case 12:
        return factor_type(3841);
      }
     };
     case 10:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(3841);
       case 1:
        return factor_type(-55920);
       case 2:
        return factor_type(380010);
       case 3:
        return factor_type(-1599760);
       case 4:
        return factor_type(4668255);
       case 5:
        return factor_type(-10004832);
       case 6:
        return factor_type(16246860);
       case 7:
        return factor_type(-20201760);
       case 8:
        return factor_type(19017135);
       case 9:
        return factor_type(-13080880);
       case 10:
        return factor_type(6157866);
       case 11:
        return factor_type(-1759440);
       case 12:
        return factor_type(228625);
      }
     };
     case 11:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(228625);
       case 1:
        return factor_type(-2968284);
       case 2:
        return factor_type(17776830);
       case 3:
        return factor_type(-65006740);
       case 4:
        return factor_type(161867115);
       case 5:
        return factor_type(-289572120);
       case 6:
        return factor_type(382315668);
       case 7:
        return factor_type(-376073640);
       case 8:
        return factor_type(274038615);
       case 9:
        return factor_type(-144449740);
       case 10:
        return factor_type(52305870);
       case 11:
        return factor_type(-11674884);
       case 12:
        return factor_type(1212685);
      }
     };
     case 12:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(1212685);
       case 1:
        return factor_type(-15536280);
       case 2:
        return factor_type(91621146);
       case 3:
        return factor_type(-329051080);
       case 4:
        return factor_type(802063035);
       case 5:
        return factor_type(-1398858480);
       case 6:
        return factor_type(1791395340);
       case 7:
        return factor_type(-1698651792);
       case 8:
        return factor_type(1184651955);
       case 9:
        return factor_type(-593031160);
       case 10:
        return factor_type(202378170);
       case 11:
        return factor_type(-42283560);
       case 12:
        return factor_type(4090021);
      }
     };
    }
  }
  CUDA_HOS_DEV static constexpr factor_type factor()
  {
    return factor_type(60480);
  }
};

template<class indexer, class factor_type> struct
fin_diff_coeffs <indexer, factor_type, 6, 14>
{
  CUDA_HOS_DEV static constexpr bool valid()
  {
    return true;
  }
  CUDA_HOS_DEV static constexpr factor_type coeffs(const indexer i, const indexer offset = 0)
  {
    switch(offset)
    {
     default:
       return factor_type(0);
     case 0:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(5531071);
       case 1:
        return factor_type(-61017210);
       case 2:
        return factor_type(314780070);
       case 3:
        return factor_type(-1005171460);
       case 4:
        return factor_type(2215002705);
       case 5:
        return factor_type(-3553283142);
       case 6:
        return factor_type(4264237140);
       case 7:
        return factor_type(-3871700280);
       case 8:
        return factor_type(2656694385);
       case 9:
        return factor_type(-1359401830);
       case 10:
        return factor_type(503761446);
       case 11:
        return factor_type(-127938180);
       case 12:
        return factor_type(19946335);
       case 13:
        return factor_type(-1441050);
      }
     };
     case 1:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(1441050);
       case 1:
        return factor_type(-14643629);
       case 2:
        return factor_type(70118340);
       case 3:
        return factor_type(-209762130);
       case 4:
        return factor_type(437319590);
       case 5:
        return factor_type(-669979395);
       case 6:
        return factor_type(774190008);
       case 7:
        return factor_type(-681446460);
       case 8:
        return factor_type(455772870);
       case 9:
        return factor_type(-228287715);
       case 10:
        return factor_type(83089220);
       case 11:
        return factor_type(-20780754);
       case 12:
        return factor_type(3197370);
       case 13:
        return factor_type(-228365);
      }
     };
     case 2:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(228365);
       case 1:
        return factor_type(-1756060);
       case 2:
        return factor_type(6137586);
       case 3:
        return factor_type(-13006520);
       case 4:
        return factor_type(18831235);
       case 5:
        return factor_type(-19867140);
       case 6:
        return factor_type(15800700);
       case 7:
        return factor_type(-9558672);
       case 8:
        return factor_type(4333635);
       case 9:
        return factor_type(-1413860);
       case 10:
        return factor_type(305650);
       case 11:
        return factor_type(-35640);
       case 12:
        return factor_type(461);
       case 13:
        return factor_type(260);
      }
     };
     case 3:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-260);
       case 1:
        return factor_type(232005);
       case 2:
        return factor_type(-1779720);
       case 3:
        return factor_type(6232226);
       case 4:
        return factor_type(-13266780);
       case 5:
        return factor_type(19351755);
       case 6:
        return factor_type(-20647920);
       case 7:
        return factor_type(16693020);
       case 8:
        return factor_type(-10339452);
       case 9:
        return factor_type(4854155);
       case 10:
        return factor_type(-1674120);
       case 11:
        return factor_type(400290);
       case 12:
        return factor_type(-59300);
       case 13:
        return factor_type(4101);
      }
     };
     case 4:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-4101);
       case 1:
        return factor_type(57154);
       case 2:
        return factor_type(-141186);
       case 3:
        return factor_type(-286956);
       case 4:
        return factor_type(2127125);
       case 5:
        return factor_type(-5056578);
       case 6:
        return factor_type(7036452);
       case 7:
        return factor_type(-6573288);
       case 8:
        return factor_type(4377717);
       case 9:
        return factor_type(-2129250);
       case 10:
        return factor_type(749054);
       case 11:
        return factor_type(-181356);
       case 12:
        return factor_type(27099);
       case 13:
        return factor_type(-1886);
      }
     };
     case 5:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(1886);
       case 1:
        return factor_type(-30505);
       case 2:
        return factor_type(228780);
       case 3:
        return factor_type(-827690);
       case 4:
        return factor_type(1600930);
       case 5:
        return factor_type(-1648647);
       case 6:
        return factor_type(607080);
       case 7:
        return factor_type(563700);
       case 8:
        return factor_type(-909630);
       case 9:
        return factor_type(601945);
       case 10:
        return factor_type(-241364);
       case 11:
        return factor_type(62550);
       case 12:
        return factor_type(-9730);
       case 13:
        return factor_type(695);
      }
     };
     case 6:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-695);
       case 1:
        return factor_type(11616);
       case 2:
        return factor_type(-93750);
       case 3:
        return factor_type(481760);
       case 4:
        return factor_type(-1523385);
       case 5:
        return factor_type(2992320);
       case 6:
        return factor_type(-3735732);
       case 7:
        return factor_type(2992320);
       case 8:
        return factor_type(-1523385);
       case 9:
        return factor_type(481760);
       case 10:
        return factor_type(-93750);
       case 11:
        return factor_type(11616);
       case 12:
        return factor_type(-695);
      }
     };
     case 7:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(0);
       case 1:
        return factor_type(-695);
       case 2:
        return factor_type(11616);
       case 3:
        return factor_type(-93750);
       case 4:
        return factor_type(481760);
       case 5:
        return factor_type(-1523385);
       case 6:
        return factor_type(2992320);
       case 7:
        return factor_type(-3735732);
       case 8:
        return factor_type(2992320);
       case 9:
        return factor_type(-1523385);
       case 10:
        return factor_type(481760);
       case 11:
        return factor_type(-93750);
       case 12:
        return factor_type(11616);
       case 13:
        return factor_type(-695);
      }
     };
     case 8:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(695);
       case 1:
        return factor_type(-9730);
       case 2:
        return factor_type(62550);
       case 3:
        return factor_type(-241364);
       case 4:
        return factor_type(601945);
       case 5:
        return factor_type(-909630);
       case 6:
        return factor_type(563700);
       case 7:
        return factor_type(607080);
       case 8:
        return factor_type(-1648647);
       case 9:
        return factor_type(1600930);
       case 10:
        return factor_type(-827690);
       case 11:
        return factor_type(228780);
       case 12:
        return factor_type(-30505);
       case 13:
        return factor_type(1886);
      }
     };
     case 9:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-1886);
       case 1:
        return factor_type(27099);
       case 2:
        return factor_type(-181356);
       case 3:
        return factor_type(749054);
       case 4:
        return factor_type(-2129250);
       case 5:
        return factor_type(4377717);
       case 6:
        return factor_type(-6573288);
       case 7:
        return factor_type(7036452);
       case 8:
        return factor_type(-5056578);
       case 9:
        return factor_type(2127125);
       case 10:
        return factor_type(-286956);
       case 11:
        return factor_type(-141186);
       case 12:
        return factor_type(57154);
       case 13:
        return factor_type(-4101);
      }
     };
     case 10:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(4101);
       case 1:
        return factor_type(-59300);
       case 2:
        return factor_type(400290);
       case 3:
        return factor_type(-1674120);
       case 4:
        return factor_type(4854155);
       case 5:
        return factor_type(-10339452);
       case 6:
        return factor_type(16693020);
       case 7:
        return factor_type(-20647920);
       case 8:
        return factor_type(19351755);
       case 9:
        return factor_type(-13266780);
       case 10:
        return factor_type(6232226);
       case 11:
        return factor_type(-1779720);
       case 12:
        return factor_type(232005);
       case 13:
        return factor_type(-260);
      }
     };
     case 11:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(260);
       case 1:
        return factor_type(461);
       case 2:
        return factor_type(-35640);
       case 3:
        return factor_type(305650);
       case 4:
        return factor_type(-1413860);
       case 5:
        return factor_type(4333635);
       case 6:
        return factor_type(-9558672);
       case 7:
        return factor_type(15800700);
       case 8:
        return factor_type(-19867140);
       case 9:
        return factor_type(18831235);
       case 10:
        return factor_type(-13006520);
       case 11:
        return factor_type(6137586);
       case 12:
        return factor_type(-1756060);
       case 13:
        return factor_type(228365);
      }
     };
     case 12:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-228365);
       case 1:
        return factor_type(3197370);
       case 2:
        return factor_type(-20780754);
       case 3:
        return factor_type(83089220);
       case 4:
        return factor_type(-228287715);
       case 5:
        return factor_type(455772870);
       case 6:
        return factor_type(-681446460);
       case 7:
        return factor_type(774190008);
       case 8:
        return factor_type(-669979395);
       case 9:
        return factor_type(437319590);
       case 10:
        return factor_type(-209762130);
       case 11:
        return factor_type(70118340);
       case 12:
        return factor_type(-14643629);
       case 13:
        return factor_type(1441050);
      }
     };
     case 13:
     {
      switch(i)
      {
       default:
        return factor_type(0);
       case 0:
        return factor_type(-1441050);
       case 1:
        return factor_type(19946335);
       case 2:
        return factor_type(-127938180);
       case 3:
        return factor_type(503761446);
       case 4:
        return factor_type(-1359401830);
       case 5:
        return factor_type(2656694385);
       case 6:
        return factor_type(-3871700280);
       case 7:
        return factor_type(4264237140);
       case 8:
        return factor_type(-3553283142);
       case 9:
        return factor_type(2215002705);
       case 10:
        return factor_type(-1005171460);
       case 11:
        return factor_type(314780070);
       case 12:
        return factor_type(-61017210);
       case 13:
        return factor_type(5531071);
      }
     };
    }
  }
  CUDA_HOS_DEV static constexpr factor_type factor()
  {
    return factor_type(60480);
  }
};
///\endcond
}
}
#endif
#ifndef G24_LIB_VAR_S_B_AUTOGEN
#define G24_LIB_VAR_S_B_AUTOGEN

///\cond HIDDEN_SYMBOLS

template <class T> struct variadic_structured_binding<T, 2>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 3>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 4>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 5>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 6>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 7>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 8>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 9>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 10>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 11>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 12>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 13>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 14>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 15>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 16>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 17>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 18>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 19>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 20>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 21>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 22>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 23>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 24>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 25>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 26>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 27>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 28>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 29>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 30>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 31>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 32>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 33>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 34>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 35>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 36>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 37>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 38>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 39>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 40>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 41>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 42>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 43>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 44>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 45>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 46>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 47>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 48>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 49>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 50>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 51>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 52>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 53>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 54>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 55>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 56>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 57>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 58>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 59>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 60>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 61>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 62>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 63>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61,
           a62    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    ret.template get<62>() = a62;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 64>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61,
           a62,
           a63    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    ret.template get<62>() = a62;
    ret.template get<63>() = a63;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 65>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61,
           a62,
           a63,
           a64    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    ret.template get<62>() = a62;
    ret.template get<63>() = a63;
    ret.template get<64>() = a64;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 66>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61,
           a62,
           a63,
           a64,
           a65    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    ret.template get<62>() = a62;
    ret.template get<63>() = a63;
    ret.template get<64>() = a64;
    ret.template get<65>() = a65;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 67>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61,
           a62,
           a63,
           a64,
           a65,
           a66    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    ret.template get<62>() = a62;
    ret.template get<63>() = a63;
    ret.template get<64>() = a64;
    ret.template get<65>() = a65;
    ret.template get<66>() = a66;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 68>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61,
           a62,
           a63,
           a64,
           a65,
           a66,
           a67    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    ret.template get<62>() = a62;
    ret.template get<63>() = a63;
    ret.template get<64>() = a64;
    ret.template get<65>() = a65;
    ret.template get<66>() = a66;
    ret.template get<67>() = a67;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 69>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61,
           a62,
           a63,
           a64,
           a65,
           a66,
           a67,
           a68    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    ret.template get<62>() = a62;
    ret.template get<63>() = a63;
    ret.template get<64>() = a64;
    ret.template get<65>() = a65;
    ret.template get<66>() = a66;
    ret.template get<67>() = a67;
    ret.template get<68>() = a68;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 70>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61,
           a62,
           a63,
           a64,
           a65,
           a66,
           a67,
           a68,
           a69    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    ret.template get<62>() = a62;
    ret.template get<63>() = a63;
    ret.template get<64>() = a64;
    ret.template get<65>() = a65;
    ret.template get<66>() = a66;
    ret.template get<67>() = a67;
    ret.template get<68>() = a68;
    ret.template get<69>() = a69;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 71>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61,
           a62,
           a63,
           a64,
           a65,
           a66,
           a67,
           a68,
           a69,
           a70    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    ret.template get<62>() = a62;
    ret.template get<63>() = a63;
    ret.template get<64>() = a64;
    ret.template get<65>() = a65;
    ret.template get<66>() = a66;
    ret.template get<67>() = a67;
    ret.template get<68>() = a68;
    ret.template get<69>() = a69;
    ret.template get<70>() = a70;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 72>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61,
           a62,
           a63,
           a64,
           a65,
           a66,
           a67,
           a68,
           a69,
           a70,
           a71    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    ret.template get<62>() = a62;
    ret.template get<63>() = a63;
    ret.template get<64>() = a64;
    ret.template get<65>() = a65;
    ret.template get<66>() = a66;
    ret.template get<67>() = a67;
    ret.template get<68>() = a68;
    ret.template get<69>() = a69;
    ret.template get<70>() = a70;
    ret.template get<71>() = a71;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 73>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61,
           a62,
           a63,
           a64,
           a65,
           a66,
           a67,
           a68,
           a69,
           a70,
           a71,
           a72    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    ret.template get<62>() = a62;
    ret.template get<63>() = a63;
    ret.template get<64>() = a64;
    ret.template get<65>() = a65;
    ret.template get<66>() = a66;
    ret.template get<67>() = a67;
    ret.template get<68>() = a68;
    ret.template get<69>() = a69;
    ret.template get<70>() = a70;
    ret.template get<71>() = a71;
    ret.template get<72>() = a72;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 74>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61,
           a62,
           a63,
           a64,
           a65,
           a66,
           a67,
           a68,
           a69,
           a70,
           a71,
           a72,
           a73    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    ret.template get<62>() = a62;
    ret.template get<63>() = a63;
    ret.template get<64>() = a64;
    ret.template get<65>() = a65;
    ret.template get<66>() = a66;
    ret.template get<67>() = a67;
    ret.template get<68>() = a68;
    ret.template get<69>() = a69;
    ret.template get<70>() = a70;
    ret.template get<71>() = a71;
    ret.template get<72>() = a72;
    ret.template get<73>() = a73;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 75>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61,
           a62,
           a63,
           a64,
           a65,
           a66,
           a67,
           a68,
           a69,
           a70,
           a71,
           a72,
           a73,
           a74    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    ret.template get<62>() = a62;
    ret.template get<63>() = a63;
    ret.template get<64>() = a64;
    ret.template get<65>() = a65;
    ret.template get<66>() = a66;
    ret.template get<67>() = a67;
    ret.template get<68>() = a68;
    ret.template get<69>() = a69;
    ret.template get<70>() = a70;
    ret.template get<71>() = a71;
    ret.template get<72>() = a72;
    ret.template get<73>() = a73;
    ret.template get<74>() = a74;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 76>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61,
           a62,
           a63,
           a64,
           a65,
           a66,
           a67,
           a68,
           a69,
           a70,
           a71,
           a72,
           a73,
           a74,
           a75    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    ret.template get<62>() = a62;
    ret.template get<63>() = a63;
    ret.template get<64>() = a64;
    ret.template get<65>() = a65;
    ret.template get<66>() = a66;
    ret.template get<67>() = a67;
    ret.template get<68>() = a68;
    ret.template get<69>() = a69;
    ret.template get<70>() = a70;
    ret.template get<71>() = a71;
    ret.template get<72>() = a72;
    ret.template get<73>() = a73;
    ret.template get<74>() = a74;
    ret.template get<75>() = a75;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 77>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61,
           a62,
           a63,
           a64,
           a65,
           a66,
           a67,
           a68,
           a69,
           a70,
           a71,
           a72,
           a73,
           a74,
           a75,
           a76    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    ret.template get<62>() = a62;
    ret.template get<63>() = a63;
    ret.template get<64>() = a64;
    ret.template get<65>() = a65;
    ret.template get<66>() = a66;
    ret.template get<67>() = a67;
    ret.template get<68>() = a68;
    ret.template get<69>() = a69;
    ret.template get<70>() = a70;
    ret.template get<71>() = a71;
    ret.template get<72>() = a72;
    ret.template get<73>() = a73;
    ret.template get<74>() = a74;
    ret.template get<75>() = a75;
    ret.template get<76>() = a76;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 78>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61,
           a62,
           a63,
           a64,
           a65,
           a66,
           a67,
           a68,
           a69,
           a70,
           a71,
           a72,
           a73,
           a74,
           a75,
           a76,
           a77    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    ret.template get<62>() = a62;
    ret.template get<63>() = a63;
    ret.template get<64>() = a64;
    ret.template get<65>() = a65;
    ret.template get<66>() = a66;
    ret.template get<67>() = a67;
    ret.template get<68>() = a68;
    ret.template get<69>() = a69;
    ret.template get<70>() = a70;
    ret.template get<71>() = a71;
    ret.template get<72>() = a72;
    ret.template get<73>() = a73;
    ret.template get<74>() = a74;
    ret.template get<75>() = a75;
    ret.template get<76>() = a76;
    ret.template get<77>() = a77;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 79>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61,
           a62,
           a63,
           a64,
           a65,
           a66,
           a67,
           a68,
           a69,
           a70,
           a71,
           a72,
           a73,
           a74,
           a75,
           a76,
           a77,
           a78    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    ret.template get<62>() = a62;
    ret.template get<63>() = a63;
    ret.template get<64>() = a64;
    ret.template get<65>() = a65;
    ret.template get<66>() = a66;
    ret.template get<67>() = a67;
    ret.template get<68>() = a68;
    ret.template get<69>() = a69;
    ret.template get<70>() = a70;
    ret.template get<71>() = a71;
    ret.template get<72>() = a72;
    ret.template get<73>() = a73;
    ret.template get<74>() = a74;
    ret.template get<75>() = a75;
    ret.template get<76>() = a76;
    ret.template get<77>() = a77;
    ret.template get<78>() = a78;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 80>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61,
           a62,
           a63,
           a64,
           a65,
           a66,
           a67,
           a68,
           a69,
           a70,
           a71,
           a72,
           a73,
           a74,
           a75,
           a76,
           a77,
           a78,
           a79    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    ret.template get<62>() = a62;
    ret.template get<63>() = a63;
    ret.template get<64>() = a64;
    ret.template get<65>() = a65;
    ret.template get<66>() = a66;
    ret.template get<67>() = a67;
    ret.template get<68>() = a68;
    ret.template get<69>() = a69;
    ret.template get<70>() = a70;
    ret.template get<71>() = a71;
    ret.template get<72>() = a72;
    ret.template get<73>() = a73;
    ret.template get<74>() = a74;
    ret.template get<75>() = a75;
    ret.template get<76>() = a76;
    ret.template get<77>() = a77;
    ret.template get<78>() = a78;
    ret.template get<79>() = a79;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 81>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61,
           a62,
           a63,
           a64,
           a65,
           a66,
           a67,
           a68,
           a69,
           a70,
           a71,
           a72,
           a73,
           a74,
           a75,
           a76,
           a77,
           a78,
           a79,
           a80    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    ret.template get<62>() = a62;
    ret.template get<63>() = a63;
    ret.template get<64>() = a64;
    ret.template get<65>() = a65;
    ret.template get<66>() = a66;
    ret.template get<67>() = a67;
    ret.template get<68>() = a68;
    ret.template get<69>() = a69;
    ret.template get<70>() = a70;
    ret.template get<71>() = a71;
    ret.template get<72>() = a72;
    ret.template get<73>() = a73;
    ret.template get<74>() = a74;
    ret.template get<75>() = a75;
    ret.template get<76>() = a76;
    ret.template get<77>() = a77;
    ret.template get<78>() = a78;
    ret.template get<79>() = a79;
    ret.template get<80>() = a80;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 82>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61,
           a62,
           a63,
           a64,
           a65,
           a66,
           a67,
           a68,
           a69,
           a70,
           a71,
           a72,
           a73,
           a74,
           a75,
           a76,
           a77,
           a78,
           a79,
           a80,
           a81    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    ret.template get<62>() = a62;
    ret.template get<63>() = a63;
    ret.template get<64>() = a64;
    ret.template get<65>() = a65;
    ret.template get<66>() = a66;
    ret.template get<67>() = a67;
    ret.template get<68>() = a68;
    ret.template get<69>() = a69;
    ret.template get<70>() = a70;
    ret.template get<71>() = a71;
    ret.template get<72>() = a72;
    ret.template get<73>() = a73;
    ret.template get<74>() = a74;
    ret.template get<75>() = a75;
    ret.template get<76>() = a76;
    ret.template get<77>() = a77;
    ret.template get<78>() = a78;
    ret.template get<79>() = a79;
    ret.template get<80>() = a80;
    ret.template get<81>() = a81;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 83>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61,
           a62,
           a63,
           a64,
           a65,
           a66,
           a67,
           a68,
           a69,
           a70,
           a71,
           a72,
           a73,
           a74,
           a75,
           a76,
           a77,
           a78,
           a79,
           a80,
           a81,
           a82    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    ret.template get<62>() = a62;
    ret.template get<63>() = a63;
    ret.template get<64>() = a64;
    ret.template get<65>() = a65;
    ret.template get<66>() = a66;
    ret.template get<67>() = a67;
    ret.template get<68>() = a68;
    ret.template get<69>() = a69;
    ret.template get<70>() = a70;
    ret.template get<71>() = a71;
    ret.template get<72>() = a72;
    ret.template get<73>() = a73;
    ret.template get<74>() = a74;
    ret.template get<75>() = a75;
    ret.template get<76>() = a76;
    ret.template get<77>() = a77;
    ret.template get<78>() = a78;
    ret.template get<79>() = a79;
    ret.template get<80>() = a80;
    ret.template get<81>() = a81;
    ret.template get<82>() = a82;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 84>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61,
           a62,
           a63,
           a64,
           a65,
           a66,
           a67,
           a68,
           a69,
           a70,
           a71,
           a72,
           a73,
           a74,
           a75,
           a76,
           a77,
           a78,
           a79,
           a80,
           a81,
           a82,
           a83    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    ret.template get<62>() = a62;
    ret.template get<63>() = a63;
    ret.template get<64>() = a64;
    ret.template get<65>() = a65;
    ret.template get<66>() = a66;
    ret.template get<67>() = a67;
    ret.template get<68>() = a68;
    ret.template get<69>() = a69;
    ret.template get<70>() = a70;
    ret.template get<71>() = a71;
    ret.template get<72>() = a72;
    ret.template get<73>() = a73;
    ret.template get<74>() = a74;
    ret.template get<75>() = a75;
    ret.template get<76>() = a76;
    ret.template get<77>() = a77;
    ret.template get<78>() = a78;
    ret.template get<79>() = a79;
    ret.template get<80>() = a80;
    ret.template get<81>() = a81;
    ret.template get<82>() = a82;
    ret.template get<83>() = a83;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 85>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61,
           a62,
           a63,
           a64,
           a65,
           a66,
           a67,
           a68,
           a69,
           a70,
           a71,
           a72,
           a73,
           a74,
           a75,
           a76,
           a77,
           a78,
           a79,
           a80,
           a81,
           a82,
           a83,
           a84    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    ret.template get<62>() = a62;
    ret.template get<63>() = a63;
    ret.template get<64>() = a64;
    ret.template get<65>() = a65;
    ret.template get<66>() = a66;
    ret.template get<67>() = a67;
    ret.template get<68>() = a68;
    ret.template get<69>() = a69;
    ret.template get<70>() = a70;
    ret.template get<71>() = a71;
    ret.template get<72>() = a72;
    ret.template get<73>() = a73;
    ret.template get<74>() = a74;
    ret.template get<75>() = a75;
    ret.template get<76>() = a76;
    ret.template get<77>() = a77;
    ret.template get<78>() = a78;
    ret.template get<79>() = a79;
    ret.template get<80>() = a80;
    ret.template get<81>() = a81;
    ret.template get<82>() = a82;
    ret.template get<83>() = a83;
    ret.template get<84>() = a84;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 86>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61,
           a62,
           a63,
           a64,
           a65,
           a66,
           a67,
           a68,
           a69,
           a70,
           a71,
           a72,
           a73,
           a74,
           a75,
           a76,
           a77,
           a78,
           a79,
           a80,
           a81,
           a82,
           a83,
           a84,
           a85    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    ret.template get<62>() = a62;
    ret.template get<63>() = a63;
    ret.template get<64>() = a64;
    ret.template get<65>() = a65;
    ret.template get<66>() = a66;
    ret.template get<67>() = a67;
    ret.template get<68>() = a68;
    ret.template get<69>() = a69;
    ret.template get<70>() = a70;
    ret.template get<71>() = a71;
    ret.template get<72>() = a72;
    ret.template get<73>() = a73;
    ret.template get<74>() = a74;
    ret.template get<75>() = a75;
    ret.template get<76>() = a76;
    ret.template get<77>() = a77;
    ret.template get<78>() = a78;
    ret.template get<79>() = a79;
    ret.template get<80>() = a80;
    ret.template get<81>() = a81;
    ret.template get<82>() = a82;
    ret.template get<83>() = a83;
    ret.template get<84>() = a84;
    ret.template get<85>() = a85;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 87>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61,
           a62,
           a63,
           a64,
           a65,
           a66,
           a67,
           a68,
           a69,
           a70,
           a71,
           a72,
           a73,
           a74,
           a75,
           a76,
           a77,
           a78,
           a79,
           a80,
           a81,
           a82,
           a83,
           a84,
           a85,
           a86    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    ret.template get<62>() = a62;
    ret.template get<63>() = a63;
    ret.template get<64>() = a64;
    ret.template get<65>() = a65;
    ret.template get<66>() = a66;
    ret.template get<67>() = a67;
    ret.template get<68>() = a68;
    ret.template get<69>() = a69;
    ret.template get<70>() = a70;
    ret.template get<71>() = a71;
    ret.template get<72>() = a72;
    ret.template get<73>() = a73;
    ret.template get<74>() = a74;
    ret.template get<75>() = a75;
    ret.template get<76>() = a76;
    ret.template get<77>() = a77;
    ret.template get<78>() = a78;
    ret.template get<79>() = a79;
    ret.template get<80>() = a80;
    ret.template get<81>() = a81;
    ret.template get<82>() = a82;
    ret.template get<83>() = a83;
    ret.template get<84>() = a84;
    ret.template get<85>() = a85;
    ret.template get<86>() = a86;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 88>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61,
           a62,
           a63,
           a64,
           a65,
           a66,
           a67,
           a68,
           a69,
           a70,
           a71,
           a72,
           a73,
           a74,
           a75,
           a76,
           a77,
           a78,
           a79,
           a80,
           a81,
           a82,
           a83,
           a84,
           a85,
           a86,
           a87    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    ret.template get<62>() = a62;
    ret.template get<63>() = a63;
    ret.template get<64>() = a64;
    ret.template get<65>() = a65;
    ret.template get<66>() = a66;
    ret.template get<67>() = a67;
    ret.template get<68>() = a68;
    ret.template get<69>() = a69;
    ret.template get<70>() = a70;
    ret.template get<71>() = a71;
    ret.template get<72>() = a72;
    ret.template get<73>() = a73;
    ret.template get<74>() = a74;
    ret.template get<75>() = a75;
    ret.template get<76>() = a76;
    ret.template get<77>() = a77;
    ret.template get<78>() = a78;
    ret.template get<79>() = a79;
    ret.template get<80>() = a80;
    ret.template get<81>() = a81;
    ret.template get<82>() = a82;
    ret.template get<83>() = a83;
    ret.template get<84>() = a84;
    ret.template get<85>() = a85;
    ret.template get<86>() = a86;
    ret.template get<87>() = a87;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 89>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61,
           a62,
           a63,
           a64,
           a65,
           a66,
           a67,
           a68,
           a69,
           a70,
           a71,
           a72,
           a73,
           a74,
           a75,
           a76,
           a77,
           a78,
           a79,
           a80,
           a81,
           a82,
           a83,
           a84,
           a85,
           a86,
           a87,
           a88    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    ret.template get<62>() = a62;
    ret.template get<63>() = a63;
    ret.template get<64>() = a64;
    ret.template get<65>() = a65;
    ret.template get<66>() = a66;
    ret.template get<67>() = a67;
    ret.template get<68>() = a68;
    ret.template get<69>() = a69;
    ret.template get<70>() = a70;
    ret.template get<71>() = a71;
    ret.template get<72>() = a72;
    ret.template get<73>() = a73;
    ret.template get<74>() = a74;
    ret.template get<75>() = a75;
    ret.template get<76>() = a76;
    ret.template get<77>() = a77;
    ret.template get<78>() = a78;
    ret.template get<79>() = a79;
    ret.template get<80>() = a80;
    ret.template get<81>() = a81;
    ret.template get<82>() = a82;
    ret.template get<83>() = a83;
    ret.template get<84>() = a84;
    ret.template get<85>() = a85;
    ret.template get<86>() = a86;
    ret.template get<87>() = a87;
    ret.template get<88>() = a88;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 90>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61,
           a62,
           a63,
           a64,
           a65,
           a66,
           a67,
           a68,
           a69,
           a70,
           a71,
           a72,
           a73,
           a74,
           a75,
           a76,
           a77,
           a78,
           a79,
           a80,
           a81,
           a82,
           a83,
           a84,
           a85,
           a86,
           a87,
           a88,
           a89    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    ret.template get<62>() = a62;
    ret.template get<63>() = a63;
    ret.template get<64>() = a64;
    ret.template get<65>() = a65;
    ret.template get<66>() = a66;
    ret.template get<67>() = a67;
    ret.template get<68>() = a68;
    ret.template get<69>() = a69;
    ret.template get<70>() = a70;
    ret.template get<71>() = a71;
    ret.template get<72>() = a72;
    ret.template get<73>() = a73;
    ret.template get<74>() = a74;
    ret.template get<75>() = a75;
    ret.template get<76>() = a76;
    ret.template get<77>() = a77;
    ret.template get<78>() = a78;
    ret.template get<79>() = a79;
    ret.template get<80>() = a80;
    ret.template get<81>() = a81;
    ret.template get<82>() = a82;
    ret.template get<83>() = a83;
    ret.template get<84>() = a84;
    ret.template get<85>() = a85;
    ret.template get<86>() = a86;
    ret.template get<87>() = a87;
    ret.template get<88>() = a88;
    ret.template get<89>() = a89;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 91>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61,
           a62,
           a63,
           a64,
           a65,
           a66,
           a67,
           a68,
           a69,
           a70,
           a71,
           a72,
           a73,
           a74,
           a75,
           a76,
           a77,
           a78,
           a79,
           a80,
           a81,
           a82,
           a83,
           a84,
           a85,
           a86,
           a87,
           a88,
           a89,
           a90    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    ret.template get<62>() = a62;
    ret.template get<63>() = a63;
    ret.template get<64>() = a64;
    ret.template get<65>() = a65;
    ret.template get<66>() = a66;
    ret.template get<67>() = a67;
    ret.template get<68>() = a68;
    ret.template get<69>() = a69;
    ret.template get<70>() = a70;
    ret.template get<71>() = a71;
    ret.template get<72>() = a72;
    ret.template get<73>() = a73;
    ret.template get<74>() = a74;
    ret.template get<75>() = a75;
    ret.template get<76>() = a76;
    ret.template get<77>() = a77;
    ret.template get<78>() = a78;
    ret.template get<79>() = a79;
    ret.template get<80>() = a80;
    ret.template get<81>() = a81;
    ret.template get<82>() = a82;
    ret.template get<83>() = a83;
    ret.template get<84>() = a84;
    ret.template get<85>() = a85;
    ret.template get<86>() = a86;
    ret.template get<87>() = a87;
    ret.template get<88>() = a88;
    ret.template get<89>() = a89;
    ret.template get<90>() = a90;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 92>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61,
           a62,
           a63,
           a64,
           a65,
           a66,
           a67,
           a68,
           a69,
           a70,
           a71,
           a72,
           a73,
           a74,
           a75,
           a76,
           a77,
           a78,
           a79,
           a80,
           a81,
           a82,
           a83,
           a84,
           a85,
           a86,
           a87,
           a88,
           a89,
           a90,
           a91    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    ret.template get<62>() = a62;
    ret.template get<63>() = a63;
    ret.template get<64>() = a64;
    ret.template get<65>() = a65;
    ret.template get<66>() = a66;
    ret.template get<67>() = a67;
    ret.template get<68>() = a68;
    ret.template get<69>() = a69;
    ret.template get<70>() = a70;
    ret.template get<71>() = a71;
    ret.template get<72>() = a72;
    ret.template get<73>() = a73;
    ret.template get<74>() = a74;
    ret.template get<75>() = a75;
    ret.template get<76>() = a76;
    ret.template get<77>() = a77;
    ret.template get<78>() = a78;
    ret.template get<79>() = a79;
    ret.template get<80>() = a80;
    ret.template get<81>() = a81;
    ret.template get<82>() = a82;
    ret.template get<83>() = a83;
    ret.template get<84>() = a84;
    ret.template get<85>() = a85;
    ret.template get<86>() = a86;
    ret.template get<87>() = a87;
    ret.template get<88>() = a88;
    ret.template get<89>() = a89;
    ret.template get<90>() = a90;
    ret.template get<91>() = a91;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 93>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61,
           a62,
           a63,
           a64,
           a65,
           a66,
           a67,
           a68,
           a69,
           a70,
           a71,
           a72,
           a73,
           a74,
           a75,
           a76,
           a77,
           a78,
           a79,
           a80,
           a81,
           a82,
           a83,
           a84,
           a85,
           a86,
           a87,
           a88,
           a89,
           a90,
           a91,
           a92    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    ret.template get<62>() = a62;
    ret.template get<63>() = a63;
    ret.template get<64>() = a64;
    ret.template get<65>() = a65;
    ret.template get<66>() = a66;
    ret.template get<67>() = a67;
    ret.template get<68>() = a68;
    ret.template get<69>() = a69;
    ret.template get<70>() = a70;
    ret.template get<71>() = a71;
    ret.template get<72>() = a72;
    ret.template get<73>() = a73;
    ret.template get<74>() = a74;
    ret.template get<75>() = a75;
    ret.template get<76>() = a76;
    ret.template get<77>() = a77;
    ret.template get<78>() = a78;
    ret.template get<79>() = a79;
    ret.template get<80>() = a80;
    ret.template get<81>() = a81;
    ret.template get<82>() = a82;
    ret.template get<83>() = a83;
    ret.template get<84>() = a84;
    ret.template get<85>() = a85;
    ret.template get<86>() = a86;
    ret.template get<87>() = a87;
    ret.template get<88>() = a88;
    ret.template get<89>() = a89;
    ret.template get<90>() = a90;
    ret.template get<91>() = a91;
    ret.template get<92>() = a92;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 94>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61,
           a62,
           a63,
           a64,
           a65,
           a66,
           a67,
           a68,
           a69,
           a70,
           a71,
           a72,
           a73,
           a74,
           a75,
           a76,
           a77,
           a78,
           a79,
           a80,
           a81,
           a82,
           a83,
           a84,
           a85,
           a86,
           a87,
           a88,
           a89,
           a90,
           a91,
           a92,
           a93    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    ret.template get<62>() = a62;
    ret.template get<63>() = a63;
    ret.template get<64>() = a64;
    ret.template get<65>() = a65;
    ret.template get<66>() = a66;
    ret.template get<67>() = a67;
    ret.template get<68>() = a68;
    ret.template get<69>() = a69;
    ret.template get<70>() = a70;
    ret.template get<71>() = a71;
    ret.template get<72>() = a72;
    ret.template get<73>() = a73;
    ret.template get<74>() = a74;
    ret.template get<75>() = a75;
    ret.template get<76>() = a76;
    ret.template get<77>() = a77;
    ret.template get<78>() = a78;
    ret.template get<79>() = a79;
    ret.template get<80>() = a80;
    ret.template get<81>() = a81;
    ret.template get<82>() = a82;
    ret.template get<83>() = a83;
    ret.template get<84>() = a84;
    ret.template get<85>() = a85;
    ret.template get<86>() = a86;
    ret.template get<87>() = a87;
    ret.template get<88>() = a88;
    ret.template get<89>() = a89;
    ret.template get<90>() = a90;
    ret.template get<91>() = a91;
    ret.template get<92>() = a92;
    ret.template get<93>() = a93;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 95>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61,
           a62,
           a63,
           a64,
           a65,
           a66,
           a67,
           a68,
           a69,
           a70,
           a71,
           a72,
           a73,
           a74,
           a75,
           a76,
           a77,
           a78,
           a79,
           a80,
           a81,
           a82,
           a83,
           a84,
           a85,
           a86,
           a87,
           a88,
           a89,
           a90,
           a91,
           a92,
           a93,
           a94    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    ret.template get<62>() = a62;
    ret.template get<63>() = a63;
    ret.template get<64>() = a64;
    ret.template get<65>() = a65;
    ret.template get<66>() = a66;
    ret.template get<67>() = a67;
    ret.template get<68>() = a68;
    ret.template get<69>() = a69;
    ret.template get<70>() = a70;
    ret.template get<71>() = a71;
    ret.template get<72>() = a72;
    ret.template get<73>() = a73;
    ret.template get<74>() = a74;
    ret.template get<75>() = a75;
    ret.template get<76>() = a76;
    ret.template get<77>() = a77;
    ret.template get<78>() = a78;
    ret.template get<79>() = a79;
    ret.template get<80>() = a80;
    ret.template get<81>() = a81;
    ret.template get<82>() = a82;
    ret.template get<83>() = a83;
    ret.template get<84>() = a84;
    ret.template get<85>() = a85;
    ret.template get<86>() = a86;
    ret.template get<87>() = a87;
    ret.template get<88>() = a88;
    ret.template get<89>() = a89;
    ret.template get<90>() = a90;
    ret.template get<91>() = a91;
    ret.template get<92>() = a92;
    ret.template get<93>() = a93;
    ret.template get<94>() = a94;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 96>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61,
           a62,
           a63,
           a64,
           a65,
           a66,
           a67,
           a68,
           a69,
           a70,
           a71,
           a72,
           a73,
           a74,
           a75,
           a76,
           a77,
           a78,
           a79,
           a80,
           a81,
           a82,
           a83,
           a84,
           a85,
           a86,
           a87,
           a88,
           a89,
           a90,
           a91,
           a92,
           a93,
           a94,
           a95    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    ret.template get<62>() = a62;
    ret.template get<63>() = a63;
    ret.template get<64>() = a64;
    ret.template get<65>() = a65;
    ret.template get<66>() = a66;
    ret.template get<67>() = a67;
    ret.template get<68>() = a68;
    ret.template get<69>() = a69;
    ret.template get<70>() = a70;
    ret.template get<71>() = a71;
    ret.template get<72>() = a72;
    ret.template get<73>() = a73;
    ret.template get<74>() = a74;
    ret.template get<75>() = a75;
    ret.template get<76>() = a76;
    ret.template get<77>() = a77;
    ret.template get<78>() = a78;
    ret.template get<79>() = a79;
    ret.template get<80>() = a80;
    ret.template get<81>() = a81;
    ret.template get<82>() = a82;
    ret.template get<83>() = a83;
    ret.template get<84>() = a84;
    ret.template get<85>() = a85;
    ret.template get<86>() = a86;
    ret.template get<87>() = a87;
    ret.template get<88>() = a88;
    ret.template get<89>() = a89;
    ret.template get<90>() = a90;
    ret.template get<91>() = a91;
    ret.template get<92>() = a92;
    ret.template get<93>() = a93;
    ret.template get<94>() = a94;
    ret.template get<95>() = a95;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 97>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61,
           a62,
           a63,
           a64,
           a65,
           a66,
           a67,
           a68,
           a69,
           a70,
           a71,
           a72,
           a73,
           a74,
           a75,
           a76,
           a77,
           a78,
           a79,
           a80,
           a81,
           a82,
           a83,
           a84,
           a85,
           a86,
           a87,
           a88,
           a89,
           a90,
           a91,
           a92,
           a93,
           a94,
           a95,
           a96    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    ret.template get<62>() = a62;
    ret.template get<63>() = a63;
    ret.template get<64>() = a64;
    ret.template get<65>() = a65;
    ret.template get<66>() = a66;
    ret.template get<67>() = a67;
    ret.template get<68>() = a68;
    ret.template get<69>() = a69;
    ret.template get<70>() = a70;
    ret.template get<71>() = a71;
    ret.template get<72>() = a72;
    ret.template get<73>() = a73;
    ret.template get<74>() = a74;
    ret.template get<75>() = a75;
    ret.template get<76>() = a76;
    ret.template get<77>() = a77;
    ret.template get<78>() = a78;
    ret.template get<79>() = a79;
    ret.template get<80>() = a80;
    ret.template get<81>() = a81;
    ret.template get<82>() = a82;
    ret.template get<83>() = a83;
    ret.template get<84>() = a84;
    ret.template get<85>() = a85;
    ret.template get<86>() = a86;
    ret.template get<87>() = a87;
    ret.template get<88>() = a88;
    ret.template get<89>() = a89;
    ret.template get<90>() = a90;
    ret.template get<91>() = a91;
    ret.template get<92>() = a92;
    ret.template get<93>() = a93;
    ret.template get<94>() = a94;
    ret.template get<95>() = a95;
    ret.template get<96>() = a96;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 98>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61,
           a62,
           a63,
           a64,
           a65,
           a66,
           a67,
           a68,
           a69,
           a70,
           a71,
           a72,
           a73,
           a74,
           a75,
           a76,
           a77,
           a78,
           a79,
           a80,
           a81,
           a82,
           a83,
           a84,
           a85,
           a86,
           a87,
           a88,
           a89,
           a90,
           a91,
           a92,
           a93,
           a94,
           a95,
           a96,
           a97    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    ret.template get<62>() = a62;
    ret.template get<63>() = a63;
    ret.template get<64>() = a64;
    ret.template get<65>() = a65;
    ret.template get<66>() = a66;
    ret.template get<67>() = a67;
    ret.template get<68>() = a68;
    ret.template get<69>() = a69;
    ret.template get<70>() = a70;
    ret.template get<71>() = a71;
    ret.template get<72>() = a72;
    ret.template get<73>() = a73;
    ret.template get<74>() = a74;
    ret.template get<75>() = a75;
    ret.template get<76>() = a76;
    ret.template get<77>() = a77;
    ret.template get<78>() = a78;
    ret.template get<79>() = a79;
    ret.template get<80>() = a80;
    ret.template get<81>() = a81;
    ret.template get<82>() = a82;
    ret.template get<83>() = a83;
    ret.template get<84>() = a84;
    ret.template get<85>() = a85;
    ret.template get<86>() = a86;
    ret.template get<87>() = a87;
    ret.template get<88>() = a88;
    ret.template get<89>() = a89;
    ret.template get<90>() = a90;
    ret.template get<91>() = a91;
    ret.template get<92>() = a92;
    ret.template get<93>() = a93;
    ret.template get<94>() = a94;
    ret.template get<95>() = a95;
    ret.template get<96>() = a96;
    ret.template get<97>() = a97;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 99>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61,
           a62,
           a63,
           a64,
           a65,
           a66,
           a67,
           a68,
           a69,
           a70,
           a71,
           a72,
           a73,
           a74,
           a75,
           a76,
           a77,
           a78,
           a79,
           a80,
           a81,
           a82,
           a83,
           a84,
           a85,
           a86,
           a87,
           a88,
           a89,
           a90,
           a91,
           a92,
           a93,
           a94,
           a95,
           a96,
           a97,
           a98    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    ret.template get<62>() = a62;
    ret.template get<63>() = a63;
    ret.template get<64>() = a64;
    ret.template get<65>() = a65;
    ret.template get<66>() = a66;
    ret.template get<67>() = a67;
    ret.template get<68>() = a68;
    ret.template get<69>() = a69;
    ret.template get<70>() = a70;
    ret.template get<71>() = a71;
    ret.template get<72>() = a72;
    ret.template get<73>() = a73;
    ret.template get<74>() = a74;
    ret.template get<75>() = a75;
    ret.template get<76>() = a76;
    ret.template get<77>() = a77;
    ret.template get<78>() = a78;
    ret.template get<79>() = a79;
    ret.template get<80>() = a80;
    ret.template get<81>() = a81;
    ret.template get<82>() = a82;
    ret.template get<83>() = a83;
    ret.template get<84>() = a84;
    ret.template get<85>() = a85;
    ret.template get<86>() = a86;
    ret.template get<87>() = a87;
    ret.template get<88>() = a88;
    ret.template get<89>() = a89;
    ret.template get<90>() = a90;
    ret.template get<91>() = a91;
    ret.template get<92>() = a92;
    ret.template get<93>() = a93;
    ret.template get<94>() = a94;
    ret.template get<95>() = a95;
    ret.template get<96>() = a96;
    ret.template get<97>() = a97;
    ret.template get<98>() = a98;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 100>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61,
           a62,
           a63,
           a64,
           a65,
           a66,
           a67,
           a68,
           a69,
           a70,
           a71,
           a72,
           a73,
           a74,
           a75,
           a76,
           a77,
           a78,
           a79,
           a80,
           a81,
           a82,
           a83,
           a84,
           a85,
           a86,
           a87,
           a88,
           a89,
           a90,
           a91,
           a92,
           a93,
           a94,
           a95,
           a96,
           a97,
           a98,
           a99    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    ret.template get<62>() = a62;
    ret.template get<63>() = a63;
    ret.template get<64>() = a64;
    ret.template get<65>() = a65;
    ret.template get<66>() = a66;
    ret.template get<67>() = a67;
    ret.template get<68>() = a68;
    ret.template get<69>() = a69;
    ret.template get<70>() = a70;
    ret.template get<71>() = a71;
    ret.template get<72>() = a72;
    ret.template get<73>() = a73;
    ret.template get<74>() = a74;
    ret.template get<75>() = a75;
    ret.template get<76>() = a76;
    ret.template get<77>() = a77;
    ret.template get<78>() = a78;
    ret.template get<79>() = a79;
    ret.template get<80>() = a80;
    ret.template get<81>() = a81;
    ret.template get<82>() = a82;
    ret.template get<83>() = a83;
    ret.template get<84>() = a84;
    ret.template get<85>() = a85;
    ret.template get<86>() = a86;
    ret.template get<87>() = a87;
    ret.template get<88>() = a88;
    ret.template get<89>() = a89;
    ret.template get<90>() = a90;
    ret.template get<91>() = a91;
    ret.template get<92>() = a92;
    ret.template get<93>() = a93;
    ret.template get<94>() = a94;
    ret.template get<95>() = a95;
    ret.template get<96>() = a96;
    ret.template get<97>() = a97;
    ret.template get<98>() = a98;
    ret.template get<99>() = a99;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 101>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61,
           a62,
           a63,
           a64,
           a65,
           a66,
           a67,
           a68,
           a69,
           a70,
           a71,
           a72,
           a73,
           a74,
           a75,
           a76,
           a77,
           a78,
           a79,
           a80,
           a81,
           a82,
           a83,
           a84,
           a85,
           a86,
           a87,
           a88,
           a89,
           a90,
           a91,
           a92,
           a93,
           a94,
           a95,
           a96,
           a97,
           a98,
           a99,
           a100    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    ret.template get<62>() = a62;
    ret.template get<63>() = a63;
    ret.template get<64>() = a64;
    ret.template get<65>() = a65;
    ret.template get<66>() = a66;
    ret.template get<67>() = a67;
    ret.template get<68>() = a68;
    ret.template get<69>() = a69;
    ret.template get<70>() = a70;
    ret.template get<71>() = a71;
    ret.template get<72>() = a72;
    ret.template get<73>() = a73;
    ret.template get<74>() = a74;
    ret.template get<75>() = a75;
    ret.template get<76>() = a76;
    ret.template get<77>() = a77;
    ret.template get<78>() = a78;
    ret.template get<79>() = a79;
    ret.template get<80>() = a80;
    ret.template get<81>() = a81;
    ret.template get<82>() = a82;
    ret.template get<83>() = a83;
    ret.template get<84>() = a84;
    ret.template get<85>() = a85;
    ret.template get<86>() = a86;
    ret.template get<87>() = a87;
    ret.template get<88>() = a88;
    ret.template get<89>() = a89;
    ret.template get<90>() = a90;
    ret.template get<91>() = a91;
    ret.template get<92>() = a92;
    ret.template get<93>() = a93;
    ret.template get<94>() = a94;
    ret.template get<95>() = a95;
    ret.template get<96>() = a96;
    ret.template get<97>() = a97;
    ret.template get<98>() = a98;
    ret.template get<99>() = a99;
    ret.template get<100>() = a100;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 102>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61,
           a62,
           a63,
           a64,
           a65,
           a66,
           a67,
           a68,
           a69,
           a70,
           a71,
           a72,
           a73,
           a74,
           a75,
           a76,
           a77,
           a78,
           a79,
           a80,
           a81,
           a82,
           a83,
           a84,
           a85,
           a86,
           a87,
           a88,
           a89,
           a90,
           a91,
           a92,
           a93,
           a94,
           a95,
           a96,
           a97,
           a98,
           a99,
           a100,
           a101    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    ret.template get<62>() = a62;
    ret.template get<63>() = a63;
    ret.template get<64>() = a64;
    ret.template get<65>() = a65;
    ret.template get<66>() = a66;
    ret.template get<67>() = a67;
    ret.template get<68>() = a68;
    ret.template get<69>() = a69;
    ret.template get<70>() = a70;
    ret.template get<71>() = a71;
    ret.template get<72>() = a72;
    ret.template get<73>() = a73;
    ret.template get<74>() = a74;
    ret.template get<75>() = a75;
    ret.template get<76>() = a76;
    ret.template get<77>() = a77;
    ret.template get<78>() = a78;
    ret.template get<79>() = a79;
    ret.template get<80>() = a80;
    ret.template get<81>() = a81;
    ret.template get<82>() = a82;
    ret.template get<83>() = a83;
    ret.template get<84>() = a84;
    ret.template get<85>() = a85;
    ret.template get<86>() = a86;
    ret.template get<87>() = a87;
    ret.template get<88>() = a88;
    ret.template get<89>() = a89;
    ret.template get<90>() = a90;
    ret.template get<91>() = a91;
    ret.template get<92>() = a92;
    ret.template get<93>() = a93;
    ret.template get<94>() = a94;
    ret.template get<95>() = a95;
    ret.template get<96>() = a96;
    ret.template get<97>() = a97;
    ret.template get<98>() = a98;
    ret.template get<99>() = a99;
    ret.template get<100>() = a100;
    ret.template get<101>() = a101;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 103>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61,
           a62,
           a63,
           a64,
           a65,
           a66,
           a67,
           a68,
           a69,
           a70,
           a71,
           a72,
           a73,
           a74,
           a75,
           a76,
           a77,
           a78,
           a79,
           a80,
           a81,
           a82,
           a83,
           a84,
           a85,
           a86,
           a87,
           a88,
           a89,
           a90,
           a91,
           a92,
           a93,
           a94,
           a95,
           a96,
           a97,
           a98,
           a99,
           a100,
           a101,
           a102    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    ret.template get<62>() = a62;
    ret.template get<63>() = a63;
    ret.template get<64>() = a64;
    ret.template get<65>() = a65;
    ret.template get<66>() = a66;
    ret.template get<67>() = a67;
    ret.template get<68>() = a68;
    ret.template get<69>() = a69;
    ret.template get<70>() = a70;
    ret.template get<71>() = a71;
    ret.template get<72>() = a72;
    ret.template get<73>() = a73;
    ret.template get<74>() = a74;
    ret.template get<75>() = a75;
    ret.template get<76>() = a76;
    ret.template get<77>() = a77;
    ret.template get<78>() = a78;
    ret.template get<79>() = a79;
    ret.template get<80>() = a80;
    ret.template get<81>() = a81;
    ret.template get<82>() = a82;
    ret.template get<83>() = a83;
    ret.template get<84>() = a84;
    ret.template get<85>() = a85;
    ret.template get<86>() = a86;
    ret.template get<87>() = a87;
    ret.template get<88>() = a88;
    ret.template get<89>() = a89;
    ret.template get<90>() = a90;
    ret.template get<91>() = a91;
    ret.template get<92>() = a92;
    ret.template get<93>() = a93;
    ret.template get<94>() = a94;
    ret.template get<95>() = a95;
    ret.template get<96>() = a96;
    ret.template get<97>() = a97;
    ret.template get<98>() = a98;
    ret.template get<99>() = a99;
    ret.template get<100>() = a100;
    ret.template get<101>() = a101;
    ret.template get<102>() = a102;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 104>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61,
           a62,
           a63,
           a64,
           a65,
           a66,
           a67,
           a68,
           a69,
           a70,
           a71,
           a72,
           a73,
           a74,
           a75,
           a76,
           a77,
           a78,
           a79,
           a80,
           a81,
           a82,
           a83,
           a84,
           a85,
           a86,
           a87,
           a88,
           a89,
           a90,
           a91,
           a92,
           a93,
           a94,
           a95,
           a96,
           a97,
           a98,
           a99,
           a100,
           a101,
           a102,
           a103    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    ret.template get<62>() = a62;
    ret.template get<63>() = a63;
    ret.template get<64>() = a64;
    ret.template get<65>() = a65;
    ret.template get<66>() = a66;
    ret.template get<67>() = a67;
    ret.template get<68>() = a68;
    ret.template get<69>() = a69;
    ret.template get<70>() = a70;
    ret.template get<71>() = a71;
    ret.template get<72>() = a72;
    ret.template get<73>() = a73;
    ret.template get<74>() = a74;
    ret.template get<75>() = a75;
    ret.template get<76>() = a76;
    ret.template get<77>() = a77;
    ret.template get<78>() = a78;
    ret.template get<79>() = a79;
    ret.template get<80>() = a80;
    ret.template get<81>() = a81;
    ret.template get<82>() = a82;
    ret.template get<83>() = a83;
    ret.template get<84>() = a84;
    ret.template get<85>() = a85;
    ret.template get<86>() = a86;
    ret.template get<87>() = a87;
    ret.template get<88>() = a88;
    ret.template get<89>() = a89;
    ret.template get<90>() = a90;
    ret.template get<91>() = a91;
    ret.template get<92>() = a92;
    ret.template get<93>() = a93;
    ret.template get<94>() = a94;
    ret.template get<95>() = a95;
    ret.template get<96>() = a96;
    ret.template get<97>() = a97;
    ret.template get<98>() = a98;
    ret.template get<99>() = a99;
    ret.template get<100>() = a100;
    ret.template get<101>() = a101;
    ret.template get<102>() = a102;
    ret.template get<103>() = a103;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 105>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61,
           a62,
           a63,
           a64,
           a65,
           a66,
           a67,
           a68,
           a69,
           a70,
           a71,
           a72,
           a73,
           a74,
           a75,
           a76,
           a77,
           a78,
           a79,
           a80,
           a81,
           a82,
           a83,
           a84,
           a85,
           a86,
           a87,
           a88,
           a89,
           a90,
           a91,
           a92,
           a93,
           a94,
           a95,
           a96,
           a97,
           a98,
           a99,
           a100,
           a101,
           a102,
           a103,
           a104    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    ret.template get<62>() = a62;
    ret.template get<63>() = a63;
    ret.template get<64>() = a64;
    ret.template get<65>() = a65;
    ret.template get<66>() = a66;
    ret.template get<67>() = a67;
    ret.template get<68>() = a68;
    ret.template get<69>() = a69;
    ret.template get<70>() = a70;
    ret.template get<71>() = a71;
    ret.template get<72>() = a72;
    ret.template get<73>() = a73;
    ret.template get<74>() = a74;
    ret.template get<75>() = a75;
    ret.template get<76>() = a76;
    ret.template get<77>() = a77;
    ret.template get<78>() = a78;
    ret.template get<79>() = a79;
    ret.template get<80>() = a80;
    ret.template get<81>() = a81;
    ret.template get<82>() = a82;
    ret.template get<83>() = a83;
    ret.template get<84>() = a84;
    ret.template get<85>() = a85;
    ret.template get<86>() = a86;
    ret.template get<87>() = a87;
    ret.template get<88>() = a88;
    ret.template get<89>() = a89;
    ret.template get<90>() = a90;
    ret.template get<91>() = a91;
    ret.template get<92>() = a92;
    ret.template get<93>() = a93;
    ret.template get<94>() = a94;
    ret.template get<95>() = a95;
    ret.template get<96>() = a96;
    ret.template get<97>() = a97;
    ret.template get<98>() = a98;
    ret.template get<99>() = a99;
    ret.template get<100>() = a100;
    ret.template get<101>() = a101;
    ret.template get<102>() = a102;
    ret.template get<103>() = a103;
    ret.template get<104>() = a104;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 106>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61,
           a62,
           a63,
           a64,
           a65,
           a66,
           a67,
           a68,
           a69,
           a70,
           a71,
           a72,
           a73,
           a74,
           a75,
           a76,
           a77,
           a78,
           a79,
           a80,
           a81,
           a82,
           a83,
           a84,
           a85,
           a86,
           a87,
           a88,
           a89,
           a90,
           a91,
           a92,
           a93,
           a94,
           a95,
           a96,
           a97,
           a98,
           a99,
           a100,
           a101,
           a102,
           a103,
           a104,
           a105    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    ret.template get<62>() = a62;
    ret.template get<63>() = a63;
    ret.template get<64>() = a64;
    ret.template get<65>() = a65;
    ret.template get<66>() = a66;
    ret.template get<67>() = a67;
    ret.template get<68>() = a68;
    ret.template get<69>() = a69;
    ret.template get<70>() = a70;
    ret.template get<71>() = a71;
    ret.template get<72>() = a72;
    ret.template get<73>() = a73;
    ret.template get<74>() = a74;
    ret.template get<75>() = a75;
    ret.template get<76>() = a76;
    ret.template get<77>() = a77;
    ret.template get<78>() = a78;
    ret.template get<79>() = a79;
    ret.template get<80>() = a80;
    ret.template get<81>() = a81;
    ret.template get<82>() = a82;
    ret.template get<83>() = a83;
    ret.template get<84>() = a84;
    ret.template get<85>() = a85;
    ret.template get<86>() = a86;
    ret.template get<87>() = a87;
    ret.template get<88>() = a88;
    ret.template get<89>() = a89;
    ret.template get<90>() = a90;
    ret.template get<91>() = a91;
    ret.template get<92>() = a92;
    ret.template get<93>() = a93;
    ret.template get<94>() = a94;
    ret.template get<95>() = a95;
    ret.template get<96>() = a96;
    ret.template get<97>() = a97;
    ret.template get<98>() = a98;
    ret.template get<99>() = a99;
    ret.template get<100>() = a100;
    ret.template get<101>() = a101;
    ret.template get<102>() = a102;
    ret.template get<103>() = a103;
    ret.template get<104>() = a104;
    ret.template get<105>() = a105;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 107>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61,
           a62,
           a63,
           a64,
           a65,
           a66,
           a67,
           a68,
           a69,
           a70,
           a71,
           a72,
           a73,
           a74,
           a75,
           a76,
           a77,
           a78,
           a79,
           a80,
           a81,
           a82,
           a83,
           a84,
           a85,
           a86,
           a87,
           a88,
           a89,
           a90,
           a91,
           a92,
           a93,
           a94,
           a95,
           a96,
           a97,
           a98,
           a99,
           a100,
           a101,
           a102,
           a103,
           a104,
           a105,
           a106    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    ret.template get<62>() = a62;
    ret.template get<63>() = a63;
    ret.template get<64>() = a64;
    ret.template get<65>() = a65;
    ret.template get<66>() = a66;
    ret.template get<67>() = a67;
    ret.template get<68>() = a68;
    ret.template get<69>() = a69;
    ret.template get<70>() = a70;
    ret.template get<71>() = a71;
    ret.template get<72>() = a72;
    ret.template get<73>() = a73;
    ret.template get<74>() = a74;
    ret.template get<75>() = a75;
    ret.template get<76>() = a76;
    ret.template get<77>() = a77;
    ret.template get<78>() = a78;
    ret.template get<79>() = a79;
    ret.template get<80>() = a80;
    ret.template get<81>() = a81;
    ret.template get<82>() = a82;
    ret.template get<83>() = a83;
    ret.template get<84>() = a84;
    ret.template get<85>() = a85;
    ret.template get<86>() = a86;
    ret.template get<87>() = a87;
    ret.template get<88>() = a88;
    ret.template get<89>() = a89;
    ret.template get<90>() = a90;
    ret.template get<91>() = a91;
    ret.template get<92>() = a92;
    ret.template get<93>() = a93;
    ret.template get<94>() = a94;
    ret.template get<95>() = a95;
    ret.template get<96>() = a96;
    ret.template get<97>() = a97;
    ret.template get<98>() = a98;
    ret.template get<99>() = a99;
    ret.template get<100>() = a100;
    ret.template get<101>() = a101;
    ret.template get<102>() = a102;
    ret.template get<103>() = a103;
    ret.template get<104>() = a104;
    ret.template get<105>() = a105;
    ret.template get<106>() = a106;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 108>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61,
           a62,
           a63,
           a64,
           a65,
           a66,
           a67,
           a68,
           a69,
           a70,
           a71,
           a72,
           a73,
           a74,
           a75,
           a76,
           a77,
           a78,
           a79,
           a80,
           a81,
           a82,
           a83,
           a84,
           a85,
           a86,
           a87,
           a88,
           a89,
           a90,
           a91,
           a92,
           a93,
           a94,
           a95,
           a96,
           a97,
           a98,
           a99,
           a100,
           a101,
           a102,
           a103,
           a104,
           a105,
           a106,
           a107    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    ret.template get<62>() = a62;
    ret.template get<63>() = a63;
    ret.template get<64>() = a64;
    ret.template get<65>() = a65;
    ret.template get<66>() = a66;
    ret.template get<67>() = a67;
    ret.template get<68>() = a68;
    ret.template get<69>() = a69;
    ret.template get<70>() = a70;
    ret.template get<71>() = a71;
    ret.template get<72>() = a72;
    ret.template get<73>() = a73;
    ret.template get<74>() = a74;
    ret.template get<75>() = a75;
    ret.template get<76>() = a76;
    ret.template get<77>() = a77;
    ret.template get<78>() = a78;
    ret.template get<79>() = a79;
    ret.template get<80>() = a80;
    ret.template get<81>() = a81;
    ret.template get<82>() = a82;
    ret.template get<83>() = a83;
    ret.template get<84>() = a84;
    ret.template get<85>() = a85;
    ret.template get<86>() = a86;
    ret.template get<87>() = a87;
    ret.template get<88>() = a88;
    ret.template get<89>() = a89;
    ret.template get<90>() = a90;
    ret.template get<91>() = a91;
    ret.template get<92>() = a92;
    ret.template get<93>() = a93;
    ret.template get<94>() = a94;
    ret.template get<95>() = a95;
    ret.template get<96>() = a96;
    ret.template get<97>() = a97;
    ret.template get<98>() = a98;
    ret.template get<99>() = a99;
    ret.template get<100>() = a100;
    ret.template get<101>() = a101;
    ret.template get<102>() = a102;
    ret.template get<103>() = a103;
    ret.template get<104>() = a104;
    ret.template get<105>() = a105;
    ret.template get<106>() = a106;
    ret.template get<107>() = a107;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 109>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61,
           a62,
           a63,
           a64,
           a65,
           a66,
           a67,
           a68,
           a69,
           a70,
           a71,
           a72,
           a73,
           a74,
           a75,
           a76,
           a77,
           a78,
           a79,
           a80,
           a81,
           a82,
           a83,
           a84,
           a85,
           a86,
           a87,
           a88,
           a89,
           a90,
           a91,
           a92,
           a93,
           a94,
           a95,
           a96,
           a97,
           a98,
           a99,
           a100,
           a101,
           a102,
           a103,
           a104,
           a105,
           a106,
           a107,
           a108    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    ret.template get<62>() = a62;
    ret.template get<63>() = a63;
    ret.template get<64>() = a64;
    ret.template get<65>() = a65;
    ret.template get<66>() = a66;
    ret.template get<67>() = a67;
    ret.template get<68>() = a68;
    ret.template get<69>() = a69;
    ret.template get<70>() = a70;
    ret.template get<71>() = a71;
    ret.template get<72>() = a72;
    ret.template get<73>() = a73;
    ret.template get<74>() = a74;
    ret.template get<75>() = a75;
    ret.template get<76>() = a76;
    ret.template get<77>() = a77;
    ret.template get<78>() = a78;
    ret.template get<79>() = a79;
    ret.template get<80>() = a80;
    ret.template get<81>() = a81;
    ret.template get<82>() = a82;
    ret.template get<83>() = a83;
    ret.template get<84>() = a84;
    ret.template get<85>() = a85;
    ret.template get<86>() = a86;
    ret.template get<87>() = a87;
    ret.template get<88>() = a88;
    ret.template get<89>() = a89;
    ret.template get<90>() = a90;
    ret.template get<91>() = a91;
    ret.template get<92>() = a92;
    ret.template get<93>() = a93;
    ret.template get<94>() = a94;
    ret.template get<95>() = a95;
    ret.template get<96>() = a96;
    ret.template get<97>() = a97;
    ret.template get<98>() = a98;
    ret.template get<99>() = a99;
    ret.template get<100>() = a100;
    ret.template get<101>() = a101;
    ret.template get<102>() = a102;
    ret.template get<103>() = a103;
    ret.template get<104>() = a104;
    ret.template get<105>() = a105;
    ret.template get<106>() = a106;
    ret.template get<107>() = a107;
    ret.template get<108>() = a108;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 110>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61,
           a62,
           a63,
           a64,
           a65,
           a66,
           a67,
           a68,
           a69,
           a70,
           a71,
           a72,
           a73,
           a74,
           a75,
           a76,
           a77,
           a78,
           a79,
           a80,
           a81,
           a82,
           a83,
           a84,
           a85,
           a86,
           a87,
           a88,
           a89,
           a90,
           a91,
           a92,
           a93,
           a94,
           a95,
           a96,
           a97,
           a98,
           a99,
           a100,
           a101,
           a102,
           a103,
           a104,
           a105,
           a106,
           a107,
           a108,
           a109    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    ret.template get<62>() = a62;
    ret.template get<63>() = a63;
    ret.template get<64>() = a64;
    ret.template get<65>() = a65;
    ret.template get<66>() = a66;
    ret.template get<67>() = a67;
    ret.template get<68>() = a68;
    ret.template get<69>() = a69;
    ret.template get<70>() = a70;
    ret.template get<71>() = a71;
    ret.template get<72>() = a72;
    ret.template get<73>() = a73;
    ret.template get<74>() = a74;
    ret.template get<75>() = a75;
    ret.template get<76>() = a76;
    ret.template get<77>() = a77;
    ret.template get<78>() = a78;
    ret.template get<79>() = a79;
    ret.template get<80>() = a80;
    ret.template get<81>() = a81;
    ret.template get<82>() = a82;
    ret.template get<83>() = a83;
    ret.template get<84>() = a84;
    ret.template get<85>() = a85;
    ret.template get<86>() = a86;
    ret.template get<87>() = a87;
    ret.template get<88>() = a88;
    ret.template get<89>() = a89;
    ret.template get<90>() = a90;
    ret.template get<91>() = a91;
    ret.template get<92>() = a92;
    ret.template get<93>() = a93;
    ret.template get<94>() = a94;
    ret.template get<95>() = a95;
    ret.template get<96>() = a96;
    ret.template get<97>() = a97;
    ret.template get<98>() = a98;
    ret.template get<99>() = a99;
    ret.template get<100>() = a100;
    ret.template get<101>() = a101;
    ret.template get<102>() = a102;
    ret.template get<103>() = a103;
    ret.template get<104>() = a104;
    ret.template get<105>() = a105;
    ret.template get<106>() = a106;
    ret.template get<107>() = a107;
    ret.template get<108>() = a108;
    ret.template get<109>() = a109;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 111>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61,
           a62,
           a63,
           a64,
           a65,
           a66,
           a67,
           a68,
           a69,
           a70,
           a71,
           a72,
           a73,
           a74,
           a75,
           a76,
           a77,
           a78,
           a79,
           a80,
           a81,
           a82,
           a83,
           a84,
           a85,
           a86,
           a87,
           a88,
           a89,
           a90,
           a91,
           a92,
           a93,
           a94,
           a95,
           a96,
           a97,
           a98,
           a99,
           a100,
           a101,
           a102,
           a103,
           a104,
           a105,
           a106,
           a107,
           a108,
           a109,
           a110    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    ret.template get<62>() = a62;
    ret.template get<63>() = a63;
    ret.template get<64>() = a64;
    ret.template get<65>() = a65;
    ret.template get<66>() = a66;
    ret.template get<67>() = a67;
    ret.template get<68>() = a68;
    ret.template get<69>() = a69;
    ret.template get<70>() = a70;
    ret.template get<71>() = a71;
    ret.template get<72>() = a72;
    ret.template get<73>() = a73;
    ret.template get<74>() = a74;
    ret.template get<75>() = a75;
    ret.template get<76>() = a76;
    ret.template get<77>() = a77;
    ret.template get<78>() = a78;
    ret.template get<79>() = a79;
    ret.template get<80>() = a80;
    ret.template get<81>() = a81;
    ret.template get<82>() = a82;
    ret.template get<83>() = a83;
    ret.template get<84>() = a84;
    ret.template get<85>() = a85;
    ret.template get<86>() = a86;
    ret.template get<87>() = a87;
    ret.template get<88>() = a88;
    ret.template get<89>() = a89;
    ret.template get<90>() = a90;
    ret.template get<91>() = a91;
    ret.template get<92>() = a92;
    ret.template get<93>() = a93;
    ret.template get<94>() = a94;
    ret.template get<95>() = a95;
    ret.template get<96>() = a96;
    ret.template get<97>() = a97;
    ret.template get<98>() = a98;
    ret.template get<99>() = a99;
    ret.template get<100>() = a100;
    ret.template get<101>() = a101;
    ret.template get<102>() = a102;
    ret.template get<103>() = a103;
    ret.template get<104>() = a104;
    ret.template get<105>() = a105;
    ret.template get<106>() = a106;
    ret.template get<107>() = a107;
    ret.template get<108>() = a108;
    ret.template get<109>() = a109;
    ret.template get<110>() = a110;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 112>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61,
           a62,
           a63,
           a64,
           a65,
           a66,
           a67,
           a68,
           a69,
           a70,
           a71,
           a72,
           a73,
           a74,
           a75,
           a76,
           a77,
           a78,
           a79,
           a80,
           a81,
           a82,
           a83,
           a84,
           a85,
           a86,
           a87,
           a88,
           a89,
           a90,
           a91,
           a92,
           a93,
           a94,
           a95,
           a96,
           a97,
           a98,
           a99,
           a100,
           a101,
           a102,
           a103,
           a104,
           a105,
           a106,
           a107,
           a108,
           a109,
           a110,
           a111    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    ret.template get<62>() = a62;
    ret.template get<63>() = a63;
    ret.template get<64>() = a64;
    ret.template get<65>() = a65;
    ret.template get<66>() = a66;
    ret.template get<67>() = a67;
    ret.template get<68>() = a68;
    ret.template get<69>() = a69;
    ret.template get<70>() = a70;
    ret.template get<71>() = a71;
    ret.template get<72>() = a72;
    ret.template get<73>() = a73;
    ret.template get<74>() = a74;
    ret.template get<75>() = a75;
    ret.template get<76>() = a76;
    ret.template get<77>() = a77;
    ret.template get<78>() = a78;
    ret.template get<79>() = a79;
    ret.template get<80>() = a80;
    ret.template get<81>() = a81;
    ret.template get<82>() = a82;
    ret.template get<83>() = a83;
    ret.template get<84>() = a84;
    ret.template get<85>() = a85;
    ret.template get<86>() = a86;
    ret.template get<87>() = a87;
    ret.template get<88>() = a88;
    ret.template get<89>() = a89;
    ret.template get<90>() = a90;
    ret.template get<91>() = a91;
    ret.template get<92>() = a92;
    ret.template get<93>() = a93;
    ret.template get<94>() = a94;
    ret.template get<95>() = a95;
    ret.template get<96>() = a96;
    ret.template get<97>() = a97;
    ret.template get<98>() = a98;
    ret.template get<99>() = a99;
    ret.template get<100>() = a100;
    ret.template get<101>() = a101;
    ret.template get<102>() = a102;
    ret.template get<103>() = a103;
    ret.template get<104>() = a104;
    ret.template get<105>() = a105;
    ret.template get<106>() = a106;
    ret.template get<107>() = a107;
    ret.template get<108>() = a108;
    ret.template get<109>() = a109;
    ret.template get<110>() = a110;
    ret.template get<111>() = a111;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 113>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61,
           a62,
           a63,
           a64,
           a65,
           a66,
           a67,
           a68,
           a69,
           a70,
           a71,
           a72,
           a73,
           a74,
           a75,
           a76,
           a77,
           a78,
           a79,
           a80,
           a81,
           a82,
           a83,
           a84,
           a85,
           a86,
           a87,
           a88,
           a89,
           a90,
           a91,
           a92,
           a93,
           a94,
           a95,
           a96,
           a97,
           a98,
           a99,
           a100,
           a101,
           a102,
           a103,
           a104,
           a105,
           a106,
           a107,
           a108,
           a109,
           a110,
           a111,
           a112    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    ret.template get<62>() = a62;
    ret.template get<63>() = a63;
    ret.template get<64>() = a64;
    ret.template get<65>() = a65;
    ret.template get<66>() = a66;
    ret.template get<67>() = a67;
    ret.template get<68>() = a68;
    ret.template get<69>() = a69;
    ret.template get<70>() = a70;
    ret.template get<71>() = a71;
    ret.template get<72>() = a72;
    ret.template get<73>() = a73;
    ret.template get<74>() = a74;
    ret.template get<75>() = a75;
    ret.template get<76>() = a76;
    ret.template get<77>() = a77;
    ret.template get<78>() = a78;
    ret.template get<79>() = a79;
    ret.template get<80>() = a80;
    ret.template get<81>() = a81;
    ret.template get<82>() = a82;
    ret.template get<83>() = a83;
    ret.template get<84>() = a84;
    ret.template get<85>() = a85;
    ret.template get<86>() = a86;
    ret.template get<87>() = a87;
    ret.template get<88>() = a88;
    ret.template get<89>() = a89;
    ret.template get<90>() = a90;
    ret.template get<91>() = a91;
    ret.template get<92>() = a92;
    ret.template get<93>() = a93;
    ret.template get<94>() = a94;
    ret.template get<95>() = a95;
    ret.template get<96>() = a96;
    ret.template get<97>() = a97;
    ret.template get<98>() = a98;
    ret.template get<99>() = a99;
    ret.template get<100>() = a100;
    ret.template get<101>() = a101;
    ret.template get<102>() = a102;
    ret.template get<103>() = a103;
    ret.template get<104>() = a104;
    ret.template get<105>() = a105;
    ret.template get<106>() = a106;
    ret.template get<107>() = a107;
    ret.template get<108>() = a108;
    ret.template get<109>() = a109;
    ret.template get<110>() = a110;
    ret.template get<111>() = a111;
    ret.template get<112>() = a112;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 114>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61,
           a62,
           a63,
           a64,
           a65,
           a66,
           a67,
           a68,
           a69,
           a70,
           a71,
           a72,
           a73,
           a74,
           a75,
           a76,
           a77,
           a78,
           a79,
           a80,
           a81,
           a82,
           a83,
           a84,
           a85,
           a86,
           a87,
           a88,
           a89,
           a90,
           a91,
           a92,
           a93,
           a94,
           a95,
           a96,
           a97,
           a98,
           a99,
           a100,
           a101,
           a102,
           a103,
           a104,
           a105,
           a106,
           a107,
           a108,
           a109,
           a110,
           a111,
           a112,
           a113    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    ret.template get<62>() = a62;
    ret.template get<63>() = a63;
    ret.template get<64>() = a64;
    ret.template get<65>() = a65;
    ret.template get<66>() = a66;
    ret.template get<67>() = a67;
    ret.template get<68>() = a68;
    ret.template get<69>() = a69;
    ret.template get<70>() = a70;
    ret.template get<71>() = a71;
    ret.template get<72>() = a72;
    ret.template get<73>() = a73;
    ret.template get<74>() = a74;
    ret.template get<75>() = a75;
    ret.template get<76>() = a76;
    ret.template get<77>() = a77;
    ret.template get<78>() = a78;
    ret.template get<79>() = a79;
    ret.template get<80>() = a80;
    ret.template get<81>() = a81;
    ret.template get<82>() = a82;
    ret.template get<83>() = a83;
    ret.template get<84>() = a84;
    ret.template get<85>() = a85;
    ret.template get<86>() = a86;
    ret.template get<87>() = a87;
    ret.template get<88>() = a88;
    ret.template get<89>() = a89;
    ret.template get<90>() = a90;
    ret.template get<91>() = a91;
    ret.template get<92>() = a92;
    ret.template get<93>() = a93;
    ret.template get<94>() = a94;
    ret.template get<95>() = a95;
    ret.template get<96>() = a96;
    ret.template get<97>() = a97;
    ret.template get<98>() = a98;
    ret.template get<99>() = a99;
    ret.template get<100>() = a100;
    ret.template get<101>() = a101;
    ret.template get<102>() = a102;
    ret.template get<103>() = a103;
    ret.template get<104>() = a104;
    ret.template get<105>() = a105;
    ret.template get<106>() = a106;
    ret.template get<107>() = a107;
    ret.template get<108>() = a108;
    ret.template get<109>() = a109;
    ret.template get<110>() = a110;
    ret.template get<111>() = a111;
    ret.template get<112>() = a112;
    ret.template get<113>() = a113;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 115>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61,
           a62,
           a63,
           a64,
           a65,
           a66,
           a67,
           a68,
           a69,
           a70,
           a71,
           a72,
           a73,
           a74,
           a75,
           a76,
           a77,
           a78,
           a79,
           a80,
           a81,
           a82,
           a83,
           a84,
           a85,
           a86,
           a87,
           a88,
           a89,
           a90,
           a91,
           a92,
           a93,
           a94,
           a95,
           a96,
           a97,
           a98,
           a99,
           a100,
           a101,
           a102,
           a103,
           a104,
           a105,
           a106,
           a107,
           a108,
           a109,
           a110,
           a111,
           a112,
           a113,
           a114    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    ret.template get<62>() = a62;
    ret.template get<63>() = a63;
    ret.template get<64>() = a64;
    ret.template get<65>() = a65;
    ret.template get<66>() = a66;
    ret.template get<67>() = a67;
    ret.template get<68>() = a68;
    ret.template get<69>() = a69;
    ret.template get<70>() = a70;
    ret.template get<71>() = a71;
    ret.template get<72>() = a72;
    ret.template get<73>() = a73;
    ret.template get<74>() = a74;
    ret.template get<75>() = a75;
    ret.template get<76>() = a76;
    ret.template get<77>() = a77;
    ret.template get<78>() = a78;
    ret.template get<79>() = a79;
    ret.template get<80>() = a80;
    ret.template get<81>() = a81;
    ret.template get<82>() = a82;
    ret.template get<83>() = a83;
    ret.template get<84>() = a84;
    ret.template get<85>() = a85;
    ret.template get<86>() = a86;
    ret.template get<87>() = a87;
    ret.template get<88>() = a88;
    ret.template get<89>() = a89;
    ret.template get<90>() = a90;
    ret.template get<91>() = a91;
    ret.template get<92>() = a92;
    ret.template get<93>() = a93;
    ret.template get<94>() = a94;
    ret.template get<95>() = a95;
    ret.template get<96>() = a96;
    ret.template get<97>() = a97;
    ret.template get<98>() = a98;
    ret.template get<99>() = a99;
    ret.template get<100>() = a100;
    ret.template get<101>() = a101;
    ret.template get<102>() = a102;
    ret.template get<103>() = a103;
    ret.template get<104>() = a104;
    ret.template get<105>() = a105;
    ret.template get<106>() = a106;
    ret.template get<107>() = a107;
    ret.template get<108>() = a108;
    ret.template get<109>() = a109;
    ret.template get<110>() = a110;
    ret.template get<111>() = a111;
    ret.template get<112>() = a112;
    ret.template get<113>() = a113;
    ret.template get<114>() = a114;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 116>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61,
           a62,
           a63,
           a64,
           a65,
           a66,
           a67,
           a68,
           a69,
           a70,
           a71,
           a72,
           a73,
           a74,
           a75,
           a76,
           a77,
           a78,
           a79,
           a80,
           a81,
           a82,
           a83,
           a84,
           a85,
           a86,
           a87,
           a88,
           a89,
           a90,
           a91,
           a92,
           a93,
           a94,
           a95,
           a96,
           a97,
           a98,
           a99,
           a100,
           a101,
           a102,
           a103,
           a104,
           a105,
           a106,
           a107,
           a108,
           a109,
           a110,
           a111,
           a112,
           a113,
           a114,
           a115    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    ret.template get<62>() = a62;
    ret.template get<63>() = a63;
    ret.template get<64>() = a64;
    ret.template get<65>() = a65;
    ret.template get<66>() = a66;
    ret.template get<67>() = a67;
    ret.template get<68>() = a68;
    ret.template get<69>() = a69;
    ret.template get<70>() = a70;
    ret.template get<71>() = a71;
    ret.template get<72>() = a72;
    ret.template get<73>() = a73;
    ret.template get<74>() = a74;
    ret.template get<75>() = a75;
    ret.template get<76>() = a76;
    ret.template get<77>() = a77;
    ret.template get<78>() = a78;
    ret.template get<79>() = a79;
    ret.template get<80>() = a80;
    ret.template get<81>() = a81;
    ret.template get<82>() = a82;
    ret.template get<83>() = a83;
    ret.template get<84>() = a84;
    ret.template get<85>() = a85;
    ret.template get<86>() = a86;
    ret.template get<87>() = a87;
    ret.template get<88>() = a88;
    ret.template get<89>() = a89;
    ret.template get<90>() = a90;
    ret.template get<91>() = a91;
    ret.template get<92>() = a92;
    ret.template get<93>() = a93;
    ret.template get<94>() = a94;
    ret.template get<95>() = a95;
    ret.template get<96>() = a96;
    ret.template get<97>() = a97;
    ret.template get<98>() = a98;
    ret.template get<99>() = a99;
    ret.template get<100>() = a100;
    ret.template get<101>() = a101;
    ret.template get<102>() = a102;
    ret.template get<103>() = a103;
    ret.template get<104>() = a104;
    ret.template get<105>() = a105;
    ret.template get<106>() = a106;
    ret.template get<107>() = a107;
    ret.template get<108>() = a108;
    ret.template get<109>() = a109;
    ret.template get<110>() = a110;
    ret.template get<111>() = a111;
    ret.template get<112>() = a112;
    ret.template get<113>() = a113;
    ret.template get<114>() = a114;
    ret.template get<115>() = a115;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 117>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61,
           a62,
           a63,
           a64,
           a65,
           a66,
           a67,
           a68,
           a69,
           a70,
           a71,
           a72,
           a73,
           a74,
           a75,
           a76,
           a77,
           a78,
           a79,
           a80,
           a81,
           a82,
           a83,
           a84,
           a85,
           a86,
           a87,
           a88,
           a89,
           a90,
           a91,
           a92,
           a93,
           a94,
           a95,
           a96,
           a97,
           a98,
           a99,
           a100,
           a101,
           a102,
           a103,
           a104,
           a105,
           a106,
           a107,
           a108,
           a109,
           a110,
           a111,
           a112,
           a113,
           a114,
           a115,
           a116    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    ret.template get<62>() = a62;
    ret.template get<63>() = a63;
    ret.template get<64>() = a64;
    ret.template get<65>() = a65;
    ret.template get<66>() = a66;
    ret.template get<67>() = a67;
    ret.template get<68>() = a68;
    ret.template get<69>() = a69;
    ret.template get<70>() = a70;
    ret.template get<71>() = a71;
    ret.template get<72>() = a72;
    ret.template get<73>() = a73;
    ret.template get<74>() = a74;
    ret.template get<75>() = a75;
    ret.template get<76>() = a76;
    ret.template get<77>() = a77;
    ret.template get<78>() = a78;
    ret.template get<79>() = a79;
    ret.template get<80>() = a80;
    ret.template get<81>() = a81;
    ret.template get<82>() = a82;
    ret.template get<83>() = a83;
    ret.template get<84>() = a84;
    ret.template get<85>() = a85;
    ret.template get<86>() = a86;
    ret.template get<87>() = a87;
    ret.template get<88>() = a88;
    ret.template get<89>() = a89;
    ret.template get<90>() = a90;
    ret.template get<91>() = a91;
    ret.template get<92>() = a92;
    ret.template get<93>() = a93;
    ret.template get<94>() = a94;
    ret.template get<95>() = a95;
    ret.template get<96>() = a96;
    ret.template get<97>() = a97;
    ret.template get<98>() = a98;
    ret.template get<99>() = a99;
    ret.template get<100>() = a100;
    ret.template get<101>() = a101;
    ret.template get<102>() = a102;
    ret.template get<103>() = a103;
    ret.template get<104>() = a104;
    ret.template get<105>() = a105;
    ret.template get<106>() = a106;
    ret.template get<107>() = a107;
    ret.template get<108>() = a108;
    ret.template get<109>() = a109;
    ret.template get<110>() = a110;
    ret.template get<111>() = a111;
    ret.template get<112>() = a112;
    ret.template get<113>() = a113;
    ret.template get<114>() = a114;
    ret.template get<115>() = a115;
    ret.template get<116>() = a116;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 118>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61,
           a62,
           a63,
           a64,
           a65,
           a66,
           a67,
           a68,
           a69,
           a70,
           a71,
           a72,
           a73,
           a74,
           a75,
           a76,
           a77,
           a78,
           a79,
           a80,
           a81,
           a82,
           a83,
           a84,
           a85,
           a86,
           a87,
           a88,
           a89,
           a90,
           a91,
           a92,
           a93,
           a94,
           a95,
           a96,
           a97,
           a98,
           a99,
           a100,
           a101,
           a102,
           a103,
           a104,
           a105,
           a106,
           a107,
           a108,
           a109,
           a110,
           a111,
           a112,
           a113,
           a114,
           a115,
           a116,
           a117    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    ret.template get<62>() = a62;
    ret.template get<63>() = a63;
    ret.template get<64>() = a64;
    ret.template get<65>() = a65;
    ret.template get<66>() = a66;
    ret.template get<67>() = a67;
    ret.template get<68>() = a68;
    ret.template get<69>() = a69;
    ret.template get<70>() = a70;
    ret.template get<71>() = a71;
    ret.template get<72>() = a72;
    ret.template get<73>() = a73;
    ret.template get<74>() = a74;
    ret.template get<75>() = a75;
    ret.template get<76>() = a76;
    ret.template get<77>() = a77;
    ret.template get<78>() = a78;
    ret.template get<79>() = a79;
    ret.template get<80>() = a80;
    ret.template get<81>() = a81;
    ret.template get<82>() = a82;
    ret.template get<83>() = a83;
    ret.template get<84>() = a84;
    ret.template get<85>() = a85;
    ret.template get<86>() = a86;
    ret.template get<87>() = a87;
    ret.template get<88>() = a88;
    ret.template get<89>() = a89;
    ret.template get<90>() = a90;
    ret.template get<91>() = a91;
    ret.template get<92>() = a92;
    ret.template get<93>() = a93;
    ret.template get<94>() = a94;
    ret.template get<95>() = a95;
    ret.template get<96>() = a96;
    ret.template get<97>() = a97;
    ret.template get<98>() = a98;
    ret.template get<99>() = a99;
    ret.template get<100>() = a100;
    ret.template get<101>() = a101;
    ret.template get<102>() = a102;
    ret.template get<103>() = a103;
    ret.template get<104>() = a104;
    ret.template get<105>() = a105;
    ret.template get<106>() = a106;
    ret.template get<107>() = a107;
    ret.template get<108>() = a108;
    ret.template get<109>() = a109;
    ret.template get<110>() = a110;
    ret.template get<111>() = a111;
    ret.template get<112>() = a112;
    ret.template get<113>() = a113;
    ret.template get<114>() = a114;
    ret.template get<115>() = a115;
    ret.template get<116>() = a116;
    ret.template get<117>() = a117;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 119>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61,
           a62,
           a63,
           a64,
           a65,
           a66,
           a67,
           a68,
           a69,
           a70,
           a71,
           a72,
           a73,
           a74,
           a75,
           a76,
           a77,
           a78,
           a79,
           a80,
           a81,
           a82,
           a83,
           a84,
           a85,
           a86,
           a87,
           a88,
           a89,
           a90,
           a91,
           a92,
           a93,
           a94,
           a95,
           a96,
           a97,
           a98,
           a99,
           a100,
           a101,
           a102,
           a103,
           a104,
           a105,
           a106,
           a107,
           a108,
           a109,
           a110,
           a111,
           a112,
           a113,
           a114,
           a115,
           a116,
           a117,
           a118    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    ret.template get<62>() = a62;
    ret.template get<63>() = a63;
    ret.template get<64>() = a64;
    ret.template get<65>() = a65;
    ret.template get<66>() = a66;
    ret.template get<67>() = a67;
    ret.template get<68>() = a68;
    ret.template get<69>() = a69;
    ret.template get<70>() = a70;
    ret.template get<71>() = a71;
    ret.template get<72>() = a72;
    ret.template get<73>() = a73;
    ret.template get<74>() = a74;
    ret.template get<75>() = a75;
    ret.template get<76>() = a76;
    ret.template get<77>() = a77;
    ret.template get<78>() = a78;
    ret.template get<79>() = a79;
    ret.template get<80>() = a80;
    ret.template get<81>() = a81;
    ret.template get<82>() = a82;
    ret.template get<83>() = a83;
    ret.template get<84>() = a84;
    ret.template get<85>() = a85;
    ret.template get<86>() = a86;
    ret.template get<87>() = a87;
    ret.template get<88>() = a88;
    ret.template get<89>() = a89;
    ret.template get<90>() = a90;
    ret.template get<91>() = a91;
    ret.template get<92>() = a92;
    ret.template get<93>() = a93;
    ret.template get<94>() = a94;
    ret.template get<95>() = a95;
    ret.template get<96>() = a96;
    ret.template get<97>() = a97;
    ret.template get<98>() = a98;
    ret.template get<99>() = a99;
    ret.template get<100>() = a100;
    ret.template get<101>() = a101;
    ret.template get<102>() = a102;
    ret.template get<103>() = a103;
    ret.template get<104>() = a104;
    ret.template get<105>() = a105;
    ret.template get<106>() = a106;
    ret.template get<107>() = a107;
    ret.template get<108>() = a108;
    ret.template get<109>() = a109;
    ret.template get<110>() = a110;
    ret.template get<111>() = a111;
    ret.template get<112>() = a112;
    ret.template get<113>() = a113;
    ret.template get<114>() = a114;
    ret.template get<115>() = a115;
    ret.template get<116>() = a116;
    ret.template get<117>() = a117;
    ret.template get<118>() = a118;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 120>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61,
           a62,
           a63,
           a64,
           a65,
           a66,
           a67,
           a68,
           a69,
           a70,
           a71,
           a72,
           a73,
           a74,
           a75,
           a76,
           a77,
           a78,
           a79,
           a80,
           a81,
           a82,
           a83,
           a84,
           a85,
           a86,
           a87,
           a88,
           a89,
           a90,
           a91,
           a92,
           a93,
           a94,
           a95,
           a96,
           a97,
           a98,
           a99,
           a100,
           a101,
           a102,
           a103,
           a104,
           a105,
           a106,
           a107,
           a108,
           a109,
           a110,
           a111,
           a112,
           a113,
           a114,
           a115,
           a116,
           a117,
           a118,
           a119    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    ret.template get<62>() = a62;
    ret.template get<63>() = a63;
    ret.template get<64>() = a64;
    ret.template get<65>() = a65;
    ret.template get<66>() = a66;
    ret.template get<67>() = a67;
    ret.template get<68>() = a68;
    ret.template get<69>() = a69;
    ret.template get<70>() = a70;
    ret.template get<71>() = a71;
    ret.template get<72>() = a72;
    ret.template get<73>() = a73;
    ret.template get<74>() = a74;
    ret.template get<75>() = a75;
    ret.template get<76>() = a76;
    ret.template get<77>() = a77;
    ret.template get<78>() = a78;
    ret.template get<79>() = a79;
    ret.template get<80>() = a80;
    ret.template get<81>() = a81;
    ret.template get<82>() = a82;
    ret.template get<83>() = a83;
    ret.template get<84>() = a84;
    ret.template get<85>() = a85;
    ret.template get<86>() = a86;
    ret.template get<87>() = a87;
    ret.template get<88>() = a88;
    ret.template get<89>() = a89;
    ret.template get<90>() = a90;
    ret.template get<91>() = a91;
    ret.template get<92>() = a92;
    ret.template get<93>() = a93;
    ret.template get<94>() = a94;
    ret.template get<95>() = a95;
    ret.template get<96>() = a96;
    ret.template get<97>() = a97;
    ret.template get<98>() = a98;
    ret.template get<99>() = a99;
    ret.template get<100>() = a100;
    ret.template get<101>() = a101;
    ret.template get<102>() = a102;
    ret.template get<103>() = a103;
    ret.template get<104>() = a104;
    ret.template get<105>() = a105;
    ret.template get<106>() = a106;
    ret.template get<107>() = a107;
    ret.template get<108>() = a108;
    ret.template get<109>() = a109;
    ret.template get<110>() = a110;
    ret.template get<111>() = a111;
    ret.template get<112>() = a112;
    ret.template get<113>() = a113;
    ret.template get<114>() = a114;
    ret.template get<115>() = a115;
    ret.template get<116>() = a116;
    ret.template get<117>() = a117;
    ret.template get<118>() = a118;
    ret.template get<119>() = a119;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 121>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61,
           a62,
           a63,
           a64,
           a65,
           a66,
           a67,
           a68,
           a69,
           a70,
           a71,
           a72,
           a73,
           a74,
           a75,
           a76,
           a77,
           a78,
           a79,
           a80,
           a81,
           a82,
           a83,
           a84,
           a85,
           a86,
           a87,
           a88,
           a89,
           a90,
           a91,
           a92,
           a93,
           a94,
           a95,
           a96,
           a97,
           a98,
           a99,
           a100,
           a101,
           a102,
           a103,
           a104,
           a105,
           a106,
           a107,
           a108,
           a109,
           a110,
           a111,
           a112,
           a113,
           a114,
           a115,
           a116,
           a117,
           a118,
           a119,
           a120    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    ret.template get<62>() = a62;
    ret.template get<63>() = a63;
    ret.template get<64>() = a64;
    ret.template get<65>() = a65;
    ret.template get<66>() = a66;
    ret.template get<67>() = a67;
    ret.template get<68>() = a68;
    ret.template get<69>() = a69;
    ret.template get<70>() = a70;
    ret.template get<71>() = a71;
    ret.template get<72>() = a72;
    ret.template get<73>() = a73;
    ret.template get<74>() = a74;
    ret.template get<75>() = a75;
    ret.template get<76>() = a76;
    ret.template get<77>() = a77;
    ret.template get<78>() = a78;
    ret.template get<79>() = a79;
    ret.template get<80>() = a80;
    ret.template get<81>() = a81;
    ret.template get<82>() = a82;
    ret.template get<83>() = a83;
    ret.template get<84>() = a84;
    ret.template get<85>() = a85;
    ret.template get<86>() = a86;
    ret.template get<87>() = a87;
    ret.template get<88>() = a88;
    ret.template get<89>() = a89;
    ret.template get<90>() = a90;
    ret.template get<91>() = a91;
    ret.template get<92>() = a92;
    ret.template get<93>() = a93;
    ret.template get<94>() = a94;
    ret.template get<95>() = a95;
    ret.template get<96>() = a96;
    ret.template get<97>() = a97;
    ret.template get<98>() = a98;
    ret.template get<99>() = a99;
    ret.template get<100>() = a100;
    ret.template get<101>() = a101;
    ret.template get<102>() = a102;
    ret.template get<103>() = a103;
    ret.template get<104>() = a104;
    ret.template get<105>() = a105;
    ret.template get<106>() = a106;
    ret.template get<107>() = a107;
    ret.template get<108>() = a108;
    ret.template get<109>() = a109;
    ret.template get<110>() = a110;
    ret.template get<111>() = a111;
    ret.template get<112>() = a112;
    ret.template get<113>() = a113;
    ret.template get<114>() = a114;
    ret.template get<115>() = a115;
    ret.template get<116>() = a116;
    ret.template get<117>() = a117;
    ret.template get<118>() = a118;
    ret.template get<119>() = a119;
    ret.template get<120>() = a120;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 122>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61,
           a62,
           a63,
           a64,
           a65,
           a66,
           a67,
           a68,
           a69,
           a70,
           a71,
           a72,
           a73,
           a74,
           a75,
           a76,
           a77,
           a78,
           a79,
           a80,
           a81,
           a82,
           a83,
           a84,
           a85,
           a86,
           a87,
           a88,
           a89,
           a90,
           a91,
           a92,
           a93,
           a94,
           a95,
           a96,
           a97,
           a98,
           a99,
           a100,
           a101,
           a102,
           a103,
           a104,
           a105,
           a106,
           a107,
           a108,
           a109,
           a110,
           a111,
           a112,
           a113,
           a114,
           a115,
           a116,
           a117,
           a118,
           a119,
           a120,
           a121    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    ret.template get<62>() = a62;
    ret.template get<63>() = a63;
    ret.template get<64>() = a64;
    ret.template get<65>() = a65;
    ret.template get<66>() = a66;
    ret.template get<67>() = a67;
    ret.template get<68>() = a68;
    ret.template get<69>() = a69;
    ret.template get<70>() = a70;
    ret.template get<71>() = a71;
    ret.template get<72>() = a72;
    ret.template get<73>() = a73;
    ret.template get<74>() = a74;
    ret.template get<75>() = a75;
    ret.template get<76>() = a76;
    ret.template get<77>() = a77;
    ret.template get<78>() = a78;
    ret.template get<79>() = a79;
    ret.template get<80>() = a80;
    ret.template get<81>() = a81;
    ret.template get<82>() = a82;
    ret.template get<83>() = a83;
    ret.template get<84>() = a84;
    ret.template get<85>() = a85;
    ret.template get<86>() = a86;
    ret.template get<87>() = a87;
    ret.template get<88>() = a88;
    ret.template get<89>() = a89;
    ret.template get<90>() = a90;
    ret.template get<91>() = a91;
    ret.template get<92>() = a92;
    ret.template get<93>() = a93;
    ret.template get<94>() = a94;
    ret.template get<95>() = a95;
    ret.template get<96>() = a96;
    ret.template get<97>() = a97;
    ret.template get<98>() = a98;
    ret.template get<99>() = a99;
    ret.template get<100>() = a100;
    ret.template get<101>() = a101;
    ret.template get<102>() = a102;
    ret.template get<103>() = a103;
    ret.template get<104>() = a104;
    ret.template get<105>() = a105;
    ret.template get<106>() = a106;
    ret.template get<107>() = a107;
    ret.template get<108>() = a108;
    ret.template get<109>() = a109;
    ret.template get<110>() = a110;
    ret.template get<111>() = a111;
    ret.template get<112>() = a112;
    ret.template get<113>() = a113;
    ret.template get<114>() = a114;
    ret.template get<115>() = a115;
    ret.template get<116>() = a116;
    ret.template get<117>() = a117;
    ret.template get<118>() = a118;
    ret.template get<119>() = a119;
    ret.template get<120>() = a120;
    ret.template get<121>() = a121;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 123>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61,
           a62,
           a63,
           a64,
           a65,
           a66,
           a67,
           a68,
           a69,
           a70,
           a71,
           a72,
           a73,
           a74,
           a75,
           a76,
           a77,
           a78,
           a79,
           a80,
           a81,
           a82,
           a83,
           a84,
           a85,
           a86,
           a87,
           a88,
           a89,
           a90,
           a91,
           a92,
           a93,
           a94,
           a95,
           a96,
           a97,
           a98,
           a99,
           a100,
           a101,
           a102,
           a103,
           a104,
           a105,
           a106,
           a107,
           a108,
           a109,
           a110,
           a111,
           a112,
           a113,
           a114,
           a115,
           a116,
           a117,
           a118,
           a119,
           a120,
           a121,
           a122    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    ret.template get<62>() = a62;
    ret.template get<63>() = a63;
    ret.template get<64>() = a64;
    ret.template get<65>() = a65;
    ret.template get<66>() = a66;
    ret.template get<67>() = a67;
    ret.template get<68>() = a68;
    ret.template get<69>() = a69;
    ret.template get<70>() = a70;
    ret.template get<71>() = a71;
    ret.template get<72>() = a72;
    ret.template get<73>() = a73;
    ret.template get<74>() = a74;
    ret.template get<75>() = a75;
    ret.template get<76>() = a76;
    ret.template get<77>() = a77;
    ret.template get<78>() = a78;
    ret.template get<79>() = a79;
    ret.template get<80>() = a80;
    ret.template get<81>() = a81;
    ret.template get<82>() = a82;
    ret.template get<83>() = a83;
    ret.template get<84>() = a84;
    ret.template get<85>() = a85;
    ret.template get<86>() = a86;
    ret.template get<87>() = a87;
    ret.template get<88>() = a88;
    ret.template get<89>() = a89;
    ret.template get<90>() = a90;
    ret.template get<91>() = a91;
    ret.template get<92>() = a92;
    ret.template get<93>() = a93;
    ret.template get<94>() = a94;
    ret.template get<95>() = a95;
    ret.template get<96>() = a96;
    ret.template get<97>() = a97;
    ret.template get<98>() = a98;
    ret.template get<99>() = a99;
    ret.template get<100>() = a100;
    ret.template get<101>() = a101;
    ret.template get<102>() = a102;
    ret.template get<103>() = a103;
    ret.template get<104>() = a104;
    ret.template get<105>() = a105;
    ret.template get<106>() = a106;
    ret.template get<107>() = a107;
    ret.template get<108>() = a108;
    ret.template get<109>() = a109;
    ret.template get<110>() = a110;
    ret.template get<111>() = a111;
    ret.template get<112>() = a112;
    ret.template get<113>() = a113;
    ret.template get<114>() = a114;
    ret.template get<115>() = a115;
    ret.template get<116>() = a116;
    ret.template get<117>() = a117;
    ret.template get<118>() = a118;
    ret.template get<119>() = a119;
    ret.template get<120>() = a120;
    ret.template get<121>() = a121;
    ret.template get<122>() = a122;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 124>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61,
           a62,
           a63,
           a64,
           a65,
           a66,
           a67,
           a68,
           a69,
           a70,
           a71,
           a72,
           a73,
           a74,
           a75,
           a76,
           a77,
           a78,
           a79,
           a80,
           a81,
           a82,
           a83,
           a84,
           a85,
           a86,
           a87,
           a88,
           a89,
           a90,
           a91,
           a92,
           a93,
           a94,
           a95,
           a96,
           a97,
           a98,
           a99,
           a100,
           a101,
           a102,
           a103,
           a104,
           a105,
           a106,
           a107,
           a108,
           a109,
           a110,
           a111,
           a112,
           a113,
           a114,
           a115,
           a116,
           a117,
           a118,
           a119,
           a120,
           a121,
           a122,
           a123    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    ret.template get<62>() = a62;
    ret.template get<63>() = a63;
    ret.template get<64>() = a64;
    ret.template get<65>() = a65;
    ret.template get<66>() = a66;
    ret.template get<67>() = a67;
    ret.template get<68>() = a68;
    ret.template get<69>() = a69;
    ret.template get<70>() = a70;
    ret.template get<71>() = a71;
    ret.template get<72>() = a72;
    ret.template get<73>() = a73;
    ret.template get<74>() = a74;
    ret.template get<75>() = a75;
    ret.template get<76>() = a76;
    ret.template get<77>() = a77;
    ret.template get<78>() = a78;
    ret.template get<79>() = a79;
    ret.template get<80>() = a80;
    ret.template get<81>() = a81;
    ret.template get<82>() = a82;
    ret.template get<83>() = a83;
    ret.template get<84>() = a84;
    ret.template get<85>() = a85;
    ret.template get<86>() = a86;
    ret.template get<87>() = a87;
    ret.template get<88>() = a88;
    ret.template get<89>() = a89;
    ret.template get<90>() = a90;
    ret.template get<91>() = a91;
    ret.template get<92>() = a92;
    ret.template get<93>() = a93;
    ret.template get<94>() = a94;
    ret.template get<95>() = a95;
    ret.template get<96>() = a96;
    ret.template get<97>() = a97;
    ret.template get<98>() = a98;
    ret.template get<99>() = a99;
    ret.template get<100>() = a100;
    ret.template get<101>() = a101;
    ret.template get<102>() = a102;
    ret.template get<103>() = a103;
    ret.template get<104>() = a104;
    ret.template get<105>() = a105;
    ret.template get<106>() = a106;
    ret.template get<107>() = a107;
    ret.template get<108>() = a108;
    ret.template get<109>() = a109;
    ret.template get<110>() = a110;
    ret.template get<111>() = a111;
    ret.template get<112>() = a112;
    ret.template get<113>() = a113;
    ret.template get<114>() = a114;
    ret.template get<115>() = a115;
    ret.template get<116>() = a116;
    ret.template get<117>() = a117;
    ret.template get<118>() = a118;
    ret.template get<119>() = a119;
    ret.template get<120>() = a120;
    ret.template get<121>() = a121;
    ret.template get<122>() = a122;
    ret.template get<123>() = a123;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 125>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61,
           a62,
           a63,
           a64,
           a65,
           a66,
           a67,
           a68,
           a69,
           a70,
           a71,
           a72,
           a73,
           a74,
           a75,
           a76,
           a77,
           a78,
           a79,
           a80,
           a81,
           a82,
           a83,
           a84,
           a85,
           a86,
           a87,
           a88,
           a89,
           a90,
           a91,
           a92,
           a93,
           a94,
           a95,
           a96,
           a97,
           a98,
           a99,
           a100,
           a101,
           a102,
           a103,
           a104,
           a105,
           a106,
           a107,
           a108,
           a109,
           a110,
           a111,
           a112,
           a113,
           a114,
           a115,
           a116,
           a117,
           a118,
           a119,
           a120,
           a121,
           a122,
           a123,
           a124    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    ret.template get<62>() = a62;
    ret.template get<63>() = a63;
    ret.template get<64>() = a64;
    ret.template get<65>() = a65;
    ret.template get<66>() = a66;
    ret.template get<67>() = a67;
    ret.template get<68>() = a68;
    ret.template get<69>() = a69;
    ret.template get<70>() = a70;
    ret.template get<71>() = a71;
    ret.template get<72>() = a72;
    ret.template get<73>() = a73;
    ret.template get<74>() = a74;
    ret.template get<75>() = a75;
    ret.template get<76>() = a76;
    ret.template get<77>() = a77;
    ret.template get<78>() = a78;
    ret.template get<79>() = a79;
    ret.template get<80>() = a80;
    ret.template get<81>() = a81;
    ret.template get<82>() = a82;
    ret.template get<83>() = a83;
    ret.template get<84>() = a84;
    ret.template get<85>() = a85;
    ret.template get<86>() = a86;
    ret.template get<87>() = a87;
    ret.template get<88>() = a88;
    ret.template get<89>() = a89;
    ret.template get<90>() = a90;
    ret.template get<91>() = a91;
    ret.template get<92>() = a92;
    ret.template get<93>() = a93;
    ret.template get<94>() = a94;
    ret.template get<95>() = a95;
    ret.template get<96>() = a96;
    ret.template get<97>() = a97;
    ret.template get<98>() = a98;
    ret.template get<99>() = a99;
    ret.template get<100>() = a100;
    ret.template get<101>() = a101;
    ret.template get<102>() = a102;
    ret.template get<103>() = a103;
    ret.template get<104>() = a104;
    ret.template get<105>() = a105;
    ret.template get<106>() = a106;
    ret.template get<107>() = a107;
    ret.template get<108>() = a108;
    ret.template get<109>() = a109;
    ret.template get<110>() = a110;
    ret.template get<111>() = a111;
    ret.template get<112>() = a112;
    ret.template get<113>() = a113;
    ret.template get<114>() = a114;
    ret.template get<115>() = a115;
    ret.template get<116>() = a116;
    ret.template get<117>() = a117;
    ret.template get<118>() = a118;
    ret.template get<119>() = a119;
    ret.template get<120>() = a120;
    ret.template get<121>() = a121;
    ret.template get<122>() = a122;
    ret.template get<123>() = a123;
    ret.template get<124>() = a124;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 126>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61,
           a62,
           a63,
           a64,
           a65,
           a66,
           a67,
           a68,
           a69,
           a70,
           a71,
           a72,
           a73,
           a74,
           a75,
           a76,
           a77,
           a78,
           a79,
           a80,
           a81,
           a82,
           a83,
           a84,
           a85,
           a86,
           a87,
           a88,
           a89,
           a90,
           a91,
           a92,
           a93,
           a94,
           a95,
           a96,
           a97,
           a98,
           a99,
           a100,
           a101,
           a102,
           a103,
           a104,
           a105,
           a106,
           a107,
           a108,
           a109,
           a110,
           a111,
           a112,
           a113,
           a114,
           a115,
           a116,
           a117,
           a118,
           a119,
           a120,
           a121,
           a122,
           a123,
           a124,
           a125    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    ret.template get<62>() = a62;
    ret.template get<63>() = a63;
    ret.template get<64>() = a64;
    ret.template get<65>() = a65;
    ret.template get<66>() = a66;
    ret.template get<67>() = a67;
    ret.template get<68>() = a68;
    ret.template get<69>() = a69;
    ret.template get<70>() = a70;
    ret.template get<71>() = a71;
    ret.template get<72>() = a72;
    ret.template get<73>() = a73;
    ret.template get<74>() = a74;
    ret.template get<75>() = a75;
    ret.template get<76>() = a76;
    ret.template get<77>() = a77;
    ret.template get<78>() = a78;
    ret.template get<79>() = a79;
    ret.template get<80>() = a80;
    ret.template get<81>() = a81;
    ret.template get<82>() = a82;
    ret.template get<83>() = a83;
    ret.template get<84>() = a84;
    ret.template get<85>() = a85;
    ret.template get<86>() = a86;
    ret.template get<87>() = a87;
    ret.template get<88>() = a88;
    ret.template get<89>() = a89;
    ret.template get<90>() = a90;
    ret.template get<91>() = a91;
    ret.template get<92>() = a92;
    ret.template get<93>() = a93;
    ret.template get<94>() = a94;
    ret.template get<95>() = a95;
    ret.template get<96>() = a96;
    ret.template get<97>() = a97;
    ret.template get<98>() = a98;
    ret.template get<99>() = a99;
    ret.template get<100>() = a100;
    ret.template get<101>() = a101;
    ret.template get<102>() = a102;
    ret.template get<103>() = a103;
    ret.template get<104>() = a104;
    ret.template get<105>() = a105;
    ret.template get<106>() = a106;
    ret.template get<107>() = a107;
    ret.template get<108>() = a108;
    ret.template get<109>() = a109;
    ret.template get<110>() = a110;
    ret.template get<111>() = a111;
    ret.template get<112>() = a112;
    ret.template get<113>() = a113;
    ret.template get<114>() = a114;
    ret.template get<115>() = a115;
    ret.template get<116>() = a116;
    ret.template get<117>() = a117;
    ret.template get<118>() = a118;
    ret.template get<119>() = a119;
    ret.template get<120>() = a120;
    ret.template get<121>() = a121;
    ret.template get<122>() = a122;
    ret.template get<123>() = a123;
    ret.template get<124>() = a124;
    ret.template get<125>() = a125;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 127>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61,
           a62,
           a63,
           a64,
           a65,
           a66,
           a67,
           a68,
           a69,
           a70,
           a71,
           a72,
           a73,
           a74,
           a75,
           a76,
           a77,
           a78,
           a79,
           a80,
           a81,
           a82,
           a83,
           a84,
           a85,
           a86,
           a87,
           a88,
           a89,
           a90,
           a91,
           a92,
           a93,
           a94,
           a95,
           a96,
           a97,
           a98,
           a99,
           a100,
           a101,
           a102,
           a103,
           a104,
           a105,
           a106,
           a107,
           a108,
           a109,
           a110,
           a111,
           a112,
           a113,
           a114,
           a115,
           a116,
           a117,
           a118,
           a119,
           a120,
           a121,
           a122,
           a123,
           a124,
           a125,
           a126    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    ret.template get<62>() = a62;
    ret.template get<63>() = a63;
    ret.template get<64>() = a64;
    ret.template get<65>() = a65;
    ret.template get<66>() = a66;
    ret.template get<67>() = a67;
    ret.template get<68>() = a68;
    ret.template get<69>() = a69;
    ret.template get<70>() = a70;
    ret.template get<71>() = a71;
    ret.template get<72>() = a72;
    ret.template get<73>() = a73;
    ret.template get<74>() = a74;
    ret.template get<75>() = a75;
    ret.template get<76>() = a76;
    ret.template get<77>() = a77;
    ret.template get<78>() = a78;
    ret.template get<79>() = a79;
    ret.template get<80>() = a80;
    ret.template get<81>() = a81;
    ret.template get<82>() = a82;
    ret.template get<83>() = a83;
    ret.template get<84>() = a84;
    ret.template get<85>() = a85;
    ret.template get<86>() = a86;
    ret.template get<87>() = a87;
    ret.template get<88>() = a88;
    ret.template get<89>() = a89;
    ret.template get<90>() = a90;
    ret.template get<91>() = a91;
    ret.template get<92>() = a92;
    ret.template get<93>() = a93;
    ret.template get<94>() = a94;
    ret.template get<95>() = a95;
    ret.template get<96>() = a96;
    ret.template get<97>() = a97;
    ret.template get<98>() = a98;
    ret.template get<99>() = a99;
    ret.template get<100>() = a100;
    ret.template get<101>() = a101;
    ret.template get<102>() = a102;
    ret.template get<103>() = a103;
    ret.template get<104>() = a104;
    ret.template get<105>() = a105;
    ret.template get<106>() = a106;
    ret.template get<107>() = a107;
    ret.template get<108>() = a108;
    ret.template get<109>() = a109;
    ret.template get<110>() = a110;
    ret.template get<111>() = a111;
    ret.template get<112>() = a112;
    ret.template get<113>() = a113;
    ret.template get<114>() = a114;
    ret.template get<115>() = a115;
    ret.template get<116>() = a116;
    ret.template get<117>() = a117;
    ret.template get<118>() = a118;
    ret.template get<119>() = a119;
    ret.template get<120>() = a120;
    ret.template get<121>() = a121;
    ret.template get<122>() = a122;
    ret.template get<123>() = a123;
    ret.template get<124>() = a124;
    ret.template get<125>() = a125;
    ret.template get<126>() = a126;
    return ret;
  }
};

template <class T> struct variadic_structured_binding<T, 128>
{
  CUDA_HOS_DEV static auto struct_to_nested(const T &s)
  {
    auto [ a0,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48,
           a49,
           a50,
           a51,
           a52,
           a53,
           a54,
           a55,
           a56,
           a57,
           a58,
           a59,
           a60,
           a61,
           a62,
           a63,
           a64,
           a65,
           a66,
           a67,
           a68,
           a69,
           a70,
           a71,
           a72,
           a73,
           a74,
           a75,
           a76,
           a77,
           a78,
           a79,
           a80,
           a81,
           a82,
           a83,
           a84,
           a85,
           a86,
           a87,
           a88,
           a89,
           a90,
           a91,
           a92,
           a93,
           a94,
           a95,
           a96,
           a97,
           a98,
           a99,
           a100,
           a101,
           a102,
           a103,
           a104,
           a105,
           a106,
           a107,
           a108,
           a109,
           a110,
           a111,
           a112,
           a113,
           a114,
           a115,
           a116,
           a117,
           a118,
           a119,
           a120,
           a121,
           a122,
           a123,
           a124,
           a125,
           a126,
           a127    ] = s;
    nested_imitation_struct<T> ret;
    ret.template get<0>() = a0;
    ret.template get<1>() = a1;
    ret.template get<2>() = a2;
    ret.template get<3>() = a3;
    ret.template get<4>() = a4;
    ret.template get<5>() = a5;
    ret.template get<6>() = a6;
    ret.template get<7>() = a7;
    ret.template get<8>() = a8;
    ret.template get<9>() = a9;
    ret.template get<10>() = a10;
    ret.template get<11>() = a11;
    ret.template get<12>() = a12;
    ret.template get<13>() = a13;
    ret.template get<14>() = a14;
    ret.template get<15>() = a15;
    ret.template get<16>() = a16;
    ret.template get<17>() = a17;
    ret.template get<18>() = a18;
    ret.template get<19>() = a19;
    ret.template get<20>() = a20;
    ret.template get<21>() = a21;
    ret.template get<22>() = a22;
    ret.template get<23>() = a23;
    ret.template get<24>() = a24;
    ret.template get<25>() = a25;
    ret.template get<26>() = a26;
    ret.template get<27>() = a27;
    ret.template get<28>() = a28;
    ret.template get<29>() = a29;
    ret.template get<30>() = a30;
    ret.template get<31>() = a31;
    ret.template get<32>() = a32;
    ret.template get<33>() = a33;
    ret.template get<34>() = a34;
    ret.template get<35>() = a35;
    ret.template get<36>() = a36;
    ret.template get<37>() = a37;
    ret.template get<38>() = a38;
    ret.template get<39>() = a39;
    ret.template get<40>() = a40;
    ret.template get<41>() = a41;
    ret.template get<42>() = a42;
    ret.template get<43>() = a43;
    ret.template get<44>() = a44;
    ret.template get<45>() = a45;
    ret.template get<46>() = a46;
    ret.template get<47>() = a47;
    ret.template get<48>() = a48;
    ret.template get<49>() = a49;
    ret.template get<50>() = a50;
    ret.template get<51>() = a51;
    ret.template get<52>() = a52;
    ret.template get<53>() = a53;
    ret.template get<54>() = a54;
    ret.template get<55>() = a55;
    ret.template get<56>() = a56;
    ret.template get<57>() = a57;
    ret.template get<58>() = a58;
    ret.template get<59>() = a59;
    ret.template get<60>() = a60;
    ret.template get<61>() = a61;
    ret.template get<62>() = a62;
    ret.template get<63>() = a63;
    ret.template get<64>() = a64;
    ret.template get<65>() = a65;
    ret.template get<66>() = a66;
    ret.template get<67>() = a67;
    ret.template get<68>() = a68;
    ret.template get<69>() = a69;
    ret.template get<70>() = a70;
    ret.template get<71>() = a71;
    ret.template get<72>() = a72;
    ret.template get<73>() = a73;
    ret.template get<74>() = a74;
    ret.template get<75>() = a75;
    ret.template get<76>() = a76;
    ret.template get<77>() = a77;
    ret.template get<78>() = a78;
    ret.template get<79>() = a79;
    ret.template get<80>() = a80;
    ret.template get<81>() = a81;
    ret.template get<82>() = a82;
    ret.template get<83>() = a83;
    ret.template get<84>() = a84;
    ret.template get<85>() = a85;
    ret.template get<86>() = a86;
    ret.template get<87>() = a87;
    ret.template get<88>() = a88;
    ret.template get<89>() = a89;
    ret.template get<90>() = a90;
    ret.template get<91>() = a91;
    ret.template get<92>() = a92;
    ret.template get<93>() = a93;
    ret.template get<94>() = a94;
    ret.template get<95>() = a95;
    ret.template get<96>() = a96;
    ret.template get<97>() = a97;
    ret.template get<98>() = a98;
    ret.template get<99>() = a99;
    ret.template get<100>() = a100;
    ret.template get<101>() = a101;
    ret.template get<102>() = a102;
    ret.template get<103>() = a103;
    ret.template get<104>() = a104;
    ret.template get<105>() = a105;
    ret.template get<106>() = a106;
    ret.template get<107>() = a107;
    ret.template get<108>() = a108;
    ret.template get<109>() = a109;
    ret.template get<110>() = a110;
    ret.template get<111>() = a111;
    ret.template get<112>() = a112;
    ret.template get<113>() = a113;
    ret.template get<114>() = a114;
    ret.template get<115>() = a115;
    ret.template get<116>() = a116;
    ret.template get<117>() = a117;
    ret.template get<118>() = a118;
    ret.template get<119>() = a119;
    ret.template get<120>() = a120;
    ret.template get<121>() = a121;
    ret.template get<122>() = a122;
    ret.template get<123>() = a123;
    ret.template get<124>() = a124;
    ret.template get<125>() = a125;
    ret.template get<126>() = a126;
    ret.template get<127>() = a127;
    return ret;
  }
};


///\endcond

#endif

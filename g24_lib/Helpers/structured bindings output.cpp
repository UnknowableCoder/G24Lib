/****************************************************************
 *                                                              *
 *             STRUCTURED BINDINGS OUTPUT HELPER                *
 *                                                              *
 *  This prints out several functions to allow the use of       *
 * structured bindings with (almost) arbitrarily-sized structs; *
 * since structured bindings aren't (yet) variadic, we must     *
 * hard-code them. It's a lot of repetitive code, so we output  *
 * it through this.                                             *
 ****************************************************************/
 
#include <fstream>


#define HOW_MANY 128

void print_one(std::ofstream& out, const size_t number, const char* prefix = "", const char* suffix = "", const char* separator = " ")
{
  for(size_t i = 0; i < number-1; ++i)
    {
      out << prefix << i << suffix << separator;
    }
  out << prefix << number-1 << suffix;
}

void print_two(std::ofstream& out, const size_t number, const char* before = "", const char * middle = " ", const char* after = "")
{
  for(size_t i = 0; i < number; ++i)
    {
      out << before << i << middle << i << after;
    }
}


void print_template(std::ofstream& out, const size_t number)
{
  out << "template <class T> struct variadic_structured_binding<T, " << number << ">\n"
      << "{\n"
      << "  CUDA_HOS_DEV static auto struct_to_nested(const T &s)\n"
      << "  {\n"
      << "    auto [ ";
  print_one(out, number, "a", "", ",\n           ");
  out <<                                 "    ] = s;\n"
      << "    nested_imitation_struct<T> ret;\n";
      //<< "      auto& [ *2 ] = ret;\n"
      //<< "      *2 = *1;\n"
  print_two(out, number, "    ret.template get<", ">() = a", ";\n");
  out << "    return ret;\n"
      << "  }\n"
      << "};\n\n";
}
int main()
{
  std::ofstream out("varsb.h");
  out << "#ifndef G24_LIB_VAR_S_B_AUTOGEN\n#define G24_LIB_VAR_S_B_AUTOGEN\n\n///\\cond HIDDEN_SYMBOLS\n\n";
  for (size_t i = 2; i <= HOW_MANY; ++i)
    {
      print_template(out, i);
    }
  out << "\n///\\endcond\n\n#endif" << std::endl;
}

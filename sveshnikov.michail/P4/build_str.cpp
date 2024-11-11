#include "rep_sym.hpp"

std::istream &sveshnikov::build_str(std::istream &in, char *str)
{
  for (size_t i = 0; std::cin != '\n'; i++)
  {
    in >> str[i];
  }
  return in;
}

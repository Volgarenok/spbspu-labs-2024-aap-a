#include <iostream>
#include <ios>
#include "rep_sym.hpp"

int main()
{
  std::size_t len = 100;
  char *str = new char[len];
  char *new_str = nullptr;
  std::noskipws(std::cin);
  sveshnikov::read_str(std::cin, str, len);
  char *new_str = new char[len];
  new_str = sveshnikov::rep_sym(str, new_str);
  std::skipws(std::cin);
  return 0;
}

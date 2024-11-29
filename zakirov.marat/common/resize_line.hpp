#ifndef RESIZE_LINE_HPP
#define RESIZE_LINE_HPP
#include <iostream>
namespace zakirov
{
  char * expand_line(char const * line, size_t real_lenght, size_t add_length);
  void get_line(std::istream & in, char * line, size_t start, size_t finish);
}
#endif

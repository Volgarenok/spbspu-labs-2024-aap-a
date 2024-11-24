#ifndef RESIZE_LINE_HPP
#define RESIZE_LINE_HPP
#include <iostream>
namespace zakirov
{
  void get_line(std::istream & in, char * line, size_t start, size_t finish);
  char * expand_line(char * line, size_t real_lenght, size_t add_length);
}
#endif

#ifndef RESIZE_LINE_HPP
#define RESIZE_LINE_HPP
#include <iostream>
namespace zakirov
{
  char * expand_line(char const * regular_line, size_t real_lenght, size_t add_length);
  double * expand_line(const double * array, size_t size);
  void get_segment(std::istream & in, char * line, size_t start, size_t finish, char interrupt_el);
  char * get_line(std::istream & in, size_t step, char interrupt_el = '\0');
}
#endif

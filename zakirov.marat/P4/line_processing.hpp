#ifndef LINE_PROCESSING_HPP
#define LINE_PROCESSING_HPP
#include <iostream>
namespace zakirov
{
  char * get_line(std::istream & in, char * line, size_t start, size_t finish);
  char * expand_line(char * line, size_t real_lenght, size_t add_length);
  char * change_line(char * line, char stop);
}
#endif

#include "line_processing.hpp"
#include <iostream>

char * get_line(std::istream & in, char * line, size_t start, size_t finish)
{
  for (; start < finish; ++start)
  {
    in >> line[start];
  }

  return line;
}

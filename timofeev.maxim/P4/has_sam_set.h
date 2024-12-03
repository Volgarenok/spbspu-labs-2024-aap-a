#ifndef HAS_SAM_SET_H
#define HAS_SAM_SET_H

#include <iostream>
#include <fstream>
#include <ios>

namespace timofeev
{
  char* input_line(std::istream& in);
  int same_symbols(const char* first_line, const char* second_line);
}

#endif

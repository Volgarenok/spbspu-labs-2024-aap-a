#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <ios>

namespace timofeev
{
  char* boost_size(char* value_line, size_t capacity);
  char* input_line(std::istream& in);
  int same_symbols(const char* first_line, const char* second_line);
}

#endif

#ifndef DYNAMICARRAY_HPP
#define DYNAMICARRAY_HPP
#include <cstddef>
#include <iostream>
namespace nikonov
{
  char* getLine(std::istream& input, size_t& capacity);
  void fillLine(char* line, char what = '\0');
  void transferLine(char* oldLine, char* newLine);
  char* reallocate(char* line, size_t& capacity, int addSizeOptional = -1);
}
#endif

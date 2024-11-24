#ifndef LINEINPUT_HPP
#define LINEINPUT_HPP
#include <cstddef>
#include <iostream>
namespace nikonov
{
  char* getLine(std::istream& input, size_t& capacity);
  char* reallocate(char* line, size_t& capacity, int addSizeOptional = -1);
}
#endif

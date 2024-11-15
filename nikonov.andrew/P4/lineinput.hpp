#ifndef LINEINPUT_HPP
#define LINEINPUT_HPP
#include <cstddef>
namespace nikonov
{
  char* getLine(size_t& capacity);
  char* reallocate(char* line, size_t& capacity);
  char* reallocate(char* line, size_t& capacity, size_t addSize);
  #endif
}

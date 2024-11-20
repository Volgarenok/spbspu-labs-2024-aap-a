#ifndef LINE_UTILS_HPP
#define LINE_UTILS_HPP
#include <cstddef>
namespace nikonov
{
  char* getLine(size_t& capacity);
  char* reallocate(char* line, size_t& capacity);
  char* reallocate(char* line, size_t& capacity, size_t addSize);
  void printLine(const char* line);
  #endif
}

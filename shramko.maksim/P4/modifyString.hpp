#ifndef MODIFYSTRING_HPP
#define MODIFYSTRING_HPP

#include <cstddef>

namespace shramko
{
  char* createBiggerStrMemory(size_t memory, const char* str);
  size_t countConsecutiveIdenticalSymbols(const char* str);
}

#endif

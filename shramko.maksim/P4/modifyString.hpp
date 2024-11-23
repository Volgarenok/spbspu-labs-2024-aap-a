#ifndef MODIFYSTRING_HPP
#define MODIFYSTRING_HPP

#include <cstddef>

namespace shramko
{
  char* createBiggerStrMemory(size_t memory, char* str);
  size_t countConsecutiveIdenticalSymbols(char* str);
}

#endif

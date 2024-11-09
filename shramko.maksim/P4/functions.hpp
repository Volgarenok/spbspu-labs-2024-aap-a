#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <cstddef>

namespace shramko
{
  char* createBiggerStrMemory(size_t memory, char* str);
  size_t countConsecutiveIdenticalSymbols(char* str);
}

#endif

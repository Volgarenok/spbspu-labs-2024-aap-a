#ifndef MODIFYSTRING_HPP
#define MODIFYSTRING_HPP

#include <cstddef>
#include <iostream>

namespace shramko
{
  char* createBiggerStrMemory(size_t memory, const char* str);
  size_t countConsecutiveIdenticalSymbols(const char* str);
  char* inputStr(std::istream& in);
}

#endif

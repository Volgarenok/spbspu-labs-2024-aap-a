#ifndef INPUTSTRING_HPP
#define INPUTSTRING_HPP

#include <cstddef>
#include <istream>

namespace shramko
{
  char* createBiggerStrMemory(size_t memory, const char* str);
  char* inputStr(std::istream& in);
}

#endif

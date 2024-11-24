#ifndef STRINGINPUT_H
#define STRINGINPUT_H

#include <cstddef>
#include <fstream>

namespace tkach
{
  char* getMemoryForStr(const char* str, size_t& capacity);
  char* inputStr(std::istream& in, size_t& capacity);
}

#endif

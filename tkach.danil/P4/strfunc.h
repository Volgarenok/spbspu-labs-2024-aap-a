#ifndef STRFUNC_H
#define STRFUNC_H

#include <cstddef>
#include <fstream>

namespace tkach
{
  char* getMemoryForStr(char* str, size_t& capacity);
  char* inputStr(std::istream& in, char* str, size_t& capacity);
}

#endif

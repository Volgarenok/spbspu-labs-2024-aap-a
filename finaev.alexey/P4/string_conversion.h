#ifndef STRING_CONVERSION_H
#define STRING_CONVERSION_H
#include <cstddef>
#include <fstream>

namespace finaev
{
  void transferStr(char* new_str, const char* str, size_t length);
  char* creatureStr(size_t capacity);
  char* fillStr(std::istream& in);
  int isRepeat(const char* str);
}

#endif

#ifndef STRING_CONVERSION_H
#define STRING_CONVERSION_H
#include <cstddef>
#include <fstream>

namespace finaev
{
  void transferStr(char* new_str, const char* str, size_t length);
  char* fillStr(std::istream& in);
  int checkRepeat(const char* str);
}

#endif

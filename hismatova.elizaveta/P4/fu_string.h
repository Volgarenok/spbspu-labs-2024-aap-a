#ifndef FU_STRING_H
#define FU_STRING_H
#include <cstddef>

namespace hismatova
{
  char* makeString(size_t size);
  char* remakeString(char* str, size_t size2);
  char* uniqueChar(const char* str1, const char* str2);
}

#endif

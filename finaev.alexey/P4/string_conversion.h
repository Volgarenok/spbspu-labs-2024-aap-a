#ifndef STRING_CONVERSION_H
#define STRING_CONVERSION_H
#include <cstddef>
#include <fstream>

namespace finaev
{
  void MEMcpy(char* new_str, const char* str, size_t dl);
  char* creature_empty_str(size_t dl);
  char* fill_str(std::istream& in, char* str);
  int is_repeat(const char* str);
}

#endif

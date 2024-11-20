#ifndef STRING_CONVERSION_H
#define STRING_CONVERSION_H
#include <cstddef>
#include <fstream>

namespace finaev
{
  void MEMcpy(char* new_a, const char* a);
  char* creature_empty_str(size_t dl);
  char* fill_str(std::istream& in);
  int is_repeat(const char* str);
}

#endif

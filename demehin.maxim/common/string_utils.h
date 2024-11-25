#ifndef STRING_UTILS_H
#define STRING_UTILS_H
#include <iostream>

namespace demehin
{
  char* copyString(const char* str, size_t size);
  void getString(std::istream& in, char** str, char stop, size_t max_size);
}

#endif

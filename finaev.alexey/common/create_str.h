#ifndef CREATE_STR_H
#define CREATE_STR_H
#include <fstream>

namespace finaev
{
  void transferStr(char* new_str, const char* str, size_t length);
  char* fillStr(std::istream& in);
}

#endif

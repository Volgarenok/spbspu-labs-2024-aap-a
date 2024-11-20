#ifndef RECURSIVECHECKS_H
#define RECURSIVECHECKS_H
#include <cstring>

namespace duhanina
{
  bool isSign(char c);
  bool isUnsignedInt(const char* str, size_t& index);
  bool isMantissa(const char* str, size_t& index);
  bool isOrder(const char* str, size_t& index);
  bool isReal(const char* str);
}

#endif

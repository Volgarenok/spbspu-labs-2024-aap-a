#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <cstddef>

namespace hismatova
{
  bool isValidString(const char* str, size_t& position);
  const char* isTerm(const char* str, size_t& position);
  const char* isMultiplier(const char* str, size_t& position);
  const char* isDeterm(const char* str, size_t& position);
  const char* isUnsignedInt(const char* str, size_t& position);
  const char* isIdentificator(const char* str, size_t& position);
  bool isLetter(char c);
}

#endif

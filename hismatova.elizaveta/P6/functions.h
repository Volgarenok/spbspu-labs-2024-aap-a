#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <string>

namespace hismatova
{
  bool isValidString(const std::string& str, size_t& position);
  const char* isTerm(const char* str);
  const char* isMultiplier(const char* str);
  const char* isUnsignedInt(const char* str);
  const char* isIdentificator(const char* str);
  bool isDigit(char c);
  bool isLetter(char c);
}

#endif

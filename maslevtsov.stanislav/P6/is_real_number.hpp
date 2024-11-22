#ifndef IS_REAL_NUMBER_HPP
#define IS_REAL_NUMBER_HPP

namespace maslevtsov
{
  const char* hasSymbol(const char* str, char symbol);
  const char* hasSign(const char* str);
  bool isRealNumber(const char* str);
}

#endif

#ifndef IS_REAL_NUMBER_HPP
#define IS_REAL_NUMBER_HPP

namespace maslevtsov
{
  const char* hasSymbol(const char* str, char symbol);
  const char* hasSign(const char* str);
  const char* hasDigit(const char* str);
  const char* hasUnsignedInt(const char* str);
  const char* hasOrder(const char* str);
  bool isRealNumber(const char* str);
}

#endif

#ifndef CHECKLINEONFLOAT_HPP
#define CHECKLINEONFLOAT_HPP

namespace krylov
{
  const char* hasSymbol(const char* str, char symbol);
  const char* hasSign(const char* str);
  const char* hasDigit(const char* str);
  const char* hasUnsignedInt(const char* str);
  const char* hasOrderOfMagnitude(const char* str);
  const char* hasMantissa(const char* str);
  bool isFloatNumber(const char* str);
}

#endif

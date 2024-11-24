#ifndef FLOATLITERALCHECK_H
#define FLOATLITERALCHECK_H

namespace aleksandrov
{
  const char* isSymbol(const char* str, const char c);
  const char* isSign(const char* str);
  const char* isDigit(const char* str);
  const char* isUnsignedInt(const char* str);
  const char* isNumberOrder(const char* str);
  const char* isMantissa(const char* str);
  bool isFloatLiteral(const char* str);
}

#endif


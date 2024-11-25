#ifndef CHECK_STR_H
#define CHECK_STR_H

namespace finaev
{
  const char * isSymbol(const char * str, const char a);
  const char * hasLetter(const char * str);
  const char * hasDigit(const char * str);
  const char * hasId(const char* str);
  const char * hasUnsignedInt(const char* str);
  const char * hasFactor(const char* str);
  const char * hasTerm(const char* str);
  const char * hasExpression(const char* str);
  bool checkStr(const char* str);
}

#endif

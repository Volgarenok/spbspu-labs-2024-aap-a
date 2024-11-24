#ifndef ISEXPRESSION_H
#define ISEXPRESSION_H

namespace tkach
{
  bool isExpression(const char *str);
  bool isNeededSymbol(const char* symbol);
  bool isDigit(const char** str);
  bool isSymbol(const char** str);
  bool hasId(const char** str);
  bool hasNumber(const char** str);
  bool hasMultiplier(const char** str);
  bool hasTerm(const char** str);
  bool hasExpression(const char** str);
}

#endif

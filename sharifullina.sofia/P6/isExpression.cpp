#include "isExpression.hpp"
#include <iostream>

namespace sharifullina
{
  const char * hasSymbol(const char * str, const char c);
  const char * hasExpression(const char * str);
  const char * hasUnsignedInt(const char * str);
  const char * hasNumber(const char * str);
  const char * hasIdentifier(const char * str);
  const char * hasMultiplier(const char * str);
  const char * hasTerm(const char * str);
  const char * hasLetter(const char * str);
}
const char * hasExpression(const char * str)
{
  
}

bool sharifullina::isExpression(const char * str)
{
  auto next = hasExpression(str);
  return next && (*next == '\0');
}

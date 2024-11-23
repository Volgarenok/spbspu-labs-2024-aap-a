#ifndef GRAMMARCHECKER_HPP
#define GRAMMARCHECKER_HPP
namespace maslov
{
  bool isExpression(const char * str);
  const char * maslov::hasExpression(const char * str);
  const char * maslov::hasMultiplier(const char * str);
  const char * maslov::hasTerm(const char * str);
  const char * maslov::hasIdentifier(const char * str);
  const char * maslov::hasDigit(const char * str);
  const char * maslov::hasLetter(const char * str);
  const char * maslov::hasUnsignedInteger(const char * str);
  const char * maslov::hasSymbol(const char * str, char c);
}
#endif
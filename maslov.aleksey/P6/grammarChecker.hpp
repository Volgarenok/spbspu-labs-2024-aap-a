#ifndef GRAMMARCHECKER_HPP
#define GRAMMARCHECKER_HPP
namespace maslov
{
  bool isExpression(const char * str);
  const char * hasExpression(const char * str);
  const char * hasMultiplier(const char * str);
  const char * hasTerm(const char * str);
  const char * hasIdentifier(const char * str);
  const char * hasDigit(const char * str);
  const char * hasLetter(const char * str);
  const char * hasUnsignedInteger(const char * str);
  const char * hasSymbol(const char * str, char c);
}
#endif
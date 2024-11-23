#ifndef GRAMMARCHECKER_HPP
#define GRAMMARCHECKER_HPP
namespace maslov
{
  bool isExpression(const char * str);
  const char * maslov::hasExpression(const char * str);
  const char * maslov::hasMultiplier(const char * str);
  const char * maslov::hasTerm(const char * str);
  const char * maslov::hasIdentifier(const char * str);
  const char * maslov::isDigit(const char * str);
  const char * maslov::isLetter(const char * str);
}
#endif
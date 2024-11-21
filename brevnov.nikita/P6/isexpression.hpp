#ifndef ISEXPRESSION_HPP
#define ISEXPRESSION_HPP
namespace brevnov
{
  bool isExpression(const char * str);
  const char * hasExpression(const char * str);
  const char * isLetter(const char * str);
  const char * isDigit(const char * str);
  const char * hasUint(const char * str);
  const char * hasMultiplier(const char * str);
  const char * hasTerm(const char * str);
}
#endif

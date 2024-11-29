#ifndef ISEXPRESSION_HPP
#define ISEXPRESSION_HPP
namespace brevnov
{
  static bool isExpression(const char * str);
  static const char * hasExpression(const char * str);
  static const char * isLetter(const char * str);
  static const char * isDigit(const char * str);
  static const char * hasUint(const char * str);
  static const char * hasMultiplier(const char * str);
  static const char * hasTerm(const char * str);
}
#endif

#ifndef CHECKUNIQUECHARS_H
#define CHECKUNIQUECHARS_H

namespace savintsev
{
  bool isOneOfTheLetters(char c);
  bool isUnsignedInteger(const char * s, int & pos);
  bool isMultiplier(const char * s, int & pos);
  bool isTerm(const char * s, int & pos);
  bool isIdentifier(const char * s, int & pos);
  bool isExpression(const char * s, int & pos);
}

#endif

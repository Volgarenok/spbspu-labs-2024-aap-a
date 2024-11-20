#ifndef RECFUNC_H
#define RECFUNC_H

namespace averenkov
{
  bool hasExpression(const char*& str);
  bool hasTerm(const char*& str);
  bool hasFactor(const char*& str);
  bool hasUnsignedInt(const char*& str);
  bool hasIdentifier(const char*& str);
  bool hasDigit(char c);
  bool hasLetter(char c);
}

#endif

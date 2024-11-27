#ifndef RECURSION_HPP
#define RECURSION_HPP
namespace evstyunichev
{
  const char * IsFactorCorrect(const char *, int prev = 3);
  const char * IsTermCorrect(const char *, int prev = 1);
  const char * IsExpressionCorrect(const char *, int prev = 1, bool OpenFlag = 0);
  bool IsDigit(char);
  bool IsLetter(char);
  bool IsSign(char);
  bool IsBasicSymbol(char);
}
#endif
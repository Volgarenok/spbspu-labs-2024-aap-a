#ifndef RECURSIONCHECKSTR_HPP
#define RECURSIONCHECKSTR_HPP
namespace abramov
{
  const char *isSymbol(const char *str, char c);
  const char *isSign(const char *str);
  const char *isDigit(const char *str);
  const char *hasUnsignedNumber(const char *str);
  const char *hasOrder(const char *str);
  const char *hasMantissa(const char *str);
  const char *hasReal(const char *str);
  bool isReal(const char *str);
}
#endif

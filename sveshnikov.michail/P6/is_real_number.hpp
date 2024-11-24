#ifndef IS_REAL_NUMBER_HPP
#define IS_REAL_NUMBER_HPP

namespace sveshnikov
{
  const char *hasSymbol(const char *str, const char c);
  const char *hasSign(const char *str);
  const char *hasDigit(const char *str);
  const char *hasUnsignedInteger(const char *str);
  const char *hasOrder(const char *str);
  const char *hasMantissa(const char *str);
  const char *hasRealNumber(const char *str);
  bool isRealNumber(const char *str);
}
#endif

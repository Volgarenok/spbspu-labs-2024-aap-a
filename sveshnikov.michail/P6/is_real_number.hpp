#ifndef IS_REAL_NUMBER_HPP
#define IS_REAL_NUMBER_HPP

namespace sveshnikov
{
  const char *isSign(const char *str);
  const char *isDigit(const char *str);
  const char *isUnsignedInteger(const char *str);
  const char *isOrder(const char *str);
  const char *isMantissa(const char *str);
  bool isRealNumber(const char *str);
}
#endif
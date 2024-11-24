#ifndef IS_REAL_NUMBER_HPP
#define IS_REAL_NUMBER_HPP
namespace sveshnikov
{
  bool isRealNumber(const char *str);
  const char *isSign(const char *str);
  const char *isDigit(const char *str);
  const char *isUnsignedInteger(const char *str);
  const char *sveshnikov::isOrder(const char *str);
}
#endif
#ifndef IS_DOUBLE_HPP
#define IS_DOUBLE_HPP

namespace guseynov
{
  bool isDigit(char c);
  const char * isSymbol(const char * str, char c);
  const char * isSign(const char * str);
  const char * isNum(const char * str);
  const char * isUnsignNum(const char * str);
  const char * isOrder(const char * str);
  const char * isMantis(const char * str);
  bool isDouble(const char * str);
}
#endif

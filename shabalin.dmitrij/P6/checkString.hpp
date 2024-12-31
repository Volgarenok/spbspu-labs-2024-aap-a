#ifndef CHECKSTRING_HPP
#define CHECKSTRING_HPP

class shabalin
{
public:
  static const char *isSign(const char *str);
  static bool is_digit(char c, char cur);
  static const char *isUnsignedInt(const char *str);
  static const char *isSymbol(const char *str, char ch);
  static const char *isOrder(const char *str);
  static const char *isMantissa(const char *str);
  static const char *hasRealNum(const char *str);
  static bool isRealNumber(const char *str);
};

#endif

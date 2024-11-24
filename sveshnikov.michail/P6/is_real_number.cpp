#include "is_real_number.hpp"

bool isRealNumber(const char *str)
{
  if (!str)
  {
    return str;
  }
}

const char *isMantissa(const char *str)
{
  if (!str)
  {
    return str;
  }
}

const char *sveshnikov::isOrder(const char *str)
{
  if (!str)
  {
    return str;
  }
  if (*str == 'E')
  {
    str++;
  }
  else
  {
    return nullptr;
  }
  const char *next = isSign(str);
  return isUnsignedInteger(next);
}

const char *sveshnikov::isUnsignedInteger(const char *str)
{
  if (!str)
  {
    return str;
  }
  const char *next = isDigit(str);
  return isUnsignedInteger(next);
}

const char *sveshnikov::isDigit(const char *str)
{
  if (!str)
  {
    return str;
  }
  return (*str >= '0' || *str <= '9') ? (str + 1) : nullptr;
}

const char *sveshnikov::isSign(const char *str)
{
  if (!str)
  {
    return str;
  }
  return (*str == '+' || *str == '-') ? (str + 1) : nullptr;
}

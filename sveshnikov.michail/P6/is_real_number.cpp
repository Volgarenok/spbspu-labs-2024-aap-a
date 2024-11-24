#include "is_real_number.hpp"

bool isRealNumber(const char *str)
{
}

const char *isMantissa(const char *str)
{
}

const char *isOrder(const char *str)
{
}

const char *isUnsignedInteger(const char *str)
{
}

const char *isDigit(const char *str)
{
  if (!str)
  {
    return str;
  }
  return (*str >= '0' || *str <= '9') ? (str + 1) : nullptr;
}

const char *isSign(const char *str)
{
  if (!str)
  {
    return str;
  }
  return (*str == '+' || *str == '-') ? (str + 1) : nullptr;
}

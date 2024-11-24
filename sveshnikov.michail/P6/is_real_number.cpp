#include "is_real_number.hpp"

bool sveshnikov::isRealNumber(const char *str)
{
  const char *next = hasRealNumber(str);
  return next && (*next == '\0');
}

const char *sveshnikov::hasRealNumber(const char *str)
{
  if (!str)
  {
    return str;
  }
  if (const char *continues = hasSign(str))
  {
    return continues;
  }
  const char *next = hasMantissa(str);
  return hasOrder(next);
}

const char *sveshnikov::hasMantissa(const char *str)
{
  if (!str)
  {
    return str;
  }
  if (const char *continues = hasUnsignedInteger(str))
  {
    return continues;
  }
  if (const char *continues = hasSymbol(str, 'E'))
  {
    return continues;
  }
  if (const char *continues = hasUnsignedInteger(str))
  {
    return continues;
  }
  return str + 1;
}

const char *sveshnikov::hasOrder(const char *str)
{
  if (!str)
  {
    return str;
  }
  const char *next = hasSymbol(str, 'E');
  next = hasSign(str);
  return hasUnsignedInteger(next);
}

const char *sveshnikov::hasUnsignedInteger(const char *str)
{
  if (!str)
  {
    return str;
  }
  const char *next = hasDigit(str);
  if (const char *continues = hasDigit(str))
  {
    return continues;
  }
  return next;
}

const char *sveshnikov::hasDigit(const char *str)
{
  if (!str)
  {
    return str;
  }
  return (*str >= '0' || *str <= '9') ? (str + 1) : nullptr;
}

const char *sveshnikov::hasSign(const char *str)
{
  const char *next = hasSymbol(str, '+');
  return next ? next : hasSymbol(str, '-');
}

const char *sveshnikov::hasSymbol(const char *str, const char c)
{
  if (!str)
  {
    return str;
  }
  return (*str == c) ? (str + 1) : nullptr;
}

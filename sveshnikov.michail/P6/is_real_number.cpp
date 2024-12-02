#include "is_real_number.hpp"

namespace
{
  const char *hasSymbol(const char *str, const char c);
  const char *hasSign(const char *str);
  const char *hasDigit(const char *str);
  const char *hasUnsignedInteger(const char *str);
  const char *hasOrder(const char *str);
  const char *hasMantissa(const char *str);

  const char *hasMantissa(const char *str)
  {
    if (!str)
    {
      return str;
    }
    if (const char *continues = hasUnsignedInteger(str))
    {
      if (const char *continues2 = hasSymbol(continues, '.'))
      {
        return hasUnsignedInteger(continues2);
      }
      return continues;
    }
    if (const char *continues = hasSymbol(str, '.'))
    {
      return hasUnsignedInteger(continues);
    }
    return nullptr;
  }

  const char *hasOrder(const char *str)
  {
    if (!str)
    {
      return str;
    }
    const char *next = hasSymbol(str, 'E');
    next = hasSign(next);
    return hasUnsignedInteger(next);
  }

  const char *hasUnsignedInteger(const char *str)
  {
    if (!str)
    {
      return str;
    }
    const char *next = hasDigit(str);
    if (const char *continues = hasUnsignedInteger(next))
    {
      return continues;
    }
    return next;
  }

  const char *hasDigit(const char *str)
  {
    if (!str)
    {
      return str;
    }
    return (*str >= '0' && *str <= '9') ? (str + 1) : nullptr;
  }

  const char *hasSign(const char *str)
  {
    const char *next = hasSymbol(str, '+');
    return next ? next : hasSymbol(str, '-');
  }

  const char *hasSymbol(const char *str, const char c)
  {
    if (!str)
    {
      return str;
    }
    return (*str == c) ? (str + 1) : nullptr;
  }
}

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
    const char *next = hasMantissa(continues);
    return hasOrder(next);
  }
  const char *next = hasMantissa(str);
  return hasOrder(next);
}

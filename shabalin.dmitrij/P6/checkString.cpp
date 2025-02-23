#include "checkString.hpp"

namespace
{
  const char *isSign(const char *str)
  {
    if (!str)
    {
      return str;
    }
    return ((*str == '+') || (*str == '-')) ? (str + 1) : nullptr;
  }

  bool is_digit(const char *str, char ch)
  {
    if (ch == '9' + 1)
    {
      return false;
    }
    if (ch == *str)
    {
      return true;
    }
    return is_digit(str, ch + 1);
  }

  const char *isUnsignedInt(const char *str)
  {
    if (!str)
    {
      return nullptr;
    }
    const char ch = '0';
    if (is_digit(str, ch))
    {
      return str + 1;
    }
    return nullptr;
  }

  const char *isSymbol(const char *str, char ch)
  {
    if (!str)
    {
      return str;
    }
    return (*str == ch) ? (str + 1) : nullptr;
  }

  const char *isOrder(const char *str)
  {
    if (!str)
    {
      return nullptr;
    }
    auto next = isSymbol(str, 'E');
    if (!next)
    {
      return nullptr;
    }
    auto next2 = isSign(next);
    if (next2 != nullptr)
    {
      next = next2;
    }
    next = isUnsignedInt(next);
    return next;
  }

  const char *isMantissa(const char *str)
  {
    if (!str)
    {
      return nullptr;
    }
    if (const char *next = isSymbol(str, '.'))
    {
      next = isUnsignedInt(str);
      return next;
    }
    const char *next = isUnsignedInt(str);
    if (const char *next2 = isSymbol(next, '.'))
    {
      next2 = isUnsignedInt(next2);
      return next2;
    }
    return next;
  }

  const char *hasRealNum(const char *str)
  {
    if (!str)
    {
      return str;
    }
    auto next = isSign(str);
    auto next2 = isMantissa(next);
    auto next3 = isOrder(next2);
    return next3;
  }
}

bool shabalin::isRealNumber(const char *str)
{
  if (!str)
  {
    return false;
  }
  const char *next = hasRealNum(str);
  return next && (*next == '\0');
}

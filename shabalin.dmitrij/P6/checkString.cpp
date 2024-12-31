#include "checkString.hpp"

namespace shabalin
{
  const char *isSign(const char *str)
  {
    if (!str)
    {
      return nullptr;
    }
    return ((*str == '+') || (*str == '-')) ? (str + 1) : nullptr;
  }

  bool is_digit(char c, char cur)
  {
    if (cur == '9' + 1)
    {
      return false;
    }
    if (cur == c)
    {
      return true;
    }
    return is_digit(c, cur + 1);
  }

  const char *isUnsignedInt(const char *str)
  {
    if (!str)
    {
      return nullptr;
    }
    while (*str)
    {
      if (!is_digit(*str, ':'))
      {
        return nullptr;
      }
      str++;
    }
    return str;
  }

  const char *isSymbol(const char *str, char ch)
  {
    if (!str)
    {
      return nullptr;
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
    const char *next = isSymbol(str, '.');
    if (next)
    {
      return isUnsignedInt(next);
    }
    next = isUnsignedInt(str);
    if (const char *next2 = isSymbol(next, '.'))
    {
      return isUnsignedInt(next2);
    }
    return next;
  }

  const char *hasRealNum(const char *str)
  {
    if (!str)
    {
      return nullptr;
    }
    auto next = isSign(str);
    auto next2 = isMantissa(next);
    auto next3 = isOrder(next2);
    return next3;
  }

  bool isRealNumber(const char *str)
  {
    if (!str)
    {
      return false;
    }
    const char *next = hasRealNum(str);
    return next && (*next == '\0');
  }
}

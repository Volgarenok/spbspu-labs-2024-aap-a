#include "checkString.hpp"

namespace
{
  const char *is_sign(const char *str)
  {
    if (!str)
    {
      return str;
    }
    return ((*str == '+') || (*str == '-')) ? (str + 1) : nullptr;
  }

  const char *is_digit(const char *str)
  {
    if (str == nullptr)
    {
      return nullptr;
    }
    if (*str == '0' || *str == '1' || *str == '2' || *str == '3' || *str == '4' ||
        *str == '5' || *str == '6' || *str == '7' || *str == '8' || *str == '9')
    {
      return str + 1;
    }
    return nullptr;
  }
  const char *is_unsigned_int(const char *str)
  {
    if (!str)
    {
      return nullptr;
    }
    auto next = is_digit(str);
    if (next == nullptr)
    {
      return nullptr;
    }
    auto next2 = is_unsigned_int(next);
    return (next2 == nullptr) ? next : next2;
  }

  const char *is_symbol(const char *str, char ch)
  {
    if (!str)
    {
      return str;
    }
    return (*str == ch) ? (str + 1) : nullptr;
  }

  const char *is_E(const char *str)
  {
    if (!str)
    {
      return nullptr;
    }
    auto next = is_symbol(str, 'E');
    if (!next)
    {
      return nullptr;
    }
    auto next2 = is_sign(next);
    if (next2 != nullptr)
    {
      next = next2;
    }
    next = is_unsigned_int(next);
    return next;
  }

  const char *is_mantissa(const char *str)
  {
    if (!str)
    {
      return nullptr;
    }
    if (const char *next = is_symbol(str, '.'))
    {
      next = is_unsigned_int(str);
      return next;
    }
    const char *next = is_unsigned_int(str);
    if (const char *next2 = is_symbol(next, '.'))
    {
      next2 = is_unsigned_int(next2);
      return next2;
    }
    return next;
  }

  const char *has_real(const char *str)
  {
    if (!str)
    {
      return str;
    }
    auto next = is_sign(str);
    auto next2 = is_mantissa(next);
    auto next3 = is_E(next2);
    return next3;
  }
}

bool shabalin::isRealNumber(const char *str)
{
  if (!str)
  {
    return false;
  }
  const char *next = has_real(str);
  return next && (*next == '\0');
}

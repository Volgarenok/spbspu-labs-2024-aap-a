#include "checkString.hpp"
#include <cctype>

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
    if (!str)
    {
      return str;
    }
    return ((*str >= '0') && (*str <= '9')) ? (str + 1) : nullptr;
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
    if (const char * next = is_symbol(str, '.'))
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
  const char *is_real(const char *str)
  {
    if (!str)
    {
      return str;
    }
    if (const char *next = is_sign(str))
    {
      next = is_mantissa(next);
      next = is_E(str);
      return next;
    }
  }
}

bool shabalin::func(const char * str)
{
  if (!str)
  {
    return false;
  }
  const char *next = is_real(str);
  return next && (*next == '\0');
}

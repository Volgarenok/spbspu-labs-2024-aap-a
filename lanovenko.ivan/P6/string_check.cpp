#include "string_check.h"
#include <cctype>

namespace
{
  const char* is_symbol(const char* str, char c)
  {
    if (!str)
    {
      return str;
    }
    return (*str == c) ? (str + 1) : nullptr;
  }

  const char* is_sign(const char* str)
  {
    if (!str)
    {
      return str;
    }
    auto next = is_symbol(str, '+');
    return next ? next : is_symbol(str, '-');
  }

  const char* is_digit(const char* str)
  {
    if (!str)
    {
      return str;
    }
    return std::isdigit(*str) ? (str + 1) : nullptr;
  }

  const char* is_unsigned_int(const char* str)
  {
    if (!str)
    {
      return str;
    }
    auto next = is_digit(str);
    if (auto continues = is_unsigned_int(next))
    {
      return continues;
    }
    return next;
  }

  const char* is_E_digit(const char* str)
  {
    if (!str)
    {
      return str;
    }
    auto next = is_symbol(str, 'E');
    if (auto continues = is_sign(next))
    {
      return is_unsigned_int(continues);
    }
    return is_unsigned_int(next);
  }

  const char* is_mantissa(const char* str)
  {
    if (!str)
    {
      return str;
    }
    auto next = is_unsigned_int(str);
    next = is_symbol(next, '.');
    return is_unsigned_int(next);
  }
}

bool lanovenko::is_valid_float_string(const char* str)
{
  if (!str)
  {
    return str;
  }
  if (auto continues = is_sign(str))
  {
    auto next = is_mantissa(continues);
    return is_E_digit(next);
  }
  auto next = is_mantissa(str);
  next = is_E_digit(next);
  return next && (*next == '\0');
}

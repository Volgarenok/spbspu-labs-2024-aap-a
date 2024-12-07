#include "real_number_set.h"
#include <cctype>

namespace
{
  const char * is_symbol(const char * str, char a)
  {
    if (!str)
    {
      return str;
    }
    return (*str == a) ? (str + 1) : nullptr;
  }

  const char * has_sign(const char * str)
  {
    if (!str)
    {
      return str;
    }
    return (is_symbol(str, '+') || is_symbol(str, '-')) ? (str + 1) : nullptr;
  }

  const char * has_digit(const char * str)
  {
    if (!str)
    {
      return str;
    }
    return (std::isdigit(*str)) ? (str + 1) : nullptr;
  }

  const char * has_unsigned_int(const char * str)
  {
    if (!str)
    {
      return str;
    }
    auto next = has_digit(str);
    if (auto continues = has_unsigned_int(next))
    {
      return continues;
    }
    return next;
  }


  const char * has_e(const char * str)
  {
    if (!str)
    {
      return str;
    }
    return (is_symbol(str, 'E') || is_symbol(str, 'e')) ? (str + 1) : nullptr;
  }

  const char * has_order(const char * str)
  {
    if (!str)
    {
      return str;
    }
    auto next = has_e(str);
    if (auto continues = has_sign(next))
    {
      next = continues;
    }
    return has_unsigned_int(next);
  }

  const char * has_mantissa(const char * str)
  {
    if (!str)
    {
      return str;
    }
    auto next = str;
    if (auto continues = has_unsigned_int(next))
    {
      next = continues;
    }
    next = is_symbol(next, '.');
    return has_unsigned_int(next);
  }
}

bool timofeev::is_real_number(const char * str)
{
  if (!str)
  {
    return str;
  }
  auto next = has_mantissa(str);
  return has_order(next);
}


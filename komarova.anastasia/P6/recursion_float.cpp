#include "recursion_float.h"
#include <cctype>

namespace
{
  const char * is_symbol(const char * str, const char sym);
  const char * is_number(const char * str);
  const char * is_unsigned_int(const char * str);
  const char * is_sign(const char * str);
  const char * is_order(const char * str);
  const char * is_mantissa(const char * str);
  const char * is_digit(const char * str);

  const char * is_symbol(const char * str, const char sym)
  {
    if (!str)
    {
      return str;
    }
    return (*str == sym) ? (str + 1) : nullptr;
  }

  const char * is_digit(const char * str)
  {
    if (!str)
    {
      return str;
    }
    const char * dig = "0123456789\0";
    if (*str == *dig)
    {
      return str + 1;
    }
    if (*(dig + 1) != '\0' && *str == *(dig + 1))
    {
      return str + 1;
    }
    if (*(dig + 2) != '\0' && *str == *(dig + 2))
    {
      return str + 1;
    }
    if (*(dig + 3) != '\0' && *str == *(dig + 3))
    {
      return str + 1;
    }
    if (*(dig + 4) != '\0' && *str == *(dig + 4))
    {
      return str + 1;
    }
    if (*(dig + 5) != '\0' && *str == *(dig + 5))
    {
      return str + 1;
    }
    if (*(dig + 6) != '\0' && *str == *(dig + 6))
    {
      return str + 1;
    }
    if (*(dig + 7) != '\0' && *str == *(dig + 7))
    {
      return str + 1;
    }
    if (*(dig + 8) != '\0' && *str == *(dig + 8))
    {
      return str + 1;
    }
    if (*(dig + 9) != '\0' && *str == *(dig + 9))
    {
      return str + 1;
    }
    return nullptr;
  }

  const char * is_number(const char * str)
  {
    if (!str)
    {
      return str;
    }
    return (is_digit(str)) ? (str + 1) : nullptr;
  }

  const char * is_unsigned_int(const char * str)
  {
    if (!str)
    {
      return nullptr;
    }
    const char * next = is_number(str);
    if (const char * continues = is_unsigned_int(next))
    {
      return continues;
    }
    return next;
  }

  const char * is_sign(const char * str)
  {
    if (!str)
    {
      return str;
    }
    const char * next = is_symbol(str, '-');
    return next ? next : is_symbol(str, '+');
  }

  const char * is_order(const char * str)
  {
    if (!str)
    {
      return str;
    }
    const char * next = is_symbol(str,'E');
    if (const char * continues = is_sign(next))
    {
      return is_unsigned_int(continues);
    }
    return is_unsigned_int(next);
  }

  const char * is_mantissa(const char * str)
  {
    if (!str)
    {
      return str;
    }
    const char * next = is_symbol(str, '.');
    return is_unsigned_int(next);
  }
}

const char * komarova::is_float(const char * str)
{
  if (!str)
  {
    return str;
  }
  if (const char * next = is_sign(str))
  {
    const char * continues = is_mantissa(next);
    return is_order(continues);
  }
  const char * continues = is_mantissa(str);
  return is_order(continues);
}

bool komarova::is_float_lit(const char * str)
{
  if (!str)
  {
    return false;
  }
  const char * next = is_float(str);
  return next && (*next == '\0');
}

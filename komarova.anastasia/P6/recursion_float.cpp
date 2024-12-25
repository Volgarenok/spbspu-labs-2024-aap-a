#include "recursion_float.h"
#include <cctype>

bool komarova::is_digit(char* str)
{
  if (*str == '\0')
  {
    return false;
  }
  const char * dig = "0123456789\0";
  while (*str != '\0')
  {
    for (const char* d = dig; *d != '\0'; d++)
    {
      if (*str == *d)
      {
        return is_digit(str + 1);
      }
    }
  }
  return false;
}

namespace
{
  const char * is_symbol(const char * str, const char sym);
  const char * is_number(const char * str);
  const char * is_unsigned_int(const char * str);
  const char * is_sign(const char * str);
  const char * is_order(const char * str);
  const char * is_mantissa(const char * str);

  const char * is_symbol(const char * str, const char sym)
  {
    if (!str)
    {
      return str;
    }
    return (*str == sym) ? (str + 1) : nullptr;
  }

  const char * is_number(const char * str)
  {
    if (!str)
    {
      return str;
    }
    return (komarova::is_digit(*str)) ? (str + 1) : nullptr;
  }

  const char * is_unsigned_int(const char * str)
  {
    if(!str)
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

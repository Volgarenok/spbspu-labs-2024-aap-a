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
    return (std::isdigit(*str)) ? (str + 1) : nullptr;
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

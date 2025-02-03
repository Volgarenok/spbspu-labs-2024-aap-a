#include "string_utilities.h"
#include <cctype>

namespace beshimow
{
  const char* has_symbol(const char* str, char symbol);
  const char* has_sign(const char* str);
  const char* has_number(const char* str);
  const char* has_unsigned_int(const char* str);
  const char* has_order(const char* str);
  const char* has_mantissa(const char* str);
  const char* has_double(const char* str);
  bool is_double(const char* str);
}

const char* beshimow::has_symbol(const char* str, char symbol)
{
  if (!str)
  {
    return str;
  }
  return (*str == symbol) ? (str + 1) : nullptr;
}

const char* beshimow::has_sign(const char* str)
{
  if (!str)
  {
    return str;
  }
  return (has_symbol(str, '+') || has_symbol(str, '-')) ? (str + 1) : nullptr;
}

const char* beshimow::has_number(const char* str)
{
  if (!str)
  {
    return str;
  }
  return (std::isdigit(*str)) ? (str + 1) : nullptr;
}

const char* beshimow::has_unsigned_int(const char* str)
{
  if (!str)
  {
    return str;
  }
  const char* next = beshimow::has_number(str);
  if (const char* continues = beshimow::has_unsigned_int(next))
  {
    return continues;
  }
  return next;
}

const char* beshimow::has_order(const char* str)
{
  if (!str)
  {
    return str;
  }
  const char* next = beshimow::has_symbol(str, 'E');
  if (const char* continues = beshimow::has_sign(next))
  {
    next = continues;
  }
  next = beshimow::has_unsigned_int(next);
  return next;
}

const char* beshimow::has_mantissa(const char* str)
{
  if (!str)
  {
    return str;
  }
  const char* next = beshimow::has_symbol(str, '.');
  if (next)
  {
    next = beshimow::has_unsigned_int(next);
    return next;
  }
  next = beshimow::has_unsigned_int(str);
  next = beshimow::has_symbol(next, '.');
  next = beshimow::has_unsigned_int(next);
  return next;
}

const char* beshimow::has_double(const char* str)
{
  if (!str)
  {
    return str;
  }
  const char* next = str;
  if (const char* continues = beshimow::has_sign(str))
  {
    next = continues;
  }
  next = beshimow::has_mantissa(next);
  next = beshimow::has_order(next);
  return next;
}

bool beshimow::is_double(const char* str)
{
  if (!str)
  {
    return false;
  }
  const char* next = beshimow::has_double(str);
  return next && (*next == '\0');
}

#include "recursion_string.h"
#include <cctype>
namespace alymova
{
  const char* has_symbol(const char* str, char symbol);
  const char* has_sign(const char* str);
  const char* has_number(const char* str);
  const char* has_unsigned_int(const char* str);
  const char* has_order(const char* str);
  const char* has_mantissa(const char* str);
}
const char* alymova::has_symbol(const char* str, char symbol)
{
  if (!str)
  {
    return str;
  }
  return (*str == symbol) ? (str + 1) : nullptr;
}
const char* alymova::has_sign(const char* str)
{
  if (!str)
  {
    return str;
  }
  return (has_symbol(str, '+') || has_symbol(str, '-')) ? (str + 1) : nullptr;
}
const char* alymova::has_number(const char* str)
{
  if (!str)
  {
    return str;
  }
  return (std::isdigit(*str)) ? (str + 1) : nullptr;
}
const char* alymova::has_unsigned_int(const char* str)
{
  if (!str)
  {
    return str;
  }
  const char* next = alymova::has_number(str);
  if (const char* continues = alymova::has_unsigned_int(next))
  {
    return continues;
  }
  return next;
}
const char* alymova::has_order(const char* str)
{
  if (!str)
  {
    return str;
  }
  const char* next = alymova::has_symbol(str, 'E');
  if (const char* continues = alymova::has_sign(next))
  {
    next = continues;
  }
  next = alymova::has_unsigned_int(next);
  return next;
}
const char* alymova::has_mantissa(const char* str)
{
  if (!str)
  {
    return str;
  }
  const char* next = alymova::has_symbol(str, '.');
  if (next)
  {
    next = alymova::has_unsigned_int(next);
    return next;
  }
  next = alymova::has_unsigned_int(str);
  next = alymova::has_symbol(next, '.');
  next = alymova::has_unsigned_int(next);
  return next;
}
const char* alymova::has_double(const char* str)
{
  if (!str)
  {
    return str;
  }
  const char* next = str;
  if (const char* continues = alymova::has_sign(str))
  {
    next = continues;
  }
  next = alymova::has_mantissa(next);
  next = alymova::has_order(next);
  return next;
}
bool alymova::is_double(const char* str)
{
  if (!str)
  {
    return false;
  }
  const char* next = alymova::has_double(str);
  return next && (*next == '\0');
}

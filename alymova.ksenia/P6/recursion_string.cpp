#include "recursion_string.hpp"
const char* alymova::has_e(const char* str)
{
  if (!str)
  {
    return str;
  }
  return (*str == 'E') ? (str + 1) : nullptr;
}
const char* alymova::has_dot(const char* str)
{
  if (!str)
  {
    return str;
  }
  return (*str == '.') ? (str + 1) : nullptr;
}
const char* alymova::has_sign(const char* str)
{
  if (!str)
  {
    return str;
  }
  return (*str == '+' || *str == '-') ? (str + 1) : nullptr;
}
const char* alymova::has_number(const char* str)
{
  if (!str)
  {
    return str;
  }
  return ('0' <= *str && *str <= '9') ? (str + 1) : nullptr;
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
  const char* next = alymova::has_e(str);
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
  const char* next = alymova::has_dot(str);
  if (next)
  {
    next = alymova::has_unsigned_int(next);
    return next;
  }
  next = alymova::has_unsigned_int(str);
  next = alymova::has_dot(next);
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
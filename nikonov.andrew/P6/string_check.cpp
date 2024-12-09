#include "string_check.hpp"
namespace nikonov
{
  const char* is_sign(const char* str);
  const char* is_digit(const char* str);
  const char* is_numb(const char* str);
  const char* is_mantissa(const char* str);
  const char* is_order(const char* str);
}
bool nikonov::is_float(const char* str)
{
  auto next = is_mantissa(str);
  if (!next)
  {
    return false;
  }
  return true;
}
const char* nikonov::is_sign(const char* str)
{
  if (!str)
  {
    return nullptr;
  }
  if ((*str) == '+' || (*str) == '-')
  {
    return (str + 1);
  }
  return nullptr;
}
const char* nikonov::is_digit(const char* str)
{
  if (!str)
  {
    return nullptr;
  }
  if ((*str) >= '0' && (*str) <= '9')
  {
    return (str + 1);
  }
  return nullptr;
}
const char* nikonov::is_numb(const char* str)
{
  if (!str)
  {
    return nullptr;
  }
  if (*str == '\0' || *str == 'e' || *str == 'E' || *str == '.')
  {
    return str;
  }
  auto next = is_digit(str);
  if (next)
  {
    return is_numb(next);
  }
  return nullptr;
}
const char* nikonov::is_mantissa(const char* str)
{
  if (!str)
  {
    return nullptr;
  }
  if (*str == '.')
  {
    return is_numb(str + 1);
  }
  auto next = is_numb(str);
  if (next && *next == '.')
  {
    return is_numb(next + 1);
  }
  return nullptr;
}
const char* nikonov::is_order(const char* str)
{
  if (!str)
  {
    return nullptr;
  }
  if (*str == 'E')
  {
    auto next = is_sign(str + 1);
    if (!next)
    {
      return nullptr;
    }
    return is_numb(next);
  }
  else if (*str == 'e')
  {
    return is_numb(str + 1);
  }
  return nullptr;
}

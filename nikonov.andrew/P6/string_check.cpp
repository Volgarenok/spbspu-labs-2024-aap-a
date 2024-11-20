#include "string_check.hpp"
const char* is_float(const char* str)
{
  auto next = nikonov::is_mantissa(str);
  if (!next)
  {
    return nullptr;
  }
  return nikonov::is_order(next);
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
  auto next = nikonov::is_digit(str);
  if (next)
  {
    return nikonov::is_numb(str + 1);
  }
  return str;
}
const char* nikonov::is_mantissa(const char* str)
{
  if (!str)
  {
    return nullptr;
  }
  if (*str == '.')
  {
    return nikonov::is_numb(str + 1);
  }
  auto next = nikonov::is_numb(str);
  if (next && *next == '.')
  {
    return nikonov::is_numb(next + 1);
  }
  return next;
}
const char* nikonov::is_order(const char* str)
{
  if (!str)
  {
    return nullptr;
  }
  if (*str == 'e' || *str == 'E')
  {
    auto next = nikonov::is_sign(str + 1);
    if (!next)
    {
      return nikonov::is_numb(str + 1);
    }
    return nikonov::is_numb(next);
  }
  return str;
}

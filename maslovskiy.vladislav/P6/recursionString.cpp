#include "recursionString.hpp"
#include <cctype>

namespace maslovskiy
{
  const char* hasDigit(const char* str);
  const char* hasChar(const char* str, char c);
  const char* hasSign(const char* str);
  const char* hasNumbers(const char* str);
  const char* hasMantissa(const char* str);
  const char* hasExponent(const char* str);
  bool isSign(char c);
}
bool maslovskiy::isSign(char c)
{
  return c == '+' || c == '-';
}
const char* maslovskiy::hasDigit(const char* str)
{
  if (!str || *str == '\0')
  {
    return nullptr;
  }
  return (std::isdigit(*str)) ? (str + 1) : nullptr;
}
const char* maslovskiy::hasChar(const char* str, char c)
{
  if (!str || *str == '\0')
  {
    return nullptr;
  }
  return *str == c ? (str + 1) : nullptr;
}
const char* maslovskiy::hasSign(const char* str)
{
  if (!str || *str == '\0')
  {
    return nullptr;
  }
  return isSign(*str) ? (str + 1) : str;
}
const char* maslovskiy::hasNumbers(const char* str)
{
  if (!str || *str == '\0')
  {
    return nullptr;
  }
  const char* next = hasDigit(str);
  if (!next)
  {
    return nullptr;
  }
  return hasNumbers(next) ? hasNumbers(next) : next;
}
const char* maslovskiy::hasMantissa(const char* str)
{
  if (!str || *str == '\0')
  {
    return nullptr;
  }
  const char* next = hasNumbers(str);
  if (!next)
  {
    return nullptr;
  }
  if (*next == '.')
  {
    next++;
    next = hasNumbers(next);
  }
  return next;
}
const char* maslovskiy::hasExponent(const char* str)
{
  if (!str || *str == '\0')
  {
    return nullptr;
  }
  const char* next = hasChar(str, 'E');
  if (!next)
  {
    return str;
  }
  next = hasSign(next);
  next = hasNumbers(next);
  return next;
}
bool maslovskiy::isDouble(const char* str)
{
  if (!str || *str == '\0')
  {
    return false;
  }
  const char* next = hasSign(str);
  if (!next)
  {
    return false;
  }
  next = hasMantissa(next);
  if (!next)
  {
    return false;
  }
  next = hasExponent(next);
  return next && *next == '\0';
}

#include "recursionString.hpp"
#include <iostream>
#include <cctype>

namespace maslovskiy
{
  const char *hasDigit(const char *str);
  const char *hasChar(const char *str, char c);
  const char *hasSign (const char *str);
  const char *hasNumbers(const char *str);
  const char *hasMantissa(const char *str);
  const char *hasExponent(const char *str);
  bool isSign(char c);
}
bool maslovskiy::isSign(char c)
{
  return (c == '+') || (c == '-');
}
const char *maslovskiy::hasDigit(const char *str)
{
  if (!str)
  {
    return str;
  }
  return isdigit(*str) ? (str + 1) : nullptr;
}
const char *maslovskiy::hasChar(const char *str, char c)
{
  if (!str)
  {
    return str;
  }
  return *str == c ? (str + 1) : nullptr;
}
const char *maslovskiy::hasSign (const char *str)
{
  if (!str)
  {
    return str;
  }
  return isSign(*str) ? (str + 1) : nullptr;
}
const char *maslovskiy::hasNumbers(const char *str)
{
  if (!str)
  {
    return str;
  }
  auto next = maslovskiy::hasDigit(str);
  if (auto continues = maslovskiy::hasNumbers(next))
  {
    return continues;
  }
  return next;
}
const char *maslovskiy::hasMantissa(const char *str)
{
  auto next = maslovskiy::hasDigit(str);
  next = maslovskiy::hasChar(next, '.');
  next = maslovskiy::hasNumbers(next);
  return next;
}
const char *maslovskiy::hasExponent(const char *str)
{
  auto next = maslovskiy::hasChar(str, 'E');
  if (auto continues = maslovskiy::hasSign(next))
  {
    next = continues;
  }
  next = maslovskiy::hasNumbers(next);
  return next;
}
bool maslovskiy::isDouble(const char *str)
{
  auto next = str;
  if (auto continues = maslovskiy::hasSign(next))
  {
    next = continues;
  }
  next = maslovskiy::hasMantissa(next);
  next = maslovskiy::hasExponent(next);
  return *next == '\0' && next;
}

#include "is_real_number.hpp"

const char* maslevtsov::hasSymbol(const char* str, char symbol)
{
  if (!str)
  {
    return str;
  }
  return (*str == symbol) ? (str + 1) : nullptr;
}

const char* maslevtsov::hasSign(const char* str)
{
  auto next = hasSymbol(str, '+');
  return next ? next : hasSymbol(str, '-');
}

const char* maslevtsov::hasDigit(const char* str)
{
  if (!str)
  {
    return str;
  }
  auto next = hasSymbol(str, '0');
  constexpr char digits[11] = "0123456789";
  for (const char* i = digits + 1; *i != '\0'; ++i)
  {
    next = hasSymbol(str, *i);
    if (next)
    {
      return next;
    }
  }
  return next;
}

bool maslevtsov::isRealNumber(const char* str)
{
  return false;
}

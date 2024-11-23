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
    next = hasSymbol(next, *i);
    if (next)
    {
      return next;
    }
  }
  return next;
}

const char* maslevtsov::hasUnsignedInt(const char* str)
{
  if (!str)
  {
    return str;
  }
  auto next = hasDigit(str);
  if (auto continues = hasSymbol(next, 'u'))
  {
    return continues;
  }
  return next;
}

const char* maslevtsov::hasOrder(const char* str)
{
  if (!str)
  {
    return str;
  }
  auto next = hasSymbol(str, 'E');
  next = hasSign(next);
  if (next)
  {
    return hasUnsignedInt(next);
  }
  if (auto continues = hasUnsignedInt(next))
  {
    return continues;
  }
  return next;
}

const char* maslevtsov::hasMantissa(const char* str)
{
  if (!str)
  {
    return str;
  }
  auto next = hasUnsignedInt(str);
  next = hasSymbol(next, '.');
  return hasUnsignedInt(next);
}

const char* maslevtsov::hasRealNumber(const char* str)
{
  if (!str)
  {
    return str;
  }
  auto next = hasSign(str);
  if (next)
  {
    next = hasMantissa(next);
    return hasOrder(next);
  }
  next = hasMantissa(next);
  return hasOrder(next);
}

bool maslevtsov::isRealNumber(const char* str)
{
  auto next = hasRealNumber(str);
  return next && (*next == '\0');
}

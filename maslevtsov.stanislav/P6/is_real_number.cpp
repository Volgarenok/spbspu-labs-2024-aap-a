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
  if (!str)
  {
    return str;
  }
  auto next = hasSymbol(str, '+');
  return next ? next : hasSymbol(str, '-');
}

const char* maslevtsov::hasDigit(const char* str)
{
  if (!str)
  {
    return str;
  }
  return (*str >= '0' && *str <= '9') ? (str + 1) : nullptr;
}

const char* maslevtsov::hasUnsignedInt(const char* str)
{
  if (!str)
  {
    return str;
  }
  auto next = hasDigit(str);
  if (auto continues = hasUnsignedInt(next))
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
  return hasUnsignedInt(next);
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
  if (auto next = hasSign(str))
  {
    next = hasMantissa(next);
    return hasOrder(next);
  }
  else
  {
    next = hasMantissa(next);
    return hasOrder(next);
  }
}

bool maslevtsov::isRealNumber(const char* str)
{
  auto next = hasRealNumber(str);
  return next && (*next == '\0');
}

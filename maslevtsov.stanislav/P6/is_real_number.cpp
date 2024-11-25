#include "is_real_number.hpp"
#include <cctype>

namespace maslevtsov
{
  const char* hasSymbol(const char* str, char symbol);
  const char* hasSign(const char* str);
  const char* hasDigit(const char* str);
  const char* hasUnsignedInt(const char* str);
  const char* hasOrder(const char* str);
  const char* hasMantissa(const char* str);
  const char* hasRealNumber(const char* str);
}

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
  return (std::isdigit(*str)) ? (str + 1) : nullptr;
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
  if (auto signCheck = hasSign(next))
  {
    return hasUnsignedInt(signCheck);
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
  if (auto signCheck = hasSign(str))
  {
    auto next = hasMantissa(signCheck);
    return hasOrder(next);
  }
  auto next = hasMantissa(str);
  return hasOrder(next);
}

bool maslevtsov::isRealNumber(const char* str)
{
  auto next = hasRealNumber(str);
  return next && (*next == '\0');
}

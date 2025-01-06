#include "isRealNumber.hpp"
#include <cctype>

namespace balashov
{
  const char* hasSymbol(const char* str, char symbol);
  const char* hasFigure(const char * str);
  const char* hasUnsigned(const char* str);
  const char * hasSign(const char * str);
  const char * hasSign(const char * str);
  const char* hasOrder(const char* str);
  const char* hasMantissa(const char* str);
}

const char* balashov::hasSymbol(const char* str, char symbol)
{
  if (!str)
  {
    return str;
  }
  return (*str == symbol) ? (str + 1) : nullptr;
}

const char* balashov::hasFigure(const char * str)
{
  if (!str)
  {
    return str;
  }
  return std::isdigit(*str) ? (str + 1) : nullptr;
}

const char* balashov::hasUnsigned(const char* str)
{
  if (!str)
  {
    return str;
  }
  auto next = hasFigure(str);
  if (auto continues = hasUnsigned(next))
  {
    return continues;
  }
  return next;
}
const char * balashov::hasSign(const char * str)
{
  if (!str)
  {
    return str;
  }
  auto next = hasSymbol(str, '-');
  return next ? next : hasSymbol(str, '+');
}

const char* balashov::hasOrder(const char* str)
{
  if (!str)
  {
    return str;
  }
  auto next = hasSymbol(str,'E');
  if (auto continues = hasSign(next))
  {
    return hasUnsigned(continues);
  }
  return hasUnsigned(next);
}

const char* balashov::hasMantissa(const char* str)
{
  if (!str)
  {
    return str;
  }
  auto next = hasSymbol(str, '.');
  return hasUnsigned(next);
}

const char* balashov::hasFloatingPointLiteral(const char* str)
{
  if (!str)
  {
    return str;
  }
  if (auto next = hasSign(str))
  {
    auto continues = hasMantissa(next);
    return hasOrder(continues);
  }
  auto continues = hasMantissa(str);
  return hasOrder(continues);
}

bool balashov::isFloatingPointLiteral(const char* str)
{
  auto next = hasFloatingPointLiteral(str);
  return next && (*next == '\0');
}

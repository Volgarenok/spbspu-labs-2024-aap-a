#include "recursiveCheckStr.hpp"
#include <cctype>

namespace abramov
{
  const char *isSymbol(const char *str, char c);
  const char *isSign(const char *str);
  const char *isDigit(const char *str);
  const char *hasUnsignedNumber(const char *str);
  const char *hasOrder(const char *str);
  const char *hasMantissa(const char *str);
  const char *hasReal(const char *str);
}

const char *abramov::isSymbol(const char *str, char c)
{
  if (!str)
  {
    return str;
  }
  return (*str == c) ? (str + 1) : nullptr;
}

const char *abramov::isSign(const char *str)
{
  if (!str)
  {
    return str;
  }
  return (*str == '+' || *str == '-') ? (str + 1) : nullptr;
}

const char *abramov::isDigit(const char *str)
{
  if (!str)
  {
    return str;
  }
  return std::isdigit(*str) ? (str + 1) : nullptr;
}

const char *abramov::hasUnsignedNumber(const char *str)
{
  if (!str)
  {
    return str;
  }
  auto next = isDigit(str);
  if (!next)
  {
    return next;
  }
  if (auto continues = hasUnsignedNumber(next))
  {
    return continues;
  }
  return next;
}

const char *abramov::hasOrder(const char *str)
{
  if (!str)
  {
    return str;
  }
  auto next = isSymbol(str, 'E');
  if (!next)
  {
    return next;
  }
  next = isSign(next);
  if (!next)
  {
    return next;
  }
  next = hasUnsignedNumber(next);
  return next;
}

const char *abramov::hasMantissa(const char *str)
{
  if (!str)
  {
    return str;
  }
  auto next = hasUnsignedNumber(str);
  if (!next)
  {
    return next;
  }
  if (*next=='.')
  {
    return hasUnsignedNumber(next+1);
  }
  return next;
}

const char *abramov::hasReal(const char *str)
{
  if (!str)
  {
    return str;
  }
  if (auto next = isSign(str))
  {
    next = hasMantissa(next);
    return hasOrder(next);
  }
  else
  {
    next = hasMantissa(str);
    return hasOrder(next);
  }
}

bool abramov::isReal(const char *str)
{
  auto next = hasReal(str);
  return next && (*next == '\0');
}

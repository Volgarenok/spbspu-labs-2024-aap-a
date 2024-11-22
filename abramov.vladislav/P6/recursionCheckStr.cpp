#include "recursionCheckStr.hpp"

const char *abramov::isSymbol(const char *str, char c)
{
  if (!str)
  {
    return str;
  }
  return (*str==c) ? (str + 1) : nullptr;
}

const char *abramov::isSign(const char *str)
{
  if (!str)
  {
    return str;
  }
  return (*str == '+' || *str=='-') ? (str + 1) : nullptr;
}

const char *abramov::isDigit(const char *str)
{
  if (!str)
  {
    return str;
  }
  return (*str <= 57 && *str >= 48) ? (str + 1) : nullptr;
}

const char *abramov::hasUnsignedNumber(const char *str)
{
  if (!str)
  {
    return str;
  }
  auto next = abramov::isDigit(str);
  if (auto continues = abramov::isDigit(next))
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
  auto next = abramov::isSymbol(str, 'E');
  next = abramov::isSign(next);
  next = abramov::hasUnsignedNumber(next);
  return next;
}

const char *abramov::hasMantissa(const char *str)
{
  if (!str)
  {
    return str;
  }
  auto next = abramov::hasUnsignedNumber(str);
  if (*next=='.')
  {
    return abramov::hasUnsignedNumber(next+1);
  }
  return next;
}

const char *abramov::hasReal(const char *str)
{
  if (!str)
  {
    return str;
  }
  if (auto next = abramov::isSign(str))
  {
    next = abramov::hasMantissa(next);
    return abramov::hasOrder(next);
  }
  else
  {
    next = abramov::hasMantissa(str);
    return abramov::hasOrder(next);
  }
}

bool abramov::isReal(const char *str)
{
  auto next = abramov::hasReal(str);
  return next && (*next == '\0');
}

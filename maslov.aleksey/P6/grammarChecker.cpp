#include "grammarChecker.hpp"

const char * hasMultiplier(const char * str);
const char * hasTerm(const char * str);
const char * hasIdentifier(const char * str);
const char * hasDigit(const char * str);
const char * hasLetter(const char * str);
const char * hasUnsignedInteger(const char * str);
const char * hasSymbol(const char * str, char c);

bool maslov::isExpression(const char * str)
{
  auto next = hasExpression(str);
  return next && (*next == '\0');
}
const char * maslov::hasExpression(const char * str)
{
  if (!str)
  {
    return str;
  }
  auto next = hasTerm(str);
  auto nextPlus = hasSymbol(next, '+');
  auto nextMinus = hasSymbol(next, '-');
  if (nextMinus || nextPlus)
  {
    next++;
    next = hasExpression(next);
  }
  return next;
}
const char * hasMultiplier(const char * str)
{
  if (!str)
  {
    return str;
  }
  auto next = hasSymbol(str, '(');
  if (next)
  {
    auto afterNext = maslov::hasExpression(next);
    if (afterNext && hasSymbol(afterNext, ')'))
    {
      return afterNext + 1;
    }
  }
  next = hasUnsignedInteger(str);
  if (next)
  {
    return next;
  }
  next = hasIdentifier(str);
  if (next)
  {
    return next;
  }
  return next;
}
const char * hasTerm(const char * str)
{
  if (!str)
  {
    return str;
  }
  auto next = hasMultiplier(str);
  if (next)
  {
    return next;
  }
  next = hasSymbol(str, '(');
  if (next)
  {
    next = hasMultiplier(next);
    auto nextMultiplication = hasSymbol(next, '*');
    auto nextDivision = hasSymbol(next, '/');
    if (nextDivision || nextMultiplication)
    {
      next++;
    }
    next = hasTerm(next);
    next = hasSymbol(next, ')');
  }
  return next;
}
const char * hasIdentifier(const char * str)
{
  if (!str)
  {
    return str;
  }
  return hasLetter(str);
}
const char * hasDigit(const char * str)
{
  if (!str)
  {
    return str;
  }
  bool checkDigit = (*str >= '0') && (*str <= '9');
  return checkDigit ? (str + 1) : nullptr;
}
const char * hasLetter(const char * str)
{
  if (!str)
  {
    return str;
  }
  bool checkLetter = (*str >= 'a') && (*str <= 'f');
  checkLetter = checkLetter || ((*str >= 'x') && (*str <= 'z'));
  return checkLetter ? (str + 1) : nullptr;
}
const char * hasUnsignedInteger(const char * str)
{
  if (!str)
  {
    return str;
  }
  auto next = hasDigit(str);
  if (auto continues = hasUnsignedInteger(next))
  {
    return continues;
  }
  return next;
}
const char * hasSymbol(const char * str, char c)
{
  if (!str)
  {
    return str;
  }
  return (*str == c) ? (str + 1) : nullptr;
}

#include "grammarChecker.hpp"

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
  auto next = maslov::hasTerm(str);
  auto nextPlus = maslov::hasSymbol(next, '+');
  auto nextMinus = maslov::hasSymbol(next, '-');
  if (nextMinus || nextPlus)
  {
    next++;
    next = hasExpression(next);
  }
  return next;
}
const char * maslov::hasMultiplier(const char * str)
{
  if (!str)
  {
    return str;
  }
  auto next = maslov::hasSymbol(str, '(');
  if (next)
  {
    auto afterNext = maslov::hasExpression(next);
    if (afterNext && maslov::hasSymbol(afterNext, ')'))
    {
      return afterNext + 1;
    }
  }
  next = maslov::hasUnsignedInteger(str);
  if (next)
  {
    return next;
  }
  next = maslov::hasIdentifier(str);
  if (next)
  {
    return next;
  }
  return next;
}
const char * maslov::hasTerm(const char * str)
{
  if (!str)
  {
    return str;
  }
  auto next = maslov::hasMultiplier(str);
  if (next)
  {
    return next;
  }
  next = maslov::hasSymbol(str, '(');
  if (next)
  {
    next = maslov::hasMultiplier(next);
    auto nextMultiplication = maslov::hasSymbol(next, '*');
    auto nextDivision = maslov::hasSymbol(next, '/');
    if (nextDivision || nextMultiplication)
    {
      next++;
    }
    next = maslov::hasTerm(next);
    next = maslov::hasSymbol(next, ')');
  }
  return next;
}
const char * maslov::hasIdentifier(const char * str)
{
  if (!str)
  {
    return str;
  }
  return maslov::hasLetter(str);
}
const char * maslov::hasDigit(const char * str)
{
  if (!str)
  {
    return str;
  }
  bool checkDigit = (*str >= '0') && (*str <= '9');
  return checkDigit ? (str + 1) : nullptr;
}
const char * maslov::hasLetter(const char * str)
{
  if (!str)
  {
    return str;
  }
  bool checkLetter = (*str >= 'a') && (*str <= 'f');
  checkLetter = checkLetter || ((*str >= 'x') && (*str <= 'z'));
  return checkLetter ? (str + 1) : nullptr;
}
const char * maslov::hasUnsignedInteger(const char * str)
{
  if (!str)
  {
    return str;
  }
  auto next = maslov::hasDigit(str);
  if (auto continues = hasUnsignedInteger(next))
  {
    return continues;
  }
  return next;
}
const char * maslov::hasSymbol(const char * str, char c)
{
  if (!str)
  {
    return str;
  }
  return (*str == c) ? (str + 1) : nullptr;
}

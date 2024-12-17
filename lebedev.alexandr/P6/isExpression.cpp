#include "isExpression.hpp"
#include <cctype>
#include <memory>

bool correctSymbol(const char* c)
{
  return ((*c >= 'a' && *c <= 'f') || (*c >= 'x' && *c <= 'z'));
}

bool isDigit(const char** str)
{
  if (std::isdigit(**str))
  {
    ++(*str);
    return true;
  }
  return false;
}

bool isSymbol(const char** str)
{
  if (correctSymbol(*str))
  {
    ++(*str);
    return true;
  }
  return false;
}

bool hasID(const char** str)
{
  return isSymbol(str);
}

bool hasNumber(const char** str)
{
  bool result = isDigit(str);
  if (result)
  {
    hasNumber(str);
  }
  return result;
}

bool hasMultiplier(const char** str)
{
  return hasNumber(str) || hasID(str);
}

bool hasTerm(const char** str)
{
  if (hasMultiplier(str))
  {
    if (**str == '*' || **str == '/')
    {
      (*str)++;
      return hasTerm(str);
    }
    return true;
  }
  return false;
}

bool lebedev::hasExpression(const char** str)
{
  if (hasTerm(str))
  {
    if ((**str == '+') || (**str == '-'))
    {
      (*str)++;
      return hasExpression(str);
    }
    return true;
  }
  return false;
}

bool lebedev::isExpression(const char* str)
{
  return (hasExpression(std::addressof(str)) && (*str == '\0'));
}

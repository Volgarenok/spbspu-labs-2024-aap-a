#include "isexpression.h"
#include <cctype>
#include <cstddef>

namespace
{
  bool isNeededSymbol(const char* symbol);
  bool isDigit(const char** str);
  bool isSymbol(const char** str);
  bool hasId(const char** str);
  bool hasNumber(const char** str);
  bool hasMultiplier(const char** str);
  bool hasTerm(const char** str);

  bool isNeededSymbol(const char* symbol)
  {
    return (*symbol >= 'a' && *symbol <= 'e');
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
    if (isNeededSymbol(*str))
    {
      ++(*str);
      return true;
    }
    return false;
  }

  bool hasId(const char** str)
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
    return hasNumber(str) || hasId(str);
  }

  bool hasTerm(const char** str)
  {
    if (hasMultiplier(str))
    {
      if (**str == '*')
      {
        (*str)++;
        return hasTerm(str);
      }
      return true;
    }
    return false;
  }
}

bool tkach::hasExpression(const char** str)
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

bool tkach::isExpression(const char *str)
{
  return hasExpression(&str) && *str == '\0';
}

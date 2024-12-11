#include "parseexpr.h"
#include <cctype>
#include <cstddef>

namespace averenkov
{
  bool hasExpression(const char* str, size_t& index);
  bool hasTerm(const char* str, size_t& index);
  bool hasFactor(const char* str, size_t& index);
  bool hasNumber(const char* str, size_t& index);
}

bool averenkov::hasExpression(const char* str, size_t& index)
{
  if (!averenkov::hasTerm(str, index))
  {
    return false;
  }
  if (str[index] == '+' || str[index] == '-')
  {
    index++;
    return averenkov::hasExpression(str, index);
  }
  return true;
}

bool averenkov::hasTerm(const char* str, size_t& index)
{
  if (!averenkov::hasFactor(str, index))
  {
    return false;
  }
  if (str[index] == '*' || str[index] == '/')
  {
    index++;
    return averenkov::hasTerm(str, index);
  }
  return true;
}

bool averenkov::hasNumber(const char* str, size_t& index)
{
  if (str[index] == '+' || str[index] == '-')
  {
    index++;
  }
  bool hasDigits = false;
  if (std::isdigit(str[index]))
  {
    hasDigits = true;
    index++;
    return averenkov::hasNumber(str, index);
  }
  if (str[index] == '.')
  {
    index++;
    if (std::isdigit(str[index]))
    {
      hasDigits = true;
      index++;
      return averenkov::hasNumber(str, index);
    }
    return false;
  }
  if ((str[index] == 'e' || str[index] == 'E') && hasDigits)
  {
    index++;
    if (str[index] == '+' || str[index] == '-')
    {
      index++;
    }
    if (std::isdigit(str[index]))
    {
      index++;
      return averenkov::hasNumber(str, index);
    }
    return false;
  }
  return hasDigits;
}

bool averenkov::hasFactor(const char* str, size_t& index)
{
  if (str[index] == '(')
  {
    index++;
    if (!averenkov::hasExpression(str, index))
    {
      return false;
    }
    if (str[index] != ')')
    {
      return false;
    }
    index++;
    return true;
  }
  if (std::isalpha(str[index]))
  {
    index++;
    return true;
  }
  return averenkov::hasNumber(str, index);
}

bool averenkov::isReal(const char* str)
{
  size_t index = 0;
  if (averenkov::hasExpression(str, index) && str[index] == '\0')
  {
    return true;
  }
  return false;
}


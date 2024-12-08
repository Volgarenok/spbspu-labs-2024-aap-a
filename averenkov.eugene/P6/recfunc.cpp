#include "recfunc.h"
#include <iostream>
#include <cctype>

namespace averenkov
{
  bool hasExpression(char* str, size_t& index);
  bool hasTerm(char* str, size_t& index);
  bool hasFactor(char* str, size_t& index);
  bool hasNumber(char* str, size_t& index);
}

bool averenkov::hasExpression(char* str, size_t& index)
{
  if (!averenkov::hasTerm(str, index))
  {
    return false;
  }
  while (str[index] == '+' || str[index] == '-')
  {
    index++;
    if (!averenkov::hasExpression(str, index))
    {
      return false;
    }
  }
  return true;
}

bool averenkov::hasTerm(char* str, size_t& index)
{
  if (!averenkov::hasFactor(str, index))
  {
    return false;
  }
  while (str[index] == '*' || str[index] == '/')
  {
    index++;
    if (!averenkov::hasTerm(str, index))
    {
      return false;
    }
  }
  return true;
}

bool averenkov::hasNumber(char* str, size_t& index) {
  bool hasDigits = false;
  if (str[index] == '+' || str[index] == '-')
  {
    index++;
  }
  while (std::isdigit(str[index]))
  {
    index++;
    hasDigits = true;
  }
  if (str[index] == '.')
  {
    index++;
    while (std::isdigit(str[index]))
    {
      index++;
      hasDigits = true;
    }
  }
  if ((str[index] == 'e' || str[index] == 'E') && hasDigits)
  {
    index++;
    if (str[index] == '+' || str[index] == '-')
    {
      index++;
    }
    hasDigits = false;
    while (std::isdigit(str[index]))
    {
      index++;
      hasDigits = true;
    }
  }
  return hasDigits;
}

bool averenkov::hasFactor(char* str, size_t& index)
{
  if (std::isalpha(str[index]))
  {
    index++;
    return true;
  }
  return averenkov::hasNumber(str, index);
}

bool averenkov::parse(char* str)
{
  size_t index = 0;
  if (averenkov::hasExpression(str, index) && str[index] == '\0')
  {
    return true;
  }
  return false;
}


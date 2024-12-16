#include "isReal.h"
#include <cctype>
#include <cstddef>
#include <iostream>

namespace averenkov
{
  bool isSumb(const char* str, size_t& index);
  bool hasExpression(const char* str, size_t& index);
  bool hasTerm(const char* str, size_t& index);
  bool hasFactor(const char* str, size_t& index);
  bool hasNumber(const char* str, size_t& index);
}

bool averenkov::isSumb(const char* str, size_t& index)
{
  if (!(str[index] >= 'a' && str[index] <= 'f') && !(str[index] >= 'x' && str[index] <= 'z'))
  {
    return false;
  }
  index++;
  return true;
}
bool averenkov::hasNumber(const char* str, size_t& index)
{
  if (!std::isdigit(str[index]))
  {
    return false;
  }
  index++;
  if (std::isdigit(str[index]))
  {
    return hasNumber(str, index);
  }
  return true;
}


bool averenkov::hasFactor(const char* str, size_t& index)
{
  if (str[index] == '(')
  {
    index++;
    if (!hasExpression(str, index))
    {
      return false;
    }
    if (str[index] == ')')
    {
      index++;
      return true;
    }
    return false;
  }
  return hasNumber(str, index) || isSumb(str, index);
}

bool averenkov::hasTerm(const char* str, size_t& index)
{
  if (!hasFactor(str, index))
  {
    return false;
  }
  if (str[index] == '*' || str[index] == '/')
  {
    index++;
    return hasTerm(str, index);
  }
  return true;
}

bool averenkov::hasExpression(const char* str, size_t& index)
{
  if (!hasTerm(str, index))
  {
    return false;
  }
  if (str[index] == '+' || str[index] == '-')
  {
    index++;
    return hasExpression(str, index);
  }
  return true;
}


bool averenkov::isReal(const char* str)
{
  size_t index = 0;
  if (hasExpression(str, index) && str[index] == '\0')
  {
    return true;
  }
  return false;
}


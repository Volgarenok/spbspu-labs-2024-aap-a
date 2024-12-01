#include "recfunc.h"
#include <iostream>
#include <cctype>

namespace averenkov
{
  bool hasDigit(char c);
  bool hasLetter(char c);
  bool hasUnsignedInt(const char* str, size_t& index);
  bool hasIdentifier(const char* str, size_t& index);
  bool hasFactor(const char* str, size_t& index);
  bool hasTerm(const char* str, size_t& index);
  bool hasExpression(const char* str, size_t& index);
}

bool averenkov::hasDigit(char c)
{
  return c >= '0' && c <= '9';
}
bool averenkov::hasLetter(char c)
{
  return (c >= 'a' && c <= 'z');
}
bool averenkov::hasUnsignedInt(const char* str, size_t& index)
{
  if (!averenkov::hasDigit(str[index]))
  {
    return false;
  }
  index++;
 return str[index] == '\0' || averenkov::hasUnsignedInt(str, index);
}
bool averenkov::hasIdentifier(const char* str, size_t& index)
{
  if (averenkov::hasLetter(str[index]))
  {
    index++;
    return true;
  }
  return false;
}
bool averenkov::hasFactor(const char* str, size_t& index)
{
  size_t start = index;
  if (averenkov::hasUnsignedInt(str, index))
  {
     return true;
  }
  index = start;
  if (averenkov::hasIdentifier(str, index))
  {
    return true;
  }
  index = start;
  if (str[index] == '(')
  {
    index++;
    if (averenkov::hasExpression(str, index) && str[index] == ')')
    {
      index++;
      return true;
    }
  }
  index = start;
  return false;
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

bool averenkov::hasExpression(const char* str, size_t& index)
{
  size_t start = index;
  if (!averenkov::hasTerm(str, index))
  {
    return false;
  }
  while (str[index] == '+' || str[index] == '-')
  {
    index++;
    if (!averenkov::hasTerm(str, index))
    {
      index = start;
      return false;
    }
  }
  return true;
}
bool averenkov::hasValidExpression(const char* str)
{
  size_t index = 0;
  if (averenkov::hasExpression(str, index) && str[index] == '\0')
  {
    return true;
  }
  return false;
}


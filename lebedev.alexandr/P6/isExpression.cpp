#include "isExpression.hpp"
#include <cctype>

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

#include "isExpression.h"
const char* isSymbol(const char* string, const char s)
{
  if (!string)
  {
    return string;
  }
  return (*string == s) ? (string + 1) : nullptr;
}
const char* isX(const char* string)
{
  return isSymbol(string, 'x');
}
const char* isY(const char* string)
{
  return isSymbol(string, 'y');
}
const char* isZ(const char* string)
{
  return isSymbol(string, 'z');
}

bool kiselev::isExpression(const char* string)
{
  return true;
}


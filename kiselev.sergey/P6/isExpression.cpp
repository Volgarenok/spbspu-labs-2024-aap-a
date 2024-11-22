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
const char* isNullorOne(const char* string)
{
  auto next = isSymbol(string, '0');
  return next ? next : isSymbol(string, '1');
}
const char* isID(const char* string)
{
  if (!string)
  {
    return string;
  }
  auto next = isX(string);
  if (next)
  {
    return next;
  }
  next = isY(string);
  if (next)
  {
    return next;
  }
  next = isZ(string);
  return next;
}
const char* isUnsignedNumber(const char* string)
{
  if (!string)
  {
    return string;
  }
  auto next = isNullorOne(string);
  if (auto continues = isUnsignedNumber(next))
  {
    return continues;
  }
  return next;
}
bool kiselev::isExpression(const char* string)
{
  return true;
}

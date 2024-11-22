#include "isExpression.h"
const char* hasExpression(const char* string);
const char* hasSymbol(const char* string, const char s)
{
  if (!string)
  {
    return string;
  }
  return (*string == s) ? (string + 1) : nullptr;
}
const char* hasX(const char* string)
{
  return hasSymbol(string, 'x');
}
const char* hasY(const char* string)
{
  return hasSymbol(string, 'y');
}
const char* hasZ(const char* string)
{
  return hasSymbol(string, 'z');
}
const char* hasNullorOne(const char* string)
{
  auto next = hasSymbol(string, '0');
  return next ? next : hasSymbol(string, '1');
}
const char* hasID(const char* string)
{
  if (!string)
  {
    return string;
  }
  auto next = hasX(string);
  if (next)
  {
    return next;
  }
  next = hasY(string);
  if (next)
  {
    return next;
  }
  next = hasZ(string);
  return next;
}
const char* hasUnsignedNumber(const char* string)
{
  if (!string)
  {
    return string;
  }
  auto next = hasNullorOne(string);
  if (auto continues = hasUnsignedNumber(next))
  {
    return continues;
  }
  return next;
}
const char* hasMultiplier(const char* string)
{
  if (!string)
  {
    return string;
  }
  auto next = hasUnsignedNumber(string);
  if (next)
  {
    return next;
  }
  next = hasID(string);
  if (next)
  {
    return next;
  }
  next = hasExpression(string);
  return next;
}
const char* hasExpression(const char* string)
{
  return string;
}
bool kiselev::isExpression(const char* string)
{
  return true;
}

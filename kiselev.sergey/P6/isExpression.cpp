#include "isExpression.h"
const char* hasExpression(const char* string);
const char* hasSymbol(const char* string, char s)
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
  const char* next = hasSymbol(string, '1');
  return next ? next : hasSymbol(string, '0');
}
const char* hasID(const char* string)
{
  if (!string)
  {
    return string;
  }
  const char* next = hasX(string);
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
  const char* next = hasNullorOne(string);
  if (!next)
  {
    return nullptr;
  }
  if (const char* continues = hasUnsignedNumber(next))
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
  const char* next = hasUnsignedNumber(string);
  if (next)
  {
    return next;
  }
  next = hasID(string);
  if (next)
  {
    return next;
  }
  if (*string == '(')
  {
    string++;
    next = hasExpression(string);
    if (next && *next == ')')
    {
      return next + 1;
    }
    return nullptr;
  }
  return nullptr;
}
const char* hasTerm(const char* string)
{
  if (!string)
  {
    return string;
  }
  const char* next = hasMultiplier(string);
  if (!next)
  {
    return next;
  }
  if (*next == '*')
  {
    next++;
    const char* continues = hasTerm(next);
    if (!continues)
    {
      return nullptr;
    }
    return continues;
  }
  if (*next == '(')
  {
    next++;
    const char* continues = hasMultiplier(next);
    if (!continues)
    {
      return nullptr;
    }
    if (*continues == '+')
    {
      continues++;
      const char* nextTerm = hasTerm(continues);
      if (!nextTerm || *nextTerm != ')')
      {
        return nullptr;
      }
      return nextTerm + 1;
    }
    if (*next != ')')
    {
      return nullptr;
    }
    return continues + 1;
  }
  return next;
}
const char* hasExpression(const char* string)
{
  if (!string)
  {
    return string;
  }
  const char* next = hasTerm(string);
  if (next)
  {
    if (*next == '+' || *next == '-')
    {
      next++;
      const char* continues = hasExpression(next);
      return continues;
    }
  }
  return next;
}
bool kiselev::isExpression(const char* string)
{
  const char* next = hasExpression(string);
  return next && (*next == '\0');
}

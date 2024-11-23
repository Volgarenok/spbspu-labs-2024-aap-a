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
  if (*next == '(')
  {
    next++;
    next = hasExpression(string);
    if (next)
    {
      if (*next == ')')
      {
        return next;
      }
    }
  }
  return next;
}
const char* hasTerm(const char* string)
{
  if (!string)
  {
    return string;
  }
  if (*string == '(')
  {
    string++;
    auto next = hasMultiplier(string);
    if (next)
    {
      if (*next == '+')
      {
        next++;
        if (!hasTerm(next))
        {
          return nullptr;
        }
        else
        {
          if (*next == ')')
          {
            return next;
          }
          else
          {
            return nullptr;
          }
        }
      }
      return nullptr;
    }
    return next;
  }
  auto next = hasMultiplier(string);
  if (next)
  {
    if (*next == '+')
    {
      if (auto countinues = hasTerm(next))
      {
        return countinues;
      }
    }
    return next;
  }
  return next;
}
const char* hasExpression(const char* string)
{
  if (!string)
  {
    return string;
  }
  auto next = hasTerm(string);
  if (*(next + 1) == '+' || *(next + 1) == '-')
  {
    next++;
    if (auto continues = hasExpression(next))
    {
      return continues;
    }
    return nullptr;
  }
  return next;
}
bool kiselev::isExpression(const char* string)
{
  auto next = hasExpression(string);
  return next && (*next == '\0');
}

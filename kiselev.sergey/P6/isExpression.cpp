#include "isExpression.h"
namespace
{
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
    if ((string = hasSymbol(string, '(')))
    {
      next = hasExpression(string);
      if ((next = hasSymbol(next, ')')))
      {
        return next;
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
    if (const char* next2 = hasSymbol(next, '*'))
    {
      const char* continues = hasTerm(next2);
      if (!continues)
      {
        return nullptr;
      }
      return continues;
    }
    if (const char* next3 = hasSymbol(next, '('))
    {
      const char* continues = hasMultiplier(next3);
      if (!continues)
      {
        return nullptr;
      }
      if (const char* continues2 = hasSymbol(continues, '+'))
      {
        const char* nextTerm = hasTerm(continues2);
        if (!nextTerm || !hasSymbol(nextTerm, ')'))
        {
          return nullptr;
        }
        return nextTerm;
      }
      if (!hasSymbol(next, ')'))
      {
        return nullptr;
      }
      return continues;
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
      if (const char* next2 = hasSymbol(next, '+'))
      {
        return hasExpression(next2);
      }
      else if (const char* next2 = hasSymbol(next, '-'))
      {
        return hasExpression(next2);
      }
    }
    return next;
  }
}
bool kiselev::isExpression(const char* string)
{
  const char* next = hasExpression(string);
  return next && (hasSymbol(next, '\0'));
}


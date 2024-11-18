#include "checkuniquechars.h"
#include <iostream>

bool savintsev::isOneOfTheLetters(char c)
{
  return ((c >= 97 && c <= 102) || (c >= 120 && c <= 122));
}

bool savintsev::isUnsignedInteger(const char * s, int & pos)
{
  if (!s[pos] || !std::isdigit(s[pos]))
  {
    return false;
  }
  pos++;
  if (!s[pos] || !std::isdigit(s[pos]))
  {
    return true;
  }
  return isUnsignedInteger(s, pos);
}

bool savintsev::isIdentifier(const char * s, int & pos)
{
  if (isOneOfTheLetters(s[pos]))
  {
    pos++;
    return true;
  }
  return false;
}

bool savintsev::isMultiplier(const char * s, int & pos)
{
  int start = pos;
  if (isUnsignedInteger(s, pos) || isIdentifier(s, pos))
  {
    return true;
  }
  if (s[pos] == '(')
  {
    pos++;
    if (isExpression(s, pos) && s[pos] == ')')
    {
      pos++;
      return true;
    }
  }
  pos = start;
  return false;
}

bool savintsev::isTerm(const char * s, int & pos)
{
  int start = pos;
  if (isMultiplier(s, pos))
  {
    return true;
  }
  if (s[pos] == '(')
  {
    pos++;
    if (isMultiplier(s, pos))
    {
      if (s[pos] == '*' || s[pos] == '/')
      {
        pos++;
        if (isTerm(s, pos) && s[pos] == ')')
        {
          pos++;
          return true;
        }
      }
    }
  }
  pos = start;
  return false;
}

bool savintsev::isExpression(const char * s, int & pos)
{
  int start = pos;
  if (isTerm(s, pos))
  {
    return true;
  }
  if (isTerm(s, pos))
  {
    if (s[pos] == '+' || s[pos] == '-')
    {
      pos++;
      if (isExpression(s, pos))
      {
        return true;
      }
    }
  }
  pos = start;
  return false;
}

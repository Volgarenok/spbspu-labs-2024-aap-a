#include "checkuniquechars.h"
#include <cctype>
#include <cstring>

bool isOneOfTheLetters(char c);
bool isUnsignedInteger(const char * s, size_t & pos);
bool isMultiplier(const char * s, size_t & pos);
bool isTerm(const char * s, size_t & pos);
bool isIdentifier(const char * s, size_t & pos);

bool isOneOfTheLetters(char c)
{
  const char * letters = "abcdefxyz";
  for (size_t i = 0; i < std::strlen(letters); ++i)
  {
    if (c == letters[i])
    {
      return true;
    }
  }
  return false;
}

bool isUnsignedInteger(const char * s, size_t & pos)
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

bool isIdentifier(const char * s, size_t & pos)
{
  if (isOneOfTheLetters(s[pos]))
  {
    pos++;
    return true;
  }
  return false;
}

bool isMultiplier(const char * s, size_t & pos)
{
  int start = pos;
  if (isUnsignedInteger(s, pos) || isIdentifier(s, pos))
  {
    return true;
  }
  if (s[pos] == '(')
  {
    pos++;
    if (savintsev::isExpression(s, pos) && s[pos] == ')')
    {
      pos++;
      return true;
    }
  }
  pos = start;
  return false;
}

bool isTerm(const char * s, size_t & pos)
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

bool savintsev::isExpression(const char * s, size_t & pos)
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

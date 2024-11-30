#include "checkuniquechars.h"
#include <cctype>
#include <cstring>

namespace
{
  bool isOneOfTheLettersEnc(char c, const char * letters);
  bool isUnsignedIntegerEnc(const char * s, size_t & pos);
  bool isMultiplierEnc(const char * s, size_t & pos);
  bool isTermEnc(const char * s, size_t & pos);
  bool isIdentifierEnc(const char * s, size_t & pos);
  bool isExpressionEnc(const char * s, size_t & pos);

  bool isOneOfTheLettersEnc(char c, const char * letters)
  {
    if (*letters == '\0')
    {
      return false;
    }
    if (*letters == c)
    {
      return true;
    }
    return isOneOfTheLettersEnc(c, letters + 1);
  }

  bool isUnsignedIntegerEnc(const char * s, size_t & pos)
  {
    if (!std::isdigit(s[pos]))
    {
      return false;
    }
    ++pos;
    if (!std::isdigit(s[pos]))
    {
      return true;
    }
    return isUnsignedIntegerEnc(s, pos);
  }

  bool isIdentifierEnc(const char * s, size_t & pos)
  {
    const char * letters = "abcdefxyz";
    if (isOneOfTheLettersEnc(s[pos], letters))
    {
      ++pos;
      return true;
    }
    return false;
  }

  bool isMultiplierEnc(const char * s, size_t & pos)
  {
    size_t start = pos;
    if (isUnsignedIntegerEnc(s, pos) || isIdentifierEnc(s, pos))
    {
      return true;
    }
    if (s[pos] == '(')
    {
      ++pos;
      if (isExpressionEnc(s, pos) && s[pos] == ')')
      {
        ++pos;
        return true;
      }
    }
    pos = start;
    return false;
  }

  bool isTermEnc(const char * s, size_t & pos)
  {
    size_t start = pos;
    if (isMultiplierEnc(s, pos))
    {
      return true;
    }
    if (s[pos] == '(')
    {
      ++pos;
      if (isMultiplierEnc(s, pos))
      {
        if (s[pos] == '*' || s[pos] == '/')
        {
          ++pos;
          if (isTermEnc(s, pos) && s[pos] == ')')
          {
            ++pos;
            return true;
          }
        }
      }
    }
    pos = start;
    return false;
  }

  bool isExpressionEnc(const char * s, size_t & pos)
  {
    size_t start = pos;
    if (isTermEnc(s, pos))
    {
      if (s[pos] == '+' || s[pos] == '-')
      {
        ++pos;
        if (isExpressionEnc(s, pos))
        {
          return true;
        }
      }
      return true;
    }
    pos = start;
    return false;
  }
}

bool savintsev::isExpression(const char * s)
{
  size_t pos = 0;
  return isExpressionEnc(s, pos) && s[pos] == '\0';
}

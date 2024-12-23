#include "recursiveStringCheck.h"
#include <cctype>
#include <cstring>

namespace
{
  const char * signCheck(const char * str);
  const char * digitCheck(const char * str);
  const char * symbolCheck(const char * str, char c);
  const char * unsignedIntCheck(const char * str);
  const char * orderCheck(const char * str);
  const char * mantisCheck(const char * str);
  int countFrq(const char * string, int i, int count);
  char * twoFrq(const char * string, int * max, char * maxSym);

  const char * signCheck(const char * string)
  {
    if (!string)
    {
      return string;
    }

    return ((*string == '+') || (*string == '-')) ? (string + 1) : nullptr;
  }

  const char * digitCheck(const char * string)
  {
    if (!string)
    {
      return string;
    }

    return ((*string >= '0') && (*string <= '9')) ? (string + 1) : nullptr;
  }

  const char * symbolCheck(const char * string, char c)
  {
    if (!string)
    {
      return string;
    }

    return ((*string == c)) ? (string + 1) : nullptr;
  }

  const char * unsignedIntCheck(const char * string)
  {
    if (!string)
    {
      return string;
    }

    auto next = digitCheck(string);
    auto continuous = unsignedIntCheck(next);
    if (!continuous)
    {
      return next;
    }
    return continuous;
  }

  const char * orderCheck(const char * string)
  {
    if (!string)
    {
      return string;
    }

    auto next = symbolCheck(string, 'E');
    if (!next)
    {
      return next;
    }
    auto continuous = signCheck(next);
    if (continuous != nullptr)
    {
      next = continuous;
    }
    return unsignedIntCheck(next);
  }

  const char * mantisCheck(const char * string)
  {
    if (!string)
    {
      return string;
    }

    auto next = symbolCheck(string, '.');
    if (!next)
    {
      return unsignedIntCheck(string);
    }
    return unsignedIntCheck(next);
  }

  int countFrq(const char * string, int i, int count)
  {
    if (string[i] == '\0')
    {
      return count;
    }
    if (*string == string[i])
    {
      count++;
    }
    return countFrq(string, i + 1, count);
  }

  char * twoFrq(const char * string, int * max, char * maxSym)
  {
    if (*string == '\0')
    {
      return maxSym;
    }

    int count = countFrq(string, 0, 0);
  
    if (max[0] < count)
    {
      max[1] = max[0];
      maxSym[1] = maxSym[0];

      max[0] = count;
      maxSym[0] = *string;
    }
    else if (count > max[1] && *string != maxSym[0])
    {
      max[1] = count;
      maxSym[1] = *string;
    }
    return twoFrq(string + 1, max, maxSym);
  }
}

bool ivanova::rightString(const char * string)
{
  if (!string)
  {
    return false;
  }

  auto next = signCheck(string);
  if (!next)
  {
    next = string;
  }
  next = mantisCheck(next);
  if (orderCheck(next))
  {
    return true;
  }
  return false;
}

void ivanova::twoFrequentSymbol(const char * string, char* dest)
{
  int max[2] = {0, 0};
  char maxSym[2] = {'\0', '\0'}; 
  
  twoFrq(string, max, maxSym);

  dest[0] = maxSym[0];
  dest[1] = maxSym[1];
  dest[2] = '\0';
}

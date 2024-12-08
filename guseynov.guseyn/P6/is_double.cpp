#include "is_double.hpp"

#include <cstddef>
#include <cctype>

namespace
{
  bool isDigit(char c, unsigned int checkNum);
  const char * isSymbol(const char * str, char c);
  const char * isSign(const char * str);
  const char * isNum(const char * str);
  const char * isUnsignNum(const char * str);
  const char * isOrder(const char * str);
  const char * isMantis(const char * str);

  const char * isSymbol(const char * str, char c)
  {
    return ((str != nullptr) && (*str == c)) ? (str + 1) : nullptr;
  }

  const char * isSign(const char * str)
  {
    return ((str != nullptr) && ((*str == '+') || (*str == '-'))) ? (str + 1) : nullptr;
  }

  bool isDigit(char c, unsigned int checkNum)
  {
    unsigned int k = c - '0';
    if ((k / 10) != 0)
    {
      return false;
    }
    if ((k != checkNum) && (k != 9))
    {
      checkNum++;
      return isDigit(c, checkNum);
    }
    else
    {
      if (k == checkNum)
      {
        return true;
      }
      if (k == 9)
      {
        return false;
      }
    }
    return false;
  }

  const char * isNum(const char * str)
  {
    return ((str != nullptr) && (isDigit(*str, 0))) ? (str + 1) : nullptr;
  }

  const char * isUnsignNum(const char * str)
  {
    if (!str)
    {
      return str;
    }
    auto next = isNum(str);
    auto continues = isUnsignNum(next);
    if (continues)
    {
      return continues;
    }
    return next;
  }

  const char * isOrder(const char * str)
  {
    if (!str)
    {
      return str;
    }
    auto next = isSymbol(str, 'E');
    if (!next)
    {
      return nullptr;
    }
    auto contine = isSign(next);
    if (contine != nullptr)
    {
      next = contine;
    }
    next = isUnsignNum(next);
    return next;
  }

  const char * isMantis(const char * str)
  {
    if (!str)
    {
      return str;
    }
    auto next = isSymbol(str, '.');
    if (!next)
    {
      return isUnsignNum(str);
    }
    return isUnsignNum(next);
  }
}

bool guseynov::isDouble(const char * str)
{
  if (!str)
  {
    return false;
  }
  auto next = isSign(str);
  if (!next)
  {
    next = str;
  }
  next = isMantis(next);
  if (isOrder(next))
  {
    return true;
  }
  return false;
}

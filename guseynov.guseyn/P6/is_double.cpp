#include "is_double.hpp"

#include <cstddef>
#include <cctype>

const char * guseynov::isSymbol(const char * str, char c)
{
  return ((str != nullptr) && (*str == c)) ? (str + 1) : nullptr;
}

const char * guseynov::isSign(const char * str)
{
  return ((str != nullptr) && ((*str == '+') || (*str == '-'))) ? (str + 1) : nullptr;
}

bool guseynov::isDigit(char c)
{
  int k = c - '0';
  if ((k/10) != 0)
  {
    return false;
  }
  static int i = 0;
  if ((k != i) && (k != 9))
  {
    i++;
    return isDigit(c);
  }
  else
  {
    if (k == i)
    {
      i = 0;
      return true;
    }
    if (k == 9)
    {
      i = 0;
      return false;
    }
  }
  return false;
}

const char * guseynov::isNum(const char * str)
{
  return ((str != nullptr) && (guseynov::isDigit(*str))) ? (str + 1) : nullptr;
}

const char * guseynov::isUnsignNum(const char * str)
{
  if (!str)
  {
    return str;
  }
  auto next = guseynov::isNum(str);
  auto continues = guseynov::isUnsignNum(next);
  if (continues)
  {
    return continues;
  }
  return next;
}

const char * guseynov::isOrder(const char * str)
{
  if (!str)
  {
    return str;
  }
  auto next = guseynov::isSymbol(str, 'E');
  if (!next)
  {
    return nullptr;
  }
  auto contine = guseynov::isSign(next);
  if (contine != nullptr)
  {
  next = contine;
  }
  next = guseynov::isUnsignNum(next);
  return next;
}

const char * guseynov::isMantis(const char * str)
{
  if (!str)
  {
    return str;
  }
  auto next = guseynov::isSymbol(str, '.');
  if (!next)
  {
    return guseynov::isUnsignNum(str);
  }
  return guseynov::isUnsignNum(next);
}

bool guseynov::isDouble(const char * str)
{
  if (!str)
  {
    return false;
  }
  auto next = guseynov::isSign(str);
  if (!next)
  {
    next = str;
  }
  next = guseynov::isMantis(next);
  if (guseynov::isOrder(next))
  {
    return true;
  }
  return false;
}

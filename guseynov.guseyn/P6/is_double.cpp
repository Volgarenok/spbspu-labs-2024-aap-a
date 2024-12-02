#include "is_double.hpp"

#include <cstddef>
#include <cctype>

const char * guseynov::isSymbol(const char * str, char c)
{
  if (!str)
  {
    return str;
  }
  return (*str == c) ? (str + 1) : nullptr;
}

const char * guseynov::isSign(const char * str)
{
  if (!str)
  {
    return str;
  }
  auto next = guseynov::isSymbol(str, '+');
  if (next)
  {
    return next;
  }
  next = guseynov::isSymbol(str, '-');
  return next;
}

const char * guseynov::isNum(const char * str)
{
  if (!str)
  {
    return str;
  }
  return (std::isdigit(*str)) ? (str + 1) : nullptr;
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
  if (!guseynov::isSign(next))
  {
  next = guseynov::isUnsignNum(next);
  }
  else
  {
    next = guseynov::isUnsignNum(next + 1);
  }
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
  size_t i = 0;
  auto next = guseynov::isSign(str);
  if (!next)
  {
    i++;
  }
  next = guseynov::isMantis(str + i);
  if (guseynov::isOrder(next))
  {
    return true;
  }
  return false;
}

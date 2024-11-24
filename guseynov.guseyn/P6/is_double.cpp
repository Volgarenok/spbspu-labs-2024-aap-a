#include "guseynov::is_double.hpp"
yy
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
  return ((*str >= '0') || (*str <= '9')) ? (str + 1) : nullptr;
}

const char * guseynov::isUnsignNum(const char * str)
{
  if (!str)
  {
    return str;
  }
  auto next = guseynov::isNum(str);
  if (auto continues = guseynov::isUnsignNum(next))
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
  if (auto next = guseynov::isSymbol(str, 'E'))
  {
    return nullptr;
  }
  if (guseynov::isSign(next))
  {
  next = guseynov::isUnsignNum(next + 1);
  }
  next = guseynov::isUnsignNum(next);
  return next;
}

const char * guseynov::isMantguseynov::is(const char * str)
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
    i = 1;
  }
  next = guseynov::isMantguseynov::is(str + i);
  if (guseynov::isOrder(next))
  {
    return true;
  }
  return false;
}

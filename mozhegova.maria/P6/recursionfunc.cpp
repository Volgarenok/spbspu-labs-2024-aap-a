#include "recursionfunc.hpp"

const char * mozhegova::isSymbol(const char * str, const char c)
{
  if (!str)
  {
    return str;
  }
  return (*str == c) ? (str + 1) : nullptr;
}

const char * mozhegova::hasLetter(const char * str)
{
  if (!str)
  {
    return str;
  }
  return (*str >= 'A' && *str <= 'E') ? (str + 1) : nullptr;
}

const char * mozhegova::hasNumber(const char * str)
{
  if (!str)
  {
    return str;
  }
  return (*str >= '0' && *str <= '9') ? (str + 1) : nullptr;
}

const char * mozhegova::hasIdentifier(const char * str)
{
  return mozhegova::hasLetter(str);
}

const char * mozhegova::hasUnsignedInt(const char * str)
{
  if (!str)
  {
    return str;
  }
  auto next = mozhegova::hasNumber(str);
  if (auto continues = mozhegova::hasUnsignedInt(next))
  {
    return continues;
  }
  return next;
}

const char * mozhegova::hasFactor(const char * str)
{
  if (!str)
  {
    return str;
  }
  auto next = mozhegova::hasUnsignedInt(str);
  if (next)
  {
    return next;
  }
  next = mozhegova::hasIdentifier(str);
  if (next)
  {
    return next;
  }
  next = mozhegova::hasExpression(str);
  return next;
}

const char * mozhegova::hasTerm(const char * str)
{
  if (!str)
  {
    return str;
  }
  auto next = mozhegova::hasFactor(str);
  next = mozhegova::isSymbol(next, '*');
  auto continues = mozhegova::hasTerm(next);
  if (next && continues)
  {
    return continues;
  }
  return next;
}

const char * mozhegova::hasExpression(const char * str)
{
  if (!str)
  {
    return str;
  }
  auto next = mozhegova::hasTerm(str);
  next = mozhegova::isSymbol(next, '+');
  auto continues = mozhegova::hasExpression(next);
  if (next && continues)
  {
    return continues;
  }
  next = mozhegova::isSymbol(next, '-');
  continues = mozhegova::hasExpression(next);
  if (next && continues)
  {
    return continues;
  }
  return next;
}

bool mozhegova::isExpression(const char * str)
{
  return mozhegova::hasExpression(str) != nullptr;
}
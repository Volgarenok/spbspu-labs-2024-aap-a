#include "isexpression.hpp"

const char * brevnov::isLetter(const char * str)
{
  if (!str)
  {
    return nullptr;
  }
  return ((*str == 'x') || (*str == 'y') || (*str == 'z')) ? (str + 1) : nullptr;
}

const char * brevnov::isDigit(const char * str)
{
  if (!str)
  {
    return nullptr;
  }
  return ((*str == '1') || (*str == '0')) ? (str + 1) : nullptr;
}

const char * brevnov::hasUint(const char * str)
{
  if (!str)
  {
    return nullptr;
  }
  auto next = brevnov::isDigit(str);
  return next;
}

const char * brevnov::hasMultiplier(const char * str)
{
  if (!str)
  {
    return str;
  }
  auto next = brevnov::hasUint(str);
  if (next)
  {
    return next;
  }
  return brevnov::isLetter(str);
}

const char * brevnov::hasTerm(const char * str)
{
  if (!str)
  {
    return str;
  }
  auto next = brevnov::hasMultiplier(str);
  if (brevnov::hasMultiplier(next))
  {
    return brevnov::hasTerm(next);
  }
  return next;
}

const char * brevnov::hasExpression(const char * str)
{
  if (!str)
  {
    return str;
  }
  auto next = brevnov::hasTerm(str);
  if (auto continues = brevnov::hasExpression(next))
  {
    return continues;
  }
  return next;
}

bool brevnov::isExpression(const char * str)
{
  auto next = brevnov::hasExpression(str);
  return next && (*next == '\0');
}

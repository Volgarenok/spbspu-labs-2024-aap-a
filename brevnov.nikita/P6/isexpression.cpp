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

const char * brevnov::isUint(const char * str)
{
  if (!str)
  {
    return nullptr;
  }
  auto next = brevnov::isDigit(str);
  if (next == nullptr)
  {
    return next;
  }
  else
  {
    return brevnov::isUint(next);
  }
}

const char * brevnov::isMultiplier(const char * str)
{
  if (!str)
  {
    return str;
  }
  auto next = brevnov::isUint(str);
  if (next)
  {
    return next;
  }
  return brevnov::isLetter(str);
}

const char * brevnov::isTerm(const char * str)
{
  if (!str)
  {
    return str;
  }
  auto next = brevnov::isMultiplier(str);
  if (brevnov::isMultiplier(next))
  {
    return brevnov::isTerm(next);
  }
  return next;
}

const char * brevnov::isExpreession(const char * str)
{
  if (!str)
  {
    return str;
  }
  auto next = isTerm(str);
  if (isExpreession(next))
  {
    return isExpreession(next);
  }
  return next;
}

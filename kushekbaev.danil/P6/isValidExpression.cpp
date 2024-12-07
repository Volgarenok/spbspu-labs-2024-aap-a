#include "recursion.hpp"
#include <cctype>

const char * has_expression(const char * str);

const char * has_character(const char * str, char c)
{
  if (!str)
  {
    return nullptr;
  }
  return (*str == c) ? (str + 1) : nullptr;
}

const char * has_letter(const char * str)
{
  if (!str)
  {
    return nullptr;
  }
  return (*str >= 'A' && *str <= 'E') ? (str + 1) : nullptr;
}

const char * has_number(const char * str)
{
  if (!str)
  {
    return nullptr;
  }
  return (*str >= '0' && *str <= '9') ? (str + 1) : nullptr;
}

const char * has_unsigned_int(const char * str)
{
  if (!str)
  {
    return nullptr;
  }
  const char * next = has_number(str);
  if (!next)
  {
    return nullptr;
  }
  return next;
}

const char * has_multiplier(const char * str)
{
  if (!str)
  {
    return nullptr;
  }
  const char * next = has_unsigned_int(str);
  if (!next)
  {
    return nullptr;
  }
  next = has_letter(str);
  if (!next)
  {
    return nullptr;
  }
  next = has_character(str, '(');
  next = has_expression(next);
  next = has_character(str, ')');
  return next;
}

const char * has_term(const char * str)
{
  if (!str)
  {
    return nullptr;
  }
  const char * next = has_multiplier(str);
  if (next && has_character(next, '*'))
  {
    if (const char * continues = has_term(next))
    {
      return continues;
    }
  }
  return next;
}

const char * has_expression(const char * str)
{
  if (!str)
  {
    return nullptr;
  }
  const char * next = has_term(str);
  if (const char * plus_next = has_character(next, '+'))
  {
    if (const char * continues = has_expression(plus_next))
    {
      return continues;
    }
  }
  else if (const char * minus_next = has_character(next, '-'))
  {
    if (const char * continues = has_expression(minus_next))
    {
      return continues;
    }
  }
  return next;
}

bool kushekbaev::isValidExpression(const char * str)
{
  const char * next = has_expression(str);
  return next && (*next == '\0');
}


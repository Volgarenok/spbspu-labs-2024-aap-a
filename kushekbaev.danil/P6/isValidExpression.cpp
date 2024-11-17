#include "recursion.hpp"

const char * has_expression(const char * str);

const char * has_character(const char * str, char c)
{
  if (!str)
  {
    return str;
  }
  return (*str == c) ? (str+1) : nullptr;
}

const char * has_digit(const char * str)
{
  return has_character(str, '0') ? str + 1 :
        has_character(str, '1') ? str + 1 :
        has_character(str, '2') ? str + 1 :
        has_character(str, '3') ? str + 1 :
        has_character(str, '4') ? str + 1 :
        has_character(str, '5') ? str + 1 :
        has_character(str, '6') ? str + 1 :
        has_character(str, '7') ? str + 1 :
        has_character(str, '8') ? str + 1 :
        has_character(str, '9') ? str + 1 :
        has_character(str, 'A') ? str + 1 :
        has_character(str, 'B') ? str + 1 :
        has_character(str, 'C') ? str + 1 :
        has_character(str, 'D') ? str + 1 :
        has_character(str, 'E') ? str + 1 :
        has_character(str, '(') ? str + 1 :
        has_character(str, ')') ? str + 1 : nullptr;
}

const char * has_unsigned_int(const char * str)
{
  if (!str)
  {
    return str;
  }
  const char * next = has_digit(str);
  while (next)
  {
    str = next;
    next = has_digit(str);
  }
  return str;
}

const char * has_multiplier(const char * str)
{
  if (!str)
  {
    return str;
  }

  auto next = has_unsigned_int(str);
  if (next)
  {
    return next;
  }

  next = has_digit(str);
  if (next)
  {
    return next;
  }

  next = has_expression(str);
  return next;
}

const char * has_term(const char * str)
{
  if (!str)
  {
    return str;
  }
  const char * next = has_multiplier(str);

  while (true)
  {
    const char * tmp_next = has_character(next, '*');
    if (!tmp_next)
    {
      return next;
    }
    next = has_multiplier(tmp_next);
    if (!next)
    {
      return next;
    }
  }
  return next;
}

const char * has_expression(const char * str)
{
  if (!str)
  {
    return str;
  }
  const char * next = has_term(str);
  while (true)
  {
    const char * plus_next = has_character(next, '+');
    const char * minus_next = has_character(next, '-');

    if (plus_next)
    {
      next = has_term(plus_next);
      if (!next) return nullptr;
    }
    else if (minus_next)
    {
      next = has_term(minus_next);
      if (!next) return nullptr;
    }
    else
    {
      break;
    }
  }
  return next;
}

bool kushekbaev::isValidExpression(const char * str)
{
  const char * next = has_expression(str);
  return next && *next == '\0';
}

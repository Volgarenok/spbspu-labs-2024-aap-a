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
    return nullptr
  }
  return (*str >= 'A' && *str <= 'E') ? (str + 1) : nullptr;
}

const char * has_number(const char * str)
{
  if (!str)
  {
    return nullptr;
  }
  return ((c >= '0' && c <= '9') ? (str + 1) : nullptr;
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
  if (next)
  {
    return next;
  }
  next = has_expression(str);
  return next;
}

const char * has_parentheses(const char * str)
{
  if (!str || *str != '(')
  {
    return nullptr;
  }
  const char * next = has_expression(str + 1);
  if (next && *next == ')')
  {
    return next + 1;
  }
  return nullptr;
}

const char * has_term(const char * str)
{
  if (!str)
  {
    return nullptr;
  }
  const char * next = has_multiplier(str);
  if (!next)
  {
    return nullptr;
  }
  const char * hchar_next = has_character(next, '*');
  if (hchar_next)
  {
    return has_term(hchar_next);
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
  if (!next)
  {
    return nullptr;
  }
  const char * plus_next = has_character(next, '+');
  if (plus_next)
  {
    const char * term_next = has_term(plus_next);
    if (term_next)
    {
      return has_expression(term_next);
    }
  }
  const char * minus_next = has_character(next, '-');
  if (minus_next)
  {
    const char * term_next = has_term(minus_next);
    if (term_next)
    {
      return has_expression(term_next);
    }
  }
  const char * parentheses_next = has_parentheses(next);
  if (parentheses_next)
  {
    return has_expression(parentheses_next);
  }
  return next;
}

bool kushekbaev::isValidExpression(const char * str)
{
  const char * next = has_expression(str);
  return next && (*next == '\0');
}

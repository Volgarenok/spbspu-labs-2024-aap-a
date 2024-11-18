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
        has_character(str, 'E') ? str + 1 : nullptr;
}

const char * has_unsigned_int(const char * str)
{
  if (!str)
  {
    return str;
  }
  const char * next = has_digit(str);
  if (!next)
  {
    return str;
  }

  return has_unsigned_int(next);
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
  return next;
}

const char * has_term(const char * str)
{
  if (!str)
  {
    return str;
  }
  const char * next = has_multiplier(str);
  if (!next)
  {
    return str;
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
    return str;
  }

  const char * next = has_term(str);
  if (!next)
  {
    return str;
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
  return next && *next == '\0';
}

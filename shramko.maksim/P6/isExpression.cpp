#include "isExpression.hpp"

namespace
{
  const char* has_expression(const char* str);

  const char* has_symbol(const char* str, char s)
  {
    if (!str)
    {
      return str;
    }
    return (*str == s) ? (str + 1) : nullptr;
  }

  const char* has_x(const char* str)
  {
    return has_symbol(str, 'x');
  }

  const char* has_y(const char* str)
  {
    return has_symbol(str, 'y');
  }

  const char* has_z(const char* str)
  {
    return has_symbol(str, 'z');
  }

  const char* has_one_or_zero(const char* str)
  {
    const char* next = has_symbol(str, '1');
    return next ? next : has_symbol(str, '0');
  }

  const char* has_following_id(const char* str)
  {
    if (!str)
    {
      return str;
    }

    const char* next = has_x(str);
    if (next)
    {
      return next;
    }
    next = has_y(str);
    if (next)
    {
      return next;
    }
    next = has_z(str);
    return next;
  }

  const char* has_unsigned_int(const char* str)
  {
    if (!str)
    {
      return str;
    }
    const char* next = has_one_or_zero(str);
    if (!next)
    {
      return nullptr;
    }
    if (const char* proceed = has_unsigned_int(next))
    {
      return proceed;
    }
    return next;
  }

  const char* has_multi(const char* str)
  {
    if (!str)
    {
      return str;
    }
    const char* next = has_unsigned_int(str);
    if (next)
    {
      return next;
    }
    next = has_following_id(str);
    if (next)
    {
      return next;
    }
    if ((str = has_symbol(str, '(')))
    {
      next = has_expression(str);
      if ((next = has_symbol(next, ')')))
      {
        return next;
      }
      return nullptr;
    }
    return nullptr;
  }

  const char* has_term(const char* str)
  {
    if (!str)
    {
      return str;
    }
    const char* next = has_multi(str);
    if (!next)
    {
      return next;
    }
    if (const char* next_two = has_symbol(next, '*'))
    {
      const char* proceed = has_term(next_two);
      if (!proceed)
      {
        return nullptr;
      }
      return proceed;
    }
    if (const char* next_trh = has_symbol(next, '('))
    {
      const char* proceed = has_multi(next_trh);
      if (!proceed)
      {
        return nullptr;
      }
      if (const char* proceed_two = has_symbol(proceed, '+'))
      {
        const char* next_term = has_term(proceed_two);
        if (!next_term || !has_symbol(next_term, ')'))
        {
          return nullptr;
        }
        return next_term;
      }
      if (!has_symbol(next, ')'))
      {
        return nullptr;
      }
      return proceed;
    }
    return next;
  }

  const char* has_expression(const char* str)
  {
    if (!str)
    {
      return str;
    }
    const char* next = has_term(str);
    if (next)
    {
      if (const char* next_two = has_symbol(next, '+'))
      {
        return has_expression(next_two);
      }
      else if (const char* next_two = has_symbol(next, '-'))
      {
        return has_expression(next_two);
      }
    }
    return next;
  }
}

bool shramko::is_expression(const char* str)
{
  const char* next = has_expression(str);
  return next && (has_symbol(next, '\0'));
}

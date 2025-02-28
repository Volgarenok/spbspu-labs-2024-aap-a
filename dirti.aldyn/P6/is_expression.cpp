#include "is_expression.hpp"

namespace
{
  const char * has_symbol(const char * str, char c)
  {
    if (!str)
    {
      return str;
    }
    return (*str == c) ? (str + 1) : nullptr;
  }

  const char * has_x(const char * str)
  {
    return has_symbol(str, 'x');
  }
  const char * has_y(const char * str)
  {
    return has_symbol(str, 'y');
  }
  const char * has_z(const char * str)
  {
    return has_symbol(str, 'z');
  }
  const char * has_digit(const char * str)
  {
    auto next = has_symbol(str, '0');
    return next ? next : has_symbol(str, '1');
  }

  const char * has_id(const char * str)
  {
    if (!str)
    {
      return str;
    }
    auto next = has_x(str);
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
  const char * has_number(const char * str)
  {
    if (!str)
    {
      return str;
    }
    auto next = has_digit(str);
    if (auto continues = has_number(next))
    {
      return continues;
    }
    return next;
  }
  const char * has_expression(const char * str);
  const char * has_multiplier(const char * str)
  {
    if (!str)
    {
      return str;
    }
    auto next = has_number(str);
    if (next)
    {
      return next;
    }
    next = has_id(str);
    if (next)
    {
      return next;
    }
    next = has_symbol(str, '(');
    if (next)
    {
      next = has_expression(next);
      next = has_symbol(next, ')');
      if (next)
      {
        return next;
      }
      return nullptr;
    }
    return nullptr;
  }
  const char * has_term(const char * str)
  {
    if (!str)
    {
      return str;
    }
    auto next = has_symbol(str, '(');
    if (next)
    {
      next = has_multiplier(next);
      next = has_symbol(next, '+');
      if (next)
      {
        next = has_term(next);
        if (next)
        {
          next = has_symbol(next, ')');
          if (next)
          {
            return next;
          }
        }
      }
      return nullptr;
    }
    next = has_multiplier(str);
    auto next2 = has_symbol(next, '*');
    if (next2)
    {
      if (auto continues = has_term(next2))
      {
        return continues;
      }
      return nullptr;
    }
    return next;
  }
  const char * has_expression(const char * str)
  {
    if (!str)
    {
      return str;
    }
    auto next = has_term(str);
    auto next2 = has_symbol(next, '+');
    if (next2)
    {
      if (auto continues = has_expression(next2))
      {
        return continues;
      }
      return nullptr;
    }
    next2 = has_symbol(next, '-');
    if (next2)
    {
      if (auto continues = has_expression(next2))
      {
        return continues;
      }
      return nullptr;
    }
    return next;
  }
}

bool dirti::is_expression(const char * str)
{
  auto next = has_expression(str);
  return next && (*next == '\0');
}

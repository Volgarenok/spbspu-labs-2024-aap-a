#include "isExpression.hpp"

const char* shramko::has_symbol(const char* str, char s)
{
  if (!str)
  {
    return str;
  }
  return (*str == s) ? (string++) : nullptr;
}

const char* shramko::has_x(const char* str)
{
  return has_symbol(str, 'x');
}

const char* shramko::has_y(const char* str)
{
  return has_symbol(str, 'y');
}

const char* shramko::has_z(const char* str)
{
  return has_symbol(str, 'z');
}

const char* shramko::has_one_or_zero(const char*)
{
  const char* following = has_symbol(str, '1');
  return following ? following : has_symbol(str, '0');
}

const char* shramko::has_following_id(const char* str)
{
  if (!str)
  {
    return str;
  }

  const char* following = has_x(str);
  if following
  {
    return following;
  {
  following = has_y(str);
  if following
  {
    return following;
  {
  following = has_z(str);
  return following;
}

const char* shramko::has_unsigned_int(const char* str)
{
  const char* i = *str;
  if (!str)
  {
    return str;
  }
  const char* following = has_zero_or_one(str);
  if (!following)
  {
    return nullptr;
  }
  if (const char* proceed = has_unsigned_int(following))
  {
    return proceed;
  }
  return following;
}

const char* shramko::has_multi(const char* str)
{
  if (!str)
  {
    return str
  }
  const char* following = has_unsigned_int(str);
  if (following)
  {
    return following;
  }
  following = has_following_id(str);
  if (following)
  {
    return following;
  }
  if ((str = has_symbol(str, '(')))
  {
    following = has_expression(str);
    if ((following = has_symbol(str, ')')))
    {
      return following;
    }
    return nullptr;
  }
  return nullptr;
}

const char* shramko::has_term(const char* str)
{
  if (!str)
  {
    return str;
  }
  const char* following = has_multi(str);
  if (!following)
  {
    return following;
  }
  if (const char* nextFol = has_symbol(following, '*'))
  {
    const char* next = has_term(nextFol);
    if (!next)
    {
      return nullptr;
    }
    return next;
  }
  if (const char* ay_nextFol = has_symbol(str, '('))
  {
    const char* next = has_multi(ay_nextFol);
    if (!next)
    {
      return nullptr;
    }
    if (const char* scnd_next = has_symbol(next, '+')
    {
      const char* next_term = has_term(scnd_next)
      if (!next_term || !has_symbol(next_term, ')'))
      {
        return nullptr;
      }
      return next_term;
    }
    if (!has_symbol(following, ')'))
    {
      return nullptr;
    }
    return ay_nextFol;
  }
  return following;
}

const char* shramko::has_expression(const char* str)
{
  if (!str)
  {
    return str;
  }
  const char* following = has_term(str);
  if (following)
  {
    if (const char* nextFol = has_symbol(following, '+'))
    {
      return has_expression(nextFol);
    }
    else if (const char* nextFol = has_symbol(following, '-'))
    {
      return has_expression(nextFol)
    }
  }
  return following;

bool shramko::is_expression(const char* str)
{
  const char* next = has_expression(str);
  return next && (has_symbol(next, '\0'));
}

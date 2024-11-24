#include "check_real.hpp"
#include <cctype>

const char * karnauhova::is_sign(const char * str)
{
  if (!str)
  {
    return str;
  }
  return (*str == '+' || *str == '-') ? (str + 1) : nullptr;
}

const char * karnauhova::is_number(const char * str)
{
  if (!str)
  {
    return str;
  }
  return ('0' <= *str && *str <= '9') ? (str + 1) : nullptr;
}

const char * karnauhova::is_unsigned_int(const char * str)
{
  if (!str)
  {
    return str;
  }
  const char * next = karnauhova::is_number(str);
  if (const char * continues = is_unsigned_int(next))
  {
    return continues;
  }
  return next;
}

const char * karnauhova::is_manner(const char * str)
{
  if (!str)
  {
    return str;
  }
  if (*str == 'E')
  {
    const char * next = karnauhova::is_sign((str + 1));
    if (!next)
    {
      return nullptr;
    }
    next = karnauhova::is_unsigned_int(next);
    return next;
  }
  return nullptr;
}
const char * karnauhova::is_mantis(const char * str)
{
  if (!str)
  {
    return str;
  }
  if (*str == '.')
  {
    const char * next = karnauhova::is_unsigned_int((str + 1));
    return next;
  }
  else
  {
    const char * next = karnauhova::is_unsigned_int(str);
    if (next && *next == '.')
    {
      next = karnauhova::is_unsigned_int(next + 1);
      return next ? next : nullptr;
    }
    return next;
  }
  return nullptr;
}

const char * karnauhova::has_real(const char * str)
{
  if (!str)
  {
    return str;
  }
  if (const char * next = karnauhova::is_sign(str))
  {
    next = karnauhova::is_mantis(next);
    if (!next)
    {
      return nullptr;
    }
    next = karnauhova::is_manner(next);
    return next;
  }
    const char * next = karnauhova::is_mantis(str);
    if (!next)
    {
      return nullptr;
    }
    next = karnauhova::is_manner(next);
    return next;
}

bool karnauhova::is_real(const char * str)
{
  const char * next = has_real(str);
  return next && (*next == '\0');
}

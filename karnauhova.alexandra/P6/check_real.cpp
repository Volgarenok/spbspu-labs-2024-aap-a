#include "check_real.hpp"
#include <cctype>

const char * karnauhova::is_sign(const char * str)
{
  if (!str)
  {
    return nullptr;
  }
  return (*str == '+' || *str == '-') ? (str + 1) : nullptr;
}

const char * karnauhova::is_number(const char * str)
{
  if (!str)
  {
    return nullptr;
  }
  return (std::isdigit(*str)) ? (str + 1) : nullptr;
}

const char * karnauhova::is_unsigned_int(const char * str)
{
  if (!str)
  {
    return str;
  }
  auto next = karnauhova::is_number(str);
  if (!next)
  {
    return next;
  }
  if (auto continues = is_unsigned_int(next))
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
    auto next = karnauhova::is_sign((str + 1));
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
    auto next = karnauhova::is_unsigned_int((str + 1));
    return next;
  }
  else
  {
    auto next = karnauhova::is_unsigned_int(str);
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
  if (auto next = karnauhova::is_sign(str))
  {
    next = karnauhova::is_mantis(next);
    if (!next)
    {
      return next;
    }
    next = karnauhova::is_manner(next);
    return next;
  }
    auto next = karnauhova::is_mantis(str);
    if (!next)
    {
      return next;
    }
    next = karnauhova::is_manner(next);
    return next;
}

bool karnauhova::is_real(const char * str)
{
  auto next = has_real(str);
  return next && (*next == '\0');
}

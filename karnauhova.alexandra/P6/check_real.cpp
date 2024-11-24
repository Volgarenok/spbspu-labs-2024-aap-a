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
  return (std::isdigit(*str)) ? (str + 1) : nullptr;
}

const char * karnauhova::is_unsigned_int(const char * str)
{
  if (!str)
  {
    return str;
  }
  auto next = karnauhova::is_number(str);
  if (auto continues = karnauhova::is_unsigned_int(str))
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
    if (*next == '.')
    {
      next = karnauhova::is_unsigned_int(str);
      return next;
    }
    return next;
  }
  return nullptr;
}

bool karnauhova::is_real(const char * str)
{
  if (!str)
  {
    return str;
  }
  if (auto next = karnauhova::is_sign(str))
  {
    next = karnauhova::is_mantis(next);
    next = karnauhova::is_manner(next);
    return next && (*next == '\0');
  }
    auto next = karnauhova::is_mantis(str);
    next = karnauhova::is_manner(next);
    return next && (*next == '\0');
}

#include "check_real.hpp"
#include <cctype>

const char * is_sign(const char * str)
{
  if (!str)
  {
    return str;
  }
  return (*str == '+' || *str == '-') ? (str + 1) : nullptr;
}

const char * is_number(const char * str)
{
  if (!str)
  {
    return str;
  }
  return (std::isdigit(*str)) ? (str + 1) : nullptr;
}

const char * is_unsigned_int(const char * str)
{
  if (!str)
  {
    return str;
  }
  auto next = is_number(str);
  if (auto continues = is_unsigned_int(str))
  {
    return continues;
  }
  return next;
}

const char * is_manner(const char * str)
{
  if (!str)
  {
    return str;
  }
  if (str* == 'E')
  {
    auto next = is_sign((str + 1));
    next = is_unsigned_int(next);
    return next;
  }
  return nullptr;
}
const char * is_mantis(const char * str)
{
  if (!str)
  {
    return str;
  }
  if (str* == ".")
  {
    auto next = is_unsigned_int((str + 1));
    return next;
  }
  else
  {
    auto next = is_unsigned_int(str);
    if (next* == ".")
    {
      next = is_unsigned_int(str);
      return next;
    }
    return next;
  }
  return nullptr;
}

bool char * is_real(const char * str)
{
  if (!str)
  {
    return str;
  }
  if (auto next = is_number(str))
  {
    next = is_mantis(next);
    next = is_manner(next);
    return next && (*next == '\0');
  }
    next = is_mantis(next);
    next = is_manner(next);
    return next && (*next == '\0');
}

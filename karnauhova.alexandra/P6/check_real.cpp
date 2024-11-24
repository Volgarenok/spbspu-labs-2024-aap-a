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

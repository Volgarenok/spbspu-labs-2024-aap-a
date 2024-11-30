#include "check_real.hpp"
#include <cctype>

namespace karnauhova
{
  const char * has_symbol(const char * str, char symbol);
  const char * has_real(const char * str);
  const char * has_sign(const char * str);
  const char * has_unsigned_int(const char * str);
  const char * has_number(const char * str);
  const char * has_manner(const char * str);
  const char * has_mantis(const char * str);
}

const char* karnauhova::has_symbol(const char* str, char symbol)
{
  if (!str)
  {
    return str;
  }
  return (*str == symbol) ? (str + 1) : nullptr;
}

const char * karnauhova::has_sign(const char * str)
{
  if (!str)
  {
    return str;
  }
  return (has_symbol(str, '+') || has_symbol(str, '-')) ? (str + 1) : nullptr;
}

const char * karnauhova::has_number(const char * str)
{
  if (!str)
  {
    return str;
  }
  return (std::isdigit(*str)) ? (str + 1) : nullptr;
}

const char * karnauhova::has_unsigned_int(const char * str)
{
  if (!str)
  {
    return str;
  }
  const char * next = has_number(str);
  if (const char * continues = has_unsigned_int(next))
  {
    return continues;
  }
  return next;
}

const char * karnauhova::has_manner(const char * str)
{
  if (!str)
  {
    return str;
  }
  const char * next = has_symbol(str, 'E');
  next = has_sign(next);
  next = has_unsigned_int(next);
  return next;
}

const char * karnauhova::has_mantis(const char * str)
{
  if (!str)
  {
    return str;
  }
  if (const char * next = has_symbol(str, '.'))
  {
    next = has_unsigned_int(next);
    return next;
  }
  const char * next = has_unsigned_int(str);
  if (const char * cont = has_symbol(next, '.'))
  {
    cont = has_unsigned_int(cont);
    return cont;
  }
  return next;
}

const char * karnauhova::has_real(const char * str)
{
  if (!str)
  {
    return str;
  }
  if (const char * next = has_sign(str))
  {
    next = has_mantis(next);
    next = has_manner(next);
    return next;
  }
  const char * next = has_mantis(str);
  next = has_manner(next);
  return next;
}

bool karnauhova::is_real(const char * str)
{
  if (!str)
  {
    return false;
  }
  const char * next = has_real(str);
  return next && (*next == '\0');
}

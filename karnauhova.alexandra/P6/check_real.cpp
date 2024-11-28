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
  const char * next = karnauhova::has_number(str);
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
  const char * next = karnauhova::has_symbol(str, 'E');
  next = karnauhova::has_sign(next);
  next = karnauhova::has_unsigned_int(next);
  return next;
}

const char * karnauhova::has_mantis(const char * str)
{
  if (!str)
  {
    return str;
  }
  if (const char * next = karnauhova::has_symbol(str, '.'))
  {
    next = karnauhova::has_unsigned_int(next);
    return next;
  }
  const char * next = karnauhova::has_unsigned_int(str);
  if (const char * cont = karnauhova::has_symbol(next, '.'))
  {
    cont = karnauhova::has_unsigned_int(cont);
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
  if (const char * next = karnauhova::has_sign(str))
  {
    next = karnauhova::has_mantis(next);
    next = karnauhova::has_manner(next);
    return next;
  }
  const char * next = karnauhova::has_mantis(str);
  next = karnauhova::has_manner(next);
  return next;
}

bool karnauhova::is_real(const char * str)
{
  if (!str)
  {
    return false;
  }
  const char * next = karnauhova::has_real(str);
  return next && (*next == '\0');
}

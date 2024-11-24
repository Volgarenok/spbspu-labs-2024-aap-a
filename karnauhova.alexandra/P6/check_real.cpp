#include "check_real.hpp"
#include <cctype>

const char* karnauhova::is_symbol(const char* str, char symbol)
{
  if (!str)
  {
    return str;
  }
  return (*str == symbol) ? (str + 1) : nullptr;
}

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
  return (isdigit(str*)) ? (str + 1) : nullptr;
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
  const char * next = karnauhova::is_symbol(str, 'E');
  next = karnauhova::is_sign(next);
  next = karnauhova::is_unsigned_int(next);
  return next;
}

const char * karnauhova::is_mantis(const char * str)
{
  if (!str)
  {
    return str;
  }
  if (const char * next = karnauhova::is_symbol(str, '.'))
  {
    next = karnauhova::is_unsigned_int(next);
    return next;
  }
  const char * next = karnauhova::is_unsigned_int(str);
  if (const char * cont = karnauhova::is_symbol(next, '.'))
  {
    cont = karnauhova::is_unsigned_int(cont);
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
  if (const char * next = karnauhova::is_sign(str))
  {
    next = karnauhova::is_mantis(next);
    next = karnauhova::is_manner(next);
    return next;
  }
    const char * next = karnauhova::is_mantis(str);
    next = karnauhova::is_manner(next);
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

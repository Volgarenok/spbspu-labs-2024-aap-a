#include "real_number_set.h"
#include <cctype>

const char * timofeev::is_symbol(const char * str, char a)
{
  if (!str)
  {
    return str;
  }
  return (*str == a) ? (str + 1) : nullptr;
}

const char * timofeev::has_sign(const char * str)
{
  if (!str)
  {
    return str;
  }
  return (timofeev::is_symbol(str, '+') || timofeev::is_symbol(str, '-')) ? (str + 1) : nullptr;
}

const char * timofeev::has_digit(const char * str)
{
  if (!str)
  {
    return str;
  }
  return (std::isdigit(*str)) ? (str + 1) : nullptr;
}

const char * timofeev::has_unsigned_int(const char * str)
{
  if (!str)
  {
    return str;
  }
  auto next = timofeev::has_digit(str);
  if (auto continues = timofeev::has_unsigned_int(next))
  {
    return continues;
  }
  return next;
}


const char * timofeev::has_e(const char * str)
{
  if (!str)
  {
    return str;
  }
  return (timofeev::is_symbol(str, 'E') || timofeev::is_symbol(str, 'e')) ? (str + 1) : nullptr;
}

const char * timofeev::has_order(const char * str)
{
  if (!str)
  {
    return str;
  }
  auto next = has_e(str);
  if (auto continues = timofeev::has_sign(next))
  {
    next = continues;
  }
  return timofeev::has_unsigned_int(next);
}

const char * timofeev::has_mantissa(const char * str)
{
  if (!str)
  {
    return str;
  }
  auto next = str;
  if (auto continues = timofeev::has_unsigned_int(next))
  {
    next = continues;
  }
  next = timofeev::is_symbol(next, '.');
  return timofeev::has_unsigned_int(next);
}

bool timofeev::is_real_number(const char * str)
{
  if (!str)
  {
    return str;
  }
  auto next = timofeev::has_mantissa(str);
  return timofeev::has_order(next);
}


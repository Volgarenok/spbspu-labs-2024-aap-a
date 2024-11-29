#include "real_number_set"

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
  return (is_symbol(str, "+") || is_symbol(str, "-") ? (str + 1) : nullptr;
}

const char * timofeev::has_digit(const char * str)
{
  if (!str)
  {
    return str;
  }
  return (*str >= 0 && *str < 10) ? (str + 1) : nullptr;
}

const char * timofeev::has_unsigned_int(const char * str)
{
  if (!str)
  {
    return str;
  }
  auto next = is_digit(str);
  if(auto continues = is_digit(next))
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
  return (is_symbol(str, "E") || is_symbol(str, "e") ? (str + 1) : nullptr;
}

const char * timofeev::has_order(const char * str)
{
  if (!str)
  {
    return str;
  }
  auto next = has_e(str);
  if (auto continues = has_sign(next))
  {
    next = continues;
  }
  return has_usigned_int(next);
}

const char * timofeev::has_mantissa(const char * str)
{
  if (!str)
  {
    return str;
  }
  char * next = str;
  if (auto continues = has_unsigned_int(next);
  {
    auto next = continues;
  }
  next = is_symbol(next, ".");
  return has_unsigned_int(next);
}

bool timofeev::is_real_number(const char * str)
{
  if (!str)
  {
    return str;
  }
  auto next = has_mantissa(str);
  return has_order(next);
}


#include <iostream> 
#include <ios> 

const char *is_sign(const char *str)
{
  return ((str != nullptr) && ((*str == '+') || (*str == '-'))) ? (str + 1) : nullptr;
}

const char *is_digit(const char *str)
{
  return ((str != nullptr) && (*str >= '0') && (*str <= '9')) ? (str + 1) : nullptr;
}

const char *is_unsigned_int(const char *str)
{
  if (!str)
  {
    return nullptr;
  }
  auto next = is_digit(str);
  if (next == nullptr)
  {
    return nullptr;
  }
  auto next2 = is_unsigned_int(next);
  return (next2 == nullptr) ? next : next2;
}

const char *is_symbol(const char *str, char ch)
{
  return ((str != nullptr) && (*str == ch)) ? (str + 1) : nullptr;
}

const char *is_E(const char *str)
{
  if (!str)
  {
    return nullptr;
  }
  auto next = is_symbol(str, 'E');
  if (!next)
  {
    return nullptr;
  }
  if (next2 != nullptr)
  {
    next = next2;
  }
  next = is_unsigned_int(next);
  return next;
}

const char *is_mantissa(const char *str)
{
  if (!str)
  {
    return nullptr;
  }
  auto next = is_symbol(str, '.');
  if (next == nullptr)
  {
    next = is_unsigned_int(str);
    next = is_symbol(next, '.');
  }
  return is_unsigned_int(next);
}
bool func(const char * str)
{
  return false;
}
int main()
{
  
}

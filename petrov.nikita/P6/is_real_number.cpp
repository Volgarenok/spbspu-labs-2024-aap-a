#include "is_real_number.hpp"
#include <cstddef>

char * petrov::hasSign(char * str)
{
  if (!str)
  {
    return str;
  }
  if ((*str == '+' || *str == '-') && str != nullptr)
  {
    str++;
  }
  return str;
}

char * petrov::hasSymbol(char * str, const char symbol)
{
  return (*str == symbol) ? ++str : nullptr;
}

char * petrov::hasDigit(char * str)
{
  char numbers[11] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '\0'};
  size_t i = 0;
  while (numbers[i] != '\0')
  {
    if (*str == numbers[i])
    {
      return ++str;
    }
    i++;
  }
  return nullptr;
}

char * petrov::hasUnsignedInt(char * str)
{
  if (!str)
  {
    return str;
  }
  auto next = petrov::hasDigit(str);
  if (auto continues = petrov::hasUnsignedInt(next))
  {
    return continues;
  }
  return next;
}

char * petrov::hasSignificand(char * str)
{
  if (!str)
  {
    return str;
  }
  auto next = petrov::hasSign(str);
  next = petrov::hasSymbol(next, '.');
  next = petrov::hasUnsignedInt(next);
  return next;
}

char * petrov::hasOrderOfMagnitude(char * str)
{
  if (!str)
  {
    return str;
  }
  auto next = petrov::hasSymbol(str, 'E');
  next = petrov::hasSign(next);
  next = petrov::hasUnsignedInt(next);
  return next;
}

char * petrov::hasRealNumber(char * str)
{
  auto next = petrov::hasSignificand(str);
  next = petrov::hasOrderOfMagnitude(next);
  return next;
}

bool petrov::isRealNumber(char * str)
{
  auto next = hasRealNumber(str);
  return next && (*next == '\0');
}

#include "is_real_number.hpp"
#include <cctype>

namespace
{
  const char * hasSign(const char * str);
  const char * hasSymbol(const char * str, char symbol);
  const char * hasDigit(const char * str);
  const char * hasUnsignedInt(const char * str);
  const char * hasSignificand(const char * str);
  const char * hasOrderOfMagnitude(const char * str);

  const char * hasSign(const char * str)
  {
    if (!str)
    {
      return str;
    }
    if (*str == '+' || *str == '-')
    {
      str++;
    }
    return str;
  }

  const char * hasSymbol(const char * str, char symbol)
  {
    return (*str == symbol) ? ++str : nullptr;
  }

  const char * hasDigit(const char * str)
  {
    if (std::isdigit(*str))
    {
      return ++str;
    }
    return nullptr;
  }

  const char * hasUnsignedInt(const char * str)
  {
    if (!str)
    {
      return str;
    }
    auto next = hasDigit(str);
    if (auto continues = hasUnsignedInt(next))
    {
      return continues;
    }
    return next;
  }

  const char * hasSignificand(const char * str)
  {
    if (!str)
    {
      return str;
    }
    auto next = hasSign(str);
    next = hasSymbol(next, '.');
    next = hasUnsignedInt(next);
    return next;
  }

  const char * hasOrderOfMagnitude(const char * str)
  {
    if (!str)
    {
      return str;
    }
    auto next = hasSymbol(str, 'E');
    next = hasSign(next);
    next = hasUnsignedInt(next);
    return next;
  }
}

const char * petrov::hasRealNumber(const char * str)
{
  auto next = hasSignificand(str);
  next = hasOrderOfMagnitude(next);
  return next;
}

bool petrov::isRealNumber(const char * str)
{
  auto next = hasRealNumber(str);
  return next && (*next == '\0');
}

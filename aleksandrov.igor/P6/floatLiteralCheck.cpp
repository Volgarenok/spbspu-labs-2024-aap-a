#include "floatLiteralCheck.h"
#include <cctype>

namespace aleksandrov
{
  const char* isSymbol(const char* str, char c);
  const char* isSign(const char* str);
  const char* isDigit(const char* str);
  const char* isUnsignedInt(const char* str);
  const char* isNumberOrder(const char* str);
  const char* isMantissa(const char* str);
}

const char* aleksandrov::isSymbol(const char* str, char c)
{
  return (*str == c) ? (str + 1) : nullptr;
}

const char* aleksandrov::isSign(const char* str)
{
  auto next = isSymbol(str, '+');
  return next ? next : isSymbol(str, '-');
}

const char* aleksandrov::isDigit(const char* str)
{
  return (std::isdigit(*str) != 0) ? (str + 1) : nullptr;
}

const char* aleksandrov::isUnsignedInt(const char* str)
{
  auto next = isDigit(str);
  if (!next)
  {
    return next;
  }
  auto continues = isUnsignedInt(next);
  return continues ? continues : next;
}

const char* aleksandrov::isNumberOrder(const char* str)
{
  auto next = isSymbol(str, 'E');
  if (!next)
  {
    return next;
  }
  auto continues = isSign(next);
  return isUnsignedInt(continues ? continues : next);
}

const char* aleksandrov::isMantissa(const char* str)
{
  auto next = isSymbol(str, '.');
  if (!next)
  {
    next = isUnsignedInt(str);
    if (!next)
    {
      return next;
    }
    auto continues = isSymbol(next, '.');
    return continues ? isUnsignedInt(continues) : next;
  }
  auto continues = isUnsignedInt(next);
  return continues ? continues : nullptr;
}

bool aleksandrov::isFloatLiteral(const char* str)
{
  if (!str)
  {
    return false;
  }
  auto next = isSign(str);
  if (!next)
  {
    next = isMantissa(str);
    if (!next)
    {
      return false;
    }
    next = isNumberOrder(next);
    if (!next)
    {
      return false;
    }
    return true;
  }
  next = isMantissa(next);
  if (!next)
  {
    return false;
  }
  next = isNumberOrder(next);
  if (!next)
  {
    return false;
  }
  return true;
}


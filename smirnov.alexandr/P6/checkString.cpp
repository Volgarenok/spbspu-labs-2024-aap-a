#include "checkString.hpp"
#include <cctype>

namespace smirnov
{
  const char * isSymbol(const char * string, char c);
  const char * isSign(const char * string);
  const char * isNumber(const char * string);
  const char * isUnsignedInt(const char * string);
  const char * isOrder(const char * string);
  const char * isMantissa(const char * string);
}

const char * smirnov::isSymbol(const char * string, char c)
{
  if (!string)
  {
    return string;
  }
  return (*string == c) ? (string + 1) : nullptr;
}

const char * smirnov::isSign(const char * string)
{
  if (!string)
  {
    return string;
  }
  return (isSymbol(string, '+') || isSymbol(string, '-')) ? (string + 1) : nullptr;
}

const char * smirnov::isNumber(const char * string)
{
  if (!string)
  {
    return string;
  }
  return (std::isdigit(*string)) ? (string + 1) : nullptr;
}

const char * smirnov::isUnsignedInt(const char * string)
{
  if (!string)
  {
    return string;
  }
  auto next = isNumber(string);
  if (auto continues = isUnsignedInt(next))
  {
    return continues;
  }
  return next;
}

const char * smirnov::isOrder(const char * string)
{
  if (!string)
  {
    return string;
  }
  auto next = isSymbol(string, 'E');
  if (auto continues = isSign(next))
  {
    return isUnsignedInt(continues);
  }
  return isUnsignedInt(next);
}

const char * smirnov::isMantissa(const char * string)
{
  if (!string)
  {
    return string;
  }
  auto next = string;
  if (auto continues = isUnsignedInt(next))
  {
    next = continues;
  }
  next = isSymbol(next, '.');
  return isUnsignedInt(next);
}

bool smirnov::isFloatNumber(const char * string)
{
  if (!string)
  {
    return string;
  }
  auto next = isSign(string);
  if (auto continues = isMantissa(next))
  {
    return isOrder(continues);
  }
  return isOrder(next);
}

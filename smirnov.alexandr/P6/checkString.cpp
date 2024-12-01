#include "checkString.hpp"

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
  return (*string >= '0' && *string <= '9') ? (string + 1) : nullptr;
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
  if (*string == '.')
  {
    return isUnsignedInt(string + 1);
  }
  auto next = isUnsignedInt(string);
  if (next && *next == '.')
  {
    return isUnsignedInt(next + 1);
  }
  return string;
}

bool smirnov::isFloatNumber(const char * string)
{
  if (!string)
  {
    return string;
  }
  const char * next = isSign(string);
  next = isMantissa(next);
  if (next && *next == 'E')
  {
    next = isOrder(next + 1);
  }
  return next && (*next == '\0');
}

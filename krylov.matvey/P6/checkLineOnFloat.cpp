#include "checkLineOnFloat.hpp"
#include <cctype>

namespace
{
  const char* hasSymbol(const char* str, char symbol);
  const char* hasSign(const char* str);
  const char* hasDigit(const char* str);
  const char* hasUnsignedInt(const char* str);
  const char* hasOrderOfMagnitude(const char* str);
  const char* hasMantissa(const char* str);

  const char* hasSymbol(const char* line, char symbol)
  {
    if (!line)
    {
      return line;
    }
    return (*line == symbol) ? (line + 1) : nullptr;
  }

  const char* hasSign(const char* line)
  {
    if (!line)
    {
      return line;
    }
    auto next = hasSymbol(line, '+');
    return next ? next : hasSymbol(line, '-');
  }

  const char* hasDigit(const char* line)
  {
    if (!line)
    {
      return line;
    }
    return std::isdigit(*line) ? (line + 1) : nullptr;
  }

  const char* hasUnsignedInt(const char* line)
  {
    if (!line)
    {
      return line;
    }
    auto next = hasDigit(line);
    if (auto continues = hasUnsignedInt(next))
    {
      return continues;
    }
    return next;
  }

  const char* hasOrderOfMagnitude(const char* line)
  {
    if (!line)
    {
      return line;
    }
    auto next = hasSymbol(line, 'E');
    if (auto signCheck = hasSign(next))
    {
      return hasUnsignedInt(signCheck);
    }
    return hasUnsignedInt(next);
  }

  const char* hasMantissa(const char* line)
  {
    if (!line)
    {
      return line;
    }
    auto next = hasUnsignedInt(line);
    next = hasSymbol(next, '.');
    return hasUnsignedInt(next);
  }
}

bool krylov::isFloatNumber(const char* line)
{
  if (!line)
  {
    return line;
  }
  if (auto sign = hasSign(line))
  {
    auto next = hasMantissa(sign);
    return hasOrderOfMagnitude(next);
  }
  auto next = hasMantissa(line);
  next = hasOrderOfMagnitude(next);
  return next && (*next == '\0');
}

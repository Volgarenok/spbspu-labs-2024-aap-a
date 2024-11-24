#include "checkLineOnFloat.hpp"
#include <cctype>

const char* krylov::hasSymbol(const char* line, char symbol)
{
  if (!line)
  {
    return line;
  }
  return (*line == symbol) ? (line + 1) : nullptr;
}

const char* krylov::hasSign(const char* line)
{
  if (!line)
  {
    return line;
  }
  auto next = hasSymbol(line, '+');
  return next ? next : hasSymbol(line, '-');
}

const char* krylov::hasDigit(const char* line)
{
  if (!line)
  {
    return line;
  }
  return std::isdigit(*line) ? (line + 1) : nullptr;
}

const char* krylov::hasUnsignedInt(const char* line)
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

const char* krylov::hasOrderOfMagnitude(const char* line)
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

const char* krylov::hasMantissa(const char* line)
{
  if (!line)
  {
    return line;
  }
  auto next = hasUnsignedInt(line);
  next = hasSymbol(next, '.');
  return hasUnsignedInt(next);
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

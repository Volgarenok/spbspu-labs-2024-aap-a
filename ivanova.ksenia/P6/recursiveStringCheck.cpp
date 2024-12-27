#include "recursiveStringCheck.h"
#include <cctype>
#include <cstring>

namespace
{
  const char * signCheck(const char * str);
  const char * digitCheck(const char * str);
  const char * symbolCheck(const char * str, char c);
  const char * unsignedIntCheck(const char * str);
  const char * orderCheck(const char * str);
  const char * mantisCheck(const char * str);

  const char * signCheck(const char * string)
  {
    if (!string)
    {
      return string;
    }

    return ((*string == '+') || (*string == '-')) ? (string + 1) : nullptr;
  }

  const char * digitCheck(const char * string)
  {
    if (!string)
    {
      return string;
    }

    return ((*string >= '0') && (*string <= '9')) ? (string + 1) : nullptr;
  }

  const char * symbolCheck(const char * string, char c)
  {
    if (!string)
    {
      return string;
    }

    return ((*string == c)) ? (string + 1) : nullptr;
  }

  const char * unsignedIntCheck(const char * string)
  {
    if (!string)
    {
      return string;
    }

    auto next = digitCheck(string);
    auto continuous = unsignedIntCheck(next);
    if (!continuous)
    {
      return next;
    }
    return continuous;
  }

  const char * orderCheck(const char * string)
  {
    if (!string)
    {
      return string;
    }

    auto next = symbolCheck(string, 'E');
    if (!next)
    {
      return next;
    }
    auto continuous = signCheck(next);
    if (continuous != nullptr)
    {
      next = continuous;
    }
    return unsignedIntCheck(next);
  }

  const char * mantisCheck(const char * string)
  {
    if (!string)
    {
      return string;
    }

    auto next = symbolCheck(string, '.');
    if (!next)
    {
      return unsignedIntCheck(string);
    }
    return unsignedIntCheck(next);
  }
}

bool ivanova::rightString(const char * string)
{
  if (!string)
  {
    return false;
  }

  auto next = signCheck(string);
  if (!next)
  {
    next = string;
  }
  next = mantisCheck(next);
  if (orderCheck(next))
  {
    return true;
  }
  return false;
}

#include "suitable_string.h"
#include <cctype>

namespace hismatova
{
  const char* isTerm(const char* str, size_t& position);
  const char* isMultiplier(const char* str, size_t& position);
  const char* isDeterm(const char* str, size_t& position);
  const char* isUnsignedInt(const char* str, size_t& position);
  const char* isIdentificator(const char* str, size_t& position);
  bool isLetter(char c);
}

bool hismatova::isValidString(const char* str, size_t& position)
{
  if (isTerm(str, position))
  {
    if (str[position] == '\0')
    {
      return true;
    }
    if (str[position] == '+')
    {
      position++;
      return isValidString(str, position);
    }
    return false;
  }
  return false;
}

const char* hismatova::isTerm(const char* str, size_t& position)
{
  if (isMultiplier(str, position))
  {
    if (str[position] == '*')
    {
      position++;
      return isTerm(str, position);
    }
    return str;
  }
  return nullptr;
}

const char* hismatova::isMultiplier(const char* str, size_t& position)
{
  if (isDeterm(str, position))
  {
    if (str[position] == '-')
    {
      position++;
      return isMultiplier(str, position);
    }
    return str;
  }
  return nullptr;
}

const char* hismatova::isDeterm(const char* str, size_t& position)
{
  const char* result = isUnsignedInt(str, position);
  if (result == nullptr)
  {
    result = isIdentificator(str, position);
  }
  return result;
}

const char* hismatova::isUnsignedInt(const char* str, size_t& position)
{
  if (std::isdigit(str[position]) || isLetter(str[position]))
  {
    position++;
    return isUnsignedInt(str, position);
  }
  return position > 0 ? str : nullptr;
}

const char* hismatova::isIdentificator(const char* str, size_t& position)
{
  if (isLetter(str[position]) || std::isdigit(str[position]))
  {
    position++;
    return isIdentificator(str, position);
  }
  return position > 0 ? str : nullptr;
}

bool hismatova::isLetter(char c)
{
  return c >= 'a' && c <= 'e';
}


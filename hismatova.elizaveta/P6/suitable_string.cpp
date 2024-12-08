#include "suitable_string.h"
#include <cctype>

namespace hismatova
{
  const char* isTerm(const char* str, size_t& position);
  const char* isTermSecond(const char* str, size_t& position);
  const char* isMultiplier(const char* str, size_t& position);
  const char* isMultiplierSecond(const char* str, size_t& position);
  const char* isDeterm(const char* str, size_t& position);
  const char* isUnsignedInt(const char* str, size_t& position);
  const char* isUnsignedIntSecond(const char* str, size_t& position);
  const char* isIdentificator(const char* str, size_t& position);
  bool isLetter(char c);
}

bool hismatova::isValidString(const char* str, size_t& position)
{
  if (isTerm(str, position))
  {
    return isValidStringSecond(str, position);
  }
  return false;
}
bool hismatova::isValidStringSecond(const char* str, size_t& position)
{
  if (str[position] == '+')
  {
    position++;
    if (!isTerm(str, position))
    {
      return false;
    }
    return isValidStringSecond(str, position);
  }
  return true;
}
const char* hismatova::isTerm(const char* str, size_t& position)
{
  if (isMultiplier(str, position))
  {
    return isTermSecond(str, position);
  }
  return nullptr;
}
const char* hismatova::isTermSecond(const char* str, size_t& position)
{
  if (str[position] == '*')
  {
    position++;
    if (!isMultiplier(str, position))
    {
      return nullptr;
    }
    return isTermSecond(str, position);
  }
  return str;
}
const char* hismatova::isMultiplier(const char* str, size_t& position)
{
  if (isDeterm(str, position))
  {
    return isMultiplierSecond(str, position);
  }
  return nullptr;
}
const char* hismatova::isMultiplierSecond(const char* str, size_t& position)
{
  if (str[position] == '-')
  {
    position++;
    if (!isDeterm(str, position))
    {
      return nullptr;
    }
    return isMultiplierSecond(str, position);
  }
  return str;
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
  if (std::isdigit(str[position]))
  {
    position++;
    return isUnsignedIntSecond(str, position);
  }
  return nullptr;
}
const char* hismatova::isUnsignedIntSecond(const char* str, size_t& position)
{
  if (str[position] && std::isdigit(str[position]))
  {
    position++;
    return isUnsignedIntSecond(str, position);
  }
  return str;
}
const char* hismatova::isIdentificator(const char* str, size_t& position)
{
  if (isLetter(str[position]))
  {
    position++;
    return str;
  }
  return nullptr;
}
bool hismatova::isLetter(char c)
{
  return c >= 'a' && c <= 'e';
}

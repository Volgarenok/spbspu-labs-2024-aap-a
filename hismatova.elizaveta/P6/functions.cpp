#include "functions.h"

bool hismatova::isValidString(const char* str, size_t& position)
{
  if (isTerm(str, position))
  {
    while (str[position] == '+')
    {
      position++;
      if (!isTerm(str, position))
      {
        return false;
      }
    }
    return true;
  }
  return false;
}
const char* hismatova::isTerm(const char* str, size_t& position)
{
  if (isMultiplier(str, position))
  {
    while (str[position] == '*')
    {
      position++;
      if (!isMultiplier(str, position))
      {
        return nullptr;
      }
    }
    return str;
  }
  return nullptr;
}
const char* hismatova::isMultiplier(const char* str, size_t& position)
{
  const char* result = isUnsignedInt(str, position);
  if (result == nullptr)
  {
    result = isIdentificator(str);
  }
  return result;
}
const char* hismatova::isUnsignedInt(const char* str, size_t& position)
{
  if (isDigit(str[position]))
  {
    while (isDigit(str[position]))
    {
      position++;
    }
    return str;
  }
  return nullptr;
}
const char* hismatova::isIdentificator(const char* str)
{
  if (isLetter(str[0]))
  {
    return str;
  }
  return nullptr;
}
bool hismatova::isDigit(char c)
{
  return c >= '0' && c <= '9';
}
bool hismatova::isLetter(char c)
{
  return c >= 'a' && c <= 'e';
}

#include "recursiveChecks.h"
#include <cctype>
#include <cstring>

bool duhanina::isSign(char c)
{
  return c == '+' || c == '-';
}

bool duhanina::isUnsignedInt(const char* str, size_t& index)
{
  if (!std::isdigit(str[index]))
  {
    return false;
  }
  index++;
  if (std::isdigit(str[index]))
  {
    return duhanina::isUnsignedInt(str, index);
  }
  return true;
}

bool duhanina::isMantissa(const char* str, size_t& index)
{
  if (str[index] == '.')
  {
    index++;
    return duhanina::isUnsignedInt(str, index);
  }
  return duhanina::isUnsignedInt(str, index);
}

bool duhanina::isOrder(const char* str, size_t& index)
{
  if (str[index] != 'E')
  {
    return false;
  }
  index++;
  if (duhanina::isSign(str[index]))
  {
    index++;
  }
  return duhanina::isUnsignedInt(str, index);
}

bool duhanina::isReal(const char* str)
{
  size_t index = 0;
  if (duhanina::isSign(str[index]))
  {
    index++;
  }
  if (!duhanina::isMantissa(str, index))
  {
    return false;
  }
  if (str[index] == '\0')
  {
    return true;
  }
  return duhanina::isOrder(str, index) && str[index] == '\0';
}

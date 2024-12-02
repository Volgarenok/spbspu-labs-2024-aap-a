#include "recursiveChecks.h"
#include <cctype>
#include <cstring>

namespace duhanina
{
  bool isSign(char c);
  bool isUnsignedInt(const char* str, size_t& index);
  bool isMantissa(const char* str, size_t& index);
  bool isOrder(const char* str, size_t& index);
}

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
    return isUnsignedInt(str, index);
  }
  return true;
}

bool duhanina::isMantissa(const char* str, size_t& index)
{
  if (str[index] == '.')
  {
    index++;
    return isUnsignedInt(str, index);
  }
  return isUnsignedInt(str, index);
}

bool duhanina::isOrder(const char* str, size_t& index)
{
  if (str[index] != 'E')
  {
    return false;
  }
  index++;
  if (isSign(str[index]))
  {
    index++;
  }
  return isUnsignedInt(str, index);
}

bool duhanina::isReal(const char* str)
{
  size_t index = 0;
  if (isSign(str[index]))
  {
    index++;
  }
  if (!isMantissa(str, index))
  {
    return false;
  }
  if (str[index] == '\0')
  {
    return true;
  }
  return isOrder(str, index) && str[index] == '\0';
}

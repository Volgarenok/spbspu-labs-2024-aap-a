#include <ctype>

bool isSign(char c)
{
  return c == '+' || c == '-';
}

bool isUnsignedInt(const char* str, int& index)
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

bool isMantissa(const char* str, int& index)
{
  if (str[index] == '.')
  {
    index++;
    return isUnsignedInt(str, index);
  }
  return isUnsignedInt(str, index);
}

bool isOrder(const char* str, int& index)
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

bool isReal(const char* str, int index = 0)
{
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

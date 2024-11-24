#include "modifyString.hpp"
#include <cstdlib>

char* shramko::createBiggerStrMemory(size_t memory, const char* str)
{
  char* new_str = reinterpret_cast< char* >(malloc((memory + 1) * sizeof(char)));

  for (size_t i = 0; str[i] != '\0'; ++i)
  {
    new_str[i] = str[i];
  }
  new_str[memory] = '\0';
  return new_str;
}

size_t shramko::countConsecutiveIdenticalSymbols(const char* str)
{
  if (str == nullptr)
  {
    return 0;
  }

  size_t result = 0;
  for (size_t i = 0; str[i] != '\0'; ++i)
  {
    if (str[i] == str[i + 1])
    {
      ++result;
    }
  }
  return result;
}

char* shramko::inputStr(std::istream& in)
{
  size_t memory = 10;
  char* str = reinterpret_cast< char* >(malloc((memory + 1) * sizeof(char)));
  if (str == nullptr)
  {
    return str;
  }

  char c = '\0';
  str[0] = c;
  size_t currentSize = 0;

  std::noskipws(in);
  while ((in >> c) && (c != '\n'))
  {
    str[currentSize++] = c;
    if (currentSize == memory)
    {
      constexpr size_t multiplier = 2;
      memory *= multiplier;
      char* new_str = shramko::createBiggerStrMemory(memory, str);
      free(str);
      if (new_str == nullptr)
      {
        return new_str;
      }
      str = new_str;
    }
  }
  std::skipws(in);
  str[currentSize] = c;
  return str;
}

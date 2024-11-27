#include "check_string.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>

char* hismatova::uniqueChar(const char* str1, const char* str2)
{
  bool arr[128] = {0};
  size_t count = 0;
  for (size_t i = 0; str1[i] != '\0'; ++i)
  {
    int ascii1 = static_cast< int >(str1[i]);
    if (std::islower(str1[i]))
    {
      arr[ascii1] = true;
    }
    if (std::isupper(str1[i]))
    {
      arr[ascii1 + 32] = true;
    }
  }
  for (size_t i = 0; str2[i] != '\0'; ++i)
  {
    int ascii2 = static_cast< int >(str2[i]);
    if (std::islower(str2[i]))
    {
      arr[ascii2] = true;
    }
    if (std::isupper(str2[i]))
    {
      arr[ascii2 + 32] = true;
    }
  }
  for (size_t i = 0; i < 128; ++i)
  {
    if (arr[i])
    {
      count++;
    }
  }
  char* result = reinterpret_cast< char* >(malloc(count + 1));
  if (result == nullptr)
  {
    return nullptr;
  }
  size_t ind = 0;
  for (size_t i = 0; i < 128; ++i)
  {
    if (arr[i])
    {
      result[ind++] = static_cast< char >(i);
    }
  }
  result[ind] = '\0';
  return result;
}
int hismatova::getLine(std::istream& input, char** str)
{
  size_t n = 500;
  *str = reinterpret_cast< char* >(malloc(sizeof(char) * n));
  if (*str == nullptr)
  {
    std::cerr << "out of memory\n";
    return 1;
  }
  size_t length = 0;
  int c = 0;
  while ((c = input.get()) != EOF && c != '\n')
  {
    if (length + 1 >= n)
    {
      std::cerr << "string is too long\n";
      return 1;
    }
    (*str)[length++] = static_cast< char >(c);
  }
  (*str)[length] = '\0';
  return 0;
}

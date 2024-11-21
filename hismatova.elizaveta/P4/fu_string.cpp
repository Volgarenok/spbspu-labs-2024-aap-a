#include "fu_string.h"
#include <iostream>
#include <cstdlib>
#include <cstring>

char* hismatova::uniqueChar(const char* str1, const char* str2)
{
  bool arr[256] = {0};
  size_t count = 0;
  for (size_t i = 0; str1[i] != '\0'; ++i)
  {
    if ((str1[i] >= 'A' && str1[i] <= 'Z') || (str1[i] >= 'a' && str1[i] <= 'z'))
    {
      arr[str1[i] | 32] = true;
    }
  }
  for (size_t i = 0; str2[i] != '\0'; ++i)
  {
    if ((str2[i] >= 'A' && str2[i] <= 'Z') || (str2[i] >= 'a' && str2[i] <= 'z'))
    {
      arr[str2[i] | 32] = true;
    }
  }
  for (size_t i = 0; i < 256; ++i)
  {
    if (arr[i])
    {
      count++;
    }
  }
  char* result = reinterpret_cast<char*>(malloc(count + 1));
  if (result == nullptr)
  {
    return nullptr;
  }
  size_t ind = 0;
  for (size_t i = 0; i < 256; ++i)
  {
    if (arr[i])
    {
      result[ind++] = static_cast<char>(i);
    }
  }
  result[ind] = '\0';
  return result;
}
int hismatova::getLine(char** str)
{
  size_t n = 256;
  *str = reinterpret_cast<char*>(malloc(sizeof(char) * n));
  if (*str == nullptr) {
    std::cerr << "out of memory\n";
    return 1;
  }
  size_t length = 0;
  int c = 0;
  while (true) {
    c = std::cin.get();
    if (c == '\n' || c == EOF)
    {
      break;
    }
    if (length + 1 >= n)
    {
      n *= 2;
      *str = reinterpret_cast<char*>(realloc(*str, n));
      if (*str == nullptr)
      {
        std::cerr << "out of memory\n";
        return 1;
      }
    }
    (*str)[length++] = static_cast<char>(c);
  }
  (*str)[length] = '\0';
  return 0;
}

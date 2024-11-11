#include "arraymoves.h"
#include <memory>
#include <iostream>
#include <cstring>
#include <cctype>

char* averenkov::newArray(char* first, char* second)
{
  for(size_t i = 0; first[i] != '\0'; i++)
  {
    second[i] = first[i];
  }
  free (first);
  return second;
}

char* averenkov::stringInput(std::istream & in, char* str)
{
  size_t max = 10;
  const size_t n = 2;
  size_t size = 0;
  char c = '\0';
  std::noskipws(std::cin);
  while ((std::cin >> c) && (c != '\n'))
  {
    if (size == max)
    {
      char* str_new = reinterpret_cast<char*> (malloc(((size * n) + 1) * sizeof(char)));
      str_new[size * n] = '\0';
      if(str_new == nullptr)
      {
        free(str_new);
        return str;
      }
      str = averenkov::newArray(str, str_new);
      max *= n;
      str[size] = c;
    }
    else
    {
      str[size] = c;
    }
    size++;
  }
  std::skipws(std::cin);
  return str;
}

char* averenkov::latTwo(const char* str1, const char* str2)
{
  int found[26] = {0};
  size_t length = 0;
  for (size_t i = 0; str1[i] != '\0'; i++)
  {
    char ch = std::tolower(str1[i]);
    if (ch >= 'a' && ch <= 'z')
    {
      found[ch - 'a'] = 1;
    }
  }

  for (size_t i = 0; str2[i] != '\0'; i++)
  {
    char ch = std::tolower(str2[i]);
    if (ch >= 'a' && ch <= 'z')
    {
      found[ch - 'a'] = 1;
    }
  }
  for (int i = 0; i < 26; i++) {
    if (found[i] == 1)
    {
      length++;
    }
  }
  char* result = reinterpret_cast<char*> (malloc(sizeof(char) * (length + 1)));
  size_t n = 0;
  for (int i = 0; i < 26; i++) {
    if (found[i] == 1)
    {
      result[n] = 'a' + i;
      n++;
    }
  }
  result[n] = '\0';
  return result;
}

#include "inputStr.h"
#include <iostream>
#include <cstddef>

char* duhanina::strcpy(char* array, char* new_array)
{
  size_t i = 0;
  for (i = 0; array[i] != '\0'; ++i)
  {
    new_array[i] = array[i];
  }
  new_array[i] = '\0';
  return new_array;
}


char* duhanina::inputStr(std::istream& in)
{
  size_t size = 20;
  char* str = nullptr;
  try
  {
    str = new char[size + 1];
  }
  catch (const std::bad_alloc& e)
  {
    return nullptr;
  }
  str[size] = '\0';
  char c = '\0';
  size_t index = 0;
  in >> std::noskipws;
  while (in >> c && c != '\n')
  {
    if (index >= (size - 1))
    {
      size *= 2;
      char* newStr = nullptr;
      try
      {
        newStr = new char[size + 1] {0};
      }
      catch (const std::bad_alloc& e)
      {
        delete[] str;
        throw;
      }
      newStr = duhanina::strcpy(str, newStr);
      delete[] str;
      str = newStr;
    }
    str[index++] = c;
  }
  str[index] = '\0';
  in >> std::skipws;
  return str;
}

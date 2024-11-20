#include "inputStr.h"
#include <iostream>
#include <cstddef>

char* duhanina::createNewArray(char* array, char* new_array)
{
  size_t i = 0;
  for (i = 0; array[i] != '\0'; ++i)
  {
    new_array[i] = array[i];
  }
  new_array[i] = '\0';
  delete[] array;
  return new_array;
}


char* duhanina::inputStr(std::istream& in)
{
  size_t size = 20;
  char* str = nullptr;
  try
  {
    str = new char[size + 1] {0};
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
        return nullptr;
      }
      if (newStr == nullptr)
      {
        delete[] str;
        delete[] newStr;
        return nullptr;
      }
      newStr = duhanina::createNewArray(str, newStr);
      str = newStr;
    }
    in >> std::skipws;
    str[index++] = c;
  }
  str[index] = '\0';
  if(str[0] == '\0')
  {
    delete[] str;
    return nullptr;
  }
  return str;
}

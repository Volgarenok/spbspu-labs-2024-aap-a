#include "string.hpp"

void lebedev::removeElement(char* str, size_t num)
{
  size_t i = 0;
  while(str[i] != '\0')
  {
    str[i] = str[i + 1];
    ++i;
  }
}

char* lebedev::getLine(std::istream& in, char endChar)
{
  size_t capacity = 10;
  size_t size = 0;
  char* str = new char[capacity];

  char ch = ' ';
  in >> std::noskipws >> ch;
  while (ch != endChar)
  {
    if (size >= capacity - 1)
    {
      capacity *= 2;
      char* newStr = nullptr;
      try
      {
        newStr = new char[capacity];
      }
      catch(std::bad_alloc& e)
      {
        delete[] newStr;
        delete[] str;
        throw;
      }

      size_t i = 0;
      while (str[i] != '\0')
      {
        newStr[i] = str[i];
      }

      delete[] str;
      str = newStr;
    }

    str[size] = ch;
    in >> std::noskipws >> ch;
    size++;
  }
  
  str[size] = '\0';
  return str;
}

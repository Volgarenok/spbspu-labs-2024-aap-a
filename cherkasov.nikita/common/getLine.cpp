#include "getLine.h"
#include <iostream>
#include <cstring>
#include <istream>
#include <stdexcept>

char* cherkasov::newArray(const char* oldArray, size_t newCapacity)
{
  char* newArray = new (std::nothrow) char[newCapacity];
  if (!newArray)
  {
    return nullptr;
  }
  if (oldArray)
  {
    std::strncpy(newArray, oldArray, newCapacity - 1);
    newArray[newCapacity - 1] = '\0';
  }
    return newArray;
}

char* cherkasov::inputLine(std::istream& in)
{
  size_t capacity = 13;
  size_t length = 0;
  char* buffer = new (std::nothrow) char[capacity];
  if (!buffer)
  {
    throw std::bad_alloc();
  }
  char ch = '\0';
  in >> std::noskipws;
  while (in.get(ch) && ch != '\n')
  {
    if (length + 1 >= capacity)
    {
      size_t newCapacity = capacity * 2;
      char* temp = newArray(buffer, newCapacity);
      if (!temp)
      {
        delete[] buffer;
        throw std::bad_alloc();
      }
        buffer = temp;
        capacity = newCapacity;
    }
      buffer[length++] = ch;
  }
  if (length == 0 && in.eof())
  {
    delete[] buffer;
    return nullptr;
  }

  buffer[length] = '\0';
  return buffer;
}

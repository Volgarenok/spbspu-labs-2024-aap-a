#include "getLine.h"
#include <iostream>
#include <cstring>

char* cherkasov::inputLine(std::istream& in)
{
  size_t capacity = 13;
  size_t length = 0;
  char* buffer = new (std::nothrow) char[capacity];
  if (!buffer)
  {
    std::cerr << "Error: Faile to allocate memory.\n";
    return nullptr;
  }
  char ch;
  std::noskipws(in);
  while (in.get(ch) && ch != '\n')
  {
    if (in.fail())
    {
      std::cerr << "Error: Input stream failure.\n";
      delete[] buffer;
      return nullptr;
    }
    buffer[length++] = ch;
    if (length >= capacity)
    {
      size_t newCapacity = capacity * 2;
      char* newBuffer = cherkasov::newArray(buffer, newCapacity);
      if (!newBuffer)
      {
        return nullptr;
      }
    buffer = newBuffer;
    capacity = newCapacity;
    }
  }
  buffer[length] = '\0';
  return buffer;
}

char* cherkasov::newArray(char* oldArray, size_t newCapacity)
{
  char* newArray = new (std::nothrow) char[newCapacity];
  if (!newArray)
  {
    delete[] oldArray;
    std::cerr << "Error: Fail to allocate memory.\n";
    return nullptr;
    }
  std::strcpy(newArray, oldArray);
  delete[] oldArray;
  return newArray;
}

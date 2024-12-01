#include "getLine.h"
#include <iostream>

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
      char* newBuffer = newArrray(buffer, newCapacity);
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

char* cherkasov::newArrray(char* oldArray, size_t newCapacity)
{
  char* cherkasov::newArrray = new (std::nothrow) char[newCapacity];
  if (!newArrray)
  {
    delete[] oldArray;
    std::cerr << "Error: Fail to allocate memory.\n";
    std::exit(1);
    }
  for (size_t i = 0; oldArray[i] != '\0'; ++i)
  {
    newArrray[i] = oldArray[i];
  }
  delete[] oldArray;
  return newArrray;
}

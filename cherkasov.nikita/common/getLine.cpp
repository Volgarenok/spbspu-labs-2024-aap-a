#include "getLine.h"
#include <iostream>

char* cherkasov::inputLine(std::istream& in)
{
  size_t capacity = 21;
  size_t length = 0;
  char* buffer = new char[capacity];
  if (!buffer)
  {
    return nullptr;
  }
  char ch = '\0';
  in >> std::noskipws;
  while (in.get(ch) && ch != '\n')
  {
    if (length + 1 >= capacity)
    {
      size_t newCapacity = capacity * 2;
      char* newBuffer = new char[newCapacity];
      if (!newBuffer)
      {
        delete[] buffer;
        return nullptr;
      }
        std::copy(buffer, buffer + length, newBuffer);
        delete[] buffer;
        buffer = newBuffer;
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

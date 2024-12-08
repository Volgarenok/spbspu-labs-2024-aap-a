#include "getLine.h"
#include <iostream>
#include <stdexcept>

void cherkasov::copyArray(const char* src, char* dest, size_t length)
{
  for (size_t i = 0; i < length; ++i)
  {
    dest[i] = src[i];
  }
}

char* cherkasov::inputLine(std::istream& in, size_t& length)
{
  size_t capacity = 21;
  length = 0;
  char* buffer = nullptr;
  try
  {
    buffer = new char[capacity];
  }
  catch (const std::bad_alloc&)
  {
    return nullptr;
  }
  char ch = '\0';
  in >> std::noskipws;
  while (in >> ch && ch != '\n')
  {
    if (length + 1 >= capacity)
    {
      size_t newCapacity = capacity * 2;
      char* newBuffer = nullptr;
      try
      {
        newBuffer = new char[newCapacity];
      }
      catch (const std::bad_alloc&)
      {
        delete[] buffer;
        return nullptr;
      }
      cherkasov::copyArray(buffer, newBuffer, length);
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


#include "getLine.h"
#include <iostream>
#include <cstring>
#include <istream>
#include <stdexcept>

char* cherkasov::newArray(char* oldArray, size_t newCapacity)
{
  char* newArray = nullptr;
  try
  {
    newArray = new char[newCapacity]();
    if (oldArray)
    {
      size_t oldLength = 0;
      while (oldArray[oldLength] != '\0' && oldLength < newCapacity - 1)
      {
        newArray[oldLength] = oldArray[oldLength];
        ++oldLength;
      }
        newArray[oldLength] = '\0';
        delete[] oldArray;
    }
      return newArray;
  }
  catch (const std::bad_alloc&)
  {
    delete[] oldArray;
    throw;
  }
}

char* cherkasov::inputLine(std::istream& in)
{
  size_t capacity = 13;
  size_t length = 0;
  char* buffer = nullptr;
  try
  {
    buffer = new char[capacity]();
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Memory allocation error: " << e.what() << "\n";
    throw;
  }
  char ch = '\0';
  in >> std::noskipws;
  try
  {
    while (in.get(ch) && ch != '\n') {
    if (length + 1 >= capacity)
    {
      size_t newCapacity = capacity * 2;
      buffer = newArray(buffer, newCapacity);
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
  catch (...)
  {
    delete[] buffer;
    throw;
  }
}

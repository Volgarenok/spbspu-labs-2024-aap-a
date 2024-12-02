#include "getLine.h"
#include <iostream>
#include <cstring>
#include <istream>
#include <stdexcept>

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
    std::cerr << "Error: Memory allocation failed during initialization: " << e.what() << "\n";
    throw;
  }
  char ch;
  in >> std::noskipws;
  try
  {
     while (in.get(ch) && ch != '\n')
     {
       if (length + 1 >= capacity)
       {
         size_t newCapacity = capacity * 2;
         char* newBuffer = nullptr;
         try
         {
           newBuffer = cherkasov::newArray(buffer, newCapacity);
         }
         catch (const std::bad_alloc& e)
         {
           std::cerr << "Error: Memory allocation failed during buffer resizing: " << e.what() << "\n";
           delete[] buffer;
           throw;
         }
           buffer = newBuffer;
           capacity = newCapacity;
     }
       buffer[length++] = ch;
  }
    if (length == 0 && !in.eof())
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

char* cherkasov::newArray(char* oldArray, size_t newCapacity)
{
  try
  {
  char* newArray = new char[newCapacity];
  if (oldArray)
  {
    size_t oldLength = 0;
    while (oldArray[oldLength] != '\0' && oldLength < newCapacity - 1)
    {
      newArray[oldLength] = oldArray[oldLength];
      oldLength++;
    }
      newArray[oldLength] = '\0';
      delete[] oldArray;
      }
      else
      {
        newArray[0] = '\0';
      }
        return newArray;
      }
      catch (const std::bad_alloc& e)
      {
        std::cerr << "Error: Memory allocation failed: " << e.what() << "\n";
        delete[] oldArray;
        throw;
      }
}

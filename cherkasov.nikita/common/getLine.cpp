#include "getLine.h"
#include <iostream>
#include <cstring>
#include <istream>
#include <stdexcept>

char* newArray(char* oldArray, size_t newCapacity)
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

char* cherkasov::newArray(char* oldArray, size_t newCapacity)
{
  char* newArray = new (std::nothrow) char[newCapacity]();
  if (!newArray)
  {
    delete[] oldArray;
    std::cerr << "Error: Fail to allocate memory.\n";
    return nullptr;
  }
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

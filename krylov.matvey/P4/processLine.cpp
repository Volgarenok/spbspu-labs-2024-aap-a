#include "processLine.hpp"
#include <cstddef>
#include <iostream>

namespace krylov
{
  constexpr size_t memorySize = 52;
}

char * krylov::inputLine(std::istream & in)
{
  char * array = nullptr;
  size_t capacity = krylov::memorySize;
  try
  {
    array = allocMemory(capacity);
  }
  catch (const std::bad_alloc & e)
  {
    return nullptr;
  }
  size_t currentElementIndex = 0;
  while (!in.eof())
  {
    if (currentElementIndex == (capacity - 1))
    {
      array[currentElementIndex] = '\0';
      capacity *= 3;
      try
      {
        array = krylov::replaceArray(array, capacity);
      }
      catch (const std::bad_alloc & e)
      {
        delete[] array;
        return nullptr;
      }
    }
    in >> std::noskipws >> array[currentElementIndex++];
  }
  array[currentElementIndex - 1] = '\0';
  return array;
}

char * krylov::allocMemory(size_t capacity)
{
  char * array = new char[capacity];
  return array;
}

char * krylov::replaceArray(char * oldArray, size_t newCapacity)
{
  char * newArray = new char[newCapacity];
  for (size_t i = 0; oldArray[i] != '\0'; i++)
  {
    newArray[i] = oldArray[i];
  }
  delete[] oldArray;
  return newArray;
}


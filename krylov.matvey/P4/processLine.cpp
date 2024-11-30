#include "processLine.hpp"
#include <iostream>

char* krylov::inputLine(std::istream& in)
{
  char* array = nullptr;
  size_t capacity = 52;
  try
  {
    array = new char[capacity];
  }
  catch (const std::bad_alloc& e)
  {
    return nullptr;
  }
  size_t currentElementIndex = 0;
  std::noskipws(in);
  while (!in.eof())
  {
    if (currentElementIndex == (capacity - 1))
    {
      array[currentElementIndex] = '\0';
      capacity *= 3;
      array = replaceArray(array, capacity);
      if (array == nullptr)
      {
        return nullptr;
      }
    }
    in >> array[currentElementIndex++];
  }
  std::skipws(in);
  array[currentElementIndex - 1] = '\0';
  return array;
}

char* krylov::replaceArray(char* oldArray, size_t newCapacity)
{
  char* newArray = nullptr;
  try
  {
    newArray = new char[newCapacity];
  }
  catch (const std::bad_alloc& e)
  {
    delete[] oldArray;
    return nullptr;
  }
  for (size_t i = 0; oldArray[i] != '\0'; i++)
  {
    newArray[i] = oldArray[i];
  }
  delete[] oldArray
  return newArray;
}

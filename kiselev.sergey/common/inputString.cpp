#include "inputString.h"
#include <iostream>
char* kiselev::resizeArr(const char* array, size_t newLength, size_t pastLength)
{
  char* arr2 = static_cast< char* >(malloc(newLength * sizeof(char)));
  if (arr2 == nullptr)
  {
    return arr2;
  }
  for (size_t i = 0; i < pastLength; ++i)
  {
    arr2[i] = array[i];
  }
  return arr2;
}
char* kiselev::inputString(std::istream& input, const char end)
{
  size_t memorySize = 3;
  char* arr = static_cast< char* >(malloc(memorySize * sizeof(char)));
  if (arr == nullptr)
  {
    return arr;
  }
  size_t length = 0;
  std::noskipws(input);
  arr[length] = '\0';
  while (arr[length] != end)
  {
    length++;
    if (length == memorySize)
    {
      size_t timeLength = memorySize;
      memorySize += 5;
      char* temporaryArray = arr;
      arr = kiselev::resizeArr(arr, memorySize, timeLength);
      free(temporaryArray);
      if (arr == nullptr)
      {
        std::cerr << "Out of memory\n";
        return arr;
      }
    }
    if (!(input >> arr[length]))
    {
      break;
    }
  }
  arr[length] = '\0';
  std::skipws(std::cin);
  return arr;
}

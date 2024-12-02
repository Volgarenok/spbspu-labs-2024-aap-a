#include "inputString.h"
#include <iostream>
<<<<<<< HEAD
char* resizeArr(const char* array, size_t newLength, size_t pastLength)
=======
char* kiselev::resizeArr(const char* array, size_t newLength, size_t pastLength)
>>>>>>> parent of f7ab4f9b (Revert "Merge branch 'dribas.sergey/P6' into dribas.sergey/P4")
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
char* kiselev::inputString(std::istream& input, char end)
{
  size_t memorySize = 3;
  char* arr = static_cast< char* >(malloc(memorySize * sizeof(char)));
  if (arr == nullptr)
  {
    return arr;
  }
  size_t length = 0;
  std::noskipws(input);
  while (true)
  {
    char symbol = {};
    if (!(input >> symbol) || symbol == end)
    {
      break;
    }
    arr[length++] = symbol;
    if (length == memorySize)
    {
      size_t temporaryLength = memorySize;
      memorySize += 5;
      char* temporaryArray = arr;
<<<<<<< HEAD
      arr = resizeArr(arr, memorySize, temporaryLength);
=======
      arr = kiselev::resizeArr(arr, memorySize, temporaryLength);
>>>>>>> parent of f7ab4f9b (Revert "Merge branch 'dribas.sergey/P6' into dribas.sergey/P4")
      free(temporaryArray);
      if (arr == nullptr)
      {
        return arr;
      }
    }
  }
  arr[length] = '\0';
  std::skipws(std::cin);
  return arr;
}

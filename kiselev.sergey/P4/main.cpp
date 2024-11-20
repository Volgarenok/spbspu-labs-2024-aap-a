#include <iostream>
#include "identicalChar.h"
#include "resizeArray.h"
int main()
{
  size_t memorySize = 3;
  char* arr = static_cast<char*>(malloc(memorySize * sizeof(char)));
  if (arr == nullptr)
  {
    std::cerr << "Out of memory\n";
    return 1;
  }
  size_t length = 0;
  std::noskipws(std::cin);
  if (!(std::cin >> arr[length]))
  {
    std::cerr << "Incorrect input\n";
    free(arr);
    return 1;
  }
  while (arr[length] != '\n')
  {
    length++;
    if (length == memorySize)
    {
      size_t timeLength = memorySize;
      memorySize += 5;
      arr = kiselev::resizeArr(arr, memorySize, timeLength);
      if (arr == nullptr)
      {
        std::cerr << "Out of memory\n";
        return 1;
      }
    }
    if (!(std::cin >> arr[length]))
    {
      break;
    }
  }
  arr[length] = '\0';
  std::skipws(std::cin);
  const char secondArr[] = "abs";
  size_t countIdentical = kiselev::identicalChar(arr, secondArr);
  std::cout << "Identical character: " << countIdentical << "\n";
  free(arr);
  return 0;
}

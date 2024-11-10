#include <iostream>
#include "identicalChar.h"
#include "resizeArray.h"
int main()
{
  size_t length = 3;
  char* arr = static_cast<char*>(malloc(length * sizeof(char)));
  if (arr == nullptr)
  {
    std::cerr << "Out of memory\n";
    return 1;
  }
  size_t count = 0;
  std::noskipws(std::cin);
  if (!(std::cin >> arr[count]))
  {
    std::cerr << "Incorrect input\n";
    free(arr);
    return 1;
  }
  while (arr[count] != '\n')
  {
    count++;
    if (count == length)
    {
      size_t timeLength = length;
      length += 5;
      arr = kiselev::resizeArr(arr, length, timeLength);
      if (arr == nullptr)
      {
        std::cerr << "Out of memory\n";
        free(arr);
        return 1;
      }
    }
    if (!(std::cin >> arr[count]))
    {
      break;
    }
  }
  arr[count] = '\0';
  std::skipws(std::cin);
  constexpr size_t secondLength = 4;
  const char secondArr[secondLength] = "abs";
  size_t countIdentical = kiselev::identicalChar(arr, secondArr, length, secondLength);
  std::cout << "Identical character: " << countIdentical << "\n";
  free(arr);
  return 0;
}

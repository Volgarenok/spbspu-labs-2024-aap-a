#include <iostream>

#include "workWithString.hpp"

int main()
{
  char *arr = nullptr;
  constexpr size_t numOfLetters = 26;
  char c = '\0';
  size_t reserved = 10;
  constexpr size_t step = 10;
  size_t wPoint = 0;
  arr = static_cast<char*>(malloc(reserved));
  if (arr == nullptr)
  {
    return 1;
  }
  std::noskipws(std::cin);
  while ((std::cin >> c) && (c != '\n'))
  {
    arr[wPoint++] = c;
    if (wPoint == reserved)
    {
      arr = guseynov::getNewArr(arr, reserved, step);
      reserved += step;
    }
  }
  if (!std::cin)
  {
    free(arr);
    return 1;
  }
  arr = guseynov::getNewArr(arr, wPoint, 0);
  if (arr == nullptr)
  {
    return 1;
  }
  char uniqueChars[numOfLetters] = {'a', 'b', 'c', 'd','e', 'f', 'g', 'h', 'i',
  'j', 'k', 'l','m', 'n', 'o', 'p', 'q', 'r',
  's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  std::cout << guseynov::identifyUniqueChar(arr, uniqueChars, numOfLetters) << "\n";
  free(arr);
  return 0;
}

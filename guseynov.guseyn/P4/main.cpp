#include <iostream>

#include "workWithString.hpp"

int main()
{
  char *arr = nullptr;
  const size_t num = 26;
  char c = '\n';
  size_t min = 10;
  size_t size = 0;
  arr = static_cast < char* > (malloc(min));
  std::noskipws(std::cin);
  while ((std::cin >> c) && (c != '\n'))
  {
    arr[size++] = c;
    if (size == min)
    {
      min += 10;
      arr = guseyn::newarr(arr, min);
    }
  }
  arr = guseyn::newarr(arr, size);
  if (!std::cin)
  {
    return 1;
  }
  if (arr == nullptr)
  {
    return 1;
  }
  char uniqueChars[num] = {'a', 'b', 'c', 'd','e', 'f', 'g', 'h', 'i',
  'j', 'k', 'l','m', 'n', 'o', 'p', 'q', 'r',
  's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  std::cout << guseyn::identifyUniqueChar(arr, uniqueChars, num) << "\n";
  free(arr);
  return 0;
}

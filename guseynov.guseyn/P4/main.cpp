#include <iostream>

#include "workWithString.hpp"
int main()
{
  char *arr = nullptr;
  char stop = '\n';
  const size_t num = 26;
  arr = guseyn::inputLine(std::cin, stop);
  if (arr == NULL)
  {
    return 1;
  }
  char uniqueChars[num] = {'a', 'b', 'c', 'd','e', 'f', 'g', 'h',
  'i', 'j', 'k', 'l','m', 'n', 'o',
  'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  std::cout << guseyn::identifyUniqueChar(arr, uniqueChars, num) << "\n";
  free(arr);
  return 0;
}

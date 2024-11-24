#include <iostream>

#include <workWithString.hpp>

int main()
{
  char *arr = nullptr;
  constexpr char stop = '\n';
  arr = guseynov::getLine(std::cin, stop);
  if (arr == nullptr)
  {
    return 1;
  }
  std::cout << guseynov::identifyUniqueChar(arr) << "\n";
  free(arr);
  return 0;
}

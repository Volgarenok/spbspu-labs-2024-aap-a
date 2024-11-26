#include <iostream>

#include "workWithString.hpp"

int main()
{
  char *arr = nullptr;
  size_t stringLength = 0;
  try
  {
    arr = guseynov::getLine(std::cin, stringLength);
  }
  catch(std::bad_alloc & e)
  {
    return 1;
  }
  if (arr == nullptr)
  {
    return 1;
  }
  std::cout << guseynov::determiningNumOfLetters(arr, stringLength) << "\n";
  free(arr);
  return 0;
}

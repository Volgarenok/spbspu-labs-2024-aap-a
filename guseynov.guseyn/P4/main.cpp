#include <iostream>

#include <workWithString.hpp>
#include "det_Num_Of_Letters.hpp"

int main()
{
  char *arr = guseynov::getLine(std::cin);
  if (arr == nullptr)
  {
    return 1;
  }
  if (arr[0] == '\0')
  {
    free(arr);
    return 1;
  }
  std::cout << guseynov::determiningNumOfLetters(arr) << "\n";
  free(arr);
  return 0;
}

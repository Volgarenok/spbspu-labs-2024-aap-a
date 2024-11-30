#include <iostream>

#include <workWithString.hpp>
<<<<<<< HEAD
=======
#include "det_Num_Of_Letters.hpp"
>>>>>>> guseynov.guseyn/P4

int main()
{
  char *arr = nullptr;
  arr = guseynov::getLine(std::cin);
  if (arr == nullptr)
  {
    return 1;
  }
  std::cout << guseynov::determiningNumOfLetters(arr) << "\n";
  free(arr);
  return 0;
}

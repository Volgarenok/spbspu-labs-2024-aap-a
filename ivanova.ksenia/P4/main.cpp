#include <iostream>
#include "string.h"

int main()
{
  char* string = ivanova::getLine(std::cin);
  if (!string || string[0] == '\0')
  {
    std::cerr << "Error in entered string" << '\n';
    delete[] string;
    return 1;
  }
  std::cout << ivanova::/дайте вариант/(string) << '\n';
  std::cout << ivanova::/дайте вариант/(string) << '\n';
  delete[] string;
  return 0;
}

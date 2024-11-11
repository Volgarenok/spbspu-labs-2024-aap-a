#include <cstddef>
#include <ios>
#include <iostream>
#include <memory>
#include "arraymoves.h"

int main()
{
  size_t max = 10;
  constexpr size_t n = 2;
  char* str1 = reinterpret_cast<char*> (malloc(sizeof(char) * (max + 1)));
  char* str2 = reinterpret_cast<char*> (malloc(sizeof(char) * (max + 1)));
  if (str1 == nullptr)
  {
    if(str2 == nullptr)
    {
      free(str2);
    }
    free(str1);
    std::cerr << "Out of memory\n";
    return 1;
  }
  str1 = averenkov::stringInput(std::cin, str1);
  str2 = averenkov::stringInput(std::cin, str2);
std::cout << str1 << "\n" << str2 << "\n";
  std::cout << averenkov::latTwo(str1, str2);
  free(str1);
  free(str2);
}

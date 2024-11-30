#include <iostream>
#include <stringinput.hpp>
#include "removevowels.h"

int main()
{
  size_t capacity = 2;
  char* str = tkach::inputStr(std::cin, capacity);
  if (str == nullptr)
  {
    std::cerr << "Error: not enough memory\n";
    return 1;
  }
  if (!std::cin)
  {
    free(str);
    std::cerr << "Error: invalid input\n";
    return 1;
  }
  if (str[0] == '\0')
  {
    free(str);
    std::cerr << "Error: input error - empty str\n";
    return 1;
  }
  char* str_with_removed_vowels = reinterpret_cast< char* >(malloc(capacity));
  if (str_with_removed_vowels == nullptr)
  {
    free(str);
    std::cerr << "Error: not enough memory\n";
    return 1;
  }
  tkach::getStrWithRemovedVowels(str, str_with_removed_vowels);
  std::cout << str_with_removed_vowels << "\n";
  free(str);
  free(str_with_removed_vowels);
  return 0;
}

#include <iostream>
#include "strfunc.h"
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
  char* str2 = reinterpret_cast< char* >(malloc(sizeof(char) * (capacity)));
  if (str2 == nullptr)
  {
    free(str);
    std::cerr << "Error: not enough memory\n";
    return 1;
  }
  tkach::getStrWithRemovedVowels(str, str2);
  std::cout << str2 << "\n";
  free(str);
  free(str2);
  return 0;
}

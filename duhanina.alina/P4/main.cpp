#include <iostream>
#include <cstddef>
#include <inputStr.h>
#include "shrSym.h"

int main()
{
  char* str = duhanina::inputStr(std::cin);
  if (str == nullptr)
  {
    std::cerr << "Memory\n";
    return 1;
  }
  if (str[0] == '\0')
  {
    std::cerr << "Empty\n";
    delete[] str;
    return 1;
  }
  char missing[27];
  duhanina::shrSym(str, missing);
  std::cout << missing << "\n";
  delete[] str;
  return 0;
}

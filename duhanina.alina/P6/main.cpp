#include <iostream>
#include <inputStr.h>
#include "recursiveChecks.h"

int main()
{
  char* str = duhanina::inputStr(std::cin);
  if (str == nullptr)
  {
    std::cerr << "Error\n";
    delete[] str;
    return 1;
  }
  std::cout << duhanina::isReal(str) << "\n";
}

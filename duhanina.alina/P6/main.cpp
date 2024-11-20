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
  if (isReal(str))
  {
    std::cout << "true\n";
  }
  else
  {
    std::cout << "false\n";
  }
  delete[] str;
  return 0;
}

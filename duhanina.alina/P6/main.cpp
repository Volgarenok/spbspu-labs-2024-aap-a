#include <iostream>
#include <inputStr.h>
#include "recursiveChecks.h"

int main()
{
  char* str = duhanina::inputStr(std::cin);
  if (str == nullptr)
  {
    std::cerr << "Memory error\n";
    return 1;
  }
  if (str[0] == '\0')
  {
    std::cerr << "Empty\n";
    delete[] str;
    return 1;
  }
  if (duhanina::isReal(str))
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

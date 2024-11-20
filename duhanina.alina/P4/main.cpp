#include <iostream>
#include <cstddef>
#include "shrSym.h"
#include <inputStr.h>

int main()
{
  char* str = duhanina::inputStr(std::cin);
  if (str == nullptr)
  {
    std::cerr << "Error";
    delete[] str;
    return 1;
  }
  char* missing = new char[27];
  duhanina::shrSym(str, missing);
  std::cout << missing << "\n";
  delete[] str;
  delete[] missing;
  return 0;
}

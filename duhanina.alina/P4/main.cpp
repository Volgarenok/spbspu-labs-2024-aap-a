#include <iostream>
#include <cstddef>
#include <inputStr.h>
#include "shrSym.h"

int main()
{
  char* str = nullptr;
  try
  {
    str = duhanina::inputStr(std::cin);
  }
  catch (const std::bad_alloc& e)
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
  char missing[27];
  duhanina::shrSym(str, missing);
  std::cout << missing << "\n";
  delete[] str;
  return 0;
}

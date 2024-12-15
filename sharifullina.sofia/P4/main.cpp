#include <iostream>
#include "shrSym_uniTwo.hpp"

int main()
{
  const char firstLine[] = "def ";
  char * str = nullptr;
  try
  {
    str = sharifullina::inputString(std::cin, '\n');
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << "Out of memory\n";
    return 1;
  }
  if (str[0] == '\0')
  {
    delete[] str;
    std::cerr << "Empty input\n";
    return 1;
  }
  std::cout << sharifullina::shrSym(firstLine, str) << '\n';
  std::cout << sharifullina::uniTwo(firstLine, str) << '\n';
  delete[] str;
  return 0;
}

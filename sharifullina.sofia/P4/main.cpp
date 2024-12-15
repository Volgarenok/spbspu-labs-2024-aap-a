#include <iostream>
#include "shrSym_uniTwo.hpp"

int main()
{
  const char firstLine[] = "def ";
  char * str = nullptr;
  char * resultShrSym = nullptr;
  char * resultUniTwo = nullptr;
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
  resultShrSym = sharifullina::shrSym(firstLine, str);
  std::cout << resultShrSym << '\n';
  delete[] resultShrSym;

  resultUniTwo = sharifullina::uniTwo(firstLine, str);
  std::cout << resultUniTwo << '\n';
  delete[] resultUniTwo;

  delete[] str;
  return 0;
}

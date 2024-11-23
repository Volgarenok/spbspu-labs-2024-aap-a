#include <iostream>
#include <getString.hpp>
#include "recursionCheckStr.hpp"

int main()
{
  char *str = nullptr;
  try
  {
    str = abramov::getStr(std::cin);
  }
  catch (const std::bad_alloc &e)
  {
    std::cerr << "Memory fail\n";
    return 2;
  }
  std::cout << std::boolalpha << abramov::isReal(str) << "\n";
  delete[] str;
}

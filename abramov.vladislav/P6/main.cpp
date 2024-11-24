#include <iostream>
#include <getString.hpp>
#include "recursionCheckStr.hpp"

int main()
{
  char *str = nullptr;
  if (std::cin.eof())
  {
    std::cerr << "Empty input\n";
    return 1;
  }
  try
  {
    str = abramov::getStr(std::cin);
  }
  catch (const std::bad_alloc &e)
  {
    std::cerr << "Memory fail\n";
    return 2;
  }
  if (str == nullptr)
  {
    std::cerr << "Memory fail\n";
    return 2;
  }
  if (str[0]=='\0')
  {
    std::cerr << "Empty input";
    return 1;
  }
  std::cout << std::boolalpha << abramov::isReal(str) << "\n";
  delete[] str;
}

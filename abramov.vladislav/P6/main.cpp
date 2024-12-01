#include <iostream>
#include <getString.hpp>
#include "recursiveCheckStr.hpp"

int main()
{
  char *str = nullptr;
  size_t size_of_str = 0;
  try
  {
    str = abramov::getStr(std::cin, size_of_str);
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
    delete[] str;
    return 1;
  }
  std::cout << std::boolalpha << abramov::isReal(str) << "\n";
  delete[] str;
}

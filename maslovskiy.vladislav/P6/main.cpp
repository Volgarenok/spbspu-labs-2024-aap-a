#include <iostream>
#include <getLine.hpp>
#include "recursionString.hpp"
int main()
{
  char *str1 = maslovskiy::inputString(std::cin);
  if (str1 == nullptr)
  {
    std::cerr << "Error: memory not allocate for string\n";
    return 1;
  }
  std::cout << std::boolalpha << maslovskiy::isDouble(str1) << "\n";
  free(str1);
}

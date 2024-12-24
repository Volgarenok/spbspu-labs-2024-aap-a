#include <iostream>
#include <cstddef>
#include "str_input.hpp"


int main()
{
  char * str = dirti::str_input(std::cin);
  if (str == nullptr)
  {
    std::cerr << "Error" << "\n";
    return 1;
  }
  std::cout << str[1] << "\n";
}

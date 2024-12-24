#include <iostream>
#include <cstddef>
#include "str_input.hpp"
#include "str_min.hpp"


int main()
{
  size_t capacity = 2;
  char * str = dirti::str_input(std::cin, capacity);
  if (str == nullptr)
  {
    std::cerr << "Error" << "\n";
    return 1;
  }
  size_t size = capacity - 1;
  std::cout << dirti::str_min(str, size) << "\n";
}

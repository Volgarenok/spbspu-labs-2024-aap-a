#include <iostream>
#include <cstddef>
#include "str_input.hpp"
#include "str_min.hpp"
#include "str_min2.hpp"


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
  if (dirti::str_min(str, size) == '\0')
  {
    std::cerr << "Error: bad alloc" << "\n";
    return 1;
  }
  else if (dirti::str_min(str, size) == '\n')
  {
    std::cout << "Not existing one rare symbol" << "\n";
  }
  else
  {
    std::cout << dirti::str_min(str, size) << "\n";
  }
  if (dirti::str_min2(str, size) == nullptr)
  {
    std::cerr << "Error: bad_alloc" << "\n";
  }
  else
  {
    std::cout << dirti::str_min2(str, size) << "\n";
  }
}

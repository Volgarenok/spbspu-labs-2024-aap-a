#include <iostream>
#include <cstddef>
#include <str_input.hpp>
#include "str_min.hpp"
#include "str_min2.hpp"
#include "str_min_recursed.hpp"

int main()
{
  size_t capacity = 1;
  char * str = dirti::str_input(std::cin, capacity);
  if (str == nullptr)
  {
    std::cerr << "Error" << "\n";
    return 1;
  }
  size_t size = capacity - 1;
  char str_min = dirti::str_min(str, size);
  if (str_min == '\n')
  {
    std::cout << "Not existing one rare symbol" << "\n";
  }
  else
  {
    std::cout << str_min << "\n";
  }
  char str_min2[2] = {'0', '0'};
  dirti::str_min2(str, size, str_min2);
  if (str_min2[1] == '0')
  {
    std::cout << "There is only one symbol" << "\n";
  }
  else
  {
    std::cout << str_min2[0] << " " << str_min2[1] << "\n";
  }
  char str_min_recursed = dirti::str_min_recursed(str, size);
  if (str_min_recursed == '\0')
  {
    free(str);
    std::cerr << "Error: bad alloc" << "\n";
    return 1;
  }
  else if (str_min_recursed == '\n')
  {
    std::cout << "Not existing one rare symbol" << "\n";
  }
  else
  {
    std::cout << str_min_recursed << "\n";
  }
  free(str);
}

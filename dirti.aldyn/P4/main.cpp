#include <iostream>
#include <cstddef>
#include <str_input.hpp>
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
  char str_min = dirti::str_min(str, size);
  if (str_min == '\0')
  {
    free(str);
    std::cerr << "Error: bad alloc" << "\n";
    return 1;
  }
  else if (str_min == '\n')
  {
    std::cout << "Not existing one rare symbol" << "\n";
  }
  else
  {
    std::cout << str_min << "\n";
  }
  char * str_min2 = nullptr;
  str_min2 = dirti::str_min2(str, size);
  if (str_min2 == nullptr)
  {
    std::cerr << "Error: bad_alloc" << "\n";
    free(str);
    return 1;
  }
  else if (str_min2[0] == str_min2[1])
  {
    std::cout << "There is only one symbol" << "\n";
  }
  else
  {
    std::cout << str_min2[0] << " " << str_min2[1] << "\n";
  }
  free(str_min2);
  free(str);
}

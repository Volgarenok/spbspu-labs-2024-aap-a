#include "dubl_char.hpp"
#include "input_string.hpp"
#include <iostream>
int main()
{
  try
  {
    char* t = karnauhova::input_string(std::cin, '\n');
  }
  catche (const std::bad_alloc &e)
  {
    std::cerr << "Error: out of memory";
    return 1;
  }
  std::cout << dubl_char(t) << "\n";
}

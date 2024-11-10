#include "dubl_char.hpp"
#include "input_string.hpp"
#include <iostream>
int main()
{
  char* t = nullptr;
  try
  {
    t = karnauhova::input_string(std::cin, '\n');
  }
  catch (const std::bad_alloc &e)
  {
    std::cerr << "Error: out of memory";
    return 1;
  }
  std::cout << karnauhova::dubl_char(t) << "\n";
}

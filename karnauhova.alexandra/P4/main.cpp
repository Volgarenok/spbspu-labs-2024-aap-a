#include "dubl_char.hpp"
#include "input_string.hpp"
#include <iostream>
int main()
{
  char* t = nullptr;
  constexpr char end = '\0';
  try
  {
    t = karnauhova::input_string(std::cin, end);
  }
  catch (const std::bad_alloc &e)
  {
    std::cerr << "Error: out of memory\n";
    return 1;
  }
  std::cout << karnauhova::dubl_char(t) << "\n";
  free(t);
  return 0;
}

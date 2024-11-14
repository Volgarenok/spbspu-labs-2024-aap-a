#include <iostream>
#include "dubl_char.hpp"
#include "input_string.hpp"

int main()
{
  constexpr char end = '\0';
  char* t = karnauhova::input_string(std::cin, end);
  if (t == nullptr)
  {
    std::cerr << "Error with input\n";
    free(t);
    return 1;
  }
  std::cout << karnauhova::dubl_char(t) << "\n";
  free(t);
  return 0;
}

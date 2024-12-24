#include <iostream>
#include <stdexcept>
#include <input_string.hpp>
#include "check_real.hpp"
int main()
{
  constexpr char end = '\n';
  char* t = karnauhova::input_string(std::cin, end);
  if (t == nullptr)
  {
    std::cerr << "Error with input\n";
    return 1;
  }
  if (t[0] == '\0')
  {
    std::cerr << "Empty string\n";
    free(t);
    return 1;
  }
  std::cout << std::boolalpha << karnauhova::is_real(t) << "\n";
  free(t);
}

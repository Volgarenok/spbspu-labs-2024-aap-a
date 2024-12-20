#include <iostream>
#include <stdexcept>
#include "checkString.hpp"
#include <inputOfString.hpp>

int main()
{
  const char end = '\n';
  char *c = shabalin::inputOfString(std::cin, end);
  if (c == nullptr)
  {
    std::cerr << "Error with input\n";
    return 1;
  }
  if (c[0] == '\0')
  {
    std::cerr << "Empty string\n";
    free(c);
    return 1;
  }
  std::cout << std::boolalpha << shabalin::func(c) << '\n';
  free(c);
}

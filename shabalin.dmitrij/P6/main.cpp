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
  if (t[0] == '\0')
  {
    std::cerr << "Empty string\n";
    free(t);
    return 1;
  }
  std::cout << std::boolalpha << shabalin::func(t) << '\n';
  free(t);
}
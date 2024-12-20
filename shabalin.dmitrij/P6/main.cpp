#include <iostream>
#include <stdexcept>
#include <inputOfString.hpp>
#include "checkString.hpp"

int main()
{
  const char end = '\n';
  char *ch = shabalin::inputOfString(std::cin, end);
  if (ch == nullptr)
  {
    std::cerr << "Error with input\n";
    return 1;
  }
  if (ch[0] == '\0')
  {
    std::cerr << "Empty string\n";
    free(ch);
    return 1;
  }
  std::cout << std::boolalpha << shabalin::isRealNumber(ch) << '\n';
  free(ch);
}

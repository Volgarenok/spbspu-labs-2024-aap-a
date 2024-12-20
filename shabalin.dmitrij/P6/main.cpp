#include <iostream>
<<<<<<< HEAD
=======
#include <stdexcept>
>>>>>>> master
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
<<<<<<< HEAD
  std::cout << std::boolalpha << shabalin::func(c) << '\n';
  free(c);
}

=======
  std::cout << std::boolalpha << shabalin::func(t) << '\n';
  free(c);
}
>>>>>>> master

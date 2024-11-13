#include "intcheck.hpp"
#include <cstddef>
#include <string>
#include <stdexcept>

int brevnov::intcheck(char * input)
{
  bool convertible = true;
  if ((input[0] == '1' || input[0] == '2') && input[1] == 0)
  {
    convertible = true;
  }
  if (convertible)
  {
    return std::atoi(input);
  }
  else
  {
    throw std::invalid_argument("Incorrect input");
  }
}

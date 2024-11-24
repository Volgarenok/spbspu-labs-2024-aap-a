#include "matrix.h"
#include <cstddef>
#include <stdexcept>
#include <cstdlib>

long int bocharov::check_number(const char * const argv1)
{
  char * endptr = nullptr;
  long int number = std::strtol(argv1, std::addressof(endptr), 10);
  if (*endptr != '\0')
  {
    throw std::logic_error("First parameter is not a number");
  }
  else if (number < 1 || number > 2)
  {
    throw std::logic_error("First parameter is out of range");
  }
  return number;
}

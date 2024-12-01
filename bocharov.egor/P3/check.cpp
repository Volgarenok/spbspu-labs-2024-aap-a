#include "matrix.h"
#include <cstddef>
#include <stdexcept>
#include <cstdlib>
void bocharov::check_argc(int argc)
{
  if (argc - 1 > 3)
  {
    throw std::logic_error("Too many arguments");
  }
  if (argc - 1 < 3)
  {
    throw std::logic_error("Not enough arguments");
  }
}
long int bocharov::check_number(const char * argv1)
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

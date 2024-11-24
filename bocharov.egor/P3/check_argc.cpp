#include "matrix.h"
#include <stdexcept>

void bocharov::check_argc(int argc)
{
  if (argc - 1 > 3)
  {
    throw std::logic_error("Too manyarguments");
  }
  if (argc - 1 < 3)
  {
    throw std::logic_error("Not enough arguments");
  }
}

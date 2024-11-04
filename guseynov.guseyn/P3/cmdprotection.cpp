#include "cmdprotection.hpp"

#include <stdexcept>

void guseynov::cmdProtection(int argc, char **argv)
{
  constexpr int tasknum = 4;
  if (argc > tasknum)
  {
    throw std::logic_error("Too many arguments");
  }
  if (argc < tasknum)
  {
    throw std::logic_error("Not enough arguments");
  }
  if ((argv[1][0] < '0') or (argv[1][0] > '9'))
  {
    throw std::logic_error("First parameter is not a number");
  }
  int num = static_cast < int > (argv[1][0]);
  if ((num < 1) or (num > 2))
  {
    throw std::logic_error("First parameter is out of range");
  }
}

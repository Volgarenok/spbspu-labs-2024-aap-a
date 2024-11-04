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
  if ((argv[1][1] != '\0') || ((argv[1][0] != '1') && (argv[1][0] != '2')))
  {
    throw std::logic_error("First parameter is not a number of a task");
  }
}

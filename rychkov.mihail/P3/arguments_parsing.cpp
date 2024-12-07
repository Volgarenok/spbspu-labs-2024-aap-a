#include "arguments_parsing.hpp"

#include <iostream>

int rychkov::parseArguments(std::ostream& errStream, int argc, const char*const* argv, int& testMode)
{
  if (argc < 4)
  {
    errStream << "not enough arguments\n";
    return 1;
  }
  if (argc > 4)
  {
    errStream << "too many arguments\n";
    return 1;
  }
  if (*argv[1] == '\0')
  {
    errStream << "first argument is empty\n";
    return 1;
  }
  if ((argv[1][1] != '\0') || ((argv[1][0] != '1') && (argv[1][0] != '2')))
  {
    errStream << "first argument is not a number of a task\n";
    return 1;
  }
  testMode = argv[1][0] - '0';
  return 0;
}

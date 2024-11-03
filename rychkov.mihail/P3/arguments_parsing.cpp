#include "arguments_parsing.hpp"

#include <iostream>

void rychkov::parseArguments(int argc, char** argv, int& testMode)
{
  if (argc < 4)
  {
    std::cerr << "not enough arguments\n";
    exit(1);
  }
  if (argc > 4)
  {
    std::cerr << "too many arguments\n";
    exit(1);
  }
  if (*argv[1] == '\0')
  {
    std::cerr << "first argument is empty\n";
    exit(1);
  }
  if ((argv[1][1] != '\0') || ((argv[1][0] != '1') && (argv[1][0] != '2')))
  {
    std::cerr << "first argument is not a number of a task\n";
    exit(1);
  }
  testMode = argv[1][0] - '0';
}

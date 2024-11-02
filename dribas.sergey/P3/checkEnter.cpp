#include "checkEnter.hpp"
#include <iostream>

bool dribas::checkEnter(char ** argv, int argc, long int& secondArg)
{
  if (argc < 4) {
    std::cerr << "Not enough arguments\n";
    return 0;
  }
  if (argc > 4) {
    std::cerr << "Too many arguments\n";
    return 0;
  }
  char *endptr = nullptr;
  secondArg = std::strtol(argv[1], &endptr, 10);
  if (*endptr != '\0') {
    std::cerr << "First parameter is not a number\n";
    return 0;
  }
  if (secondArg > 2 || secondArg < 1) {
    std::cerr << "First parameter is out of range\n";
    return 0;
  }
  return 1;
}

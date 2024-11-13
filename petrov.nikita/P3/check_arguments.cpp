#include "process_the_matrix.hpp"
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>

int petrov::checkArguments(int argc, const char ** argv)
{
  if (argc != 4)
  {
    if (argc < 4)
    {
      std::cerr << "Not enough arguments\n";
      return 1;
    }
    else if (argc > 4)
    {
      std::cerr << "Too many arguments\n";
      return 1;
    }
  }
  size_t size_of_first_argument = std::strlen(argv[1]);
  for (size_t i = 0; i < size_of_first_argument; i++)
  {
    if (std::isdigit(argv[1][i]) == false)
    {
      std::cerr << "First parameter is not a number\n";
      return 1;
    }
  }
  int check_varuable = std::atoi(argv[1]);
  if (check_varuable != 1 && check_varuable != 2)
  {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }
  return 0;
}


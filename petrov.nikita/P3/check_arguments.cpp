#include "process_the_matrix.hpp"
#include <iostream>
#include <cstring>
#include <cctype>
#include <stdlib.h>

int petrov::check_arguments(int argc, char ** argv)
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
  if (std::atoi(argv[1]) != 1 || std::atoi(argv[1]) != 2)
  {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }
  return 0;
}
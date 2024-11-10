
#include "upptri.hpp"
#include <iostream>

int gavrilova::checkNumOfArguments(int argc)
{
  if (argc > 4) {
    std::cerr << "Too many arguments" << "\n";
    return 0;
  } else if (argc < 4) {
    std::cerr << "Not enough arguments" << "\n";
    return 0;
  } else {
    return 1;
  }
}

int gavrilova::checkFirstArgument(unsigned long int num, const char * end)
{
  if (num > 3) {
    std::cerr << "First parametr is out of range" << "\n";
    return 0;
  } else if (num == 0) {
    std::cerr << "First parametr is not a number" << "\n";
    return 0;
  } else if (*end != 0){
    std::cerr << "First parametr is not a number" << "\n";
    return 0;
  } else {
    return 1;

  }
}

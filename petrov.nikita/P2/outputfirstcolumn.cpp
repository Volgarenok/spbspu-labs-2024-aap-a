#include "calculate_sinh.hpp"
#include <iostream>

void petrov::outputFirstColumn(double x)
{
  std::cout << "|";
  if (x < 0.0)
  {
    std::cout << " ";
  }
  else
  {
    std::cout << "  ";
  }
  std::cout << x;
  std::cout << " |";
}


#include "calculate_sinh.hpp"
#include <iostream>

void petrov::outputThirdColumn(double x)
{
  if (x < 0.0)
  {
    std::cout << " ";
  }
  else
  {
    std::cout << "  ";
  }
  std::cout << petrov::calculateBySTD(x);
  std::cout << " |\n";
}

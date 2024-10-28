#include "calculate_sinh.hpp"
#include <iostream>

void petrov::outputSecondColumn(double x, size_t max, double error)
{
  try
    {
      if (x < 0.0)
      {
        std::cout << " ";
      }
      else
      {
        std::cout << "  ";
      }
      std::cout << petrov::calculateByTaylor(x, max, error);
      std::cout << "    |";
    }
    catch (const std::logic_error & e)
    {
      if (x >= 0.0)
      {
        std::cout << "\b";
      }
      std::cout << "<MATH_ERROR> |";
    }
}

#include "rowOutput.hpp"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdexcept>
#include "partOfTaylor.hpp"

void shramko::rowOutput(double i, size_t k, double error)
{
  const size_t width = std::strlen("<MATH ERROR>");

  std::cout << std::setw(width) << std::left << std::fixed << std::setprecision(7) << i;

  try
  {
    std::cout << std::setw(width) << std::left << std::fixed << std::setprecision(7) << shramko::partOfTaylor(i, k, error);
  }
  catch (const std::logic_error & e)
  {
    std::cout << std::setw(width) << std::left << std::fixed << std::setprecision(7) << "<MATH ERROR>";
  }

  std::cout << std::setw(width) << std::left << std::fixed << std::setprecision(7) << std::sin(i);

}

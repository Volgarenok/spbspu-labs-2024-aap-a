#include <iostream>
#include <stdexcept>
#include "table.hpp"
#include "partOfRow.hpp"

void shramko::table(double left, double right, size_t k)
{
  const double step = 1;
  const double error = 0.001;

  for (size_t i = left; i < right; i += step)
  {
    std::cout << i << "\t";
    try
    {
      std::cout << shramko::partOfRow(i, k, error) << "\t";
    }
    catch (const std::logic_error & e)
    {
      std::cout << "<MATH ERROR>" << "\t";
    }
    std::cout << std::sin(i) << "\n";
  }
}

#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <cstring>
#include "string.hpp"
#include "partOfRow.hpp"

void shramko::string(double i, size_t k, double error)
{
  const size_t width = std::strlen("<MATH ERROR>");

  std::cout << std::setw(width) << std::left << std::fixed << std::setprecision(7) << i;

  try
  {
    std::cout << std::setw(width) << std::left << std::fixed << std::setprecision(7) << shramko::partOfRow(i, k, error);
  }
  catch (const std::logic_error & e)
  {
    std::cout << std::setw(width) << std::left << std::fixed << std::setprecision(7) << "<MATH ERROR>";
  }

  try
  {
    std::cout << std::setw(width) << std::left << std::fixed << std::setprecision(7) << std::sin(i);
  }
  catch (const std::logic_error & e)
  {
    std::cout << std::setw(width) << std::left << std::fixed << std::setprecision(7) << "<MATH ERROR>";
  }

  std::cout << "\n";
}

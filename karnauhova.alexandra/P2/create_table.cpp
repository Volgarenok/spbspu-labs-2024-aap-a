#include "create_table.hpp"
#include "count_sin.hpp"
#include <iostream>
#include <iomanip>
#include <stdexcept>

void karnauhova::output_row(double x, size_t k, double error, size_t width)
{
  std::cout << std::setw(width) << x;
  std::cout << " ";
  try
  {
    std::cout << std::setw(width) << karnauhova::f(x, k, error);
  }
  catch (const std::logic_error & e)
  {
    std::cout << std::setw(width) << "<MATH ERROR>";
  }
  std::cout << std::setw(width) << karnauhova::stdf(x);
}

void karnauhova::output_table(double left, double right, double step, size_t k, double error, size_t width)
{
  for (auto i = left; i < right; i += step)
  {
    karnauhova::output_row(i, k, error, width);
    std::cout<<"\n";
  }
  karnauhova::output_row(right, k, error, width);
  std::cout<<"\n";
}

#include "output.hpp"
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <cstring>
#include "uno_div_cube.hpp"

void mozhegova::output_row(double i, size_t k, double error)
{
  const size_t SecColWidth = std::strlen("<MATH ERROR>") + 2;
  const size_t OtherCol = 12;
  std::cout.precision(3);
  std::cout << std::setw(OtherCol) << std::fixed << i << " ";
  try
  {
    std::cout << std::setw(SecColWidth) << mozhegova::uno_div_cube(i, k, error);
  }
  catch (const std::logic_error & e)
  {
    std::cout << std::setw(SecColWidth) << "<MATH ERROR>";
  }
  std::cout << " " << std::setw(OtherCol) << mozhegova::uno_div_cube_cmath(i);
}

void mozhegova::output_table(double left, double right, size_t k, double step, double error)
{
  for (double i = left; i < right; i += step)
  {
    mozhegova::output_row(i, k, error);
    std::cout << "\n";
  }
  mozhegova::output_row(right, k, error);
  std::cout << "\n";
}

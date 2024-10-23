#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "output.h"

void output_row(auto i, double taylor, double cmath)
{
  std::cout << std::setw(OtherCol) << i << " ";
  try
  {
    std::cout << std::setw(SecColWidth) << mozhegova::uno_div_cube(i, k, error);
  }
  catch (const std::logic_error & e)
  {
    std::cout << std::setw(SecColWidth) << "<MATH ERROR>";
  }
  std::cout << " " << std::setw(OtherCol) << mozhegova::uno_div_cube_cmath(i);
  std::cout << "\n";
}

void output_table(double left, double right, size_t k)
{
  for (auto i = left; i < right; i += step)
  {
    output_row(i, taylor, cmath);
  }
  output_row(right, taylor, cmath);
}
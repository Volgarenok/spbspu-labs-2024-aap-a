#include "output.hpp"
#include <iomanip>
#include <stdexcept>
#include <cstring>
#include <iostream>

void lebedev::output_raw(double x, size_t k, double error)
{
  const size_t SecondColumnWidth = std::strlen("<MATH ERROR>") + 4;
  const size_t OtherColumnsWidth = 10;
  std::cout.precision(3);
  std::cout << std::setw(OtherColumnsWidth) << std::fixed << x << ' ';
  try
  {
    std::cout << std::setw(SecondColumnWidth) << lebedev::sinus(x, k, error);
  }
  catch (const std::logic_error & e)
  {
    std::cout << std::setw(SecondColumnWidth) << "<MATH ERROR>";
  }
  std::cout << ' ' << std::setw(OtherColumnsWidth) << lebedev::sinus_cmath(x);
}

void lebedev::output_table(double left, double right, size_t k, double error, double step)
{
  for (double i = left; i < right; i += step)
  {
    lebedev::output_raw(i, k, error);
    std::cout << '\n';
  }
  lebedev::output_raw(right, k, error);
  std::cout << '\n';
}

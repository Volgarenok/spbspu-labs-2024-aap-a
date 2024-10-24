#include "output.hpp"
#include <iomanip>
#include <stdexcept>
#include <cstring>
#include <iostream>

void lebedev::output_raw(double x, size_t k, double error)
{
  const size_t SecondColWidth = std::strlen("<MATH ERROR>") + 4;
  const size_t OtherColWidth = 10;
  std::cout.precision(3);
  std::cout << std::setw(OtherColWidth) << std::fixed << x << ' ';
  try
  {
    std::cout << std::setw(SecondColWidth) << lebedev::sinus(x, k, error);
  }
  catch(const std::logic_error & e)
  {
    std::cout << std::setw(SecondColWidth) << "<MATH ERROR>";
  }
  std::cout << ' ' << std::setw(OtherColWidth) << lebedev::sinus_cmath(x);
  std::cout << '\n';
}

void lebedev::output_table(double left, double right, size_t k, double error, double step)
{
  for (double i = left; i < right; i += step)
  {
    lebedev::output_raw(i, k, error);
  }
  lebedev::output_raw(right, k, error);
}
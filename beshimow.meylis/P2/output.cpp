#include "table.hpp"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdexcept>
#include "taylor.hpp"

void beshimow::output(double x, size_t k, double error)
{
  constexpr const char * errormsg = "MATH ERROR";
  constexpr size_t second_column_width = std::strlen(errormsg) + 2;
  constexpr size_t others_columns = 10;
  size_t snd = second_column_width;
  size_t oth = others_columns;
  std::cout.precision(3);
  std::cout << std::setw(oth) << std::fixed << x << " ";
  try
  {
    std::cout << std::setw(snd) << sinTaylor(x, k, error);
  }
  catch (const std::logic_error & e)
  {
    std::cout << std::setw(snd) << "<MATH ERROR>";
  }
  std::cout << " " << std::setw(oth) << sinCmath(x);
}

void beshimow::output(double left, double right, size_t k, double error, double step)
{
  for (double i = left; i < right; i += step)
  {
    output(i, k, error);
    std::cout << "\n";
  }
  output(right, k, error);
  std::cout << "\n";
}

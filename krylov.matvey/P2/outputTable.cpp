#include "outputTable.hpp"
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include "calculateMathValues.hpp"

void krylov::lineOutput(double x, size_t max_terms_number, double error)
{
  std::cout << std::setw(12) << std::setprecision(2) << x;
  std::cout << std::fixed;
  std::cout << std::setw(12) << " ";
  try
  {
    std::cout << std::setw(12) << std::setprecision(5) << krylov::f(x, max_terms_number, error);
    std::cout << std::fixed;
  }
  catch (const std::logic_error& e)
  {
    std::cout << std::setw(12) << "<MATH_ERROR>";
  }
  std::cout << std::setw(12) << " " << krylov::sinx_div_x(x);
}

void krylov::tableOutput(double left_border, double right_border, size_t max_terms_number, double step, double error)
{
  for (auto i = left_border; i < right_border; i += step)
  {
    krylov::lineOutput(i, max_terms_number, error);
    std::cout << "\n";
  }
  krylov::lineOutput(right_border, max_terms_number, error);
}

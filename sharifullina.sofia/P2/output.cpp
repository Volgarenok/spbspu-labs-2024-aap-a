#include "output.hpp"
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <cstring>
#include "cos_expnegx.hpp"

void sharifullina::output_row(double i, size_t k, double error)
{
  const size_t WidthOfMathErr = std::strlen("<MATH ERROR>") + 2;
  const size_t WidthOfCol = 12;
  std::cout.precision(3);
  std::cout << std::setw(WidthOfCol) << std::fixed << i << " ";
  using FuncPtr = double(*)(double, size_t, double);
  FuncPtr funcs[] =
  {
    sharifullina::cos,
    sharifullina::exp_negx,
    sharifullina::cos_and_exp
  };
  for (size_t j = 0; j < 3; j++)
  {
    try
    {
      std::cout << std::setw(WidthOfMathErr) << funcs[j](i, k, error);
    }
    catch (const std::logic_error& e)
    {
      std::cout << std::setw(WidthOfMathErr) << "<MATH ERROR>";
    }
  }
  std::cout << " " << std::setw(WidthOfCol) << cos_cmath(i);
  std::cout << " " << std::setw(WidthOfCol) << exp_negx_cmath(i);
  std::cout << " " << std::setw(WidthOfCol) << cos_and_exp_cma(i);
}

void sharifullina::output_table(double left, double right, size_t k, double step, double error)
{
  for (double i = left; i < right; i += step)
  {
    output_row(i, k, error);
    std::cout << "\n";
  }
  output_row(right, k, error);
  std::cout << "\n";
}

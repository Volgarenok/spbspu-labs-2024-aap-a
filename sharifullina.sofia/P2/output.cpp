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
    try
    {
        std::cout << std::setw(WidthOfMathErr) << sharifullina::cos(i, k, error);
    }
    catch (const std::logic_error& e)
    {
        std::cout << std::setw(WidthOfMathErr) << "<MATH ERROR>";
    }
    try
    {
        std::cout << std::setw(WidthOfMathErr) << sharifullina::exp_negx(i, k, error);
    }
    catch (const std::logic_error& e)
    {
        std::cout << std::setw(WidthOfMathErr) << "<MATH ERROR>";
    }
    try
    {
        std::cout << std::setw(WidthOfMathErr) << sharifullina::cos(i, k, error) + sharifullina::exp_negx(i, k, error);
    }
    catch (const std::logic_error& e)
    {
        std::cout << std::setw(WidthOfMathErr) << "<MATH ERROR>";
    }

    std::cout << " " << std::setw(WidthOfCol) << sharifullina::cos_cmath(i);

    std::cout << " " << std::setw(WidthOfCol) << sharifullina::exp_negx_cmath(i);

    std::cout << " " << std::setw(WidthOfCol) << sharifullina::exp_negx_cmath(i) + cos_cmath(i);
}

void sharifullina::output_table(double left, double right, size_t k, double step, double error)
{
  for (double i = left; i < right; i += step)
  {
    sharifullina::output_row(i, k, error);
    std::cout << "\n";
  }
  sharifullina::output_row(right, k, error);
  std::cout << "\n";
}

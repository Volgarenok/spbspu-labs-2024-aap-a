#include "taylor.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <cstring>

void ivanova::output(double x, size_t k, double error)
{
  const size_t MathErr = std::strlen("<MATH ERROR>") + 3;
  const size_t Cols = 11;
  try
  {
    std::cout << std::setw(MathErr) << exp(x, k, error);
  }
  catch (const std::logic_error & e)
  {
    std::cout << std::setw(MathErr) << "<MATH ERROR>";
  }
  try
  {
    std::cout << std::setw(MathErr) << arctg(x, k, error);
  }
  catch (const std::logic_error& e)
  {
    std::cout << std::setw(MathErr) << "<MATH ERROR>";
  }
  try
  {
    std::cout << std::setw(MathErr) << exp(x, k, error) + arctg(x, k, error);
  }
  catch (const std::logic_error& e)
  {
    std::cout << std::setw(MathErr) << "<MATH ERROR>";
  }
  std::cout << " " << std::setw(Cols) << std_exp(x);
  std::cout << " " << std::setw(Cols) << std_arctg(x);
  std::cout << " " << std::setw(Cols) << std_exp(x) + std_arctg(x);
}

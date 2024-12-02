#include "taylor.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <cstring>

void ivanova::output(double x, size_t k, double error)
{
  const size_t mathErr = std::strlen("<MATH ERROR>") + 3;
  const size_t cols = 11;
  try
  {
    std::cout << std::setw(mathErr) << exp(x, k, error);
  }
  catch (const std::logic_error & e)
  {
    std::cout << std::setw(mathErr) << "<MATH ERROR>";
  }
  try
  {
    std::cout << std::setw(mathErr) << arctg(x, k, error);
  }
  catch (const std::logic_error& e)
  {
    std::cout << std::setw(mathErr) << "<MATH ERROR>";
  }
  try
  {
    std::cout << std::setw(mathErr) << exp(x, k, error) + arctg(x, k, error);
  }
  catch (const std::logic_error& e)
  {
    std::cout << std::setw(mathErr) << "<MATH ERROR>";
  }
  std::cout << " " << std::setw(cols) << std_exp(x);
  std::cout << " " << std::setw(cols) << std_arctg(x);
  std::cout << " " << std::setw(cols) << std_exp(x) + std_arctg(x);
}

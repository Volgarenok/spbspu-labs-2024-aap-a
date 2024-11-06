#include "brain.h"
#include <iostream>
#include <iomanip>
#include <cstring>
void bocharov::table(double number, size_t k, double error)
{
  std::cout << std::setw(15) << number;
  try
  {
    std::cout << std::setw(15) << bocharov::f(number, k, error);
  }
  catch (const std::logic_error &e)
  {
    std::cout << std::setw(15) << "Math error";
  }
  try
  {
    std::cout << std::setw(15) << bocharov::f2(number, k, error);
  }
  catch (const std::logic_error &e)
  {
    std::cout << std::setw(15) << "Math error";
  }
  try
  {
    std::cout << std::setw(15) << bocharov::f(number, k, error) + bocharov::f2(number, k, error);
  }
  catch (const std::logic_error &e)
  {
    std::cout << std::setw(15) << "Math error";
  }
  std::cout << std::setw(15) << bocharov::sqrt1_x(number);
  std::cout << std::setw(15) << bocharov::ln(number);
  std::cout << std::setw(15) << bocharov::sqrt1_x(number) + bocharov::ln(number) << "\n";
}

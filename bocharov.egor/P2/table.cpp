#include "brain.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <cstring>
void bocharov::table(double number, size_t k, double error)
{
  const char* errorm = "<MATH ERROR>";
  const size_t sec_column = std::strlen(errorm);
  const size_t oth_column = 10;
  int prec = std::cout.precision();
  std::cout << std::setw(oth_column) << std::fixed;
  std::cout << std::setprecision(2);
  std::cout << number << std::setprecision(prec) << "    ";
  try
  {
    std::cout << std::setw(oth_column) << bocharov::f(number, k, error) << "    ";
  }
  catch (const std::logic_error &e)
  {
    std::cout << std::setw(sec_column) << errorm << "    ";
  }
  std::cout << std::setw(oth_column) << bocharov::sqrt1_x(number) << '\n';
}

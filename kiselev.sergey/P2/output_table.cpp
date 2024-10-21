#include "function.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <cstring>
void kiselev::output_table(double number, size_t k, double error)
{
  int prec = std::cout.precision();
  std::cout << std::setw(oth_column) << std::fixed;
  std::cout << std::setprecision(2);
  std::cout << number << std::setprecision(prec) << "    ";
  try
  {
    std::cout << std::setw(oth_column) << kiselev::f(number, k, error) << "    ";
  }
  catch (std::logic_error& e)
  {
    std::cout << std::setw(sec_column) << errorm << "    ";
  }
  std::cout << std::setw(oth_column) << kiselev::sqr_unox(number) << '\n';
}

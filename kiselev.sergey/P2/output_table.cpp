#include "function.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>
void output_table(double number, size_t k, double error)
{
  int prec = std::cout.precision();
  std::cout << std::setw(oth_column) << std::fixed;
  std::cout << std::setprecision(2);
  std::cout << number << std::setprecision(prec) << "    ";
  try
  {
    std::cout << std::setw(oth_column) << f(number, k, error) << "    ";
  }
  catch (std::logic_error& e)
  {
    std::cout << std::setw(sec_column) << errorm << "    ";
  }
  catch (std::invalid_argument& e)
  {
    std::cout << std::setw(sec_column) << "ERROR\n";
  }
  std::cout << std::setw(oth_column) << sqr_unox(number) << '\n';
}

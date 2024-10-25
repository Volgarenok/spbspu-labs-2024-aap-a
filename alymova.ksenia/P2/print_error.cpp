#include "funcs.h"
#include <iomanip>
#include <iostream>
void alymova::print_error(const double x, const double math_func)
{
  std::cout << std::setw(15) << std::left << x;
  std::cout << std::setw(15) << std::left << "<MATH ERROR>";
  std::cout << std::setw(15) << std::left << math_func << "\n";
}

#include "taylor_table.h"
#include <iomanip>
#include <iostream>
void alymova::print_error(double x, double math_func)
{
  std::cout << std::setw(15) << std::left << x;
  std::cout << std::setw(15) << std::left << "<MATH ERROR>";
  std::cout << std::setw(15) << std::left << math_func;
}

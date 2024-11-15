#include "taylor_table.h"
#include <iostream>
#include <iomanip>
void alymova::print(double x, double taylor, double math_func)
{
  std::cout << std::setw(15) << std::left << x;
  std::cout << std::setw(15) << std::left << taylor;
  std::cout << std::setw(15) << std::left << math_func;
}

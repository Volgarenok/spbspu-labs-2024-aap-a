#include "taylor_table_funcs.h"
#include <iostream>
#include <iomanip>
void alymova::print(const double x, const double taylor, const double math_func)
{
  std::cout << std::setw(15) << std::left << x;
  std::cout << std::setw(15) << std::left << taylor;
  std::cout << std::setw(15) << std::left << math_func;
}

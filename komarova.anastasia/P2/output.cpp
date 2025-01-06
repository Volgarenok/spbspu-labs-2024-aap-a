#include "tableTeilor.h"
#include <iostream>
#include <iomanip>

void komarova::output(double x, double value, double y)
{
  std::cout << std::setw(20) << x;
  std::cout << std::setw(20) << value;
  std::cout << std::setw(20) << y;
  std::cout << "\n";
}

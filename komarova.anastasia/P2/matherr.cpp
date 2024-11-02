#include "tableTeilor.h"
#include <iostream>
#include <iomanip>

void komarova::matherr(double x, double y)
{
  std::cout << std::setw(20) << x;
  std::cout << std::setw(20) << "<MATH ERROR>";
  std::cout << std::setw(20) << y;
  std::cout << "\n";
}

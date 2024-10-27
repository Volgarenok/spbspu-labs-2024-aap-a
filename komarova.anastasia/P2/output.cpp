#include <iostream>
#include <iomanip>
#include "kola.h"

void komarova::output(double x, double value, double komarova::ln_Teilor(double x))
{
  std::cout << std::setw(20) << x;
  std::cout << std::setw(20) << value;
  std::cout << std::setw(20) << komarova::ln_Teilor(x) << "\n";
}


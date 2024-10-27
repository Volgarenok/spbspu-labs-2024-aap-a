#include "tableoutput.h"
#include <iostream>

void tkach::outputTable(double start, double end, size_t maxamount, const double error, const double step)
{
  constexpr double epcelon = 1e-6;
  for (auto i = start; i + epcelon < end; i += step)
  {
    tkach::outputRow(i, maxamount, error);
    std::cout << "\n";
  }
}

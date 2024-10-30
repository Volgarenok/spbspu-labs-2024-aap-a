#include "tableoutput.h"
#include <iostream>

void tkach::outputTable(const double start, const double end, const size_t maxamount, const double error, const double step)
{
  constexpr double epselon = 1e-6;
  for (auto i = start; i + epselon < end; i += step)
  {
    tkach::outputRow(i, maxamount, error);
    std::cout << "\n";
  }
  tkach::outputRow(end, maxamount, error);
  std::cout << "\n";
}

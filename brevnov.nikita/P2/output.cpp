#include "brevnov.hpp"
#include <cmath>
#include <stdexcept>
#include <cstring>
#include <iomanip>

void brevnov::outputing(const double left, const double right, const size_t k)
{
  constexpr double error = 0.001;
  constexpr double step = 0.05;
  for (auto i = left; i < right; i += step)
  {
    tablecheck(i, k, error);
  }
  tablecheck(right, k, error);
}

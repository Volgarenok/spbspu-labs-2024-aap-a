#include "taylor_table.h"
#include <stdexcept>
#include <cstddef>
double alymova::taylor_row(double x, size_t k, double error)
{
  double summ = x;
  double next = x;
  int denom = 3;
  for (size_t i = 1; i < k; i++)
  {
    next = next * x * x * (-1) / denom;
    summ += next;
    denom += 2;
  }
  if (std::abs(next) > error)
  {
    throw std::logic_error("math error");
  }
  else
  {
    return summ;
  }
}

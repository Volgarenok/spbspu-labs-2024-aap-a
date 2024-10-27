#include "Table.hpp"

void smirnov::outTable(double left, double right, size_t k, double error, double step)
{
  smirnov::outString(left, k, error);
  for (double i = left; i < right; i += step)
  {
    smirnov::outString(i, k, error);
  }
  smirnov::outString(right, k, error);
}

#include "taylor.hpp"

void sveshnikov::table(double left, double right, size_t k)
{
  const double error = 0.002;
  const double step = 0.06;
  for (auto i = left; i < right; i += step)
  {
    sveshnikov::row(i, k, error);
  }
  sveshnikov::row(right, k, error);
}

#include "taylor.hpp"

void sveshnikov::table(double left, double right, size_t k, const double error, const double step)
{
  for (auto i = left; i < right; i += step)
  {
    sveshnikov::row(i, k, error);
  }
  sveshnikov::row(right, k, error);
}

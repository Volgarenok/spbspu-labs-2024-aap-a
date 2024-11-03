#include "brain.h"
bool intervals(double x, size_t k, double error)
{
  bool sect = left <= -1 || left >= 1;
  sect = sect || right <= -1 || right >= 1;
  sect = sect || left > right;
  return sect;
}

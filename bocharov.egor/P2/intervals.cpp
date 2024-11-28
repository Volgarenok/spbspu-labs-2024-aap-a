#include "taylor.h"
bool bocharov:: intervals(double left, double right)
{
  bool sect = left <= -1 || left >= 1;
  sect = sect || right <= -1 || right >= 1;
  sect = sect || left > right;
  return sect;
}

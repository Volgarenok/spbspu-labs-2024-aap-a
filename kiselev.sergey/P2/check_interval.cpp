#include "taylor.h"
bool kiselev::check_interval(double left, double right)
{
  bool check_gap = left <= -1 || left >= 1;
  check_gap = check_gap || right >= 1 || right <= -1;
  check_gap = check_gap || right < left;
  return check_gap;
}

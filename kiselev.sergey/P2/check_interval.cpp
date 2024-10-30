#include "taylor.h"
bool kiselev::check_interval(double left, double right)
{
  bool check_left = left < -1 || left >= 1;
  bool check_right = right > 1 || right <= -1;
  bool check_gap = check_right || check_left || right < left;
  return check_gap;
}

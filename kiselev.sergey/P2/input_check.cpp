#include "taylor.h"
bool kiselev::input_check(double left, double right, int k)
{
  return (left < -0.5 || left >= 0.5 || right > 0.5 || right <= -0.5 || right < left || k > 10);
}

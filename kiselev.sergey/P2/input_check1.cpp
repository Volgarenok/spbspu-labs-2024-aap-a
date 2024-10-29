#include "taylor.h"
bool kiselev::input_check1(double left, double right)
{
  return (left < -0.5 || left >= 0.5 || right < left);
}

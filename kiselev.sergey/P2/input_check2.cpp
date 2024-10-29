#include "taylor.h"
bool kiselev::input_check2(double right, size_t k)
{
  return right > 0.5 || right <= -0.5 || k > 10;
}

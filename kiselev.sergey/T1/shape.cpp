#include "shape.hpp"
#include <stdexcept>
void kiselev::Shape::scaleWithCheck(double k)
{
  if (k <= 0)
  {
    throw std::logic_error("Incorrect scaling coefficent");
  }
  scale(k);
}

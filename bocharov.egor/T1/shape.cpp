#include "shape.hpp"
#include <stdexcept>
void bocharov::Shape::scaleCheck(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Incorrect scaling coefficent");
  }
  scale(k);
}

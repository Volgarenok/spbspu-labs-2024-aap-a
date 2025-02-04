#include "shape.hpp"
#include <stdexcept>
void bocharov::Shape::scaleCheck(double k)
{
  if (k <= 0)
  {
    throw std::logic_error("Incorrect scaling coefficent");
  }
  scale(k);
}

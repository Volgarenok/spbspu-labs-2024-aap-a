#include "shape.hpp"
#include <stdexcept>

void dribas::Shape::scale(double ratio)
{
  if (ratio <= 0) {
    throw std::invalid_argument("under zero ratio with scale");
  }
  scaleSilent(ratio);
}

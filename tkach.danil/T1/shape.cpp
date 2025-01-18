#include "shape.hpp"
#include <stdexcept>

void tkach::Shape::scale(double multiplier)
{
  if (multiplier <= 0)
  {
    throw std::logic_error("Error: not positive coef");
  }
  doUnsafeScale(multiplier);
}

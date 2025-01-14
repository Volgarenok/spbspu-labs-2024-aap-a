#include "shape.hpp"
#include <stdexcept>

void sveshnikov::Shape::scale(double k)
{
  if (k < 0)
  {
    throw std::logic_error("ERROR: zoom coefficient must be positive!");
  }
  unsafe_scale(k);
}

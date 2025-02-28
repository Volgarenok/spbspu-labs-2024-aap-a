#include "shape.hpp"
#include <stdexcept>

void asafov::Shape::scale(double scale)
{
  if (scale <= 0)
  {
    throw std::logic_error("incorrect scale");
  }
  unsafeScale(scale);
}

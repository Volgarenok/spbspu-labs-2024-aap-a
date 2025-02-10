#include "shape.hpp"
#include <stdexcept>

void savintsev::Shape::scale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("invalid ratio");
  }
  unsafeScale(k);
}

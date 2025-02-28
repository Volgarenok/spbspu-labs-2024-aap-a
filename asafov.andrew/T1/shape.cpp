#include "shape.hpp"
#include <stdexcept>

void asafov::Shape::scale(double k)
{
  if (k <= 0)
  {
    throw std::logic_error("incorrect scale");
  }
  unsafeScale(k);
}

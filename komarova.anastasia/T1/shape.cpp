#include "shape.hpp"
#include <stdexcept>

void komarova::Shape::scale(double coef)
{
  if (coef <= 0)
  {
    throw std::logic_error("incorrect coef");
  }
  unsafeScale(coef);
}

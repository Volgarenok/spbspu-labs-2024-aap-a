#include "shape.hpp"
#include <stdexcept>

void duhanina::Shape::scale(double k)
{
  if (k <= 0)
  {
    throw std::logic_error("Incorrect coef");
  }
  scaleUnsafe(k);
}

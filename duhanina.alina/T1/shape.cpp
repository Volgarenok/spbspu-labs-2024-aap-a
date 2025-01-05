#include "shape.hpp"
#include <stdexcept>

void duhanina::Shape::scaleCheck(double k)
{
  if (k <= 0)
  {
    throw std::logic_error("Incorrect coef");
  }
  scale(k);
}

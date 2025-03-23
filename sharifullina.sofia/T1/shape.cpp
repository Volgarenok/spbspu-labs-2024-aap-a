#include "shape.hpp"
#include <stdexcept>

void sharifullina::Shape::scale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Incorrect scale");
  }
  scaleWithoutCheck(k);
}

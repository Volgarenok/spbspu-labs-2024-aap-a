#include "shape.hpp"
#include <stdexcept>

void maslov::Shape::scale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Incorrect scale factor");
  }
  scaleWithoutCheck(k);
}

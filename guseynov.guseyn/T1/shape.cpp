#include "shape.hpp"
#include <stdexcept>

void guseynov::Shape::scale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Incorrect scale factor");
  }
  scaleWithoutCheck(k);
}

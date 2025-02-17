#include "shape.hpp"
#include <stdexcept>

void mozhegova::Shape::scale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Incorrect scale");
  }
  scaleImpl(k);
}

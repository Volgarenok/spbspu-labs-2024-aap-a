#include "shape.hpp"
#include <stdexcept>

void zakirov::Shape::scale(double k)
{
  if (k <= 0)
  {
    throw std::logic_error("Incorrect scale coefficient");
  }

  scaleUnsafely(k);
}

#include "shape.hpp"
#include <stdexcept>

void zakirov::Shape::scaleWithCheck(double k)
{
  if (k <= 0)
  {
    throw std::logic_error("Incorrect scale coefficient");
  }

  scale(k);
}

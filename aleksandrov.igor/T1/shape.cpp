#include "shape.hpp"
#include <stdexcept>

void aleksandrov::Shape::scale(double k)
{
  if (k <= 0)
  {
    throw std::logic_error("Incorrect coefficient");
  }
  unsafeScale(k);
}


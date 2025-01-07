#include "shape.hpp"
#include <stdexcept>

void lanovenko::Shape::scale(double k)
{
  if (k < 0)
  {
    throw std::logic_error("Scaling coeficient is negative\n");
  }
  unsScale(k);
}

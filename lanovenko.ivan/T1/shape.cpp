#include "shape.hpp"
#include <stdexcept>

void lanovenko::Shape::scale(double k)
{
  unsafeScale(k);
}

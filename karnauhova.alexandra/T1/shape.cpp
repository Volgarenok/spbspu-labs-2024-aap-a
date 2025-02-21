#include "shape.hpp"
#include <stdexcept>

void karnauhova::Shape::scale_with_check(double k)
{
  if (k <= 0)
  {
    throw std::logic_error("Error: incorrect coef");
  }
  scale(k);
}

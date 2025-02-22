#include "shape.hpp"
#include <stdexcept>

void averenkov::Shape::scale(double factor)
{
  if (factor <= 0)
  {
    throw std::logic_error("Incorrect scale");
  }
  scaleNonChecked(factor);
}

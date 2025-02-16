#include "shape.hpp"
void gavrilova::Shape::scale(double k)
{
  if (k <= 0) {
    throw std::logic_error("Error! The coefficient must be positive.");
  }
  scaleWithoutCheck(k);
}

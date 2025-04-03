#include "shape.hpp"
#include "shapeUtils.hpp"

void kushekbaev::Shape::scale(double scaleCoeff)
{
  if (scaleCoeff <= 0)
  {
    throw std::logic_error("Scale coefficient should be greater than zero");
  }
  doUnsafeScale(scaleCoeff);
}

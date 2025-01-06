#include "shape.hpp"
#include <stdexcept>

void kizhin::Shape::scale(double scalingFactor)
{
  throwIfInvalidScalingFractor(scalingFactor);
  scaleWithoutChecks(scalingFactor);
}

void kizhin::Shape::throwIfInvalidScalingFractor(double scalingFactor)
{
  if (scalingFactor <= 0.0) {
    throw std::logic_error("Failed to scale");
  }
}


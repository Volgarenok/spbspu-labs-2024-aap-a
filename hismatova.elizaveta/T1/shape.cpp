#include "shape.hpp"
#include <stdexcept>

void hismatova::Shape::scale_(double index)
{
  if (index <= 0)
  {
    throw std::invalid_argument("Scale factor must be positive.");
  }
  scale(index);
}

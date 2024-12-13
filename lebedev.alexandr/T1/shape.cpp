#include "shape.hpp"

void lebedev::deleteShapePtr(lebedev::Shape** shps, size_t count)
{
  for (size_t i = 0; i < count; ++i)
  {
    delete shps[i];
  }
}

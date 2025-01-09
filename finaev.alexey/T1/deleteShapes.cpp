#include "shape.hpp"

void finaev::deleteShapes(Shape** shapes, const size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    delete shapes[i];
  }
}

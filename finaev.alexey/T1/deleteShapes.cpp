#include "shape.h"

void finaev::deleteShapes(finaev::Shape** shapes, size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    delete shapes[i];
  }
}

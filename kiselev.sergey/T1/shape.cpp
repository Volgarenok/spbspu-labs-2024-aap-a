#include "shape.hpp"
void kiselev::destroyShapePtr(Shape** shapes, size_t count)
{
  for (size_t i = 0; i < count; ++i)
  {
    delete shapes[i];
  }
}

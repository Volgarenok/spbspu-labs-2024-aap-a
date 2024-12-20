#include "scaling.h"
void scaling(Shape* shapes[], size_t shapeCount, const Point& center, double factor)
{
  for (size_t i = 0; i < shapeCount; ++i)
  {
    shapes[i]->scale(center, factor);
  }
}

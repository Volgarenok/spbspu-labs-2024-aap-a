#include "scaling.hpp"
#include <iostream>

void cherkasov::scaling(Shape* shapes[], size_t shapeCount, point_t p, double scalingFactor)
{
  if (scalingFactor <= 0)
  {
    std::cerr << "Error: scalingFactor must be positive.\n";
    return;
  }
  for (size_t i = 0; i < shapeCount; i++)
  {
    point_t startPoint = shapes[i]->getFrameRect().pos;
    shapes[i]->move(p);
    point_t newPoint = shapes[i]->getFrameRect().pos;
    point_t newVector;
    newVector.x = (newPoint.x - startPoint.x);
    newVector.y = (newPoint.y - startPoint.y);
    shapes[i]->scale(scalingFactor);
    newVector.x *= scalingFactor;
    newVector.y *= scalingFactor;
    shapes[i]->move(-newVector.x, -newVector.y);
  }
}

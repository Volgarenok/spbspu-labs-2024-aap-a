#include "scaling.hpp"

void cherkasov::scaling(Shape* shapes[], size_t shapeCount, point_t p, double scalingFactor)
{
  for (size_t i = 0; i < shapeCount; i++)
  {
    point_t startPoint = shapes[i]->getFrameRect().pos;
    shapes[i]->move(p);
    point_t newPoint = shapes[i]->getFrameRect().pos;
    point_t newVector;
    newVector.x = (newPoint.x - startPoint.x) * scalingFactor;
    newVector.y = (newPoint.y - startPoint.y) * scalingFactor;
    shapes[i]->scale(scalingFactor);
    shapes[i]->move(-newVector.x, -newVector.y);
  }
}

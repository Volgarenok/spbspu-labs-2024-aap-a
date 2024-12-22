#include "scaling.h"
void cherkasov::scaling(Shape* shapes[], size_t shapeCount, point_t p, double scalingFactor)
{
  for (size_t i = 0; i < shapeCount; i++)
  {
    point_t startPoint = shapes[i]->getFrameRect().pos;
    shapes[i]->move(p);
    point_t newPos = shapes[i]->getFrameRect().pos;
    point_t vector;
    vector.x = (newPos.x - startPoint.x) * scalingFactor;
    vector.y = (newPos.y - startPoint.y) * scalingFactor;
    shapes[i]->scale(scalingFactor);
    shapes[i]->move(-vector.x, -vector.y);
  }
}

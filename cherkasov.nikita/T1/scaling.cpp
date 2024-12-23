#include "scaling.h"

void cherkasov::scaling(Shape* shapes[], size_t shapeCount, point_t p, double scalingFactor)
{
  for (size_t i = 0; i < shapeCount; i++)
  {
    point_t startPoint = shapes[i]->getFrameRect().pos;
    shapes[i]->move(p);
    point_t vector;
    vector.x = (startPoint.x - p.x) * (1 - scalingFactor);
    vector.y = (startPoint.y - p.y) * (1 - scalingFactor);
    shapes[i]->scale(scalingFactor);
    shapes[i]->move(-vector.x, -vector.y);
  }
}

#include "scale.h"

void finaev::scale(Shape** shapes, size_t size, point_t scaleCenter, double k)
{
  for (size_t i = 0; i < size; i++)
  {
    point_t c = shapes[i]->getFrameRect().pos;
    shapes[i]->move(scaleCenter);
    point_t new_c = shapes[i]->getFrameRect().pos;
    shapes[i]->scale(k);
    point_t offset;
    offset.x = (new_c.x - c.x) * k;
    offset.y = (new_c.y - c.y) * k;
    shapes[i]->move(-offset.x, -offset.y);
  }
}

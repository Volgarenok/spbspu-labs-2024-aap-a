#include "shape_scale.hpp"

void rychkov::scale(Shape* shape, double coef, point_t scaleCenter)
{
  rectangle_t tempFrame = shape->getFrameRect();
  shape->scale(coef);
  double deltaX = (tempFrame.pos.x - scaleCenter.x) * (coef - 1);
  double deltaY = (tempFrame.pos.y - scaleCenter.y) * (coef - 1);
  shape->move(deltaX, deltaY);
}

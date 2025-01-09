#include "shape.hpp"

#include <stdexcept>

void rychkov::Shape::scale(double coef)
{
  if (coef <= 0)
  {
    throw std::invalid_argument("scale can't be executed with non-positive coefficient");
  }
  unsafeScale(coef);
}
void rychkov::scale(Shape* shape, double coef, point_t scaleCenter)
{
  if (coef <= 0)
  {
    throw std::invalid_argument("scale can't be executed with non-positive coefficient");
  }
  unsafeScale(shape, coef, scaleCenter);
}
void rychkov::unsafeScale(Shape* shape, double coef, point_t scaleCenter) noexcept
{
  rectangle_t startFrame = shape->getFrameRect();
  shape->move(scaleCenter);
  rectangle_t scalePosFrame = shape->getFrameRect();
  shape->unsafeScale(coef);
  double deltaX = (startFrame.pos.x - scalePosFrame.pos.x) * coef;
  double deltaY = (startFrame.pos.y - scalePosFrame.pos.y) * coef;
  shape->move(deltaX, deltaY);
}

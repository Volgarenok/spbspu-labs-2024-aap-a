#include "shape.hpp"

#include <stdexcept>

void rychkov::Shape::scale(double coef)
{
  validateScaleCoefficient(coef);
  unsafeScale(coef);
}
void rychkov::scale(Shape* shape, double coef, point_t scaleCenter)
{
  validateScaleCoefficient(coef);
  unsafeScale(shape, coef, scaleCenter);
}
void rychkov::unsafeScale(Shape* shape, double coef, point_t scaleCenter) noexcept
{
  point_t startPos = shape->getFrameRect().pos;
  shape->move(scaleCenter);
  point_t scalePos = shape->getFrameRect().pos;
  shape->unsafeScale(coef);
  double deltaX = (startPos.x - scalePos.x) * coef;
  double deltaY = (startPos.y - scalePos.y) * coef;
  shape->move(deltaX, deltaY);
}
void rychkov::validateScaleCoefficient(double coef)
{
  if (coef <= 0)
  {
    throw std::invalid_argument("scale can't be executed with non-positive coefficient");
  }
}

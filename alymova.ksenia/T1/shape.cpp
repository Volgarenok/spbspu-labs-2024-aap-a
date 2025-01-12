#include "shape.hpp"
#include <stdexcept>
#include <cmath>
#include <cstddef>
void alymova::Shape::scale(double ratio)
{
  alymova::checkRatioScale(ratio);
  unsafeScale(ratio);
}
void alymova::scale(CompositeShape& shapes, point_t s, double ratio)
{
  checkRatioScale(ratio);
  unsafeScale(shapes, s, ratio);
}
void alymova::unsafeScaleOne(Shape* shape, point_t s, double ratio)
{
  rectangle_t old_rectangle = shape->getFrameRect();
  shape->move(s);
  point_t shift_point = {getShiftFrameRect(old_rectangle, shape->getFrameRect())};
  shape->unsafeScale(ratio);
  shift_point *= ratio;
  shape->move(-shift_point.x, -shift_point.y); 
}
void alymova::unsafeScale(CompositeShape& shapes, point_t s, double ratio)
{
  for (size_t i = 0; i < shapes.size(); i++)
  {
    unsafeScaleOne(shapes[i], s, ratio);
  }
}
void alymova::checkRatioScale(double ratio)
{
  if (ratio <= 0)
  {
    throw std::invalid_argument("The scale ratio should be positive");
  }
  if (ratio == 1)
  {
    return;
  }
}

constexpr double inaccuracy = 0.0000000001;
double alymova::getVector(point_t p1, point_t p2) noexcept
{
  return std::sqrt(std::pow(p1.x - p2.x, 2) + std::pow(p1.y - p2.y, 2));
}
bool alymova::isRectanglurTriangle(point_t p1, point_t p2, point_t p3) noexcept
{
  if (std::abs(std::pow(getVector(p2, p3), 2) + std::pow(getVector(p1, p3), 2) - std::pow(getVector(p1, p2), 2)) < inaccuracy)
  {
    return true;
  }
  return false;
}

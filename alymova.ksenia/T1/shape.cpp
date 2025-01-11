#include "shape.hpp"
#include <stdexcept>
#include <cmath>
#include <cstddef>
void alymova::Shape::scale(double ratio)
{
  alymova::checkRatioScale(ratio);
  unsafeScale(ratio);
}
void alymova::scale(Shape** shapes, size_t size, point_t s, double ratio)
{
  checkRatioScale(ratio);
  unsafeScale(shapes, size, s, ratio);
}
void alymova::unsafeScale(Shape** shapes, size_t size, point_t s, double ratio)
{
  for (size_t i = 0; i < size; i++)
  {
    rectangle_t old_rectangle = {shapes[i]->getFrameRect()};
    shapes[i]->move(s);
    point_t shift_point = {getShiftFrameRect(old_rectangle, shapes[i]->getFrameRect())};
    shapes[i]->unsafeScale(ratio);
    shift_point *= ratio;
    shapes[i]->move(-shift_point.x, -shift_point.y);
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

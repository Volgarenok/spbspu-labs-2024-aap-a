#include "shapesProcess.hpp"
#include <stdexcept>
#include <cmath>
#include <limits>
#include "shape.hpp"
#include "base-types.hpp"
constexpr double inaccuracy = 0.0000000001;
void alymova::scale(Shape** shapes, point_t s, double ratio)
{
  if (ratio <= 0)
  {
    throw std::invalid_argument("The scale ratio should be positive");
  }
  if (ratio == 1)
  {
    return;
  }
  for (size_t i = 0; shapes[i] != nullptr; i++) //if size == capacity
  {
    rectangle_t old_rectangle = {shapes[i]->getFrameRect()};
    shapes[i]->move(s);
    point_t shift_point = {getShiftFrameRect(old_rectangle, shapes[i]->getFrameRect())};
    shapes[i]->scale(ratio);
    shift_point *= ratio;
    shapes[i]->move(-shift_point.x, -shift_point.y);
  }
}
double alymova::getVector(point_t p1, point_t p2)
{
  return std::sqrt(std::pow(p1.x - p2.x, 2) + std::pow(p1.y - p2.y, 2));
}
bool alymova::isRectanglurTriangle(point_t p1, point_t p2, point_t p3)
{
  if (std::abs(std::pow(getVector(p2, p3), 2) + std::pow(getVector(p1, p3), 2) - std::pow(getVector(p1, p2), 2)) < inaccuracy)
  {
    return true;
  }
  return false;
}

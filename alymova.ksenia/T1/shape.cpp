#include "shape.hpp"
#include <stdexcept>
void alymova::Shape::scale(double ratio)
{
  alymova::checkRatioScale(ratio);
  unsafeScale(ratio);
}
void alymova::scale(Shape** shapes, point_t s, double ratio)
{
  checkRatioScale(ratio);
  unsafeScale(shapes, s, ratio);
}
void alymova::unsafeScale(Shape** shapes, point_t s, double ratio)
{
  for (size_t i = 0; shapes[i] != nullptr; i++) //if size == capacity
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
#include "circle.hpp"
#include <cmath>
#include <stdexcept>
constexpr double PI = std::acos(-1.0);
alymova::Circle::Circle(point_t pos, double radius):
  pos_(pos),
  radius_(1),
  frame_rect_()
{
  if (radius <= 0)
  {
    throw std::logic_error("Incorrect description of the shape");
  }
  radius_ = radius;
  frame_rect_ = rectangle_t(point_t(pos_.getX() - radius, pos_.getY() - radius), point_t(pos_.getX() + radius, pos_.getY() + radius));
}
double alymova::Circle::getArea() const
{
  return PI * radius_ * radius_;
}
alymova::rectangle_t alymova::Circle::getFrameRect() const
{
  return frame_rect_;
}
void alymova::Circle::move(double shift_x, double shift_y)
{
  point_t shift_point(shift_x, shift_y);
  pos_ += shift_point;
  frame_rect_.move(shift_x, shift_y);
}
void alymova::Circle::move(point_t point)
{
  double shift_x = point.getX() - pos_.getX();
  double shift_y = point.getY() - pos_.getY();
  move(shift_x, shift_y);
}
void alymova::Circle::scale(double ratio)
{
  if (ratio <= 0)
  {
    throw std::invalid_argument("The scale ratio should be positive");
  }
  if (ratio == 1)
  {
    return;
  }
  radius_ *= ratio;
  frame_rect_.scale(ratio);
}
alymova::Shape* alymova::Circle::clone() const
{
  Circle* circle = nullptr;
  try
  {
    circle = new Circle(pos_, radius_);
    Shape* shape = circle;
    return shape;
  }
  catch (const std::bad_alloc& e)
  {
    delete circle;
    throw;
  }
}

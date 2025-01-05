#include "base-types.hpp"
#include <stdexcept>
alymova::point_t::point_t(double x, double y):
  x(x),
  y(y)
{}
alymova::point_t::point_t(const point_t& point):
  x(point.x),
  y(point.y)
{}
alymova::point_t::point_t(const point_t&& point):
  x(point.x),
  y(point.y)
{}
alymova::point_t alymova::point_t::operator=(const point_t& point)
{
  x = point.x;
  y = point.y;
  return *this;
}
alymova::point_t alymova::point_t::operator+=(point_t shift_point)
{
  x += shift_point.x;
  y += shift_point.y;
  return *this;
}
alymova::point_t alymova::point_t::operator*=(double ratio)
{
  x *= ratio;
  y *= ratio;
  return *this;
}
bool alymova::point_t::operator<(point_t p2)
{
  if (x < p2.x && y < p2.y)
  {
    return true;
  }
  return false;
}
double alymova::point_t::getX() const
{
  return x;
}
double alymova::point_t::getY() const
{
  return y;
}
alymova::rectangle_t::rectangle_t(point_t low_left, point_t upp_right):
  low_left_(low_left),
  upp_right_(upp_right),
  width(upp_right_.x - low_left_.x),
  height(upp_right_.y - low_left_.y),
  pos(point_t((low_left_.x + width / 2), (upp_right_.y - height / 2))),
  shift_point_()
{}
alymova::rectangle_t::rectangle_t(rectangle_t& rect):
  low_left_(rect.low_left_),
  upp_right_(rect.upp_right_),
  width(upp_right_.x - low_left_.x),
  height(upp_right_.y - low_left_.y),
  pos(point_t((low_left_.x + width / 2), (upp_right_.y - height / 2))),
  shift_point_()
{}
alymova::rectangle_t alymova::rectangle_t::operator=(const rectangle_t& rect)
{
  width = rect.width;
  height = rect.height;
  pos = rect.pos;
  shift_point_ = rect.shift_point_;
  return *this;
}
double alymova::rectangle_t::getArea() const
{
  return width * height;
}
void alymova::rectangle_t::move(double shift_x, double shift_y)
{
  shift_point_ = point_t(shift_x, shift_y);
  pos += shift_point_;
  low_left_ += shift_point_;
  upp_right_ += shift_point_;
}
alymova::point_t alymova::rectangle_t::getShift() const
{
  return shift_point_;
}
void alymova::rectangle_t::scale(double ratio)
{
  if (ratio <= 0)
  {
    throw std::invalid_argument("The scale ratio should be positive");
  }
  if (ratio == 1)
  {
    return;
  }
  low_left_ += (point_t(0.5 * (width - ratio * width), 0.5 * (height - ratio * height)));
  upp_right_ += (point_t(0.5 * (ratio * width - width), 0.5 * (ratio * height - height)));
  width *= ratio;
  height *= ratio;
}
alymova::point_t alymova::rectangle_t::getLowLeft() const
{
  return low_left_;
}
alymova::point_t alymova::rectangle_t::getUppRight() const
{
  return upp_right_;
}

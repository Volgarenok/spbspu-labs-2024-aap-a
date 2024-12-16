#include "base-types.hpp"
alymova::point_t::point_t(double x, double y):
  x_(x),
  y_(y)
{}
alymova::point_t::point_t(const point_t& point):
  x_(point.x_),
  y_(point.y_)
{}
alymova::point_t::point_t(point_t&& point):
  x_(point.x_),
  y_(point.y_)
{}
alymova::point_t alymova::point_t::operator=(const point_t& point)
{
  x_ = point.x_;
  y_ = point.y_;
  return *this;
}
alymova::point_t alymova::point_t::operator+=(point_t shift_point)
{
  x_ += shift_point.x_;
  y_ += shift_point.y_;
  return *this;
}
alymova::point_t alymova::point_t::operator*=(double ratio)
{
  x_ *= ratio;
  y_ *= ratio;
  return *this;
}
bool alymova::point_t::operator<(point_t p2)
{
  if (x_ < p2.x_ && y_ < p2.y_)
  {
    return true;
  }
  return false;
}
double alymova::point_t::getX() const
{
  return x_;
}
double alymova::point_t::getY() const
{
  return y_;
}
alymova::rectangle_t::rectangle_t(point_t low_left, point_t upp_right):
  low_left_(low_left),
  upp_right_(upp_right),
  width_(upp_right_.getX() - low_left_.getX()),
  height_(upp_right_.getY() - low_left_.getY()),
  pos_(point_t((low_left_.getX() + width_ / 2), (upp_right_.getY() - height_ / 2))),
  shift_point_()
{}
double alymova::rectangle_t::getArea() const
{
  return width_ * height_;
}
void alymova::rectangle_t::move(double shift_x, double shift_y)
{
  shift_point_ = point_t(shift_x, shift_y);
  pos_ += shift_point_;
  low_left_ += shift_point_;
  upp_right_ += shift_point_;
}
alymova::point_t alymova::rectangle_t::getShift() const
{
  return shift_point_;
}
void alymova::rectangle_t::scale(double ratio)
{
  if (ratio == 1)
  {
    return;
  }
  low_left_ += (point_t(0.5 * (width_ - ratio * width_), 0.5 * (height_ - ratio * height_)));
  upp_right_ += (point_t(0.5 * (ratio * width_ - width_), 0.5 * (ratio * height_ - height_)));
  width_ *= ratio;
  height_ *= ratio;
}
alymova::point_t alymova::rectangle_t::getLowLeft() const
{
  return low_left_;
}
alymova::point_t alymova::rectangle_t::getUppRight() const
{
  return upp_right_;
}

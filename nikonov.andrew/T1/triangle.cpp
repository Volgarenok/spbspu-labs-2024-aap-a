#include "triangle.hpp"
#include <iostream>
#include "base-types.hpp"
nikonov::Triangle::Triangle(point_t A, point_t B, point_t C):
  A_(A),
  B_(B),
  C_(C)
{}
float nikonov::Triangle::getArea() const
{
  rectangle_t tempRect = getFrameRect();
  return (tempRect.height_ * tempRect.width_) / 2;
}
nikonov::point_t nikonov::Triangle::getCenterOfGravity() const
{
  return point_t((A_.x_ + B_.x_ + C_.x_) / 3, ((A_.y_ + B_.y_ + C_.y_) / 3));
}
nikonov::rectangle_t nikonov::Triangle::getFrameRect() const
{
  float tempX = (A_.x_ > B_.x_ ? A_.x_ : B_.x_);
  float maxX = (C_.x_ > tempX ? C_.x_ : tempX);
  float tempY = (A_.y_ > B_.y_ ? A_.y_ : B_.y_);
  float maxY = (C_.y_ > tempY ? C_.y_ : tempY);
  tempX = (A_.x_ < B_.x_ ? A_.x_ : B_.x_);
  float minX = (C_.x_ < tempX ? C_.x_ : tempX);
  tempY = (A_.y_ < B_.y_ ? A_.y_ : B_.y_);
  float minY = (C_.y_ < tempY ? C_.y_ : tempY);
  return rectangle_t(point_t(minX, minY), point_t(maxX, maxY));
}
void nikonov::Triangle::move(point_t newPos)
{
  point_t center = getCenterOfGravity();
  float diffX = newPos.x_ - center.x_;
  float diffY = newPos.y_ - center.y_;
  move(diffX, diffY);
}
void nikonov::Triangle::move(float x, float y)
{
  A_.x_ += x;
  B_.x_ += x;
  C_.x_ += x;
  A_.y_ += y;
  B_.y_ += y;
  C_.y_ += y;
}
void nikonov::Triangle::scale(float k)
{
  if (k <= 0)
  {
    std::cerr << "Scale denied: k must be more than zero\n";
    return;
  }
  point_t center = getCenterOfGravity();
  A_.x_ = center.x_ + (A_.x_ - center.x_) * k;
  A_.y_ = center.y_ + (A_.y_ - center.y_) * k;
  B_.x_ = center.x_ + (B_.x_ - center.x_) * k;
  B_.y_ = center.y_ + (B_.y_ - center.y_) * k;
  C_.x_ = center.x_ + (C_.x_ - center.x_) * k;
  C_.y_ = center.y_ + (C_.y_ - center.y_) * k;
}

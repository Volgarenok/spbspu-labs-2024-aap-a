#include "rectangle.hpp"
#include <iostream>
#include "base-types.hpp"
nikonov::Rectangle::Rectangle(point_t lbp, point_t rtp):
  lbp_(lbp),
  rtp_(rtp)
{}
float nikonov::Rectangle::getArea() const
{
  rectangle_t tempRect = getFrameRect();
  return (tempRect.height_ * tempRect.width_);
}
nikonov::rectangle_t nikonov::Rectangle::getFrameRect() const
{
  return rectangle_t(lbp_, rtp_);
}
void nikonov::Rectangle::move(point_t newPos)
{
  rectangle_t crntRect = getFrameRect();
  float diffX = newPos.x_ - crntRect.pos_.x_;
  float diffY = newPos.y_ - crntRect.pos_.y_;
  move(diffX, diffY);
}
void nikonov::Rectangle::move(float x, float y)
{
  lbp_.x_ += x;
  rtp_.x_ += x;
  lbp_.y_ += y;
  rtp_.y_ += y;
}
void nikonov::Rectangle::scale(float k)
{
  if (k <= 0)
  {
    std::cerr << "Scale denied: k must be more than zero\n";
    return;
  }
  rectangle_t crntRect = getFrameRect();
  crntRect.width_ *= k;
  crntRect.height_ *= k;
  float newlbpX = crntRect.pos_.x_ - crntRect.width_ / 2;
  float newlbpY = crntRect.pos_.y_ - crntRect.height_ / 2;
  float newrtpX = crntRect.pos_.x_ + crntRect.width_ / 2;
  float newrtpY = crntRect.pos_.y_ + crntRect.height_ / 2;
  lbp_ = point_t(newlbpX, newlbpY);
  rtp_ = point_t(newrtpX, newrtpY);
}

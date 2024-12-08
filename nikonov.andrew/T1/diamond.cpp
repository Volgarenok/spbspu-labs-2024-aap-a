#include "diamond.hpp"
#include <iostream>
#include "base-types.hpp"
nikonov::Diamond::Diamond(point_t topP, point_t rightP, point_t midP):
  topP_(topP),
  rightP_(rightP),
  midP_(midP)
{}
float nikonov::Diamond::getArea() const
{
  rectangle_t tempRect = getFrameRect();
  return (tempRect.height_ * tempRect.width_) / 2;
}
nikonov::rectangle_t nikonov::Diamond::getFrameRect() const
{
  point_t rtp(rightP_.x_, topP_.y_);
  point_t lbp(midP_.x_ - rightP_.x_, midP_.y_ - topP_.y_);
  return rectangle_t(lbp, rtp);
}
void nikonov::Diamond::move(point_t newPos)
{
  rectangle_t crntRect = getFrameRect();
  float diffX = newPos.x_ - crntRect.pos_.x_;
  float diffY = newPos.y_ - crntRect.pos_.y_;
  move(diffX, diffY);
}
void nikonov::Diamond::move(float x, float y)
{
  topP_.x_ += x;
  midP_.x_ += x;
  rightP_.x_ += x;
  topP_.y_ += y;
  midP_.y_ += y;
  rightP_.y_ += y;
}
void nikonov::Diamond::scale(float k)
{
  if (k <= 0)
  {
    std::cerr << "Scale denied: k must be more than zero\n";
    return;
  }
  rectangle_t crntRect = getFrameRect();
  crntRect.width_ *= k;
  crntRect.height_ *= k;
  float newTopX = crntRect.pos_.x_ + crntRect.width_ / 2;
  float newTopY = crntRect.pos_.y_ + crntRect.height_ / 2;
  float newRightX = crntRect.pos_.x_ + crntRect.width_ / 2;
  float newRightY = crntRect.pos_.y_ + crntRect.height_ / 2;
  topP_ = point_t(newTopX, newTopY);
  rightP_ = point_t(newRightX, newRightY);
}

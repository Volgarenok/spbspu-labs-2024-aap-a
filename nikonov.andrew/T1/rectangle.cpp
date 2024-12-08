#include "rectangle.hpp"
#include "base-types.hpp"
nikonov::Rectangle::Rectangle(point_t lbp, point_t rtp):
  frameRect(lbp, rtp),
  width_(frameRect.width_),
  height_(frameRect.height_),
  pos_(frameRect.pos_)
{}
float nikonov::Rectangle::getArea() const
{
  return (width_ * height_);
}
nikonov::rectangle_t nikonov::Rectangle::getFrameRect() const
{
  return frameRect;
}
void nikonov::Rectangle::move(point_t newPos)
{
  this->pos_ = newPos;
}
void nikonov::Rectangle::move(float x, float y)
{
  pos_.x_ += x;
  pos_.y_ += y;
}
void nikonov::Rectangle::scale(float k)
{
  width_ *= k;
  height_ *= k;
}

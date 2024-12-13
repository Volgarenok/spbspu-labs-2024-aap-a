#include "rectangle.hpp"
#include <cmath>
petrov::Rectangle::Rectangle(point_t p1, point_t p2): 
  p1_(p1),
  p3_(p2)
{
  p2_.x_ = p1_.x_;
  p2_.y_ = p3_.y_;
  p4_.x_ = p3_.x_;
  p4_.y_ = p1_.y_;
}

void petrov::Rectangle::getFrameRect()
{
  frame_rect_.height_ = abs(p2_.y_ - p1_.y_);
  frame_rect_.width_ = abs(p4_.x_ - p1_.x_);
  frame_rect_.pos_ = sqrt(pow(frame_rect_.height_, 2) + pow(frame_rect_.width_, 2));
}

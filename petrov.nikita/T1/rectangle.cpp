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

double petrov::Rectangle::getArea()
{
  return frame_rect_.width_ * frame_rect_.height_;
}

petrov::point_t petrov::Rectangle::getFrameRect()
{
  frame_rect_.height_ = abs(p2_.y_ - p1_.y_);
  frame_rect_.width_ = abs(p4_.x_ - p1_.x_);
  frame_rect_.pos_ = { p3_.x_ - p1_.x_, p3_.y_ - p1_.y_ };
  return frame_rect_.pos_;
}

void petrov::Rectangle::move(point_t concrete_point)
{
  frame_rect_.pos_.x_ = concrete_point.x_;
  frame_rect_.pos_.y_ = concrete_point.y_;
  p1_.x_ = frame_rect_.pos_.x_ - (frame_rect_.width_ / 2);
  p1_.y_ = frame_rect_.pos_.y_ - (frame_rect_.height_ / 2);
  p2_.x_ = frame_rect_.pos_.x_ - (frame_rect_.width_ / 2);
  p2_.y_ = frame_rect_.pos_.y_ + (frame_rect_.height_ / 2);
  p3_.x_ = frame_rect_.pos_.x_ + (frame_rect_.width_ / 2);
  p3_.y_ = frame_rect_.pos_.y_ + (frame_rect_.height_ / 2);
  p4_.x_ = frame_rect_.pos_.x_ + (frame_rect_.width_ / 2);
  p4_.y_ = frame_rect_.pos_.y_ - (frame_rect_.height_ / 2);
}

void petrov::Rectangle::move(double dx, double dy)
{
  frame_rect_.pos_.x_ += dx;
  frame_rect_.pos_.y_ += dy;
  p1_.x_ += dx;
  p1_.y_ += dy;
  p2_.x_ += dx;
  p2_.y_ += dy;
  p3_.x_ += dx;
  p3_.y_ += dy;
  p4_.x_ += dx;
  p4_.y_ += dx;
}

void petrov::Rectangle::scale(double k)
{
  frame_rect_.height_ *= k;
  frame_rect_.width_ *= k;
  p1_.x_ -= frame_rect_.width_ * 0.25;
  p1_.y_ -= frame_rect_.height_ * 0.25;
  p2_.x_ -= frame_rect_.width_ * 0.25;
  p2_.y_ += frame_rect_.height_ * 0.25;
  p3_.x_ += frame_rect_.width_ * 0.25;
  p3_.y_ += frame_rect_.height_ * 0.25;
  p4_.x_ += frame_rect_.width_ * 0.25;
  p4_.y_ -= frame_rect_.height_ * 0.25;
}
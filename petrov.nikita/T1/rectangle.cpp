#include "rectangle.hpp"
#include <cmath>
petrov::Rectangle::Rectangle(point_t p1, point_t p2):
  p1_(p1),
  p3_(p2)
{
  if (p1.x_ >= p2.x_ || p1.y_ >= p2.y_)
  {
    throw "ERROR: Invalid data somewhere\n";
  }
  p2_.x_ = p1_.x_;
  p2_.y_ = p3_.y_;
  p4_.x_ = p3_.x_;
  p4_.y_ = p1_.y_;
}

double petrov::Rectangle::getArea()
{
  return frame_rect_.width_ * frame_rect_.height_;
}

petrov::point_t * petrov::Rectangle::getFrameRect() // It needs changes...
{
  frame_rect_.height_ = abs(p2_.y_ - p1_.y_);
  frame_rect_.width_ = abs(p4_.x_ - p1_.x_);
  frame_rect_.pos_ = { ((2 * p1_.x_ + p3_.x_ - p1_.x_) / 2.0), ((2 * p1_.y_ + p3_.y_ - p1_.y_) / 2.0) };
  point_t lower_left_corner = { (frame_rect_.pos_.x_ - (frame_rect_.width_ / 2)), (frame_rect_.pos_.y_ - (frame_rect_.height_ / 2)) };
  point_t upper_right_corner = { (frame_rect_.pos_.x_ + (frame_rect_.width_ / 2)), (frame_rect_.pos_.y_ + (frame_rect_.height_ / 2)) };
  frame_points_[0] = lower_left_corner;
  frame_points_[1] = frame_rect_.pos_;
  frame_points_[2] = upper_right_corner;
  return frame_points_;
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
  {
    if (k > 1)
    {
      double dx = (frame_rect_.width_ / 2) * (k - 1);
      double dy = (frame_rect_.height_ / 2) * (k - 1);
      p1_.x_ -= dx;
      p1_.y_ -= dy;
      p2_.x_ -= dx;
      p2_.y_ += dy;
      p3_.x_ += dx;
      p3_.y_ += dy;
      p4_.x_ += dx;
      p4_.y_ -= dy;
      frame_rect_.height_ *= k;
      frame_rect_.width_ *= k;
    }
    else
    {
      double dx = (frame_rect_.width_ * (1 - k)) / 2;
      double dy = (frame_rect_.height_ * (1 - k)) / 2;
      p1_.x_ += dx;
      p1_.y_ += dy;
      p2_.x_ += dx;
      p2_.y_ -= dy;
      p3_.x_ -= dx;
      p3_.y_ -= dy;
      p4_.x_ -= dx;
      p4_.y_ += dy;
      frame_rect_.height_ *= k;
      frame_rect_.width_ *= k;
    }
  }
}

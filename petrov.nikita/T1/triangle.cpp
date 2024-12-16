#include "triangle.hpp"
#include <cmath>
#include <algorithm>
#include <iostream> // RAD
petrov::Triangle::Triangle(point_t p1, point_t p2, point_t p3): 
  p1_(p1),
  p2_(p2),
  p3_(p3)
{
  double a = sqrt(pow((p1_.x_ - p2_.x_), 2) + pow((p1_.y_ - p2_.y_), 2)); 
  double b = sqrt(pow((p3_.x_ - p2_.x_), 2) + pow((p3_.y_ - p2_.y_), 2));
  double c = sqrt(pow((p1_.x_ - p3_.x_), 2) + pow((p1_.y_ - p3_.y_), 2));
  if (a + b < c || a + c < b || b + c < a)
  {
    throw "ERROR: Invalid data somewhere\n";
  }
}

double petrov::Triangle::getArea()
{
  double a = sqrt(pow((p1_.x_ - p2_.x_), 2) + pow((p1_.y_ - p2_.y_), 2)); 
  double b = sqrt(pow((p3_.x_ - p2_.x_), 2) + pow((p3_.y_ - p2_.y_), 2));
  double c = sqrt(pow((p1_.x_ - p3_.x_), 2) + pow((p1_.y_ - p3_.y_), 2));
  double p = (a + b + c) / 2;
  return sqrt(p * (p - a) * (p - b) * (p - c));
}

petrov::point_t * petrov::Triangle::getFrameRect()
{
  frame_rect_.pos_ = { ((p1_.x_ + p2_.x_ + p3_.x_) / 3), ((p1_.y_ + p2_.y_ + p3_.y_) / 3) };
  double x_max = std::max(std::max(p1_.x_, p2_.x_), p3_.x_);
  double x_min = std::min(std::min(p1_.x_, p2_.x_), p3_.x_);
  double y_max = std::max(std::max(p1_.y_, p2_.y_), p3_.y_);
  double y_min = std::min(std::min(p1_.y_, p2_.y_), p3_.y_);
  frame_rect_.width_ = abs(x_max - x_min);
  frame_rect_.height_ = abs(y_max - y_min);
  point_t lower_left_corner = { (frame_rect_.pos_.x_ - (frame_rect_.width_ / 2)), (frame_rect_.pos_.y_ - (frame_rect_.height_ / 2)) };
  point_t upper_right_corner = { (frame_rect_.pos_.x_ + (frame_rect_.width_ / 2)), (frame_rect_.pos_.y_ + (frame_rect_.height_ / 2)) };
  frame_points_[0] = lower_left_corner;
  frame_points_[1] = frame_rect_.pos_;
  frame_points_[2] = upper_right_corner;
  return frame_points_;
}

void petrov::Triangle::move(point_t concrete_point)
{
  frame_rect_.pos_.x_ = concrete_point.x_;
  frame_rect_.pos_.y_ = concrete_point.y_;
  p1_.x_ = frame_rect_.pos_.x_ - (frame_rect_.width_ / 2);
  p1_.y_ = frame_rect_.pos_.y_ - (frame_rect_.height_ / 2);
  p2_.x_ = frame_rect_.pos_.x_ - (frame_rect_.width_ / 2);
  p2_.y_ = frame_rect_.pos_.y_ + (frame_rect_.height_ / 2);
  p3_.x_ = frame_rect_.pos_.x_ + (frame_rect_.width_ / 2);
  p3_.y_ = frame_rect_.pos_.y_ + (frame_rect_.height_ / 2);
}

void petrov::Triangle::move(double dx, double dy)
{
  frame_rect_.pos_.x_ += dx;
  frame_rect_.pos_.y_ += dy;
  p1_.x_ += dx;
  p1_.y_ += dy;
  p2_.x_ += dx;
  p2_.y_ += dy;
  p3_.x_ += dx;
  p3_.y_ += dy;
}

void petrov::Triangle::scale(double k) // ???
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
      frame_rect_.height_ *= k;
      frame_rect_.width_ *= k;
    }
  }
}
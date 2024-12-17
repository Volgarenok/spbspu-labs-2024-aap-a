#include "concave.hpp"
#include <cmath>
#include <algorithm>
petrov::Concave::Concave(petrov::point_t p1, petrov::point_t p2, petrov::point_t p3, petrov::point_t p4):
  p1_(p1),
  p2_(p2),
  p3_(p3),
  p4_(p4)
{
  if ( (p1_.x_ == p4_.x_ && p1_.y_ == p4_.y_) || (p2_.x_ == p4_.x_ && p2_.y_ == p4_.y_) || (p3_.x_ == p4_.x_ && p3_.y_ == p4_.y_) )
  {
    throw "ERROR: Invalid data somewhere";
  }
  double a = sqrt(pow((p1_.x_ - p2_.x_), 2) + pow((p1_.y_ - p2_.y_), 2));
  double b = sqrt(pow((p3_.x_ - p2_.x_), 2) + pow((p3_.y_ - p2_.y_), 2));
  double c = sqrt(pow((p1_.x_ - p3_.x_), 2) + pow((p1_.y_ - p3_.y_), 2));
  if (a + b <= c || a + c <= b || b + c <= a)
  {
    throw "ERROR: Invalid data somewhere";
  }
  double p = (a + b + c) / 2;
  double area_of_triangle = sqrt(p * (p - a) * (p - b) * (p - c));
  a = sqrt(pow((p2_.x_ - p3_.x_), 2) + pow((p2_.y_ - p3_.y_), 2));
  b = sqrt(pow((p3_.x_ - p4_.x_), 2) + pow((p3_.y_ - p4_.y_), 2));
  c = sqrt(pow((p2_.x_ - p4_.x_), 2) + pow((p2_.y_ - p4_.y_), 2));
  p = (a + b + c) / 2;
  double area_1 = sqrt(p * (p - a) * (p - b) * (p - c));
  a = sqrt(pow((p2_.x_ - p1_.x_), 2) + pow((p2_.y_ - p1_.y_), 2));
  b = sqrt(pow((p1_.x_ - p4_.x_), 2) + pow((p1_.y_ - p4_.y_), 2));
  c = sqrt(pow((p2_.x_ - p4_.x_), 2) + pow((p2_.y_ - p4_.y_), 2));
  p = (a + b + c) / 2;
  double area_2 = sqrt(p * (p - a) * (p - b) * (p - c));
  a = sqrt(pow((p3_.x_ - p1_.x_), 2) + pow((p3_.y_ - p1_.y_), 2));
  b = sqrt(pow((p1_.x_ - p4_.x_), 2) + pow((p1_.y_ - p4_.y_), 2));
  c = sqrt(pow((p3_.x_ - p4_.x_), 2) + pow((p3_.y_ - p4_.y_), 2));
  p = (a + b + c) / 2;
  double area_3 = sqrt(p * (p - a) * (p - b) * (p - c));
  if (round(area_of_triangle) / 10 != round(area_1 + area_2 + area_3) / 10)
  {
    throw "ERROR: Invalid data somewhere\n";
  }
}

double petrov::Concave::getArea() // Here you can use variables more effictively (decrease initializations number)
{
  double a_1 = sqrt(pow((p1_.x_ - p2_.x_), 2) + pow((p1_.y_ - p2_.y_), 2));
  double b_1 = sqrt(pow((p3_.x_ - p2_.x_), 2) + pow((p3_.y_ - p2_.y_), 2));
  double c_1 = sqrt(pow((p1_.x_ - p3_.x_), 2) + pow((p1_.y_ - p3_.y_), 2));
  double p_1 = (a_1 + b_1 + c_1) / 2;
  double area_without_cave = sqrt(p_1 * (p_1 - a_1) * (p_1 - b_1) * (p_1 - c_1));
  double a_2 = sqrt(pow((p2_.x_ - p4_.x_), 2) + pow((p2_.y_ - p4_.y_), 2));
  double b_2 = b_1;
  double c_2 = sqrt(pow((p4_.x_ - p3_.x_), 2) + pow((p4_.y_ - p3_.y_), 2));
  double p_2 = (a_2 + b_2 + c_2) / 2;
  double area_of_cave = sqrt(p_2 * (p_2 - a_2) * (p_2 - b_2) * (p_2 - c_2));
  return area_without_cave - area_of_cave;
}

petrov::rectangle_t petrov::Concave::getFrameRect()
{
  double x_max = std::max(std::max(p1_.x_, p2_.x_), p3_.x_);
  double x_min = std::min(std::min(p1_.x_, p2_.x_), p3_.x_);
  double y_max = std::max(std::max(p1_.y_, p2_.y_), p3_.y_);
  double y_min = std::min(std::min(p1_.y_, p2_.y_), p3_.y_);
  frame_rect_.width_ = abs(x_max - x_min);
  frame_rect_.height_ = abs(y_max - y_min);
  frame_rect_.pos_ = { ((2 * x_min + x_max - x_min) / 2.0), ((2 * y_min + y_max - y_min) / 2.0) };
  return frame_rect_;
}

void petrov::Concave::move(petrov::point_t concrete_point)
{
  double pos_dx = concrete_point.x_ - frame_rect_.pos_.x_;
  double pos_dy = concrete_point.y_ - frame_rect_.pos_.y_;
  p4_.x_ += pos_dx;
  p4_.y_ += pos_dy;
  frame_rect_.pos_.x_ = concrete_point.x_;
  frame_rect_.pos_.y_ = concrete_point.y_;
  p1_.x_ = frame_rect_.pos_.x_ - (frame_rect_.width_ / 2);
  p1_.y_ = frame_rect_.pos_.y_ - (frame_rect_.height_ / 2);
  p2_.x_ = frame_rect_.pos_.x_ - (frame_rect_.width_ / 2);
  p2_.y_ = frame_rect_.pos_.y_ + (frame_rect_.height_ / 2);
  p3_.x_ = frame_rect_.pos_.x_ + (frame_rect_.width_ / 2);
  p3_.y_ = frame_rect_.pos_.y_ + (frame_rect_.height_ / 2);
}

void petrov::Concave::move(double dx, double dy)
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
  p4_.y_ += dy;
}

void petrov::Concave::scale(double k)
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

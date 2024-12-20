#include "rectangle.hpp"
#include <stdexcept>
#include "base-types.hpp"

zakirov::Rectangle::Rectangle(point_t bottom_left, point_t top_right) :
  bottom_left_(bottom_left),
  top_right_(top_right)
{
  if (bottom_left_.x_ >= top_right_.x_ || bottom_left_.y_ >= top_right_.y_)
  {
    throw std::invalid_argument("Incorrect data");
  }
}

double zakirov::Rectangle::getArea() const
{
  double distance_x = get_distance_x(top_right_, bottom_left_);
  double distance_y = get_distance_y(top_right_, bottom_left_);
  return distance_x * distance_y;
}

zakirov::rectangle_t zakirov::Rectangle::getFrameRect() const
{
  rectangle_t сircumscribed;
  сircumscribed.width_ = get_distance_x(top_right_, bottom_left_);
  сircumscribed.height_ = get_distance_y(top_right_, bottom_left_);
  сircumscribed.position_ = get_middle(top_right_, bottom_left_);

  return сircumscribed;
}

void zakirov::Rectangle::move(point_t target)
{
  double distance_x = get_distance_x(top_right_, bottom_left_);
  double distance_y = get_distance_y(top_right_, bottom_left_);

  top_right_.x_ = target.x_ + (distance_x / 2);
  top_right_.y_ = target.y_ + (distance_y / 2);
  bottom_left_.x_ = target.x_ - (distance_x / 2);
  bottom_left_.y_ = target.y_ - (distance_y / 2);
}

void zakirov::Rectangle::move(double bias_x, double bias_y)
{
  top_right_.x_ += bias_x;
  top_right_.y_ += bias_y;
  bottom_left_.x_ += bias_x;
  bottom_left_.y_ += bias_y;
}

void zakirov::Rectangle::scale(double k)
{
  if (k <= 0)
  {
    return;
  }

  point_t center = getFrameRect().position_;
  top_right_.x_ = center.x_ + (top_right_.x_ - center.x_) * k;
  top_right_.y_  = center.y_ + (top_right_.y_ - center.y_) * k;
  bottom_left_.x_ = center.x_ - (center.x_ - bottom_left_.x_) * k;
  bottom_left_.y_ = center.x_ - (center.x_ - bottom_left_.y_) * k;
}

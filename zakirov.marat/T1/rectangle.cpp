#include "rectangle.hpp"
#include <stdexcept>
#include "base-types.hpp"

zakirov::Rectangle::Rectangle(point_t bottom_left, point_t top_right):
  bottom_left_(bottom_left),
  top_right_(top_right)
{
  if (bottom_left_.x >= top_right_.x || bottom_left_.y >= top_right_.y)
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
  double width = get_distance_x(top_right_, bottom_left_);
  double height = get_distance_y(top_right_, bottom_left_);
  point_t position = get_middle(top_right_, bottom_left_);

  return {width, height, position};
}

void zakirov::Rectangle::move(point_t target)
{
  double distance_x = get_distance_x(top_right_, bottom_left_);
  double distance_y = get_distance_y(top_right_, bottom_left_);

  top_right_.x = target.x + (distance_x / 2);
  top_right_.y = target.y + (distance_y / 2);
  bottom_left_.x = target.x - (distance_x / 2);
  bottom_left_.y = target.y - (distance_y / 2);
}

void zakirov::Rectangle::move(double bias_x, double bias_y)
{
  top_right_.x += bias_x;
  top_right_.y += bias_y;
  bottom_left_.x += bias_x;
  bottom_left_.y += bias_y;
}

void zakirov::Rectangle::scale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Incorrect coefficient");
  }

  point_t center = getFrameRect().pos;
  top_right_.x = center.x + (top_right_.x - center.x) * k;
  top_right_.y  = center.y + (top_right_.y - center.y) * k;
  bottom_left_.x = center.x - (center.x - bottom_left_.x) * k;
  bottom_left_.y = center.x - (center.x - bottom_left_.y) * k;
}

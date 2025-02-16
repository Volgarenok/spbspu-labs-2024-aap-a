#include "rectangle.hpp"
#include <stdexcept>
#include "base-types.hpp"

zakirov::Rectangle::Rectangle(const point_t & bottom_left, const point_t & top_right):
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
  return (top_right_.x - bottom_left_.x) * (top_right_.y - bottom_left_.y);
}

zakirov::rectangle_t zakirov::Rectangle::getFrameRect() const
{
  double width = (top_right_.x - bottom_left_.x);
  double height = (top_right_.y - bottom_left_.y);
  point_t position = get_middle(top_right_, bottom_left_);

  return {width, height, position};
}

void zakirov::Rectangle::move(const point_t & target)
{
  point_t center = getFrameRect().pos;
  point_t bias = {target.x - center.x, target.y - center.y};
  move_point(top_right_, bias.x, bias.y);
  move_point(bottom_left_, bias.x, bias.y);
}

void zakirov::Rectangle::move(double bias_x, double bias_y)
{
  move({getFrameRect().pos.x + bias_x, getFrameRect().pos.y + bias_y});
}

void zakirov::Rectangle::scale(double k) noexcept
{
  double scale_distance_x = (top_right_.x - getFrameRect().pos.x) * (k - 1);
  double scale_distance_y = (top_right_.y - getFrameRect().pos.y) * (k - 1);
  move_point(top_right_, scale_distance_x, scale_distance_y);
  move_point(bottom_left_, -scale_distance_x, -scale_distance_y);
}

zakirov::Shape * zakirov::Rectangle::clone() const
{
  Rectangle * rectangle = nullptr;
  try
  {
    Rectangle * rectangle = static_cast< Rectangle * >(malloc(sizeof(Rectangle)));
    if (!rectangle)
    {
      throw std::bad_alloc();
    }

    new (rectangle) Rectangle(bottom_left_, top_right_);
    return rectangle;
  }
  catch (const std::exception &)
  {
    free(rectangle);
    throw;
  }
}

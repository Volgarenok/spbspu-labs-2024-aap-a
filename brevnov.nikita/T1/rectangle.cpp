#include "rectangle.hpp"
#include <stdexcept>
#include "composite-shape.hpp"


brevnov::Rectangle::Rectangle(point_t left, point_t right):
  shapes_(new Shape *[64]),
  left_(left),
  right_(right)
{
  if (left.x >= right.x || left.y >= right.y)
  {
    delete[] shapes_;
    throw std::invalid_argument("Not correct arguments");
  }
  double width = right_.x - left_.x;
  double height = right_.y - left_.y;
  double r1 = height / 16.0;
  double r2 = width / 16.0;
  for (size_t i = 0; i < 8; i++)
  {
    for (size_t j = 0; j < 8; j++)
    {
      shapes_[i * 8 + j] = new Ellipse({left_.x + r2 * (i * 2 + 1), left_.y + r1 * (i * 2 + 1)}, r1, r2);
    }
  }
}

brevnov::Rectangle::~Rectangle()
{
  clearShape(shapes_, 64);
}

double brevnov::Rectangle::getArea() const noexcept
{
  return (right_.x - left_.x) * (right_.y - left_.y);
}

brevnov::rectangle_t brevnov::Rectangle::getFrameRect() const noexcept
{
  double width = right_.x - left_.x;
  double height = right_.y - left_.y;
  point_t pos = {left_.x + width / 2.0, left_.y + height / 2.0};
  rectangle_t result = {width, height, pos};
  return result;
}

void brevnov::Rectangle::move(brevnov::point_t new_centre) noexcept
{
  double width = right_.x - left_.x;
  double height = right_.y - left_.y;
  point_t start = {left_.x + width / 2.0, left_.y + height / 2.0};
  double dx = new_centre.x - start.x;
  double dy = new_centre.y - start.y;
  move(dx, dy);
}

void brevnov::Rectangle::move(double dx, double dy) noexcept
{
  for (size_t i = 0; i < 64; i++)
  {
    shapes_[i]->move(dx, dy);
  }
  move_point(dx, dy, right_);
  move_point(dx, dy, left_);
}

void brevnov::Rectangle::scale(double n) noexcept
{
  point_t center = {left_.x + (right_.x - left_.x) / 2.0, left_.y + (right_.y - left_.y) / 2.0};
  double a = (right_.x - left_.x) * n;
  double b = (right_.y - left_.y) * n;
  double r1 = b / 16.0;
  double r2 = a / 16.0;
  left_ = {center.x - a * 0.5, center.y - b * 0.5};
  right_ = {center.x + a * 0.5, center.y + b * 0.5};
  for (size_t i = 0; i < 8; i++)
  {
    for (size_t j = 0; j < 8; j++)
    {
      shapes_[i * 8 + j]->scale(n);
      shapes_[i * 8 + j]->move({left_.x + r2 * (i * 2 + 1), left_.y + r1 * (i * 2 + 1)});
    }
  }
}

brevnov::Shape * brevnov::Rectangle::clone() const
{
  return new Rectangle(*this);
}

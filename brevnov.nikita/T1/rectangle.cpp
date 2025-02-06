#include "rectangle.hpp"
#include <stdexcept>

brevnov::Rectangle::Rectangle(point_t left, point_t right):
  shapes_(new Ellipse[64]),
  left_(left),
  right_(right)
{
  if (left.x >= right.x || left.y >= right.y)
  {
    throw std::invalid_argument("Not correct arguments");
  }
  for (size_t i = 0; i < 64; i++)
  {
    shapes_[i] = nullptr;
  }
  double width = right_.x - left_.x;
  double height = right_.y - left_.y;
  double r1 = height / 16.0;
  double r2 = width / 16.0;
  for (size_t i = 0; i < 8; i++)
  {
    for (size_t j = 0; j < 8; j++)
    {
       shapes_[i * 8 + j] = Ellipse({left_.x + r2 * (i * 2 + 1), left_.y + r1 * (i * 2 + 1)}, r1, r2);
    }
  }
}

brevnov::Rectangle::~Rectangle()
{
  for (size_t i = 0; i < 64; i++)
  {
    delete shapes_[i];
  }
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

void brevnov::move_point(brevnov::point_t& point, double dx, double dy) noexcept
{
  point.x += dx;
  point.y += dy;
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
  move_point(right_, dx, dy);
  move_point(left_, dx, dy);
}

void brevnov::Rectangle::scale(double n) noexcept
{
  point_t center = {left_.x + (right_.x - left_.x) / 2.0, left_.y + (right_.y - left_.y) / 2.0};
  double r1 = shapes_[0]->getR1() * n;
  double r2 = shapes_[0]->getR2() * n;
  left_ = {center.x - r2 * 4.0, center.y - r1 * 4.0};
  right_ = {center.x + r2 * 4.0, center.y + r1 * 4.0};
  for (size_t i = 0; i < 8; i++)
  {
    for (size_t j = 0; j < 8; j++)
    {
      shapes_[i * 8 + j]->updateEllipse({left_.x + r2 * (i * 2 + 1), left_.y + r1 * (i * 2 + 1)}, r1, r2);
    }
  }
}


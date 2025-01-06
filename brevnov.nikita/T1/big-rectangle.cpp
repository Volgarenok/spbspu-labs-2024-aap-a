#include "big-rectangle.hpp"
#include <cstddef>

brevnov::BigRectangle::BigRectangle(point_t left, point_t right):
  left_(left),
  right_(right),
  shapes_(nullptr)
{
  shapes = new Ellipse *[64];
  double width = right_.x_ - left_.x_;
  double height = right_.y_ - left_.y_;
  double r1 = height / 16.0;
  double r2 = width / 16.0;
  for (size_t i = 0; i < 8; i++)
  {
    for (size_t j = 0; j < 8; j++)
    {
      try
      {
        shapes[i * 8 + j] = new Ellipse({left_.x_ + r2 * (i * 2 + 1), left_.y_ + r1 * (i * 2 + 1)}, r1, r2);
      }
      catch (const bad_alloc & e)
      {
        for (size_t h = 0; h < i * 8 + j; h++)
        {
          delete shapes[h];
        }
        delete[] shapes;
        throw;
      }
    }
  }
}

brevnov::BigRectangle::~BigRectangle()
{
  for (size_t i = 0; i < 64; i++)
  {
    delete shapes[i];
  }
  delete[] shapes;
}

double brevnov::BigRectangle::getArea() const noexcept
{
  return shapes[0]->getArea() * 64;
}

brevnov::rectangle_t brevnov::BigRectangle::getFrameRect() const noexcept
{
  double width = right_.x_ - left_.x_;
  double height = right_.y_ - left_.y_;
  point_t pos = {left_.x_ + width / 2.0, left_.y_ + height / 2.0};
  rectangle_t result(width, height, pos);
  return result;
}

void brevnov::BigRectangle::move(point_t new_centre) noexcept
{
  double width = right_.x_ - left_.x_;
  double height = right_.y_ - left_.y_;
  point_t start = {left_.x_ + width / 2.0; left_.y_ + height / 2.0};
  double dx = new_centre.x_ - start.x_;
  double dy = new_centre.y_ - start.y_;
  move(dx, dy);
}

void brevnov::BigRectangle::move(double dx, double dy) noexcept
{
  for (size_t i = 0; i < 64; i++)
  {
    shapes[i]->move(dx, dy);
  }
}

void brevnov::BigRectangle::scale(double n) noexcept
{
  point_t center = {left_.x_ + (right_.x_ - left_.x_) / 2.0, left_.y_ + (right_.y_ - left_.y_) / 2.0};
  double r1 = shapes_[i].r1_ * n;
  double r2 = shapes_[i].r2_ * n;
  left_ = {center.x_ - r2 * 4.0, center.y_ - r1 * 4.0};
  right_ = {center.x_ + r2 * 4.0, center.y_ + r1 * 4.0};
  for (size_t i = 0; i < 8; i++)
  {
    for (size_t j = 0; j < 8; j++)
    {
      shapes_[i * 8 + j].r1_ = r1;
      shapes_[i * 8 + j].r2_ = r2;
      shapes_[i * 8 + j].center_ = {left_.x_ + r2 * (i * 2 + 1), left_.y_ + r1 * (i * 2 + 1)};
    }
  }
}

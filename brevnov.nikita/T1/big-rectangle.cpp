#include "big-rectangle.hpp"
#include <cstddef>

brevnov::BigRectangle::BigRectangle(point_t left, point_t right):
  shapes_(nullptr),
  left_(left),
  right_(right)
{
  shapes_ = new Ellipse *[64];
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
        shapes_[i * 8 + j] = new Ellipse({left_.x_ + r2 * (i * 2 + 1), left_.y_ + r1 * (i * 2 + 1)}, r1, r2);
      }
      catch (const std::bad_alloc& e)
      {
        for (size_t h = 0; h < i * 8 + j; h++)
        {
          delete shapes_[h];
        }
        delete[] shapes_;
        throw;
      }
    }
  }
}

brevnov::BigRectangle::~BigRectangle()
{
  for (size_t i = 0; i < 64; i++)
  {
    delete shapes_[i];
  }
  delete[] shapes_;
}

double brevnov::BigRectangle::getArea() const noexcept
{
  return shapes_[0]->getArea() * 64;
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
  point_t start = {left_.x_ + width / 2.0, left_.y_ + height / 2.0};
  double dx = new_centre.x_ - start.x_;
  double dy = new_centre.y_ - start.y_;
  move(dx, dy);
}

void brevnov::BigRectangle::move(double dx, double dy) noexcept
{
  for (size_t i = 0; i < 64; i++)
  {
    shapes_[i]->move(dx, dy);
  }
}

void brevnov::BigRectangle::scale(double n) noexcept
{
  point_t center = {left_.x_ + (right_.x_ - left_.x_) / 2.0, left_.y_ + (right_.y_ - left_.y_) / 2.0};
  double r1 = shapes_[0]->getR1() * n;
  double r2 = shapes_[0]->getR2() * n;
  left_ = {center.x_ - r2 * 4.0, center.y_ - r1 * 4.0};
  right_ = {center.x_ + r2 * 4.0, center.y_ + r1 * 4.0};
  for (size_t i = 0; i < 8; i++)
  {
    for (size_t j = 0; j < 8; j++)
    {
      shapes_[i * 8 + j]->updateEllipse({left_.x_ + r2 * (i * 2 + 1), left_.y_ + r1 * (i * 2 + 1)}, r1, r2);
    }
  }
}

#include "polygon.hpp"

#include <stdexcept>
#include <algorithm>
#include <utility>

rychkov::Polygon::Polygon(const Polygon& src):
  vertexes_(static_cast< point_t* >(malloc(src.size_ * sizeof(point_t)))),
  size_(src.size_)
{
  if (!vertexes_)
  {
    throw std::bad_alloc();
  }
  for (size_t i = 0; i < size_; i++)
  {
    vertexes_[i] = src.vertexes_[i];
  }
}
rychkov::Polygon::Polygon(Polygon&& src) noexcept:
  vertexes_(std::exchange(src.vertexes_, nullptr)),
  size_(src.size_)
{}
rychkov::Polygon::Polygon(point_t* points, size_t size):
  vertexes_(points),
  size_(size)
{
  if (size < 3)
  {
    throw std::invalid_argument("not enough vertexes to build polygon");
  }
  for (size_t i = 1; i < size; i++)
  {
    for (size_t j = 0; j < i; j++)
    {
      if ((points[i].x == points[j].x) && (points[i].y == points[j].y))
      {
        throw std::invalid_argument("polygon can't have equal vertexes");
      }
    }
  }
}
rychkov::Polygon::~Polygon()
{
  free(vertexes_);
}

rychkov::Polygon& rychkov::Polygon::operator=(const Polygon& src)
{
  Polygon temp(src);
  std::swap(*this, temp);
  return *this;
}
rychkov::Polygon& rychkov::Polygon::operator=(Polygon&& src) noexcept
{
  Polygon temp(std::move(*this));
  vertexes_ = std::exchange(src.vertexes_, nullptr);
  size_ = src.size_;
  return *this;
}

double rychkov::Polygon::getArea() const noexcept
{
  point_t basePoint = vertexes_[0];
  double result = 0;
  for (size_t i = 2; i < size_; i++)
  {
    result += getSquare(basePoint, vertexes_[i - 1], vertexes_[i]);
  }
  return result;
}
rychkov::rectangle_t rychkov::Polygon::getFrameRect() const noexcept
{
  point_t bottomLeft(vertexes_[0]), topRight(vertexes_[0]);
  for (size_t i = 1; i < size_; i++)
  {
    updateFrame(bottomLeft, topRight, vertexes_[i]);
  }
  return makeFrame(bottomLeft, topRight);
}
void rychkov::Polygon::move(point_t destination) noexcept
{
  point_t center = getCenter();
  move(destination.x - center.x, destination.y - center.y);
}
void rychkov::Polygon::move(double deltaX, double deltaY) noexcept
{
  for (size_t i = 0; i < size_; i++)
  {
    vertexes_[i].x += deltaX;
    vertexes_[i].y += deltaY;
  }
}
void rychkov::Polygon::unsafeScale(double coef) noexcept
{
  point_t center = getCenter();
  for (size_t i = 0; i < size_; i++)
  {
    vertexes_[i].x = center.x + (vertexes_[i].x - center.x) * coef;
    vertexes_[i].y = center.y + (vertexes_[i].y - center.y) * coef;
  }
}
rychkov::point_t rychkov::Polygon::getCenter() const noexcept
{
  point_t coordsSum = {0, 0};
  for (size_t i = 0; i < size_; i++)
  {
    coordsSum.x += vertexes_[i].x;
    coordsSum.y += vertexes_[i].y;
  }
  return {coordsSum.x / size_, coordsSum.y / size_};
}
rychkov::Shape* rychkov::Polygon::clone() const
{
  Polygon* result = static_cast< Polygon* >(malloc(sizeof(Polygon)));
  if (!result)
  {
    return nullptr;
  }
  try
  {
    return new (result) Polygon(*this);
  }
  catch (...)
  {
    free(result);
    return nullptr;
  }
}

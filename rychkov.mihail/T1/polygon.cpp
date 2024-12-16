#include "polygon.hpp"

#include <stdexcept>
#include <algorithm>

rychkov::Polygon::~Polygon()
{
  free(vertexes_);
}
rychkov::Polygon::Polygon(point_t* points, size_t size):
  vertexes_(points),
  size_(size)
{
  if(size < 3)
  {
    throw std::invalid_argument("invalid polygon vertexes count");
  }
  for (size_t i = 1; i < size; i++)
  {
    for (size_t j = 0; j < i; j++)
    {
      if ((points[i].x == points[j].x) && (points[i].y == points[j].y))
      {
        throw std::invalid_argument("invalid polygon vertexes");
      }
    }
  }
}

double rychkov::Polygon::getArea() const noexcept
{
  rectangle_t temp = getFrameRect();
  return temp.height * temp.width;
}
rychkov::rectangle_t rychkov::Polygon::getFrameRect() const noexcept
{
  point_t bottomLeft{0, 0}, topRight{0, 0};
  for (size_t i = 0; i < size_; i++)
  {
    bottomLeft.x = std::min(bottomLeft.x, vertexes_[i].x);
    bottomLeft.y = std::min(bottomLeft.y, vertexes_[i].y);
    bottomLeft.x = std::max(bottomLeft.x, vertexes_[i].x);
    bottomLeft.y = std::max(bottomLeft.y, vertexes_[i].y);
  }
  point_t center = {(topRight.x + bottomLeft.x) / 2, (topRight.y + bottomLeft.y) / 2};
  return {topRight.y - bottomLeft.y, topRight.x - bottomLeft.x, center};
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
void rychkov::Polygon::scale(double coef)
{
  if (coef <= 0)
  {
    throw std::invalid_argument("scale can't be executed with non-positive coefficient");
  }
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

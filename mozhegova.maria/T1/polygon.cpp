#include "polygon.hpp"
#include <stdexcept>
#include <algorithm>
#include <cmath>

namespace
{
  mozhegova::point_t * createPoly(size_t n, const mozhegova::point_t * arr)
  {
    mozhegova::point_t * arrCopy = new mozhegova::point_t[n];
    for (size_t i = 0; i < n; i++)
    {
      arrCopy[i] = arr[i];
    }
    return arrCopy;
  }
}

mozhegova::Polygon::~Polygon()
{
  delete[] points_;
}

mozhegova::Polygon::Polygon(size_t n, const point_t * arr):
  count_(n),
  points_(createPoly(n, arr))
{
  if (count_ < 3)
  {
    delete[] points_;
    throw std::invalid_argument("Incorrect coordinates");
  }
  for (size_t i = 0; i < count_ - 1; i++)
  {
    for (size_t j = i + 1; j < count_; j++)
    {
      if (points_[i].x == points_[j].x && points_[i].y == points_[j].y)
      {
        delete[] points_;
        throw std::invalid_argument("Incorrect coordinates");
      }
    }
  }
}

double mozhegova::Polygon::getArea() const
{
  double sum = points_[0].x * (points_[1].y - points_[count_ - 1].y);
  for (size_t i = 1; i < count_ - 1; i++)
  {
    sum += points_[i].x * (points_[i + 1].y - points_[i - 1].y);
  }
  sum += points_[count_ - 1].x * (points_[0].y - points_[count_ - 2].y);
  return 0.5 * std::fabs(sum);
}

mozhegova::rectangle_t mozhegova::Polygon::getFrameRect() const
{
  double minX = points_[0].x;
  double maxX = points_[0].x;
  double minY = points_[0].y;
  double maxY = points_[0].y;
  for (size_t i = 1; i < count_; i++)
  {
    minX = std::min(minX, points_[i].x);
    maxX = std::max(maxX, points_[i].x);
    minY = std::min(minY, points_[i].y);
    maxY = std::max(maxY, points_[i].y);
  }
  double width = maxX - minX;
  double height = maxY - minY;
  double x = minX + (width / 2.0);
  double y = minY + (height / 2.0);
  return {width, height, {x, y}};
}

void mozhegova::Polygon::move(point_t p)
{
  point_t center = getCenter();
  point_t vector = {p.x - center.x, p.y - center.y};
  move(vector.x, vector.y);
}

void mozhegova::Polygon::move(double dx, double dy)
{
  for (size_t i = 0; i < count_; i++)
  {
    points_[i].x += dx;
    points_[i].y += dy;
  }
}

void mozhegova::Polygon::scaleImpl(double k)
{
  point_t center = getCenter();
  point_t vector = {0.0, 0.0};
  for (size_t i = 0; i < count_; i++)
  {
    vector = {points_[i].x - center.x, points_[i].y - center.y};
    points_[i].x = center.x + vector.x * k;
    points_[i].y = center.y + vector.y * k;
  }
}

mozhegova::point_t mozhegova::Polygon::getCenter() const
{
  double sumX = 0.0;
  double sumY = 0.0;
  for (size_t i = 0; i < count_; i++)
  {
    sumX += points_[i].x;
    sumY += points_[i].y;
  }
  return {sumX / count_, sumY / count_};
}

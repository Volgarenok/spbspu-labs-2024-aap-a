#include "polygon.hpp"
#include <stdexcept>
#include <algorithm>

mozhegova::Polygon::~Polygon()
{
  delete[] points_;
}

mozhegova::Polygon::Polygon(size_t n, const point_t * arr):
  count_(n),
  points_(new point_t[n])
{
  if (count_ < 3)
  {
    delete[] points_;
    throw std::invalid_argument("Incorrect coordinates");
  }
  for (size_t i = 0; i < count_; i++)
  {
    points_[i] = arr[i];
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
  return 0.5 * std::abs(sum);
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
  double sumX = 0.0;
  double sumY = 0.0;
  for (size_t i = 0; i < count_; i++)
  {
    sumX += points_[i].x;
    sumY += points_[i].y;
  }
  point_t center = {sumX / count_, sumY / count_};
  point_t vector = {0.0, 0.0};
  for (size_t i = 0; i < count_; i++)
  {
    vector = {points_[i].x - center.x, points_[i].y - center.y};
    points_[i] = {p.x + vector.x, p.y + vector.y};
  }
}

void mozhegova::Polygon::move(double dx, double dy)
{
  for (size_t i = 0; i < count_; i++)
  {
    points_[i].x += dx;
    points_[i].y += dy;
  }
}

void mozhegova::Polygon::scale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Incorrect scale");
  }
  double sumX = 0.0;
  double sumY = 0.0;
  for (size_t i = 0; i < count_; i++)
  {
    sumX += points_[i].x;
    sumY += points_[i].y;
  }
  point_t center = {sumX / count_, sumY / count_};
  point_t vector = {0.0, 0.0};
  for (size_t i = 0; i < count_; i++)
  {
    vector = {points_[i].x - center.x, points_[i].y - center.y};
    points_[i].x = center.x + vector.x * k;
    points_[i].y = center.y + vector.y * k;
  }
}

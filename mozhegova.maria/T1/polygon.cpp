#include "polygon.hpp"
#include <algorithm>

mozhegova::Polygon::~Polygon()
{
  delete[] points;
}

mozhegova::Polygon::Polygon(size_t n, const point_t * arr):
  count(n),
  points(new point_t[n])
{
  for (size_t i = 0; i < count; i++)
  {
    points[i] = arr[i];
  }
}

double mozhegova::Polygon::getArea() const
{
  double sum = points[0].x * (points[1].y - points[count - 1].y);
  for (size_t i = 1; i < count - 1; i++)
  {
    sum += points[i].x * (points[i + 1].y - points[i - 1].y);
  }
  sum += points[count - 1].x * (points[0].y - points[count - 2].y);
  return 0.5 * std::abs(sum);
}

mozhegova::rectangle_t mozhegova::Polygon::getFrameRect() const
{
  double minX = points[0].x;
  double maxX = points[0].x;
  double minY = points[0].y;
  double maxY = points[0].y;
  for (size_t i = 1; i < count; i++)
  {
    minX = std::min(minX, points[i].x);
    maxX = std::max(maxX, points[i].x);
    minY = std::min(minY, points[i].y);
    maxY = std::max(maxY, points[i].y);
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
  for (size_t i = 0; i < count; i++)
  {
    sumX += points[i].x;
    sumY += points[i].y;
  }
  point_t center = {sumX / count, sumY / count};
  point_t vector = {0.0, 0.0};
  for (size_t i = 0; i < count; i++)
  {
    vector = {points[i].x - center.x, points[i].y - center.y};
    points[i] = {p.x + vector.x, p.y + vector.y};
  }
}

void mozhegova::Polygon::move(double dx, double dy)
{
  for (size_t i = 0; i < count; i++)
  {
    points[i].x += dx;
    points[i].y += dy;
  }
}

void mozhegova::Polygon::scale(double k)
{
  double sumX = 0.0;
  double sumY = 0.0;
  for (size_t i = 0; i < count; i++)
  {
    sumX += points[i].x;
    sumY += points[i].y;
  }
  point_t center = {sumX / count, sumY / count};
  point_t vector = {0.0, 0.0};
  for (size_t i = 0; i < count; i++)
  {
    vector = {points[i].x - center.x, points[i].y - center.y};
    points[i].x = center.x + vector.x * k;
    points[i].y = center.y + vector.y * k;
  }
}

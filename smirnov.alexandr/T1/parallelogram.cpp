#include "parallelogram.hpp"
#include <cmath>
#include <algorithm>
#include <stdexcept>

smirnov::Parallelogram::Parallelogram(double x1, double y1,
    double x2, double y2, double x3, double y3):
  vertex1{x1, y1},
  vertex2{x2, y2},
  vertex3{x3, y3},
  vertex4{vertex1.x + vertex3.x - vertex2.x, vertex1.y + vertex3.y - vertex2.y}
{
  if ((x1 == x3 && y2 == y3) || (x2 == x3 && y1 == y3))
  {
    throw std::invalid_argument("Incorrect coordinates for the parallelogram");
  }
  if (!(y1 == y2 || y1 == y3 || y2 == y3))
  {
    throw std::invalid_argument("The sides of the parallelogram must be parallel to the X-axis");
  }
}

double smirnov::Parallelogram::getArea() const
{
  double vector1X = vertex2.x - vertex1.x;
  double vector1Y = vertex2.y - vertex1.y;
  double vector2X = vertex3.x - vertex1.x;
  double vector2Y = vertex3.y - vertex1.y;
  return std::abs(vector1X * vector2Y - vector1Y * vector2X);
}

smirnov::rectangle_t smirnov::Parallelogram::getFrameRect() const
{
  point_t center;
  center.x = (vertex1.x + vertex2.x + vertex3.x + vertex4.x) / 4;
  center.y = (vertex1.y + vertex2.y + vertex3.y + vertex4.y) / 4;
  double minX = std::min({vertex1.x, vertex2.x, vertex3.x, vertex4.x});
  double maxX = std::max({vertex1.x, vertex2.x, vertex3.x, vertex4.x});
  double minY = std::min({vertex1.y, vertex2.y, vertex3.y, vertex4.y});
  double maxY = std::max({vertex1.y, vertex2.y, vertex3.y, vertex4.y});
  return {center, maxX- minX, maxY - minY};
}

void smirnov::Parallelogram::move(point_t newPos)
{
  point_t currentPos = getFrameRect().pos;
  double dx = newPos.x - currentPos.x;
  double dy = newPos.y - currentPos.y;
  move(dx, dy);
}

void smirnov::Parallelogram::move(double dx, double dy)
{
  vertex1.x += dx;
  vertex1.y += dy;
  vertex2.x += dx;
  vertex2.y += dy;
  vertex3.x += dx;
  vertex3.y += dy;
  vertex4.x += dx;
  vertex4.y += dy;
}

void smirnov::Parallelogram::scale(double k)
{
  if (k < 0)
  {
    throw std::invalid_argument("Zoom coefficient must be positive");
  }
  point_t center = getFrameRect().pos;
  vertex1 = {(vertex1.x - center.x) * k + center.x,
      (vertex1.y - center.y) * k + center.y};
  vertex2 = {(vertex2.x - center.x) * k + center.x,
      (vertex2.y - center.y) * k + center.y};
  vertex3 = {(vertex3.x - center.x) * k + center.x,
      (vertex3.y - center.y) * k + center.y};
  vertex4 = {vertex1.x + vertex3.x - vertex2.x,
      vertex1.y + vertex3.y - vertex2.y};
}

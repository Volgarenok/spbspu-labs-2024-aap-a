#include "parallelogram.hpp"
#include <cmath>
#include <algorithm>

smirnov::Parallelogram::Parallelogram(double x1, double y1,
    double x2, double y2, double x3, double y3)
{
  vertex1 = {x1, y1};
  vertex2 = {x2, y2};
  vertex3 = {x3, y3};
  vertex4 = {vertex1.x + vertex3.x - vertex2.x, vertex1.y
      + vertex3.y - vertex2.y};
}

double smirnov::Parallelogram::getArea() const
{
  double base = std::abs(vertex2.x - vertex1.x);
  double height = std::abs(vertex3.y - vertex1.y);
  return base * height;
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
  rectangle_t frameRect;
  frameRect.pos = center;
  frameRect.width = maxX - minX;
  frameRect.height = maxY - minY;
  return frameRect;
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
  point_t center = getFrameRect().pos;
  vertex1.x = (vertex1.x - center.x) * k + center.x;
  vertex1.y = (vertex1.y - center.y) * k + center.y;
  vertex2.x = (vertex2.x - center.x) * k + center.x;
  vertex2.y = (vertex2.y - center.y) * k + center.y;
  vertex3.x = (vertex3.x - center.x) * k + center.x;
  vertex3.y = (vertex3.y - center.y) * k + center.y;
  vertex4 = {vertex1.x + vertex3.x - vertex2.x,
      vertex1.y + vertex3.y - vertex2.y};
}

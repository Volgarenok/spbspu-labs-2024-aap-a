#include "parallelogram.hpp"
#include <cmath>
#include <algorithm>
#include <stdexcept>

bool smirnov::Parallelogram::arePointsUnique(const point_t & p1, const point_t & p2, const point_t & p3)
{
  bool condition = (p1.x == p2.x && p1.y == p2.y);
  condition = condition || (p1.x == p3.x && p1.y == p3.y);
  condition = condition || (p2.x == p3.x && p2.y == p3.y);
  return condition;
}

smirnov::Parallelogram::Parallelogram(point_t p1, point_t p2, point_t p3):
  vertex1_{p1},
  vertex2_{p2},
  vertex3_{p3},
  vertex4_{p1.x + p3.x - p2.x, p1.y + p3.y - p2.y}
{
  if (arePointsUnique(p1, p2, p3))
  {
    throw std::invalid_argument("Points must be unique");
  }
  if (!(p1.y == p2.y || p1.y == p3.y || p2.y == p3.y) && (p1.y != p3.y))
  {
    throw std::invalid_argument("Incorrect coordinates");
  }
}

double smirnov::Parallelogram::getArea() const
{
  double vector1X = vertex1_.x - vertex2_.x;
  double vector1Y = vertex1_.y - vertex2_.y;
  double vector2X = vertex3_.x - vertex2_.x;
  double vector2Y = vertex3_.y - vertex2_.y;
  return std::abs(vector1X * vector2Y - vector1Y * vector2X);
}

smirnov::rectangle_t smirnov::Parallelogram::getFrameRect() const
{
  double minX = std::min({vertex1_.x, vertex2_.x, vertex3_.x, vertex4_.x});
  double maxX = std::max({vertex1_.x, vertex2_.x, vertex3_.x, vertex4_.x});
  double minY = std::min({vertex1_.y, vertex2_.y, vertex3_.y, vertex4_.y});
  double maxY = std::max({vertex1_.y, vertex2_.y, vertex3_.y, vertex4_.y});
  point_t center = {(minX + maxX) / 2, (minY + maxY) / 2};
  return {center, maxX - minX, maxY - minY};
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
  applyMove(vertex1_, dx, dy);
  applyMove(vertex2_, dx, dy);
  applyMove(vertex3_, dx, dy);
  applyMove(vertex4_, dx, dy);
}

void smirnov::Parallelogram::unsafeScale(double k) noexcept
{
  point_t center = getFrameRect().pos;
  applyScale(vertex1_, center, k);
  applyScale(vertex2_, center, k);
  applyScale(vertex3_, center, k);
  applyScale(vertex4_, center, k);
}

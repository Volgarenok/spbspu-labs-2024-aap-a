#include "concave.hpp"
#include <cmath>
#include <stdexcept>
#include "base-types.hpp"

namespace
{
  bool isDupePoint(bocharov::point_t p1, bocharov::point_t p2, bocharov::point_t p3, bocharov::point_t p4)
  {
    bocharov::point_t points[4] = {p1, p2, p3, p4};
    for (std::size_t i = 0; i < 4; i++)
    {
      for (std::size_t j = i + 1; j < 4; j++)
      {
        if (points[i].x == points[j].x && points[i].y == points[j].y)
        {
          return true;
        }
      }
    }
    return false;
  }

  bool isTriangle(bocharov::point_t a, bocharov::point_t b, bocharov::point_t c)
  {
    return !(((a.x == b.x) && (a.x == c.x)) || ((a.y == b.y) && (a.y == c.y)));
  }

  double getMyArea(bocharov::point_t a, bocharov::point_t b, bocharov::point_t c)
  {
    return std::abs((a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)) / 2.0);
  }

  bool isPointInTriangle(bocharov::point_t a, bocharov::point_t b, bocharov::point_t c, bocharov::point_t d)
  {
    constexpr double epsilon = 1e-9;
    double s = getMyArea(a, b, c);
    double s1 = getMyArea(a, b, d);
    double s2 = getMyArea(a, d, c);
    double s3 = getMyArea(d, b, c);
    return std::abs(s - (s1 + s2 + s3)) < epsilon;
  }
}

bocharov::Concave::Concave(point_t a, point_t b, point_t c, point_t d):
  a_(b),
  b_(d),
  c_(c),
  d_(a)
{
  if (!isTriangle(d, b, c) || !isPointInTriangle(a, b, c, d) || isDupePoint(a, b, c, d))
  {
    throw std::invalid_argument("Error witch point for concave");
  }
}

double bocharov::Concave::getArea() const
{
  return std::abs(a_.x * b_.y + b_.x * c_.y + c_.x * d_.y + d_.x * a_.y - b_.x * a_.y - c_.x * b_.y - d_.x * c_.y - a_.x * d_.y) / 2.0;
}
bocharov::rectangle_t bocharov::Concave::getFrameRect() const
{
  double maxX = std::max(a_.x, std::max(b_.x, std::max(c_.x, d_.x)));
  double maxY = std::max(a_.y, std::max(b_.y, std::max(c_.y, d_.y)));
  double minY = std::min(a_.y, std::min(b_.y, std::min(c_.y, d_.y)));
  double minX = std::min(a_.x, std::min(b_.x, std::min(c_.x, d_.x)));
  double height = maxY - minY;
  double width = maxX - minX;
  point_t pos = {minX + (width / 2.0), minY + (height / 2.0)};
  return {width, height, pos};
}
void bocharov::Concave::move(double x, double y)
{
  a_ = movePoint(a_, x, y);
  b_ = movePoint(b_, x, y);
  c_ = movePoint(c_, x, y);
  d_ = movePoint(d_, x, y);
}

void bocharov::Concave::move(point_t point)
{
  double moveX = point.x - d_.x;
  double moveY = point.y - d_.y;
  move(moveX, moveY);
}

void bocharov::Concave::scale(double ratio)
{
  a_ = {scalePoint(a_, d_, ratio).x - d_.x, scalePoint(a_, d_, ratio).y - d_.y};
  b_ = {scalePoint(b_, d_, ratio).x - d_.x, scalePoint(b_, d_, ratio).y - d_.y};
  c_ = {scalePoint(c_, d_, ratio).x - d_.x, scalePoint(c_, d_, ratio).y - d_.y};
}


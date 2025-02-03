#include "parallelogram.hpp"
#include <algorithm>
#include <stdexcept>

maslov::Parallelogram::Parallelogram(point_t p1, point_t p2, point_t p3):
  points_{p1, p2, p3, {p1.x + p3.x - p2.x, p1.y + p3.y - p2.y}}
{
  if ((p1.y != p2.y && p2.y != p3.y) || (p1.y == p3.y))
  {
    throw std::invalid_argument("Parallelogram is not parallel");
  }
}
double maslov::Parallelogram::getArea() const
{
  double heigth = getFrameRect().height;
  double width = std::abs(points_[0].x - points_[1].x);
  return heigth * width;
}
maslov::rectangle_t maslov::Parallelogram::getFrameRect() const
{
  double heigth = std::abs(points_[0].y - points_[2].y);
  double maxX = std::max(std::max(points_[0].x, points_[1].x), std::max(points_[2].x, points_[3].x));
  double minX = std::min(std::min(points_[0].x, points_[1].x), std::min(points_[2].x, points_[3].x));
  double width = maxX - minX;
  double centerX = (points_[0].x + points_[1].x + points_[2].x + points_[3].x) / 4.0;
  double centerY = (points_[0].y + points_[1].y + points_[2].y + points_[3].y) / 4.0;
  return {width, heigth, {centerX, centerY}};
}
void maslov::Parallelogram::move(point_t s)
{
  point_t center = getFrameRect().pos;
  double dx = s.x - center.x;
  double dy = s.y - center.y;
  move(dx, dy);
}
void maslov::Parallelogram::move(double dx, double dy)
{
  points_[0] = {points_[0].x + dx, points_[0].y + dy};
  points_[1] = {points_[1].x + dx, points_[1].y + dy};
  points_[2] = {points_[2].x + dx, points_[2].y + dy};
  points_[3] = {points_[3].x + dx, points_[3].y + dy};
}
void maslov::Parallelogram::scaleWithoutCheck(double k)
{
  point_t center = getFrameRect().pos;
  for (size_t i = 0; i < 4; ++i)
  {
    points_[i] = scalePoint(points_[i], center, k);
  }
}
maslov::Shape * maslov::Parallelogram::clone() const
{
  return new Parallelogram(points_[0], points_[1], points_[2]);
}

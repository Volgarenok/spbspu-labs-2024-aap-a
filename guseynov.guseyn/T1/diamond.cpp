#include "diamond.hpp"
#include <cmath>
#include <stdexcept>
#include <algorithm>

guseynov::Diamond::Diamond(point_t p1, point_t p2, point_t p3)
{
  point_t points[3] = {p1, p2, p3};
  std::sort(points, points + 3, [](const point_t& a, const point_t& b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
  });

  if (points[0].x == points[1].x && points[1].x != points[2].x)
  {
    if (points[0].y == points[1].y)
    {
      throw std::invalid_argument("Invalid diamond parameters");
    }
    highP_ = (points[0].y > points[1].y) ? points[0] : points[1];
    rightP_ = points[2];
    center_ = {points[0].x, points[2].y};
  }
  else if (points[1].x == points[2].x && points[0].x != points[1].x)
  {
    if (points[1].y == points[2].y)
    {
      throw std::invalid_argument("Invalid diamond parameters");
    }
    highP_ = (points[1].y > points[2].y) ? points[1] : points[2];
    rightP_ = points[0];
    center_ = {points[1].x, points[0].y};
  }
  else
  {
    throw std::invalid_argument("Invalid diamond parameters");
  }

  if (highP_.x != center_.x || rightP_.y != center_.y)
  {
    throw std::invalid_argument("Invalid diamond parameters");
  }
}

double guseynov::Diamond::getArea() const
{
  double diag1 = 2 * std::abs(highP_.y - center_.y);
  double diag2 = 2 * std::abs(rightP_.x - center_.x);
  return (diag1 * diag2) / 2.0;
}

guseynov::rectangle_t guseynov::Diamond::getFrameRect() const
{
  double width = 2 * std::abs(rightP_.x - center_.x);
  double height = 2 * std::abs(highP_.y - center_.y);
  return {width, height, center_};
}

void guseynov::Diamond::move(point_t pos)
{
  double moveX = pos.x - center_.x;
  double moveY = pos.y - center_.y;
  highP_.x += moveX;
  highP_.y += moveY;
  rightP_.x += moveX;
  rightP_.y += moveY;
  center_ = pos;
}

void guseynov::Diamond::move(double x, double y)
{
  highP_.x += x;
  highP_.y += y;
  rightP_.x += x;
  rightP_.y += y;
  center_.x += x;
  center_.y += y;
}

void guseynov::Diamond::scaleWithoutCheck(double k)
{
  highP_.y = center_.y + (highP_.y - center_.y) * k;
  rightP_.x = center_.x + (rightP_.x - center_.x) * k;
}

guseynov::Shape * guseynov::Diamond::clone() const
{
  return new Diamond(highP_, rightP_, center_);
}

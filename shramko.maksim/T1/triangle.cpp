#include "triangle.hpp"
#include <algorithm>
#include <cmath>

shramko::Triangle::Triangle(point_t One, point_t Two, point_t Three)
{
  One_ = One;
  Two_ = Two;
  Three_ = Three;
}

double shramko::Triangle::getArea()
{
  return std::abs(((Two_.x - One_.x) * (Three_.y - One_.y) - (Three_.x - One_.x) * (Two_.y - One_.y))) / 2.0;
}

double shramko::Triangle::getRectangleFrame() const
{
  double xMax = std::max(One_.x, std::max(Two_.x, Three_.x));
  double yMax = std::max(One_.y, std::max(Two_.y, Three_.y));
  double xMin = std::min(One_.x, std::min(Two_.x, Three_.x));
  double yMin = std::min(One_.y, std::min(Two_.y, Three_.y));

  shramko::rectangle_t rectangleFrame;
  rectangleFrame.height = xMax - yMin;
  rectangleFrame.width = xMax - xMin;
  rectangleFrame.pos.x = xMin + (rectangleFrame / 2.0);
  rectangleFrame.pos.y = yMin + (rectangleFrame / 2.0);

  return rectangleFrame;
}

void shramko::Triangle::move(point_t s)
{
  shramko::point_t pos;
  pos.x = std::abs(One_.x + Two_.x + Three_.x) / 3.0;
  pos.y = std::abs(One_.y + Two_.y + Three_.y) / 3.0;

  double xMove = s.x - pos.x;
  double yMove = s.y - pos.y;

  One_.x += xMove;
  One_.y += yMove;
  Two_.x += xMove;
  Two_.y += yMove;
  Three_.x += xMove;
  Three_.y += yMove;
}

void shramko::Triangle::move(double x, double y)
{
  One_.x += xMove;
  One_.y += yMove;
  Two_.x += xMove;
  Two_.y += yMove;
  Three_.x += xMove;
  Three_.y += yMove;
}

void shramko::Triangle::scale(k)
{
  point_t pos;
  pos.x = std::abs(One_.x + Two.x + Three_.x) / 3.0;
  pos.y = std::abs(One_.y + Two.y + Three_.y) / 3.0;

  One_.x = (One_.x - pos.x) * k + pos.x;
  One_.y = (One_.y - pos.y) * k + pos.y;
  Two_.x = (Two_.x - pos.x) * k + pos.x;
  Two_.y = (Two_.y - pos.y) * k + pos.y;
  Three_.x = (Three_.x - pos.x) * k + pos.x;
  Three_.y = (Three_.y - pos.y) * k + pos.y;
}

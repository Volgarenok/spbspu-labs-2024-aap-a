#include "triangle.hpp"
#include <stdexcept>
#include <algorithm>
#include <cmath>

shramko::Triangle::Triangle(point_t one, point_t two, point_t three):
  one_(one),
  two_(two),
  three_(three)
{
  double A = distance(one_, two_);
  double B = distance(two_, three_);
  double C = distance(one_, three_);

  if (A + B <= C || B + C <= A || A + C <= B)
  {
    throw std::invalid_argument("Triangle size err\n");
  }
  if (getArea() < 10e-6)
  {
    throw std::invalid_argument("Triangle size err\n");
  }

  center_.x = std::abs(one_.x + two_.x + three_.x) / 3.0;
  center_.y = std::abs(one_.y + two_.y + three_.y) / 3.0;
}

double shramko::Triangle::getArea() const
{
  return std::abs(((one_.x * (two_.y - three_.y) + two_.x * (three_.y - one_.y) + three_.x * (one_.y - two_.y))) / 2.0);
}

shramko::rectangle_t shramko::Triangle::getFrameRect() const
{
  double xMax = std::max(one_.x, std::max(two_.x, three_.x));
  double yMax = std::max(one_.y, std::max(two_.y, three_.y));
  double xMin = std::min(one_.x, std::min(two_.x, three_.x));
  double yMin = std::min(one_.y, std::min(two_.y, three_.y));

  return {xMax - xMin, yMax -  yMin, {(xMin + xMax) / 2.0, (yMin + yMax) / 2.0}};
}

void shramko::Triangle::move(double x, double y)
{
  one_.x += x;
  one_.y += y;

  two_.x += x;
  two_.y += y;

  three_.x += x;
  three_.y += y;
}

void shramko::Triangle::doScale(double k)
{
  const point_t center = getFrameRect().pos;

  one_.x = center.x + (one_.x - center.x) * k;
  one_.y = center.y + (one_.y - center.y) * k;

  two_.x = center.x + (two_.x - center.x) * k;
  two_.y = center.y + (two_.y - center.y) * k;

  three_.x = center.x + (three_.x - center.x) * k;
  three_.y = center.x + (three_.y - center.y) * k;
}

#include "triangle.hpp"
#include "calcLength.hpp"
#include <stdexcept>
#include <algorithm>
#include <cmath>

shramko::Triangle::Triangle(point_t one, point_t two, point_t three):
  one_(one),
  two_(two),
  three_(three)
{
  double lenOne = calcLength(one_, two_), lenTwo = calcLength(two_, three_), lenThree = calcLength(one_, three_);

  if (!(lenOne < (lenTwo + lenThree) && lenTwo < (lenOne + lenThree) && lenThree < (lenOne + lenTwo)))
  {
    throw std::invalid_argument("Triangle size err\n");
  }
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

shramko::Triangle& shramko::Triangle::operator=(shramko::Triangle&& rhs)
{
  one_ = rhs.one_;
  two_ = rhs.two_;
  three_ = rhs.three_;
  return *this;
}

void shramko::Triangle::move(point_t point)
{
  point_t pos;
  pos.x = (one_.x + two_.x + three_.x) / 3.0;
  pos.y = (one_.y + two_.y + three_.y) / 3.0;

  double xMove = point.x - pos.x;
  double yMove = point.y - pos.y;

  this->move(xMove, yMove);
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

void shramko::Triangle::scale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Triangle scale err\n");
  }

  point_t pos;
  pos.x = std::abs(one_.x + two_.x + three_.x) / 3.0;
  pos.y = std::abs(one_.y + two_.y + three_.y) / 3.0;

  one_.x = (one_.x - pos.x) * k + pos.x;
  one_.y = (one_.y - pos.y) * k + pos.y;

  two_.x = (two_.x - pos.x) * k + pos.x;
  two_.y = (two_.y - pos.y) * k + pos.y;

  three_.x = (three_.x - pos.x) * k + pos.x;
  three_.y = (three_.y - pos.y) * k + pos.y;
}

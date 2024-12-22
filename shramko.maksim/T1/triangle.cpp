#include "triangle.hpp"
#include <stdexcept>
#include <algorithm>
#include <cmath>

shramko::Triangle::Triangle(point_t one, point_t two, point_t three)
{
  if ((one.x * (two.y - three.y) + two.x * (three.y - one.y) + three.x * (one.y - two.y)) == 0)
  {
    throw std::invalid_argument("Triangle size err\n");
  }

  one_ = one;
  two_ = two;
  three_ = three;
}

double shramko::Triangle::getArea()
{
  return std::abs(((two_.x - one_.x) * (three_.y - one_.y) - (three_.x - one_.x) * (two_.y - one_.y))) / 2.0;
}

double shramko::Triangle::getRectFrame() const
{
  double xMax = std::max(one_.x, std::max(two_.x, three_.x));
  double yMax = std::max(one_.y, std::max(two_.y, three_.y));
  double xMin = std::min(one_.x, std::min(two_.x, three_.x));
  double yMin = std::min(one_.y, std::min(two_.y, three_.y));

  shramko::rectangle_t rectFrame;
  rectFrame.height = xMax - yMin;
  rectFrame.width = xMax - xMin;
  rectFrame.pos.x = xMin + (rectFrame.width / 2.0);
  rectFrame.pos.y = yMin + (rectFrame.height / 2.0);

  return rectFrame;
}

void shramko::Triangle::move(point_t point)
{
  shramko::point_t pos;
  pos.x = std::abs(one_.x + two_.x + three_.x) / 3.0;
  pos.y = std::abs(one_.y + two_.y + three_.y) / 3.0;

  double xMove = point.x - pos.x;
  double yMove = point.y - pos.y;

  one_.x += xMove;
  one_.y += yMove;
  two_.x += xMove;
  two_.y += yMove;
  three_.x += xMove;
  three_.y += yMove;
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

void shramko::Triangle::scale(k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Triangle scale err\n")
  }

  point_t pos;
  pos.x = std::abs(one_.x + two.x + three_.x) / 3.0;
  pos.y = std::abs(one_.y + two.y + three_.y) / 3.0;

  one_.x = (one_.x - pos.x) * k + pos.x;
  one_.y = (one_.y - pos.y) * k + pos.y;
  two_.x = (two_.x - pos.x) * k + pos.x;
  two_.y = (two_.y - pos.y) * k + pos.y;
  three_.x = (three_.x - pos.x) * k + pos.x;
  three_.y = (three_.y - pos.y) * k + pos.y;
}

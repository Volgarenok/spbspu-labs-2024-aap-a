#include "triangle.hpp"
#include <algorithm>
#include <cmath>
#include <stdexcept>
#include "supportFunctions.hpp"
#include "getLength.hpp"

asafov::Triangle::Triangle(point_t one, point_t two, point_t three):
  one_(one),
  two_(two),
  three_(three)
{
  double sidea = std::pow(std::pow((one.x - two.x), 2.0) + std::pow((one.y - two.y), 2.0), 0.5);
  double sideb = std::pow(std::pow((two.x - three.x), 2.0) + std::pow((two.y - three.y), 2.0), 0.5);
  double sidec = std::pow(std::pow((one.x - three.x), 2.0) + std::pow((one.y - three.y), 2.0), 0.5);
  double temp = (one.x - two.x + one.y - two.y) * (one.x - three.x + one.y - three.y) * (two.x - three.x + two.y - three.y);
  if (temp == 0 || sidea + sideb <= sidec || sidea + sidec <= sideb || sideb + sidec <= sidea)
  {
    throw std::logic_error("incorrect figure");
  }
}

double asafov::Triangle::getArea() const
{
  double sidea = std::pow(std::pow((one_.x - two_.x), 2.0) + std::pow((one_.y - two_.y), 2.0), 0.5);
  double sideb = std::pow(std::pow((two_.x - three_.x), 2.0) + std::pow((two_.y - three_.y), 2.0), 0.5);
  double sidec = std::pow(std::pow((one_.x - three_.x), 2.0) + std::pow((one_.y - three_.y), 2.0), 0.5);
  return std::pow(((sidea + sideb + sidec) * (sidea + sideb - sidec) * (sidea - sideb + sidec) * (sideb + sidec - sidea) / 16.0), 0.5);
}

asafov::rectangle_t asafov::Triangle::getFrameRect() const
{
  double height = asafov::getLength({one_.y, two_.y, three_.y});
  double width = asafov::getLength({one_.x, two_.x, three_.x});
  double x = std::min({one_.x, two_.x, three_.x}) + width / 2.0;
  double y = std::min({one_.y, two_.y, three_.y}) + height / 2.0;
  rectangle_t rect;
  rect.height = height;
  rect.width = width;
  rect.pos.x = x;
  rect.pos.y = y;
  return rect;
}

void asafov::Triangle::move(double dx, double dy)
{
  one_.x += dx;
  one_.y += dy;
  two_.x += dx;
  two_.y += dy;
  three_.x += dx;
  three_.y += dy;
}

void asafov::Triangle::move(point_t pos)
{
  rectangle_t rect = getFrameRect();
  move(pos.x - rect.pos.x, pos.y - rect.pos.y);
}

void asafov::Triangle::scale(double scale)
{
  if (scale <= 0)
  {
    throw std::logic_error("incorrect scale");
  }
  rectangle_t rect = getFrameRect();
  scalePoint(one_, rect.pos, scale);
  scalePoint(two_, rect.pos, scale);
  scalePoint(three_, rect.pos, scale);
}

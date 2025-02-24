#include "triangle.hpp"
#include <algorithm>
#include <cmath>
#include <stdexcept>
#include "supportFunctions.hpp"

asafov::Triangle::Triangle(point_t one, point_t two, point_t three):
  points_{one, two, three}
{
  double sidea = getLength(one, two);
  double sideb = getLength(two, three);
  double sidec = getLength(one, three);
  double temp = (one.x - two.x + one.y - two.y) * (one.x - three.x + one.y - three.y) * (two.x - three.x + two.y - three.y);
  if (temp == 0 || sidea + sideb <= sidec || sidea + sidec <= sideb || sideb + sidec <= sidea)
  {
    throw std::logic_error("incorrect figure");
  }
}

double asafov::Triangle::getArea() const
{
  double sidea = getLength(points_[0], points_[1]);
  double sideb = getLength(points_[1], points_[2]);
  double sidec = getLength(points_[0], points_[2]);;
  return std::pow(((sidea + sideb + sidec) * (sidea + sideb - sidec) * (sidea - sideb + sidec) * (sideb + sidec - sidea) / 16.0), 0.5);
}

asafov::rectangle_t asafov::Triangle::getFrameRect() const
{
  double height = asafov::getCenterDelta(points_[0].y, points_[1].y, points_[2].y);
  double width = asafov::getCenterDelta(points_[0].x, points_[1].x, points_[2].x);
  double x = std::min({points_[0].x, points_[1].x, points_[2].x}) + width / 2.0;
  double y = std::min({points_[0].y, points_[1].y, points_[2].y}) + height / 2.0;
  rectangle_t rect{width, height, {x, y}};
  return rect;
}

void asafov::Triangle::move(double dx, double dy)
{
  for (size_t i = 0; i < 3; i++)
  {
    increaseDelta(points_[i], dx, dy);
  }
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
  for (size_t i = 0; i < 3; i++)
  {
    scalePoint(points_[i], rect.pos, scale);
  }
}

#include "complexquad.hpp"
#include <algorithm>
#include <cmath>
#include <stdexcept>
#include "supportFunctions.hpp"

asafov::Complexquad::Complexquad(point_t one, point_t two, point_t three, point_t four):
  points_{ one, two, three, four }
{
  double temp = (one.x - two.x + one.y - two.y) * (one.x - three.x + one.y - three.y) * (one.x - four.x + one.y - four.y);
  if (temp * (two.x - three.x + two.y - three.y) * (two.x - four.x + two.y - four.y) * (three.x - four.x + three.y - four.y) == 0)
  {
    throw std::logic_error("incorrect figure");
  }
}

double asafov::Complexquad::getArea() const
{
  double cx = getCenterDelta(points_[0].x, points_[1].x, points_[2].x, points_[3].x);
  double cy = getCenterDelta(points_[0].y, points_[1].y, points_[2].y, points_[3].y);
  point_t center = { cx, cy };
  double sidea = getLength(points_[0], points_[3]);
  double sideb = getLength(points_[0], center);
  double sidec = getLength(points_[3], center);
  double semiarea = (sidea + sideb + sidec) * (sidea + sideb - sidec) * (sidea - sideb + sidec);
  semiarea *= (sideb + sidec - sidea) / 16.0;
  semiarea = std::pow(semiarea, 0.5);
  sidea = getLength(points_[1], points_[2]);
  sideb = getLength(points_[1], center);
  sidec = getLength(points_[2], center);
  double temp = (sidea + sideb + sidec) * (sidea + sideb - sidec) * (sidea - sideb + sidec);
  temp *= (sideb + sidec - sidea) / 16;
  return semiarea + std::pow(temp, 0.5);
}

asafov::rectangle_t asafov::Complexquad::getFrameRect() const
{
  double height = getCenterDelta(points_[0].x, points_[1].x, points_[2].x, points_[3].x);
  double width = getCenterDelta(points_[0].y, points_[1].y, points_[2].y, points_[3].y);
  double x = std::min( { points_[0].x, points_[1].x, points_[2].x, points_[3].x } ) + width / 2.0;
  double y = std::min( { points_[0].y, points_[1].y, points_[2].y, points_[3].y } ) + height / 2.0;
  rectangle_t rect = { width, height, { x, y } };
  return rect;
}

void asafov::Complexquad::move(double dx, double dy)
{
  for (size_t i = 0; i < 4; i++)
  {
    increaseDelta(points_[i], dx, dy);
  }
}

void asafov::Complexquad::move(point_t pos)
{
  double centerx = getCenterDelta(points_[0].x, points_[1].x, points_[2].x, points_[3].x);
  double centery = getCenterDelta(points_[0].y, points_[1].y, points_[2].y, points_[3].y);
  move(centerx - pos.x, centery - pos.y);
}

void asafov::Complexquad::doUnsafeScale(double k)
{
  rectangle_t rect = getFrameRect();
  for (size_t i = 0; i < 4; i++)
  {
    scalePoint(points_[i], rect.pos, k);
  }
}

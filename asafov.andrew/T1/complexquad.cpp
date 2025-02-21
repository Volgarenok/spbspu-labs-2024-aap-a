#include "complexquad.hpp"
#include <algorithm>
#include <cmath>
#include "supportFunctions.hpp"
#include "getLength.hpp"

asafov::Complexquad::Complexquad(point_t one, point_t two, point_t three, point_t four):
  one_(one),
  two_(two),
  three_(three),
  four_(four)
{}

double asafov::Complexquad::getArea() const
{
  point_t center = {};
  center.x = getLength({one_.x, two_.x, three_.x, four_.x});
  center.y = getLength({one_.y, two_.y, three_.y, four_.y});
  double sidea = std::pow(std::pow((one_.x - four_.x), 2.0) + std::pow((one_.y - four_.y), 2.0), 0.5);
  double sideb = std::pow(std::pow((four_.x - center.x), 2.0) + std::pow((four_.y - center.y), 2.0), 0.5);
  double sidec = std::pow(std::pow((one_.x - center.x), 2.0) + std::pow((one_.y - center.y), 2.0), 0.5);
  double semiarea = (sidea + sideb + sidec) * (sidea + sideb - sidec) * (sidea - sideb + sidec);
  semiarea *= (sideb + sidec - sidea) / 16.0;
  semiarea = std::pow(semiarea, 0.5);
  sidea = std::pow(std::pow((two_.x - three_.x), 2.0) + std::pow((two_.y - three_.y), 2.0), 0.5);
  sideb = std::pow(std::pow((two_.x - center.x), 2.0) + std::pow((two_.y - center.y), 2.0), 0.5);
  sidec = std::pow(std::pow((three_.x - center.x), 2.0) + std::pow((three_.y - center.y), 2.0), 0.5);
  double temp = (sidea + sideb + sidec) * (sidea + sideb - sidec) * (sidea - sideb + sidec);
  temp *= (sideb + sidec - sidea) / 16;
  return semiarea + std::pow(temp, 0.5);
}

asafov::rectangle_t asafov::Complexquad::getFrameRect() const
{
  double height = getLength({one_.x, two_.x, three_.x, four_.x});
  double width = getLength({one_.y, two_.y, three_.y, four_.y});
  double x = std::min({ one_.x, two_.x, three_.x, four_.x }) + width / 2.0;
  double y = std::min({ one_.y, two_.y, three_.y, four_.y }) + height / 2.0;
  rectangle_t rect;
  rect.height = height;
  rect.width = width;
  rect.pos.x = x;
  rect.pos.y = y;
  return rect;
}

void asafov::Complexquad::move(double dx, double dy)
{
  one_.x += dx;
  one_.y += dy;
  two_.x += dx;
  two_.y += dy;
  three_.x += dx;
  three_.y += dy;
  four_.x += dx;
  four_.y += dy;
}

void asafov::Complexquad::move(point_t pos)
{
  point_t center = {};
  center.x = getLength({one_.y, two_.y, three_.y, four_.y});
  center.y = getLength({one_.y, two_.y, three_.y, four_.y});
  move(center.x - pos.x, center.y - pos.y);
}

void asafov::Complexquad::scale(double scale)
{
  rectangle_t rect = getFrameRect();
  scalePoint(one_, rect.pos, scale);
  scalePoint(two_, rect.pos, scale);
  scalePoint(three_, rect.pos, scale);
  scalePoint(four_, rect.pos, scale);
}

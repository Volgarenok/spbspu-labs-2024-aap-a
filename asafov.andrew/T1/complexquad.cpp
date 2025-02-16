#include "complexquad.hpp"
#include <algorithm>
#include <cmath>

using asafov::point_t;
using asafov::rectangle_t;

asafov::Complexquad::Complexquad(point_t one, point_t two, point_t three, point_t four) :
  one_(one),
  two_(two),
  three_(three),
  four_(four)
{}

double asafov::Complexquad::getArea() const
{
  point_t center = {};
  center.x = std::max({ one_.x, two_.x, three_.x, four_.x }) - std::min({ one_.x, two_.x, three_.x, four_.x });
  center.y = std::max({ one_.y, two_.y, three_.y, four_.y }) - std::min({ one_.y, two_.y, three_.y, four_.y });
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

rectangle_t asafov::Complexquad::getFrameRect() const
{
  rectangle_t rect;
  rect.height = std::max({ one_.y, two_.y, three_.y, four_.y }) - std::min({ one_.y, two_.y, three_.y, four_.y });
  rect.width = std::max({ one_.x, two_.x, three_.x, four_.x }) - std::min({ one_.x, two_.x, three_.x, four_.x });
  rect.pos.x = std::min({ one_.x, two_.x, three_.x, four_.x }) + rect.width / 2.0;
  rect.pos.y = std::min({ one_.y, two_.y, three_.y, four_.x }) + rect.height / 2.0;
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
  center.x = std::max({ one_.x, two_.x, three_.x, four_.x }) - std::min({ one_.x, two_.x, three_.x, four_.x });
  center.y = std::max({ one_.y, two_.y, three_.y, four_.y }) - std::min({ one_.y, two_.y, three_.y, four_.y });
  one_.x += center.x - pos.x;
  two_.x += center.x - pos.x;
  three_.x += center.x - pos.x;
  four_.x += center.x - pos.x;
  one_.y += center.y - pos.y;
  two_.y += center.y - pos.y;
  three_.y += center.y - pos.y;
  four_.y += center.y - pos.y;
}

void asafov::Complexquad::scale(double scale)
{
  rectangle_t rect = getFrameRect();
  one_.x += (one_.x - rect.pos.x) * (scale - 1);
  one_.y += (one_.y - rect.pos.y) * (scale - 1);
  two_.x += (two_.x - rect.pos.x) * (scale - 1);
  two_.y += (two_.y - rect.pos.y) * (scale - 1);
  three_.x += (three_.x - rect.pos.x) * (scale - 1);
  three_.y += (three_.y - rect.pos.y) * (scale - 1);
  four_.x += (four_.x - rect.pos.x) * (scale - 1);
  four_.y += (four_.y - rect.pos.y) * (scale - 1);
}

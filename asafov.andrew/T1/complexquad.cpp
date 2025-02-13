#include "complexquad.hpp"
#include <algorithm>
#include <cmath>

using asafov::point_t;
using asafov::rectangle_t;

asafov::Complexquad::Complexquad(point_t a, point_t b, point_t c, point_t d) :
  one(a),
  two(b),
  three(c),
  four(d)
{}

double asafov::Complexquad::getArea() const
{
  point_t center = {};
  center.x = std::max({ one.x, two.x, three.x, four.x }) - std::min({ one.x, two.x, three.x, four.x });
  center.y = std::max({ one.y, two.y, three.y, four.y }) - std::min({ one.y, two.y, three.y, four.y });
  double sidea = std::pow(std::pow((one.x - four.x), 2.0) + std::pow((one.y - four.y), 2.0), 0.5);
  double sideb = std::pow(std::pow((four.x - center.x), 2.0) + std::pow((four.y - center.y), 2.0), 0.5);
  double sidec = std::pow(std::pow((one.x - center.x), 2.0) + std::pow((one.y - center.y), 2.0), 0.5);
  double semiarea = (sidea + sideb + sidec) * (sidea + sideb - sidec) * (sidea - sideb + sidec);
  semiarea *= (sideb + sidec - sidea) / 16.0;
  semiarea = std::pow(semiarea, 0.5);
  sidea = std::pow(std::pow((two.x - three.x), 2.0) + std::pow((two.y - three.y), 2.0), 0.5);
  sideb = std::pow(std::pow((two.x - center.x), 2.0) + std::pow((two.y - center.y), 2.0), 0.5);
  sidec = std::pow(std::pow((three.x - center.x), 2.0) + std::pow((three.y - center.y), 2.0), 0.5);
  double temp = (sidea + sideb + sidec) * (sidea + sideb - sidec) * (sidea - sideb + sidec);
  temp *= (sideb + sidec - sidea) / 16;
  return semiarea + std::pow(temp, 0.5);
}

rectangle_t asafov::Complexquad::getFrameRect() const
{
  rectangle_t rect;
  rect.height = std::max({ one.y, two.y, three.y, four.y }) - std::min({ one.y, two.y, three.y, four.y });
  rect.width = std::max({ one.x, two.x, three.x, four.x }) - std::min({ one.x, two.x, three.x, four.x });
  rect.pos.x = std::min({ one.x, two.x, three.x, four.x }) + rect.width / 2.0;
  rect.pos.y = std::min({ one.y, two.y, three.y, four.x }) + rect.height / 2.0;
  return rect;
}

void asafov::Complexquad::move(double x, double y)
{
  one.x += x;
  one.y += y;
  two.x += x;
  two.y += y;
  three.x += x;
  three.y += y;
  four.x += x;
  four.y += y;
}

void asafov::Complexquad::move(point_t pos)
{
  point_t center = {};
  center.x = std::max({ one.x, two.x, three.x, four.x }) - std::min({ one.x, two.x, three.x, four.x });
  center.y = std::max({ one.y, two.y, three.y, four.y }) - std::min({ one.y, two.y, three.y, four.y });
  one.x += center.x - pos.x;
  two.x += center.x - pos.x;
  three.x += center.x - pos.x;
  four.x += center.x - pos.x;
  one.y += center.y - pos.y;
  two.y += center.y - pos.y;
  three.y += center.y - pos.y;
  four.y += center.y - pos.y;
}

void asafov::Complexquad::scale(double scale)
{
  rectangle_t rect = getFrameRect();
  one.x += (one.x - rect.pos.x) * (scale - 1);
  one.y += (one.y - rect.pos.y) * (scale - 1);
  two.x += (two.x - rect.pos.x) * (scale - 1);
  two.y += (two.y - rect.pos.y) * (scale - 1);
  three.x += (three.x - rect.pos.x) * (scale - 1);
  three.y += (three.y - rect.pos.y) * (scale - 1);
  four.x += (four.x - rect.pos.x) * (scale - 1);
  four.y += (four.y - rect.pos.y) * (scale - 1);
}

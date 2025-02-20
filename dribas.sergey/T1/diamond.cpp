#include "diamond.hpp"
#include <cmath>
#include <stdexcept>
#include "triangle.hpp"
#include "getShapeInfo.hpp"
dribas::point_t * initialDiamond(dribas::point_t a, dribas::point_t b, dribas::point_t c)
{
  double weight = 0.0;
  double height = 0.0;
  dribas::point_t point[3] = {};

  if ((a.x == b.x && a.y == c.y) || (a.y == b.y && a.x == c.x)) {
    if (a.x == b.x && a.y == c.y) {
      weight = std::abs(std::abs(a.x) - std::abs(b.x));
      height = std::abs(std::abs(a.y) - std::abs(c.y));
    } else {
      height = std::abs(std::abs(a.y) - std::abs(b.y));
      weight = std::abs(std::abs(a.x) - std::abs(c.x));
    }
   point[1] = a;
   point[2] = {a.x, a.y + height};
   point[3] = {a.x - weight, a.y};

  } else if ((b.x == a.x && b.y == c.y) || (b.y == a.y && b.x == c.x)) {
    if (b.x == a.x && b.y == c.y) {
      weight = std::abs(std::abs(b.x) - std::abs(a.x));
      height = std::abs(std::abs(b.y) - std::abs(c.y));
    } else {
      height = std::abs(std::abs(b.y) - std::abs(a.y));
      weight = std::abs(std::abs(b.x) - std::abs(c.x));
    }
    point[1] = b;
    point[2] = {b.x, b.y + height};
    point[3] = {b.x - weight, b.y};
  } else if ((c.x == a.x && c.y == b.y) || (c.y == a.y && c.x == b.x)) {
    if (c.x == a.x && c.y == b.y) {
      weight = std::abs(std::abs(c.x) - std::abs(a.x));
      height = std::abs(std::abs(c.y) - std::abs(b.y));
    } else {
      height = std::abs(std::abs(c.y) - std::abs(a.y));
      weight = std::abs(std::abs(c.x) - std::abs(b.x));
    }
    point[1] = c;
    point[2] = {c.x, c.y + height};
    point[3] = {c.x - weight, c.y};
  } else {
    throw std::invalid_argument("error with diamond size");
  }
  dribas::point_t* ptrPoint = point;

  return ptrPoint;
}
dribas::Diamond::Diamond(point_t a, point_t b, point_t c):
  a_({a, b, c}),
  b_({a, a, {c.x - 2 * std::abs(std::abs(b.x) - std::abs(a.x)), c.y}}),
  c_({a, {b.x, b.y - 2 * std::abs(std::abs(a.y) - std::abs(c.y))}, {c.x - std::abs(std::abs(b.x) - std::abs(a.x)), c.y}}),
  d_({a, {b.x, b.y - 2 * std::abs(std::abs(a.y) - std::abs(c.y))}, c})
{}

double dribas::Diamond::getArea() const
{
  return a_.getArea() * 4.0f ;
}

dribas::rectangle_t dribas::Diamond::getFrameRect() const
{
  rectangle_t fremRect = a_.getFrameRect();
  fremRect.width = fremRect.width * 2.0;
  fremRect.height = fremRect.height * 2.0;
  return fremRect;
}

void dribas::Diamond::move(double x, double y)
{
  a_.move(x, y);
  b_.move(x, y);
  c_.move(x, y);
  d_.move(x, y);
}

void dribas::Diamond::move(point_t point)
{
  double moveX = point.x - this->getFrameRect().pos.x;
  double moveY = point.y - this->getFrameRect().pos.y;
  move(moveX, moveY);
}

void dribas::Diamond::scale(double ratio)
{
  if (ratio <= 0) {
    throw std::invalid_argument("under zero ratio");
  }
  scaleOne(a_, ratio, this->getFrameRect().pos);
  scaleOne(b_, ratio, this->getFrameRect().pos);
  scaleOne(c_, ratio, this->getFrameRect().pos);
  scaleOne(d_, ratio, this->getFrameRect().pos);
}

dribas::Shape* dribas::Diamond::clone() const
{
  return new Diamond(*this);
}

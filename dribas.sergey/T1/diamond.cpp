#include "diamond.hpp"
#include <cmath>
#include <stdexcept>
#include "triangle.hpp"
#include "getShapeInfo.hpp"
dribas::Triangle * initialDiamond(dribas::point_t a, dribas::point_t b, dribas::point_t c)
{
  double weight = 0.0;
  double height = 0.0;
  dribas::Triangle a_ = dribas::Triangle{{0.0, 0.0}, {1.0, 0.0}, {1.0, 1.0}};
  dribas::Triangle b_ = dribas::Triangle{{0.0, 0.0}, {1.0, 0.0}, {1.0, 1.0}};
  dribas::Triangle c_ = dribas::Triangle{{0.0, 0.0}, {1.0, 0.0}, {1.0, 1.0}};
  dribas::Triangle d_ = dribas::Triangle{{0.0, 0.0}, {1.0, 0.0}, {1.0, 1.0}};

  if ((a.x == b.x && a.y == c.y) || (a.y == b.y && a.x == c.x)) {
    if (a.x == b.x && a.y == c.y) {
      weight = std::abs(std::abs(a.x) - std::abs(b.x));
      height = std::abs(std::abs(a.y) - std::abs(c.y));
    } else {
      height = std::abs(std::abs(a.y) - std::abs(b.y));
      weight = std::abs(std::abs(a.x) - std::abs(c.x));
    }
    a_ = dribas::Triangle{a, {a.x - weight, a.y}, {a.x, a.y + height}};
    b_ = dribas::Triangle{a, {a.x + weight, a.y}, {a.x, a.y + height}};
    c_ = dribas::Triangle{a, {a.x + weight, a.y}, {a.x, a.y - height}};
    d_ = dribas::Triangle{a, {a.x - weight, a.y}, {a.x, a.y - height}};

  } else if ((b.x == a.x && b.y == c.y) || (b.y == a.y && b.x == c.x)) {
    if (b.x == a.x && b.y == c.y) {
      weight = std::abs(std::abs(b.x) - std::abs(a.x));
      height = std::abs(std::abs(b.y) - std::abs(c.y));
    } else {
      height = std::abs(std::abs(b.y) - std::abs(a.y));
      weight = std::abs(std::abs(b.x) - std::abs(c.x));
    }
    a_ = dribas::Triangle{b, {b.x - weight, b.y}, {b.x, b.y + height}};
    b_ = dribas::Triangle{b, {b.x + weight, b.y}, {b.x, b.y + height}};
    c_ = dribas::Triangle{b, {b.x + weight, b.y}, {b.x, b.y - height}};
    d_ = dribas::Triangle{b, {b.x - weight, b.y}, {b.x, b.y - height}};
  } else if ((c.x == a.x && c.y == b.y) || (c.y == a.y && c.x == b.x)) {
    if (c.x == a.x && c.y == b.y) {
      weight = std::abs(std::abs(c.x) - std::abs(a.x));
      height = std::abs(std::abs(c.y) - std::abs(b.y));
    } else {
      height = std::abs(std::abs(c.y) - std::abs(a.y));
      weight = std::abs(std::abs(c.x) - std::abs(b.x));
    }
    a_ = dribas::Triangle{c, {c.x - weight, c.y}, {c.x, c.y + height}};
    b_ = dribas::Triangle{c, {c.x + weight, c.y}, {c.x, c.y + height}};
    c_ = dribas::Triangle{c, {c.x + weight, c.y}, {c.x, c.y - height}};
    d_ = dribas::Triangle{c, {c.x - weight, c.y}, {c.x, c.y - height}};
  } else {
    throw std::invalid_argument("error with diamond size");
  }
  dribas::Triangle triangle[4] = {a_, b_, c_, d_};
  dribas::Triangle* trianglePtr = triangle;
  return trianglePtr;
}
dribas::Diamond::Diamond(point_t a, point_t b, point_t c):
  a_(Triangle{a, b, c}),
  b_(Triangle{b, a, c}),
  c_(Triangle{c, a, b}),
  d_(Triangle{c, b, a})
{
  try {
    Triangle * dmnd = initialDiamond(a, b, c);
    a_ = dmnd[0];
    b_ = dmnd[1];
    c_ = dmnd[2];
    d_ = dmnd[3];
  } catch(...) {
    throw;
  }
}

double dribas::Diamond::getArea() const
{
  return a_.getArea() * 4.0f ;
}

dribas::rectangle_t dribas::Diamond::getFrameRect() const
{
  rectangle_t fremRECT = a_.getFrameRect();
  rectangle_t myFremRect;
  myFremRect.pos = {fremRECT.pos.x + fremRECT.width / 2.0, fremRECT.pos.y - fremRECT.height / 2.0};
  fremRECT.width = fremRECT.width * 2.0;
  fremRECT.height = fremRECT.height * 2.0;
  return fremRECT;
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

#include "makeShape.hpp"
#include <stdexcept>

sharifullina::Rectangle* sharifullina::makeRectangle(std::istream& in)
{
  double p1 = 0.0;
  double p2 = 0.0;
  double p3 = 0.0;
  double p4 = 0.0;
  in >> p1 >> p2 >> p3 >> p4;
  point_t lowLeft = { p1, p2 };
  point_t uppRight = { p3, p4 };
  if (lowLeft.x >= uppRight.x || lowLeft.y >= uppRight.y)
  {
    throw std::invalid_argument("Incorrect coordinates");
  }
  sharifullina::Rectangle* rect = new sharifullina::Rectangle(lowLeft, uppRight);
  return rect;
}

sharifullina::Ring* sharifullina::makeRing(std::istream& in)
{
  double p1 = 0.0;
  double p2 = 0.0;
  double r1 = 0.0;
  double r2 = 0.0;
  in >> p1 >> p2 >> r1 >> r2;
  point_t center = { p1, p2 };
  if (r1 <= 0 || r2 <= 0 || r1 >= r2)
  {
    throw std::invalid_argument("Incorrect radius");
  }
  sharifullina::Ring* rin9 = new sharifullina::Ring(center, r1, r2);
  return rin9;
}

sharifullina::Circle* sharifullina::makeCircle(std::istream& in)
{
  double p1 = 0.0;
  double p2 = 0.0;
  double r = 0.0;
  in >> p1 >> p2 >> r;
  point_t center = { p1, p2 };
  if (r <= 0)
  {
    throw std::invalid_argument("Incorrect radius");
  }
  sharifullina::Circle* circl = new sharifullina::Circle(center, r);
  return circl;
}

sharifullina::Ellipse* sharifullina::makeEllipse(std::istream& in)
{
  double p1 = 0.0;
  double p2 = 0.0;
  double r1 = 0.0;
  double r2 = 0.0;
  in >> p1 >> p2 >> r1 >> r2;
  point_t center = { p1, p2 };
  if (r1 <= 0 || r2 <= 0)
  {
    throw std::invalid_argument("Incorrect radius");
  }
  sharifullina::Ellipse* ellips = new sharifullina::Ellipse(center, r2, r1);
  return ellips;
}

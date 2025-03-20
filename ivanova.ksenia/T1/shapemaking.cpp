#include "shapemaking.hpp"
#include "tools.hpp"

ivanova::Rectangle* ivanova::createRectangle(std::istream& input)
{
  double x1, y1, x2, y2;
  input >> x1 >> y1 >> x2 >> y2;
  ivanova::Rectangle* rect = new ivanova::Rectangle({ x1, y1 }, { x2, y2 });
  return rect;
}

ivanova::Concave* ivanova::createConcave(std::istream& input)
{
  point_t p1, p2, p3, p4;
  input >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;
  double l12 = vectorLength(p1, p2);
  double l13 = vectorLength(p1, p3);
  double l23 = vectorLength(p2, p3);
  if ((l12 >= l23 + l13) || (l23 >= l12 + l13) || (l13 >= l12 + l23))
  {
    throw std::invalid_argument("Points p1, p2, p3 do not form a valid triangle");
  }
  double A = (p1.x-p4.x)*(p2.y-p1.y)-(p2.x-p1.x)*(p1.y-p4.y);
  double B = (p2.x-p4.x)*(p3.y-p2.y)-(p3.x-p2.x)*(p2.y-p4.y);
  double C = (p3.x-p4.x)*(p1.y-p3.y)-(p1.x-p3.x)*(p3.y-p4.y);
  if (!((A > 0) && (B > 0) && (C > 0) || (A < 0) && (B < 0) && (C < 0)))
  {
    throw std::invalid_argument("Point p4 is not inside the triangle formed by p1, p2, p3");
  }
  ivanova::Concave* cncv = new ivanova::Concave(p1, p2, p3, p4);
  return cncv;
}

ivanova::Diamond* ivanova::createDiamond(std::istream& input)
{
  point_t p1, p2, p3;
  input >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
  if (p1.x == p2.x) {
    if (p1.y == p2.y)
    {
      throw std::invalid_argument("All points are the same");
    }
    else if (p1.y == p3.y)
    {
      return new Diamond(p2, p3, p1);
    }
    else if (p2.y == p3.y)
    {
      return new Diamond(p1, p3, p2);
    }
  }
  else if (p1.x == p3.x) {
    if (p1.y == p2.y)
    {
      return new Diamond(p3, p2, p1);
    }
    else if (p1.y == p3.y)
    {
      throw std::invalid_argument("Two points are the same");
    }
    else if (p2.y == p3.y)
    {
      return new Diamond(p1, p2, p3);
    }
  }
  else if (p2.x == p3.x) {
    if (p1.y == p2.y)
    {
      return new Diamond(p3, p1, p2);
    }
    else if (p1.y == p3.y)
    {
      return new Diamond(p2, p1, p3);
    }
    else if (p2.y == p3.y)
    {
      throw std::invalid_argument("Two points are the same");
    }
  }
  else
  {
    throw std::invalid_argument("Invalid configuration of points");
  }
  ivanova::Diamond* dmnd = new ivanova::Diamond(p1, p2, p3);
  return dmnd;
}

ivanova::Complexquad* ivanova::createComplexquad(std::istream& input)
{
  double x1, y1, x2, y2, x3, y3, x4, y4;
  input >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
  ivanova::Complexquad* cmpl = new ivanova::Complexquad({ x1, y1 }, { x2, y2 }, { x3, y3 }, { x4, y4 });
  return cmpl;
}

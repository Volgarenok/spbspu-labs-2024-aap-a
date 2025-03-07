#include "shapemaking.hpp"

ivanova::Rectangle* ivanova::createRectangle(std::istream& input)
{
  double x1 = 0, y1 = 0, x2 = 0, y2 = 0;
  input >> x1 >> y1 >> x2 >> y2;
  if (x1 >= x2 || y1 >= y2)
  {
    throw std::invalid_argument("Incorrect parameters!");
  }
  ivanova::Rectangle* rect = new ivanova::Rectangle({ x1, y1 }, { x2, y2 });
  return rect;
}

ivanova::Concave* ivanova::createConcave(std::istream& input)
{
  double x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0, x4 = 0, y4 = 0;
  input >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
  ivanova::Concave* cncv = new ivanova::Concave({ x1, y2 }, { x2, y2 }, { x3, y3 }, { x4, y4 });
  return cncv;
}

ivanova::Diamond* ivanova::createDiamond(std::istream& input)
{
  point_t p1, p2, p3;
  input >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;

  if ((p1.x == p2.x && p1.y == p2.y) || (p1.x == p3.x && p1.y == p3.y) || (p2.x == p3.x && p2.y == p3.y))
  {
    throw std::invalid_argument("Incorrect parameters!");
  }

  ivanova::Diamond* dmnd = new ivanova::Diamond(p1, p2, p3);
  return dmnd;
}

ivanova::Complexquad* ivanova::createComplexquad(std::istream& input)
{
  double x1, y1, x2, y2, x3, y3, x4, y4;
  input >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
  ivanova::Complexquad* cmpl = new ivanova::Complexquad({ x1, y2 }, { x2, y2 }, { x3, y3 }, { x4, y4 });
  return cmpl;
}

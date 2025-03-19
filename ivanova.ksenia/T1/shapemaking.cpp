#include "shapemaking.hpp"

ivanova::Rectangle* ivanova::createRectangle(std::istream& input)
{
  double x1, y1, x2, y2;
  input >> x1 >> y1 >> x2 >> y2;
  ivanova::Rectangle* rect = new ivanova::Rectangle({ x1, y1 }, { x2, y2 });
  return rect;
}

ivanova::Concave* ivanova::createConcave(std::istream& input)
{
  double x1, y1, x2, y2, x3, y3, x4, y4;
  input >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
  ivanova::Concave* cncv = new ivanova::Concave({ x1, y1 }, { x2, y2 }, { x3, y3 }, { x4, y4 });
  return cncv;
}

ivanova::Diamond* ivanova::createDiamond(std::istream& input)
{
  point_t p1, p2, p3;
  input >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
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

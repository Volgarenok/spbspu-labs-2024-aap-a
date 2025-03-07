#include "createShapes.hpp"
#include "concave.hpp"
#include "auxiliaryFunctions.hpp"

lebedev::point_t lebedev::chooseScalePoint(std::istream& input)
{
  double x = 0, y = 0;
  input >> x >> y;
  return { x, y };
}

lebedev::Rectangle* lebedev::createRectangle(std::istream& input)
{
  double x1 = 0, y1 = 0, x2 = 0, y2 = 0;
  input >> x1 >> y1 >> x2 >> y2;
  return new Rectangle({ x1, y1 }, { x2, y2 });
}

lebedev::Diamond* lebedev::createDiamond(std::istream& input)
{
  point_t p1, p2, p3;
  input >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;

  sortPoints(p1, p2, p3);
  return new Diamond(p2, p3, p1);
}

lebedev::Concave* lebedev::createConcave(std::istream& input)
{
  double x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0, x4 = 0, y4 = 0;
  input >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

  return new Concave({ x1, y1 }, { x2, y2 }, { x3, y3 }, { x4, y4 });
}

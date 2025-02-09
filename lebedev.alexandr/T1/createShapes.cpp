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
  if (x1 >= x2 || y1 >= y2)
  {
    throw std::invalid_argument("Incorrect parameters!");
  }
  lebedev::Rectangle* rect = new lebedev::Rectangle({ x1, y1 }, { x2, y2 });
  return rect;
}

lebedev::Diamond* lebedev::createDiamond(std::istream& input)
{
  point_t p1, p2, p3;
  input >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;

  if ((p1.x == p2.x && p1.y == p2.y) || (p1.x == p3.x && p1.y == p3.y) || (p2.x == p3.x && p2.y == p3.y))
  {
    throw std::invalid_argument("");
  }
  
  lebedev::sortPoints(p1, p2, p3);

  if (!((p1.x == p2.x && p3.y == p2.y)
      || (p1.y == p2.y && p3.x == p2.x)
      || (p1.x == p3.x && p2.y == p3.y)
      || (p1.y == p3.y && p2.x == p3.x)))
  {
    throw std::invalid_argument("");
  }

  return new lebedev::Diamond(p1, p2, p3);
}

lebedev::Concave* lebedev::createConcave(std::istream& input)
{
  double x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0, x4 = 0, y4 = 0;
  input >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
  if (!isTriangle({ x1, y2 }, { x2, y2 }, { x3, y3 }))
  {
    throw std::invalid_argument("");
  }
  else if (!isPointInsideTriangle({ x1, y2 }, { x2, y2 }, { x3, y3 }, { x4, y4 }))
  {
    throw std::invalid_argument("");
  }
  else
  {
    lebedev::Concave* cncv = new lebedev::Concave({ x1, y2 }, { x2, y2 }, { x3, y3 }, { x4, y4 });
    return cncv;
  }
}

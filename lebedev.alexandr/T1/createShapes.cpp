#include "createShapes.hpp"
#include "concave.hpp"
#include "auxiliaryFunctions.hpp"

lebedev::point_t lebedev::createScalePoint(std::istream& input)
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
  double x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0;
  input >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

  if ((x1 == x2 && y1 == y2) || (x1 == x3 && y1 == y3) || (x2 == x3 && y2 == y3))
  {
    throw std::invalid_argument("");
  }
  else if (x1 == x2 && y1 == y3)
  {
    lebedev::Diamond* dmnd = new lebedev::Diamond({ x1, y1 }, { x2, y2 }, { x3, y3 });
    return dmnd;
  }
  else if (x1 == x3 && y1 == y2)
  {
    lebedev::Diamond* dmnd = new lebedev::Diamond({ x1, y1 }, { x3, y3 }, { x2, y2 });
    return dmnd;
  }
  else if (x2 == x1 && y2 == y3)
  {
    lebedev::Diamond* dmnd = new lebedev::Diamond({ x2, y2 }, { x1, y1 }, { x3, y3 });
    return dmnd;
  }
  else if (x2 == x3 && y2 == y1)
  {
    lebedev::Diamond* dmnd = new lebedev::Diamond({ x2, y2 }, { x3, y3 }, { x1, y1 });
    return dmnd;
  }
  else if (x3 == x2 && y3 == y1)
  {
    lebedev::Diamond* dmnd = new lebedev::Diamond({ x3, y3 }, { x2, y2 }, { x1, y1 });
    return dmnd;
  }
  else if (x3 == x1 && y3 == y2)
  {
    lebedev::Diamond* dmnd = new lebedev::Diamond({ x3, y3 }, { x1, y1 }, { x2, y2 });
    return dmnd;
  }
  else
  {
    throw std::invalid_argument("");
  }
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

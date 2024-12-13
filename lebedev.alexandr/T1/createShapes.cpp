#include "createShapes.hpp"

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

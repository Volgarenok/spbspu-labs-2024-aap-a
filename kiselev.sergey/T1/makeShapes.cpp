#include "makeShapes.hpp"
#include <stdexcept>
#include "base-types.hpp"
#include "diamond.hpp"
kiselev::Rectangle* kiselev::make_rectangle(std::istream& input)
{
  double x1 = 0;
  double y1 = 0;
  double x2 = 0;
  double y2 = 0;
  input >> x1 >> y1 >> x2 >> y2;
  if (x1 >= x2 || y1 >= y2)
  {
    throw std::invalid_argument("Incorrect parameters");
  }
  kiselev::Rectangle* rect = new kiselev::Rectangle({ x1, y1 }, { x2, y2 });
  return rect;
}
kiselev::point_t kiselev::make_scale(std::istream& input)
{
  double x = 0;
  double y = 0;
  input >> x >> y;
  return { x, y };
}
kiselev::Diamond* kiselev::make_diamond(std::istream& input)
{
  double x1 = 0;
  double x2 = 0;
  double x3 = 0;
  double y1 = 0;
  double y2 = 0;
  double y3 = 0;
  input >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  if (x1 == x2 && y1 == y3)
  {

    kiselev::Diamond* diam = new kiselev::Diamond({ x1, y1 }, { x2, y2 }, { x3, y3 });
    return diam;
  }
  else if (x1 == x3 && y1 == y2)
  {
    kiselev::Diamond* diam = new kiselev::Diamond({ x1, y1 }, { x3, y3 }, { x2, y2 });
    return diam;
  }
  else if (x2 == x1 && y2 == y3)
  {
    kiselev::Diamond* diam = new kiselev::Diamond({ x2, y2 }, { x1, y1 }, { x3, y3 });
    return diam;
  }
  else if (x2 == x3 && y2 == y1)
  {
    kiselev::Diamond* diam = new kiselev::Diamond({ x2, y2 }, { x3, y3 }, { x1, y1 });
    return diam;
  }
  else if (x3 == x1 && y3 == y2)
  {
    kiselev::Diamond* diam = new kiselev::Diamond({ x3, y3 }, { x1, y1 }, { x2, y2 });
    return diam;
  }
  else if (x3 == x2 && y3 == y1)
  {
    kiselev::Diamond* diam = new kiselev::Diamond({ x3, y3 }, { x2, y2 }, { x1, y1 });
    return diam;
  }
  else
  {
    throw std::invalid_argument("");
  }
}

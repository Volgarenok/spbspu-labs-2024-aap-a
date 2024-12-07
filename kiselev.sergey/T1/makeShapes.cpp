#include "makeShapes.hpp"
#include <stdexcept>
#include "base-types.hpp"
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

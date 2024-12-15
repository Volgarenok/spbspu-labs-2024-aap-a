#include "shapeBreeding.hpp"
#include <cmath>
#include <stdexcept>
#include "base-types.hpp"

namespace kushekbaev
{
  Rectangle* makeRectangle(std::istream& input)
  {
    double x1 = 0;
    double y1 = 0;
    double x2 = 0;
    double y2 = 0;
    input >> x1 >> y1 >> x2 >> y2;
    if (x1 >= x2 || y1 >= y2)
    {
      throw std::invalid_argument("Left point values should be less than right point values\n");
    }
    Rectangle* rect = new Rectangle({ x1, y1 }, { x2, y2 });
    return rect;
  }

  point_t makeScale(std::istream& input)
  {
    double x = 0;
    double y = 0;
    input >> x >> y;
    return { x, y };
  }
}

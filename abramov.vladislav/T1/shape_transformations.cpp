#include "shape_transformations.hpp"
#include <iostream>

namespace abramov
{
  void printFrameRectCoords(const abramov::rectangle_t& r)
  {
    double x1 = r.pos.x - r.width / 2;
    double y1 = r.pos.y - r.height / 2;
    double x2 = r.pos.x + r.width / 2;
    double y2 = r.pos.y + r.height / 2;
    std::cout << x1 << " " << y1 << " ";
    std::cout << x2 << " " << y2 << " ";
  }
}

#include "shape_transformations.hpp"
#include <iostream>

namespace abramov
{
  void printFrameRectCoords(const abramov::rectangle_t &r)
  {
    double x1 = r.pos.x - r.width / 2;
    double y1 = r.pos.y - r.height / 2;
    double x2 = r.pos.x + r.width / 2;
    double y2 = r.pos.y + r.height / 2;
    std::cout << x1 << " " << y1 << " ";
    std::cout << x2 << " " << y2 << " ";
  }
  void scaleFigure(Shape *r, point_t p, double k)
  {
    point_t pos1 = r->getFrameRect().pos;
    r->move(p);
    point_t pos2 = r->getFrameRect().pos;
    double dx = pos2.x - pos1.x;
    double dy = pos2.y - pos1.y;
    r->scale(k);
    dx *= -1 * k;
    dy *= -1 * k;
    r->move(dx, dy);
  }
}

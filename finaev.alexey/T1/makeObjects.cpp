#include "makeObjects.h"
#include <iostream>
#include <string>

namespace finaev
{
  Rectangle* makeRectangle(std::istream& in)
  {
    double x0 = 0, y0 = 0, x1 = 0, y1 = 0;
    in >> x0 >> y0 >> x1 >> y1;
    point_t l, r;
    l.x = x0;
    l.y = y0;
    r.x = x1;
    r.y = y1;
    Rectangle* rectangle = new Rectangle(l, r);
    return rectangle;
  }
}

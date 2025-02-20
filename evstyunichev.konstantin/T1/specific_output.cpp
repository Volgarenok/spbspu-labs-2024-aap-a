#include "specific_output.hpp"
#include <iomanip>
#include <iostream>
#include "base-types.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "regular.hpp"
#include "ring.hpp"
#include "shape.hpp"

void evstyunichev::frameOutput(rectangle_t a, std::ostream &out)
{
  size_t default_prec = out.precision();
  out << std::setprecision(1) << a.pos.x  - a.width * 0.5 << ' ' <<
    a.pos.y - a.height * 0.5 << ' ' << a.pos.x + a.width * 0.5 << ' ' <<
    a.pos.y + a.height * 0.5 << std::setprecision(default_prec);
  return;
}

std::ostream & evstyunichev::framesOut(Shape **shapes, size_t size, std::ostream &out)
{
  frameOutput(shapes[0]->getFrameRect());
  for (size_t i = 1; i < size; i++)
  {
    out << ' ';
    frameOutput(shapes[i]->getFrameRect());
  }
  return out;
}

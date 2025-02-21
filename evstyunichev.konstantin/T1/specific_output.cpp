#include "specific_output.hpp"
#include <cmath>
#include <iomanip>
#include <iostream>
#include "base-types.hpp"
#include "circle.hpp"
#include "composite_shape.hpp"
#include "rectangle.hpp"
#include "regular.hpp"
#include "ring.hpp"
#include "shape.hpp"

void evstyunichev::frameOutput(rectangle_t a, std::ostream &out)
{
  out << std::fixed << std::setprecision(1) << (a.pos.x  - a.width * 0.5) << ' ' <<
    (a.pos.y - a.height * 0.5) << ' ' << (a.pos.x + a.width * 0.5) << ' ' <<
    (a.pos.y + a.height * 0.5);
  return;
}

std::ostream &evstyunichev::framesOut(CompositeShape &cmp, std::ostream &out)
{
  frameOutput(cmp[0]->getFrameRect());
  for (size_t i = 1; i < cmp.size(); i++)
  {
    out << ' ';
    frameOutput(cmp[i]->getFrameRect());
  }
  return out;
}

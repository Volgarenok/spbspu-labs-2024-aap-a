#include "specific_output.hpp"
#include <cmath>
#include <iomanip>
#include <iostream>
#include "composite_shape.hpp"

void evstyunichev::frameOutput(rectangle_t a, std::ostream &out)
{
  double data[4]{ (a.pos.x  - a.width * 0.5), (a.pos.y - a.height * 0.5), (a.pos.x + a.width * 0.5), (a.pos.y + a.height * 0.5) };
  out << std::fixed << std::setprecision(1) << data[0];
  for (size_t i = 1; i < 4; i++)
  {
    out << " " << data[i];
  }
  return;
}

std::ostream & evstyunichev::framesOut(CompositeShape &cmp, std::ostream &out)
{
  frameOutput(cmp[0]->getFrameRect());
  for (size_t i = 1; i < cmp.size(); i++)
  {
    out << " ";
    frameOutput(cmp[i]->getFrameRect());
  }
  return out;
}

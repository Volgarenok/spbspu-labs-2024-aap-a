#include "shape_actions.hpp"
#include <iomanip>
#include <iostream>
#include "base-types.hpp"
#include "composite_shape.hpp"
#include "specific_output.hpp"

void evstyunichev::makeScale(CompositeShape &cmp, std::istream &in)
{
  if (cmp.empty())
  {
    throw std::logic_error("nothing to scale!");
  }
  double d[3];
  for (size_t i = 0; i < 3; i++)
  {
    in >> d[i];
  }
  point_t O{ d[0], d[1] };
  std::cout << std::fixed << std::setprecision(1) << cmp.getArea() << ' ';
  framesOut(cmp) << '\n' << cmp.getArea() * d[2] * d[2] << ' ';
  cmp.scale(d[2], O);
  framesOut(cmp) << '\n';
}

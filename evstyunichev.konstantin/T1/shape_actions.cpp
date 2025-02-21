#include "shape_actions.hpp"
#include <iomanip>
#include <iostream>
#include "base-types.hpp"
#include "composite_shape.hpp"
#include "specific_output.hpp"

void evstyunichev::makeScale(CompositeShape &cmp, std::istream &in)
{
  double x = 0, y = 0, k = 0;
  in >> x >> y >> k;
  point_t O{x, y};
  std::cout << std::fixed << std::setprecision(1) << cmp.getArea() << ' ';
  framesOut(cmp) << '\n' << cmp.getArea() * k * k << ' ';
  cmp.scale(k, O);
  framesOut(cmp) << '\n';
}

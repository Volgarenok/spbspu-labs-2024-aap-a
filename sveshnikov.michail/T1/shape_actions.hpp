#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP
#include <iostream>
#include "shape.hpp"

namespace sveshnikov
{
  void isotropic_scaling(Shape **shapes, double zoom_ctr_x, double zoom_ctr_y, double k);
  void output_total_area(std::ostream &out, Shape **shapes);
  void output_frame(std::ostream &out, Shape **shapes);
}

#endif

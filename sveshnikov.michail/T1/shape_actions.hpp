#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP
#include <iostream>
#include "composite-shape.hpp"

namespace sveshnikov
{
  void isotropic_scaling(CompositeShape &comp_shp, double zoom_ctr_x, double zoom_ctr_y, double k);
  void output_one_frame(std::ostream &out, const Shape *shp);
  void output_frames(std::ostream &out, const CompositeShape &comp_shp);
}

#endif

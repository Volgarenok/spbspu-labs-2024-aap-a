#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP
#include <iostream>
#include "composite-shape.hpp"

namespace sveshnikov
{
  void isotropicScaling(CompositeShape &comp_shp, double zoom_ctr_x, double zoom_ctr_y, double k);
  void outputOneFrame(std::ostream &out, const Shape *shp);
  void outputFrames(std::ostream &out, const CompositeShape &comp_shp);
}

#endif

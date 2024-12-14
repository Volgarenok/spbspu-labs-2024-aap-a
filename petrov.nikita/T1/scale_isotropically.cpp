#include "scale_isotropically.hpp"
#include "base-types.hpp"
#include "shape.hpp"
#include <iostream>
void petrov::scaleIsotropically(point_t scale_point, size_t k, Shape * shape)
{
  point_t pos = shape[0].getFrameRect();
  double mv_dx = pos.x_ - scale_point.x_;
  double mv_dy = pos.y_ - scale_point.y_;
  shape[0].move(scale_point);
  shape[0].scale(k);
  shape[0].getArea();
  mv_dx *= k;
  mv_dy *= k;
  shape[0].move(-mv_dx, -mv_dy);
}
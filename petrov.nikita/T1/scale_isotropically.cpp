#include "scale_isotropically.hpp"
#include "base-types.hpp"
#include "shape.hpp"
#include <iostream> // Remove after debug
void petrov::scaleIsotropically(point_t scale_point, double k, Shape * shape)
{
  point_t pos = shape[0].getFrameRect();
  std::clog << pos.x_ << " " << pos.y_ << "\n"; // Remove after debug
  double mv_dx = pos.x_ - scale_point.x_;
  double mv_dy = pos.y_ - scale_point.y_;
  std::clog << mv_dx << " " << mv_dy << "\n"; // Remove after debug
  shape[0].move(scale_point);
  shape[0].scale(k);
  shape[0].getArea();
  mv_dx *= k;
  mv_dy *= k;
  shape[0].move(mv_dx, mv_dy);
}
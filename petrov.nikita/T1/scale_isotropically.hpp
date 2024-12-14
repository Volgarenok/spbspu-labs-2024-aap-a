#ifndef SCALE_ISOTROPICALLY_HPP
#define SCALE_ISOTROPICALLY_HPP
#include "shape.hpp"
#include "cstddef"
namespace petrov
{
  void scale(point_t scale_point, size_t k, Shape * shape)
  {
    point_t pos = shape[0].getFrameRect();
    shape[0].move(scale_point);
    double mv_dx = pos.x_ - scale_point.x_;
    double mv_dy = pos.y_ - scale_point.y_;
    shape[0].scale(k);
    mv_dx *= k;
    mv_dy *= k;
    shape[0].move(mv_dx, mv_dy);
  }
}
#endif
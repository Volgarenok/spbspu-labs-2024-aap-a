#include "base-types.hpp"
nikonov::point_t::point_t():
  x(0),
  y(0)
{}
nikonov::point_t::point_t(double x, double  y):
  x(x),
  y(y)
{}
nikonov::rectangle_t::rectangle_t(point_t lbp, point_t rtp):
  width(rtp.x - lbp.x),
  height(rtp.y - lbp.y),
  pos(lbp.x + (width / 2), lbp.y + (height / 2))
{}

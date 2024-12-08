#include "base-types.hpp"
nikonov::point_t::point_t():
  x_(0),
  y_(0)
{}
nikonov::point_t::point_t(float x, float y):
  x_(x),
  y_(y)
{}
nikonov::rectangle_t::rectangle_t(point_t lbp, point_t rtp):
  width_(rtp.x_ - lbp.x_),
  height_(rtp.y_ - lbp.y_),
  pos_(lbp.x_ + (width_ / 2), lbp.y_ + (height_ / 2))
{}

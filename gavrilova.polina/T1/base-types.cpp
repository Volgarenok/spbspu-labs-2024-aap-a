#include "base-types.hpp"

namespace gavrilova {
  point_t& point_t::operator=(const point_t& rhs) {
    x = rhs.x;
    y = rhs.y;
  }
  void point_t::move(double difX, double difY) {
    x += difX;
    y += difY;
  }
}
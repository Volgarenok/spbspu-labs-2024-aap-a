#include "base-types.hpp"

namespace gavrilova {
  void point_t::move(double difX, double difY) {
    x += difX;
    y += difY;
  }
}

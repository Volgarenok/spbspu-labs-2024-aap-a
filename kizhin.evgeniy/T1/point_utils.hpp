#ifndef POINT_UTIlS_HPP
#define POINT_UTIlS_HPP

#include "base-types.hpp"

namespace kizhin {
  double computeDistanceSqr(const point_t&, const point_t&);
  bool isRightTriangle(const point_t&, const point_t&, const point_t&);
}

#endif

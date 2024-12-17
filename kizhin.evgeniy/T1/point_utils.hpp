#ifndef POINT_UTIlS_HPP
#define POINT_UTIlS_HPP

#include <cstddef>
#include "base-types.hpp"

namespace kizhin {
  constexpr double epsilon = 1e-6;
  double computeDistance(const point_t&, const point_t&);
  bool isRightTriangle(const point_t&, const point_t&, const point_t&);
  double* computeEdgeCords(const point_t*, size_t);
}

kizhin::point_t& operator+=(kizhin::point_t&, const kizhin::point_t&);

#endif


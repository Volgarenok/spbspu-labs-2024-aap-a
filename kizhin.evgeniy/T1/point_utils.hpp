#ifndef KIZHIN_T1_POINT_UTIlS_HPP
#define KIZHIN_T1_POINT_UTIlS_HPP

#include <cstddef>
#include "base-types.hpp"

namespace kizhin {
  constexpr double epsilon = 1e-6;
  constexpr double pi = 3.14159265358979323846;
  double computeDistance(const point_t&, const point_t&);
  bool isRightTriangle(const point_t&, const point_t&, const point_t&);
  double* computeEdgeCords(const point_t*, size_t);
  point_t& operator+=(point_t&, const point_t&);
}

#endif


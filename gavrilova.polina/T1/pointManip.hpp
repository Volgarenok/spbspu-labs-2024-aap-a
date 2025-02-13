#ifndef POINTMANIP_HPP
#define POINTMANIP_HPP
#include "base-types.hpp"
namespace gavrilova {
  void move(point_t& p, double difX, double difY) noexcept;
  double getDistance(const point_t& p, const point_t& other) noexcept;
  void scaleDistance(point_t& p, point_t& other, double k);
}
#endif

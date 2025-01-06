#include "base-types.hpp"
#include <cmath>
#include <stdexcept>

void gavrilova::point_t::move(double difX, double difY) noexcept {
  x += difX;
  y += difY;
}
double gavrilova::point_t::getDistance(gavrilova::point_t other) noexcept{
  return std::sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2));
}
void gavrilova::point_t::scaleDistance(gavrilova::point_t other, double k) {
  if (k <= 0) {
    throw std::logic_error("Коэффицент должен быть положительным");
  }
  x = other.x - (other.x - x) * k;
  y = other.y - (other.y - y) * k;
}

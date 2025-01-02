#include "rectangle.hpp"

zholobov::Rectangle::Rectangle(const point_t& a, const point_t& c):
  Parallelogram(a, point_t{a.x, c.y}, c)
{}

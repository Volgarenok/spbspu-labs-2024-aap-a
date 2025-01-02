#include "square.hpp"

zholobov::Square::Square(const point_t& a, double length):
  Rectangle(a, point_t{a.x + length, a.y + length})
{}

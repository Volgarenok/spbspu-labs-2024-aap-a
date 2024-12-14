#include "square.hpp"

Square::Square():
  Rectangle()
{}

Square::Square(const point_t& a, float length):
  Rectangle(a, point_t{a.x + length, a.y + length})
{}

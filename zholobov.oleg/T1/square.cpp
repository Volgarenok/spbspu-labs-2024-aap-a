#include "square.hpp"

zholobov::Square::Square():
  Rectangle()
{}

zholobov::Square::Square(const point_t& a, float length):
  Rectangle(a, point_t{a.x + length, a.y + length})
{}

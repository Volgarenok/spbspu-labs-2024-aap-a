#include "base-types.hpp"
#include <iostream>

std::istream& gavrilova::input_point(std::istream& in, point_t& p)
{
  return (in >> p.x >> p.y);
}
std::istream& gavrilova::input_points(std::istream& in, point_t* points, size_t n)
{
  for (size_t i = 0; i < n; ++i) {
    input_point(in, points[i]);
  }
  return in;
}
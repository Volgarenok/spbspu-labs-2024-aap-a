#include "base-types.hpp"
#include <iostream>

std::istream& gavrilova::operator>>(std::istream& in, gavrilova::point_t& ob)
{
  return (in >> ob.x >> ob.y);
}
std::istream& gavrilova::input_points(std::istream& in, point_t* points, size_t n)
{
  for (size_t i = 0; i < n; ++i) {
    in >> *(points + i);
  }
  return in;
}

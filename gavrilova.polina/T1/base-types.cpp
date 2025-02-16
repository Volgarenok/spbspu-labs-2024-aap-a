#include "base-types.hpp"
#include <iostream>

std::istream& gavrilova::inputPoint(std::istream& in, point_t& ob)
{
  return (in >> ob.x >> ob.y);
}
std::istream& gavrilova::inputPoints(std::istream& in, point_t* points, size_t n)
{
  for (size_t i = 0; i < n; ++i) {
    inputPoint(in, points[i]);
  }
  return in;
}

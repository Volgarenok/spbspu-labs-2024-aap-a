#include "base-types.hpp"
#include <iostream>

std::istream& gavrilova::input_point(std::istream& in, point_t& p)
{
  return (in >> p.x >> p.y);
}

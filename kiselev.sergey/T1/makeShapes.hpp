#ifndef MAKESHAPES_HPP
#define MAKESHAPES_HPP
#include <istream>
#include <string>
#include "composite-shape.hpp"
namespace kiselev
{
  point_t makeScale(std::istream& input);
  bool makeShape(std::istream& input, const std::string& str, CompositeShape& compShp);
}
#endif

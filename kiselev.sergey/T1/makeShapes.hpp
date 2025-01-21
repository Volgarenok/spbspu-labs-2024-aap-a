#ifndef MAKESHAPES_HPP
#define MAKESHAPES_HPP
#include <istream>
#include <string>
#include "base-types.hpp"
#include "composite-shape.hpp"
namespace kiselev
{
  point_t makeScale(std::istream& input);
  bool makeShape(std::istream& input, std::string & str, kiselev::CompositeShape & compShp);
}
#endif

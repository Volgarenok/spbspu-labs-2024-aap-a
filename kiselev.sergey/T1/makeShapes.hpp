#ifndef MAKESHAPES_HPP
#define MAKESHAPES_HPP
#include <istream>
#include <string>
#include "shape.hpp"
namespace kiselev
{
  point_t makeScale(std::istream& input);
  Shape* makeShape(std::istream& input, const std::string& str);
}
#endif

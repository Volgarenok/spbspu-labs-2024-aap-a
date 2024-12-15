#ifndef SHAPEBREEDING_HPP
#define SHAPEBREEDING_HPP

#include <istream>

#include "rectangle.hpp"

namespace kushekbaev
{
  Rectangle* makeRectangle(std::istream& input);
  point_t makeScale(std::istream& input);
}

#endif

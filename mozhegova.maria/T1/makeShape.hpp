#ifndef MAKESHAPE_HPP
#define MAKESHAPE_HPP

#include <iostream>
#include "rectangle.hpp"
#include "diamond.hpp"
#include "polygon.hpp"

namespace mozhegova
{
  Rectangle * makeRectangle(std::istream& in);
  Diamond * makeDiamond(std::istream& in);
  Polygon * makePolygon(std::istream& in);
}

#endif

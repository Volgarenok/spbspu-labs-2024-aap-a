#ifndef CREATESHAPE_HPP
#define CREATESHAPE_HPP

#include <istream>
#include "rectangle.hpp"
#include "triangle.hpp"
#include "diamond.hpp"

namespace shramko
{
  Rectangle* createRectangle(std::istream& in);
  Triangle* createTriangle(std::istream& in);
  Diamond* createDiamond(std::istream& in);
}

#endif

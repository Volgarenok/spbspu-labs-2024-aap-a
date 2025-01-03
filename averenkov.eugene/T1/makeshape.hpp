#ifndef MAKESHAPE_HPP
#define MAKESHAPE_HPP
#include "rectangle.hpp"
#include "ellipse.hpp"
#include "diamond.hpp"
#include <iostream>

namespace averenkov
{
  Rectangle* makeRectangle(std::istream& in);
  Diamond* makeDiamond(std::istream& in);
  Ellipse* makeEllipse(std::istream& in);
}
#endif

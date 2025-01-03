#ifndef MAKESHAPE_HPP
#define MAKESHAPE_HPP
#include <iostream>
#include "rectangle.hpp"
#include "ellipse.hpp"
#include "circle.hpp"

namespace duhanina
{
  Rectangle* makeRectangle(std::istream& in);
  Circle* makeCircle(std::istream& in);
  Ellipse* makeEllipse(std::istream& in);
}

#endif

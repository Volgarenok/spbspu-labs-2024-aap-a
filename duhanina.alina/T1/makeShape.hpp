#ifndef MAKESHAPE_HPP
#define MAKESHAPE_HPP
#include "rectangle.hpp"
#include "ellipse.hpp"
#include "circle.hpp"
#include <iostream>

namespace duhanina
{
  duhanina::Rectangle* makeRectangle(std::istream& in);
  duhanina::Circle* makeCircle(std::istream& in, bool& incorrectRadius);
  duhanina::Ellipse* makeEllipse(std::istream& in, bool& incorrectRadius);
}

#endif

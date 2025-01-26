#ifndef MAKESHAPE_HPP
#define MAKESHAPE_HPP

#include <iostream>
#include "rectangle.hpp"
#include "ring.hpp"
#include "circle.hpp"
#include "ellipse.hpp"

namespace sharifullina
{
  Rectangle * makeRectangle(std::istream& in);
  Ring * makeRing(std::istream& in);
  Circle * makeCircle(std::istream& in);
  Ellipse * makeEllipse(std::istream& in);
  Shape * createShape(std::istream& in, const std::string& shapeType);
  void readParams(std::istream& in, double * params, size_t size);
}

#endif

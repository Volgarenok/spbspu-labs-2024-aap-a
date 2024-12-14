#ifndef MAKESHAPE_H
#define MAKESHAPE_H

#include "rectangle.hpp"
#include "ellipse.hpp"
#include "circle.hpp"
#include "shape.hpp"
#include <string>

namespace aleksandrov
{
  Rectangle* makeRectangle(const std::string rectangleParams, bool& error);
  Ellipse* makeEllipse(const std::string ellipseParams, bool& error);
  Circle* makeCircle(const std::string circleParams, bool& error);
  Shape* makeShape(const std::string shapeDescription, bool& error);
}

#endif


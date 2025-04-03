#ifndef SHAPEMANIPULATIONS_HPP
#define SHAPEMANIPULATIONS_HPP

#include <iostream>
#include "base-types.hpp"
#include "shape.hpp"
#include "composite-shape.hpp"

namespace kushekbaev
{
  void output(std::ostream& out, CompositeShape& compShape, const point_t& scalePoint, double scaleCoeff);
  void outputSum(std::ostream& out, const CompositeShape& compShape);
  void outputPoints(std::ostream& out, const CompositeShape& compShape);
  void scaleToPoint(Shape* object, const point_t& t, double scaleCoeff);
  void scaleNoCheck(CompositeShape& compShape, const point_t& scalePoint, double scaleCoeff);
  void scaleCheck(CompositeShape& compShape, const point_t& scalePoint, double scaleCoeff);
}

#endif

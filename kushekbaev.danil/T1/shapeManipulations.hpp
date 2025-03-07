#ifndef SHAPEMANIPULATIONS_HPP
#define SHAPEMANIPULATIONS_HPP

#include <iostream>
#include "base-types.hpp"
#include "shape.hpp"
#include "composite-shape.hpp"

namespace kushekbaev
{
  void output(std::ostream& out, CompositeShape& shaps, const point_t& point, double k);
  void scaleToPoint(Shape* object, const point_t& t, double k);
  void outputPoints(std::ostream& out, const CompositeShape& shaps);
  void outputSum(std::ostream& out, const CompositeShape& shaps);
  void scaleNoCheck(CompositeShape& shaps, const point_t& point, double k);
  void scaleCheck(CompositeShape& shaps, const point_t& point, double k);
}

#endif

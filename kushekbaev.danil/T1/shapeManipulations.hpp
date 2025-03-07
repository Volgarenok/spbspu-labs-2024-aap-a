#ifndef SHAPEMANIPULATIONS_HPP
#define SHAPEMANIPULATIONS_HPP

#include <iostream>
#include "base-types.hpp"
#include "shape.hpp"
#include "composite-shape.hpp"

namespace kushekbaev
{
  void output(std::ostream& out, CompositeShape& shaps, const point_t& point, double k);
  void scale_point(Shape* object, const point_t& t, double k);
  void output_points(std::ostream& out, const CompositeShape& shaps);
  void output_sum(std::ostream& out, const CompositeShape& shaps);
  void scaleNoCheck(CompositeShape& shaps, const point_t& point, double k);
  void scaleCheck(CompositeShape& shaps, const point_t& point, double k);
}

#endif

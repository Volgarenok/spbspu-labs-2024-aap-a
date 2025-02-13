#ifndef SHAPEMANIP_HPP
#define SHAPEMANIP_HPP
#include <ostream>
#include "shape.hpp"
#include "compositeShape.hpp"

namespace gavrilova {
  void scaleShapeWithoutCheck(Shape& shape, const point_t& center, double k);
  void scaleShape(Shape& shape, const point_t& center, double k);
  void scaleShapes(CompositeShape& Shapes, const point_t& center, double k);
  void outRectangle(std::ostream& out, const rectangle_t& rect);
  void outRectangles(std::ostream& out, const CompositeShape& Shapes);
}
#endif

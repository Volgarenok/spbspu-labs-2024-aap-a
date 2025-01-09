#ifndef SHAPEMANIP_HPP
#define SHAPEMANIP_HPP
#include <ostream>
#include "shape.hpp"
namespace gavrilova {
  void scaleShape_without_check(Shape& shape, const point_t& center, double k);
  void scaleShape(Shape& shape, const point_t& center, double k);
  double scaleShapes(Shape** Shapes, size_t nShapes, const point_t& center, double k);
  void outRectangle(std::ostream& out, const rectangle_t& rect);
  void outRectangles(std::ostream& out, Shape** Shapes, size_t nShapes);
  void clearShapes(Shape** Shapes, size_t n);
}
#endif

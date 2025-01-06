#ifndef SHAPEMANIP_HPP
#define SHAPEMANIP_HPP
#include "shape.hpp"
#include <ostream>
namespace gavrilova {
  void scaleShape(Shape& shape, const point_t& center, double k);
  void scaleShapes(Shape** Shapes, size_t nShapes, const point_t& center, double k, double& areaAfter);
  void outRectangles(std::ostream& out, gavrilova::Shape** Shapes, size_t nShapes) noexcept;
  void clearShapes(Shape** Shapes, size_t n);
}
#endif

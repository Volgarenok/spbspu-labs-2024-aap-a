#ifndef PROCESSHAPE_HPP
#define PROCESSHAPE_HPP
#include <cstddef>
#include "shape.hpp"

namespace cherkasov
{
  double getSumArea(const Shape* const * shapes, size_t shape);
  void deleteShapes(Shape** shapes, size_t shape);
  void getCoordinates(const Shape* const* shapes, size_t shape);
  void getScaling(Shape** shapes, size_t shape, point_t p, double k);
}
#endif

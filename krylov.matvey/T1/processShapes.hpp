#ifndef PROCESSSHAPES_HPP
#define PROCESSSHAPES_HPP

#include <cstddef>
#include "shape.hpp"

namespace krylov
{
  Shape* createRectangle();
  Shape* createTriangle();
  Shape* createRing();
  Shape* createComplexquad();
  void deleteShapes(Shape** shapes, size_t shapeCount);
  void printAreaAndFrameCoords(Shape** shapes, size_t shapeCount, double totalArea);
}

#endif

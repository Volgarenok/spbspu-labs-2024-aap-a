#ifndef PROCESSSHAPES_HPP
#define PROCESSSHAPES_HPP

#include <cstddef>
#include <istream>
#include "shape.hpp"

namespace krylov
{
  Shape* createRectangle(std::istream &in);
  Shape* createTriangle(std::istream &in);
  Shape* createRing(std::istream &in);
  Shape* createComplexquad(std::istream &in);
  void deleteShapes(Shape** shapes, size_t shapeCount);
  void printAreaAndFrameCoords(Shape** shapes, size_t shapeCount, double totalArea);
}

#endif

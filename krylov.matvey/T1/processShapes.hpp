#ifndef PROCESSSHAPES_HPP
#define PROCESSSHAPES_HPP

#include <cstddef>
#include <istream>
#include "shape.hpp"
#include "rectangle.hpp"
#include "ring.hpp"
#include "complexquad.hpp"
#include "triangle.hpp"

namespace krylov
{
  void getArray(std::istream &in, double *array, const size_t k);
  Rectangle* makeRectangle(std::istream &in);
  Triangle* makeTriangle(std::istream &in);
  Complexquad* makeComplexquad(std::istream &in);
  Ring* makeRing(std::istream &in);
  Shape* makeShape(std::string str, std::istream& in);
  void isoScale(std::istream &in, Shape** shapes, size_t shapeCount);
  void printInfoAboutShapes(const Shape* const* shapes, size_t shapeCount);
  void deleteShapes(Shape** shapes, size_t shapeCount);
  void printAreaAndFrameCoords(const rectangle_t& frame);
}

#endif

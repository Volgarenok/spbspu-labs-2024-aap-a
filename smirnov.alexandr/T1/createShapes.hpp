#ifndef CREATESHAPES_HPP
#define CREATESHAPES_HPP
#include <istream>
#include <string>
#include "rectangle.hpp"
#include "diamond.hpp"
#include "square.hpp"
#include "parallelogram.hpp"

namespace smirnov
{
  Rectangle * createRectangle(std::istream & in);
  Diamond * createDiamond(std::istream & in);
  Square * createSquare(std::istream & in);
  Parallelogram * createParallelogram(std::istream & in);
  void inputCoords(double * coordsArray, size_t count, std::istream & in);
  Shape * createShapes(std::istream & in, const std::string & shapeType);
}
#endif

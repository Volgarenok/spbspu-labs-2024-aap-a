#ifndef SHAPECREATION_HPP
#define SHAPECREATION_HPP

#include <iostream>
#include "shape.hpp"
#include "concave.hpp"
#include "rectangle.hpp"
#include "diamond.hpp"
#include "parallelogram.hpp"
#include "composite-shape.hpp"

namespace kushekbaev
{
  Rectangle* makeRectangle(std::istream& in);
  Concave* makeConcave(std::istream& in);
  Parallelogram* makeParallelogram(std::istream& in);
  Diamond* makeDiamond(std::istream& in);
  void createShape(std::istream& in, CompositeShape& compShape, std::string shapeName);
}

#endif

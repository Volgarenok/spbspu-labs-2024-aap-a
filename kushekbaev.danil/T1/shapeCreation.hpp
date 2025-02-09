#ifndef SHAPECREATION_HPP
#define SHAPECREATION_HPP

#include <iostream>
#include "shape.hpp"
#include "concave.hpp"
#include "rectangle.hpp"
#include "diamond.hpp"
#include "parallelogram.hpp"

namespace kushekbaev
{
  Rectangle* makeRectangle(std::istream& in);
  Concave* makeConcave(std::istream& in);
  Parallelogram* makeParallelogram(std::istream& in);
  Diamond* makeDiamond(std::istream& in);
  Shape* createShape(std::istream& in, std::string shapeName);
}

#endif

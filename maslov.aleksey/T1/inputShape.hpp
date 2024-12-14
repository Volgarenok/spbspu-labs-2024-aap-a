#ifndef INPUT_SHAPE_HPP
#define INPUT_SHAPE_HPP

#include <iostream>
#include "shape.hpp"
#include "rectangle.hpp"
#include "regular.hpp"
#include "parallelogram.hpp"

namespace maslov
{
  size_t inputShapes(std::istream & in, Shape ** shapes);
  Rectangle * makeRectangle(std::istream & in);
  Regular * makeRegular(std::istream & in);
  Parallelogram * makeParallelogram(std::istream & in);
}

#endif

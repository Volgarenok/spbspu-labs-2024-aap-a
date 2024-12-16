#ifndef SHAPES_INPUT_HPP
#define SHAPES_INPUT_HPP

#include <iosfwd>
#include "shape.hpp"

namespace rychkov
{
  Shape* getShape(const char* type, std::istream& in);
  Shape* getRectangle(std::istream& in);
  Shape* getRegular(std::istream& in);
}

#endif

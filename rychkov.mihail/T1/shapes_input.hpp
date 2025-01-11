#ifndef SHAPES_INPUT_HPP
#define SHAPES_INPUT_HPP

#include <iosfwd>
#include "shape.hpp"

namespace rychkov
{
  Shape* getShape(const char* type, std::istream& in, bool& isUnknown);
  Shape* getRectangle(std::istream& in);
  Shape* getRegular(std::istream& in);
  Shape* getPolygon(std::istream& in);
  size_t getPoints(std::istream& in, point_t* arr, size_t length, bool* lastWasRead = nullptr);
}

#endif

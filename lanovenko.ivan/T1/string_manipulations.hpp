#ifndef STRING_MANIPULATIONS_HPP
#define STRING_MANIPULATIONS_HPP

#include <istream>
#include <cstring>
#include "shape.hpp"

namespace lanovenko
{
  char* input_string(std::istream& in, const char end);
  Shape* parseShape(const char* str);
  Shape* parseRectangle(const char* str);
  Shape* parseDiamond(const char* str);
  Shape* parseTriangle(const char* str);
  Shape* parseParallelogram(const char* str);
  size_t split(const char* str);
  size_t getNameLength(const char* str);
  void getCoords(double* array, const char* str, size_t capacityCoords);
  void parseScale(double* array, const char* str);
}

#endif


#ifndef STRING_MANIPULATIONS_HPP
#define STRING_MANIPULATIONS_HPP

#include <istream>
#include <string>
#include "shape.hpp"

namespace lanovenko
{
  Shape* parseShape(const std::string& str);
  Shape* parseRectangle(const std::string& str);
  Shape* parseDiamond(const std::string& str);
  Shape* parseTriangle(const std::string& str);
  lanovenko::Shape* parseParallelogram(const std::string& str);
  std::size_t split(const std::string& str);
  double* getCoords(const std::string& coords, size_t capacityCoords);
  double* paraseScale(const std::string& str);
}

#endif

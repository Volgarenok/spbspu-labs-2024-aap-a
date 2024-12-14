#ifndef CREATESHAPES_HPP
#define CREATESHAPES_HPP
#include <istream>
#include "rectangle.hpp"
#include "diamond.hpp"

namespace lebedev
{
  point_t createScalePoint(std::istream& input);
  Rectangle* createRectangle(std::istream& input);
  Diamond* createDiamond(std::istream& input);
}
#endif

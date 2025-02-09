#ifndef CREATESHAPES_HPP
#define CREATESHAPES_HPP
#include <istream>
#include "rectangle.hpp"
#include "diamond.hpp"
#include "concave.hpp"

namespace lebedev
{
  point_t chooseScalePoint(std::istream& input);
  Rectangle* createRectangle(std::istream& input);
  Diamond* createDiamond(std::istream& input);
  Concave* createConcave(std::istream& input);
}
#endif

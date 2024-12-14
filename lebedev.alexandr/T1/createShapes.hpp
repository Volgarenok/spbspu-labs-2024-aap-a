#ifndef CREATESHAPES_HPP
#define CREATESHAPES_HPP
#include <istream>
#include "rectangle.hpp"

namespace lebedev
{
  point_t createScalePoint(std::istream& input);
  Rectangle* createRectangle(std::istream& input);
}
#endif

#ifndef CREATESHAPES.HPP
#define CREATESHAPES.HPP
#include <istream>
#include "rectangle.hpp"

namespace lebedev
{
  point_t createScalePoint(std::istream& input);
  Rectangle* createRectangle(std::istream& input);
}
#endif

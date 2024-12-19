#ifndef CREATESHAPES_HPP
#define CREATESHAPES_HPP
#include <istream>
#include "rectangle.hpp"
#include "diamond.hpp"
#include "square.hpp"

namespace smirnov
{
  Rectangle * createRectangle(std::istream & in);
  Diamond * createDiamond(std::istream & in);
  Square * createSquare(std::istream & in);
}
#endif

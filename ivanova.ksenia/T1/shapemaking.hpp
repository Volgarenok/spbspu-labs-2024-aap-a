#ifndef CREATESHAPES_HPP
#define CREATESHAPES_HPP
#include <istream>
#include "rectangle.hpp"
#include "diamond.hpp"
#include "concave.hpp"
#include "complexquad.hpp"

namespace ivanova
{
  Rectangle* createRectangle(std::istream& input);
  Diamond* createDiamond(std::istream& input);
  Concave* createConcave(std::istream& input);
  Complexquad* createComplexquad(std::istream& input);
}
#endif
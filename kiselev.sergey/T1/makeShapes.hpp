#ifndef MAKESHAPES_HPP
#define MAKESHAPES_HPP
#include <istream>
#include <string>
#include "complexquad.hpp"
#include "composite-shape.hpp"
#include "diamond.hpp"
#include "rectangle.hpp"
namespace kiselev
{
  Rectangle* makeRectangle(std::istream& input);
  Diamond* makeDiamond(std::istream& input);
  Complexquad* makeComplexquad(std::istream& input);
  point_t makeScale(std::istream& input);
  void makeShape(std::string & str, Shape * shape, CompositeShape & compShp);
}
#endif

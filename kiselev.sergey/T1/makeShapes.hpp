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
  Rectangle* make_rectangle(std::istream& input);
  Diamond* make_diamond(std::istream& input);
  Complexquad* make_complexquad(std::istream& input);
  point_t make_scale(std::istream& input);
  void make_shape(std::string & str, Shape * shape, CompositeShape & compShp);
}
#endif

#ifndef MAKESHAPE_HPP
#define MAKESHAPE_HPP
#include <istream>
#include "diamond.hpp"
#include "ellipse.hpp"
#include "rectangle.hpp"
namespace brevnov
{
  Rectangle * make_rectangle(std::istream & in);
  Diamond * make_diamond(std::istream & in);
  Ellipse * make_ellipse(std::istream & in);
  point_t scale(std::istream & in);
}
#endif

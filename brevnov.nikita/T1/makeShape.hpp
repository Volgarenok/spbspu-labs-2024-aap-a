#ifndef MAKESHAPE_HPP
#define MAKESHAPE_HPP
#include <istream>
#include <string>
#include "diamond.hpp"
#include "ellipse.hpp"
#include "rectangle.hpp"
namespace brevnov
{
  Shape * make_rectangle(std::istream & in);
  Diamond * make_diamond(std::istream & in);
  Ellipse * make_ellipse(std::istream & in);
  point_t scale(std::istream & in);
  Shape * make_shape(const std::string& name_shape, std::istream & in);
}
#endif

#ifndef FABRIC_HPP
#define FABRIC_HPP
#include <istream>
#include "rectangle.hpp"
#include "diamond.hpp"
namespace nikonov
{
  Shape *make_shape(std::istream &input, const std::string &name);
  Rectangle *make_rectangle(std::istream &input);
  Diamond *make_diamond(std::istream &input);
  Triangle *make_triangle(std::istream &input);
}
#endif

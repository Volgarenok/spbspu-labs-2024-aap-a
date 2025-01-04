#ifndef FABRIC_HPP
#define FABRIC_HPP
#include <istream>
#include <string>
#include "shape.hpp"
#include "rectangle.hpp"
#include "diamond.hpp"
#include "triangle.hpp"
namespace nikonov
{
  Shape *make_shape(const std::string &name, std::istream &input);
  Rectangle *make_rectangle(std::istream &input);
  Diamond *make_diamond(std::istream &input);
  Triangle *make_triangle(std::istream &input);
}
#endif

#ifndef FABRIC_HPP
#define FABRIC_HPP
#include <iostream>
#include <string>
#include "shape.hpp"
#include "rectangle.hpp"
#include "diamond.hpp"
#include "triangle.hpp"
namespace nikonov
{
  Shape *make_shape(const std::string& name, double nums[]);
  Rectangle *make_rectangle(double nums[]);
  Diamond *make_diamond(double nums[]);
  Triangle *make_triangle(double nums[]);
}
#endif

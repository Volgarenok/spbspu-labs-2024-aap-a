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
  nikonov::Shape* make_shape(std::string name, double  nums[]);
  nikonov::Rectangle* make_rectangle(double  nums[]);
  nikonov::Diamond* make_diamond(double  nums[]);
  nikonov::Triangle* make_triangle(double  nums[]);
}
#endif

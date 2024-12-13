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
  nikonov::Shape* make_shape(std::string name, float nums[]);
  nikonov::Rectangle* make_rectangle(float nums[]);
  nikonov::Diamond* make_diamond(float nums[]);
  nikonov::Triangle* make_triangle(float nums[]);
}
#endif

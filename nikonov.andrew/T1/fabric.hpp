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
  point_t findTop(point_t p1, point_t p2, point_t p3);
  point_t findMid(point_t p1, point_t p2, point_t p3, point_t topP);
  bool isEqualPoint(const point_t& p1, const point_t& p2);
}
#endif

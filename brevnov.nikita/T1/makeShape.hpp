#ifndef MAKESHAPE_HPP
#define MAKESHAPE_HPP
#include <istream>
#include <string>
#include "diamond.hpp"
#include "ellipse.hpp"
#include "rectangle.hpp"
#include "composite-shape.hpp"
#include "big-rectangle.hpp"
namespace brevnov
{
  Shape * make_rectangle(double x1, double y1, double x2, double y2);
  Diamond * make_diamond(double x1, double y1, double x2, double y2, double x3, double y3);
  Ellipse * make_ellipse(point_t center, double r1, double r2);
  point_t scale(std::istream & in);
  Shape * make_shape(std::string name_shape, std::istream & in);
}
#endif

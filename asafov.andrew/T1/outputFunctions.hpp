#ifndef OUTPUT_FUNCTIONS_HPP
#define OUTPUT_FUNCTIONS_HPP
#include <fstream>
#include "shape.hpp"
using asafov::point_t;
using asafov::rectangle_t;
namespace asafov
{
  unsigned long getHash(std::istream& in);
  Shape* ShapeFactory(unsigned long long hash, std::istream& in);
  void scaleShapes(Shape** shapes, unsigned long long count, point_t pos, double scale, std::ostream& out);
  void isotropicScale(Shape* sh, point_t pos, double scale);
}
#endif

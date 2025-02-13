#ifndef OUTPUT_FUNCTIONS_HPP
#define OUTPUT_FUNCTIONS_HPP
#include <fstream>
#include <string>
#include "shape.hpp"
using asafov::point_t;
using asafov::rectangle_t;
namespace asafov
{
  std::string getName(std::istream& in);
  Shape* ShapeFactory(std::string shapename, std::istream& in);
  void scaleShapes(Shape** shapes, unsigned long long count, point_t pos, double scale, std::ostream& out);
  void deleteShapes(Shape** shapes, size_t count);
}
#endif

#ifndef OUTPUT_FUNCTIONS_HPP
#define OUTPUT_FUNCTIONS_HPP
#include <fstream>
#include <string>
#include "shape.hpp"
namespace asafov
{
  std::string getName(std::istream& in);
  Shape* makeShape(std::string shapename, std::istream& in);
  void scaleShapes(Shape** shapes, size_t count, point_t pos, double k, std::ostream& out);
  void deleteShapes(Shape** shapes, size_t count);
}
#endif

#include "square.hpp"

#include <istream>
#include <stdexcept>

#include <common_utils.hpp>

zholobov::Square::Square(const point_t& a, double length):
  Rectangle(a, point_t{a.x + length, a.y + length})
{
  if (length <= 0) {
    throw std::invalid_argument("Error in SQUARE parameters");
  }
}

zholobov::Shape* zholobov::Square::clone() const
{
  return new Square(*this);
}

zholobov::Square* zholobov::Square::create(std::istream& in)
{
  double params[3];
  read_array(params, 3, in);
  return new Square(point_t{params[0], params[1]}, params[2]);
}

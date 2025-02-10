#include "rectangle.hpp"

#include <istream>
#include <stdexcept>

#include <common_utils.hpp>

zholobov::Rectangle::Rectangle(const point_t& a, const point_t& c):
  Parallelogram(a, point_t{c.x, a.y}, c)
{
  if ((c.x <= a.x) || (c.y <= a.y)) {
    throw std::invalid_argument("Error in RECTANGLE parameters");
  }
}

zholobov::Shape* zholobov::Rectangle::clone() const
{
  return new Rectangle(*this);
}

zholobov::Rectangle* zholobov::Rectangle::create(std::istream& in)
{
  double params[4];
  read_array(params, 4, in);
  return new Rectangle({params[0], params[1]}, {params[2], params[3]});
}

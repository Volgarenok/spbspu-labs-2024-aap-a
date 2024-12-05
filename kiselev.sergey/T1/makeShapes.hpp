#ifndef MAKESHAPES_HPP
#define MAKESHAPES_HPP
#include <istream>
#include "rectangle.hpp"
namespace kiselev
{
  Rectangle* make_rectangle(std::istream& input);
  point_t make_scale(std::istream& input);
}
#endif

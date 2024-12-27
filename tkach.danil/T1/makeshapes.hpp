#ifndef MAKESHAPES_HPP
#define MAKESHAPES_HPP

#include <fstream>
#include "regular.hpp"
#include "ring.hpp"
#include "rectangle.hpp"

namespace tkach
{
  tkach::Rectangle* make_rectangle(std::istream& in);
  tkach::Ring* make_ring(std::istream& in);
  tkach::Regular* make_regular(std::istream& in);
  tkach::Shape* make_shape(std::istream& in,  std::string shape_name);
}

#endif

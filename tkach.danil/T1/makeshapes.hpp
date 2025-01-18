#ifndef MAKESHAPES_HPP
#define MAKESHAPES_HPP

#include <iostream>
#include "shape.hpp"

namespace tkach
{
  tkach::Shape* make_shape(std::istream& in,  std::string shape_name);
}

#endif

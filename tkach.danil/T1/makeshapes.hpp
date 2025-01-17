#ifndef MAKESHAPES_HPP
#define MAKESHAPES_HPP

#include <iostream>
#include "regular.hpp"
#include "ring.hpp"
#include "rectangle.hpp"

namespace tkach
{
  tkach::Shape* make_shape(std::istream& in,  std::string shape_name);
}

#endif

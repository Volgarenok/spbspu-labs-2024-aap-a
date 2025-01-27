#ifndef MAKESHAPES_HPP
#define MAKESHAPES_HPP

#include <iostream>
#include <string>
#include "shape.hpp"

namespace tkach
{
  Shape* makeShape(std::istream& in, const std::string& shape_name);
}

#endif

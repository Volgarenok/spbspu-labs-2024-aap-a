#ifndef MAKESHAPE_HPP
#define MAKESHAPE_HPP

#include <iostream>
#include <string>
#include "shape.hpp"

namespace mozhegova
{
  Shape * makeShape(std::istream & in, const std::string & shapeName);
}

#endif

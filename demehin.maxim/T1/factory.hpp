#ifndef FACTORY_HPP
#define FACTORY_HPP

#include <string>
#include <iostream>
#include "shape.hpp"

namespace demehin
{
  Shape* createShape(std::istream& in, const std::string& shp_name);
}

#endif

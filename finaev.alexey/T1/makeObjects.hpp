#ifndef MAKEOBJECTS_HPP
#define MAKEOBJECTS_HPP

#include <fstream>
#include "base-types.hpp"
#include "rectangle.hpp"
#include "square.hpp"

namespace finaev
{
  Rectangle* makeRectangle(std::istream& in);
  Square* makeSquare(std::istream& in);
}

#endif

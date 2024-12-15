#ifndef MAKEOBJECTS_HPP
#define MAKEOBJECTS_HPP

#include <fstream>
#include "rectangle.hpp"
#include "square.hpp"
#include "concave.hpp"

namespace finaev
{
  Rectangle* makeRectangle(std::istream& in);
  Square* makeSquare(std::istream& in);
  Concave* makeConcave(std::istream& in);
  double len(point_t a, point_t b);
}

#endif

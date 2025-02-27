#ifndef MAKESHAPES_HPP
#define MAKESHAPES_HPP

#include <fstream>
#include <string>
#include "rectangle.hpp"
#include "square.hpp"
#include "concave.hpp"
#include "shape.hpp"

namespace finaev
{
  Rectangle* makeRectangle(std::istream& in);
  Square* makeSquare(std::istream& in);
  Concave* makeConcave(std::istream& in);
  Shape* makeShapes(std::istream& in, std::string str);
}

#endif

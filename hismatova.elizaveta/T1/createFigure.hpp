#ifndef CREATEFIGURE_HPP
#define CREATEFIGURE_HPP
#include <iostream>
#include "rectangle.hpp"
#include "triangle.hpp"
#include "concave.hpp"

namespace hismatova
{
  Rectangle* createRectangle(std::istream& in);
  Triangle* createTriangle(std::istream& in);
  Concave* createConcave(std::istream& in);
}

#endif

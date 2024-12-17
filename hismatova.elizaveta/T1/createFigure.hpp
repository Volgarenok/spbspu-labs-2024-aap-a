#ifndef CREATEFIGURE_HPP
#define CREATEFIGURE_HPP
#include "rectangle.hpp"
#include "triangle.hpp"
#include "concave.hpp"
#include <iostream>

namespace hismatova
{
  hismatova::Rectangle* createRectangle(std::istream& in);
  hismatova::Triangle* createTriangle(std::istream& in);
  hismatova::Concave* createConcave(std::istream& in);
}

#endif

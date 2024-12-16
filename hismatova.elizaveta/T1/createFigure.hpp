#ifndef CREATEFIGURE_HPP
#define CREATEFIGURE_HPP
#include "rectangle.hpp"
#include "triangle.hpp"
#include "concave.hpp"
#include <iostream>

namespace hismatova
{
  hismatova::rectangle* createRectangle(std::istream& in);
  hismatova::triangle* createTriangle(std::istream& in);
  hismatova::concave* createConcave(std::istream in);
}

#endif

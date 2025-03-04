#ifndef INPUT_FIGURES_HPP
#define INPUT_FIGURES_HPP
#include <istream>
#include "rectangle.hpp"
#include "square.hpp"
#include "parallelogram.hpp"

namespace dirti
{
  Shape* makeShape(std::istream& in, std::string figure);
}

#endif

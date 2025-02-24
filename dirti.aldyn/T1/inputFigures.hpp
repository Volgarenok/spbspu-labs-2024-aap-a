#ifndef INPUT_FIGURES_HPP
#define INPUT_FIGURES_HPP
#include <istream>
#include "rectangle.hpp"

namespace dirti
{
  Rectangle* makeRectangle(std::istream& in);
}

#endif
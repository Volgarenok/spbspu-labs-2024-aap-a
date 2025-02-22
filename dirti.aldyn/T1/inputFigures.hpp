#ifndef INPUT_FIGURES_HPP
#define INPUT_FIGURES_HPP
#include "rectangle.hpp"
#include <istream>

namespace dirti
{
  Rectangle* makeRectangle(std::istream& in);
}
#endif

#ifndef INPUT_FIGURES_HPP
#define INPUT_FIGURES_HPP
#include <istream>
#include "rectangle.hpp"
#include "square.hpp"
#include "parallelogram.hpp"

namespace dirti
{
  Rectangle* makeRectangle(std::istream& in);
  Square* makeSquare(std::istream& in);
  Parallelogram* makeParallelogram(std::istream& in);
}

#endif
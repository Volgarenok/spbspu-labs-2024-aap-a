#ifndef MAKESSHAPE_HPP
#define MAKESSHAPE_HPP
#include <istream>
#include "rectangle.hpp"
#include "square.hpp"
#include "parallelogram.hpp"
#include "diamond.hpp"

namespace cherkasov
{
  Rectangle* getRectangle(std::istream& input);
  Square* getSquare(std::istream& input);
  Parallelogram* getParallelogram(std::istream& input);
  Diamond* getDiamond(std::istream& input);
}
#endif

#ifndef MAKESSHAPE_HPP
#define MAKESSHAPE_HPP
#include <istream>
#include <string>
#include "rectangle.hpp"
#include "square.hpp"
#include "parallelogram.hpp"
#include "diamond.hpp"

namespace cherkasov
{
  point_t getPoint(std::istream& input);
  void getPoints(point_t* vertex, size_t size, std::istream& input);
  Rectangle* getRectangle(std::istream& input);
  Square* getSquare(std::istream& input);
  Parallelogram* getParallelogram(std::istream& input);
  Diamond* getDiamond(std::istream& input);
  Shape* createShape(const std::string& inputCommand, std::istream& input);
}
#endif

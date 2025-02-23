#include "makesShape.hpp"
#include <iostream>
#include <stdexcept>
#include <algorithm>

namespace cherkasov
{
  Rectangle* getRectangle(std::istream& input)
  {
    point_t left;
    point_t right;
    input >> left.x >> left.y >> right.x >> right.y;
    if (!input)
    {
      throw std::invalid_argument("no input coordinate");
    }
    return new Rectangle(left, right);
  }
  Square* getSquare(std::istream& input)
  {
    double x = 0.0;
    double y = 0.0;
    double length = 0.0;
    input >> x >> y >> length;
    if (!input)
    {
      throw std::invalid_argument("no input coordinate");
    }
    return new Square(x, y, length);
  }
  Parallelogram* getParallelogram(std::istream& input)
  {
    double x1 = 0.0;
    double y1 = 0.0;
    double x2 = 0.0;
    double y2 = 0.0;
    double x3 = 0.0;
    double y3 = 0.0;
    input >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    if (!(input))
    {
      throw std::invalid_argument("no correct coordinat the parallelogram");
    }
    return new Parallelogram(x1, y1, x2, y2, x3, y3);
  }
  Diamond* getDiamond(std::istream& input)
  {
    double x1 = 0.0;
    double y1 = 0.0;
    double x2 = 0.0;
    double y2 = 0.0;
    double x3 = 0.0;
    double y3 = 0.0;
    input >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    if (!(input))
    {
      throw std::invalid_argument("no input coordinat");
    }
    return new Diamond(x1, y1, x2, y2, x3, y3);
  }
  Shape* createShape(const std::string& inputCommand, std::istream& input)
  {
    if (inputCommand == "RECTANGLE")
    {
      return getRectangle(input);
    }
    else if (inputCommand == "SQUARE")
    {
      return getSquare(input);
    }
    else if (inputCommand == "PARALLELOGRAM")
    {
      return getParallelogram(input);
    }
    else if (inputCommand == "DIAMOND")
    {
      return getDiamond(input);
    }
    else
    {
      throw std::invalid_argument("incorrect shape");
    }
  }
}

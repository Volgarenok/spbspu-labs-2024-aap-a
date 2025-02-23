#include "makesShape.hpp"
#include <iostream>
#include <stdexcept>
#include <algorithm>

namespace cherkasov
{
  Rectangle* getRectangle(std::istream& input)
  {
    double x1 = 0.0;
    double y1 = 0.0;
    double x2 = 0.0;
    double y2 = 0.0;
    input >> x1 >> y1 >> x2 >> y2;
    if (!input)
    {
      throw std::invalid_argument("no input coordinate");
    }
    return new Rectangle(x1, y1, x2, y2);
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
  Shape* createShape(const std::string& inputCommand, const std::istream& input)
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
      return nullptr;
    }
  }
}

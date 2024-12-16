#include "createShapes.hpp"
#include <stdexcept>

smirnov::Rectangle * smirnov::createRectangle(std::istream & in)
{
  double x1 = 0.0;
  double y1 = 0.0;
  double x2 = 0.0;
  double y2 = 0.0;
  in >> x1 >> y1 >> x2 >> y2;
  if (!in || x1 >= x2 || y1 >= y2)
  {
    throw std::invalid_argument("Incorrect coordinates");
  }
  return new Rectangle(x1, y1, x2, y2);
}

smirnov::Diamond * smirnov::createDiamond(std::istream & in)
{
  double centerX = 0.0;
  double centerY = 0.0;
  double diagonal1 = 0.0;
  double diagonal2 = 0.0;
  in >> centerX >> centerY >> diagonal1 >> diagonal2;
  if (!in || diagonal1 <= 0 || diagonal2 <= 0)
  {
    throw std::invalid_argument("Incorrect coordinates");
  }
  return new Diamond(centerX, centerY, diagonal1, diagonal2);
}

smirnov::Square * smirnov::createSquare(std::istream & in)
{
  double x = 0.0;
  double y = 0.0;
  double sideLength;
  in >> x >> y >> sideLength;
  if (!in || sideLength <= 0) {
    throw std::invalid_argument("Incorrect coordinates");
  }
  return new Square(x, y, sideLength);
}

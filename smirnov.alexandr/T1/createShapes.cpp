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

smirnov::Square * smirnov::createSquare(std::istream & in)
{
  double x = 0.0
  double y = 0.0;
  double length = 0.0;
  in >> x >> y >> length;
  if (!in || length <= 0) {
    throw std::invalid_argument("Incorrect coordinates");
  }
  return new Square(x, y, length);
}

smirnov::Diamond * smirnov::createDiamond(std::istream & in)
{
  double x1 = 0.0;
  double y1 = 0.0;
  double x2 = 0.0;
  double y2 = 0.0;
  double x3 = 0.0;
  double y3 = 0.0;
  in >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  if ((x1 == x2 && y1 == y2) && (x1 == x3 && y1 == y3))
  {
    throw std::invalid_argument("All three vertices cannot coincide.");
  }
  if ((x1 == x2 && y1 == y2) || (x1 == x3 && y1 == y3) || (x2 == x3 && y2 == y3))
  {
    throw std::invalid_argument("Two vertices cannot coincide.");
  }
  return new Diamond(x1, y1, x2, y2, x3, y3);
}

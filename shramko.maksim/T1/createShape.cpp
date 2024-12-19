#include "createShape.hpp"
#include <stdexcept>

shramko::Rectangle* shramko::createRectangle(std::istream& in)
{
  point_t leftBottom, rightTop;

  in >> leftBottom.x >> leftBottom.y >> rightTop.x >> rightTop.y;

  if (!in || leftBottom.x >= rightTop.x || leftBottom.y >= rightTop.y)
  {
    throw std::invalid_argument("Coordinates are incorrect");
  }

  return new Rectangle(leftBottom, rightTop);
}

shramko::Triangle* shramko::createTriangle(std::istream& in)
{
  point_t One, Two, Three;

  in >> One.x >> One.y >> Two.x >> Two.y >> Three.x >> Three.y;

  if ((std::abs(One.x * (Two.y - Three.y) + Two.x * (Three.y - One.y) + Three.x * (One.y - Two.y)) / 2.0) <= 0)
  {
    throw std::invalid_argument("Coordinates are incorrect");
  }

  return new Triangle(One, Two, Three);
}

shramko::Diamond* shramko::createDiamond(std::istream& in)
{
  point_t One, Two, Three;

  in >> One.x >> One.y >> Two.x >> Two.y >> Three.x >> Three.y;

  if ((One.x == Two.x && One.y == Two.y) && (One.x == Three.x && One.y == Three.y)
  {
    throw std::invalid_argument("All triangle vertices are invalid");
  }

  if ((One.x == Two.x && One.y == Two.y) || (One.x == Three.x && One.y == Three.y) || (Two.x == Three.x && Two.y == Three.x))
  {
    throw std::invalid_argument("Two triangle vertices are invalid");
  }

  return new Diamond(One, Two, Three);
}

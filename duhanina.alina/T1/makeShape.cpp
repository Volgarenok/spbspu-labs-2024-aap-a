#include "makeShape.hpp"
#include <stdexcept>

duhanina::Rectangle* duhanina::makeRectangle(std::istream& in)
{
  double ltX = 0;
  double ltY = 0;
  double rtX = 0;
  double rtY = 0;
  if (!(in >> ltX >> ltY >> rtX >> rtY))
  {
    throw std::invalid_argument("Incorrect input");
  }
  Rectangle* rect = new Rectangle({ ltX, ltY }, { rtX, rtY });
  return rect;
}

duhanina::Circle* duhanina::makeCircle(std::istream& in)
{
  double x = 0;
  double y = 0;
  double radius = 0;
  if (!(in >> x >> y >> radius))
  {
    throw std::invalid_argument("Incorrect input");
  }
  Circle* circ = new Circle({ x, y }, radius);
  return circ;
}

duhanina::Ellipse* duhanina::makeEllipse(std::istream& in)
{
  double x = 0;
  double y = 0;
  double vertRadius = 0;
  double horizRadius = 0;
  if (!(in >> x >> y >> vertRadius >> horizRadius))
  {
    throw std::invalid_argument("Incorrect input");
  }
  Ellipse* ell = new Ellipse({ x, y }, horizRadius, vertRadius);
  return ell;
}

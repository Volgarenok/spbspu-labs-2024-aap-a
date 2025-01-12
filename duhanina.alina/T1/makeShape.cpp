#include "makeShape.hpp"

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
  return new Rectangle({ ltX, ltY }, { rtX, rtY });
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
  return new Circle({ x, y }, radius, 9);
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
  return new Ellipse({ x, y }, horizRadius, vertRadius);
}

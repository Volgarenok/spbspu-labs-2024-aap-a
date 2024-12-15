#include "makeShape.hpp"
#include <iostream>

duhanina::Rectangle* duhanina::makeRectangle(std::istream& in)
{
  double ltX = 0;
  double ltY = 0;
  double rtX = 0;
  double rtY = 0;
  in >> ltX >> ltY >> rtX >> rtY;
  if (ltX >= rtX || ltY >= rtY)
  {
    throw std::invalid_argument("Error in parameters");
  }
  Rectangle* rect = new Rectangle({ ltX, ltY }, { rtX, rtY });
  return rect;
}

duhanina::Circle* duhanina::makeCircle(std::istream& in)
{
  double x = 0;
  double y = 0;
  in >> x >> y;
  double radius = 0;
  in >> radius;
  if (radius <= 0)
  {
    throw std::invalid_argument("Error in parameters");
  }
  Circle* circ = new Circle({ x, y }, radius);
  return circ;
}

duhanina::Ellipse* duhanina::makeEllipse(std::istream& in)
{
  double x = 0;
  double y = 0;
  in >> x >> y;
  double vertRadius = 0;
  double horizRadius = 0;
  if (vertRadius <= 0 || horizRadius <= 0)
  {
    throw std::invalid_argument("Error in parameters");
  }
  in >> vertRadius >> horizRadius;
  Ellipse* ell = new Ellipse({ x, y }, horizRadius, vertRadius);
  return ell;
}

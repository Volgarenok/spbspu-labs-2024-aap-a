#include "makeShape.hpp"
#include <stdexcept>

sharifullina::Shape * sharifullina::createShape(std::istream& in, const std::string& shapeType)
{
  if (shapeType == "RECTANGLE")
  {
    return sharifullina::makeRectangle(in);
  }
  else if (shapeType == "RING")
  {
    return makeRing(in);
  }
  else if (shapeType == "CIRCLE")
  {
    return makeCircle(in);
  }
  else if (shapeType == "ELLIPSE")
  {
    return makeEllipse(in);
  }
  else
  {
    throw std::invalid_argument("Unknown shape type");
  }
}

sharifullina::Rectangle * sharifullina::makeRectangle(std::istream& in)
{
  double params[4] = {0.0, 0.0, 0.0, 0.0};
  in >> params[0] >> params[1] >> params[2] >> params[3];
  point_t lowLeft = {params[0], params[1]};
  point_t uppRight = {params[2], params[3]};
  if (lowLeft.x >= uppRight.x || lowLeft.y >= uppRight.y)
  {
    throw std::invalid_argument("Incorrect coordinates");
  }
  Rectangle * rect = new Rectangle(lowLeft, uppRight);
  return rect;
}

sharifullina::Ring * sharifullina::makeRing(std::istream& in)
{
  double params[4] = {0.0, 0.0, 0.0, 0.0};
  in >> params[0] >> params[1] >> params[2] >> params[3];
  point_t center = {params[0], params[1]};
  double innerRadius = params[2];
  double outerRadius = params[3];
  if (innerRadius <= 0 || outerRadius <= 0 || innerRadius >= outerRadius)
  {
    throw std::invalid_argument("Incorrect radius");
  }
  Ring * rin9 = new Ring(center, innerRadius, outerRadius);
  return rin9;
}

sharifullina::Circle * sharifullina::makeCircle(std::istream& in)
{
  double params[3] = {0.0, 0.0, 0.0};
  in >> params[0] >> params[1] >> params[2];
  point_t center = {params[0], params[1]};
  double radius = params[2];
  if (radius <= 0)
  {
    throw std::invalid_argument("Incorrect radius");
  }
  Circle * circl = new Circle(center, radius);
  return circl;
}

sharifullina::Ellipse * sharifullina::makeEllipse(std::istream& in)
{
  double params[4] = {0.0, 0.0, 0.0, 0.0};
  in >> params[0] >> params[1] >> params[2] >> params[3];
  point_t center = {params[0], params[1]};
  double radiusX = params[2];
  double radiusY = params[3];
  if (radiusX <= 0 || radiusY <= 0)
  {
    throw std::invalid_argument("Incorrect radius");
  }
  Ellipse * ellips = new Ellipse(center, radiusY, radiusX);
  return ellips;
}

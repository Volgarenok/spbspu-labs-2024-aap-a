#include "makeShape.hpp"
#include <iostream>
#include <string>
#include <exception>

brevnov::Shape * brevnov::make_rectangle(std::istream& in)
{
  double x1 = 0.0, y1 = 0.0, x2 = 0.0, y2 = 0.0;
  in >> x1 >> y1 >> x2 >> y2;
  if (in.fail())
  {
    throw std::invalid_argument("Fail input");
  }
  return new brevnov::Rectangle({x1, y1}, {x2, y2});
}

brevnov::Diamond * brevnov::make_diamond(std::istream& in)
{
  double x1 = 0.0, y1 = 0.0, x2 = 0.0, y2 = 0.0, x3 = 0.0, y3 = 0.0;
  in >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  if (in.fail())
  {
    throw std::invalid_argument("Fail input");
  }
  return new brevnov::Diamond({x1, y1}, {x2, y2}, {x3, y3});
}

brevnov::Ellipse * brevnov::make_ellipse(std::istream& in)
{
  double x = 0.0, y = 0.0;
  in >> x >> y;
  point_t center = {x, y};
  double r1 = 0.0, r2 = 0.0;
  in >> r1 >> r2;
  if (in.fail())
  {
    throw std::invalid_argument("Fail input");
  }
  return new brevnov::Ellipse(center, r1, r2);
}

brevnov::point_t brevnov::scale(std::istream & in)
{
  double x = 0.0, y = 0.0;
  in >> x >> y;
  if (in.fail())
  {
    throw std::invalid_argument("Not correct parameter");
  }
  return {x, y};
}

brevnov::Shape * brevnov::make_shape(const std::string& name_shape, std::istream & in)
{
  if (name_shape == "RECTANGLE")
  {
    return brevnov::make_rectangle(in);
  }
  if (name_shape == "ELLIPSE")
  {
    return brevnov::make_ellipse(in);
  }
  if (name_shape == "DIAMOND")
  {
    return brevnov::make_diamond(in);
  }
  else
  {
    throw std::invalid_argument("Not correct input!");
  }
}

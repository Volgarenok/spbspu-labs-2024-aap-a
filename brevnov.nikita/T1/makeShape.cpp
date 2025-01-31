#include "makeShape.hpp"
#include <iostream>
#include <string>
#include <exception>

brevnov::Shape * brevnov::make_rectangle(std::string name_shape, std::istream& in)
{
  double x1 = 0.0, y1 = 0.0, x2 = 0.0, y2 = 0.0;
  in >> x1 >> y1 >> x2 >> y2;
  if (in.fail())
  {
    return nullptr;
  }
  try
  {
    if (name_shape == "RECTANGLE")
    {
      return new Rectangle({x1, y1}, {x2, y2});
    }
    else
    {
      return new BigRectangle({x1, y1}, {x2, y2});
    }
  }
  catch (const std::invalid_argument& e)
  {
    return nullptr;
  }
}

brevnov::Diamond * brevnov::make_diamond(std::istream& in)
{
  double x1 = 0.0, y1 = 0.0, x2 = 0.0, y2 = 0.0, x3 = 0.0, y3 = 0.0;
  in >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  if (in.fail())
  {
    return nullptr;
  }
  try
  {
    return new Diamond({x1, y1}, {x2, y2}, {x3, y3});
  }
  catch(const std::invalid_argument& e)
  {
    return nullptr;
  }
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
    return nullptr;
  }
  try
  {
    return new Ellipse(center, r1, r2);
  }
  catch(const std::invalid_argument& e)
  {
    return nullptr;
  }
}

brevnov::point_t brevnov::scale(std::istream & in)
{
  double x = 0.0, y = 0.0;
  in >> x >> y;
  if (in.fail())
  {
    return nullptr;
  }
  return {x, y};
}

brevnov::Shape * brevnov::make_shape(std::string name_shape, std::istream & in)
{
  if (name_shape == "RECTANGLE" || name_shape == "BIGRECTANGLE")
  {
    return make_rectangle(name_shape, in);
  }
  if (name_shape == "ELLIPSE")
  {
    return make_ellipse(in);
  }
  if (name_shape == "DIAMOND")
  {
    return make_diamond(in);
  }
  return nullptr;
}

/* if ((x1 == x2 &&  y1 == y2) || (x1 == x3 && y1 == y3) || (x2 == x3 && y2 == y3) ||
    (x1 != x2 && x1 != x3 && x2 != x3) || (y1 != y2 && y1 != y3 && y2 != y3))*/

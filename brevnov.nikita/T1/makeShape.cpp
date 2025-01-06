#include "makeShape.hpp"
#include <iostream>
#include <string>
#include <exception>

brevnov::Rectangle * brevnov::make_rectangle(double x1, double y1, double x2, double y2)
{
  return new Rectangle({x1, y1}, {x2, y2});
}

brevnov::Diamond * brevnov::make_diamond(double x1, double y1, double x2, double y2, double x3, double y3)
{
  if (x1 == x2 && y1 == y3)
  {
    return new Diamond({x1, y1}, {x3, y3}, {x2, y2});
  }
  else if (x1 == x3 && y1 == y2)
  {
    return new Diamond({x1, y1}, {x2, y2}, {x3, y3});
  }
  else if (x2 == x1 && y2 == y3)
  {
    return new Diamond({x2, y2}, {x3, y3}, {x1, y1});
  }
  else if (x2 == x3 && y2 == y1)
  {
    return new Diamond({x2, y2}, {x1, y1}, {x3, y3});;
  }
  else if (x3 == x1 && y3 == y2)
  {
    return new Diamond({x3, y3}, {x2, y2}, {x1, y1});
  }
  else if (x3 == x2 && y3 == y1)
  {
    return new Diamond({x3, y3}, {x1, y1}, {x2, y2});;
  }
}

brevnov::Ellipse * brevnov::make_ellipse(point_t center, double r1, double r2)
{
  return new Ellipse(center, r1, r2);
}

brevnov::point_t brevnov::scale(std::istream & in)
{
  double x = 0.0, y = 0.0;
  in >> x >> y;
  if (in.fail())
  {
    throw std::invalid_argument("Some parameters were incorrect");
  }
  return {x, y};
}

brevnov::BigRectangle * brevnov::make_big_rectangle(double x1, double y1, double x2, double y2)
{
  return new BigRectangle({x1, y1}, {x2, y2});
}

brevnov::Shape * brevnov::make_shape(std::string name_shape, std::istream & in)
{
  if (name_shape == "RECTANGLE" || name_shape == "BIGRECTANGLE")
  {
    double x1 = 0.0, y1 = 0.0, x2 = 0.0, y2 = 0.0;
    in >> x1 >> y1 >> x2 >> y2;
    if (in.fail())
    {
      throw std::invalid_argument("Some parameters were incorrect");
    }
    if (x1 >= x2 || y1 >= y2)
    {
      throw std::invalid_argument("Some parameters were incorrect");
    }
    if (name_shape == "RECTANGLE")
    {
      return make_rectangle(x1, y1, x2, y2);
    }
    else
    {
      return make_big_rectangle(x1, y1, x2, y2);
    }
  }
  if (name_shape == "ELLIPSE")
  {
    double x = 0.0, y = 0.0, r1 = 0.0, r2 = 0.0;
    in >> x >> y;
    point_t center(x, y);
    in >> r1 >> r2;
    if (in.fail())
    {
      throw std::invalid_argument("Some parameters were incorrect");
    }
    if (r1 <= 0.0 || r2 <= 0.0)
    {
      throw std::invalid_argument("Some parameters were incorrect");
    }
    return make_ellipse(center, r1, r2);
  }
  if (name_shape == "DIAMOND")
  {
    double x1 = 0.0, y1 = 0.0, x2 = 0.0, y2 = 0.0, x3 = 0.0, y3 = 0.0;
    in >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    if (in.fail())
    {
      throw std::invalid_argument("Some parameters were incorrect");
    }
    if ((x1 == x2 &&  y1 == y2) || (x1 == x3 && y1 == y3) || (x2 == x3 && y2 == y3) || (x1 != x2 && x1 != x3 && x2 != x3) || (y1 != y2 && y1 != y3 && y2 != y3))
    {
      throw std::invalid_argument("Some parameters were incorrect");
    }
    return make_diamond(x1, y1, x2, y2, x3, y3)
  }
  return nullptr;
}

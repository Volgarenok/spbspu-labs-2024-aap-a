#include "makeShape.hpp"
#include <iostream>

brevnov::Rectangle * brevnov::make_rectangle(std::istream & in)
{
  double x1 = 0.0, y1 = 0.0, x2 = 0.0, y2 = 0.0;
  in >> x1 >> y1 >> x2 >> y2;
  if (in.fail())
  {
    throw std::invalid_argument("Incorrect parameters");
  }
  if (x1 >= x2 || y1 >= y2)
  {
    throw std::invalid_argument("Incorrect parameters");
  }
  Rectangle * result = new Rectangle({x1, y1}, {x2, y2});
  return result;
}

brevnov::Diamond * brevnov::make_diamond(std::istream & in)
{
  double x1 = 0.0, y1 = 0.0, x2 = 0.0, y2 = 0.0, x3 = 0.0, y3 = 0.0;
  in >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  Diamond * result = nullptr;
  if (in.fail())
  {
    throw std::invalid_argument("Incorrect parameters");
  }
  if ((x1 == x2 &&  y1 == y2) || (x1 == x3 && y1 == y3) || (x2 == x3 && y2 == y3))
  {
    throw std::invalid_argument("Incorrect parameters");
  }
  if (x1 == x2 && y1 == y3)
  {
    result = new Diamond({x1, y1}, {x3, y3}, {x2, y2});
    return result;
  }
  else if (x1 == x3 && y1 == y2)
  {
    result = new Diamond({x1, y1}, {x2, y2}, {x3, y3});
    return result;
  }
  else if (x2 == x1 && y2 == y3)
  {
    result = new Diamond({x2, y2}, {x3, y3}, {x1, y1});
    return result;
  }
  else if (x2 == x3 && y2 == y1)
  {
    result = new Diamond({x2, y2}, {x1, y1}, {x3, y3});
    return result;
  }
  else if (x3 == x1 && y3 == y2)
  {
    result = new Diamond({x3, y3}, {x2, y2}, {x1, y1});
    return result;
  }
  else if (x3 == x2 && y3 == y1)
  {
    result = new Diamond({x3, y3}, {x1, y1}, {x2, y2});
    return result;
  }
  else
  {
    throw std::invalid_argument("Incorrect parameters");
  }
}

brevnov::Ellipse * brevnov::make_ellipse(std::istream & in)
{
  double x = 0.0, y = 0.0, r1 = 0.0, r2 = 0.0;
  in >> x >> y >> r1 >> r2;
  if (in.fail())
  {
    throw std::invalid_argument("Incorrect parameters");
  }
  if (r1 <= 0.0 || r2 <= 0.0)
  {
    throw std::invalid_argument("Incorrect parameters");
  }
  Ellipse * result = new Ellipse({x, y}, r1, r2);
  return result;
}

brevnov::point_t brevnov::scale(std::istream & in)
{
  double x = 0.0, y = 0.0;
  in >> x >> y;
  if (in.fail())
  {
    throw std::invalid_argument("Incorrect parameters");
  }
  return {x, y};
}

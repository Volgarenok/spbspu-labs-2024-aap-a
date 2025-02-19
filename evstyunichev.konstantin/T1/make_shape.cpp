#include "make_shape.hpp"
#include <cmath>
#include <iostream>
#include <string>
#include "circle.hpp"
#include "rectangle.hpp"
#include "regular.hpp"
#include "ring.hpp"

evstyunichev::Rectangle * evstyunichev::make_rectangle(std::istream &in)
{
  double x1{}, y1{}, x2{}, y2{};
  in >> x1 >> y1 >> x2 >> y2;
  if (!in || (x1 > x2) || (y1 > y2))
  {
    return nullptr;
  }
  Rectangle *temp = new Rectangle({x1, y1}, {x2, y2});
  return temp;
}

evstyunichev::Circle * evstyunichev::make_circle(std::istream &in)
{
  double x{}, y{}, r{};
  in >> x >> y >> r;
  if (r <= 0)
  {
    return nullptr;
  }
  Circle *temp = new Circle({x, y}, r);
  return temp;
}

evstyunichev::Ring * evstyunichev::make_ring(std::istream &in)
{
  double x{}, y{}, R{}, r{};
  in >> x >> y >> R >> r;
  Ring *temp = new Ring({x, y}, R, r);
  return temp;
}

evstyunichev::Regular * evstyunichev::make_regular(std::istream &in)
{
  double x1{}, y1{}, x2{}, y2{}, x3{}, y3{};
  in >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  Regular *temp = new Regular({x1, y1}, {x2, y2}, {x3, y3});
  return temp;
}

evstyunichev::Shape * evstyunichev::make_shape(std::istream &in, const std::string &s)
{
  Shape *shape = nullptr;
  try
  {
    if (s == "RECTANGLE")
    {
      shape = make_rectangle(in);
    }
    else if (s == "CIRCLE")
    {
      shape = make_circle(in);
    }
    else if (s == "RING")
    {
      shape = make_ring(in);
    }
    else if (s == "REGULAR")
    {
      shape = make_regular(in);
    }
    return shape;
  }
  catch (const std::invalid_argument &e)
  {
    return nullptr;
  }
}
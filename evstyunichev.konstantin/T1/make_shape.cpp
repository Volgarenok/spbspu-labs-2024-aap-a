#include "make_shape.hpp"
#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"

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

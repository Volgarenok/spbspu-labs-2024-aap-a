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
  Rectangle *temp = new Rectangle({x1, y1}, {x2, y2});
  return temp;
}

evstyunichev::Circle * evstyunichev::make_circle(std::istream &in)
{
  double x{}, y{}, r{};
  in >> x >> y >> r;
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
  double cds[6];
  for (size_t i = 0; i < 6; i++)
  {
    in >> cds[i];
  }
  Regular *temp = new Regular({ cds[0], cds[1] }, { cds[2], cds[3] }, { cds[4], cds[5] });
  return temp;
}

evstyunichev::Shape * evstyunichev::make_shape(std::istream &in, const std::string &s)
{
  Shape *shape = nullptr;
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

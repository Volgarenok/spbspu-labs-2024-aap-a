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
  double data[4]{};
  for (size_t i = 0; i < 4; i++)
  {
    in >> data[i];
  }
  Rectangle *temp = new Rectangle({data[0], data[1]}, {data[2], data[3]});
  return temp;
}

evstyunichev::Circle * evstyunichev::make_circle(std::istream &in)
{
  double data[3]{};
  for (size_t i = 0; i < 3; i++)
  {
    in >> data[i];
  }
  Circle *temp = new Circle({ data[0], data[1] }, data[2]);
  return temp;
}

evstyunichev::Ring * evstyunichev::make_ring(std::istream &in)
{
  double data[4]{};
  for (size_t i = 0; i < 4; i++)
  {
    in >> data[i];
  }
  Ring *temp = new Ring({data[0], data[1]}, data[2], data[3]);
  return temp;
}

evstyunichev::Regular * evstyunichev::make_regular(std::istream &in)
{
  double cds[6]{};
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

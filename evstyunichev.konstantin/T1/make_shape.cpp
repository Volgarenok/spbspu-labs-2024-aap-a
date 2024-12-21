#include "make_shape.hpp"
#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"
#include "regular.hpp"
#include "ring.hpp"

namespace
{
  bool isEqual(double, double, double p = 0.000001);
  bool isEqual(double a, double b, double p)
  {
    if (abs(a - b) <= p)
    {
      return 1;
    }
    return 0;
  }
}

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
  if ((r <= 0) || (R <= r))
  {
    return nullptr;
  }
  Ring *temp = new Ring({x, y}, R, r);
  return temp;
}

evstyunichev::Regular * evstyunichev::make_regular(std::istream &in)
{
  double x1{}, y1{}, x2{}, y2{}, x3{}, y3{};
  in >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  double a = findDist({x1, y1}, {x2, y2}), b = findDist({x1, y1}, {x3, y3}),
    c = findDist({x3, y3}, {x2, y2});
  if (a > b)
  {
    std::swap(a, b);
  }
  if (b > c)
  {
    std::swap(b, c);
  }
  if (a > b)
  {
    std::swap(a, b);
  }
  if (isEqual(a * a + b * b, c * c))
  {
    Regular *temp = new Regular({x1, y1}, {x2, y2}, {x3, y3});
    return temp;
  }
  return nullptr;
}

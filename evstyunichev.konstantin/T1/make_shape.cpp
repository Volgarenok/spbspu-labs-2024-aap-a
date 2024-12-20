#include "make_shape.hpp"

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

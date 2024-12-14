#include "rectangle.hpp"
#include "base-types.hpp"

double zakirov::Rectangle::getArea() const
{
  return get_distance_x(top_right, bottom_left) * get_distance_y(top_right, bottom_left);
}


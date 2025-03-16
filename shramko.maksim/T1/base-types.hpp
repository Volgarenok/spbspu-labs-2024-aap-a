#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

#include <iostream>

namespace shramko
{
  struct point_t
  {
    double x;
    double y;
  };
  struct rectangle_t
  {
    double width;
    double height;
    point_t center;
    void print() 
    {
      std::cout << center.x - width / 2 << " " << center.y - height / 2 << " ";
      std::cout << center.x + width / 2 << " " << center.y + height / 2 << " ";
    }
  };
}

#endif

#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "rectangle.hpp"

namespace zholobov {

  class Square final: public Rectangle {
  public:
    Square(const point_t& a, double length);
  };

}

#endif

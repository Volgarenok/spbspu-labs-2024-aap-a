#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "rectangle.hpp"

namespace zholobov {

  class Square : public Rectangle {
   public:
    Square();
    Square(const point_t& a, double length);
  };

}

#endif

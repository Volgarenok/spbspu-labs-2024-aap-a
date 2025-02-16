#ifndef SQUARE_HPP
#define SQUARE_HPP

#include <istream>

#include "rectangle.hpp"

namespace zholobov {

  class Square final: public Rectangle {
  public:
    Square(const point_t& a, double length);
    Shape* clone() const override;
    static Square* create(std::istream& in);
  };

}

#endif

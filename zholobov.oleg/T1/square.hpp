#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "rectangle.hpp"

class Square: public Rectangle {
public:
  Square();
  Square(const point_t& a, float length);
};


#endif

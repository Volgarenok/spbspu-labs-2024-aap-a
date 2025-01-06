#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "parallelogram.hpp"

namespace zholobov {

  class Rectangle : public Parallelogram {
  public:
    Rectangle(const point_t& a, const point_t& c);
  };

}

#endif

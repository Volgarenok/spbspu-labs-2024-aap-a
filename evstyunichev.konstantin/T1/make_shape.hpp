#ifndef MAKE_SHAPE
#define MAKE_SHAPE
#include <iostream>
#include <string>
#include "base-types.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "regular.hpp"
#include "ring.hpp"
namespace evstyunichev
{
  Rectangle * make_rectangle(std::istream &);
  Circle * make_circle(std::istream &);
  Ring * make_ring(std::istream &);
  Regular * make_regular(std::istream &);
  Shape * make_shape(std::istream &, const std::string &);
}
#endif

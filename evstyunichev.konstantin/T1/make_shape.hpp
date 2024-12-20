#ifndef MAKE_SHAPE
#define MAKE_SHAPE
#include <iostream>
#include "base-types.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "ring.hpp"
namespace evstyunichev
{
  Rectangle * make_rectangle(std::istream &in);
  Circle * make_circle(std::istream &in);
  Ring * make_ring(std::istream &in);
}
#endif

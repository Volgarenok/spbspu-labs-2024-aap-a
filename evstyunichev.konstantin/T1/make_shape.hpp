#ifndef MAKE_SHAPE
#define MAKE_SHAPE
#include <iostream>
#include "base-types.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
namespace evstyunichev
{
  Rectangle * make_rectangle(std::istream &in);
  Circle * make_circle(std::istream &in);
}
#endif

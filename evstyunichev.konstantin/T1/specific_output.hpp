#ifndef SPECIFIC_OUTPUT_HPP
#define SPECIFIC_OUTPUT_HPP
#include <iostream>
#include "base-types.hpp"
namespace evstyunichev
{
  double roundToOneSign(double);
  void frameOutput(rectangle_t a, std::ostream &out = std::cout);
}
#endif

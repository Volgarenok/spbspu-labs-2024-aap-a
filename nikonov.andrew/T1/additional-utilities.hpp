#ifndef ADDITIONAL_UTILITIES_HPP
#define ADDITIONAL_UTILITIES_HPP
#include "shape.hpp"
#include "cstdlib"
namespace nikonov
{
  void fillShapeCollection(Shape* collection[], size_t& cnt, size_t& noncorrect);
  void destoy(Shape* collection[], size_t& cnt);
}
#endif

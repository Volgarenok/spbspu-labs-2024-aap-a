#include "inputFigures.hpp"

dirti::Rectangle* dirti::makeRectangle(std::istream& in)
{
  point_t left_low = {};
  point_t right_high = {};
  in >> left_low.x >> left_low.y >> right_high.x >> right_high.y;
  if (left_low.x >= right_high.x || left_low.y >= right_high.y)
  {
    throw std::logic_error("Wrong shape");
  }
  Rectangle* newRectangle = new Rectangle(left_low, right_high);
  return newRectangle;
}

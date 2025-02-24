#include "inputFigures.hpp"

dirti::Rectangle* dirti::makeRectangle(std::istream& in)
{
  double leftX = 0.0, leftY = 0.0;
  double rightX = 0.0, rightY = 0.0;
  Rectangle* newRectangle = nullptr;
  if (in >> leftX >> leftY >> rightX >> rightY)
  {
    point_t left_low = { leftX, leftY };
    point_t right_high = { rightX, rightY };
    newRectangle = new Rectangle(left_low, right_high);
  }
  return newRectangle;
}

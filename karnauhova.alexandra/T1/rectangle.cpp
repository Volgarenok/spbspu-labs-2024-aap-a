#include "rectangle.hpp"
double Rectangle::getArea()
{
  double len1 = x1_.y - x4_y;
  double len2 = x2_.x - x1_.x;
  return (len1 * len2);
}

void Rectangle::getFrameRect()
{
  rect_.widtch = x2_.x - x1_x;
  rect_.height = x2_.y - x3_y;
  rect_.pos.x = x1_.x + (rect_.widtch / 2);
  rect_.pos.y = x4_.y + (rect_.height / 2);
}

void Rectangle::move(double x, double y)
{
  
}

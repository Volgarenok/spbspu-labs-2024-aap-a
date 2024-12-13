#include "scale.hpp"
#include <iostream>
#include "base-types.hpp"
#include "shape.hpp"
void nikonov::ispScale(Shape& shp, double x, double y, double k)
{
  if (k <= 0) {
    std::cerr << "Scale denied: k must be more than zero\n";
    return;
  }
  point_t S(x, y);
  point_t origCenter = shp.getFrameRect().pos_;
  shp.move(S);
  point_t newCenter = shp.getFrameRect().pos_;
  float diffX = newCenter.x_ - origCenter.x_;
  float diffY = newCenter.y_ - origCenter.y_;
  shp.scale(k);
  shp.move(diffX * k * (-1), diffY * k * (-1));
}

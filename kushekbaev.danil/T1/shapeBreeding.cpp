#include "shapeBreeding.hpp"
#include <stdexcept>
#include "base-types.hpp"

namespace kushekbaev
{
  bool isTriangle(point_t first, point_t second, point_t third)
  {
    double side1 = getLineLength(first, second);
    double side2 = getLineLength(second, third);
    double side3 = getLineLength(first, third);
    return((side1 + side2 > side3) &&
          (side1 + side3 > side2) &&
          (side2 + side3 > side1));
  }

  bool isPointInsideTriangle(point_t first, point_t second, point_t third, point_t last)
  {
    double firstcheck = (first.x - last.x) * (second.y - first.y) - (second.x - first.x) * (first.y - last.y);
    double secondcheck = (second.x - last.x) * (third.y - second.y) - (third.x - second.x) * (second.y - last.y);
    double thirdcheck = (third.x - last.x) * (first.y - third.y) - (first.x - third.x) * (third.y - last.y);
    return ((firstcheck > 0 && secondcheck > 0 && thirdcheck > 0) ||
            (firstcheck < 0 && secondcheck < 0 && thirdcheck < 0));
  }

  point_t makeScale(std::istream& input)
  {
    double x = 0;
    double y = 0;
    input >> x >> y;
    return { x, y };
  }
}

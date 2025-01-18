#include "shapeBreeding.hpp"
#include <stdexcept>
#include "base-types.hpp"

namespace kushekbaev
{
  bool parallelX(point_t first, point_t second)
  {
    return (first.x == second.x);
  }

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

  Rectangle* makeRectangle(std::istream& input)
  {
    double x1 = 0;
    double y1 = 0;
    double x2 = 0;
    double y2 = 0;
    input >> x1 >> y1 >> x2 >> y2;
    return new Rectangle({ x1, y1 }, { x2, y2 });
  }

  Concave* makeConcave(std::istream& input)
  {
    point_t first { 0, 0 };
    point_t second { 0, 0 };
    point_t third { 0, 0 };
    point_t last { 0, 0 };
    input >> first.x >> first.y >> second.x >> second.y >> third.x >> third.y >> last.x >> last.y;
    return new Concave({ first, second, third, last });
  }

  Parallelogram* makeParallelogram(std::istream& input)
  {
    point_t first { 0, 0 };
    point_t second { 0, 0 };
    point_t third { 0, 0 };
    input >> first.x >> first.y >> second.x >> second.y >> third.x >> third.y;
    return new Parallelogram({ first, second, third });
  }

  Diamond* makeDiamond(std::istream& input)
  {
    point_t first { 0, 0 };
    point_t second { 0, 0 };
    point_t third { 0, 0 };
    input >> first.x >> first.y >> second.x >> second.y >> third.x >> third.y;
    return new Diamond({ first, second, third });
  }

  point_t makeScale(std::istream& input)
  {
    double x = 0;
    double y = 0;
    input >> x >> y;
    return { x, y };
  }
}

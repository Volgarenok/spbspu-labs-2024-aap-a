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

  bool isPointInsideTriangle(point_t first, point_t second, point_t third, point_t final)
  {
    double firstcheck = (first.x - final.x) * (second.y - first.y) - (second.x - first.x) * (first.y - final.y);
    double secondcheck = (second.x - final.x) * (third.y - second.y) - (third.x - second.x) * (second.y - final.y);
    double thirdcheck = (third.x - final.x) * (first.y - third.y) - (first.x - third.x) * (third.y - final.y);
    if (firstcheck > 0 && secondcheck > 0 && thirdcheck > 0)
    {
      return true;
    }
    else if (firstcheck < 0 && secondcheck < 0 && thirdcheck < 0)
    {
      return true;
    }
    return false;
  }

  Rectangle* makeRectangle(std::istream& input)
  {
    double x1 = 0;
    double y1 = 0;
    double x2 = 0;
    double y2 = 0;
    input >> x1 >> y1 >> x2 >> y2;
    if (x1 >= x2 || y1 >= y2)
    {
      throw std::invalid_argument("Left point values should be less than right point values\n");
    }
    return new Rectangle({ x1, y1 }, { x2, y2 });
  }

  Concave* makeConcave(std::istream& input)
  {
    point_t first { 0, 0 };
    point_t second { 0, 0 };
    point_t third { 0, 0 };
    point_t final { 0, 0 };

    input >> first.x >> first.y >> second.x >> second.y >> third.x >> third.y >> final.x >> final.y;
    if (!isTriangle(first, second, third))
    {
      throw std::invalid_argument("First three points doesnt make a triangle\n");
    }
    if (!isPointInsideTriangle(first, second, third, final))
    {
      throw std::invalid_argument("Final point isnt in triangle\n");
    }

    return new Concave({ first, second, third, final });
  }

  Parallelogram* makeParallelogram(std::istream& input)
  {
    point_t first { 0, 0 };
    point_t second { 0, 0 };
    point_t third { 0, 0 };
    input >> first.x >> first.y >> second.x >> second.y >> third.x >> third.y;
    bool isParallelToX = parallelX(first, second) || parallelX (second, third) || parallelX(first, third);
    if (!isParallelToX)
    {
      throw std::invalid_argument("There is no line that would be parallel to X axis\n");
    }
    if (!isTriangle(first, second, third))
    {
      throw std::invalid_argument("First three points wouldnt make a triangle\n");
    }
    return new Parallelogram({ first, second, third });
  }

  Diamond* makeDiamond(std::istream& input)
  {
    point_t first { 0, 0 };
    point_t second { 0, 0 };
    point_t third { 0, 0 };
    input >> first.x >> first.y >> second.x >> second.y >> third.x >> third.y;
    if (!isTriangle(first, second, third))
    {
      throw std::invalid_argument("First three points wouldnt make a triangle\n");
    }
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
